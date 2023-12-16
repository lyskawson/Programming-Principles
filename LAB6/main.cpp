#include <iostream>
#include <vector>


using namespace std;

void displayVector(const vector<int> &w)
{
    for (auto i = w.begin(); i != w.end(); i++)
        cout << *i << " ";
    cout << endl;
}

void moveRight(vector<int> &v)
{
    for (int i = v.size() - 1; i > 0; i--)
    {
        v[i] = v[i - 1];
    }
    v[0] = 0;
}

void moveLeft(vector<int> &v)
{
    for (int i = 0 ; i < v.size(); i++)
    {
        v[i] = v[i + 1];
    }

    v[v.size()-1] = 0;
}

bool isSame(const vector<int> &v,const vector<int> &w)
{
    for(size_t i=0;i<v.size();i++)
    {
        if(abs(v[i]) != abs(w[i]))
            return false;
    }
    return true;
}

void rotateVector(vector<int> &v , int dir)
{

    if(dir>0)
    {
        for (int i = 0; i < dir; i++)
        {
            int temp = v.back();
            for (int j = v.size() - 1; j > 0; j--)
            {
                v[j] = v[j - 1];
            }
            v[0] = temp;
        }
    }
    else if(dir<0)
    {
        dir = abs(dir);
        for(int i=0;i<dir;i++)
        {
            int temp = v[0];
            for(int j = 0 ; j < v.size(); j++)
            {
                v[j] = v[j + 1];
            }
            v.back() = temp;
        }
    }
    else
        return;
}









int main()
{
    vector<int> v1;
    for(int i=1;i<=10;i++)
        v1.push_back(i);

    rotateVector(v1, -2);
    //moveRight(v1);
    //moveLeft(v1);
    displayVector(v1);
    cout << endl;


    return 0;
}
