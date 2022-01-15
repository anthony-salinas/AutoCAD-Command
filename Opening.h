#pragma once
#include<tchar.h>
class Opening
{
private:
	int id;
	TCHAR roughOpening[20];

public:
	Opening();
	int getID();
	void setID(int doorID);
	TCHAR* getRoughOpening();
	void setRoughOpening(const char* doorRO);
};

