#include "staff_dto.h"
#include "rank_type.h"
#include "position_type.h"
#include <iostream>
using namespace std;

StaffDTO::StaffDTO(long staff_id, string name, string gender,
		RankType rank, PositionType position, long shop_id) {
	this->staff_id = staff_id;
	this->name = name;
	this->gender = gender;
	this->rank = rank;
	this->position = position;
	this->supermarket_id = supermarket_id;
}

long &StaffDTO::get_staff_id() {
	return staff_id;
}

string &StaffDTO::get_name() {
	return name;
}

string &StaffDTO::get_gender() {
	return gender;
}

RankType &StaffDTO::get_rank() {
	return rank;
}

PositionType &StaffDTO::get_position() {
	return position;
}

long &StaffDTO::get_supermarket_id() {
	return supermarket_id;
}

ostream &operator <<(ostream &out, StaffDTO &obj) {
	out << obj.staff_id << " " << obj.name << " " << obj.gender << " "
			<< rank_type_to_string(obj.rank) << " "
			<< position_type_to_string(obj.position) << " " << obj.supermarket_id;
	return out;
}

istream &operator >>(istream &in, StaffDTO &obj) {
	string rank_type_str;
	string position_type_str;
	in >> obj.staff_id >> obj.name >> obj.gender >> rank_type_str
			>> position_type_str >> obj.supermarket_id;
	obj.rank = rank_type_value_of_string(rank_type_str);
	obj.position = position_type_value_of_string(position_type_str);
	return in;
}

