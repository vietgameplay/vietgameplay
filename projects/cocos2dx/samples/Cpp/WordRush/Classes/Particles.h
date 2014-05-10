#ifndef __PARTICLES_H__
#define __PARTICLES_H__

#include "particle_nodes/CCParticleSystemQuad.h"

using namespace cocos2d;
namespace VGP
{

//! @brief A fire particle system
class ParticleJet : public CCParticleSystemQuad
{
public:
    ParticleJet(){}
    virtual ~ParticleJet(){}
    bool init(CCPoint position){ return initWithTotalParticles(150, position); }
    virtual bool initWithTotalParticles(unsigned int numberOfParticles, CCPoint position);
    
    static ParticleJet* create(CCPoint position);
    static ParticleJet* createWithTotalParticles(unsigned int numberOfParticles, CCPoint position);
};

//! @brief A fire particle system
class  ParticleFire : public CCParticleSystemQuad
{
public:
    ParticleFire(){}
    virtual ~ParticleFire(){}
    bool init(CCPoint position){ return initWithTotalParticles(250, position); }
    virtual bool initWithTotalParticles(unsigned int numberOfParticles, CCPoint position);
    
    static ParticleFire* create(CCPoint position);
    static ParticleFire* createWithTotalParticles(unsigned int numberOfParticles, CCPoint position);
};

//! @brief A fireworks particle system
class  ParticleFireworks : public CCParticleSystemQuad
{
public:
    ParticleFireworks(){}
    virtual ~ParticleFireworks(){}
    bool init(){ return initWithTotalParticles(1500); }
    virtual bool initWithTotalParticles(unsigned int numberOfParticles);
    
    static ParticleFireworks* create();
    static ParticleFireworks* createWithTotalParticles(unsigned int numberOfParticles);
};

//! @brief A sun particle system
class  ParticleSun : public CCParticleSystemQuad
{
public:
    ParticleSun(){}
    virtual ~ParticleSun(){}
    bool init(){ return initWithTotalParticles(350); }
    virtual bool initWithTotalParticles(unsigned int numberOfParticles);
    
    static ParticleSun* create();
    static ParticleSun* createWithTotalParticles(unsigned int numberOfParticles);
};

//! @brief A galaxy particle system
class  ParticleGalaxy : public CCParticleSystemQuad
{
public:
    ParticleGalaxy(){}
    virtual ~ParticleGalaxy(){}
    bool init(){ return initWithTotalParticles(200); }
    virtual bool initWithTotalParticles(unsigned int numberOfParticles);
    
    static ParticleGalaxy* create();
    static ParticleGalaxy* createWithTotalParticles(unsigned int numberOfParticles);
};

//! @brief A flower particle system
class  ParticleFlower : public CCParticleSystemQuad
{
public:
    ParticleFlower(){}
    virtual ~ParticleFlower(){}
    bool init(CCPoint position){ return initWithTotalParticles(20, position); }
    virtual bool initWithTotalParticles(unsigned int numberOfParticles, CCPoint position);
    
    static ParticleFlower* create(CCPoint position);
    static ParticleFlower* createWithTotalParticles(unsigned int numberOfParticles, CCPoint position);
};

//! @brief A meteor particle system
class  ParticleMeteor : public CCParticleSystemQuad
{
public:
    ParticleMeteor(){}
    virtual ~ParticleMeteor(){}
    bool init(){ return initWithTotalParticles(150); }
    virtual bool initWithTotalParticles(unsigned int numberOfParticles);

    static ParticleMeteor * create();
    static ParticleMeteor* createWithTotalParticles(unsigned int numberOfParticles);
};

//! @brief An spiral particle system
class  ParticleSpiral : public CCParticleSystemQuad
{
public:
    ParticleSpiral(){}
    virtual ~ParticleSpiral(){}
    bool init(){ return initWithTotalParticles(500); }
    virtual bool initWithTotalParticles(unsigned int numberOfParticles);
    
    static ParticleSpiral* create();
    static ParticleSpiral* createWithTotalParticles(unsigned int numberOfParticles);
};

//! @brief An explosion particle system
class  ParticleExplosion : public CCParticleSystemQuad
{
public:
    ParticleExplosion(){}
    virtual ~ParticleExplosion(){}
    bool init(){ return initWithTotalParticles(700); }
    virtual bool initWithTotalParticles(unsigned int numberOfParticles);
    
    static ParticleExplosion* create();
    static ParticleExplosion* createWithTotalParticles(unsigned int numberOfParticles);
};

//! @brief An smoke particle system
class  ParticleSmoke : public CCParticleSystemQuad
{
public:
    ParticleSmoke(){}
    virtual ~ParticleSmoke(){}
    bool init(){ return initWithTotalParticles(200); }
    virtual bool initWithTotalParticles(unsigned int numberOfParticles);
    
    static ParticleSmoke* create();
    static ParticleSmoke* createWithTotalParticles(unsigned int numberOfParticles);
};

//! @brief An snow particle system
class  ParticleSnow : public CCParticleSystemQuad
{
public:
    ParticleSnow(){}
    virtual ~ParticleSnow(){}
    bool init(){ return initWithTotalParticles(700); }
    virtual bool initWithTotalParticles(unsigned int numberOfParticles);
    
    static ParticleSnow* create();
    static ParticleSnow* createWithTotalParticles(unsigned int numberOfParticles);
};

//! @brief A rain particle system
class  ParticleRain : public CCParticleSystemQuad
{
public:
    ParticleRain(){}
    virtual ~ParticleRain(){}
    bool init(){ return initWithTotalParticles(1000); }
    virtual bool initWithTotalParticles(unsigned int numberOfParticles);
    
    static ParticleRain* create();
    static ParticleRain* createWithTotalParticles(unsigned int numberOfParticles);
};

//! @brief A rainboW particle system
class  ParticleRainbow : public CCParticleSystemQuad
{
public:
    ParticleRainbow(){}
    virtual ~ParticleRainbow(){}
    bool init(CCPoint position){ return initWithTotalParticles(1000, position); }
    virtual bool initWithTotalParticles(unsigned int numberOfParticles, CCPoint position);
    
    static ParticleRainbow* create(CCPoint position);
    static ParticleRainbow* createWithTotalParticles(unsigned int numberOfParticles, CCPoint position);
};

//! @brief A rainboW particle system
class  ParticleBigFlower : public CCParticleSystemQuad
{
public:
    ParticleBigFlower(){}
    virtual ~ParticleBigFlower(){}
    bool init(CCPoint position){ return initWithTotalParticles(50, position); }
    virtual bool initWithTotalParticles(unsigned int numberOfParticles, CCPoint position);
    
    static ParticleBigFlower* create(CCPoint position);
    static ParticleBigFlower* createWithTotalParticles(unsigned int numberOfParticles, CCPoint position);
};

}
#endif 
