#pragma once
#include "string"
class category {
private:
    std::string  type;
    int     id;
public:
    int get_id()        { return id; };
    std::string get_type()   { return type; };
    ~category();
    category();
    category(int id, std::string type) { this->type = type; this->id = id; }
};