#include "pch.h"
#include "Opening.h"
Opening::Opening() {
	id = 0;
	*roughOpening = '\0';
}

int Opening::getID() {
	return id;
}

void Opening::setID(int doorID) {
	id = doorID;
}

TCHAR* Opening::getRoughOpening() {
	return roughOpening;
}

void Opening::setRoughOpening(const char* doorRoughOpening) {
	for (int i = 0; i < strlen(doorRoughOpening); i++) {
		roughOpening[i] = doorRoughOpening[i];
	}
	roughOpening[strlen(doorRoughOpening)] = '\0';
}

