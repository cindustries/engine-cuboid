#include "NetworkController.h"
#include "cuboid_server.h"
#include "enet/enet.h"
#include "CuboidServer.h"

namespace server {

NetworkController::NetworkController(CuboidServer* ParentEngine) :
	root(ParentEngine)
{ initEnet(); };


NetworkController::~NetworkController() {

}

void NetworkController::initEnet() {
	if( enet_initialize() != 0){
		root->fatalError("NetController", "Cannot initialise ENet");
	};
	enetAddress.host = ENET_HOST_ANY;
	enetAddress.port = 24024;
	
	enetHost = enet_host_create(&enetAddress, 64, 2, 0, 0);
	if(enetHost == NULL) {
		root->fatalError("NetController", "Cannot create ENet host");
	}
}

};