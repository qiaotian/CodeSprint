#ifndef PRICEUNITTYPE_H_
#define PRICEUNITTYPE_H_

#include <string>
using namespace std;

enum PriceUnitType {
	USD, EURO,JPY, CNY
};

string price_unit_type_to_string(PriceUnitType type);
PriceUnitType price_unit_type_value_of_string(string src);

#endif /* PRICEUNITTYPE_H_ */
