#include "position_type.h"
#include <string>
#include <stdexcept>
using namespace std;

string position_type_to_string(PositionType type) {
	switch (type) {
	case staff:
		return "staff";
	case manager:
		return "manager";
	case region_manager:
		return "region manager";
	default:
		return "";
	}
}

PositionType position_type_value_of_string(string src) {
	// convert the string, src, in its upper case
	for (string::iterator it = src.begin(); it != src.end(); it++) {
		*it = tolower(*it);
	}

	if (src == "staff") {
		return staff;
	}

	if (src == "manager") {
		return manager;
	}

	if (src == "region manager") {
		return region_manager;
	}

	throw invalid_argument("Unknown Position Type : " + src);
}

