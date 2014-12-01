// to enable CCLOG()
#define COCOS2D_DEBUG 1

#include "Defines.h"

extern Languages s_language;
extern int s_bestScore;

void FileOperation::saveFile()
{
	string path = getFilePath();
	FILE *fp = fopen(path.c_str(), "w");

	if (! fp)
	{
		CCLOG("can not create file %s", path.c_str());
		return;
	}
	fprintf( fp, "%d ", (int)s_language );
	fprintf( fp, "%d ", s_bestScore );
	//fputs("file example", fp);
	fclose(fp);
}

void FileOperation::readFile()
{
	string path = getFilePath();
	FILE *fp = fopen(path.c_str(), "r");
	char buf[50] = {0};

	if (! fp)
	{
		//if null -> init save
		saveFile();
		return;
	}

	fgets(buf, 50, fp);
	//CCLOG("read content %s", buf);
	int lang;
	sscanf( buf, "%d" "%d", &lang, &s_bestScore );
	//s_language = (Languages)lang;
	fclose(fp); 
}

string FileOperation::getFilePath()
{
	string path("");

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	// In android, every programe has a director under /data/data.
	// The path is /data/data/ + start activity package name.
	// You can save application specific data here.
	path.append(SAVE_PATH);
#endif

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	// You can save file in anywhere if you have the permision.
	path.append("D:/tmpfile");
#endif

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WOPHONE)
	path = cocos2d::CCApplication::sharedApplication().getAppDataPath();

#ifdef _TRANZDA_VM_
	// If runs on WoPhone simulator, you should insert "D:/Work7" at the
	// begin. We will fix the bug in no far future.
	path = "D:/Work7" + path;
	path.append("tmpfile");
#endif

#endif

	return path;
}