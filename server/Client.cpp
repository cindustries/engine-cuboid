#include "cuboid_server.h"
namespace server {

using namespace std;
// Constructors/Destructors
//  

Client::Client(CuboidServer* serverRoot, int ID, ENetPeer* peer, string name) :
	root(serverRoot),
	ID(ID),
	enetPeer(peer),
	name(name)
{};


Client::~Client ( ) { }

};