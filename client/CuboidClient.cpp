#include "cuboid_client.h"
namespace client {


CuboidClient::CuboidClient() : sout(std::cout) {}

CuboidClient::~CuboidClient() {}

void CuboidClient::doTick() {}

void CuboidClient::fatalError(const char* SubSys, const char* Msg) {
	sout << "Fatal Error [" << SubSys << "] " << Msg << endl;
	exit(-1);
}

void CuboidClient::print(const char* Msg) {
	sout << Msg << endl; //FIXME reroute to console
}

void CuboidClient::printMsg(const char* Msg) {
	//FIXME display GUI popup
}




};