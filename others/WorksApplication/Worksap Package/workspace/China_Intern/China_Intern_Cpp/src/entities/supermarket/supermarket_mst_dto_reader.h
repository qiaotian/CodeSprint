#ifndef SUPERMARKET_MST_DTO_READER_H_
#define SUPERMARKET_MST_DTO_READER_H_

#include "../abstract_dto_reader.h"
#include "supermarket_mst_dto.h"
#include "../icsv_master_dto.h"

class SupermarketMstDTOReader: public AbstractDTOReader {
public:
	SupermarketMstDTOReader();
	SupermarketMstDTOReader(string &file_address);
	ICsvMasterDTO *convert_array_to_dto(vector<string> &value);
	string get_file_address();
	~SupermarketMstDTOReader();

private:
	string file_address;
	static const int COLUMN_INDEX_SUPERMARKET_ID = 0;
	static const int COLUMN_INDEX_SUPERMARKET_NAME = 1;
	static const int COLUMN_INDEX_ADDRESS = 2;
	static const int COLUMN_INDEX_TEL = 3;
};

#endif /* SUPERMARKET_MST_DTO_READER_H_ */
