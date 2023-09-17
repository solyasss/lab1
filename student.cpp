#include <iostream>
#include <cstring>
using namespace std;

class Student
{
    char *name;
    int age;
    char *email;

public:
    Student()
    {
        cout << "Default Constructor" << endl;
        name = nullptr;
        age = 0;
        email = nullptr;
    }

    Student(const char *n, int a, const char *e)
    {
        cout << "Constructor with 3 params" << endl;
        name = new char[strlen(n) + 1];
        strcpy(name, n);
        age = a;
        email = new char[strlen(e) + 1];
        strcpy(email, e);
    }

    const char *getEmail()
    {
        return email;
    }

    void setEmail(const char *e)
    {
        if (email != nullptr)
        {
            delete[] email;
        }
        email = new char[strlen(e) + 1];
        strcpy(email, e);
    }

    void Input()
    {
        char buff[20];
        cout << "Enter name: ";
        cin >> buff;
        if (name != nullptr)
        {
            cout << "Deleting -> " << name << endl;
            delete[] name;
        }
        name = new char[strlen(buff) + 1];
        strcpy(name, buff);

        cout << "Enter age: ";
        cin >> age;

        char emailBuff[50];
        cout << "Enter email: ";
        cin >> emailBuff;
        setEmail(emailBuff);
    }

    void Print()
    {
        cout << "Name: " << name << "\tAge: " << age << "\tEmail: " << email << endl;
    }

    ~Student()
    {
        cout << "Destructor" << endl;
        delete[] name;
        delete[] email;
    }
};

int main()
{
    Student obj1("Oleg", 20, "oleg@example.com");
    obj1.Print();
    obj1.Input();
    obj1.Print();

    return 0;
}
