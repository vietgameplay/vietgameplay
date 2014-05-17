#include "Particles.h"
#include "CCDirector.h"
#include "textures/CCTextureCache.h"
#include "particle_nodes/firePngData.h"
#include "platform/CCImage.h"

using namespace cocos2d;
namespace VGP
{

//
// ParticleFire
//

enum 
{
    kCCParticleModeGravity,
    kCCParticleModeRadius,    
};
static CCTexture2D* getDefaultTexture()
{
    CCTexture2D* texture = NULL;
    CCImage* pImage = NULL;
    do 
    {
        bool bRet = false;
        const char* key = "__firePngData";
		texture = CCTextureCache::sharedTextureCache()->textureForKey(key);
        CC_BREAK_IF(texture != NULL);

        pImage = new CCImage();
        CC_BREAK_IF(NULL == pImage);
        bRet = pImage->initWithImageData((void*)__firePngData, sizeof(__firePngData), CCImage::kFmtPng);
        CC_BREAK_IF(!bRet);

        texture = CCTextureCache::sharedTextureCache()->addUIImage(pImage, key);
    } while (0);

    CC_SAFE_RELEASE(pImage);

    return texture;
}

ParticleJet* ParticleJet::create(CCPoint position)
{
    ParticleJet* pRet = new ParticleJet();
    if (pRet && pRet->init(position))
    {
        pRet->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(pRet);
    }
    return pRet;
}

ParticleJet* ParticleJet::createWithTotalParticles(unsigned int numberOfParticles, CCPoint position)
{
    ParticleJet* pRet = new ParticleJet();
    if (pRet && pRet->initWithTotalParticles(numberOfParticles, position))
    {
        pRet->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(pRet);
    }
    return pRet;
}

bool ParticleJet::initWithTotalParticles(unsigned int numberOfParticles, CCPoint position)
{
	
    if( CCParticleSystemQuad::initWithTotalParticles(numberOfParticles) )
    {
        // duration
        setDuration(0.6f);
		//_autoRemoveOnFinish = true;
        // Gravity Mode
        setEmitterMode(kCCParticleModeGravity);

        // Gravity Mode: gravity
        modeA.gravity = CCPoint(0,-30);

        // Gravity Mode: radial acceleration
        modeA.radialAccel = 0;
        modeA.radialAccelVar = 0;

        // Gravity Mode: speed of particles
        modeA.speed = 360;
        modeA.speedVar = 50;        

        // starting angle
        m_fAngle = 270;
        m_fAngleVar = 10;

        // emitter position
        setPosition(position);
		m_tPosVar = CCPoint(40, 20);

        // life of particles
        m_fLife = 0.75f;
        m_fLifeVar = 1.0f;


        // CCSize, in pixels
        m_fStartSize = 8.0f;
        m_fStartSizeVar = 2.0f;
        setEndSize(kCCParticleStartSizeEqualToEndSize);

        // emits per frame
        setEmissionRate(getTotalParticles()/getLife());

        // color of particles
        m_tStartColor.r = 0.76f;
        m_tStartColor.g = 0.25f;
        m_tStartColor.b = 0.12f;
        m_tStartColor.a = 1.0f;
        m_tStartColorVar.r = 0.0f;
        m_tStartColorVar.g = 0.0f;
        m_tStartColorVar.b = 0.0f;
        m_tStartColorVar.a = 0.0f;
        m_tEndColor.r = 0.0f;
        m_tEndColor.g = 0.0f;
        m_tEndColor.b = 0.0f;
        m_tEndColor.a = 1.0f;
        m_tEndColorVar.r = 0.0f;
        m_tEndColorVar.g = 0.0f;
        m_tEndColorVar.b = 0.0f;
        m_tEndColorVar.a = 0.0f;

        CCTexture2D* texture = getDefaultTexture();
        if (texture != NULL)
        {
            setTexture(texture);
        }
        
        // additive
        setBlendAdditive(true);
        return true;
    }
	
    return false;
}

ParticleFire* ParticleFire::create(CCPoint position)
{
    ParticleFire* pRet = new ParticleFire();
    if (pRet && pRet->init(position))
    {
        pRet->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(pRet);
    }
    return pRet;
}

ParticleFire* ParticleFire::createWithTotalParticles(unsigned int numberOfParticles, CCPoint position)
{
    ParticleFire* pRet = new ParticleFire();
    if (pRet && pRet->initWithTotalParticles(numberOfParticles, position))
    {
        pRet->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(pRet);
    }
    return pRet;
}

bool ParticleFire::initWithTotalParticles(unsigned int numberOfParticles, CCPoint position)
{
	
    if( CCParticleSystemQuad::initWithTotalParticles(numberOfParticles) )
    {
        // duration
        setDuration(0.6f);

        // Gravity Mode
        setEmitterMode(kCCParticleModeGravity);

        // Gravity Mode: gravity
        modeA.gravity = CCPoint(0,0);

        // Gravity Mode: radial acceleration
        modeA.radialAccel = 0;
        modeA.radialAccelVar = 0;

        // Gravity Mode: speed of particles
        modeA.speed = 60;
        modeA.speedVar = 20;        

        // starting angle
        m_fAngle = 0;
        m_fAngleVar = 10;

        // emitter position
        setPosition(position);
        m_tPosVar = CCPoint(40, 20);

        // life of particles
        m_fLife = 3;
        m_fLifeVar = 0.25f;


        // CCSize, in pixels
        m_fStartSize = 54.0f;
        m_fStartSizeVar = 10.0f;
        setEndSize(kCCParticleStartSizeEqualToEndSize);

        // emits per frame
        setEmissionRate(getTotalParticles()/getLife());

        // color of particles
        m_tStartColor.r = 0.76f;
        m_tStartColor.g = 0.25f;
        m_tStartColor.b = 0.12f;
        m_tStartColor.a = 1.0f;
        m_tStartColorVar.r = 0.0f;
        m_tStartColorVar.g = 0.0f;
        m_tStartColorVar.b = 0.0f;
        m_tStartColorVar.a = 0.0f;
        m_tEndColor.r = 0.0f;
        m_tEndColor.g = 0.0f;
        m_tEndColor.b = 0.0f;
        m_tEndColor.a = 1.0f;
        m_tEndColorVar.r = 0.0f;
        m_tEndColorVar.g = 0.0f;
        m_tEndColorVar.b = 0.0f;
        m_tEndColorVar.a = 0.0f;

        CCTexture2D* texture = getDefaultTexture();
        if (texture != NULL)
        {
            setTexture(texture);
        }
        
        // additive
        setBlendAdditive(true);
        return true;
    }
	
    return false;
}
//
// ParticleFireworks
//

ParticleFireworks* ParticleFireworks::create()
{
    ParticleFireworks* pRet = new ParticleFireworks();
    if (pRet && pRet->init())
    {
        pRet->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(pRet);
    }
    return pRet;
}

ParticleFireworks* ParticleFireworks::createWithTotalParticles(unsigned int numberOfParticles)
{
    ParticleFireworks* pRet = new ParticleFireworks();
    if (pRet && pRet->initWithTotalParticles(numberOfParticles))
    {
        pRet->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(pRet);
    }
    return pRet;
}

bool ParticleFireworks::initWithTotalParticles(unsigned int numberOfParticles)
{
	
    if( CCParticleSystemQuad::initWithTotalParticles(numberOfParticles) )
    {
        // duration
       setDuration(-1);

        // Gravity Mode
        setEmitterMode(kCCParticleModeGravity);

        // Gravity Mode: gravity
        modeA.gravity = CCPoint(0,-90);

        // Gravity Mode:  radial
        modeA.radialAccel = 0;
        modeA.radialAccelVar = 0;

        //  Gravity Mode: speed of particles
        modeA.speed = 180;
        modeA.speedVar = 50;

        // emitter position
        CCSize winSize = CCDirector::sharedDirector()->getWinSize();
        setPosition(CCPoint(winSize.width/2, winSize.height/2));

        // angle
        m_fAngle= 90;
        m_fAngleVar = 20;

        // life of particles
        m_fLife = 3.5f;
        m_fLifeVar = 1;

        // emits per frame
        setEmissionRate(getTotalParticles()/getLife());

        // color of particles
        m_tStartColor.r = 0.5f;
        m_tStartColor.g = 0.5f;
        m_tStartColor.b = 0.5f;
        m_tStartColor.a = 1.0f;
        m_tStartColorVar.r = 0.5f;
        m_tStartColorVar.g = 0.5f;
        m_tStartColorVar.b = 0.5f;
        m_tStartColorVar.a = 0.1f;
        m_tEndColor.r = 0.1f;
        m_tEndColor.g = 0.1f;
        m_tEndColor.b = 0.1f;
        m_tEndColor.a = 0.2f;
        m_tEndColorVar.r = 0.1f;
        m_tEndColorVar.g = 0.1f;
        m_tEndColorVar.b = 0.1f;
        m_tEndColorVar.a = 0.2f;

        // CCSize, in pixels
        m_fStartSize = 8.0f;
        m_fStartSizeVar = 2.0f;
        setEndSize(kCCParticleStartSizeEqualToEndSize);

        CCTexture2D* texture = getDefaultTexture();
        if (texture != NULL)
        {
            setTexture(texture);
        }
        // additive
        setBlendAdditive(false);
        return true;
    }
	
    return false;
}
//
// ParticleSun
//
ParticleSun* ParticleSun::create()
{
    ParticleSun* pRet = new ParticleSun();
    if (pRet && pRet->init())
    {
        pRet->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(pRet);
    }
    return pRet;
}

ParticleSun* ParticleSun::createWithTotalParticles(unsigned int numberOfParticles)
{
    ParticleSun* pRet = new ParticleSun();
    if (pRet && pRet->initWithTotalParticles(numberOfParticles))
    {
        pRet->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(pRet);
    }
    return pRet;
}

bool ParticleSun::initWithTotalParticles(unsigned int numberOfParticles)
{
	
    if( CCParticleSystemQuad::initWithTotalParticles(numberOfParticles) )
    {
        // additive
        setBlendAdditive(true);

        // duration
        setDuration(0.6f);

        // Gravity Mode
        setEmitterMode(kCCParticleModeGravity);

        // Gravity Mode: gravity
        setGravity(CCPoint(0,0));

        // Gravity mode: radial acceleration
        setRadialAccel(0);
        setRadialAccelVar(0);

        // Gravity mode: speed of particles
        setSpeed(20);
        setSpeedVar(5);


        // angle
        m_fAngle = 90;
        m_fAngleVar = 360;

        // emitter position
        CCSize winSize = CCDirector::sharedDirector()->getWinSize();
        setPosition(CCPoint(winSize.width/2, winSize.height/2));
        setPosVar(CCPointZero);

        // life of particles
        m_fLife = 1;
        m_fLifeVar = 0.5f;

        // CCSize, in pixels
        m_fStartSize = 30.0f;
        m_fStartSizeVar = 10.0f;
        setEndSize(kCCParticleStartSizeEqualToEndSize);

        // emits per seconds
        setEmissionRate(getTotalParticles()/getLife());

        // color of particles
        m_tStartColor.r = 0.76f;
        m_tStartColor.g = 0.25f;
        m_tStartColor.b = 0.12f;
        m_tStartColor.a = 1.0f;
        m_tStartColorVar.r = 0.0f;
        m_tStartColorVar.g = 0.0f;
        m_tStartColorVar.b = 0.0f;
        m_tStartColorVar.a = 0.0f;
        m_tEndColor.r = 0.0f;
        m_tEndColor.g = 0.0f;
        m_tEndColor.b = 0.0f;
        m_tEndColor.a = 1.0f;
        m_tEndColorVar.r = 0.0f;
        m_tEndColorVar.g = 0.0f;
        m_tEndColorVar.b = 0.0f;
        m_tEndColorVar.a = 0.0f;

        CCTexture2D* texture = getDefaultTexture();
        if (texture != NULL)
        {
            setTexture(texture);
        }

        return true;
    }
	
    return false;
}

//
// ParticleGalaxy
//

ParticleGalaxy* ParticleGalaxy::create()
{
    ParticleGalaxy* pRet = new ParticleGalaxy();
    if (pRet && pRet->init())
    {
        pRet->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(pRet);
    }
    return pRet;
}

ParticleGalaxy* ParticleGalaxy::createWithTotalParticles(unsigned int numberOfParticles)
{
    ParticleGalaxy* pRet = new ParticleGalaxy();
    if (pRet && pRet->initWithTotalParticles(numberOfParticles))
    {
        pRet->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(pRet);
    }
    return pRet;
}

bool ParticleGalaxy::initWithTotalParticles(unsigned int numberOfParticles)
{
	
    if( CCParticleSystemQuad::initWithTotalParticles(numberOfParticles) )
    {
        // duration
        setDuration(0.6f);

        // Gravity Mode
        setEmitterMode(kCCParticleModeGravity);

        // Gravity Mode: gravity
        setGravity(CCPoint(0,0));

        // Gravity Mode: speed of particles
        setSpeed(60);
        setSpeedVar(10);

        // Gravity Mode: radial
        setRadialAccel(-80);
        setRadialAccelVar(0);

        // Gravity Mode: tangential
        setTangentialAccel(80);
        setTangentialAccelVar(0);

        // angle
        m_fAngle = 90;
        m_fAngleVar = 360;

        // emitter position
        CCSize winSize = CCDirector::sharedDirector()->getWinSize();
        setPosition(CCPoint(winSize.width/2, winSize.height/2));
        setPosVar(CCPointZero);

        // life of particles
        m_fLife = 4;
        m_fLifeVar = 1;

        // CCSize, in pixels
        m_fStartSize = 37.0f;
        m_fStartSizeVar = 10.0f;
        setEndSize(kCCParticleStartSizeEqualToEndSize);

        // emits per second
        setEmissionRate(getTotalParticles()/getLife());

        // color of particles
        m_tStartColor.r = 0.12f;
        m_tStartColor.g = 0.25f;
        m_tStartColor.b = 0.76f;
        m_tStartColor.a = 1.0f;
        m_tStartColorVar.r = 0.0f;
        m_tStartColorVar.g = 0.0f;
        m_tStartColorVar.b = 0.0f;
        m_tStartColorVar.a = 0.0f;
        m_tEndColor.r = 0.0f;
        m_tEndColor.g = 0.0f;
        m_tEndColor.b = 0.0f;
        m_tEndColor.a = 1.0f;
        m_tEndColorVar.r = 0.0f;
        m_tEndColorVar.g = 0.0f;
        m_tEndColorVar.b = 0.0f;
        m_tEndColorVar.a = 0.0f;

        CCTexture2D* texture = getDefaultTexture();
        if (texture != NULL)
        {
            setTexture(texture);
        }

        // additive
        setBlendAdditive(true);
        return true;
    }
	
    return false;
}

//
// ParticleFlower
//

ParticleFlower* ParticleFlower::create(CCPoint position)
{
    ParticleFlower* pRet = new ParticleFlower();
    if (pRet && pRet->init(position))
    {
        pRet->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(pRet);
    }
    return pRet;
}

ParticleFlower* ParticleFlower::createWithTotalParticles(unsigned int numberOfParticles, CCPoint position)
{
    ParticleFlower* pRet = new ParticleFlower();
    if (pRet && pRet->initWithTotalParticles(numberOfParticles, position))
    {
        pRet->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(pRet);
    }
    return pRet;
}

bool ParticleFlower::initWithTotalParticles(unsigned int numberOfParticles, CCPoint position)
{
	
    if( CCParticleSystemQuad::initWithTotalParticles(numberOfParticles) )
    {
        // duration
        setDuration(0.6f);

        // Gravity Mode
        setEmitterMode(kCCParticleModeGravity);

        // Gravity Mode: gravity
        setGravity(CCPoint(0,0));

        // Gravity Mode: speed of particles
        setSpeed(80);
        setSpeedVar(10);

        // Gravity Mode: radial
        setRadialAccel(-60);
        setRadialAccelVar(0);

        // Gravity Mode: tangential
        setTangentialAccel(15);
        setTangentialAccelVar(0);

        // angle
        m_fAngle = 90;
        m_fAngleVar = 360;

        // emitter position
        setPosition(position.x, position.y);
        setPosVar(CCPointZero);

        // life of particles
        m_fLife = 1;
        m_fLifeVar = 1;

        // CCSize, in pixels
        m_fStartSize = 30.0f;
        m_fStartSizeVar = 10.0f;
        setEndSize(kCCParticleStartSizeEqualToEndSize);

        // emits per second
        setEmissionRate(getTotalParticles()/getLife());

        // color of particles
        m_tStartColor.r = 0.50f;
        m_tStartColor.g = 0.50f;
        m_tStartColor.b = 0.50f;
        m_tStartColor.a = 1.0f;
        m_tStartColorVar.r = 0.5f;
        m_tStartColorVar.g = 0.5f;
        m_tStartColorVar.b = 0.5f;
        m_tStartColorVar.a = 0.5f;
        m_tEndColor.r = 0.0f;
        m_tEndColor.g = 0.0f;
        m_tEndColor.b = 0.0f;
        m_tEndColor.a = 1.0f;
        m_tEndColorVar.r = 0.0f;
        m_tEndColorVar.g = 0.0f;
        m_tEndColorVar.b = 0.0f;
        m_tEndColorVar.a = 0.0f;

        CCTexture2D* texture = getDefaultTexture();
        if (texture != NULL)
        {
            setTexture(texture);
        }

        // additive
        setBlendAdditive(true);
        return true;
    }
	
    return false;
}
//
// ParticleMeteor
//
ParticleMeteor * ParticleMeteor::create()
{
    ParticleMeteor *pRet = new ParticleMeteor();
    if (pRet && pRet->init())
    {
        pRet->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(pRet);
    }
    return pRet;
}

ParticleMeteor* ParticleMeteor::createWithTotalParticles(unsigned int numberOfParticles)
{
    ParticleMeteor* pRet = new ParticleMeteor();
    if (pRet && pRet->initWithTotalParticles(numberOfParticles))
    {
        pRet->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(pRet);
    }
    return pRet;
}

bool ParticleMeteor::initWithTotalParticles(unsigned int numberOfParticles)
{
	
    if( CCParticleSystemQuad::initWithTotalParticles(numberOfParticles) )
    {
        // duration
		setDuration(0.6f);

        // Gravity Mode
        setEmitterMode(kCCParticleModeGravity);

        // Gravity Mode: gravity
        setGravity(CCPoint(0,0));

        // Gravity Mode: speed of particles
        setSpeed(15);
        setSpeedVar(5);

        // Gravity Mode: radial
        setRadialAccel(0);
        setRadialAccelVar(0);

        // Gravity Mode: tangential
        setTangentialAccel(0);
        setTangentialAccelVar(0);

        // angle
		m_fAngle = 90;
        m_fAngleVar = 360;

        // emitter position
        CCSize winSize = CCDirector::sharedDirector()->getWinSize();
		setPosition(CCPoint(winSize.width/2, winSize.height/2));
        setPosVar(CCPointZero);

        // life of particles
		m_fLife = 2;
        m_fLifeVar = 1;

        // CCSize, in pixels
        m_fStartSize = 60.0f;
        m_fStartSizeVar = 10.0f;
        setEndSize(kCCParticleStartSizeEqualToEndSize);

        // emits per second
        setEmissionRate(getTotalParticles()/getLife());

        // color of particles
        m_tStartColor.r = 0.2f;
        m_tStartColor.g = 0.4f;
        m_tStartColor.b = 0.7f;
        m_tStartColor.a = 1.0f;
        m_tStartColorVar.r = 0.0f;
        m_tStartColorVar.g = 0.0f;
        m_tStartColorVar.b = 0.2f;
        m_tStartColorVar.a = 0.1f;
        m_tEndColor.r = 0.0f;
        m_tEndColor.g = 0.0f;
        m_tEndColor.b = 0.0f;
        m_tEndColor.a = 1.0f;
        m_tEndColorVar.r = 0.0f;
        m_tEndColorVar.g = 0.0f;
        m_tEndColorVar.b = 0.0f;
        m_tEndColorVar.a = 0.0f;

        CCTexture2D* texture = getDefaultTexture();
        if (texture != NULL)
        {
            setTexture(texture);
        }

        // additive
        setBlendAdditive(true);
        return true;
    }
	
    return false;
}

//
// ParticleSpiral
//

ParticleSpiral* ParticleSpiral::create()
{
    ParticleSpiral* pRet = new ParticleSpiral();
    if (pRet && pRet->init())
    {
        pRet->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(pRet);
    }
    return pRet;
}

ParticleSpiral* ParticleSpiral::createWithTotalParticles(unsigned int numberOfParticles)
{
    ParticleSpiral* pRet = new ParticleSpiral();
    if (pRet && pRet->initWithTotalParticles(numberOfParticles))
    {
        pRet->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(pRet);
    }
    return pRet;
}

bool ParticleSpiral::initWithTotalParticles(unsigned int numberOfParticles)
{
	
    if( CCParticleSystemQuad::initWithTotalParticles(numberOfParticles) ) 
    {
        // duration
        setDuration(0.6f);

        // Gravity Mode
        setEmitterMode(kCCParticleModeGravity);

        // Gravity Mode: gravity
        setGravity(CCPoint(0,0));

        // Gravity Mode: speed of particles
        setSpeed(150);
        setSpeedVar(0);

        // Gravity Mode: radial
        setRadialAccel(-380);
        setRadialAccelVar(0);

        // Gravity Mode: tangential
        setTangentialAccel(45);
        setTangentialAccelVar(0);

        // angle
        m_fAngle = 90;
        m_fAngleVar = 0;

        // emitter position
        CCSize winSize = CCDirector::sharedDirector()->getWinSize();
        setPosition(CCPoint(winSize.width/2, winSize.height/2));
        setPosVar(CCPointZero);

        // life of particles
        m_fLife = 12;
        m_fLifeVar = 0;

        // CCSize, in pixels
        m_fStartSize = 20.0f;
        m_fStartSizeVar = 0.0f;
        setEndSize(kCCParticleStartSizeEqualToEndSize);

        // emits per second
        setEmissionRate(getTotalParticles()/getLife());

        // color of particles
        m_tStartColor.r = 0.5f;
        m_tStartColor.g = 0.5f;
        m_tStartColor.b = 0.5f;
        m_tStartColor.a = 1.0f;
        m_tStartColorVar.r = 0.5f;
        m_tStartColorVar.g = 0.5f;
        m_tStartColorVar.b = 0.5f;
        m_tStartColorVar.a = 0.0f;
        m_tEndColor.r = 0.5f;
        m_tEndColor.g = 0.5f;
        m_tEndColor.b = 0.5f;
        m_tEndColor.a = 1.0f;
        m_tEndColorVar.r = 0.5f;
        m_tEndColorVar.g = 0.5f;
        m_tEndColorVar.b = 0.5f;
        m_tEndColorVar.a = 0.0f;

        CCTexture2D* texture = getDefaultTexture();
        if (texture != NULL)
        {
            setTexture(texture);
        }

        // additive
        setBlendAdditive(false);
        return true;
    }
	
    return false;
}

//
// ParticleExplosion
//

ParticleExplosion* ParticleExplosion::create()
{
    ParticleExplosion* pRet = new ParticleExplosion();
    if (pRet && pRet->init())
    {
        pRet->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(pRet);
    }
    return pRet;
}

ParticleExplosion* ParticleExplosion::createWithTotalParticles(unsigned int numberOfParticles)
{
    ParticleExplosion* pRet = new ParticleExplosion();
    if (pRet && pRet->initWithTotalParticles(numberOfParticles))
    {
        pRet->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(pRet);
    }
    return pRet;
}

bool ParticleExplosion::initWithTotalParticles(unsigned int numberOfParticles)
{
	
    if( CCParticleSystemQuad::initWithTotalParticles(numberOfParticles) ) 
    {
        // duration
        setDuration(0.1f);

        setEmitterMode(kCCParticleModeGravity);

        // Gravity Mode: gravity
        setGravity(CCPoint(0,0));

        // Gravity Mode: speed of particles
        setSpeed(70);
        setSpeedVar(40);

        // Gravity Mode: radial
        setRadialAccel(0);
        setRadialAccelVar(0);

        // Gravity Mode: tangential
        setTangentialAccel(0);
        setTangentialAccelVar(0);

        // angle
        m_fAngle = 90;
        m_fAngleVar = 360;

        // emitter position
        CCSize winSize = CCDirector::sharedDirector()->getWinSize();
        setPosition(CCPoint(winSize.width/2, winSize.height/2));
        setPosVar(CCPointZero);

        // life of particles
        m_fLife = 5.0f;
        m_fLifeVar = 2;

        // CCSize, in pixels
        m_fStartSize = 15.0f;
        m_fStartSizeVar = 10.0f;
        setEndSize(kCCParticleStartSizeEqualToEndSize);

        // emits per second
		setEmissionRate(getTotalParticles()/getDuration());

        // color of particles
        m_tStartColor.r = 0.7f;
        m_tStartColor.g = 0.1f;
        m_tStartColor.b = 0.2f;
        m_tStartColor.a = 1.0f;
        m_tStartColorVar.r = 0.5f;
        m_tStartColorVar.g = 0.5f;
        m_tStartColorVar.b = 0.5f;
        m_tStartColorVar.a = 0.0f;
        m_tEndColor.r = 0.5f;
        m_tEndColor.g = 0.5f;
        m_tEndColor.b = 0.5f;
        m_tEndColor.a = 0.0f;
        m_tEndColorVar.r = 0.5f;
        m_tEndColorVar.g = 0.5f;
        m_tEndColorVar.b = 0.5f;
        m_tEndColorVar.a = 0.0f;

        CCTexture2D* texture = getDefaultTexture();
        if (texture != NULL)
        {
            setTexture(texture);
        }

        // additive
        setBlendAdditive(false);
        return true;
    }
	
    return false;
}

//
// ParticleSmoke
//

ParticleSmoke* ParticleSmoke::create()
{
    ParticleSmoke* pRet = new ParticleSmoke();
    if (pRet && pRet->init())
    {
        pRet->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(pRet);
    }
    return pRet;
}

ParticleSmoke* ParticleSmoke::createWithTotalParticles(unsigned int numberOfParticles)
{
    ParticleSmoke* pRet = new ParticleSmoke();
    if (pRet && pRet->initWithTotalParticles(numberOfParticles))
    {
        pRet->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(pRet);
    }
    return pRet;
}

bool ParticleSmoke::initWithTotalParticles(unsigned int numberOfParticles)
{
	
    if( CCParticleSystemQuad::initWithTotalParticles(numberOfParticles) )
    {
        // duration
        setDuration(0.6f);

        // Emitter mode: Gravity Mode
        setEmitterMode(kCCParticleModeGravity);

        // Gravity Mode: gravity
        setGravity(CCPoint(0,0));

        // Gravity Mode: radial acceleration
        setRadialAccel(0);
        setRadialAccelVar(0);

        // Gravity Mode: speed of particles
        setSpeed(25);
        setSpeedVar(10);

        // angle
        m_fAngle = 90;
        m_fAngleVar = 5;

        // emitter position
        CCSize winSize = CCDirector::sharedDirector()->getWinSize();
        setPosition(CCPoint(winSize.width/2, 0));
        setPosVar(CCPoint(20, 0));

        // life of particles
        m_fLife = 4;
        m_fLifeVar = 1;

        // CCSize, in pixels
        m_fStartSize = 60.0f;
        m_fStartSizeVar = 10.0f;
        setEndSize(kCCParticleStartSizeEqualToEndSize);

        // emits per frame
        setEmissionRate(getTotalParticles()/getLife());

        // color of particles
        m_tStartColor.r = 0.8f;
        m_tStartColor.g = 0.8f;
        m_tStartColor.b = 0.8f;
        m_tStartColor.a = 1.0f;
        m_tStartColorVar.r = 0.02f;
        m_tStartColorVar.g = 0.02f;
        m_tStartColorVar.b = 0.02f;
        m_tStartColorVar.a = 0.0f;
        m_tEndColor.r = 0.0f;
        m_tEndColor.g = 0.0f;
        m_tEndColor.b = 0.0f;
        m_tEndColor.a = 1.0f;
        m_tEndColorVar.r = 0.0f;
        m_tEndColorVar.g = 0.0f;
        m_tEndColorVar.b = 0.0f;
        m_tEndColorVar.a = 0.0f;

        CCTexture2D* texture = getDefaultTexture();
        if (texture != NULL)
        {
            setTexture(texture);
        }

        // additive
        setBlendAdditive(false);
        return true;
    }
	
    return false;
}

//
// ParticleSnow
//

ParticleSnow* ParticleSnow::create()
{
    ParticleSnow* pRet = new ParticleSnow();
    if (pRet && pRet->init())
    {
        pRet->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(pRet);
    }
    return pRet;
}

ParticleSnow* ParticleSnow::createWithTotalParticles(unsigned int numberOfParticles)
{
    ParticleSnow* pRet = new ParticleSnow();
    if (pRet && pRet->initWithTotalParticles(numberOfParticles))
    {
        pRet->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(pRet);
    }
    return pRet;
}

bool ParticleSnow::initWithTotalParticles(unsigned int numberOfParticles)
{
	
    if( CCParticleSystemQuad::initWithTotalParticles(numberOfParticles) ) 
    {
        // duration
        setDuration(0.6f);

        // set gravity mode.
        setEmitterMode(kCCParticleModeGravity);

        // Gravity Mode: gravity
        setGravity(CCPoint(0,-1));

        // Gravity Mode: speed of particles
        setSpeed(5);
        setSpeedVar(1);

        // Gravity Mode: radial
        setRadialAccel(0);
        setRadialAccelVar(1);

        // Gravity mode: tangential
        setTangentialAccel(0);
        setTangentialAccelVar(1);

        // emitter position
        CCSize winSize = CCDirector::sharedDirector()->getWinSize();
        setPosition(CCPoint(winSize.width/2, winSize.height + 10));
        setPosVar(CCPoint(winSize.width/2, 0));

        // angle
        m_fAngle = -90;
        m_fAngleVar = 5;

        // life of particles
        m_fLife = 45;
        m_fLifeVar = 15;

        // CCSize, in pixels
        m_fStartSize = 10.0f;
        m_fStartSizeVar = 5.0f;
        setEndSize(kCCParticleStartSizeEqualToEndSize);

        // emits per second
        setEmissionRate(10);

        // color of particles
        m_tStartColor.r = 1.0f;
        m_tStartColor.g = 1.0f;
        m_tStartColor.b = 1.0f;
        m_tStartColor.a = 1.0f;
        m_tStartColorVar.r = 0.0f;
        m_tStartColorVar.g = 0.0f;
        m_tStartColorVar.b = 0.0f;
        m_tStartColorVar.a = 0.0f;
        m_tEndColor.r = 1.0f;
        m_tEndColor.g = 1.0f;
        m_tEndColor.b = 1.0f;
        m_tEndColor.a = 0.0f;
        m_tEndColorVar.r = 0.0f;
        m_tEndColorVar.g = 0.0f;
        m_tEndColorVar.b = 0.0f;
        m_tEndColorVar.a = 0.0f;

        CCTexture2D* texture = getDefaultTexture();
        if (texture != NULL)
        {
            setTexture(texture);
        }

        // additive
        setBlendAdditive(false);
        return true;
    }
	
    return false;
}

//
// ParticleRain
//

ParticleRain* ParticleRain::create()
{
    ParticleRain* pRet = new ParticleRain();
    if (pRet && pRet->init())
    {
        pRet->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(pRet);
    }
    return pRet;
}

ParticleRain* ParticleRain::createWithTotalParticles(unsigned int numberOfParticles)
{
    ParticleRain* pRet = new ParticleRain();
    if (pRet && pRet->initWithTotalParticles(numberOfParticles))
    {
        pRet->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(pRet);
    }
    return pRet;
}

bool ParticleRain::initWithTotalParticles(unsigned int numberOfParticles)
{
	
    if( CCParticleSystemQuad::initWithTotalParticles(numberOfParticles) )
    {
        // duration
        setDuration(0.6f);

        setEmitterMode(kCCParticleModeGravity);

        // Gravity Mode: gravity
        setGravity(CCPoint(10,-10));

        // Gravity Mode: radial
        setRadialAccel(0);
        setRadialAccelVar(1);

        // Gravity Mode: tangential
        setTangentialAccel(0);
        setTangentialAccelVar(1);

        // Gravity Mode: speed of particles
        setSpeed(130);
        setSpeedVar(30);

        // angle
        m_fAngle = -90;
        m_fAngleVar = 5;


        // emitter position
        CCSize winSize = CCDirector::sharedDirector()->getWinSize();
        setPosition(CCPoint(winSize.width/2, winSize.height));
        setPosVar(CCPoint(winSize.width/2, 0));

        // life of particles
        m_fLife = 4.5f;
        m_fLifeVar = 0;

        // CCSize, in pixels
        m_fStartSize = 4.0f;
        m_fStartSizeVar = 2.0f;
        setEndSize(kCCParticleStartSizeEqualToEndSize);

        // emits per second
        setEmissionRate(20);

        // color of particles
        m_tStartColor.r = 0.7f;
        m_tStartColor.g = 0.8f;
        m_tStartColor.b = 1.0f;
        m_tStartColor.a = 1.0f;
        m_tStartColorVar.r = 0.0f;
        m_tStartColorVar.g = 0.0f;
        m_tStartColorVar.b = 0.0f;
        m_tStartColorVar.a = 0.0f;
        m_tEndColor.r = 0.7f;
        m_tEndColor.g = 0.8f;
        m_tEndColor.b = 1.0f;
        m_tEndColor.a = 0.5f;
        m_tEndColorVar.r = 0.0f;
        m_tEndColorVar.g = 0.0f;
        m_tEndColorVar.b = 0.0f;
        m_tEndColorVar.a = 0.0f;

        CCTexture2D* texture = getDefaultTexture();
        if (texture != NULL)
        {
            setTexture(texture);
        }

        // additive
        setBlendAdditive(false);
        return true;
    }
	
    return false;
}


//
// ParticleRainbow
//

ParticleRainbow* ParticleRainbow::create(CCPoint position)
{
    ParticleRainbow* pRet = new ParticleRainbow();
    if (pRet && pRet->init(position))
    {
        pRet->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(pRet);
    }
    return pRet;
}

ParticleRainbow* ParticleRainbow::createWithTotalParticles(unsigned int numberOfParticles, CCPoint position)
{
    ParticleRainbow* pRet = new ParticleRainbow();
    if (pRet && pRet->initWithTotalParticles(numberOfParticles, position ))
    {
        pRet->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(pRet);
    }
    return pRet;
}

bool ParticleRainbow::initWithTotalParticles(unsigned int numberOfParticles, CCPoint position)
{
	
    if( CCParticleSystemQuad::initWithTotalParticles(numberOfParticles) )
    {
        // duration
        setDuration(-1);

        // Gravity Mode
        setEmitterMode(kCCParticleModeGravity);

        // Gravity Mode: gravity
        setGravity(CCPoint(0,0));

        // Gravity mode: radial acceleration
        setRadialAccel(0);
        setRadialAccelVar(0);

        // Gravity mode: speed of particles
        setSpeed(120);
        setSpeedVar(0);


        // angle
        setAngle(180);
        setAngleVar(0);

        // emitter position
        setPosition(position);
        setPosVar(CCPointZero);

        // life of particles
        setLife(0.5f);
        setLifeVar(0);

        // CCSize, in pixels
        setStartSize(25.0f);
        setStartSizeVar(0);
        setEndSize(kCCParticleStartSizeEqualToEndSize);

        // emits per seconds
        setEmissionRate(getTotalParticles()/getLife());

        // color of particles
        setStartColor(ccc4FFromccc4B(ccc4(50, 50, 50, 50)));
        setEndColor(ccc4FFromccc4B(ccc4(0, 0, 0, 0)));

        m_tStartColorVar.r = 0.0f;
        m_tStartColorVar.g = 0.0f;
        m_tStartColorVar.b = 0.0f;
        m_tStartColorVar.a = 0.0f;
        m_tEndColorVar.r = 0.0f;
        m_tEndColorVar.g = 0.0f;
        m_tEndColorVar.b = 0.0f;
        m_tEndColorVar.a = 0.0f;
        CCTexture2D* texture = getDefaultTexture();
        if (texture != NULL)
        {
            setTexture(texture);
        }

        // additive
        setBlendAdditive(false);
        return true;
    }
	
    return false;
}


//
// ParticleRainbow
//

ParticleBigFlower* ParticleBigFlower::create(CCPoint position)
{
    ParticleBigFlower* pRet = new ParticleBigFlower();
    if (pRet && pRet->init(position))
    {
        pRet->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(pRet);
    }
    return pRet;
}

ParticleBigFlower* ParticleBigFlower::createWithTotalParticles(unsigned int numberOfParticles, CCPoint position)
{
    ParticleBigFlower* pRet = new ParticleBigFlower();
    if (pRet && pRet->initWithTotalParticles(numberOfParticles, position ))
    {
        pRet->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(pRet);
    }
    return pRet;
}

bool ParticleBigFlower::initWithTotalParticles(unsigned int numberOfParticles, CCPoint position)
{
	
    if( CCParticleSystemQuad::initWithTotalParticles(numberOfParticles) )
    {
        // duration
        setDuration(-1);

        // Gravity Mode
        setEmitterMode(kCCParticleModeGravity);

		// gravity
		setGravity(CCPointZero);
    
		// angle
		setAngle(90);
		setAngleVar(360);
    
		// speed of particles
		setSpeed(160);
		setSpeedVar(20);
    
		// radial
		setRadialAccel(-120);
		setRadialAccelVar(0);
    
		// tagential
		setTangentialAccel(30);
		setTangentialAccelVar(0);
    
		// emitter position
		setPosition(CCPoint(160,240) );
		setPosVar(CCPointZero);
    
		// life of particles
		setLife(4);
		setLifeVar(1);
    
		// spin of particles
		setStartSpin(0);
		setStartSizeVar(0);
		setEndSpin(0);
		setEndSpinVar(0);
    
		// color of particles
		ccColor4F startColor = {0.5f, 0.5f, 0.5f, 1.0f};
		setStartColor(startColor);
    
		ccColor4F startColorVar = {0.5f, 0.5f, 0.5f, 1.0f};
		setStartColorVar(startColorVar);
    
		ccColor4F endColor = {0.1f, 0.1f, 0.1f, 0.2f};
		setEndColor(endColor);
    
		ccColor4F endColorVar = {0.1f, 0.1f, 0.1f, 0.2f};    
		setEndColorVar(endColorVar);
    
		// CCSize, in pixels
		setStartSize(80.0f);
		setStartSizeVar(40.0f);
		setEndSize(kCCParticleStartSizeEqualToEndSize);
    
		// emits per second
		setEmissionRate(getTotalParticles()/getLife());
    
		// additive
		setBlendAdditive(true);

        setPosition(position);
		//old
        CCTexture2D* texture = getDefaultTexture();
        if (texture != NULL)
        {
            setTexture(texture);
        }

        return true;
    }
	
    return false;
}

}

