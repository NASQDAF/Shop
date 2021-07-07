/**
product.csv
Id;Name;Price;Category;Rating
1;Smart TV;7000;3;1;
2;Apple iPhone 8;10000;1;8;
3;Mobile Redmi Note 9; 4000;1;2;


category.csv
Id;Name;
1;Cell phones;
2;Notebooks;
3;TV sets;


user.csv
id;Name;login;password;
1;John;username;11111;
2;Jane;user1;aaa1;


Задания.
1*. В режиме админа добавлять товары (и категории). (также удалять или изменять цены)                                       +
2. В режиме пользователя залогиниться, просмотреть список товаров                                                           +
3. Положить товар в корзину.                                                                                                +
4. Просмотреть список товаров в корзине.
5. Купить )                                                                                                                 +


Реализация
а) Создать класс Товар, имеющий переменные имя, цена, рейтинг.                                                              +
б) Создать класс Категория, имеющий переменные имя и массив товаров. Создать несколько объектов класса Категория.           +
в) Создать класс Basket, содержащий массив купленных товаров.                                                               +
г) Создать класс User, содержащий логин, пароль и объект класса Basket. Создать объект класса User. (Интернет магазин)      +
*/
#include "globalink.h"
#include "ELF.h"
#include "admin.h"
#include "user.h"
#include "basket.h"
#include "category.h"
#include "product.h"

int getnextid(vector<product*> P) { return P[P.size()-1]->get_id() + 1; }
int getnextid(vector<category*> P) { return P[P.size()-1]->get_id() + 1; }

int main() {
    setlocale(0, "");
#pragma region INITIALISATION
    uf* cla = NULL;
    g::user_data_base.push_back(new admin);

    ifstream fin("users.csv");
    if (fin.is_open()) {
        while (!fin.eof()) {
            string name, login, password;
            fin >> name >> login >> password;
            g::user_data_base.push_back(new user(name, login, password));
        }
        fin.close();
    }
    
    ifstream finprod("products.csv");
    if (finprod.is_open()) {
        while (!finprod.eof()) {
            int id, category, rate;
            float price;
            string name;
            finprod >> id >> name >> price >> category >> rate;
            //name.replace("_", " ");
            g::product_data_base.push_back(new product(id, name, price, category, rate));
        }
        finprod.close();
    }
    
    ifstream fincat("category.csv");
    if (fincat.is_open()) {
        while (!fincat.eof()) {
            int id;
            string type;
            fincat >> id >> type;
            g::category_list.push_back(new category(id, type));
        }
        fincat.close();
    }
#pragma endregion

    string login, password;
    
    while (1) {
        bool ka = 0;
        short aut=0;
        cout << " 1) Authorize\n 2) Power off\n>";
        cin >> aut;
        ka = aut - 1;
        if (ka)
            exit(0);
        system("cls");
        bool n = 0;
        while (n != 1) {
            cout << "Login: "; cin >> login;
            if (login == "exit")
                exit(0);
            cout << "Password: "; cin >> password;
            for (auto i : g::user_data_base)
                if (login != "exit") {
                    if (login == i->get_login() && password == i->get_password()) {
                        cout << i->get_admin();
                        cla = i;
                        n = 1;
                        break;
                    }
                }
                else
                    exit(0);
            system("cls");
            cout << "\n\tIncorrect login or password.\n";
        }
        short sh = -1;
        while (1)
        {
            system("cls");
            cla->CCS();
            cin >> sh;
            if (sh == 0)
                break;
            cla->CCS_respond(sh);
        }
        system("cls");
    }

}