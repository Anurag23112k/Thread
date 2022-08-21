#include "../include/thread.h"
#include <cstring>
#include <cstdio>
#include <iostream>
#include <cstdlib>
using namespace std;

//------------------------------------------------------------------>
///Initialization
Thread::Thread()
{
    //ctor
    str = new char[1];
    str[0] = '\0';
}

Thread::Thread(const char* buffer)
{
    this->setThread(buffer);

}

Thread::Thread(const Thread& source)
{
    char* buffer = source.getThread();
    this->setThread(buffer);
}

void Thread::operator = (const char* buffer)
{
    this->setThread(buffer);
}

//----------------------------------------------------------------->

///Utility methods

int Thread::length() const
{
    return strlen(str);
}

Thread Thread::subThread(int pos,int len){
    Thread res;
    Thread z(this->getThread());
    int n = this->length();
    if(len>n){
        cout<<"Out of range"<<endl;
        exit(1);
    }
    for(int i=pos;i<len;i++){
        res = res + z[i];
    }
    return res;
}

char Thread::operator [] (int n)
{
    return str[n];
}

int Thread::toInt(){
  char* x = this->getThread();
  int s = 0;
  int i;
  if(x[0] == '-')
    i = 1;
  else
    i = 0;
  while(x[i] != '\0'){
    s = s*10 + x[i]%48;
    i++;
  }
  if(x[0] == '-')
    return -s;
  return s;
}

long Thread::toLongInt(){
  char* x = this->getThread();
  long s = 0;
  int i = 0;
  if(x[0] == '-')
    i = 1;
  else
    i = 0;
  while(x[i] != '\0'){
    s = s*10 + x[i]%48;
    i++;
  }
  if(x[0] == '-')
    return -s;
  return s;
}

long long Thread::toLargeInt(){
  char* x = this->getThread();
  long long s = 0;
  int i = 0;
  if(x[0] == '-')
    i = 1;
  else
    i = 0;
  while(x[i] != '\0'){
    s = s*10 + x[i]%48;
    i++;
  }
  if(x[0] == '-')
    return -s;
  return s;
}

Thread Thread::toThread(int num){
  Thread z;
  int rem;
  while(num){
    rem = num%10 + 48;
    num = num/10;
    z = (char)rem + z;
  }
  cout<<z<<endl;
  return z;
}

//------------------------------------------------------------------->

/// add methods

char* Thread::add(const char& x,const char* y) const
{
    int i=0;
    int n = strlen(y);
    char* temp = new char[n+2];
    temp[0] = x;
    for(i=0;i<n;i++)
        temp[i+1] = y[i];
    temp[i+1] = '\0';
    return temp;
}

char* Thread::add(const char* x,const char& y) const
{
    int i=0;
    int n = strlen(x);
    char* temp = new char[n+2];
    for(i=0;i<n;i++)
        temp[i] = x[i];
    temp[i++] = y;
    temp[i] = '\0';
    return temp;
}

char* Thread::add(const char* x,const char* y) const
{
    int n = strlen(x) + strlen(y);
    int i=0,j=0,k=0;
    char* temp = new char[n+1];
    while(x[i]!='\0')
        temp[k++] = x[i++];
    while(y[j]!='\0')
        temp[k++] = y[j++];
    temp[k] = '\0';
    return temp;
}

/// comparison utility methods

///// returns 0 if x == y returns 2 if x > y and returns -2 if x < y
/*
  * x > y means x will come after y in dictionary arrangement
  * x < y means x will come before y in dictionary arrnagement
*/
int Thread::compareThread(const char* x,const char* y) const {
  int i = 0;
  int j = 0;
  int n = strlen(x);
  int m = strlen(y);
  while(x[i] != '\0' && y[j] != '\0'){
    if(x[i] > y[j])
      return 2;
    if(x[i] < y[j])
      return -2;
    i++;
    j++;
  }
  if(i < n)
    return 2;
  if(j < m)
    return -2;
  return 0;
}

/// + operator methods

Thread operator + (const char& lhs,const Thread& rhs)
{
    char* x = rhs.getThread();
    char* res = rhs.add(lhs,x);
    Thread temp(res);
    delete[] res;
    return temp;
}

Thread operator + (const Thread& lhs,const char& rhs)
{
    char* x = lhs.getThread();
    char* res = lhs.add(x,rhs);
    Thread temp(res);
    delete[] res;
    return temp;
}

Thread operator + (const char* lhs,const Thread& rhs)
{
    char* x = rhs.getThread();
    char* res = rhs.add(lhs,x);
    Thread temp(res);
    delete[] res;
    return temp;
}

Thread operator + (const Thread& lhs,const char* rhs)
{
    char* x = lhs.getThread();
    char* res = lhs.add(x,rhs);
    Thread temp(res);
    delete[] res;
    return temp;
}

Thread operator + (const Thread& lhs,const Thread& rhs)
{
    char* x = lhs.getThread();
    char* y = rhs.getThread();
    char* res = lhs.add(x,y);
    Thread temp(res);
    delete[] res;
    return temp;
}

/// Comparison operators

bool operator == (const Thread& lhs,const Thread& rhs){
  char* x = lhs.getThread();
  char* y = rhs.getThread();
  int z = lhs.compareThread(x,y);
  if(z == 0)
    return true;
  else
    return false;
}

bool operator != (const Thread& lhs,const Thread& rhs){
  return !(lhs == rhs);
}


//----------------------------------------------------------------->

///Output and input operator method

ostream& operator << (ostream& out,Thread& rhs)
{
    int i=0;
    char* res = rhs.getThread();
    for(;res[i]!='\0';i++)
        out<<res[i];
    return out;
}

istream& operator >> (istream& in,Thread& rhs){
    char s[1024];
    in>>s;
    rhs = s;
    return in;
}

void Thread::getLine(){
    char s[1024];
    cin.get(s,1024);
    this->setThread(s);
}

//----------------------------------------------------------------->
///Getter and setter

void Thread::setThread(const char* buffer)
{
    int i=0;
    int n = strlen(buffer);
    delete[] str;
    str = new char[n+1];
    for(;i<n;i++)
        str[i] = buffer[i];
    str[i] = '\0';
}

char* Thread::getThread() const
{
    return str;
}

//------------------------------------------------------------------->

///Destructor

Thread::~Thread()
{
    //dtor
    delete[] str;
}
