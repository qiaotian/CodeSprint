#ifndef STAFF_DTO_READER_H_
#define STAFF_DTO_READER_H_

#include "../abstract_dto_reader.h"
#include "staff_dto.h"
#include "../icsv_master_dto.h"

class StaffDTOReader: public AbstractDTOReader {
public:
	StaffDTOReader();
	StaffDTOReader(string &file_address);
	ICsvMasterDTO *convert_array_to_dto(vector<string> &value);
	string get_file_address();
	~StaffDTOReader();

private:
	string file_address;
	static const int COLUMN_INDEX_STAFF_ID = 0;
	static const int COLUMN_INDEX_NAME = 1;
	static const int COLUMN_INDEX_GENDER = 2;
	static const int COLUMN_INDEX_RANK = 3;
	static const int COLUMN_INDEX_POSITION = 4;
	static const int COLUMN_INDEX_SUPERMARKET_ID = 5;
};

#endif /* STAFF_DTO_READER_H_ */
