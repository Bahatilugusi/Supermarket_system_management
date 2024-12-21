#include <iostream>
#include <fstream>

using namespace std;

class shopping
{
private:
    int pcode;
    float price;
    float dis;
    string pname;

public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void rem();
    void list();
    void receipt();
};

void shopping ::menu()
{
m:
    int choice;
    string email;
    string password;

    cout << "\n\t\tSupermarket Main Menu\n";
    cout << "\n1> Administrator";
    cout << "\n2> Buyer";
    cout << "\n3> Exit";
    cout << "Please Select your choice";

    switch (choice)
    {
    case 1:
        cout << "\n\tPlease Login";
        cout << "Enter Email: ";
        cin >> email;
        cout << "Enter Your password: ";
        cin >> password;

        if (password == "buna")
        {
            administrator();
        }
        else
        {
            cout << "incorrect password!";
        }
        break;

    case 2:
        buyer();
        break;

    case 3:
        exit(0);
        break;

    default:
        cout << "Please select from the given options";
        break;
    }
    goto m;
}

void shopping ::administrator()
{
m:
    int choice;
    cout << "\n\t\tAdministrator Menu";
    cout << "\n\t1. Add product";
    cout << "\n\t2. Modify the Product";
    cout << "\n\t3. Delete the product";
    cout << "\n\t4. Back to main menu now";

    cout << "Please Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        add();
        break;
    case 2:
        edit();
        break;
    case 3:
        rem();
        break;
    case 4:
        menu();
        break;
    default:
        cout << "\nInvalid choice";
        break;
    }
    goto m;
}

void shopping ::buyer()
{
m:
    int choice;
    cout << "\n\t\tBuyer Menu";
    cout << "\n\t1.Buy Product";
    cout << "\n\tGo back";
    cout << "Enter your choice";
    cin >> choice;

    switch (choice)
    {
    case 1:
        receipt();
        break;

    case 2:
        menu();
        break;

    default:
        cout << "\nInvalid choice";
        break;
    }
    goto m;
}