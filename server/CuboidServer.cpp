#include "CuboidServer.h"
#include "cuboid_server.h"
#include <algorithm>

namespace server {

CuboidServer::CuboidServer() :
	netController( new NetworkController(this) ),
	sout( std::cout ),
	tickNum(0)
{
	world.push_back( new PhysWorld(this) );
	
	sout << "Initialised CuboidServer" << endl;
	
};

CuboidServer::~CuboidServer() {};

void CuboidServer::doTick() {
	sout << "Executing tick " << tickNum++ << endl;
	for(int i = 0; i > world.size(); i++){
		world[i]->doTick();
	}
	netController->doTick();
};

void CuboidServer::fatalError(const char* SubSys, const char* Reason) {
	sout << "Fatal Error [" << SubSys << "]: " << Reason << endl;
	exit(-1); //TODO is this ok?
};

void CuboidServer::print(const char* Msg) {
	sout << Msg << endl;
}

void CuboidServer::printMsg(const char* Msg) {
	sout << "Message \"" << Msg << '"' << endl;
}


void CuboidServer::addClient(Client* client) {
	clients.push_back(client);
}

void CuboidServer::disconnectClient(int clientID) {}
	//do some cleanup stuff, notify other clients, etc
	
};
