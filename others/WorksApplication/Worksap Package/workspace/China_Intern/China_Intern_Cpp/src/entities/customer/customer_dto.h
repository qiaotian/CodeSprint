#ifndef CUSTOMER_DTO_H_
#define CUSTOMER_DTO_H_

#include <string>
#include <iostream>
#include "../icsv_master_dto.h"
using namespace std;

class CustomerDTO: public ICsvMasterDTO {
public:
	CustomerDTO(long customer_id, string name, string gender, string tel);
	long &get_customer_id();
	string &get_name();
	string &get_gender();
	string &get_tel();
	friend ostream &operator <<(ostream &out, CustomerDTO &obj);
	friend istream &operator >>(istream &in, CustomerDTO &obj);

private:
	long customer_id;
	string name;
	string gender;
	string tel;
};

#endif /* CUSTOMER_DTO_H_ */
