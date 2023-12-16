#include <iostream>


using namespace std;

void zadanie1()
{
    int a,b;
    cin >> a;
    cin >> b;


    if(a<b)
    {
        cout << a << endl;
    }
    else if(a>b)
    {
        cout << b <<endl;
    }
    else
        cout << a << endl;
}

void zadanie2()
{
    double a,b, result;
    cin >> a;
    cin >> b;

    if(a>=b)
    {
        if( b!= 0)
        {
            cout << a/b << endl;
        }
        else
            cout << "EROOR: dividing by zero " << endl;

    }
    if(b>a)
    {
        if( a!= 0)
        {
            cout << b/a << endl;
        }
        else
            cout << "EROOR: dividing by zero " << endl;
    }
}

void zadanie3()
{
    int a,b;
    cin >> a;
    cin >> b;

    if(a%b == 0)
    {
        cout << a/b;
    }
    else
        cout << a % b << endl;
}

void zadanie4()
{
    int a,b,c;
    if ((a>0 && a<=10) && a < b && (b>15 || c == 5))
    {
        cout << "true" << endl;
    }
    else
        cout << "false" << endl;
}

void zadanie5()
{
    float a,b, proc;
    cin >> a;
    cin >> b;
    if(a <= b && a >= 0)
    {
        proc = a * 100 /b;


        if(proc>=0 && proc < 50 )
            cout << "2.0" << endl;
        if(proc>=50 && proc < 60 )
            cout << "3.0" << endl;
        if(proc>=60 && proc < 70 )
            cout << "3.5" << endl;
        if(proc>=70 && proc < 80 )
            cout << "4.0" << endl;
        if(proc>=80 && proc < 90 )
            cout << "4.5" << endl;
        if(proc>=90 && proc < 100 )
            cout << "5.0" << endl;
        if(proc==100 )
            cout << "5.5" << endl;
    }
    else
        cout << "ERROR" << endl;
}

void zadanie6()
{
    float a,b,c,delta;

    cin >> a;
    cin >> b;
    cin >> c;

    if (a==0.0)
        if (b!=0.0)
            cout << "Jest to równanie liniowe o rozwiazaniu x=" <<-c/b << endl;
        else if (c==0.0)
            cout << "Rozwiazaniem jest dowolne x" << endl;
        else
           cout << "Brak rozwiazan" << endl;
    else
    {
        delta=pow(b,2)-4.0*a*c;
        if (delta<0)
            cout << "Brak rozwiazan rzeczywistych" << endl;

        else if (delta>0)
            cout << "Rozwiazaniem sa x1= " << (-b-sqrt(delta))/(2*a) << " i x2= " << (-b+sqrt(delta))/(2*a) << endl;
        else
            cout << "Rozwiazaniem sa x1=x2= " << -b/2*a << endl;
    }

}

void zadanie7()
{
    float a, b, c, d, e, f, delta, delta_x, delta_y;
    cin >> a;
    cin >> b;
    cin >> c;
    cin >> d;
    cin >> e;
    cin >> f;

    delta = a * e - b * d;
    delta_x = c * e - b * f;
    delta_y = a * f - c * d;

    if (delta != 0)
    {
        float x = delta_x / delta;
        float y = delta_y / delta;
        cout << "Rozwiazanie układu rownan:" << endl;
        cout << "x = " << x << endl;
        cout << "y = " << y << endl;
    }
    else
    {
        if (delta_x == 0 && delta_y == 0)
        {
            cout << "Układ ma nieskończenie wiele rozwiazań." << endl;
        }
        else
        {
            cout << "Układ jest sprzeczny." << endl;
        }
    }
}

void zadanie8()
{



    

}

int main() {

    int choice;
    cout << "Wpisz nr zadania ktore chcesz przetestowac: " << endl;
    cin >> choice;

    switch(choice)
    {
        case 1:
            zadanie1();
            break;
        case 2:
            zadanie2();
            break;
        case 3:
            zadanie3();
            break;
        case 4:
            zadanie4();
            break;
        case 5:
            zadanie5();
            break;
        case 6:
            zadanie6();
            break;
        case 7:
            zadanie7();
            break;
        case 8:
            zadanie8();
            break;
    }



    return 0;
}
