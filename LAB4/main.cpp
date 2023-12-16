#include <iostream>
#include <cmath>

using namespace std;

void task1(int A, int B )
{
    for(int i = A; i< B +1; i++ )
    {
        cout << i << endl;
    }
}

int sumap(int A, int B)
{
    int sum = 0;
    for(int i = A; i< B +1; i++ )
    {
        if(i % 2 == 0)
            sum = sum +i;
    }
    return sum;
}

float distance(float x1, float x2, float y1, float y2)
{
    return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));

}

bool isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int daysInYear(int year)
{
    if(isLeapYear(year)==true )
        return 366;
    else
        return 365;
}

int daysInMonth(int year, int month)
{
    int months[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (month == 2 && isLeapYear(year))
        return 29;
    else
        return months[month];
}

int daysPast(int year, int month, int day)
{
    int daysCount = 0;
    for(int i = 1900; i < year ; ++i)
    {
        daysCount = daysCount + daysInYear(i);
    }
    for(int i = 1; i < month;++i )
    {
        daysCount += daysInMonth(year, i);
    }
    daysCount += day;
    return daysCount;

}

int nwd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int nwd4nums(int a, int b, int c, int d)
{
    int nwdAB = nwd(a, b);
    int nwdCD = nwd(c, d);

    return nwd(nwdAB, nwdCD);
}

bool isPrime(int a, int b)
{
    return nwd(a, b) == 1;
}

bool isPythagorean(int a, int b, int c) {

    return (a * a + b * b == c * c) || (a * a + c * c == b * b) || (b * b + c * c == a * a);
}

int digitCount(int num)
{
    int digitCount = 0;
    if (num == 0) {
        return 1;
    }


    while (num != 0)
    {
        num = num/ 10;
        digitCount++;
    }
    return digitCount;
}

int digitProduct(int num)
{
    int product = 1;


    if(num == 0)
        return 0;

    while (num != 0)
    {
        int digit = num % 10;
        product = product * digit;
        num = num / 10;
    }
    return product;
}

int main() {
    //task1(1,5);
    //cout << sumap(1,6);
    //cout << distance(2.0, 5.0, 10.0, 8.0);
    assert(isLeapYear(2020)==true);
    assert(isLeapYear(1924)==true);
    assert(isLeapYear(1993)==false);
    assert(daysInYear(2020)==366);
    //cout << daysPast(2023, 11, 15);
    //cout << digitCount(54632);
    cout << digitProduct(2361 );

    return 0;
}
