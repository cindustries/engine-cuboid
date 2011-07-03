#ifndef CUBOIDCLIENT_H
#define CUBOIDCLIENT_H

namespace client {


/**
  * class CuboidClient
  * Base client object
  */

class CuboidClient : virtual public CuboidEngine {
public:

	/**
	* Empty Constructor
	*/
	CuboidClient();

	/**
	* Empty Destructor
	*/
	virtual ~CuboidClient();


	/**
	*/
	void doTick();
	
	ostream& sout;
	
	void fatalError(const char* SubSys, const char* Msg);
	void print(const char* Msg);
	void printMsg(const char* Msg);

};
}; // end of package namespace

#endif // CUBOIDCLIENT_H
