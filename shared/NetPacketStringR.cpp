#include "cuboid_shared.h"
#include "NetPacketStringR.h"

namespace shared {

//it is either readable, or writable, but not both
NetPacketStringR::NetPacketStringR(uchar* data) : data(data), dataPtr(NULL) {};

NetPacketStringR::~NetPacketStringR() { data.clear(); };


inline int NetPacketStringR::getInt() {
	int i = char(*dataPtr++);
	if( i == 127 ){
		i = char(*dataPtr++)<<8;
		i |= char(*dataPtr++);
	}else if( i = 128 ){
		i = char(*dataPtr++)<<24;
		i |= char(*dataPtr++)<<16; 
		i |= char(*dataPtr++)<<8; 
		i |= char(*dataPtr++);
	};
	return i;
}

inline string NetPacketStringR::getString() {
	int len = getInt();
	string tmpStr((const char*)dataPtr, len);
	dataPtr += len;
	return tmpStr;
}

};