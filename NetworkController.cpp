#include "NetworkController.h"
#include "cuboid_server.h"
#include "enet/enet.h"
#include <sstream>



NetworkController::NetworkController(CuboidServer* ParentEngine) :
	root(ParentEngine)
{ initEnet(); };


NetworkController::~NetworkController() {
	enet_host_destroy(enetHost);
	enet_deinitialize();
}

void NetworkController::doTick() {
	ENetEvent Event;
	
	while( enet_host_service(enetHost, &Event, 0) > 0 ){
		switch( Event.type ) {
			case ENET_EVENT_TYPE_RECEIVE:
				//we have recieved a packet
				processPacket(Event.packet);
			break;
			
			case ENET_EVENT_TYPE_CONNECT:
				
			break;
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
	
	root->sout << "Attempting to create host..." << endl;
	
	if( root->confMgr.varExists("host_address") ){
		enet_address_set_host( &enetAddress, root->confMgr.getVarS("host_address").c_str() );
		
		root->sout << "Binding to configured address " << root->confMgr.getVarS("host_address") <<endl;
	}else{
		enetAddress.host = ENET_HOST_ANY;
		root->sout << "Binding to any available address" << endl;
	}
	
	if( root->confMgr.varExists("host_port") ){
		enetAddress.port = root->confMgr.getVarI("host_port");
	}else{
		enetAddress.port = HOST_PORT_DEFAULT;
	}
	
	root->sout << "Binding to port " << enetAddress.port << endl;
	
	enetHost = enet_host_create(&enetAddress, (root->confMgr.varExists("max_clients")) ? (root->confMgr.getVarI("max_clients")) : MAX_CLIENTS_DEFAULT, 2, 0, 0);
	
	if(enetHost == NULL) {
		root->fatalError("NetController", "Cannot create ENet host");
	}
}

void NetworkController::processPacket(ENetPacket* packet) {
	uchar* data = packet->data;
	CuboidNetProtocol type = static_cast<CuboidNetProtocol>(data[0]);
	//TODO packet processing
	/*if(type == NET_REQUEST_JOIN){
		string name;
		//string format is it's length followed by the string of chars
		name.copy( (char*)&data[2], (size_t)data[1] );
		root->sout << "Recieved NET_REQUEST_JOIN with name " << name << endl;
	}else{
		root->sout << "Recieved unknown packet." << endl;
	}*/

}
