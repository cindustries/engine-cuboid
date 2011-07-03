#ifndef NETPACKETSTRING_H
#define NETPACKETSTRING_H
#include "cuboid_shared.h"

typedef unsigned char uchar;

namespace shared {
using namespace std;

class NetPacketStringR {

public:
	NetPacketStringR(uchar* data);
	virtual ~NetPacketStringR();
	
	inline int getInt();
	inline string getString();
	
private:
	
	basic_string<uchar> data;
	uchar* dataPtr;
	
};

};

#endif // NETPACKETSTRING_H
