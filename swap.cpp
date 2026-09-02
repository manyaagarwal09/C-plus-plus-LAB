#include <iostream>
using namespace std;

void swap(int a, int b)
{
    int t;
    t=a;
    a=b;
    b=t;
    cout<<"After swapping: x="<< a <<"y="<< b<<endl;
}

int main()
{
    int x=60;
    int y=80;
    cout<<"Before swapping: x="<< x <<"y="<< y <<endl;
    swap(x, y);
    return 0;
}