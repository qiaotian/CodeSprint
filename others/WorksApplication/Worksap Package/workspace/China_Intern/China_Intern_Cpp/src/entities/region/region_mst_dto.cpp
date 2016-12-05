#include "region_mst_dto.h"
#include <iostream>
using namespace std;

RegionMstDTO::RegionMstDTO(long region_id, string name, long manager_id) {
	this->region_id = region_id;
	this->name = name;
	this->manager_id = manager_id;
}

long &RegionMstDTO::get_region_id() {
	return region_id;
}

string &RegionMstDTO::get_name() {
	return name;
}

long &RegionMstDTO::get_manager_id() {
	return manager_id;
}

ostream &operator <<(ostream &out, RegionMstDTO &obj) {
	out << obj.region_id << " " << obj.name << " " << obj.manager_id;
	return out;
}

istream &operator >>(istream &in, RegionMstDTO &obj) {
	in >> obj.region_id >> obj.name >> obj.manager_id;
	return in;
}
