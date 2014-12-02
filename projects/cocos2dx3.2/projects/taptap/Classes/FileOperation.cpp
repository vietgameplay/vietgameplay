// to enable CCLOG()
#define COCOS2D_DEBUG 1

#include "Defines.h"

extern Languages s_language;
extern int s_bestScore;

void FileOperation::saveFile()
{
    std::string fullFilePath = FileUtils::getInstance()->getWritablePath() + "rms.json";

    if (!FileUtils::getInstance()->isFileExist(fullFilePath))
    {
        ofstream ofile;
        ofile.open(fullFilePath.c_str());
        ofile << "0";
        ofile << "0 ";
        ofile.close();
        log("----file is not exist, we have to create new one");
    }
    else
    {
        FILE *fp = fopen(fullFilePath.c_str(), "w");
        fprintf( fp, "%d ", (int)s_language );
        fprintf( fp, "%d ", s_bestScore );
        fclose( fp );
    }
    log("-----------path%s", fullFilePath.c_str());
}

void FileOperation::readFile()
{
    std::string fullFilePath = FileUtils::getInstance()->getWritablePath() + "rms.json";
	FILE *fp = fopen(fullFilePath.c_str(), "r");
	char buf[50] = {0};

	if (! fp)
	{
		//if null -> init save
		saveFile();
		return;
	}

	fgets(buf, 50, fp);
	CCLOG("----read content %s", buf);
	int lang;
	sscanf( buf, "%d %d", &lang, &s_bestScore );
    CCLOG("---read content %s", buf);
	s_language = (Languages)lang;
	fclose(fp);
}

string FileOperation::getFilePath()
{
	string path("");

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	// In android, every programe has a director under /data/data.
	// The path is /data/data/ + start activity package name.
	// You can save application specific data here.
	path.append("D:/tmpfile");
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
