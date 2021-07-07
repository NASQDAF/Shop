#pragma once
#include "string"
using namespace std;
#include "category.h"

class product : public category {
private:
    string  name;
    float   price;
    int     pcategory;
    int     rate;
    int     id;

public:
    int get_id() { return id; }
    int get_rate() { return rate; }
    int get_category() { return pcategory; }
    float get_price() { return price; }
    void set_price(float price) { this->price = price; }
    string get_name() { return name; }
    void add_product(int id, string name, float price, int category, int rate) {
        this->id = id;
        this->name = name;
        this->price = price;
        this->pcategory = category;
        this->rate = rate;
    };
    void add_product(int id, string name, float price, int category) {
        this->id = id;
        this->name = name;
        this->price = price;
        this->pcategory = category;
        this->rate = 0;
    };
    string get_name(int id) { return name; }
    product() {}
    product(int id, string name, float price, int pcategory, int rate) {
        this->id = id;
        this->name = name;
        this->price = price;
        this->pcategory = pcategory;
        this->rate = rate;
    }
    ~product() {};
};