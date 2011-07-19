#ifndef _CUBOID_NET_PROTOCOL_
#define _CUBOID_NET_PROTOCOL_

//defines all the network packet types

const static int HOST_PORT_DEFAULT = 24024;
const static int MAX_CLIENTS_DEFAULT = 32;

	
enum DisconnectReason {
	DISCR_UNKERROR = 0,
	DISCR_NETERR_TIMEOUT,
	DISCR_NETERR_FATAL,
	DISCR_SERVERSHUTDOWN,
	DISCR_KICK,
	DISCR_BAN,
	DISCR_REFUSE,
	DISCR_MSREFUSE,
	DISCR_NORMAL
};

enum ConnectionState {
	CONNST_ERROR = 0,
	CONNST_CONNECTING,
	CONNST_RESOURCE,
	CONNST_ACTIVE,
	CONNST_DISCONNECTING
};

enum CuboidNetProtocol {
	NET_NOOP = 0, // do nothing
	NET_ERROR, // followed by a CuboidNetError

	NET_REQUEST_JOIN, //reqest to join a server (once a connection has been established), sends all the data c2s
	NET_CONFIRM_JOIN, //sends back the client ID, and other required startup info s2c
	
	NET_MESSAGE, // string, display a popup message (client) or print message to cmdline/log (server) - for debugging really
	
	NET_DOWNLOAD_RESOURCE,
	
	NET_PLAYER_SPAWN, //your player has spawned s2c
	
	NET_ENTITY_SPAWN, NET_ENTITY_REMOVE, NET_ENTITY_UPDATEPOS,
	NET_GUI_SHOWWINDOW
};

enum CuboidNetError {
	NETERR_UNKOWN = 0,
	NETERR_TIMEOUT,
	NETERR_FATAL
};


#endif /* _CUBOID_NET_PROTOCOL_ */
