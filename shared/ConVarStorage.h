
#ifndef CONVARSTORAGE_H
#define CONVARSTORAGE_H
#include <string>
#include <map>

namespace shared {
using namespace std;

/**
  * class ConVarStorage
  * 
  */

class ConVarStorage {
	
public:


	/**
	* Empty Constructor
	*/
	ConVarStorage();

	/**
	* Empty Destructor
	*/
	virtual ~ConVarStorage();
	
	void setVarS(string Name, string Value);
	void setVarI(string Name, int    Value);
	void setVarF(string Name, float  Value);
	
	string getVarS(string Name);
	int    getVarI(string Name);
	float  getVarF(string Name);
	
private:
	
	map<string,string> varList;

};
}; // end of package namespace

#endif // CONVARSTORAGE_H
