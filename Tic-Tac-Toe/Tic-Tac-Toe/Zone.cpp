#include "pch.h"
#include "Zone.h"


Zone::Zone(int index)
{
	this->index = index;
	this->state = 0;
}

Zone::~Zone()
{
}

int Zone::getIndex()
{
	return this->index;
}
int Zone::getState()
{
	return this->state;
}
void Zone::setState(int state)
{
	this->state = state;
}
