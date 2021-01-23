#include "pch.h"
#include "ZoneMaster.h"
#include "Zone.h"
#include <iostream>


ZoneMaster::ZoneMaster()
{
	for (int i=0; i < 9; i++)
	{
		zones[i] = new Zone(i+1);
	}
}


ZoneMaster::~ZoneMaster()
{

}

void ZoneMaster::printZoneIndexes()
{
	for (int i=0; i < 9; i++)
	{
		std::cout << "\n"<< zones[i]->getIndex() <<"";
	}
}
int ZoneMaster::getZoneIndex(int index)
{
	return zones[index]->getIndex();
}
int ZoneMaster::getZoneState(int index)
{
	return zones[index]->getState();
}
void ZoneMaster::setZoneState(int index,int state)
{
	zones[index]->setState(state);
}
