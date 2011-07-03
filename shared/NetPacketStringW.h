#ifndef NETPACKETSTRINGW_H
#define NETPACKETSTRINGW_H

#include "cuboid_shared.h"

namespace shared {

class NetPacketStringW {

public:
	NetPacketStringW();
	virtual ~NetPacketStringW();
	
	inline void putType( CuboidNetProtocol type );
	inline void putInt(int i); //TODO floats
	inline void putString(string& s);
	
	//quick-packet-creation funcs
	void newNoop();
	void newRequestJoin(string& Name);
	void newConfirmJoin(int CID);
	void newMessage(string& Msg);
	
	basic_string<uchar> data;
};

};

#endif // NETPACKETSTRINGW_H
