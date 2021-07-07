#pragma once
#include "vector"
#include "product.h"
#include "category.h"
#include "ELF.h"
using namespace std;
namespace g {
	std::vector<uf*>			user_data_base;
	std::vector<product*>	product_data_base;
	std::vector<category*>	category_list;
}