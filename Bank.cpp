#include <iostream>
#include <windows.h>
#include <limits>
using namespace std;
void setColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

class profile1
{
private:
    string name, password = "Ced";

public:
};

class profile2
{
private:
    string name, password = "wong";

public:
};

class profile3
{
private:
    string name, password = "james";

public:
};

class BankAccount
{
private:
    float balance = 0.0;

public:
    BankAccount(float initialBal)
    {
        balance = initialBal;
    }
    float AddMoney(float value)
    {
        value = value + balance;
        balance = 0.0;
        balance = value + balance;
        return value;
    }

    float LoanMoney(float valueL)
    {
        if (balance == 0.0)
        {
            valueL = balance - valueL;
            balance = 0.0;
            balance = valueL - balance;
        }
        else
        {
            if (balance > valueL)
            {
                valueL = balance - valueL;
                balance = 0.0;
                balance = valueL - balance;
            }
            else if (balance < valueL)
            {
                valueL = valueL - balance;
                balance = 0.0;
                balance = valueL - balance;
            }
        }
        return valueL;
    }

    float Balance() const
    {
        return balance;
    }
};
int main()
{
    system("cls");
    string arr[] = {
        "WELCOME", " WELCOME", "  WELCOME", "   WELCOME", "    WELCOME",
        "     WELCOM", "      WELCO", "       WELC", "        WEL",
        "         WE", "          W", "           ",
        "E", "ME", "OME", "COME", "LCOME", "ELCOME"};

    int size = sizeof(arr) / sizeof(arr[0]);

    // Animation loop with color change
    for (int i = 0; i < 20; i++)
    {
        setColor(2 + (i % 6)); // Cycle through colors
        cout << "\r" << arr[i % size] << flush;
        Sleep(125);
    }

    // Flashing final welcome message
    for (int j = 0; j < 3; j++)
    {
        setColor(14); // Yellow
        cout << "\r   WELCOME" << flush;
        Sleep(300);
        setColor(4); // Red
        cout << "\r   WELCOME" << flush;
        Sleep(300);
    }

    setColor(7); // Reset to default color
    cout << "\r   WELCOME" << flush;

    Sleep(500);
    system("cls");
    float initialBal;
    BankAccount bank(initialBal);
    while (true)
    {
    end:
        string pass;
        cout << "Enter Password: " << endl;
        cin >> pass;
        if (pass != "password")
        {
            while (pass != "password")
            {
                system("cls");
                cout << "Invalid Password!" << endl;
                Sleep(1000);
                system("cls");
                cout << "Enter Password: " << endl;
                cin >> pass;
            }
        }
        if (pass == "password")
        {
            system("cls");
            while (true)
            {
                cout << "Add(1)" << endl;
                cout << "Loan(2)" << endl;
                cout << "Balance(3)" << endl;
                cout << "Return(4)" << endl;
                cout << "End(5)" << endl;
                int banks;
                cin >> banks;
                system("cls");
                switch (banks)
                {
                case 1:
                    float value;
                    cout << "Enter Value to Add" << endl;
                    cin >> value;
                    if (cin.fail())
                    {
                        while (cin.fail())
                        {
                            system("cls");
                            cout << "You did not enter any number" << endl;
                            Sleep(1000);
                            system("cls");
                            cin.clear();
                            cout << "Please input a valid input..." << endl;
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cin >> value;
                            system("cls");
                            cout << "Added: " << value << endl;
                            Sleep(1000);
                            bank.AddMoney(value);
                            system("cls");
                        }
                    }
                    else
                    {
                        system("cls");
                        cout << "Added: " << value << endl;
                        Sleep(1000);
                        bank.AddMoney(value);
                        system("cls");
                    }
                    break;
                case 2:
                    float valueL;
                    cout << "Enter Value to Loan" << endl;
                    cin >> valueL;
                    if (cin.fail())
                    {
                        while (cin.fail())
                        {
                            system("cls");
                            cout << "You did not enter any number" << endl;
                            Sleep(1000);
                            system("cls");
                            cin.clear();
                            cout << "Please input a valid input..." << endl;
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cin >> valueL;
                            system("cls");
                            cout << "Loaned: " << valueL;
                            Sleep(1000);
                            bank.LoanMoney(valueL);
                            system("cls");
                        }
                    }
                    else
                    {
                        system("cls");
                        cout << "Loaned: " << valueL;
                        Sleep(1000);
                        bank.LoanMoney(valueL);
                        system("cls");
                    }
                    break;
                case 3:
                    system("cls");
                    cout << "Balance is: ";
                    cout << bank.Balance();
                    Sleep(2000);
                    cout << endl;
                    int press;
                    cout << "Press any letter to Exit..." << endl;
                    cout << "Press any number to Return..." << endl;
                    cin >> press;
                    if (cin.fail())
                    {
                        cin.clear();
                        system("cls");
                        return 0;
                    }
                    else
                    {
                        system("cls");
                        break;
                    }
                case 4:
                    goto end;
                case 5:
                    system("cls");
                    return 0;
                }
            }
        }
    }
}
