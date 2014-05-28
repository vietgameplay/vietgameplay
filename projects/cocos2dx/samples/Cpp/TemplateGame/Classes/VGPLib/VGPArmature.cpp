#include "VGPLib.h"

VGPArmature* VGPArmature::instance;

VGPArmature* VGPArmature::getInstance()
{
	if ( instance == NULL )
		instance = new VGPArmature();
	return instance;
}

CCArmature* VGPArmature::createAnimation( const char *name, int playIndex, CCPoint position, int zOrder, int tag )
{
	CCArmature *armature = CCArmature::create( name );
	armature->setPosition( position );
	armature->setZOrder( zOrder );
	armature->setTag( tag );
	armature->getAnimation()->playByIndex( playIndex );
	return armature;
}

CCArmature* VGPArmature::createAnimation( const char *name, int playIndex, CCPoint position, int zOrder )
{
	return createAnimation( name, playIndex, position, zOrder, -1 );
}

CCArmature* VGPArmature::createAnimation( const char *name, int playIndex, CCPoint position )
{
	return createAnimation( name, playIndex, position, 0, -1 );
}


void VGPArmature::addAnimation( CCLayer *layer, const char *name, int playIndex, CCPoint position, int zOrder, int tag )
{
	layer->addChild( createAnimation( name, playIndex, position, zOrder, tag ) );
}

void VGPArmature::addAnimation( CCLayer *layer, const char *name, int playIndex, CCPoint position, int zOrder )
{
	layer->addChild( createAnimation( name, playIndex, position, zOrder, -1 ) );
}

void VGPArmature::addAnimation( CCLayer *layer, const char *name, int playIndex, CCPoint position )
{
	layer->addChild( createAnimation( name, playIndex, position, 0, -1 ) );
}


