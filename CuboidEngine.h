#ifndef CUBOIDENGINE_H
#define CUBOIDENGINE_H

#include <iostream>
#include <sstream>

/**
  * class CuboidEngine
  *
  */

class CuboidEngine {
public:

	static const int VERSION;

	/**
	 * To be implemented - does an engine tick.
	 */
	virtual void doTick() = 0;
	virtual void fatalError(const char* SubSys, const char* Reason) = 0;
	virtual void print(const char* Msg) = 0;
	virtual void printMsg(const char* Msg) = 0;

};

#endif // CUBOIDENGINE_H
