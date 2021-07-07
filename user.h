#pragma once
#include "globalink.h"
#include "basket.h"
class user : public uf, basket {
private:
    basket bask;
    string name = "user";
    string login = "user";
    string password = "1";
    void productlist(bool);
    const bool is_admin = false;
    
public:
    void    CCS_respond(int)    override;
    string  get_password()      override;
    bool    get_admin()         override;
    string  get_login()         override;
    string  get_name()          override;
    void    CCS()               override;

    user(string, string, string);
    user(string, string);
    user() {};
   ~user() {};
};