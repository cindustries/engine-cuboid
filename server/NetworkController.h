#ifndef NETWORKCONTROLLER_H
#define NETWORKCONTROLLER_H
#include "cuboid_server.h"
#include "enet/enet.h"

namespace server {

class NetworkController
{

public:
	//we _NEED_ a root engine, or this cannot function - hence no empty constructor
	NetworkController(CuboidServer* ParentEngine);
	~NetworkController();
    
private:
	void initEnet();
	CuboidServer* root;
	ENetAddress enetAddress;
	ENetHost* enetHost;
};

};
#endif // NETWORKCONTROLLER_H
