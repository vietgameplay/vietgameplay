#ifndef _FILE_OPERATION_H_
#define _FILE_OPERTIONN_H_
//nguyenvietvu.it@gmail.com/14285700

#include "cocos2d.h"
#include <iostream>
#include <fstream>
#include <istream>
#include <string>

class FileOperation 
{
public:
	static void saveFile(void);
	static void readFile(void);
	static std::string getFilePath();
};

#endif
