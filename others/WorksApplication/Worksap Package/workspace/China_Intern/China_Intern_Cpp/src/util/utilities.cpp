#include "utilities.h"
#include "../csv_parser/csv_reader.h"
#include "../csv_parser/csv_writer.h"
#include "strptime.h"
#include <iostream>
#include <ctime>
#include <stdexcept>
using namespace std;

const string Utilities::kDefaultDateWithoutTimeFormat = "%Y/%m/%d";
const string Utilities::kDefaultDateFormat = "%Y/%m/%d %H:%M";
const string Utilities::kDefaultTimeFormat = "%H:%M";

void Utilities::close_siently(ifstream &in) {
	if (in && in.is_open()) {
		in.close();
	}
}

void Utilities::close_siently(CSVReader &reader) {
	reader.close();
}

void Utilities::close_siently(CSVWriter &writer) {
	writer.close();
}

struct tm Utilities::parse_date_without_time_str(string &date_str) {
	struct tm time_struct;
	if (!strptime(date_str.c_str(), Utilities::kDefaultDateWithoutTimeFormat.c_str(),
			&time_struct)) {
		throw invalid_argument("Failed to parse Date String! Please use format: " + Utilities::kDefaultDateWithoutTimeFormat);
	}
	return time_struct;
}

string Utilities::format_date_without_time(struct tm &date) {
	char buf[256] = {0};
	strftime(buf, 256, Utilities::kDefaultDateWithoutTimeFormat.c_str(), &date);
	string date_str(buf);
	return date_str;
}

struct tm Utilities::parse_date_str(string &date_str) {
	struct tm time_struct;
	if (!strptime(date_str.c_str(), Utilities::kDefaultDateFormat.c_str(),
			&time_struct)) {
		throw invalid_argument("Failed to parse Date String! Please use format: " + Utilities::kDefaultDateFormat);
	}
	return time_struct;
}

string Utilities::format_date(struct tm &date) {
	char buf[256] = {0};
	strftime(buf, 256, Utilities::kDefaultDateFormat.c_str(), &date);
	string date_str(buf);
	return date_str;
}

struct tm Utilities::parse_time_str(string &time_str) {
	struct tm time_struct;
	if (!strptime(time_str.c_str(), Utilities::kDefaultTimeFormat.c_str(),
			&time_struct)) {
		throw invalid_argument("Failed to parse Time String! Please use format: " + Utilities::kDefaultTimeFormat);
	}
	return time_struct;
}

string Utilities::format_time(struct tm &time) {
	char buf[256] = {0};
	strftime(buf, 256, Utilities::kDefaultTimeFormat.c_str(), &time);
	string time_str(buf);
	return time_str;
}

