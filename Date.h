#ifndef DATE_H
#define DATE_H

class Date{
    public:
        Date(int day = 1, int month = 1, int year = 1900);
        Date(const Date& date);

        int GetDay() const;
        int GetMonth() const;
        int GetYear() const;

        void SetDay(int d);
        void SetMonth(int m);
        void SetYear(int y);

    private:
        int day;
        int month;
        int year;
};

#endif
