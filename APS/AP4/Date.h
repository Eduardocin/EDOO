//Date class definition
#ifndef DATE_H
#define DATE_H

class Date{
    private:
        int day;
        int month;
        int year;
    public:
        void init( int month, int day, int year);
        void init(void);
        void print(void);

};

#endif // DATE_H