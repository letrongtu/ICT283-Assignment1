#ifndef TIME_H
#define TIME_H

class Time{
    public:
        Time(int hour = 0, int minute = 0);
        Time(const Time& time);

        int GetHour() const;
        int GetMinute() const;

        void SetHour(int d);
        void SetMinute(int m);

    private:
        int hour;
        int minute;
};

#endif
