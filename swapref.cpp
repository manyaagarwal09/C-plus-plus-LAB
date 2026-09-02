#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int t;
    t=*a;
    *a=*b;
    *b=t;

}

int main()
{
    int x=20;
    int y=40;
    cout<<"Before swapping: x="<< x <<"y="<< y <<endl;
    swap(&x,&y);
    cout<<"After swapping: x="<< x <<"y="<< y <<endl;
    return 0;
}