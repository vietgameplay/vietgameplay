#ifndef _VGPLABEL_H_
#define _VGPLABEL_H_

#include "cocos2d.h"

using namespace cocos2d;

class VGPLabel
{
protected:
	static VGPLabel* instance;

public:
	static VGPLabel* getInstance();	

	CCLabelTTF* createLabel( char *strName, char* fontName, float fontSize,	CCSize dimensions, CCPoint position, CCTextAlignment hAlignment, CCVerticalTextAlignment vAlignment, int zOrder, int tag );

	CCLabelTTF* createLabel( char *strName, char* fontName, float fontSize, CCSize dimensions, CCPoint position, CCTextAlignment hAlignment, CCVerticalTextAlignment vAlignment, int zOrder );

	CCLabelTTF* createLabel( char *strName, char* fontName, float fontSize, CCSize dimensions, CCPoint position, CCTextAlignment hAlignment, CCVerticalTextAlignment vAlignment );

	CCLabelTTF* createLabel( char *strName, char *fontName, float fontSize, CCSize dimensions, CCPoint position, CCTextAlignment hAlignment );

	CCLabelTTF* createLabel( char *strName, char *fontName, float fontSize, CCPoint position );

	void addLabel( CCLayer* layer, char *strName, char* fontName, float fontSize, CCSize dimensions, CCPoint position, CCTextAlignment hAlignment, CCVerticalTextAlignment vAlignment, int zOrder, int tag );

	void addLabel( CCLayer* layer, char *strName, char* fontName, float fontSize, CCSize dimensions, CCPoint position, CCTextAlignment hAlignment, CCVerticalTextAlignment vAlignment, int zOrder );

	void addLabel( CCLayer* layer, char *strName, char* fontName, float fontSize, CCSize dimensions, CCPoint position, CCTextAlignment hAlignment, CCVerticalTextAlignment vAlignment );

	void addLabel( CCLayer* layer, char *strName, char *fontName, float fontSize, CCSize dimensions, CCPoint position, CCTextAlignment hAlignment );

	void addLabel( CCLayer* layer, char *strName, char *fontName, float fontSize, CCPoint position );

	CCLabelBMFont* createLabelBMFont( char *strName, char* fntFile, float width, CCPoint position, CCTextAlignment alignment, CCPoint imageOffset, int zOrder, int tag );

	CCLabelBMFont* createLabelBMFont( char *strName, char* fntFile, float width, CCPoint position, CCTextAlignment alignment, CCPoint imageOffset, int zOrder );

	CCLabelBMFont* createLabelBMFont( char *strName, char* fntFile, float width, CCPoint position, CCTextAlignment alignment, CCPoint imageOffset );

	CCLabelBMFont* createLabelBMFont( char *strName, char* fntFile, float width, CCPoint position, CCTextAlignment alignment );

	CCLabelBMFont* createLabelBMFont( char *strName, char* fntFile, float width, CCPoint position );

	CCLabelBMFont* createLabelBMFont( char *strName, char* fntFile, CCPoint position );

	void addLabelBMFont( CCLayer* layer, char *strName, char* fntFile, float width, CCPoint position, CCTextAlignment alignment, CCPoint imageOffset, int zOrder, int tag );

	void addLabelBMFont( CCLayer* layer, char *strName, char* fntFile, float width, CCPoint position, CCTextAlignment alignment, CCPoint imageOffset, int zOrder );

	void addLabelBMFont( CCLayer* layer, char *strName, char* fntFile, float width, CCPoint position, CCTextAlignment alignment, CCPoint imageOffset );

	void addLabelBMFont( CCLayer* layer, char *strName, char* fntFile, float width, CCPoint position, CCTextAlignment alignment );

	void addLabelBMFont( CCLayer* layer, char *strName, char* fntFile, float width, CCPoint position );

	void addLabelBMFont( CCLayer* layer, char *strName, char* fntFile, CCPoint position );
};


#endif