#include "abstract_dto_reader.h"
#include "icsv_master_dto.h"
#include "../csv_parser/csv_reader.h"
#include "../constants/constants.h"
#include "../util/utilities.h"
#include <vector>
#include <string>
using namespace std;

vector<ICsvMasterDTO *> AbstractDTOReader::get_values() {
	return values;
}

void AbstractDTOReader::init() {
	ifstream file_reader(this->get_file_address().c_str());
	if (file_reader) {
		CSVReader csv_reader(file_reader, kDefaultCsvSeparator);
		vector<string> value;
		csv_reader.read_next(value); // skip header
		csv_reader.read_next(value);
		while (!value.empty()) {
			values.push_back(this->convert_array_to_dto(value));
			csv_reader.read_next(value);
		}
		Utilities::close_siently(csv_reader);
	}
	Utilities::close_siently(file_reader);
}

ICsvMasterDTO *AbstractDTOReader::convert_array_to_dto(vector<string> &value) {
	ICsvMasterDTO *dto = new ICsvMasterDTO();
	return dto;
}

string AbstractDTOReader::get_file_address() {
	string str = "csv address";
	return str;
}

AbstractDTOReader::~AbstractDTOReader() {
	for (vector<ICsvMasterDTO *>::iterator it = values.begin(); it != values.end(); it++) {
		delete *it;
	}
}

