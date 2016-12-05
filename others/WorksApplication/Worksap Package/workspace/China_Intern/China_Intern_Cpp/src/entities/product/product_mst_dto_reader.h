#ifndef PRODUCT_MST_DTO_READER_H_
#define PRODUCT_MST_DTO_READER_H_

#include "../abstract_dto_reader.h"
#include "../icsv_master_dto.h"

class ProductMstDTOReader: public AbstractDTOReader {
public:
	ProductMstDTOReader();
	ProductMstDTOReader(string &file_address);
	ICsvMasterDTO *convert_array_to_dto(vector<string> &value);
	string get_file_address();
	~ProductMstDTOReader();

private:
	string file_address;
	static const int COLUMN_INDEX_PRODUCT_MST_ID = 0;
	static const int COLUMN_INDEX_PRODUCT_TYPE = 1;
	static const int COLUMN_INDEX_PRODUCT_NAME = 2;
	static const int COLUMN_INDEX_PRICE = 3;
	static const int COLUMN_INDEX_PRICE_UNIT = 4;
};

#endif /* PRODUCT_MST_DTO_READER_H_ */
