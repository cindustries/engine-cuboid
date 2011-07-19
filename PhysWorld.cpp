#include "PhysWorld.h"
#include "cuboid_server.h"

//constructor/destructor
PhysWorld::PhysWorld(CuboidServer* ParentEngine) :
	root(ParentEngine)
{
	initBullet();
};

PhysWorld::~PhysWorld(){
	delete physCollisionConfiguration;
	delete physCollisionDispatcher;
	delete physPairCache;
	delete physConstraintSolver;
	delete physDynamicsWorld;
};

//physical control
void PhysWorld::setGravityMagnitude(float Gravity) {
	physDynamicsWorld->setGravity(btVector3(0, -Gravity, 0));
}


void PhysWorld::initBullet(){
	physCollisionConfiguration = new btDefaultCollisionConfiguration;
	physCollisionDispatcher = new btCollisionDispatcher(physCollisionConfiguration);
	physPairCache = new btDbvtBroadphase;
	physConstraintSolver = new btSequentialImpulseConstraintSolver;
	physDynamicsWorld = new btDiscreteDynamicsWorld(physCollisionDispatcher, physPairCache, physConstraintSolver, physCollisionConfiguration);
	
	setGravityMagnitude(9.8f);
	
}

void PhysWorld::doTick() {
	physDynamicsWorld->stepSimulation(1); //TODO wtf is timeStep?
}


