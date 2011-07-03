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
	
	void doTick();
	void disconnectPeer(ENetPeer* peer);
    
private:
	void initEnet();
	void processPacket(ENetPacket* packet);
	CuboidServer* root;
	ENetAddress enetAddress;
	ENetHost* enetHost;
};

};
#endif // NETWORKCONTROLLER_H
