#ifndef CSV_WRITER_H_
#define CSV_WRITER_H_

#include <iostream>
#include <string>
#include <vector>
#include "csv_constants.h"
using namespace std;

class CSVWriter {
public:
	CSVWriter(ofstream &out);
	CSVWriter(ofstream &out, char separator);
	CSVWriter(ofstream &out, char separator, char quotechar);
	void write_all(vector<vector<string> > all_lines);
	void close();

private:
	ofstream &out;
	char separator;
	char quotechar;

	void write_next(vector<string> &next_line);
};

#endif /* CSV_WRITER_H_ */
