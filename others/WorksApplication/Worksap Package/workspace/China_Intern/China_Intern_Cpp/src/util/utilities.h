#ifndef UTILITIES_H_
#define UTILITIES_H_

#include "../csv_parser/csv_reader.h"
#include "../csv_parser/csv_writer.h"
#include <iostream>
#include <ctime>
using namespace std;

class Utilities {
public:
	static void close_siently(ifstream &in);
	static void close_siently(CSVReader &reader);
	static void close_siently(CSVWriter &writer);
	static struct tm parse_date_without_time_str(string &date_str);
	static string format_date_without_time(struct tm &date);
	static struct tm parse_date_str(string &date_str);
	static string format_date(struct tm &date);
	static struct tm parse_time_str(string &time_str);
	static string format_time(struct tm &time);

private:
	static const string kDefaultDateWithoutTimeFormat;
	static const string kDefaultDateFormat;
	static const string kDefaultTimeFormat;
};

#endif /* UTILITIES_H_ */
