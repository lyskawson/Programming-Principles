#include <iostream>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void task1()
{
    for(int i = 0; i < 11; i++)
        cout << i << endl;
}

void task2()
{
    int A,B;
    cin >> A;
    cin >> B;
    for(int i = A; i<B+1;i++)
        cout << i << endl;
}

void task3()
{
    int A,B,C;
    cin >> A;
    cin >> B;
    cin >> C;
    for(int i = A; i<B+1;i=C+i)
        cout << i << endl;
}

void task4()
{
    int K;
    cin >> K;
    for(int i = 1; i<K+1;i++)
        cout << 'a' << i << '=' << 2*i + 1 << endl;
}

void task5()
{
    int N;
    float num, sum = 0.0;

    std::cout << "Enter integer N: ";
    std::cin >> N;

    std::cout << "Enter " << N << " floating nums:" << std::endl;
    for (int i = 0; i < N; ++i)
    {
        std::cout << "Enter num #" << i + 1 << ": ";
        std::cin >> num;
        sum += num;
    }

    float avarage = sum / N;

    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Avarage: " << avarage  << std::endl;
}

void task6()
{
    int num, positiveCount, dividedBy6Count, smallerNumCount, lastNum;
    lastNum = positiveCount=dividedBy6Count=smallerNumCount=0;
    bool firstIteration = true;

    std::cout << "Enter integers (enter 0 to end): " << std::endl;
    do{
        cin >> num;

        if(num > 0)
            positiveCount++;
        if(num%6 == 0)
            dividedBy6Count++;
        if(num < lastNum && (firstIteration == false))
            smallerNumCount++;
        lastNum = num;
        firstIteration = false;
    }while( num != 0);
    cout << positiveCount << endl;
    cout << dividedBy6Count - 1 << endl; //bo 0 jest podzielne
    cout << smallerNumCount << endl;
}

int factorial(int n)
{
    if(n>1)
        return n * factorial(n-1);
    else
        return 1;
}


void task7()
{
    int n,m;
    cout << "Enter number bigger or equal to 1: " << endl;
    cin >> n;
    n=m;
    cout << n << "!" << " = " << factorial(n) << " //recursion" << endl; // recursion


    int factorial = 1;
    for(int i = 0; i <= m; i++)
    {
        factorial = factorial * i;
    }
    cout << m << "!" << " = " << factorial << endl;

}

int NWD(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int NWW(int a, int b)
{
    return (a * b) / NWD(a, b);
}

void task8()
{
    int a, b;
    cin >> a;
    cin >> b;
    cout << "NWD: "<< NWD(a,b) << endl;
    cout << "NWW: "<< NWW(a,b) << endl;
}

void task9()
{

    srand(time(0));

    for (int i = 0; i < 10; ++i)
    {
        int randomNum = rand() % 10 + 1; // Generuj liczbę z zakresu 1-10
        cout << randomNum << endl;
    }
}

void task10()
{
    int n,remainder, b;
    int i = 1;
    int binaryNumber = 0;

    cout << "Enter number: ";
    cin >> n;
    b = n;

    while(b!=0)
    {
        remainder = b % 2;

        b = b / 2;
        binaryNumber = binaryNumber+remainder * i;
        i=i*10;
    }

    cout << "Liczba w systemie binarnym: ";
    cout << binaryNumber << endl;


    cout << "Liczba w systemie szesnastkowym: ";
    cout << std::hex << n << endl;


    cout << "Liczba w systemie osemkowym: ";
    cout << std::oct << n << std::endl;
}

void task11()
{
    cout << "| Celcius | Kelvin | Fahrenheit|" << endl;
    cout << fixed << setprecision(2); // Ustawienie precyzji na 2 miejsca po przecinku

    for (float celsius = -20; celsius <= 100; celsius += 5)
        {
            float kelvin = celsius + 273.15;
            float fahrenheit = celsius * 9.0 / 5.0 + 32.0;

            cout << "| " << setw(7) << celsius << " | " << setw(6) << kelvin << " | " << setw(9) << fahrenheit << " |" << endl;
        }
    cout << "--------------------------------" << endl;
}

void task12()
{
    for (int i = 1; i < 11; i++)
    {
        for (int j = 1; j < 11  ; j++)
        {
            cout << setw(4) << i * j;
        }
        cout << endl;
    }
}

void task13()
{
    double x, result;
    int N, factorial;

    cout << "Enter x: ";
    cin >> x;

    cout << "Enter N: ";
    cin >> N;
    factorial = 1;
    result = 1;

    for (int n = 1; n <= N; ++n)
    {
        factorial = factorial * n; // Obliczanie n!
        result = result +  pow(x, n) / factorial; // Dodawanie kolejnego składnika do sumy
    }

        cout << "e^x for x= " << x << " and  N= " << N << " is equal: " << result << endl;

}

void task14()
{
    int N;
    double pi = 0.0;

    cout << "Enter N: ";
    cin >> N;

    for (int k = 1; k <= N; ++k) {
        pi = pi + pow(-1, k + 1) / (2.0 * k - 1);
    }

    pi = pi * 4;

    cout << "Approximation for pi for N= " << N << " is equal: " << setprecision(11) << pi <<  endl;
    cout << "Actual value of pi rounded to 10 digits after a decimal: " << setprecision(11) << M_PI << endl;
}

int main()
{
    //task1();
    //task2();
    //task3();
    //task4();
    //task5();
    //task6();
    //task7();
    //task8();
    //task9();
    //task10();
    //task11();
    //task12();
    //task13();
    task14();


    return 0;
}
