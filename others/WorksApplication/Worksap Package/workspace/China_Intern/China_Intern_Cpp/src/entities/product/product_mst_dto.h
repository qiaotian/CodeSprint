#ifndef PRODUCT_MST_DTO_H_
#define PRODUCT_MST_DTO_H_

#include "../icsv_master_dto.h"
#include "../../constants/price_unit_type.h"
#include <string>
using namespace std;

class ProductMstDTO: public ICsvMasterDTO {
public:
	ProductMstDTO(long product_mst_id, string product_type, string product_name, double price, PriceUnitType price_unit);
	long &get_product_mst_id();
	string &get_product_type();
	string &get_product_name();
    double &get_price();
	PriceUnitType &get_price_unit();

	friend ostream &operator <<(ostream &out, ProductMstDTO &obj);
	friend istream &operator >>(istream &in, ProductMstDTO &obj);

private:
	long product_mst_id;
	string product_type;
	string product_name;
    double price;
	PriceUnitType price_unit;
};

#endif /* PRODUCT_MST_DTO_H_ */
