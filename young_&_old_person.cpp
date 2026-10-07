#include <iostream>
#include <cstring>
using namespace std;
const int SIZE = 10;
class Person
{
    char name[64];
    int age;
    char address[64];
public:
    // Default constructor
    Person()
    {
        strcpy(name, "Unknown");
        age = 0;
        strcpy(address, "Unknown");
    }
    // Parameterized constructor
    Person(const char n[], int a, const char addr[])
    {
        strcpy(name, n);
        age = a;
        strcpy(address, addr);
    }
    // Inline function to find youngest age
    static inline int youngestAge(const Person arr[], int n)
    {
        int min = arr[0].age;
        for (int i = 1; i < n; i++)
        {
            if (arr[i].age < min)
                min = arr[i].age;
        }
        return min;
    }
    // Inline function to find oldest age
    static inline int oldestAge(const Person arr[], int n)
    {
        int max = arr[0].age;
        for (int i = 1; i < n; i++)
        {
            if (arr[i].age > max)
                max = arr[i].age;
        }
        return max;
    }
};
int main()
{
    Person p[SIZE];
    char name[64];
    char address[64];
    int age;
    // Taking input for 10 persons
    for (int i = 0; i < SIZE; i++)
    {
        cout << "\nEnter details of Person " << i + 1 << endl;
        cout << "Enter name: ";
        cin.ignore();
        cin.getline(name, 64);
        cout << "Enter age: ";
        cin >> age;
        cin.ignore();
        cout << "Enter address: ";
        cin.getline(address, 64);
        p[i] = Person(name, age, address);
    }
    // Display youngest and oldest age
    cout << "\nYoungest age : "
         << Person::youngestAge(p, SIZE) << endl;
    cout << "Oldest age   : "
         << Person::oldestAge(p, SIZE) << endl;
    return 0;
}
