#include "Requirments.h"

bool checkDate(char str[])
{
    char *endptr;
    int base = 10;
    int year, month, day;

    day = strtol(str, &endptr, base);
     if(day>31||day<1)
     {
       return 0;
     }

    if (endptr[0] == '/') {
        month = strtol(endptr + 1, &endptr, base);
        if(month>12||month<1)
        {
       return 0;
        }
    } else {
        return 0;
    }
    if (endptr[0] == '/') {
        year = strtol(endptr + 1, &endptr, base);
       if(year>2021||year<1000)
       {
       return 0;
       }
    } else {
        return 0;
    }
if((day==31)&&(month!=1||month!=3||month!=5||month!=7||month!=8||month!=10||month!=12))
{
    return 0;
}
if(day>29&&month!=2)
{
return 0;
}
    return 1;
}

int checkTime(char str[])
{
  char *endptr;
    int base = 10;
    int h, m;

    h = strtol(str, &endptr, base);
     if(h>23||h<0)
     {
         puts("h");
       return 0;
     }

    if (endptr[0] == ':') {
        m= strtol(endptr + 1, &endptr, base);
    }
        if(m>59||m<0)
        {
            puts("m");
       return 0;
        }
    return 1;
}

bool isNumbers(char str[])
{
    int i;
    for (i=0;i<7;i++)
    {
        if(str[i]<'0' || str[i]>'9')
            return 0;
    }
    return 1;
}


bool fourDigitNum(int num)
{
    if(num>999&&num<10000)
    return 1;
    return 0;
}
bool fiveDigitNum(int num)
{
    if(num>9999&&num<100000)
    return true;
    return false;
}
bool isThreeDigitNum(long num)
{
    if(num>99&&num<1000)
    return true;
    return false;
}
bool sevenDigitNum(long num)
{
    if(num>0 && num<10000000)
    return 1;
    return 0;
}
bool isSevenDigitNum(long num)
{
    if(num>999999 && num<10000000)
    return 1;
    return 0;
}
bool isNineDigitNum(long num)
{
    if(num>9999999 && num<1000000000)
    return 1;
    return 0;
}
bool isTenDigitNum(long num)
{
    if(num>999999999 && num<10000000000)
    return 1;
    return 0;
}
bool TenDigitNum(long num)
{
    if(num>0 && num<10000000000)
    return 1;
    return 0;
}


