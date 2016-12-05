#include "staff_dto_reader.h"
#include "staff_dto.h"
#include "../../constants/constants.h"
#include "../icsv_master_dto.h"
#include "rank_type.h"
#include "position_type.h"
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

StaffDTOReader::StaffDTOReader() {
	this->file_address = kDefaultCsvFolder + "STAFF_MST.csv";
	AbstractDTOReader::init();
}

StaffDTOReader::StaffDTOReader(string &file_address) {
	this->file_address = file_address;
	AbstractDTOReader::init();
}

string StaffDTOReader::get_file_address() {
	return this->file_address;
}

ICsvMasterDTO *StaffDTOReader::convert_array_to_dto(vector<string> &value) {
	long staff_id = atol(value[COLUMN_INDEX_STAFF_ID].c_str());
	string name = value[COLUMN_INDEX_NAME];
	string gender = value[COLUMN_INDEX_GENDER];
	RankType rank = rank_type_value_of_string(value[COLUMN_INDEX_RANK]);
	PositionType position = position_type_value_of_string(
			value[COLUMN_INDEX_POSITION]);
	long supermarket_id = atol(value[COLUMN_INDEX_SUPERMARKET_ID].c_str());
	ICsvMasterDTO *obj = new StaffDTO(staff_id, name, gender, rank,
			position, supermarket_id);
	return obj;
}

StaffDTOReader::~StaffDTOReader() {

}

