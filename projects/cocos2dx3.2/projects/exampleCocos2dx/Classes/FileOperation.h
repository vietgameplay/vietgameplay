#ifndef _FILE_OPERATION_H_
#define _FILE_OPERTIONN_H_

#include <string>

class FileOperation 
{
public:
	static void saveFile(void);
	static void readFile(void);
	static std::string getFilePath();
};

#endif
