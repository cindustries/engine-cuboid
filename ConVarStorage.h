
#ifndef CONVARSTORAGE_H
#define CONVARSTORAGE_H
#include <string>
#include <map>

using namespace std;

/**
  * class ConVarStorage
  * 
  */

class ConVarStorage {
	
public:

	ConVarStorage();
	virtual ~ConVarStorage();
	
	void setVarS(string Name, string Value);
	void setVarI(string Name, int    Value);
	void setVarF(string Name, float  Value);
	
	string getVarS(string Name);
	int    getVarI(string Name);
	float  getVarF(string Name);
	
	bool varExists(string Name);
	
private:
	
	map<string,string> varList;

};

#endif // CONVARSTORAGE_H
