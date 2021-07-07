#pragma once
#include <string>
class uf {
public:
    virtual void    CCS_respond(int k)  = 0;
    virtual std::string  get_password() = 0;
    virtual bool    get_admin()         = 0;
    virtual std::string  get_login()    = 0;
    virtual std::string  get_name()     = 0;
    virtual void    CCS()               = 0;

};