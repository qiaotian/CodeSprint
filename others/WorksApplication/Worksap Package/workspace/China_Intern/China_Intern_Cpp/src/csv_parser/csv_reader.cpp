#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include "csv_reader.h"
using namespace std;

CSVReader::CSVReader(ifstream &in) :
		in(in) {
	if (!this->in) {
		throw invalid_argument("File not exist.");
	}
	this->separator = kDefaultSeparator;
	this->quotechar = kQuotechar;
}

CSVReader::CSVReader(ifstream &in, const char separator) :
		in(in) {
	if (!this->in) {
		throw invalid_argument("File not exist.");
	}
	this->separator = separator;
	this->quotechar = kQuotechar;
}

CSVReader::CSVReader(ifstream &in, const char separator, const char quotechar) :
		in(in) {
	if (!this->in) {
		throw invalid_argument("File not exist.");
	}
	this->separator = separator;
	this->quotechar = quotechar;
}

void CSVReader::read_next(vector<string> &result) {
	result.clear();
	string line;
	string lineTmp;

	// is_first_read and quote_count_per_line are used in the case that the date in one column contains '\n'
	bool is_first_read = true;
	int quote_count_per_line = 0;
	while (is_first_read || quote_count_per_line % 2 != 0) {
		is_first_read = false;
		if (getline(this->in, lineTmp) == NULL) {
			return;
		}
		for (unsigned i = 0; i < lineTmp.size(); i++) {
			char c = lineTmp[i];
			if (c == kQuotechar) {
				quote_count_per_line++;
			}
		}
		line += lineTmp;
	}

	int start_index = 0;

	int quote_count = 0;
	int size = line.size();
	for (int i = 0; i < size; i++) {
		char c = line[i];
		if (c == this->quotechar) {
			quote_count++;
			continue;
		}

		if (c == this->separator && quote_count % 2 == 0) {
			string cell = line.substr(start_index, i - start_index);
			result.push_back(trim_quotes(cell));
			start_index = i + 1;
		}
	}
	string cell = line.substr(start_index, size - start_index);
	result.push_back(trim_quotes(cell));
}

void CSVReader::close() {
	if (this->in.is_open())
		this->in.close();
}

string CSVReader::trim_quotes(string &cell) {
	if (cell.empty()) {
		return cell;
	}
	if (cell[0] == this->quotechar && cell.size() > 2) {
		return cell.substr(1, cell.size() - 2);
	} else {
		return cell;
	}
}

