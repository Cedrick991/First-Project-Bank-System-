#include<iostream>
#include<conio.h>
#include<windows.h>
using namespace std;
class BankAccount{
    private:
    float balance = 0.0;
    public:
    BankAccount(float initialBal){
        balance = initialBal;
    }
    float AddMoney(float value){
        value = value + balance;
        balance = 0.0;
        balance = value + balance;
        return value;
    }

    float LoanMoney(float valueL){
        if(balance>valueL){
        valueL = balance - valueL;
        balance = 0.0;
        balance = valueL - balance;
        }else if(balance<valueL){
        valueL = valueL - balance;
        balance = 0.0;
        balance = valueL - balance;
        }
        return valueL;
    }

    float Balance() const{
        return balance;
    }
};
int main(){
    float initialBal;
    BankAccount bank(initialBal);
    string pass;
    cout<<"Enter Password: "<<endl;
    cin>>pass;
    if(pass != "password"){
        while(pass != "password"){
            system("cls");
            cout<<"Invalid Password!"<<endl;
            Sleep(1000);
            system("cls");
            cout<<"Enter Password: "<<endl;
            cin>>pass;
        }
    }
    if(pass == "password"){
    system("cls");
    while(true){
        cout<<"Add(1)"<<endl;
        cout<<"Loan(2)"<<endl;
        cout<<"Balance(3)"<<endl;
        cout<<"End(4)"<<endl;
        int banks;
        cin>>banks;
        system("cls");
        switch(banks){
        case 1:
            float value;
            cout<<"Enter Value to Add"<<endl;
            cin>>value;
            if(cin.fail()){
            cout<<"You did not enter any number"<<endl;
            system("cls");
            cout<<"Please input a valid input..."<<endl;
            cin>>value;
            }else{
            system("cls");
            cout<<"Added: "<<value<<endl;
            Sleep(1000);
            bank.AddMoney(value);
            system("cls");
            }
            break;
        case 2:
            float valueL;
            cout<<"Enter Value to Loan"<<endl;
            cin>>valueL;
            if(cin.fail()){
            cout<<"You did not enter any number"<<endl;
            system("cls");
            cout<<"Please input a valid input..."<<endl;
            cin>>valueL;
            }else{
            system("cls");
            cout<<"Loaned: "<<valueL;
            Sleep(1000);
            bank.LoanMoney(valueL);
            system("cls");
            }
            break;
        case 3:
            system("cls");
            cout<<"Balance is: ";
            cout<<bank.Balance();
            Sleep(2000);
            cout<<endl;
            int press;
            cout<<"Press Any key to Exit..."<<endl;
            cin>>press;
            if(cin.fail()){
            cout<<"Balance is: ";
            cout<<bank.Balance();
            }else{
            system("cls");
            break;
            }
        case 4:
            system("cls");
            return 0;
            break;
        default  : cout<<"invalid"<<endl;
        break;
    }
    }
}
}