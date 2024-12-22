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

void shopping ::add()
{
m:
    fstream data;
    int c;
    int token = 0;
    float p;
    float d;
    string n;

    cout << "\n\t\tAdd new Product";
    cout << "\n\tProduct code: ";
    cin >> pcode;
    cout << "Name of the Product: ";
    cin >> pname;
    cout << "\n\tPrice of the Product: ";
    cout << "Discout on the Product: ";
    cin >> dis;

    data.open("database.txt", ios::in);
    if (!data)
    {
        data.open("database.txt", ios::app | ios::out);
        data << " " << pname << " " << price << " " << dis << "\n";
        data.close();
    }
    else
    {
        data >> c >> n >> p >> d;
        while (!data.eof())
        {
            if (c == pcode)
            {
                token++;
            }
            data >> c >> n >> p >> d;
        }
        data.close();

        if (token == 1)
            goto m;
        else
        {
            data.open("database.txt", ios::app | ios::out);
            data << " " << pname << " " << price << " " << dis << "\n";
            data.close();
        }
    }
    cout << "\n\t\tRecord inserted!";
}
void shopping::edit()
{
    fstream data, data1;
    int pkey;
    int token = 0;
    int c;
    float p;
    float d;
    string n;

    cout << "\n\t\t Modify the record";
    cout << "\n\t\tProduct code: ";
    cin >> pkey;

       data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "\n\nFile doesn't exist!";
    }
    else
    {
        data1.open("database1.txt", ios::app | ios::out);

        data >> pcode >> pname >> price >> dis;
        while (!data.eof())
        {
            if (pkey == pcode)
            {
                cout << "\n\tProduct new code: ";
                cin >> c;
                cout << "\n\tName of the Product: ";
                cin >> n;
                cout << "\n\tPrice: ";
                cin >> p;
                cout << "\n\tDiscount";
                cin >> d;
                data1 << " " << n << " " << p << " " << "d" << "\n";
                cout << "\n\tRecord Edited";
                token++;
            }
            else
            {
                data1 << " " << pcode << " " << price << " " << dis << "\n";
            }
            data >> pcode >> pname >> price >> dis;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt", "database.txt");
        if (token == 0)
        {
            cout << "\nRecord not found sorry!";
        }
    }
}

void shopping::rem()
{
    fstream data, data1;
    int pkey;
    int token = 0;
    cout << "\n\t Delete product";
    cout << "\n\t Product code: ";
    cin >> pkey;
    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "File doesn't exist";
    }
    else
    {
        data1.open("database1.txt", ios::app | ios::out);
        data >> pcode >> pname >> price >> dis;
        while (data.eof())
        {
            if (pcode == pkey)
            {
                cout << "\n\tProduct delete successful";
                token++;
            }
            else
            {
                data1 << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
            }
            data >> pcode >> pname >> price >> dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt", "database.txt");
        if (token == 0)
        {
            cout << "\n\nRecord not found";
        }
    }
}

void shopping ::list()
{
    fstream data;
    data.open("database.txt", ios::in);
    cout << "\n\nProNo\tName\tprice";
    data >> pcode >> pname >> price >> dis;
    while (!data.eof())
    {
        cout << pcode << "\t\t" << pname << "\t\t" << price << "\n";
        data >> pcode >> pname >> price >> dis;
    }
    data.close();
}

void shopping::receipt()
{
    fstream data;

    int arrc[100];
    int arrq[100];
    char choice;
    int c = 0;
    float amount = 0;
    float dis = 0;
    float total = 0;

    cout << "\n\t\t\t\tRECEIPT";
    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "\n\tEmpty database.";
    }
    else
    {
        data.close();
        list();
        cout << "\n\t\t\tPlease place the order";
          do
        {
        m:
            cout << "\nEnter product code: ";
            cin >> arrc[c];
            cout << "\nEnter the product quantity: ";
            cin >> arrq[c];
            for (int i = 0; i < c; i++)
            {
                if (arrc[c] == arrc[i])
                {
                    cout << "\n\nDuplicate product code. Please try again";
                    goto m;
                }
            }
            c++;
            cout << "\n\nDo you want to buy another product? if Yes then pess y else no: ";
            cin >> choice;
        } while (choice == "y");

        cout << "\n\n\t\t-----RECEIPT-------\n";
        cout << "\nProduct No\t Product quantity\tAmount \tAmount with discount";

        for (int i = 0; i < c; i++)
        {
            data.open("database.txt", ios::in);
            data >> pcode >> pname >> price >> dis;
            while (!data.eof())
            {
                if (pcode == arrc[i])
                {
                    amount = price * arrq[i];
                    dis = amount - (amount * dis / 100);
                    total = total + dis;
                    cout << "\n"
                         << pcode << "\t\t" << arrq[i] << "\t\t" << price << "\t" << amount << "\t\t" << dis;
                }
                data >> pcode >> pname >> price >> dis;
            }
        }
        data.close();
    }
     cout << "\n\n_____________________________";
    cout << "\n Total Amount : " << total;
}
int main()
{
    shopping s;
    s.menu();
}