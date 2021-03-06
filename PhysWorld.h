#ifndef PHYSWORLD_H
#define PHYSWORLD_H
#include "cuboid_server.h"
#include "btBulletDynamicsCommon.h"


/**
  * class PhysWorld
  * contains the world - all entities, map data, and the physics engine
  */

class PhysWorld {
public:

	// Constructors/Destructors
	
	PhysWorld(CuboidServer* ParentEngine);
	~PhysWorld();
	
	//physical control
	void setGravityMagnitude(float Gravity);
	void doTick();
	
private:
	
	CuboidServer* root;
	
	void initBullet();
	
	//physics stuff
	btDefaultCollisionConfiguration* physCollisionConfiguration;
	btCollisionDispatcher* physCollisionDispatcher;
	btDbvtBroadphase* physPairCache;
	btSequentialImpulseConstraintSolver* physConstraintSolver;
	btDiscreteDynamicsWorld* physDynamicsWorld;
	
};

#endif // PHYSWORLD_H
