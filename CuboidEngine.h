#ifndef CUBOIDENGINE_H
#define CUBOIDENGINE_H

#include <iostream>
#include <sstream>


class CuboidEngine {
public:

	virtual ~CuboidEngine();

	const static int VERSION;

	virtual void doTick() = 0;
	virtual void fatalError(const char* SubSys, const char* Reason) = 0;
	virtual void print(const char* Msg) = 0;
	virtual void printMsg(const char* Msg) = 0;

};

#endif // CUBOIDENGINE_H
