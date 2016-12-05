#include "price_unit_type.h"
#include <stdexcept>
#include <string>
using namespace std;

string price_unit_type_to_string(PriceUnitType type) {
	switch (type) {
	case USD:
		return "USD";
	case EURO:
		return "EURO";
	case JPY:
		return "JPY";
	case CNY:
		return "CNY";
	default:
		return "";
	}
}

PriceUnitType price_unit_type_value_of_string(string src) {

	// convert the string, src, in its upper case
	for (string::iterator it = src.begin(); it != src.end(); it++) {
		*it = toupper(*it);
	}

	if (src == "USD") {
		return USD;
	}

	if (src == "EURO") {
		return EURO;
	}

	if (src == "JPY") {
		return JPY;
	}

	if (src == "CNY") {
		return CNY;
	}

	throw invalid_argument("Unknown Price Unit Type : " + src);
}




