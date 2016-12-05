#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include "csv_writer.h"
using namespace std;

CSVWriter::CSVWriter(ofstream &out) :
		out(out) {
	this->separator = kDefaultSeparator;
	this->quotechar = kQuotechar;
}

CSVWriter::CSVWriter(ofstream &out, char separator) :
		out(out) {
	this->separator = separator;
	this->quotechar = kQuotechar;
}

CSVWriter::CSVWriter(ofstream &out, char separator, char quotechar) :
		out(out) {
	this->separator = separator;
	this->quotechar = quotechar;
}

void CSVWriter::write_all(vector<vector<string> > all_lines) {
	for (vector<vector<string> >::iterator it = all_lines.begin(); it != all_lines.end(); it++) {
		this->write_next(*it);
	}
}

void CSVWriter::close() {
	this->out.flush();
	this->out.close();
}

void CSVWriter::write_next(vector<string> &next_line) {
	if (next_line.empty()) {
		return;
	}
	string line = "";
	for (vector<string>::iterator it = next_line.begin(); it != next_line.end(); it++) {
		if (it != next_line.begin())
			line += this->separator;
		line += this->quotechar;
		line += *it;
		line += this->quotechar;
	}
	this->out << line << endl;
}

