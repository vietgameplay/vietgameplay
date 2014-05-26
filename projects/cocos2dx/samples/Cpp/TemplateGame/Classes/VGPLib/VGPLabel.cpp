#include "VGPLib.h"

using namespace cocos2d;

VGPLabel* VGPLabel::instance;

extern int s_language;

VGPLabel* VGPLabel::getInstance()
{
	if ( instance == NULL )
		instance = new VGPLabel();
	return instance;
}

cocos2d::CCLabelTTF* VGPLabel::createLabel( char *strName, char* fontName, float fontSize,
								cocos2d::CCSize dimensions, cocos2d::CCPoint position, 
								cocos2d::CCTextAlignment hAlignment, cocos2d::CCVerticalTextAlignment vAlignment, int zOrder, int tag )
{
	CCLabelTTF* label = CCLabelTTF::create( strName, fontName, fontSize, dimensions,  hAlignment, vAlignment );
	label->setPosition( position ); 
	label->setZOrder( zOrder );
	label->setTag( tag );
	return label;
}

cocos2d::CCLabelTTF* VGPLabel::createLabel( char *strName, char* fontName, float fontSize,
								cocos2d::CCSize dimensions, cocos2d::CCPoint position, 
								cocos2d::CCTextAlignment hAlignment, cocos2d::CCVerticalTextAlignment vAlignment, int zOrder )
{
	return createLabel( strName, fontName, fontSize, dimensions, position, hAlignment, vAlignment, zOrder, -1 );
}

cocos2d::CCLabelTTF* VGPLabel::createLabel( char *strName, char* fontName, float fontSize,
								cocos2d::CCSize dimensions, cocos2d::CCPoint position, 
								cocos2d::CCTextAlignment hAlignment, cocos2d::CCVerticalTextAlignment vAlignment )
{
	return createLabel( strName, fontName, fontSize, dimensions, position, hAlignment, vAlignment, 0 );
}

cocos2d::CCLabelTTF* VGPLabel::createLabel( char *strName, char *fontName, float fontSize,
								cocos2d::CCSize dimensions, cocos2d::CCPoint position, cocos2d::CCTextAlignment hAlignment )
{
	return createLabel( strName, fontName, fontSize, dimensions, position, hAlignment, kCCVerticalTextAlignmentTop );
}

 cocos2d::CCLabelTTF* VGPLabel::createLabel( char *strName, char *fontName, float fontSize, cocos2d::CCPoint position )
 {
	 return createLabel( strName, fontName, fontSize, CCSize( 0, 0 ), position, kCCTextAlignmentCenter, kCCVerticalTextAlignmentTop );
 }

void VGPLabel::addLabel( cocos2d::CCLayer* layer, char *strName, char* fontName, float fontSize,
								CCSize dimensions, CCPoint position, CCTextAlignment hAlignment, CCVerticalTextAlignment vAlignment, int zOrder, int tag )
{
	CCLabelTTF* label = createLabel( strName, fontName, fontSize, dimensions, position, hAlignment, vAlignment, zOrder, tag );
   	layer->addChild( label );
}

void VGPLabel::addLabel( cocos2d::CCLayer* layer, char *strName, char* fontName, float fontSize,
								CCSize dimensions, CCPoint position, CCTextAlignment hAlignment, CCVerticalTextAlignment vAlignment, int zOrder )
{
	addLabel( layer, strName, fontName,  fontSize, dimensions, position, hAlignment, vAlignment, zOrder, -1 );
}

void VGPLabel::addLabel( cocos2d::CCLayer* layer, char *strName, char* fontName, float fontSize,
								CCSize dimensions, CCPoint position, CCTextAlignment hAlignment, CCVerticalTextAlignment vAlignment )
{
	addLabel( layer, strName, fontName,  fontSize, dimensions, position, hAlignment, vAlignment, 0, -1 );
}

void VGPLabel::addLabel( cocos2d::CCLayer* layer, char *strName, char *fontName, float fontSize,
                               CCSize dimensions, CCPoint position, CCTextAlignment hAlignment )
{	
	addLabel( layer, strName, fontName, fontSize, dimensions, position, hAlignment, kCCVerticalTextAlignmentTop );
}

void VGPLabel::addLabel( cocos2d::CCLayer* layer, char *strName, char *fontName, float fontSize, CCPoint position )
{
	addLabel( layer, strName, fontName, fontSize, CCSize( 0, 0 ), position, kCCTextAlignmentCenter );
}

