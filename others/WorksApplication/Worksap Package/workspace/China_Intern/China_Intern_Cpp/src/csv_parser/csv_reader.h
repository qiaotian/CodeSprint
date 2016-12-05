#ifndef CSV_READER_H_
#define CSV_READER_H_

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "csv_constants.h"
using namespace std;

class CSVReader {
public:
	CSVReader(ifstream &in);
	CSVReader(ifstream &in, const char separator);
	CSVReader(ifstream &in, const char separator, const char quotechar);
	void read_next(vector<string> &result);
	void close();

private:
	ifstream &in;
	char separator;
	char quotechar;

	string trim_quotes(string &cell);
};

#endif /* CSV_READER_H_ */
