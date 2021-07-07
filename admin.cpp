#include <Windows.h>
#include "admin.h"

void admin::userlist(bool b = 0) {
    cout << "\n\tUSER LIST DATA BASE\n";
    int j = 1;
    for (auto i : g::user_data_base) {
        if (b)
            cout << "[" << j++ << "]: ";
        cout << i->get_login() << ":" << i->get_password() << endl;
    }
}
void admin::productlist(bool b = 0) {
    cout << "\n\tPRODUCT LIST DATA BASE\n";
    int j = 1;
    for (auto i : g::product_data_base) {
        if (b)
            cout << "[" << j++ << "]: ";
        cout << i->get_id() << ":" << i->get_name() << endl;
    }
}
void admin::categorylist(bool b = 0) {
    cout << "\n\tCATEGORY LIST DATA BASE\n";
    int j = 1;
    for (auto i : g::category_list) {
        if (b)
            cout << "[" << j++ << "]: ";
        cout << i->get_id() << ":" << i->get_type() << endl;
    }
}

string  admin::get_password()   { return password; }
bool    admin::get_admin()      { return is_admin; }
string  admin::get_login()      { return login; }
string  admin::get_name()       { return name; }
void    admin::CCS()   {
    cout << "\tCURRENT CONTROL SET\n"
        << "1) Add user to the DB\n"
        << "2) Delete user from the DB\n"
        << "3) Add a product\n"
        << "4) Change product's price\n"
        << "5) Delete a product\n"
        << "6) Add a category\n"
        << "7) Delete a category\n"
        << "0) Exit\n";
}
void admin::CCS_respond(int k){
    switch (k) {
        case 1:///////////////////////////////////////////////////////////////////////////////////////////////
        {
            system("cls");
            string login, password, name;
            cout << "\tAdding user to the DB\t\t" << name << "\nInput name: ";
            cin >> name;
            cout << "\nInput login: ";
            cin >> login;
            cout << "\nInput password: ";
            cin >> password;
            user* u = new user(login, password);
            g::user_data_base.push_back(u);
            write_user_in_DB(name, login, password);
            cout << "\nUser has been successfuly added.";
            Sleep(500);
            userlist();
            system("pause");
            break;
        }
        case 2:///////////////////////////////////////////////////////////////////////////////////////////////
        {
            system("cls");
            cout << "\tDelete users from the DB\t\t" << name << "\n";
            if (g::user_data_base.size() == 0) {
                cout << "\n\n\tthere is no users in the data base.\n\n";
                system("pause");
                break;
            }
            userlist(1);
            int k;
            cout << "Input number: ";
            while (1) {
                cin >> k;
                if (k <= g::user_data_base.size() && k > 0)
                    break;
                else if (k == 0)
                    break;
                else
                    cout << "\nInput correct number\n";
            }
            if (k == 0)
                break;
            if (!g::user_data_base[k - 1]->get_admin()) {
                g::user_data_base.erase(g::user_data_base.begin() + k - 1);
                delete_user_from_DB();
            }
            else
                cout << "\n\t\tMr. White should be alive.";
            cout << "\nUser has been successfuly deleted.";
            Sleep(500);
            userlist();
            system("pause");
            break;
        }
        case 3:///////////////////////////////////////////////////////////////////////////////////////////////
        {
            system("cls");
            cout << "Adding a product to the product list\t\t" << name << "\n";
            int category = -1, rate;
            std::string name;
            float price;
            short id = g::product_data_base[g::product_data_base.size() - 1]->get_id() + 1;
            cout << "\nInsert name: ";
            cin >> name;
            cout << "\nInsert price: ";
            cin >> price;
            if (g::category_list.size() > 0) {
                cout << "Select a category: ";
                categorylist(1);
                cin >> category;
                category--;
            }
            cout << "\nChoose begin rating: ";
            cin >> rate;
            cout << endl;
            g::product_data_base.push_back(new product(id, name, price, category, rate));
            write_product_in_DB(id, name, price, category, rate);
            cout << "\nA new product has been successfuly added.";
            Sleep(500);
            system("cls");
            productlist();
            system("pause");
            break;
        }
        case 4:///////////////////////////////////////////////////////////////////////////////////////////////
        {
            system("cls");
            cout << "\tChanging a price of a product\t\t" << name << "\n";
            if (g::product_data_base.size() <= 0) {
                cout << "\n\n\tthere is no products in the data base.\n\n";
                system("pause");
                break;
            }
            short k=0;
            float f = 0;
            if (g::product_data_base.size() > 0) {
                productlist(1);
                while (1) {
                    cin >> k;
                    if (k <= g::product_data_base.size() && k > 0)
                        break;
                    else if (k == 0)
                        break;
                    else
                        cout << "\nInput correct number\n";
                }
            }
            cout << "\nCurrent price of the product is " << 
                g::product_data_base[k - 1]->get_price() << "\nInsert a new price: ";
            cin >> f;
            g::product_data_base[k - 1]->set_price(f);
            cout << "\nAn old price has been succesfully replaced\n\n";
            Sleep(500);
            cout << g::product_data_base[k - 1]->get_name() << " costs " << 
                g::product_data_base[k - 1]->get_price() << " UAH\n";
            system("pause");
            break;
        }
        case 5:///////////////////////////////////////////////////////////////////////////////////////////////
        {
            system("cls");
            cout << "\tDeleting a product of the product list\t\t" << name << "\n";
            if (g::product_data_base.size() <= 0) {
                cout << "\n\n\tthere is no products in the data base.\n\n";
                system("pause");
                break;
            }
            short k=0;
            if (g::product_data_base.size() > 0) {
                productlist(1);
                while (1) {
                    cin >> k;
                    if (k <= g::product_data_base.size() && k > 0)
                        break;
                    else if (k == 0)
                        break;
                    else
                        cout << "\nInput correct number\n";
                }
            }
            g::product_data_base.erase(g::product_data_base.begin() + k - 1);
            delete_product_from_DB();
            cout << "\nThe product has been successfuly deleted.";
            Sleep(500);
            productlist();
            system("pause");
            break;
        }
        case 6:///////////////////////////////////////////////////////////////////////////////////////////////
        {
            system("cls");
            cout << "Adding a category to the category list\t\t" << name << "\n";
            std::string name;
            short id = g::category_list[g::category_list.size() - 1]->get_id() + 1;
            cout << "\nInsert name: ";
            cin >> name;
            cout << endl;
            g::category_list.push_back(new category(id, name));
            write_category_in_DB(id, name);
            cout << "\nA new category has been successfuly added.";
            Sleep(500);
            system("cls");
            categorylist();
            system("pause");
            break;
        }
        case 7:///////////////////////////////////////////////////////////////////////////////////////////////
        {
            system("cls");
            cout << "\tDeleting a category of the category list\t\t" << name << "\n";
            if (g::category_list.size() <= 0) {
                cout << "\n\n\tthere is no categoryes in the data base.\n\n";
                system("pause");
                break;
            }
            short k = 0;
            if (g::category_list.size() > 0) {
                categorylist(1);
                while (1) {
                    cin >> k;
                    if (k <= g::category_list.size() && k > 0)
                        break;
                    else if (k == 0)
                        break;
                    else
                        cout << "\nInput correct number\n";
                }
            }
            g::category_list.erase(g::category_list.begin() + k - 1);
            delete_category_from_DB();
            cout << "\nThe category has been successfuly deleted.";
            Sleep(500);
            categorylist();
            system("pause");
            break;
        }
        default:///////////////////////////////////////////////////////////////////////////////////////////////
            cout << "Don't be a " << name << "lol, hunny\n";
            system("pause");
            break;
        
    }
}