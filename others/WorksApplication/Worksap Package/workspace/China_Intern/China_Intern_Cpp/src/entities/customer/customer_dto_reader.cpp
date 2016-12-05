#include "customer_dto_reader.h"
#include "customer_dto.h"
#include "../icsv_master_dto.h"
#include "../../util/utilities.h"
#include "../../constants/constants.h"
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

CustomerDTOReader::CustomerDTOReader() {
	this->file_address = kDefaultCsvFolder + "CUSTOMER_MST.csv";
	AbstractDTOReader::init();
}

CustomerDTOReader::CustomerDTOReader(string &file_address) {
	this->file_address = file_address;
	AbstractDTOReader::init();
}

string CustomerDTOReader::get_file_address() {
	return this->file_address;
}

ICsvMasterDTO *CustomerDTOReader::convert_array_to_dto(vector<string> &value) {
	long customer_id = atol(value[COLUMN_INDEX_CUSTOMER_ID].c_str());
	string name = value[COLUMN_INDEX_NAME];
	string gender = value[COLUMN_INDEX_GENDER];
	string tel = value[COLUMN_INDEX_TEL];
	ICsvMasterDTO *obj = new CustomerDTO(customer_id, name, gender, tel);
	return obj;
}

CustomerDTOReader::~CustomerDTOReader() {

}
