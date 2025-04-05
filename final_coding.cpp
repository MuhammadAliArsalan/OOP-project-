#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>
#include <sstream>
using namespace std;
class manufacturer
{
public:
    string manufacturer_name;
    char manufacturer_gender;
    int manufacturer_age;
    int manufacturer_phone;
    int manufacturer_code;

    void add_manufacturer()
    {
        system("cls");
        add_manufacturer_page:
        fstream add_data;
        int code; // this variable use to read the data to generate the code
        string name;
        int age;
        string gender;
        int phone;
        string date;
        cout << "\t\t\t\t\t \t ----------------------------------------------\n";
        cout << "\t\t\t\t\t \t|                ADD MANUFACTURER              |\n";
        cout << "\t\t\t\t\t \t ----------------------------------------------\n";
        add_data.open("database_manufacturer.txt", ios::in); // file open in read mode
        if (add_data)                                        // if file exit
        {
            while (!add_data.eof())                                 // read the file until end of file
            {                                                       // the purpse to find out the last code of manucature
                add_data >> code >> name >> age >> gender >> phone; // read the data
                if (add_data.eof())                                 // end of file we get the last code of manufacture
                    break;
            }
            add_data.close();
        }
        manufacturer_code = code + 1; // this code is the last code which get from read file
        cout << "\t\t\t\t\t \tGenerated manufacturer code: " << manufacturer_code << endl;
        cout << "\t\t\t\t\t \tEnter manufacturer name: ";
        cin >> manufacturer_name;
        cout << "\t\t\t\t\t \tEnter manufacturer age: ";
        cin >> manufacturer_age;
        cout << "\t\t\t\t\t \tEnter per manufacturer Phone number: ";
        cin >> manufacturer_phone;
        cout << "\t\t\t\t\t \tEnter manufacturer gender: ";
        cin >> manufacturer_gender;
        cout << "\t\t\t\t\t \t ---------------------------------------------\n";
        add_data.open("database_manufacturer.txt", ios::app | ios::out); // write mode opne the file
        add_data << manufacturer_code << "   " << manufacturer_name << "   " << manufacturer_age << "   " << manufacturer_gender << "   " << manufacturer_phone << "\n";
        add_data.close();
        cout << " \t\t\t\t\t \t_____________________________________________\n";
        cout << "\t\t\t\t\t \t|                                             |\n";
        cout << "\t\t\t\t\t \t|         Manufacturer has been saved          |\n";
        cout << "\t\t\t\t\t \t|_____________________________________________|\n";
    }
    void delete_manufacturer()
    {
        system("cls");
        fstream add_data, data;
        int pkey;
        int token = 0; // it is the floag varibale to
        cout << "\t\t\t\t\t \t ----------------------------------------------\n";
        cout << "\t\t\t\t\t \t|                DELETE manufacturer           |\n";
        cout << "\t\t\t\t\t \t ----------------------------------------------\n";
        cout << "\t\t\t\t\t \tEnter Manfucature code: ";
        cin >> pkey;
        add_data.open("database_manufacturer.txt", ios::in);          // read mode
        data.open("database1_manufacturer.txt", ios::app | ios::out); // write mode
        add_data >> manufacturer_code >> manufacturer_name >> manufacturer_age >> manufacturer_gender >> manufacturer_phone;
        while (!add_data.eof())
        {
            if (pkey == manufacturer_code)
            {
                cout << " \t\t\t\t\t \t_____________________________________________\n";
                cout << "\t\t\t\t\t \t|                                             |\n";
                cout << "\t\t\t\t\t \t|       manufacturer has been delete          |\n";
                cout << "\t\t\t\t\t \t|_____________________________________________|\n";
                token++;
            }
            else
            {
                // if manufacaturer code not equal to give code then add data store in txt through data object
                data << "   " << manufacturer_code << "   " << manufacturer_name << "   " << manufacturer_age << "   " << manufacturer_gender << "   "
                     << "   " << manufacturer_phone << "\n";
            }
            // read the data through add_data
            add_data >> manufacturer_code >> manufacturer_name >> manufacturer_age >> manufacturer_gender >> manufacturer_phone;
        }
        add_data.close();
        data.close();
        remove("database_manufacturer.txt");                               // delete the old txt file
        rename("database1_manufacturer.txt", "database_manufacturer.txt"); // new txt file rename by old file anme
        if (token == 0)
        {
            cout << " \t\t\t\t\t \t_____________________________________________\n";
            cout << "\t\t\t\t\t \t|                                             |\n";
            cout << "\t\t\t\t\t \t|     This code of manufacturer not found     |\n";
            cout << "\t\t\t\t\t \t|_____________________________________________|\n";
        }
        system("pause");
    }
    void show_all_manufacturer()
    {
        system("cls");
        fstream data;
        data.open("database_manufacturer.txt", ios::in); // read mode
        cout << "\n\n_________________________________________________________________________\n";
        cout << " Code\t\tName\t\tAge\t\tGender\t\tPhone No\n";
        cout << "_________________________________________________________________________\n";
        data >> manufacturer_code >> manufacturer_name >> manufacturer_age >> manufacturer_gender >> manufacturer_phone;
        while (!data.eof())
        {
            cout << "  " << manufacturer_code << "\t\t" << manufacturer_name << "\t\t" << manufacturer_age << "\t\t" << manufacturer_gender << "\t\t" << manufacturer_phone << "\n";
            data >> manufacturer_code >> manufacturer_name >> manufacturer_age >> manufacturer_gender >> manufacturer_phone;
        }
        cout << "_________________________________________________________________________\n";
        data.close();
    }
    void search_manufacturer()
    {
        system("cls");
        string searchName;
        bool found = false;
        cout << "\t\t\t\t\t \t ----------------------------------------------\n";
        cout << "\t\t\t\t\t \t|          SEARCH manufacturer BY NAME          |\n";
        cout << "\t\t\t\t\t \t ----------------------------------------------\n";
        cout << "\t\t\t\t\t \tEnter manufacturer name to search: ";
        cin >> searchName;
        ifstream data("database_manufacturer.txt");
        string line;
        cout << "\n\n_________________________________________________________________________\n";
        cout << " Code\t\tName\t\tAge\t\tGender\t\tPhone No\n";
        cout << "_________________________________________________________________________\n";
        while (getline(data, line))
        {
            stringstream ss(line); // stringstream object denoted by ss and intialize by line
            // The stringstream class is used individual data items from a string. Here's why stringstream is used:
            // stringstream split the string beacuse we want to get only name from data
            string code, name, age, gender, phone;
            ss >> code >> name >> age >> gender >> phone; // hold the data
            if (name == searchName)
            {
                cout << "  " << code << "\t\t" << name << "\t\t" << age << "\t\t" << gender << "\t\t" << phone << "\n";
                found = true;
            }
        }
        cout << "_________________________________________________________________________\n";
        data.close();
        if (!found)
        {
            cout << " \t\t\t\t\t \t_____________________________________________\n";
            cout << "\t\t\t\t\t \t|        No manufacturer found with that name |\n";
            cout << "\t\t\t\t\t \t|_____________________________________________|\n";
        }
    }
};
class medicine
{
public:
    string medicine_name;
    string expiry_date;
    int medicine_quantity;
    float medicine_per_price;
    int medicine_code;
    void add_medicine()
    {
        string choice = "y";
        while (choice != "n")
        {
            system("cls");
            fstream add_data;
            int code;
            int token = 0;
            string name;
            int price;
            int quantity;
            string date;
            cout << "\t\t\t\t\t \t ----------------------------------------------\n";
            cout << "\t\t\t\t\t \t|                ADD MEDICINE                  |\n";
            cout << "\t\t\t\t\t \t ----------------------------------------------\n";
            add_data.open("database_Medicine.txt", ios::in);
            if (add_data)
            {
                while (!add_data.eof())
                {
                    add_data >> code >> name >> price >> quantity >> date;
                    if (add_data.eof())
                        break;
                }
                add_data.close();
            }
            medicine_code = code + 1;
            cout << "\t\t\t\t\t \tGenerated medicine code: " << medicine_code << endl;
            cout << "\t\t\t\t\t \tEnter Medicine name: ";
            cin >> medicine_name;
            cout << "\t\t\t\t\t \tEnter per Medicine Price: ";
            cin >> medicine_per_price;
            cout << "\t\t\t\t\t \tEnter Medicine quantity: ";
            cin >> medicine_quantity;
            cout << "\t\t\t\t\t \tEnter Medicine expiry date: ";
            cin >> expiry_date;
            cout << "\t\t\t\t\t \t ---------------------------------------------\n";
            add_data.open("database_Medicine.txt", ios::app | ios::out);
            add_data << medicine_code << "   " << medicine_name << "   " << medicine_per_price << "   " << medicine_quantity << "   " << expiry_date << "\n";
            add_data.close();
            cout << " \t\t\t\t\t \t_____________________________________________\n";
            cout << "\t\t\t\t\t \t|                                             |\n";
            cout << "\t\t\t\t\t \t|           Medicine has been saved           |\n";
            cout << "\t\t\t\t\t \t|_____________________________________________|\n";
            cout << "Do you want to add more medicine data? (y/n): ";
            cin >> choice;
        }
    }
    void delete_medicine()
    {
        system("cls");
        fstream add_data, data;
        int pkey;
        int token = 0;
        cout << "\t\t\t\t\t \t ----------------------------------------------\n";
        cout << "\t\t\t\t\t \t|                DELETE MEDICINE               |\n";
        cout << "\t\t\t\t\t \t ----------------------------------------------\n";
        cout << "\t\t\t\t\t \tEnter Medicine code: ";
        cin >> pkey;
        add_data.open("database_Medicine.txt", ios::in);
        data.open("database1_Medicine.txt", ios::app | ios::out);
        add_data >> medicine_code >> medicine_name >> medicine_per_price >> medicine_quantity >> expiry_date;
        while (!add_data.eof())
        {
            if (pkey == medicine_code)
            {
                cout << " \t\t\t\t\t \t_____________________________________________\n";
                cout << "\t\t\t\t\t \t|                                             |\n";
                cout << "\t\t\t\t\t \t|          Medicine has been delete           |\n";
                cout << "\t\t\t\t\t \t|_____________________________________________|\n";
                token++;
            }
            else
            {
                data << "   " << medicine_code << "   " << medicine_name << "   " << medicine_per_price << "   " << medicine_quantity << "   "
                     << "   " << expiry_date << "\n";
            }
            add_data >> medicine_code >> medicine_name >> medicine_per_price >> medicine_quantity >> expiry_date;
        }
        add_data.close();
        data.close();
        remove("database_Medicine.txt");
        rename("database1_Medicine.txt", "database_Medicine.txt");
        if (token == 0)
        {
            cout << " \t\t\t\t\t \t_____________________________________________\n";
            cout << "\t\t\t\t\t \t|                                             |\n";
            cout << "\t\t\t\t\t \t|       This code of medicine not found       |\n";
            cout << "\t\t\t\t\t \t|_____________________________________________|\n";
        }
        system("pause");
    }
    void show_all_medicine()
    {
        int code;
        int token = 0;
        string name;
        int price;
        int quantity;
        string date;
        system("cls");
        fstream data;
        data.open("database_Medicine.txt", ios::in);
        cout << "\n\n______________________________________________________________________________\n";
        cout << " Code\t\tName\t\tPrice\t\tQuantity\tExpiry date\n";
        cout << "_______________________________________________________________________________\n";
        data >> medicine_code >> medicine_name >> medicine_per_price >> medicine_quantity >> expiry_date;
        while (!data.eof())
        {
            cout << "  " << medicine_code << "\t\t" << medicine_name << "\t" << medicine_per_price << "\t\t" << medicine_quantity << "\t\t" << expiry_date << "\n";
            data >> medicine_code >> medicine_name >> medicine_per_price >> medicine_quantity >> expiry_date;
        }
        cout << "________________________________________________________________________________\n";
        data.close();
    }
    void search_medicine()
    {
        system("cls");
        string searchName;
        bool found = false;
        cout << "\t\t\t\t\t \t ----------------------------------------------\n";
        cout << "\t\t\t\t\t \t|           SEARCH medicine BY NAME            |\n";
        cout << "\t\t\t\t\t \t ----------------------------------------------\n";
        cout << "\t\t\t\t\t \tEnter medicine name to search: ";
        cin >> searchName;
        ifstream data("database_Medicine.txt");
        if (!data)
        {
            cout << " \t\t\t\t\t \t_____________________________________________\n";
            cout << "\t\t\t\t\t \t|                                             |\n";
            cout << "\t\t\t\t\t \t|             File does not exist             |\n";
            cout << "\t\t\t\t\t \t|_____________________________________________|\n";
        }
        else
        {
            string line;
            cout << "\n\n___________________________________________________________________________\n";
            cout << " Code\t\tName\t\tPrice\t\tQuantity\tExpiry Date\n";
            cout << "___________________________________________________________________________\n";
            while (getline(data, line))
            {
                stringstream ss(line);
                string code, name, price, quantity, date;
                ss >> code >> name >> price >> quantity >> date;
                if (name == searchName)
                {
                    cout << "  " << code << "\t\t" << name << "\t" << price << "\t\t" << quantity << "\t\t" << date << "\n";
                    found = true;
                }
            }
            cout << "___________________________________________________________________________\n";
            data.close();
            if (!found)
            {
                cout << " \t\t\t\t\t \t_____________________________________________\n";
                cout << "\t\t\t\t\t \t|        No medicine found with that name     |\n";
                cout << "\t\t\t\t\t \t|_____________________________________________|\n";
            }
        }
    }
};
class seller
{
public:
    string seller_name;
    string seller_gender;
    int seller_age;
    string seller_address;
    int seller_code;
    void add_seller()
    {
        system("cls");
    add_seller_page:
        fstream add_data;
        int code;
        int token = 0;
        string name;
        int age;
        string gender;
        string address;
        string date;
        cout << "\t\t\t\t\t \t ----------------------------------------------\n";
        cout << "\t\t\t\t\t \t|                 ADD SELLER                   |\n";
        cout << "\t\t\t\t\t \t ----------------------------------------------\n";
        add_data.open("database_seller.txt", ios::in);
        if (add_data)
        {
            while (!add_data.eof())
            {
                add_data >> code >> name >> age >> gender >> address;
                if (add_data.eof())
                    break;
            }
            add_data.close();
        }
        seller_code = code + 1;
        cout << "\t\t\t\t\t \tGenerated seller code: " << seller_code << endl;
        cout << "\t\t\t\t\t \tEnter seller name: ";
        cin >> seller_name;
        cout << "\t\t\t\t\t \tEnter seller age: ";
        cin >> seller_age;
        cout << "\t\t\t\t\t \tEnter seller address: ";
        cin >> seller_address;
        cout << "\t\t\t\t\t \tEnter seller gender: ";
        cin >> seller_gender;
        cout << "\t\t\t\t\t \t ---------------------------------------------\n";
        add_data.open("database_seller.txt", ios::app | ios::out);
        add_data << seller_code << "   " << seller_name << "   " << seller_age << "   " << seller_gender << "   " << seller_address << "\n";
        add_data.close();
        cout << " \t\t\t\t\t \t_____________________________________________\n";
        cout << "\t\t\t\t\t \t|                                             |\n";
        cout << "\t\t\t\t\t \t|             Seller has been saved           |\n";
        cout << "\t\t\t\t\t \t|_____________________________________________|\n";
    }
    void delete_seller()
    {
        system("cls");
        fstream add_data, data;
        int pkey;
        int token = 0;
        cout << "\t\t\t\t\t \t ----------------------------------------------\n";
        cout << "\t\t\t\t\t \t|                   DELETE seller              |\n";
        cout << "\t\t\t\t\t \t ----------------------------------------------\n";
        cout << "\t\t\t\t\t \tEnter Medicine code: ";
        cin >> pkey;
        add_data.open("database_seller.txt", ios::in);
        data.open("database1_seller.txt", ios::app | ios::out);
        add_data >> seller_code >> seller_name >> seller_age >> seller_gender >> seller_address;
        while (!add_data.eof())
        {
            if (pkey == seller_code)
            {
                cout << " \t\t\t\t\t \t_____________________________________________\n";
                cout << "\t\t\t\t\t \t|                                             |\n";
                cout << "\t\t\t\t\t \t|           seller has been delete            |\n";
                cout << "\t\t\t\t\t \t|_____________________________________________|\n";
                token++;
            }
            else
            {
                data << "   " << seller_code << "   " << seller_name << "   " << seller_age << "   " << seller_gender << "      " << seller_address << "\n";
            }
            add_data >> seller_code >> seller_name >> seller_age >> seller_gender >> seller_address;
        }
        add_data.close();
        data.close();
        remove("database_seller.txt");
        rename("database1_seller.txt", "database_seller.txt");
        if (token == 0)
        {
            cout << " \t\t\t\t\t \t_____________________________________________\n";
            cout << "\t\t\t\t\t \t|                                             |\n";
            cout << "\t\t\t\t\t \t|         This code of seller not found       |\n";
            cout << "\t\t\t\t\t \t|_____________________________________________|\n";
        }
        system("pause");
    }
    void show_all_seller()
    {
        system("cls");
        fstream data;
        data.open("database_seller.txt", ios::in);
        cout << "\n\n_______________________________________________________________________________\n";
        cout << " Code\t\tName\t\tAge\t\tGender\t\tAddress\n";
        cout << "_______________________________________________________________________________\n";
        data >> seller_code >> seller_name >> seller_age >> seller_gender >> seller_address;
        while (!data.eof())
        {
            cout << "  " << seller_code << "\t\t" << seller_name << "\t\t" << seller_age << "\t\t" << seller_gender << "\t\t" << seller_address << "\n";
            data >> seller_code >> seller_name >> seller_age >> seller_gender >> seller_address;
        }
        cout << "_______________________________________________________________________________\n";
        data.close();
    }
    string searchName;
    void search_seller()
    {
        system("cls");
        bool found = false;
        cout << "\t\t\t\t\t \t ----------------------------------------------\n";
        cout << "\t\t\t\t\t \t|            SEARCH seller BY NAME             |\n";
        cout << "\t\t\t\t\t \t ----------------------------------------------\n";
        cout << "\t\t\t\t\t \tEnter seller name to search: ";
        cin >> searchName;
        ifstream data("database_seller.txt");
        if (!data)
        {
            cout << " \t\t\t\t\t \t_____________________________________________\n";
            cout << "\t\t\t\t\t \t|                                             |\n";
            cout << "\t\t\t\t\t \t|             File does not exist             |\n";
            cout << "\t\t\t\t\t \t|_____________________________________________|\n";
        }
        else
        {
            string line;
            cout << "\n\n__________________________________________________________________________________________\n";
            cout << " Code\t\tName\t\tAge\t\tGender\t\tAddress\n";
            cout << "__________________________________________________________________________________________\n";
            while (getline(data, line))
            {
                stringstream ss(line);
                string code, name, age, gender, address;
                ss >> code >> name >> age >> gender >> address;
                if (name == searchName)
                {
                    cout << "  " << code << "\t\t" << name << "\t\t" << age << "\t\t" << gender << "\t\t" << address << "\n";
                    found = true;
                }
            }
            cout << "_________________________________________________________________________________________\n";
            data.close();
            if (!found)
            {
                cout << " \t\t\t\t\t \t_____________________________________________\n";
                cout << "\t\t\t\t\t \t|          No seller found with that name     |\n";
                cout << "\t\t\t\t\t \t|_____________________________________________|\n";
            }
        }
    }
    string give_seller_name()
    {
        return searchName;
    }
};
class customer
{
public:
    string customer_name;
    char customer_gender;
    int customer_age;
    int customer_phone;
    int customer_code;
    void add_customer()
    {
        system("cls");
    add_customer_page:
        fstream add_data;
        int code;
        int token = 0;
        string name;
        int age;
        string gender;
        int phone;
        string date;
        cout << "\t\t\t\t\t \t ----------------------------------------------\n";
        cout << "\t\t\t\t\t \t|                ADD CUSTOMER                  |\n";
        cout << "\t\t\t\t\t \t ----------------------------------------------\n";
        add_data.open("database_1customer.txt", ios::in);
        if (add_data)
        {
            while (!add_data.eof())
            {
                add_data >> code >> name >> age >> gender >> phone;
                if (add_data.eof())
                    break;
            }
            add_data.close();
        }
        customer_code = code + 1;
        cout << "\t\t\t\t\t \tGenerated customer code: " << customer_code << endl;
        cout << "\t\t\t\t\t \tEnter customer name: ";
        cin >> customer_name;
        cout << "\t\t\t\t\t \tEnter customer age: ";
        cin >> customer_age;
        cout << "\t\t\t\t\t \tEnter customer Phone number: ";
        cin >> customer_phone;
        cout << "\t\t\t\t\t \tEnter customer gender: ";
        cin >> customer_gender;
        cout << "\t\t\t\t\t \t ---------------------------------------------\n";
        add_data.open("database_1customer.txt", ios::app | ios::out);
        add_data << customer_code << "   " << customer_name << "   " << customer_age << "   " << customer_gender << "   " << customer_phone << "\n";
        add_data.close();
        cout << " \t\t\t\t\t \t_____________________________________________\n";
        cout << "\t\t\t\t\t \t|                                             |\n";
        cout << "\t\t\t\t\t \t|             Customer has been saved         |\n";
        cout << "\t\t\t\t\t \t|_____________________________________________|\n";
    }
    void delete_customer()
    {
        system("cls");
        fstream add_data, data;
        int pkey;
        int token = 0;
        cout << "\t\t\t\t\t \t ----------------------------------------------\n";
        cout << "\t\t\t\t\t \t|                    DELETE CUSTOMER           |\n";
        cout << "\t\t\t\t\t \t ----------------------------------------------\n";
        cout << "\t\t\t\t\t \tEnter customer code: ";
        cin >> pkey;
        add_data.open("database_1customer.txt", ios::in);
        data.open("database1_1customer.txt", ios::app | ios::out);
        add_data >> customer_code >> customer_name >> customer_age >> customer_gender >> customer_phone;
        while (!add_data.eof())
        {
            if (pkey == customer_code)
            {
                cout << " \t\t\t\t\t \t_____________________________________________\n";
                cout << "\t\t\t\t\t \t|                                             |\n";
                cout << "\t\t\t\t\t \t|         customer has been delete            |\n";
                cout << "\t\t\t\t\t \t|_____________________________________________|\n";
                token++;
            }
            else
            {
                data << "   " << customer_code << "   " << customer_name << "   " << customer_age << "   " << customer_gender << "   "
                     << "   " << customer_phone << "\n";
            }
            add_data >> customer_code >> customer_name >> customer_age >> customer_gender >> customer_phone;
        }
        add_data.close();
        data.close();
        remove("database_1customer.txt");
        rename("database1_1customer.txt", "database_1customer.txt");

        if (token == 0)
        {
            cout << " \t\t\t\t\t \t_____________________________________________\n";
            cout << "\t\t\t\t\t \t|                                             |\n";
            cout << "\t\t\t\t\t \t|       This code of customer not found       |\n";
            cout << "\t\t\t\t\t \t|_____________________________________________|\n";
        }
        system("pause");
    }
    void show_all_customer()
    {
        system("cls");
        fstream data;
        data.open("database_1customer.txt", ios::in);
        cout << "\n\n_________________________________________________________________________\n";
        cout << " Code\t\tName\t\tAge\t\tGender\t\tPhone No\n";
        cout << "_________________________________________________________________________\n";
        data >> customer_code >> customer_name >> customer_age >> customer_gender >> customer_phone;
        while (!data.eof())
        {
            cout << "  " << customer_code << "\t\t" << customer_name << "\t\t" << customer_age << "\t\t" << customer_gender << "\t\t" << customer_phone << "\n";
            data >> customer_code >> customer_name >> customer_age >> customer_gender >> customer_phone;
        }
        cout << "_________________________________________________________________________\n";
        data.close();
    }
    void search_customer()
    {
        system("cls");
        string searchName;
        bool found = false;
        cout << "\t\t\t\t\t \t ----------------------------------------------\n";
        cout << "\t\t\t\t\t \t|            SEARCH customer BY NAME           |\n";
        cout << "\t\t\t\t\t \t ----------------------------------------------\n";
        cout << "\t\t\t\t\t \tEnter customer name to search: ";
        cin >> searchName;
        ifstream data("database_1customer.txt");
        string line;
        cout << "\n\n_________________________________________________________________________\n";
        cout << " Code\t\tName\t\tAge\t\tGender\t\tPhone No\n";
        cout << "_________________________________________________________________________\n";
        while (getline(data, line))
        {
            stringstream ss(line);
            string code, name, age, gender, phone;
            ss >> code >> name >> age >> gender >> phone;
            if (name == searchName)
            {
                cout << "  " << code << "\t\t" << name << "\t\t" << age << "\t\t" << gender << "\t\t" << phone << "\n";
                found = true;
            }
        }
        cout << "_________________________________________________________________________\n";
        data.close();

        if (!found)
        {
            cout << " \t\t\t\t\t \t_____________________________________________\n";
            cout << "\t\t\t\t\t \t|        No customer found with that name     |\n";
            cout << "\t\t\t\t\t \t|_____________________________________________|\n";
        }
    }
    string give_customer_name()
    {
        return customer_name;
    }
};
class selling : public customer, public seller, public medicine
{
public:
    string customer_bill_name;
    string seller_bill_name;
    float total = 0;
    string date;
    void selling_medicine_menu()
    {
        add_customer();
        system("cls");
    selling_medicine_menu:
        int choice;
        cout << "\t\t\t\t\t \t _____________________________________________\n";
        cout << "\t\t\t\t\t \t|                                             |\n";
        cout << "\t\t\t\t\t \t|            SELLING MEDICINE MENU            |\n";
        cout << "\t\t\t\t\t \t|_____________________________________________|\n";
        cout << "\t\t\t\t\t \t|    1) Selling medicine                      |\n";
        cout << "\t\t\t\t\t \t|                                             |\n";
        cout << "\t\t\t\t\t \t|    2) See all medicine                      |\n";
        cout << "\t\t\t\t\t \t|                                             |\n";
        cout << "\t\t\t\t\t \t|    3) Search medicine                       |\n";
        cout << "\t\t\t\t\t \t|                                             |\n";
        cout << "\t\t\t\t\t \t|Please select!!                              |\n";
        cout << "\t\t\t\t\t \t|_____________________________________________|\n";
        cout << "\t\t\t\t\t \t     ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            selling_medicine();
            break;
        case 2:
            show_all_medicine();
            break;
        case 3:
            search_medicine();
            break;
        default:
            cout << "\t\t\t\t\t \t|        select form the given option         |\n";
            break;
        }
        system("pause");
        goto selling_medicine_menu;
    }
    void selling_medicine()
    {
        customer_bill_name = give_customer_name();
        seller_bill_name = give_seller_name();
        fstream data, temp;
        int arry_code[100];
        int arry_quantity[100];
        int c = 0;
        char choice[5];
        float amount = 0;
    buy_page:
        cout << " \t\t\t\t\t \t_____________________________________________\n";
        cout << "\t\t\t\t\t \t|                                             |\n";
        cout << "\t\t\t\t\t \t|               SELL MEDICINE                 |\n";
        cout << "\t\t\t\t\t \t|_____________________________________________|\n";
        cout << "\t\t\t\t\t\tEnter date:";
        cin >> date;
        data.open("database_Medicine.txt", ios::in);
        if (!data)
        {
            cout << " \t\t\t\t\t \t_____________________________________________\n";
            cout << "\t\t\t\t\t \t|                                             |\n";
            cout << "\t\t\t\t\t \t|              EMPTY DATA BASE                |\n";
            cout << "\t\t\t\t\t \t|_____________________________________________|\n";
        }
        else
        {
            data.close();
            // Assuming you have the show_all_medicine() function to display all medicines
            // show_all_medicine();
            cout << "\t\t\t\t\t\t _____________________________________________\n";
            cout << "\t\t\t\t\t\t|           PLEASE PLACE THE ORDER            |\n";
            cout << "\t\t\t\t\t\t|_____________________________________________|\n";
            do
            {
                show_all_medicine();
                cout << "\t\t\t\t\t\tEnter the Medicine code:";
                cin >> arry_code[c];
                cout << "\t\t\t\t\t\tEnter the Medicine Quantity:";
                cin >> arry_quantity[c];
                c++;
                cout << "\t\t\t\t\t\t _____________________________________________\n";
                cout << "\t\t\t\t\t\t|Do you want to buy other medicine (y or n)";
                cin >> choice;
                cout << "\t\t\t\t\t\t|_____________________________________________|\n";
            } while (choice[0] == 'y');
            ifstream data("database_1customer.txt");
            string line;
            cout << "DATE: " << date << endl;
            cout << "SELLER NAME            " << give_seller_name() << endl;
            cout << "CUSTOMER dETAIL";
            cout << "\n______________________________________________________________________________\n";
            cout << " Code\t\tName\t\tAge\t\tGender\t\tPhone No\n";
            cout << "______________________________________________________________________________\n";
            bool found = false;
            while (getline(data, line))
            {
                stringstream ss(line);
                string code, name, age, gender, phone;
                ss >> code >> name >> age >> gender >> phone;
                if (name == customer_bill_name)
                {
                    cout << "  " << code << "\t\t" << name << "\t\t" << age << "\t\t" << gender << "\t\t" << phone << "\n";
                    found = true;
                }
            }
            cout << "______________________________________________________________________________\n";
            data.close();
            cout << "MEDICINE DETAIL";
            cout << "\n\n_______________________________________________________________________________\n";
            cout << " Code\t\tName\t\tPrice\t\tQuantity\tExpiry Date\n";
            for (int i = 0; i < c; i++)
            {
                data.open("database_Medicine.txt", ios::in);
                temp.open("temp.txt", ios::out); // Temporary file for storing updated data
                bool found = false;
                while (data >> medicine_code >> medicine_name >> medicine_per_price >> medicine_quantity >> expiry_date)
                {
                    if (medicine_code == arry_code[i])
                    {
                        amount = medicine_per_price * arry_quantity[i];
                        total = total + amount;
                        medicine_quantity = medicine_quantity - arry_quantity[i];
                        if (medicine_quantity > 0)
                        {
                            found = true;
                            cout << medicine_code << "\t\t" << medicine_name << "\t" << medicine_per_price << "\t\t"
                                 << arry_quantity[i] << "\t\t" << expiry_date << "\n";

                            temp << medicine_code << "\t\t" << medicine_name << "\t\t" << medicine_per_price << "\t\t"
                                 << medicine_quantity << "\t\t" << expiry_date << "\n";
                        }
                    }
                    else
                    {
                        temp << medicine_code << "\t\t" << medicine_name << "\t\t" << medicine_per_price << "\t\t"
                             << medicine_quantity << "\t\t" << expiry_date << "\n";
                    }
                }
                data.close();
                temp.close();
                remove("database_Medicine.txt");             // Remove the old file
                rename("temp.txt", "database_Medicine.txt"); // Rename the temporary file to replace the old file
            }
            cout << "________________________________________________________________________\n";
            cout << "Total amount:                                                |" << total << "Rs" << endl;
            cout << "________________________________________________________________________\n";
        }
        ofstream database("selling_database.txt", ios::app);
        if (database.is_open())
        {
            database << customer_bill_name << "\t" << seller_bill_name << "\t" << total << "\t" << date << "\n";
            database.close();
        }
        else
        {
            cerr << "Failed to open the selling database file for writing." << endl;
        }
    }
    void show_selling_data()
    {
        system("cls");
        ifstream data("selling_database.txt");
        if (!data)
        {
            cout << "Error opening file." << endl;
            return;
        }
        cout << "\n\n________________________________________________________\n";
        cout << " Seller Name\tCustomer Name\tTotal Amount\t Date\n";
        cout << "____________________________________________________________\n";
        string seller_name, customer_name, total, date;
        double total_price = 0.0; // Variable to store the sum of totals
        while (data >> seller_name >> customer_name >> total >> date)
        {
            cout << "  " << seller_name << "\t\t" << customer_name << "\t\t" << total << "\t\t" << date << "\n";
            total_price += stod(total); // Convert total to double and add to total_price
        }
        cout << "____________________________________________________________\n";
        cout << "Total Price: " << total_price << "Rs\n";
        data.close();
    }
    void search_selling_data()
    {
        system("cls");
        string search_date;
        cout << "Enter search date: ";
        cin >> search_date;
        ifstream data("selling_database.txt");
        if (!data)
        {
            cout << "Error opening file." << endl;
            return;
        }
        cout << "\n\n________________________________________________________\n";
        cout << " Seller Name\tCustomer Name\tTotal Amount\t Date\n";
        cout << "____________________________________________________________\n";
        string seller_name, customer_name, total, date;
        double total_price = 0.0; // Variable to store the sum of totals
        while (data >> seller_name >> customer_name >> total >> date)
        {
            if (date == search_date)
            {
                cout << "  " << seller_name << "\t\t" << customer_name << "\t\t" << total << "\t\t" << date << "\n";
                total_price += stod(total); // Convert total to double and add to total_price
            }
        }
        cout << "____________________________________________________________\n";
        cout << "Total Income: " << total_price << "Rs\n";

        data.close();
    }
};
class PMS_menu : public selling, public manufacturer
{
public:
    string seller_name_check;

