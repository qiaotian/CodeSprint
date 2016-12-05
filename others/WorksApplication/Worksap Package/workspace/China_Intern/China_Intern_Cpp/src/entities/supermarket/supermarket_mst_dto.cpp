#include "supermarket_mst_dto.h"
#include <iostream>
using namespace std;

SupermarketMstDTO::SupermarketMstDTO(long supermarket_id, string supermarket_name, string address,
		string tel) {
	this->supermarket_id = supermarket_id;
	this->supermarket_name = supermarket_name;
	this->address = address;
	this->tel = tel;
}

long &SupermarketMstDTO::get_supermarket_id() {
	return supermarket_id;
}

string &SupermarketMstDTO::get_supermarket_name() {
    return supermarket_name;
}

string &SupermarketMstDTO::get_address() {
	return address;
}

string &SupermarketMstDTO::get_tel() {
	return tel;
}

ostream &operator <<(ostream &out, SupermarketMstDTO &obj) {
	out << obj.supermarket_id << " " << obj.address << " "
			<< obj.tel;
	return out;
}

istream &operator >>(istream &in, SupermarketMstDTO &obj) {
	in >> obj.supermarket_id >> obj.address >> obj.tel;
	return in;
}

