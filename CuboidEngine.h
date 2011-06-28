#ifndef CUBOIDENGINE_H
#define CUBOIDENGINE_H

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

};

#endif // CUBOIDENGINE_H
