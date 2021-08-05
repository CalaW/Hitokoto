#include "Time.h"
#include <iostream>

using namespace std;

int main()
{
    Time mtime = Time::now();
    cout << mtime << mtime.getTime() << endl;
    cin >> mtime;
    cout << mtime << mtime.getTime() << endl;

    tm timeS;
    cin >> timeS.tm_year >> timeS.tm_mon >> timeS.tm_mday
        >> timeS.tm_hour >> timeS.tm_min >> timeS.tm_sec;
    timeS.tm_year -= 1900;
    timeS.tm_mon -= 1;
    Time mmtime(timeS);
    cout << mmtime << mmtime.getTime() << endl;

    int year, mon, mday, hour, min, sec;
    cin >> year >> mon >> mday >> hour >> min >> sec;
    Time mmmtime(year, mon, mday, hour, min, sec);
    cout << mmmtime << mmmtime.getTime() << endl;

    return 0;
}