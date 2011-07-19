#ifndef CUBOIDSERVER_H
#define CUBOIDSERVER_H
#include "cuboid_server.h"

using namespace std;

class CuboidServer : public CuboidEngine {
public:

	CuboidServer();
	virtual ~CuboidServer();
	
	virtual void doTick();
	virtual void fatalError(const char* SubSys, const char* Reason);
	virtual void print(const char* Msg);
	virtual void printMsg(const char* Msg);
	//void addClient( Client* client ); //called upon connection
	void disconnectClient( int clientID );
	
	ConCmdManager cmdMgr;
	ConVarStorage confMgr;
	
	std::ostream& sout;
	
private:
	
	std::vector<PhysWorld*> world;
	//std::vector<Client*> clients;
	NetworkController* netController;
	
	int tickNum;

};

#endif // CUBOIDSERVER_H
