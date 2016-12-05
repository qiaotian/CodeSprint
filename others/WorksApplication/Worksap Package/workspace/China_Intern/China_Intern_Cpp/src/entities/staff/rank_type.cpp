#include "rank_type.h"
#include <string>
#include <stdexcept>
using namespace std;

string rank_type_to_string(RankType type) {
	switch (type) {
	case assistant:
		return "assistant";
	case senior:
		return "senior";
	case expert:
		return "expert";
	case officer:
		return "officer";
	default:
		return "";
	}
}

RankType rank_type_value_of_string(string src) {
	// convert the string, src, in its upper case
	for (string::iterator it = src.begin(); it != src.end(); it++) {
		*it = tolower(*it);
	}

	if (src == "assistant") {
		return assistant;
	}

	if (src == "senior") {
		return senior;
	}

	if (src == "expert") {
		return expert;
	}

	if (src == "officer") {
		return officer;
	}

	throw invalid_argument("Unknown Rank Type : " + src);
}

