#ifndef CUBOIDCLIENT_H
#define CUBOIDCLIENT_H


class CuboidClient : virtual public CuboidEngine {
public:

	CuboidClient();
	virtual ~CuboidClient();

	void doTick();
	
	std::ostream& sout;
	
	void fatalError(const char* SubSys, const char* Msg);
	void print(const char* Msg);
	void printMsg(const char* Msg);

};

#endif // CUBOIDCLIENT_H
