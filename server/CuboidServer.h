#ifndef CUBOIDSERVER_H
#define CUBOIDSERVER_H
#include "cuboid_server.h"

namespace server {
using namespace std;

/**
  * class CuboidServer
  * 
  */

class CuboidServer : public CuboidEngine {
public:

	// Constructors/Destructors
	
	/**
		* Empty Constructor
		*/
	CuboidServer();

	/**
		* Empty Destructor
		*/
	~CuboidServer();
	
	void doTick();
	void fatalError(const char* SubSys, const char* Reason);
	void print(const char* Msg);
	void printMsg(const char* Msg);
	void addClient( Client* client ); //called upon connection
	void disconnectClient( int clientID );
	
	ConCmdManager cmdMgr;
	ConVarStorage confMgr;
	
	std::ostream& sout;
	
private:
	
	vector<PhysWorld*> world;
	vector<Client*> clients;
	NetworkController* netController;
	
	int tickNum;

};

}; // end of package namespace

#endif // CUBOIDSERVER_H
