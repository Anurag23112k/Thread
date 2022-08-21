#ifndef THREAD_H
#define THREAD_H
#include <iostream>

class Thread
{
    public:
        Thread();
        Thread(const char*);
        Thread(const Thread&);

        void operator = (const char*);

        /// + Operator overloading
        friend Thread operator + (const char&,const Thread&);
        friend Thread operator + (const Thread&,const char&);
        friend Thread operator + (const char*,const Thread&);
        friend Thread operator + (const Thread&,const char*);
        friend Thread operator + (const Thread&,const Thread&);

        /// Comparison operators
        friend bool operator == (const Thread&, const Thread&);
        friend bool operator != (const Thread&, const Thread&);

        ///output and input operator
        friend std::ostream& operator << (std::ostream&,Thread&);
        friend std::istream& operator >>(std::istream&,Thread&);
        void getLine();

        ///utility methods
        int length() const;
        Thread subThread(int,int);
        char operator [] (int);
        int toInt();
        long toLongInt();
        long long toLargeInt();
        Thread toThread(int);

        ~Thread();

    private:
        char* str;
        void setThread(const char*);

        char* getThread() const;

        char* add(const char&,const char*) const;
        char* add(const char*,const char&) const;
        char* add(const char*,const char*) const;

        ///comparison utility methods
        int compareThread(const char*,const char*) const;
};

#endif // THREAD_H
