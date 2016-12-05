#ifndef CUSTOMER_DTO_READER_H_
#define CUSTOMER_DTO_READER_H_

#include "../abstract_dto_reader.h"
#include "customer_dto.h"
#include "../icsv_master_dto.h"

class CustomerDTOReader: public AbstractDTOReader {
public:
	CustomerDTOReader();
	CustomerDTOReader(string &file_address);
	ICsvMasterDTO *convert_array_to_dto(vector<string> &value);
	string get_file_address();
	~CustomerDTOReader();

private:
	string file_address;
	static const int COLUMN_INDEX_CUSTOMER_ID = 0;
	static const int COLUMN_INDEX_NAME = 1;
	static const int COLUMN_INDEX_GENDER = 2;
	static const int COLUMN_INDEX_TEL = 3;
};

#endif /* CUSTOMER_DTO_READER_H_ */
