#include "region_mst_dto_reader.h"
#include "region_mst_dto.h"
#include "../../constants/constants.h"
#include "../icsv_master_dto.h"
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

RegionMstDTOReader::RegionMstDTOReader() {
	this->file_address = kDefaultCsvFolder + "REGION_MST.csv";
	AbstractDTOReader::init();
}

RegionMstDTOReader::RegionMstDTOReader(string &file_address) {
	this->file_address = file_address;
	AbstractDTOReader::init();
}

string RegionMstDTOReader::get_file_address() {
	return this->file_address;
}

ICsvMasterDTO *RegionMstDTOReader::convert_array_to_dto(vector<string> &value) {
	long region_id = atol(value[COLUMN_INDEX_REGION_ID].c_str());
	string name = value[COLUMN_INDEX_NAME];
	long manager_id = atol(value[COLUMN_INDEX_MANAGER_ID].c_str());
	ICsvMasterDTO *obj = new RegionMstDTO(region_id, name, manager_id);
	return obj;
}

RegionMstDTOReader::~RegionMstDTOReader() {

}

