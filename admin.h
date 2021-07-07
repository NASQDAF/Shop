#pragma once
#include<fstream>
#include<iostream>
#include "globalink.h"
#include "user.h"

class admin : public uf {
private:
    string name = "admin";
    string login = "amin";
    string password = "7";

    const bool is_admin = true;

    void write_user_in_DB(
        string name,
        string login,
        string password
    )
    {
        ofstream fout("users.csv", ios_base::app);
        if (fout.is_open()) {
            fout << endl << name << " " << login << " " << password;
        }
        fout.close();
    }

    void delete_user_from_DB() {
        ofstream f("users.csv");
        if (f.is_open()) {
            short j = 0;
            for (auto i : g::user_data_base) {
                if (j != 0) {
                    f << i->get_name() << " " <<
                        i->get_login() << " " <<
                        i->get_password();
                    if (j < g::user_data_base.size() - 1)
                        f << endl;
                }
                j++;
            }
            f.close();
        }
    }

    void write_category_in_DB(
        int id,
        string type
    )
    {
        ofstream fout("category.csv", ios_base::app);
        if (fout.is_open()) {
            fout << endl << id << " " << type;
        }
        fout.close();
    }

    void delete_category_from_DB() {
        ofstream f("category.csv");
        if (f.is_open()) {
            short j = 0;
            for (auto i : g::category_list) {
                f << i->get_id() << " " << i->get_type();
                if (j < g::category_list.size() - 1)
                    f << endl;
                j++;
            }
            f.close();
        }
    }

    void write_product_in_DB(
        int id,
        string name,
        float price,
        int category,
        int rate
    )
    {
        ofstream f("products.csv", ios_base::app);
        if (f.is_open()) {
            f << endl <<
                id << " " <<
                name << " " <<
                price << " " <<
                category << " " <<
                rate;
        }
        f.close();
    }

    void delete_product_from_DB() {
        ofstream f("products.csv");
        if (f.is_open()) {
            short j = 0;
            for (auto i : g::product_data_base) {
                f << i->get_id() << " " <<
                    i->get_name() << " " <<
                    i->get_price() << " " <<
                    i->get_category() << " " <<
                    i->get_rate();
                if (j < g::product_data_base.size() - 1)
                    f << endl;
                j++;
            }
            f.close();
        }
    }

    void userlist       (bool);
    void productlist    (bool);
    void categorylist   (bool);

public:
    
    string  get_name()          override;
    string  get_login()         override; 
    string  get_password()      override;

    bool    get_admin()         override;
    
    void    CCS()               override;
    void    CCS_respond(int i)    override;

    admin() {};
   ~admin() {};
};