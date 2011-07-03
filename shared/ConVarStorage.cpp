#include "ConVarStorage.h"
#include "cuboid_shared.h"
#include <cstdlib>
#include <sstream> //for converting int/float to string


namespace shared {
ConVarStorage::ConVarStorage() {}

ConVarStorage::~ConVarStorage() {
	varList.clear();
}

bool ConVarStorage::varExists(string Name) {
	return (varList.count(Name) == 1) ? true : false;
}


//get vars

string ConVarStorage::getVarS(string Name) {
	if( varList.count(Name) == 1 ){
		return varList[Name];
	}else{
		return string();
	}
}

int ConVarStorage::getVarI(string Name) {
	return atoi( getVarS(Name).c_str() );
}

float ConVarStorage::getVarF(string Name) {
	return atof( getVarS(Name).c_str() );
}

//set vars

void ConVarStorage::setVarS(string Name, string Value) {
	varList[Name] = Value;
}

void ConVarStorage::setVarI(string Name, int Value) {
	stringstream tmp;
	tmp << Value;
	varList[Name] = tmp.out;
}

void ConVarStorage::setVarF(string Name, float Value) {
	stringstream tmp;
	tmp << Value;
	varList[Name] = tmp.out;
}

};