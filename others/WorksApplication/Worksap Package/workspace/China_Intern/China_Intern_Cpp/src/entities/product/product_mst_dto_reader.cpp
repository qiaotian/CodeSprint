#include "product_mst_dto.h"
#include "product_mst_dto_reader.h"
#include "../../constants/constants.h"
#include "../icsv_master_dto.h"
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

ProductMstDTOReader::ProductMstDTOReader() {
	this->file_address = kDefaultCsvFolder + "PRODUCT_MST.csv";
	AbstractDTOReader::init();
}

ProductMstDTOReader::ProductMstDTOReader(string &file_address) {
	this->file_address = file_address;
	AbstractDTOReader::init();
}

string ProductMstDTOReader::get_file_address() {
	return this->file_address;
}

ICsvMasterDTO *ProductMstDTOReader::convert_array_to_dto(vector<string> &value) {
	long product_mst_id = atol(value[COLUMN_INDEX_PRODUCT_MST_ID].c_str());
	string product_type = value[COLUMN_INDEX_PRODUCT_TYPE];
	string product_name = value[COLUMN_INDEX_PRODUCT_NAME];
	double price = atof(value[COLUMN_INDEX_PRICE].c_str());
	PriceUnitType price_unit = price_unit_type_value_of_string(value[COLUMN_INDEX_PRICE_UNIT]);
	ICsvMasterDTO *obj = new ProductMstDTO(product_mst_id, product_type, product_name, price, price_unit);
	return obj;
}

ProductMstDTOReader::~ProductMstDTOReader() {

}

