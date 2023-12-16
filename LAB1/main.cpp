#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

void zadanie_1()
{
    int x[6];
    x[0] = 2+3*4;
    x[1] = 20/10/10;
    x[2] = 20 - 20 + 5;
    x[3] = 5 + 10/2;
    x[4] = (5+10)/3;

    for(int i=0; i<6; i++)
    {
        cout << x[i] << endl;
    }
}

void zadanie_2()
{
    int d1,d2;
    cout << "Enter first integer: " << endl;
    cin >> d1;
    cout << "Eneter second integer: " << endl;
    cin >> d2;

    cout << "Results: "<< endl;
    cout << d1 << "-" << d2 << "=" << d1 - d2 << endl;
    cout << d1 << "+" << d2 << "=" << d1 + d2 << endl;
    cout << d1 << "*" << d2 << "=" << d1 * d2 << endl;
    cout << d1 << "/" << d2 << "=" << d1 / d2 << endl;
}

void zadanie_3()
{
    int d1,d2;
    cout << "Enter first integer: " << endl;
    cin >> d1;
    cout << "Eneter second integer: " << endl;
    cin >> d2;

    float result1 = d1 / d2;
    int result2 = d1 / d2;
    double result3 = d1 / d2;

    cout << "for float: " << d1 << "/" << d2 << "=" << result1 << endl;
    cout << "for double: " <<  d1 << "/" << d2 << "=" << result3 << endl;
    cout << "for int: " << d1 << "/" << d2 << "=" << result2 << endl;
}

void zadanie_4()
{
    int a = 2;
    float b = 1;
    cout << "result of explicit division by zero: "<<  10/0 << endl;
    cout << "result of dividing an integer by zero : " << a/0 << endl;
    cout << "result of dividing an floating point  by zero: " << b/0 << endl;
}

void zadanie_5()
{
    float R;
    cout <<"Enter radius: " << endl;
    cin >> R;
    float area = M_PI * R * R;
    float circuit = 2* M_PI* R;

    cout << "area: " << area << endl;
    cout << "circuit: " << circuit << endl;
}

void zadanie_6()
{
    float x1, x2, y1, y2, distance;
    cout << "Enter x1 coordinate: " << endl;
    cin >> x1;
    cout << "Enter x2 coordinate: " << endl;
    cin >> x2;
    cout << "Enter y1 coordinate: " << endl;
    cin >> y1;
    cout << "Enter y2 coordinate: " << endl;
    cin >> y2;

    distance = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    cout << "distance between points: " << distance << endl;
}

void zadanie_7()
{
    float r, V1, V2;
    cout << "Enter radius: ";
    cin >>  r;

    V1 = 4/3 * M_PI * pow(r,3);
    V2 = M_PI * 4/3 * pow(r,3);

    cout << V1 << endl;
    cout << V1 << endl;

}

void zadanie_8()
{
    float y[7];
    y[0] = sin(0);
    y[1] = sin(M_PI/4);
    y[2] = sin(M_PI/2);
    y[3] = sin(M_PI);
    y[4] = sin(45);
    y[5] = sin(90);
    y[6] = sin(180);

    for(int i =0 ; i < 7; i++)
    {
        cout << y[i] << endl;
    }
}

void zadanie_9()
{
    double pi;
    pi = M_PI;
    cout << fixed << setprecision(1) << pi << endl;
    cout << fixed << setprecision(3) << pi << endl;
    cout << fixed << setprecision(5) << pi << endl;
    cout << fixed << setprecision(7) << pi << endl;

}

int main()
{

    //zadanie_1();
    //zadanie_2();
    //zadanie_3();
    //zadanie_4();
    //zadanie_5();
    //zadanie_6();
    //zadanie_7();
    //zadanie_8();
    zadanie_9();


    return 0;
}