//bit map font 
CCLabelBMFont* VGPLabel::createLabelBMFont( char *strName, char* fntFile, float width, cocos2d::CCPoint position, CCTextAlignment alignment, CCPoint imageOffset, int zOrder, int tag )
{
	CCLabelBMFont *label = CCLabelBMFont::create( strName, fntFile, width, alignment, imageOffset);
	label->setPosition( position ); 
	label->setZOrder( zOrder );
	label->setTag( tag );
	return label;
}

CCLabelBMFont* VGPLabel::createLabelBMFont( char *strName, char* fntFile, float width, cocos2d::CCPoint position, CCTextAlignment alignment, CCPoint imageOffset, int zOrder )
{
	return createLabelBMFont( strName, fntFile, width, position, alignment, imageOffset, zOrder, -1 );
}

CCLabelBMFont* VGPLabel::createLabelBMFont( char *strName, char* fntFile, float width, cocos2d::CCPoint position, CCTextAlignment alignment, CCPoint imageOffset )
{
	return createLabelBMFont( strName,  fntFile, width, position, alignment, imageOffset, 0 );
}

cocos2d::CCLabelBMFont* VGPLabel::createLabelBMFont( char *strName, char* fntFile, float width, cocos2d::CCPoint position, cocos2d::CCTextAlignment alignment )
{
	return createLabelBMFont( strName,  fntFile, width, position, alignment, CCPoint( 0, 0 ), 0 );
}

cocos2d::CCLabelBMFont* VGPLabel::createLabelBMFont( char *strName, char* fntFile, float width, cocos2d::CCPoint position )
{
	return createLabelBMFont( strName,  fntFile, width, position,  kCCTextAlignmentLeft, CCPoint( 0, 0 ), 0 );
}

cocos2d::CCLabelBMFont* VGPLabel::createLabelBMFont( char *strName, char* fntFile, cocos2d::CCPoint position )
{
	return createLabelBMFont( strName,  fntFile, kCCLabelAutomaticWidth, position,  kCCTextAlignmentLeft, CCPoint( 0, 0 ), 0 );
}

void VGPLabel::addLabelBMFont( cocos2d::CCLayer* layer, char *strName, char* fntFile, float width, cocos2d::CCPoint position, cocos2d::CCTextAlignment alignment, cocos2d::CCPoint imageOffset, int zOrder, int tag )
{
	CCLabelBMFont* label = createLabelBMFont( strName, fntFile, width, position, alignment, imageOffset, zOrder, tag );
	layer->addChild( label );
}

void VGPLabel::addLabelBMFont( cocos2d::CCLayer* layer, char *strName, char* fntFile, float width, cocos2d::CCPoint position, cocos2d::CCTextAlignment alignment, cocos2d::CCPoint imageOffset, int zOrder )
{
	addLabelBMFont( layer, strName, fntFile, width, position, alignment, imageOffset, zOrder, -1 );
}

void VGPLabel::addLabelBMFont( cocos2d::CCLayer* layer, char *strName, char* fntFile, float width, cocos2d::CCPoint position, cocos2d::CCTextAlignment alignment, cocos2d::CCPoint imageOffset )
{
	addLabelBMFont( layer, strName, fntFile, width, position, alignment, imageOffset, 0 );
}

void VGPLabel::addLabelBMFont( cocos2d::CCLayer* layer, char *strName, char* fntFile, float width, cocos2d::CCPoint position, cocos2d::CCTextAlignment alignment )
{
	addLabelBMFont( layer, strName, fntFile, width, position, alignment, CCPoint( 0, 0 ), 0 );
}

void VGPLabel::addLabelBMFont( cocos2d::CCLayer* layer, char *strName, char* fntFile, float width, cocos2d::CCPoint position )
{
	addLabelBMFont( layer, strName, fntFile, width, position, kCCTextAlignmentLeft, CCPoint( 0, 0 ), 0 );
}

void VGPLabel::addLabelBMFont( cocos2d::CCLayer* layer, char *strName, char* fntFile, cocos2d::CCPoint position )
{
	addLabelBMFont( layer, strName, fntFile, kCCLabelAutomaticWidth, position, kCCTextAlignmentLeft, CCPoint( 0, 0 ), 0 );
}
