#include "Time.h"

Time::Time(int hour, int minute) : hour(hour), minute(minute)
{
}

Time::Time(const Time &time) : hour(time.hour), minute(time.minute)
{
}

int Time::GetHour() const
{
    return hour;
}

int Time::GetMinute() const
{
    return minute;
}

void Time::SetHour(int h)
{
    hour = h;
}

void Time::SetMinute(int m)
{
    minute = m;
}
