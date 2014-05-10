#include "Effect.h"
//#include "Particles.h"
using namespace cocos2d;
namespace VGP
{
const char* cEffectImages[] = 
{
	"images/dummy.png", 
	"images/stars.png", 
	"images/fire.png",
	"images/stars.png",
	"images/fire.png",
	"images/fire.png",
	"images/fire.png",
	"images/fire.png",
	"images/stars1.png",
	"images/snow.png",
	"images/snow.png",
	"images/snow.png",
	"images/fire.png",
	"images/particles.png",
	"images/stars1.png"
};
Effect::Effect()
{

}
Effect::~Effect()
{
}
void Effect::init(CCLayer* layer, EffectEnum effectId)
{
	switch(effectId)
	{
	case EFFECT_NONE :
		{
			break;
		}
	case EFFECT_FLOWER :
		{
			this->emitter = VGP::ParticleFlower::create(this->position);
			break;
		}
	case EFFECT_FIRE :
		{
			this->emitter = VGP::ParticleFire::create(this->position);
			break;
		}
	case EFFECT_FIREWORKS :
		{
			this->emitter = VGP::ParticleFireworks::create();
			break;
		}
	case EFFECT_SUN :
		{
			this->emitter = VGP::ParticleSun::create();
			break;
		}
		case EFFECT_GALAXY :
		{
			this->emitter = VGP::ParticleGalaxy::create();
			break;
		}
	case EFFECT_METEOR :
		{
			this->emitter = VGP::ParticleMeteor::create();
			break;
		}
		case EFFECT_SPIRAL :
		{
			this->emitter = VGP::ParticleSpiral::create();
			break;
		}
	case EFFECT_EXPLOSION :
		{
			this->emitter = VGP::ParticleExplosion::create();
			break;
		}
	case EFFECT_SMOKE :
		{
			this->emitter = VGP::ParticleSmoke::create();
			break;
		}
	case EFFECT_SNOW :
		{
			this->emitter = VGP::ParticleSnow::create();
			break;
		}
	case EFFECT_RAIN :
		{
			this->emitter = VGP::ParticleRain::create();
			break;
		}
	case  EFFECT_JET :
		{
			this->emitter = VGP::ParticleJet::create(this->position);
			break;
		}
	case EFFECT_RAINBOW :
		{
			this->emitter = VGP::ParticleRainbow::create(this->position);
			break;
		}
	case EFFECT_BIGFLOWER :
		{
			this->emitter = VGP::ParticleBigFlower::create(this->position);
			break;
		}
	}

	this->emitter->retain();
	this->emitter->setTexture( CCTextureCache::sharedTextureCache()->addImage(cEffectImages[effectId]) );
	layer->addChild(emitter, 100);
	this->emitter->stopSystem();
}
void Effect::update()
{

}

void Effect::setPosition(int x, int y)
{
	position.x = x;
	position.y = y;
    if (emitter != NULL)
    {
		emitter->setPosition( x, y);
    }
}

void Effect::moveTo( float duration, CCPoint toPosition)
{
    if (emitter != NULL)
    {
		emitter->runAction( cocos2d::CCMoveTo::create(duration, toPosition));
    }
}
//reset effect
void Effect::start( CCPoint srcPosition, CCPoint desPosition, float duration)
{
	if (emitter != NULL)
    {
		emitter->setDuration(duration);
		emitter->setPosition(srcPosition);
		emitter->resetSystem();
		if(srcPosition.x != desPosition.x && srcPosition.y != desPosition.y)
		{
			emitter->runAction( cocos2d::CCMoveTo::create(duration, desPosition));
		}
		position = desPosition;
		size.width = 20;
		size.height = 20;
	}
}
//stop effect
void Effect::stop()
{
	if (emitter != NULL)
    {
		emitter->stopSystem();
	}
}

}