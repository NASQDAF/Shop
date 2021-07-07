#pragma once
#include "globalink.h"
#include "iostream"
#include "string"

using namespace std;
class basket {
private:
    vector<product*> bag_of_the_dicks;
    
    int total_price = 0;
public:
    void get_list_of_products(bool b=0) {
        short j = 1;
        for (auto i : bag_of_the_dicks) {
            if (b)
                cout << "[" << j++ << "]: ";
            cout << i->get_name() << " " << i->get_price() << endl;
        }
    }
    float get_total_price() {
        total_price = 0;
        
        for (auto i : bag_of_the_dicks)
            total_price += i->get_price();
        return total_price;
    }
    void add_product_basket(short k) {
        bag_of_the_dicks.push_back(g::product_data_base[k-1]);
    }
    short size() { return bag_of_the_dicks.size(); }
    void erase(short k) { bag_of_the_dicks.erase(bag_of_the_dicks.begin() + k-1); }
    void clear() { bag_of_the_dicks.clear(); }
    basket() {};
    ~basket() {};
};