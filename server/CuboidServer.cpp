#include "CuboidServer.h"
#include "cuboid_server.h"

namespace server {

CuboidServer::CuboidServer() :
	netController( new NetworkController(this) )
{
	world.push_back( new PhysWorld(this) );
};

CuboidServer::~CuboidServer() {};

void CuboidServer::doTick() {};

void CuboidServer::fatalError(const char* SubSys, const char* Reason) {
	std::cout << "Fatal Error [" << SubSys << "]: " << Reason << endl;
	//FIXME figure a way to cleanly terminate the problem
};

void CuboidServer::print(const char* Msg) {
	std::cout << Msg << endl;
}

void CuboidServer::printMsg(const char* Msg) {
	std::cout << "Message \"" << Msg << '"' << endl;
}


void CuboidServer::addClient(Client* client) {
	clients.push_back(client);
}



};
