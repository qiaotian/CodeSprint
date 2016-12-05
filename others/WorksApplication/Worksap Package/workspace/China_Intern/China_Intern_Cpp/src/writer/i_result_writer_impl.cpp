#include "i_result_writer_impl.h"
#include "../constants/constants.h"
#include "../csv_parser/csv_writer.h"
#include "../util/utilities.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

const string IResultWriterImpl::DEFAULT_OUTPUT_FILE_NAME = "result.csv";

IResultWriterImpl::IResultWriterImpl() {
	this->out_file_path = kDefaultCsvOutputFolder + DEFAULT_OUTPUT_FILE_NAME;
}

IResultWriterImpl::IResultWriterImpl(string &file_address) {
	this->out_file_path = file_address;
}

void IResultWriterImpl::write_result(vector<vector<string> > result) {
	ofstream out(out_file_path.c_str());
	CSVWriter writer(out, kDefaultCsvSeparator, kDefaultCsvQuotechar);
	writer.write_all(result);
	Utilities::close_siently(writer);
}

IResultWriterImpl::~IResultWriterImpl() {

}

