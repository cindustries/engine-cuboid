
#ifndef CONCMDMANAGER_H
#define CONCMDMANAGER_H

#include "cuboid_shared.h"
#include <string>
#include <map>
#include <vector>

using namespace std;

class ConCmdManager {
public:

	ConCmdManager();
	~ConCmdManager();
	
	void execCommand(string Cmd);
	void setCommandCallback(string CmdName, void(*callbackFunc)(string,vector<string>)); //calls: callbackFunc( string CmdName, string Arguments );
	void delCommand(string CmdName);
	
private:
	map<string, void (*)(string,vector<string>)> cmdList;
	


};

#endif // CONCMDMANAGER_H
