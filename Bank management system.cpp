#include <fstream>
#include <iostream>
using namespace std;

void delete_heap(char *name, char *pass, char *dob, char *cnic, char *contact)
{
    delete[] name;
    name = NULL;
    delete[] pass;
    pass = NULL;
    delete[] dob;
    dob = NULL;
    delete[] cnic;
    cnic = NULL;
    delete[] contact;
    contact = NULL;
}

int account_number(ifstream& read)
{
    int num = 0;
    char waste;
    char *name = new char[50];
    char *pass = new char[6];
    char *dob = new char[10];
    char *cnic = new char[15];
    char *contact = new char[15];
    double amount = 0;
    read.open("bank.txt");

    while (read>>num)
    {
        read >> waste;
        read.getline(name, 50, ',');
        read.getline(pass, 6, ',');
        read.getline(dob, 9, ',');
        read.getline(cnic, 15, ',');
        read.getline(contact, 15, ',');
        read >> amount;
        read >> waste;
    }
    delete_heap(name, pass, dob, cnic, contact);
    return num;
}

bool compare_pass(char pass_user[], char *pass)
{
    int x = 0;
    for (int i = 0; i < 5; i++)
    {
        if (pass_user[i] == pass[i])
        {
            x++;
        }
    }
    if (x == 5)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void update_file(ifstream &read, ofstream &write, int num_user)
{
    int num = 0;
    char waste;
    char *name = new char[50];
    char *pass = new char[6];
    char *dob = new char[9];
    char *cnic = new char[15];
    char *contact = new char[15];
    double amount = 0;
    read.open("bank.txt");
    write.open("temp.txt", ios::app);

    while (read >> num)
    {
        read >> waste;
        read.getline(name, 50, ',');
        read.getline(pass, 6, ',');
        read.getline(dob, 9, ',');
        read.getline(cnic, 15, ',');
        read.getline(contact, 15, ',');
        read >> amount;
        read >> waste;
        if (num == num_user)
        {
            cout << "Enter your updated Name: ";
            cin.ignore();
            cin.getline(name, 50);
            cout<<"Enter your updated Password: ";
            cin.ignore();
            cin>>pass;
            cout << "Enter your updated Date of Birth (DDMMYYYY): ";
            cin.ignore();
            cin.getline(dob, 10);
            cout << "Enter your updated contact number : ";
            cin.ignore();
            cin.getline(contact, 15);
            write << num << "," << name << "," << pass << "," << dob << "," << cnic << "," << contact << "," << amount << ",\n";
        }

        else
        {
            write << num << "," << name << "," << pass << "," << dob << "," << cnic << "," << contact << "," << amount << ",\n";
        }
    }
    read.close();
    write.close();
    write.open("bank.txt");
    write.close();
    write.open("bank.txt", ios::app);
    read.open("temp.txt");
    while (read >> num)
    {
        read >> waste;
        read.getline(name, 50, ',');
        read.getline(pass, 6, ',');
        read.getline(dob, 9, ',');
        read.getline(cnic, 15, ',');
        read.getline(contact, 15, ',');
        read >> amount;
        read >> waste;
        write << num << "," << name << "," << pass << "," << dob << "," << cnic << "," << contact << "," << amount << ",\n";
    }
    read.close();
    write.close();
    delete_heap(name, pass, dob, cnic, contact);
    write.open("temp.txt");
    write.close();
}

bool check_existance(int ac_num, ifstream &read)
{
    int num = 0;
    char waste;
    char *name = new char[50];
    char *pass = new char[6];
    char *dob = new char[9];
    char *cnic = new char[15];
    char *contact = new char[15];
    double amount = 0;
    read.open("bank.txt");
    while (read >> num)
    {
        read >> waste;
        read.getline(name, 50, ',');
        read.getline(pass, 6, ',');
        read.getline(dob, 9, ',');
        read.getline(cnic, 15, ',');
        read.getline(contact, 15, ',');
        read >> amount;
        read >> waste;
        if (num == ac_num)
        {
            delete_heap(name, pass, dob, cnic, contact);
            read.close();
            return true;
            break;
        }
    }
    read.close();
    delete_heap(name, pass, dob, cnic, contact);
    return false;
}

bool check_password(int num_user, char pass_user[], ifstream &read)
{
    int num = 0;
    char waste;
    char *name = new char[50];
    char *pass = new char[6];
    char *dob = new char[9];
    char *cnic = new char[15];
    char *contact = new char[15];
    double amount = 0;
    read.open("bank.txt");
    while (read >> num)
    {
        read >> waste;
        read.getline(name, 50, ',');
        read.getline(pass, 6, ',');
        read.getline(dob, 9, ',');
        read.getline(cnic, 15, ',');
        read.getline(contact, 15, ',');
        read >> amount;
        read >> waste;
        if (num == num_user && compare_pass(pass_user, pass))
        {
            delete_heap(name, pass, dob, cnic, contact);
            read.close();
            return true;
            break;
        }
    }
    read.close();
    delete_heap(name, pass, dob, cnic, contact);
    return false;
}

void new_account(ofstream &write,ifstream& read)
{
    int num = 0;
    char *name = new char[50];
    char *pass = new char[6];
    char *dob = new char[9];
    char *cnic = new char[15];
    char *contact = new char[15];
    double amount = 0;
    cout << "Enter your Name: ";
    cin.ignore();
    cin.getline(name, 50);
    cout << "Enter your Password (5 digit): ";
    cin.ignore();
    cin>>pass;
    cout << "Enter your Date of Birth (DDMMYYYY): ";
    cin.ignore();
    cin >> dob;
    cout << "Enter your CNIC Number without space: ";
    cin.ignore();
    cin >> cnic;
    cout << "Enter your Contact number: ";
    cin.ignore();
    cin >> contact;
    cout << "Enter The Initial amount(500 for Saving and 1000 for current): ";
    cin.ignore();
    cin >> amount;
    write.open("bank.txt", ios::app);
    write << account_number(read)+1 << "," << name << "," << pass << "," << dob << "," << cnic << "," << contact << "," << amount << ",\n";
    write.close();
    delete_heap(name, pass, dob, cnic, contact);
}

int check_amount(int amount_user,int ac_num,ifstream& read)
{
    int num = 0;char waste;
    char *name = new char[50];
    char *pass = new char[6];
    char *dob = new char[9];
    char *cnic = new char[15];
    char *contact = new char[15];
    double amount = 0;

    while (read >> num)
    {
        read >> waste;
        read.getline(name, 50, ',');
        read.getline(pass, 6, ',');
        read.getline(dob, 9, ',');
        read.getline(cnic, 15, ',');
        read.getline(contact, 15, ',');
        read >> amount;
        read >> waste;
        if (num == ac_num)
        {
            return amount;
            break;
        }
    }
        delete_heap(name, pass, dob, cnic, contact);
}

void deposit(int amount_user,int num_user,ifstream& read,ofstream& write)
{
    int num = 0;
    char waste;
    char *name = new char[50];
    char *pass = new char[6];
    char *dob = new char[10];
    char *cnic = new char[15];
    char *contact = new char[15];
    double amount = 0;
    read.open("bank.txt");
    write.open("temp.txt", ios::app);

    while (read >> num)
    {
        read >> waste;
        read.getline(name, 50, ',');
        read.getline(pass, 6, ',');
        read.getline(dob, 9, ',');
        read.getline(cnic, 15, ',');
        read.getline(contact, 15, ',');
        read >> amount;
        read >> waste;
        if (num == num_user)
        {
            write << num << "," << name << "," << pass << "," << dob << "," << cnic << "," << contact << "," << amount+amount_user << ",\n";
        }

        else
        {
            write << num << "," << name << "," << pass << "," << dob << "," << cnic << "," << contact << "," << amount << ",\n";
        }
    }
    read.close();
    write.close();
    write.open("bank.txt");
    write.close();
    write.open("bank.txt", ios::app);
    read.open("temp.txt");
    while (read >> num)
    {
        read >> waste;
        read.getline(name, 50, ',');
        read.getline(pass, 6, ',');
        read.getline(dob, 9, ',');
        read.getline(cnic, 15, ',');
        read.getline(contact, 15, ',');
        read >> amount;
        read >> waste;
        write << num << "," << name << "," << pass << "," << dob << "," << cnic << "," << contact << "," << amount << ",\n";
    }
    read.close();
    write.close();
    delete_heap(name, pass, dob, cnic, contact);
    write.open("temp.txt");
    write.close();
}

void withdraw(int amount_user,int num_user,ifstream& read,ofstream& write)
{
     int num = 0;
    char waste;
    char *name = new char[50];
    char *pass = new char[6];
    char *dob = new char[10];
    char *cnic = new char[15];
    char *contact = new char[15];
    double amount = 0;
    read.open("bank.txt");
    write.open("temp.txt", ios::app);

    while (read >> num)
    {
        read >> waste;
        read.getline(name, 50, ',');
        read.getline(pass, 6, ',');
        read.getline(dob, 9, ',');
        read.getline(cnic, 15, ',');
        read.getline(contact, 15, ',');
        read >> amount;
        read >> waste;
        if (num == num_user)
        {
            write << num << "," << name << "," << pass << "," << dob << "," << cnic << "," << contact << "," << amount-amount_user << ",\n";
        }

        else
        {
            write << num << "," << name << "," << pass << "," << dob << "," << cnic << "," << contact << "," << amount << ",\n";
        }
    }
    read.close();
    write.close();
    write.open("bank.txt");
    write.close();
    write.open("bank.txt", ios::app);
    read.open("temp.txt");
    while (read >> num)
    {
        read >> waste;
        read.getline(name, 50, ',');
        read.getline(pass, 6, ',');
        read.getline(dob, 9, ',');
        read.getline(cnic, 15, ',');
        read.getline(contact, 15, ',');
        read >> amount;
        read >> waste;
        write << num << "," << name << "," << pass << "," << dob << "," << cnic << "," << contact << "," << amount << ",\n";
    }
    read.close();
    write.close();
    delete_heap(name, pass, dob, cnic, contact);
    write.open("temp.txt");
    write.close();
}

void modify(ifstream &read, ofstream &write)
{
    int num_user;
    char waste;
    char pass_user[6] = {'\0'};
    int num = 0;
    char *name = new char[50];
    char *pass = new char[6];
    char *dob = new char[9];
    char *cnic = new char[15];
    char *contact = new char[15];
    double amount = 0;
    cout << "Enter your account Number: ";
    cin >> num_user;

    if (check_existance(num_user, read))
    {
        while (true)
        {
            cout << "Enter your Pasword(5 digit): ";
            cin >> pass_user;
            if (check_password(num_user, pass_user, read))
            {
                update_file(read, write, num_user);
                break;
            }
            else
            {
                cout << "Incorrect Password!!!" << endl
                     << endl;
            }
        }
    }
}

void account_info(int ac_num,ifstream& read)
{

    int num = 0;
    char waste;
    char *name = new char[50];
    char *pass = new char[6];
    char *dob = new char[9];
    char *cnic = new char[15];
    char *contact = new char[15];
    double amount = 0;
    read.open("bank.txt");
    while (read >> num)
    {
        read >> waste;
        read.getline(name, 50, ',');
        read.getline(pass, 6, ',');
        read.getline(dob, 9, ',');
        read.getline(cnic, 15, ',');
        read.getline(contact, 15, ',');
        read >> amount;
        read >> waste;
        if (num == ac_num)
        {
            cout<<"\nAcount Number is: "<<num;
            cout<<"\nName of account holder is: "<<name;
            cout<<"\nAcount Password is: "<<pass;
            cout<<"\nDate o Birth is: "<<dob;
            cout<<"\nCNIC Number is: "<<cnic;
            cout<<"\nContact Number is: "<<contact;
            cout<<"\nAmount is: "<<amount;
            delete_heap(name, pass, dob, cnic, contact);
            read.close();
            break;
        }
    }
    read.close();
}

void transaction(ifstream &read,ofstream& write)
{
    int num, amount,choice;
    char pass[6];
    cout << "Enter your account number: ";
    cin >> num;
    if (check_existance(num, read))
    {
        cout << "Enter your password: ";
        cin.ignore();
        cin.getline(pass, 6);
        if (check_password(num, pass, read))
        {
            cout<<"Press 1 for deposit \n";
            cout<<"Press 2 for withdraw \n\n";
            cout<<"Enter Option: ";
            cin>>choice;
            if(choice==1)
            {
                cout<<"\nEnter deposit amount: ";cin>>amount;
                deposit(amount,num,read,write);
                cout<<"\nAmount Deposited!!!\n";
            }
            else if(choice==2)
            {
                cout<<"\nEnter withdraw amount: ";cin>>amount;
                if(amount<check_amount(amount,num,read))
                {
                    withdraw(amount,num,read,write);
                    cout<<"\nAmount withdrawed!!!\n";
                }
                else{
                    cout<<"\nYou have not enough amount!!!\n";
                }
            }
            else{
                cout<<"Incorrect option!!!\n";
            }
        }
        else
        {
            cout << "Incorrect password!!!" << endl;
        }
    }
    else
    {
        cout << "Incorrect account number!!!" << endl;
    }
}

void remove_account(ifstream &read, ofstream &write, int num_user)
{
    int num = 0;
    char waste;
    char *name = new char[50];
    char *pass = new char[6];
    char *dob = new char[9];
    char *cnic = new char[15];
    char *contact = new char[15];
    double amount = 0;
    read.open("bank.txt");
    write.open("temp.txt", ios::app);

    while (read >> num)
    {
        read >> waste;
        read.getline(name, 50, ',');
        read.getline(pass, 6, ',');
        read.getline(dob, 9, ',');
        read.getline(cnic, 15, ',');
        read.getline(contact, 15, ',');
        read >> amount;
        read >> waste;
        if (num != num_user)
        {
            write << num << "," << name << "," << pass << "," << dob << "," << cnic << "," << contact << "," << amount << ",\n";
        }

    }
    read.close();
    write.close();
    write.open("bank.txt");
    write.close();
    write.open("bank.txt", ios::app);
    read.open("temp.txt");
    while (read >> num)
    {
        read >> waste;
        read.getline(name, 50, ',');
        read.getline(pass, 6, ',');
        read.getline(dob, 9, ',');
        read.getline(cnic, 15, ',');
        read.getline(contact, 15, ',');
        read >> amount;
        read >> waste;
        write << num << "," << name << "," << pass << "," << dob << "," << cnic << "," << contact << "," << amount << ",\n";
    }
    read.close();
    write.close();
    delete_heap(name, pass, dob, cnic, contact);
    write.open("temp.txt");
    write.close();
}

void customers_list(ifstream& read)
{
    int i=1;
    int num = 0;
    char waste;
    char *name = new char[50];
    char *pass = new char[6];
    char *dob = new char[9];
    char *cnic = new char[15];
    char *contact = new char[15];
    double amount = 0;
    read.open("bank.txt");
    while (read >> num)
    {
        read >> waste;
        read.getline(name, 50, ',');
        read.getline(pass, 6, ',');
        read.getline(dob, 10, ',');
        read.getline(cnic, 15, ',');
        read.getline(contact, 15, ',');
        read >> amount;
        read >> waste;

        cout<<i<<" - "<<name<<endl;i++;
    }
}

int menu()
{
    int choice;
    cout << "\t\t\t<<<<<<<<>  WELCOME TO MAIN MENU  <>>>>>>>>\n";
    cout << "\n\t\tPress 1 to Create New Account";
    cout << "\n\t\tPress 2 to Modify an existing Account";
    cout << "\n\t\tPress 3 for transactions";
    cout << "\n\t\tPress 4 to check information of an existing Account";
    cout << "\n\t\tPress 5 to remove an existing Account";
    cout << "\n\t\tPress 6 to view customers list";
    cout << "\n\t\tPress 7 to Exit";
    cout << "\nEnter option: ";
    cin >> choice;
    return choice;
}

int main()
{
    ifstream read;
    ofstream write;
    int choice,ac_num;
    char pass[6];

    cout << "\t\t\t<<<<<<<<>  BANK MANAGEMENT SYSTEM  <>>>>>>>>\n";

    while (true)
    {
        choice = menu();
        if (choice == 1)
        {
            new_account(write,read);
        }
        else if (choice == 2)
        {
            modify(read, write);
        }
        else if (choice == 3)
        {
            transaction(read,write);
        }
        else if (choice == 4)
        {
            cout<<"Enter account number: ";
            cin>>ac_num;
            if(check_existance(ac_num,read))
            {
                cout<<"Enter your password (5 digit): ";
                cin.ignore();
                cin.getline(pass,6);
                if(check_password(ac_num,pass,read))
                {
                    account_info(ac_num,read);
                }
                else{
                    cout<<"Incorrect password!!!"<<endl;
                }
            }
            else{
                cout<<"Account does not exist!!!"<<endl;
            }
        }
        else if (choice == 5)
        {
             cout<<"Enter account number: ";
            cin>>ac_num;
            if(check_existance(ac_num,read))
            {
                cout<<"Enter your password (5 digit): ";
                cin.ignore();
                cin.getline(pass,6);
                if(check_password(ac_num,pass,read))
                {
                    remove_account(read,write,ac_num);
                }
                else{
                    cout<<"Incorrect password!!!"<<endl;
                }
            }
            else{
                cout<<"Account does not exist!!!"<<endl;
            }
        }
        else if (choice == 6)
        {
            customers_list(read);
        }
        else if (choice == 7)
        {
            return 0;
        }
        else
        {
            cout<<"\nIncorrect option!!!\n";
            cout<<"Try again!!!\n";
        }
    }

    return 0;
}
