#include "supermarket_mst_dto_reader.h"
#include "supermarket_mst_dto.h"
#include "../../constants/constants.h"
#include "../icsv_master_dto.h"
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

SupermarketMstDTOReader::SupermarketMstDTOReader() {
	this->file_address = kDefaultCsvFolder + "SUPERMARKET_MST.csv";
	AbstractDTOReader::init();
}

SupermarketMstDTOReader::SupermarketMstDTOReader(string &file_address) {
	this->file_address = file_address;
	AbstractDTOReader::init();
}

string SupermarketMstDTOReader::get_file_address() {
	return this->file_address;
}

ICsvMasterDTO *SupermarketMstDTOReader::convert_array_to_dto(vector<string> &value) {
	long supermarket_id = atol(value[COLUMN_INDEX_SUPERMARKET_ID].c_str());
	string supermarket_name = value[COLUMN_INDEX_SUPERMARKET_NAME];
	string address = value[COLUMN_INDEX_ADDRESS];
	string tel = value[COLUMN_INDEX_TEL];
	ICsvMasterDTO *obj = new SupermarketMstDTO(supermarket_id, supermarket_name, address, tel);
	return obj;
}

SupermarketMstDTOReader::~SupermarketMstDTOReader() {

}

