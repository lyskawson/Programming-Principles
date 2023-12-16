#include <iostream>

using namespace std;

void task1()
{
    int t, days;
    cin>>t; //liczba zestawow
    for(int i=0; i<t; i++)
    {
        int segments;
        cin>>segments; //liczba segemntow w zestawie
        int legs[segments];
        int legsSum = 0;

        for(int j=0;j<segments;j++)
        {
            cin>>legs[j]; //tablica przechowujaca ilosc nozek w segmentach
            legsSum = legsSum + legs[j];

        }
        days = segments + legsSum - 1;
        cout << days<< endl;
    }
};

float avg(int n)
{
    float sum = 0;
    float count = 0;
    for(int i = 2; i < n - 1; i++)
    {

        if(n%i == 0)
        {
            sum = sum + i;
            count++;
        }
    }
    return sum/count;
}
void task2()
{

    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {

    }

}

int main()
{
    //task1();
    //task2();
    cout << avg(6) << endl;
    return 0;
}



