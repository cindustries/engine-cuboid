#include "cuboid_shared.h"

namespace shared {
	
ConCmdManager::ConCmdManager() {};

ConCmdManager::~ConCmdManager(){
	cmdList.clear();
}

void ConCmdManager::execCommand(string Cmd) {
	string CmdName;
	vector<string> CmdArgs;
	size_t findVal = Cmd.find(' ');
	if( findVal != string::npos)
		CmdName = Cmd.substr(0, findVal);
		
		string tmp = Cmd.substr(findVal+1);
		while(findVal = tmp.find(' ')){
			if(findVal == string::npos){
				CmdArgs.push_back( tmp );
			}else{
				CmdArgs.push_back( tmp.substr(0, findVal) );
				tmp = tmp.substr(findVal+1);
			};
		};
	
	if( cmdList.count(CmdName) == 1 ){
		void (*funcPtr)(string,vector<string>) = (void (*)(string,vector<string>))cmdList[CmdName];
		funcPtr(CmdName,CmdArgs);
	}
}


};

