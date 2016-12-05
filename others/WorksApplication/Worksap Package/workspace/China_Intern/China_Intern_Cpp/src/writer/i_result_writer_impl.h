#ifndef I_RESULT_WRITER_IMPL_H_
#define I_RESULT_WRITER_IMPL_H_

#include "i_result_writer.h"
#include <vector>
#include <string>
using namespace std;

class IResultWriterImpl: public IResultWriter {
public:
	IResultWriterImpl();
	IResultWriterImpl(string &file_address);
	void write_result(vector<vector<string> > result);
	~IResultWriterImpl();

private:
	static const string DEFAULT_OUTPUT_FILE_NAME;
	string out_file_path;
};

#endif /* I_RESULT_WRITER_IMPL_H_ */
