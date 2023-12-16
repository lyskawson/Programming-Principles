#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

void displayVector(const vector<int> &w)
{
    for (auto i = w.begin(); i != w.end(); i++)
        cout << *i << " ";
    cout << endl;
}

void displayArray(const int tab[], int size)
{
    for(int i=0; i<size; i++)
    {
        cout << tab[i] << " ";
    }
    cout << endl;
}

void displayPartOfVector(const vector<int> &w, int n)
{
    for(size_t i=0; i<w.size(); i=i+n)
    {
        cout << w[i] << " ";
    }
    cout << endl;
}

void displayPartOfArray(const int tab[], int size, int n)
{
    for (int i = n - 1; i < size; i += n)
    {
        cout << tab[i] << " ";
    }
    cout << endl;
}

float  averageOfelements(const vector<int> &w)
{
    float sum = 0;
    for(size_t i=0; i<w.size(); i++)
        sum +=w[i];
    return sum/ w.size();
}

float  varianceOfelements(const vector<int> &w)
{
    float average = averageOfelements(w);
    double sumaKwadratowRoznic = 0.0;

    for (int i = 0; i < w.size(); i++)
    {
        sumaKwadratowRoznic += pow(w[i] - average, 2);
    }

    return sumaKwadratowRoznic / w.size();
}

vector<int> fibonacci(int N)
{
    vector<int> f;
    if (N <= 0)
    {
        return f;
    }
    else if (N == 1)
    {
        f.push_back(0);
    }
    else
    {
        f.push_back(0);
        f.push_back(1);
        for (int i = 2; i < N; i++)
        {
            int nextFibonacci = f[i - 1] + f[i - 2];
            f.push_back(nextFibonacci);
        }
    }
    return f;
}

void copyArray(const int tab1[], int tab2[], int N)
{
    for (size_t i = 0; i < N; i++)
    {
        tab2[i] = tab1[i];
    }
}

void reverseArray(int tab[], int N)
{

    for (int i = 0; i < N/2; i++)
    {
        int temp = tab[i];
        tab[i] = tab[N - i - 1];
        tab[N - i - 1] = temp;
    }
}

vector<int> evenValues(const vector<int> &v)
{
    vector<int> e;
    for(size_t i=0; i<v.size(); i++)
    {
        if(v[i]%2 == 0)
            e.push_back(v[i]);
    }
    return e;
}

bool isValue(const vector<int> &v,int val)
{
    for (const auto &i : v)
    {
        if (i == val)
        {
            return true;
        }
    }

    return false;
}

int firstAppear(const vector<int> &v, int x)
{
    for (size_t i = 0; i < v.size(); i++)
    {
        if (v[i] == x)
            return static_cast<int>(i);
    }

    return -1;
}

int lastAppear(const vector<int> &v, int x)
{
    int lastAppear = -1;

    for (size_t i = 0; i < v.size(); i++)
    {
        if (v[i] == x)
        {
            lastAppear = static_cast<int>(i);
        }
    }

    return lastAppear;
}

int main()
{
    srand(time(0));
    int value1 = 1 ;
    int N = 10;
    int A = 1;
    int B = 5;
    vector<int> v1;
    vector<int> v2;
    int tab1[10];
    int tab2[10];

    for(int i = 0; i < N; i++)
    {
        int randomNum = rand() % (B - A + 1) + A;
        tab1[i]=randomNum;
    }

    for(int i=0; i <= 100; i++)
    {
        v1.push_back(value1);
    }

    for(int i = 0; i < N; i++)
    {
        int randomNum = rand() % (B - A + 1) + A;
        v2.push_back(randomNum);
    }


    cout << "v2: ";
    displayVector(v2);
    cout << "tab1: ";
    displayArray(tab1,10);
    cout << "part of v2: ";
    displayPartOfVector(v2, 3);
    cout << "average of v2: " << averageOfelements(v2) << endl;
    cout << "variance of v2: " << varianceOfelements(v2) << endl;
    cout << "fibonacci: ";
    displayVector(fibonacci(10));
    copyArray(tab1, tab2, 10);
    cout << "Coppied tab1: ";
    displayArray(tab2, 10);
    reverseArray(tab1,10);
    cout << "Reversed tab1: ";
    displayArray(tab1, 10);
    cout << "Even values of v2: ";
    displayVector(evenValues(v2));

    return 0;
}

