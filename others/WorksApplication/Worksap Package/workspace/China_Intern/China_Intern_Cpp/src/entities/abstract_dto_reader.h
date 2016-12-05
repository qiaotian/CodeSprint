/*
 * abstract_dto_reader.h
 *
 *  Created on: Jul 14, 2014
 *  Updated on: Jul 20, 2015
 */

#ifndef ABSTRACT_DTO_READER_H_
#define ABSTRACT_DTO_READER_H_

#include "icsv_master_dto.h"
#include <string>
#include <vector>
using namespace std;

class AbstractDTOReader {
public :
	vector<ICsvMasterDTO *> get_values();
	virtual ~AbstractDTOReader();
	void init();
	virtual ICsvMasterDTO *convert_array_to_dto(vector<string> &value);
	virtual string get_file_address();

private:
	vector<ICsvMasterDTO *> values;
};

#endif /* ABSTRACT_DTO_READER_H_ */
