#include "CuboidServer.h"
#include "cuboid_server.h"

namespace server {

CuboidServer::CuboidServer() :
	world( new PhysWorld(this) ),
	netController( new NetworkController(this) )
{};

CuboidServer::~CuboidServer() {};

void CuboidServer::doTick() {};

void CuboidServer::fatalError(const char* SubSys, const char* Reason) {
	cout << "Fatal Error [" << SubSys << "]: " << Reason << endl;
};



};
