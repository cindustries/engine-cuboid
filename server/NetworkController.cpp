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

void NetworkController::doTick() {
	ENetEvent Event;
	while( enet_host_service(enetHost, &Event, 0) > 0 ){
		switch( Event.type ) {
			case ENET_EVENT_TYPE_RECEIVE:
				//we have recieved a packet
			break;
			
			case ENET_EVENT_TYPE_CONNECT:
			case ENET_EVENT_TYPE_DISCONNECT:
				//TODO handle these
			break;
		};
	}
}


void NetworkController::initEnet() {
	if( enet_initialize() != 0){
		root->fatalError("NetController", "Cannot initialise ENet");
	};
	enetAddress.host = ENET_HOST_ANY; //allow us to bind to any address //FIXME take this from settings
	enetAddress.port = 24024; //FIXME take this from settings
	
	enetHost = enet_host_create(&enetAddress, 64, 2, 0, 0);
	if(enetHost == NULL) {
		root->fatalError("NetController", "Cannot create ENet host");
	}
}

};