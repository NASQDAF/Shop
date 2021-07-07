#include "product.h"
void    product::set_price(float price) { this->price = price; }
int     product::get_category() { return category; }
float   product::get_price()    { return price; }
int     product::get_rate()     { return rate; }
string  product::get_name()     { return name; }
int     product::get_id()       { return id; }
void    product::add_product(int id, string name, float price, int category) {
    this->id        = id;
    this->name      = name;
    this->price     = price;
    this->category = category;
    this->rate      = 0;
};
void    product::add_product(int id, string name, float price, int category, int rate) {
    this->id        = id;
    this->name      = name;
    this->price     = price;
    this->category = category;
    this->rate      = rate;
};
product::product(int id, string name, float price, int category, int rate) {
    this->id = id;
    this->name = name;
    this->price = price;
    this->category = category;
    this->rate = rate;
}