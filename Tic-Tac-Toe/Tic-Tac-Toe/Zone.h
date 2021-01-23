#pragma once
class Zone
{
private: 
	int index;
	int state;
public:
	Zone(int index);
	~Zone();
	int getIndex();
	int getState();
	void setState(int state);
};

