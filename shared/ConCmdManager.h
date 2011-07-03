
#ifndef CONCMDMANAGER_H
#define CONCMDMANAGER_H

#include <string>
#include <map>

namespace shared {
using namespace std;

/**
  * class ConCmdManager
  * 
  */

class ConCmdManager {
public:

	/**
	* Empty Constructor
	*/
	ConCmdManager();

	/**
	* Empty Destructor
	*/
	virtual ~ConCmdManager();
	
	void execCommand(string Cmd);
	void setCommandCallback(string CmdName, void*callbackFunc(string,vector<string>)); //calls: callbackFunc( string CmdName, string Arguments );
	void delCommand(string CmdName);
	
private:
	map<string, void (*)(string,vector<string>)> cmdList;
	


};
}; // end of package namespace

#endif // CONCMDMANAGER_H
