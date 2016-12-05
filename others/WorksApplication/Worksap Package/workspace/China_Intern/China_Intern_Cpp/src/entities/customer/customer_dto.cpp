#include "customer_dto.h"
#include "../../util/utilities.h"
#include <string>
using namespace std;

CustomerDTO::CustomerDTO(long customer_id, string name, string gender, string tel) {
	this->customer_id = customer_id;
	this->name = name;
	this->gender = gender;
	this->tel = tel;
}

long &CustomerDTO::get_customer_id() {
	return customer_id;
}

string &CustomerDTO::get_name() {
	return name;
}

string &CustomerDTO::get_gender() {
	return gender;
}

string &CustomerDTO::get_tel() {
	return tel;
}

ostream &operator <<(ostream &out, CustomerDTO &obj) {
	out << obj.customer_id << " " << obj.name << " " << obj.gender << " " << obj.tel;
	return out;
}

istream &operator >>(istream &in, CustomerDTO &obj) {
	in >> obj.customer_id >> obj.name >> obj.gender >> obj.tel;
	return in;
}

