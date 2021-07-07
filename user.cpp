#include<Windows.h>
#include "globalink.h"
#include "user.h"
void user::productlist(bool b = 0) {
    cout << "\n\tPRODUCT LIST DATA BASE\n";
    int j = 1;
    for (auto i : g::product_data_base) {
        if (b)
            cout << "[" << j++ << "]: ";
        cout << i->get_id() << ":" << i->get_name() << endl;
    }
}

string  user::get_password()    { return password; }
bool    user::get_admin()       { return is_admin; }
string  user::get_login()       { return login; }
string  user::get_name()        { return name; }

void    user::CCS(){
        cout << "\tChoose option\n"
            << "1) Add a product to the basket\n"
            << "2) Delete a product from the basket\n"
            << "3) Suck admin's dick\n"
            << "4) Pay\n";
    }

void user::CCS_respond(int k){
    switch (k) {
        case 1:
        {
            system("cls");
            cout << "\tSelecting a product to shop\t\t" << name << "\n";
            if (g::product_data_base.size() <= 0) {
                cout << "\n\n\tthere is no products in the market.\n\n";
                system("pause");
                break;
            }
            short k;
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
            bask.add_product_basket(k);
            cout << "\tA new product has been succesfully added to the basket\n";
            Sleep(500);
            bask.get_list_of_products();
            cout << "\nTotal price: " << bask.get_total_price() << endl;
            system("pause");
            break;
        }
        case 2:
        {
            system("cls");
            cout << "\tDeleting a product from the basket\t\t" << name << "\n";
            if (bask.size() <= 0) {
                cout << "\n\n\tthere is no products in the basket.\n\n";
                system("pause");
                break;
            }
            bask.get_list_of_products(1);
            short k;
            while (1) {
                cin >> k;
                if (k <= g::user_data_base.size() && k > 0)
                    break;
                else if (k == 0)
                    break;
                else
                    cout << "\nInput correct number\n";
            }
            bask.erase(k);
            cout << "\tA product has been succesfully deleted from the basket\n";
            Sleep(500);
            cout << "Now your basket has:\n";
            bask.get_list_of_products();
            cout << "\nTotal price: " << bask.get_total_price() << " UAH\n";
            system("pause");
            break;
        }
        case 3:
            system("cls");
            cout << "\tA product list\t\t" << name << "\n";
            productlist();
            system("pause");
            break;
        case 4:
            system("cls");
            cout << "You've paid:\n";
            bask.get_list_of_products();
            cout << "\nWelcome back\n";
            system("pause");
            bask.clear();
            break;
        default:
            cout << "Don't be a lol, hunny\n";
            break;
        }
    }
    user::user(string name, string login, string password) {
        this->name      = name;
        this->login     = login;
        this->password  = password;
    }
    user::user(string login, string password) {
        this->login     = login;
        this->password  = password;
    }