    void search_seller_selling()
    {
        system("cls");
        bool found = false;
        cout << "\t\t\t\t\t \t ----------------------------------------------\n";
        cout << "\t\t\t\t\t \t|            SEARCH seller BY NAME             |\n";
        cout << "\t\t\t\t\t \t ----------------------------------------------\n";
        cout << "\t\t\t\t\t \tEnter seller name to search: ";
        cin >> searchName;
        ifstream data("database_seller.txt");
        string line;
        while (getline(data, line))
        {
            stringstream ss(line);
            string code, name, age, gender, address;
            ss >> code >> name >> age >> gender >> address;
            if (name == searchName)
            {
                main_seller_menu();
            }
        }
        data.close();
        if (!found)
        {
            cout << " \t\t\t\t\t \t_____________________________________________\n";
            cout << "\t\t\t\t\t \t|          No seller found with that name     |\n";
            cout << "\t\t\t\t\t \t|_____________________________________________|\n";
            system("pause");
        }
    }

    void main_menu()
    {
        system("cls");
    menu_page:
        int choice;
        cout << "\t\t\t\t\t \t _____________________________________________\n";
        cout << "\t\t\t\t\t \t|                                             |\n";
        cout << "\t\t\t\t\t \t|          PHARMACY MANAGEMENT SYSTEM         |\n";
        cout << "\t\t\t\t\t \t|_____________________________________________|\n";
        cout << "\t\t\t\t\t \t|    1) Admin Command                         |\n";
        cout << "\t\t\t\t\t \t|                                             |\n";
        cout << "\t\t\t\t\t \t|    2) Seller Command                        |\n";
        cout << "\t\t\t\t\t \t|                                             |\n";
        cout << "\t\t\t\t\t \t|    3) Exit                                  |\n";
        cout << "\t\t\t\t\t \t|                                             |\n";
        cout << "\t\t\t\t\t \t|Please select!!                              |\n";
        cout << "\t\t\t\t\t \t|_____________________________________________|\n";
        cout << "\t\t\t\t\t \t     ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            admin_menu();
            break;
        case 2:
            search_seller_selling();
            break;
        case 3:
            system("cls");
            exit(0);
            break;
        default:
            cout << "\t\t\t\t\t \t|        select form the given option         |\n";
            system("pause");
            break;
        }
        goto menu_page;
    }
    void admin_menu()
    {
        system("cls");
    admin_menu_page:
        int choice;
        cout << "\t\t\t\t\t \t _________________________________________________________________________________\n";
        cout << "\t\t\t\t\t \t|                                                                                 |\n";
        cout << "\t\t\t\t\t \t|                                ADMIN COMMANDS                                   |\n";
        cout << "\t\t\t\t\t \t|_________________________________________________________________________________|\n";
        cout << "\t\t\t\t\t \t|    1) ADD Command (seller, medicine)                                            |\n";
        cout << "\t\t\t\t\t \t|                                                                                 |\n";
        cout << "\t\t\t\t\t \t|    2) DELETE Command (seller, medicine, manugacturer)                           |\n";
        cout << "\t\t\t\t\t \t|                                                                                 |\n";
        cout << "\t\t\t\t\t \t|    3) SHOW DAtA (seller, medicine, manugacturer, cusomer, selling, selling data)|\n";
        cout << "\t\t\t\t\t \t|                                                                                 |\n";
        cout << "\t\t\t\t\t \t|    4) SERACH Command  (seller, medicine, manugacturer)                          |\n";
        cout << "\t\t\t\t\t \t|                                                                                 |\n";
        cout << "\t\t\t\t\t \t|    5) Back to main menu                                                         |\n";
        cout << "\t\t\t\t\t \t|                                                                                 |\n";
        cout << "\t\t\t\t\t \t|Please select!!                                                                  |\n";
        cout << "\t\t\t\t\t \t|_________________________________________________________________________________|\n";
        cout << "\t\t\t\t\t \t     ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            admin_add();
            break;
        case 2:
            admin_delete();
            break;
        case 3:
            admin_show();
            break;
        case 4:
            admin_search();
            break;
        case 5:
            main_menu();
            break;
        default:
            cout << "\t\t\t\t\t \t|        select form the given option         |\n";
            system("pause");
            break;
        }
        goto admin_menu_page;
    }
    void admin_add()
    {
        system("cls");
    admin_add_page:
        int choice;
        cout << "\t\t\t\t\t \t _________________________________________________________________________\n";
        cout << "\t\t\t\t\t \t|                                                                         |\n";
        cout << "\t\t\t\t\t \t|                             ADMIN ADD COMMANDS                          |\n";
        cout << "\t\t\t\t\t \t|_________________________________________________________________________|\n";
        cout << "\t\t\t\t\t \t|    1) Add sellers                                                       |\n";
        cout << "\t\t\t\t\t \t|                                                                         |\n";
        cout << "\t\t\t\t\t \t|    2) Add medicines                                                     |\n";
        cout << "\t\t\t\t\t \t|                                                                         |\n";
        cout << "\t\t\t\t\t \t|    3) Back to Admin command                                             |\n";
        cout << "\t\t\t\t\t \t|                                                                         |\n";
        cout << "\t\t\t\t\t \t|Please select!!                                                          |\n";
        cout << "\t\t\t\t\t \t|_________________________________________________________________________|\n";
        cout << "\t\t\t\t\t \t     ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            add_seller();
            break;
        case 2:
            add_manufacturer();
            add_medicine();
            break;
        case 3:
            admin_menu();
            break;
        default:
            cout << "\t\t\t\t\t \t|        select form the given option         |\n";
            system("pause");
            break;
        }
        goto admin_add_page;
    }
    void admin_delete()
    {
        system("cls");
    admin_delete_page:
        int choice;
        cout << "\t\t\t\t\t \t _________________________________________________________________________\n";
        cout << "\t\t\t\t\t \t|                                                                         |\n";
        cout << "\t\t\t\t\t \t|                           ADMIN DELETE COMMANDS                         |\n";
        cout << "\t\t\t\t\t \t|_________________________________________________________________________|\n";
        cout << "\t\t\t\t\t \t|    1) Delete sellers                                                    |\n";
        cout << "\t\t\t\t\t \t|                                                                         |\n";
        cout << "\t\t\t\t\t \t|    2) Delete medicines                                                  |\n";
        cout << "\t\t\t\t\t \t|                                                                         |\n";
        cout << "\t\t\t\t\t \t|    3) Delete manufacturers                                              |\n";
        cout << "\t\t\t\t\t \t|                                                                         |\n";
        cout << "\t\t\t\t\t \t|    4) Back to Admin command                                             |\n";
        cout << "\t\t\t\t\t \t|                                                                         |\n";
        cout << "\t\t\t\t\t \t|Please select!!                                                          |\n";
        cout << "\t\t\t\t\t \t|_________________________________________________________________________|\n";
        cout << "\t\t\t\t\t \t     ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            delete_seller();
            break;
        case 2:
            delete_medicine();
            break;
        case 3:
            delete_manufacturer();
            break;
        case 4:
            admin_menu();
            break;
        default:
            cout << "\t\t\t\t\t \t|        select form the given option         |\n";
            system("pause");
            break;
        }
        goto admin_delete_page;
    }
    void admin_show()
    {
        system("cls");
    admin_show_page:
        int choice;
        cout << "\t\t\t\t\t \t _________________________________________________________________________\n";
        cout << "\t\t\t\t\t \t|                                                                         |\n";
        cout << "\t\t\t\t\t \t|                         ADMIN SHOW DATA COMMANDS                        |\n";
        cout << "\t\t\t\t\t \t|_________________________________________________________________________|\n";
        cout << "\t\t\t\t\t \t|    1) Show data of sellers                                              |\n";
        cout << "\t\t\t\t\t \t|                                                                         |\n";
        cout << "\t\t\t\t\t \t|    2) Show data of medicines                                            |\n";
        cout << "\t\t\t\t\t \t|                                                                         |\n";
        cout << "\t\t\t\t\t \t|    3) Show data of manufacturers                                        |\n";
        cout << "\t\t\t\t\t \t|                                                                         |\n";
        cout << "\t\t\t\t\t \t|    4) Show data of customers                                            |\n";
        cout << "\t\t\t\t\t \t|                                                                         |\n";
        cout << "\t\t\t\t\t \t|    5) Show all selling data                                             |\n";
        cout << "\t\t\t\t\t \t|                                                                         |\n";
        cout << "\t\t\t\t\t \t|    6) Back to Admin command                                             |\n";
        cout << "\t\t\t\t\t \t|                                                                         |\n";
        cout << "\t\t\t\t\t \t|Please select!!                                                          |\n";
        cout << "\t\t\t\t\t \t|_________________________________________________________________________|\n";
        cout << "\t\t\t\t\t \t     ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            show_all_seller();
            break;
        case 2:
            show_all_medicine();
            break;
        case 3:
            show_all_manufacturer();
            break;
        case 4:
            show_all_customer();
            break;
        case 5:
            show_selling_data();
            break;
        case 6:
            admin_menu();
            break;
        default:
            cout << "\t\t\t\t\t \t|        select form the given option         |\n";
            system("pause");
            break;
        }
        goto admin_show_page;
    }
    void admin_search()
    {
        system("cls");
    admin_search_page:
        int choice;
        cout << "\t\t\t\t\t \t _________________________________________________________________________\n";
        cout << "\t\t\t\t\t \t|                                                                         |\n";
        cout << "\t\t\t\t\t \t|                           ADMIN SEARCH COMMANDS                         |\n";
        cout << "\t\t\t\t\t \t|_________________________________________________________________________|\n";
        cout << "\t\t\t\t\t \t|    1) Search sellers                                                    |\n";
        cout << "\t\t\t\t\t \t|                                                                         |\n";
        cout << "\t\t\t\t\t \t|    2) Search medicines                                                  |\n";
        cout << "\t\t\t\t\t \t|                                                                         |\n";
        cout << "\t\t\t\t\t \t|    3) Search manufacturers                                              |\n";
        cout << "\t\t\t\t\t \t|                                                                         |\n";
        cout << "\t\t\t\t\t \t|    4) Search selling data by date                                       |\n";
        cout << "\t\t\t\t\t \t|                                                                         |\n";
        cout << "\t\t\t\t\t \t|    5) Back to Admin command                                             |\n";
        cout << "\t\t\t\t\t \t|                                                                         |\n";
        cout << "\t\t\t\t\t \t|Please select!!                                                          |\n";
        cout << "\t\t\t\t\t \t|_________________________________________________________________________|\n";
        cout << "\t\t\t\t\t \t     ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            search_seller();
            break;
        case 2:
            search_medicine();
            break;
        case 3:
            search_manufacturer();
            break;
        case 4:
            search_selling_data();
            break;
        case 5:
            admin_menu();
            break;
        default:
            cout << "\t\t\t\t\t \t|        select form the given option         |\n";
            system("pause");
            break;
        }
        goto admin_search_page;
    }
    void main_seller_menu()
    {
        system("cls");
    seller_menu_page:
        int choice;
        cout << "\t\t\t\t\t \t _________________________________________________________________________\n";
        cout << "\t\t\t\t\t \t|                                                                         |\n";
        cout << "\t\t\t\t\t \t|                               SELLER COMMANDS                           |\n";
        cout << "\t\t\t\t\t \t|_________________________________________________________________________|\n";
        cout << "\t\t\t\t\t \t|    1) SELLING medicine                                                  |\n";
        cout << "\t\t\t\t\t \t|                                                                         |\n";
        cout << "\t\t\t\t\t \t|    2) SHOW DAtA command (medicine, customer)                            |\n";
        cout << "\t\t\t\t\t \t|                                                                         |\n";
        cout << "\t\t\t\t\t \t|    3) SERACH Command  (customer, medicine)                              |\n";
        cout << "\t\t\t\t\t \t|                                                                         |\n";
        cout << "\t\t\t\t\t \t|    4) Back to main menu                                                 |\n";
        cout << "\t\t\t\t\t \t|                                                                         |\n";
        cout << "\t\t\t\t\t \t|Please select!!                                                          |\n";
        cout << "\t\t\t\t\t \t|_________________________________________________________________________|\n";
        cout << "\t\t\t\t\t \t     ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            selling_medicine_menu();
            break;
        case 2:
            seller_show();
            break;
        case 3:
            seller_search();
            break;
        case 4:
            main_menu();
            break;
        default:
            cout << "\t\t\t\t\t \t|        select form the given option         |\n";
            system("pause");
            break;
        }
        goto seller_menu_page;
    }
    void seller_show()
    {
        system("cls");
    seller_show_page:
        int choice;
        cout << "\t\t\t\t\t \t _________________________________________________________________________\n";
        cout << "\t\t\t\t\t \t|                                                                         |\n";
        cout << "\t\t\t\t\t \t|                         SELLER SHOW DATA COMMANDS                       |\n";
        cout << "\t\t\t\t\t \t|_________________________________________________________________________|\n";
        cout << "\t\t\t\t\t \t|    1) Show data of customers                                            |\n";
        cout << "\t\t\t\t\t \t|                                                                         |\n";
        cout << "\t\t\t\t\t \t|    2) Show data of medicines                                            |\n";
        cout << "\t\t\t\t\t \t|                                                                         |\n";
        cout << "\t\t\t\t\t \t|    3) Back to seller commands                                           |\n";
        cout << "\t\t\t\t\t \t|                                                                         |\n";
        cout << "\t\t\t\t\t \t|Please select!!                                                          |\n";
        cout << "\t\t\t\t\t \t|_________________________________________________________________________|\n";
        cout << "\t\t\t\t\t \t     ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            show_all_customer();
            break;
        case 2:
            show_all_medicine();
            break;
        case 3:
            main_seller_menu();
            break;
        default:
            cout << "\t\t\t\t\t \t|        select form the given option         |\n";
            system("pause");
            break;
        }
        goto seller_show_page;
    }
    void seller_search()
    {
        system("cls");
    seller_search_page:
        int choice;
        cout << "\t\t\t\t\t \t _________________________________________________________________________\n";
        cout << "\t\t\t\t\t \t|                                                                         |\n";
        cout << "\t\t\t\t\t \t|                           SELLER SEARCH COMMANDS                        |\n";
        cout << "\t\t\t\t\t \t|_________________________________________________________________________|\n";
        cout << "\t\t\t\t\t \t|    1) Serach medicine                                                   |\n";
        cout << "\t\t\t\t\t \t|                                                                         |\n";
        cout << "\t\t\t\t\t \t|    2) Search customer                                                   |\n";
        cout << "\t\t\t\t\t \t|                                                                         |\n";
        cout << "\t\t\t\t\t \t|    3) Back to seller commands                                           |\n";
        cout << "\t\t\t\t\t \t|                                                                         |\n";
        cout << "\t\t\t\t\t \t|Please select!!                                                          |\n";
        cout << "\t\t\t\t\t \t|_________________________________________________________________________|\n";
        cout << "\t\t\t\t\t \t     ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            search_medicine();
            break;
        case 2:
            search_customer();
            break;
        case 3:
            seller_show();
            break;
        default:
            cout << "\t\t\t\t\t \t|        select form the given option         |\n";
            system("pause");
            break;
        }
        goto seller_search_page;
    }
};
int main()
{
    PMS_menu m1;
    m1.main_menu();
    return 0;
}
