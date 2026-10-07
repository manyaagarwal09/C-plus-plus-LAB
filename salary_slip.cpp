#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

const int SIZE = 10;

class Person
{
    char name[64];
    int age;
    char address[64];

    // Salary components
    float basic;
    float hra;
    float da;
    float ta;
    float grossSalary;

    void calculateSalary()
    {
        hra = 0.20f * basic;
        da = 0.50f * basic;
        ta = 1500.0f;

        grossSalary = basic + hra + da + ta;
    }

public:

    // Default constructor
    Person()
    {
        strcpy(name, "Unknown");
        age = 0;
        strcpy(address, "Unknown");

        basic = 0;
        hra = 0;
        da = 0;
        ta = 0;
        grossSalary = 0;
    }

    // Parameterized constructor
    Person(const char n[], int a, const char addr[], float b)
    {
        strcpy(name, n);
        age = a;
        strcpy(address, addr);

        basic = b;

        calculateSalary();
    }

    // Display salary slip
    void displaySalarySlip() const
    {
        cout << fixed << setprecision(2);

        cout << "\n========================================\n";
        cout << "              SALARY SLIP\n";
        cout << "========================================\n";

        cout << "Name    : " << name << endl;
        cout << "Age     : " << age << endl;
        cout << "Address : " << address << endl;

        cout << "----------------------------------------\n";
        cout << left << setw(25) << "EARNINGS"
             << right << setw(15) << "Amount" << endl;

        cout << left << setw(25) << "Basic Pay"
             << right << setw(15) << basic << endl;

        cout << left << setw(25) << "HRA (20%)"
             << right << setw(15) << hra << endl;

        cout << left << setw(25) << "DA (50%)"
             << right << setw(15) << da << endl;

        cout << left << setw(25) << "Travel Allowance"
             << right << setw(15) << ta << endl;

        cout << left << setw(25) << "Gross Salary"
             << right << setw(15) << grossSalary << endl;

        cout << "========================================\n";
    }
};

int main()
{
    // Array of 10 Person objects
    Person p[SIZE];

    char name[64];
    char address[64];
    int age;
    float basic;

    // Take input for 10 persons
    for (int i = 0; i < SIZE; i++)
    {
        cout << "\nEnter details of Person " << i + 1 << endl;

        cout << "Enter Name: ";
        cin.getline(name, 64);

        cout << "Enter Age: ";
        cin >> age;
        cin.ignore();

        cout << "Enter Address: ";
        cin.getline(address, 64);

        cout << "Enter Basic Salary: ";
        cin >> basic;
        cin.ignore();

        // Parameterized constructor
        p[i] = Person(name, age, address, basic);
    }

    // Display salary slips
    for (int i = 0; i < SIZE; i++)
    {
        p[i].displaySalarySlip();
    }

    return 0;
}