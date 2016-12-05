#ifndef REGION_MST_DTO_H_
#define REGION_MST_DTO_H_

#include "../icsv_master_dto.h"
#include <string>
using namespace std;

class RegionMstDTO: public ICsvMasterDTO {
public:
	RegionMstDTO(long region_id, string name, long manager_id);
	long &get_region_id();
	string &get_name();
	long &get_manager_id();
	friend ostream &operator <<(ostream &out, RegionMstDTO &obj);
	friend istream &operator >>(istream &in, RegionMstDTO &obj);

private:
	long region_id;
	string name;
	long manager_id;
};

#endif /* REGION_MST_DTO_H_ */
