#ifndef POSITION_TYPE_H_
#define POSITION_TYPE_H_

#include <string>
using namespace std;

enum PositionType {
	staff, manager, region_manager
};

string position_type_to_string(PositionType type);
PositionType position_type_value_of_string(string src);



#endif /* POSITION_TYPE_H_ */
