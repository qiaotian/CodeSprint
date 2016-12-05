#include "product_mst_dto.h"
#include <iostream>
using namespace std;

ProductMstDTO::ProductMstDTO(long product_mst_id, string product_type, string product_name, double price, PriceUnitType price_unit) {
	this->product_mst_id = product_mst_id;
	this->product_type = product_type;
	this->product_name = product_name;
	this->price = price;
	this->price_unit = price_unit;
}

long &ProductMstDTO::get_product_mst_id() {
	return product_mst_id;
}

string &ProductMstDTO::get_product_type() {
	return product_type;
}

string &ProductMstDTO::get_product_name() {
	return product_name;
}

double &ProductMstDTO::get_price() {
    return price;
}

PriceUnitType &ProductMstDTO::get_price_unit() {
    return price_unit;
}

ostream &operator <<(ostream &out, ProductMstDTO &obj) {
	out << obj.product_mst_id << " " << obj.product_type << " "
			<< obj.product_name << " " << obj.price << " " << obj.price_unit;
	return out;
}

istream &operator >>(istream &in, ProductMstDTO &obj) {
    string price_unit;
	in >> obj.product_mst_id >> obj.product_type >> obj.product_name >> obj.price >> price_unit;
	obj.price_unit = price_unit_type_value_of_string(price_unit);
	return in;
}

