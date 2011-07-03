
#ifndef CLIENT_H
#define CLIENT_H
#include <enet/enet.h>
#include "net_protocol.h"

namespace server {
using namespace std;
using namespace shared;

/**
  * class Client
  * 
  */

class Client {
friend class CuboidServer;
friend class NetworkController;
public:


	/**
	* Empty Constructor
	*/
	Client(CuboidServer* serverRoot, int ID, ENetPeer* peer, string name);

	/**
	* Empty Destructor
	*/
	virtual ~Client();
	
	int getID();
	string getName();
private:
	
	int ID;
	ENetPeer* enetPeer;
	
	CuboidServer* root;
	ConnectionState connState;
	
	
	string name;
	
	//some attributes TODO
	// Entity* playerEnt;
	int health;
	int weapon;
	int ammo;
	

};
}; // end of package namespace

#endif // CLIENT_H
