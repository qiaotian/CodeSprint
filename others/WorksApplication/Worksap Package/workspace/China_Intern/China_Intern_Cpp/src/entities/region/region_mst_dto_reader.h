#ifndef REGION_MST_DTO_READER_H_
#define REGION_MST_DTO_READER_H_

#include "../abstract_dto_reader.h"
#include "region_mst_dto.h"
#include "../icsv_master_dto.h"

class RegionMstDTOReader: public AbstractDTOReader {
public:
	RegionMstDTOReader();
	RegionMstDTOReader(string &file_address);
	ICsvMasterDTO *convert_array_to_dto(vector<string> &value);
	string get_file_address();
	~RegionMstDTOReader();

private:
	string file_address;
	static const int COLUMN_INDEX_REGION_ID = 0;
	static const int COLUMN_INDEX_NAME = 1;
	static const int COLUMN_INDEX_MANAGER_ID = 2;
};

#endif /* REGION_MST_DTO_READER_H_ */
