#ifndef SUPERMARKET_DTO_H_
#define SUPERMARKET_DTO_H_

#include "../icsv_master_dto.h"
#include <string>
using namespace std;

class SupermarketMstDTO: public ICsvMasterDTO {
public:
	SupermarketMstDTO(long supermarket_id, string supermarket_name, string address, string tel);
	long &get_supermarket_id();
	string &get_supermarket_name();
	string &get_address();
	string &get_tel();

	friend ostream &operator <<(ostream &out, SupermarketMstDTO &obj);
	friend istream &operator >>(istream &in, SupermarketMstDTO &obj);

private:
	long supermarket_id;
	string supermarket_name;
	string address;
	string tel;
};

#endif /* SUPERMARKET_DTO_H_ */
