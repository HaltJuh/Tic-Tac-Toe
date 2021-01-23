#pragma once
#ifndef ZONEMASTER_H_
#define ZONEMASTER_H_

#include "Zone.h"
class ZoneMaster
{
private:
	Zone* zones[9];
public:
	ZoneMaster();
	~ZoneMaster();
	void printZoneIndexes();
	int getZoneIndex(int index);
	int getZoneState(int index);
	void setZoneState(int index,int state);
};
#endif
