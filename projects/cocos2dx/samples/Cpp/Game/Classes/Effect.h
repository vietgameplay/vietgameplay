#ifndef __EFFECT_H__
#define __EFFECT_H__
#include "Particles.h"
#include "cocos2d.h"

using namespace cocos2d;
enum EffectEnum 
{
	EFFECT_NONE = 0,
	EFFECT_FLOWER,
	EFFECT_FIRE,
	EFFECT_FIREWORKS,
	EFFECT_SUN,
	EFFECT_GALAXY,
	EFFECT_METEOR,
	EFFECT_SPIRAL,
	EFFECT_EXPLOSION,
	EFFECT_SMOKE,
	EFFECT_SNOW,
	EFFECT_RAIN,
	EFFECT_JET,
	EFFECT_RAINBOW,
	EFFECT_BIGFLOWER
};

namespace VGP
{
class Effect
{
public:
	cocos2d::CCPoint	position; //position of effect
	cocos2d::CCSize	size;	  //size of object
public:
	CCParticleSystem* emitter;
	char* str;
	Effect();
	~Effect();
	void init(CCLayer* layer, EffectEnum effectId);
	void update();
	void setPosition(int x, int y);
	void stop();
	void start(CCPoint srcPosition, CCPoint desPosition, float duration);
	void moveTo(float duration, CCPoint toPosition);
};
}
#endif