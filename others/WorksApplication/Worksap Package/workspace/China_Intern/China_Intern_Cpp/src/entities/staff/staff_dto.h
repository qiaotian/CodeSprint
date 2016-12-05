#ifndef STAFF_DTO_H_
#define STAFF_DTO_H_

#include "../icsv_master_dto.h"
#include "position_type.h"
#include "rank_type.h"
#include <string>
using namespace std;

class StaffDTO: public ICsvMasterDTO {
public:
	StaffDTO(long staff_id, string name, string gender, RankType rank,
			PositionType position, long supermarket_id);
	long &get_staff_id();
	string &get_name();
	string &get_gender();
	RankType &get_rank();
	PositionType &get_position();
	long &get_supermarket_id();
	friend ostream &operator <<(ostream &out, StaffDTO &obj);
	friend istream &operator >>(istream &in, StaffDTO &obj);

private:
	long staff_id;
	string name;
	string gender;
	RankType rank;
	PositionType position;
	long supermarket_id;
};

#endif /* STAFF_DTO_H_ */
