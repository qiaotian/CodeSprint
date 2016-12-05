#ifndef RANK_TYPE_H_
#define RANK_TYPE_H_

#include <string>
using namespace std;

enum RankType {
	assistant, senior, expert, officer
};

string rank_type_to_string(RankType type);
RankType rank_type_value_of_string(string src);



#endif /* RANK_TYPE_H_ */
