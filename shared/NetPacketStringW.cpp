#include "cuboid_shared.h"
#include "NetPacketStringW.h"

namespace shared {

NetPacketStringW::NetPacketStringW() {};
NetPacketStringW::~NetPacketStringW() { data.clear(); };

//uses cube-style encoding: fast, but not the most efficient size-wise
// first byte: -128 to +126 => single byte, absolute value
// 127 => two-byte short follows
// 128 => full four-byte int follows
inline void NetPacketStringW::putInt(int i) { 
	uchar tmpBuf[5];
	if( -128 < i && i <= 126 ){
		tmpBuf[0] = (uchar)i;
		data.append(tmpBuf,1);
	}else if( -32768 < i && i <= 32768 ){
		tmpBuf[0] = 127;
		tmpBuf[1] = (uchar)(i >> 8);
		tmpBuf[2] = (uchar)i;
		data.append(tmpBuf,3);
	}else{
		tmpBuf[0] = 128;
		tmpBuf[1] = (uchar)(i >> 24);
		tmpBuf[2] = (uchar)(i >> 16);
		tmpBuf[3] = (uchar)(i >> 8);
		tmpBuf[4] = (uchar)i;
		data.append(tmpBuf,5);
	}
}

//putting a string: an int defining it's length followed by the chars
inline void NetPacketStringW::putString(string& s) {
	putInt(s.length());
	data.append((uchar*)s.c_str(), s.length());
}

inline void NetPacketStringW::putType( CuboidNetProtocol type ){ putInt(type); }

//helper funcs
void NetPacketStringW::newNoop() {
	putType(NET_NOOP);
}

void NetPacketStringW::newMessage(string& Msg) {
	putType(NET_MESSAGE);
	putString(Msg);
}

void NetPacketStringW::newRequestJoin(string& Name) {
	putType(NET_REQUEST_JOIN);
	putString(Name);
}

void NetPacketStringW::newConfirmJoin(int CID) {
	putType(NET_CONFIRM_JOIN);
	putInt(CID);
}






};