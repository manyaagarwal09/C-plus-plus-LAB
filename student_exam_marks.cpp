#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Student
{
private:
    int rollNo;
    string name;

public:
    Student(int r, string n)
    {
        rollNo = r;
        name = n;
    }

    void displayStudent() const
    {
        cout << "Roll No: " << rollNo << endl;
        cout << "Name: " << name << endl;
    }
};

class Exam : public Student
{
private:
    float marks[6];

public:
    Exam(int r, string n, float m[])
        : Student(r, n)
    {
        for (int i = 0; i < 6; i++)
            marks[i] = m[i];
    }

    float getMark(int i) const
    {
        return marks[i];
    }

    void displayMarks() const
    {
        cout << "\nMarks:\n";

        for (int i = 0; i < 6; i++)
            cout << "Subject " << i + 1 << ": "
                 << marks[i] << endl;
    }
};

class Result : public Exam
{
private:
    float totalMarks;

public:
    Result(int r, string n, float m[])
        : Exam(r, n, m)
    {
        totalMarks = 0;
    }

    void calculateTotal()
    {
        totalMarks = 0;

        for (int i = 0; i < 6; i++)
            totalMarks += getMark(i);
    }

    void displayResult() const
    {
        cout << "\n===== RESULT =====\n";

        displayStudent();
        displayMarks();

        cout << fixed << setprecision(2);
        cout << "\nTotal Marks: " << totalMarks << endl;
        cout << "Percentage: "
             << (totalMarks / 600) * 100 << "%" << endl;
    }
};

int main()
{
    int rollNo;
    string name;
    float marks[6];

    cout << "Enter Roll No: ";
    cin >> rollNo;

    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, name);

    cout << "Enter marks for 6 subjects:\n";

    for (int i = 0; i < 6; i++)
    {
        cout << "Subject " << i + 1 << ": ";
        cin >> marks[i];

        while (marks[i] < 0 || marks[i] > 100)
        {
            cout << "Invalid marks! Enter marks between 0 and 100: ";
            cin >> marks[i];
        }
    }

    Result r(rollNo, name, marks);

    r.calculateTotal();
    r.displayResult();

    return 0;
}
