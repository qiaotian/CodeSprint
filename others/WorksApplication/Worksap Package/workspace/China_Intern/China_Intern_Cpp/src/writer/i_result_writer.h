#ifndef I_RESULT_WRITER_H_
#define I_RESULT_WRITER_H_

#include <vector>
#include <string>
using namespace std;

class IResultWriter {
public:
	virtual void write_result(vector<vector<string> > result) = 0;
	virtual ~IResultWriter() = 0;
};

#endif /* I_RESULT_WRITER_H_ */
