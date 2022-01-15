// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include <tchar.h>
#include "acdb.h"
#include "aced.h"
#include "Opening.h"

#pragma comment(linker,"/EXPORT:acrxEntryPoint")
#pragma comment(linker,"/EXPORT:acrxGetApiVersion")

void doorSchedule() {
	const int totalDoors = 19;
	Opening doors[totalDoors];
	
	for (int i = 0; i < totalDoors; i++) {
		doors[i].setID(i + 1); // door IDs are 1 through 19 for this project
	}
	// manually set rough openings found in architectural plans
	doors[0].setRoughOpening("40.5x86.25");
	doors[1].setRoughOpening("NOT USED");
	doors[2].setRoughOpening("NOT USED");
	doors[3].setRoughOpening("38x98");
	doors[4].setRoughOpening("36x82");
	doors[5].setRoughOpening("50x82");
	doors[6].setRoughOpening("36x82");
	doors[7].setRoughOpening("74x82");
	doors[8].setRoughOpening("36x82");
	doors[9].setRoughOpening("50x82");
	doors[10].setRoughOpening("98x82");
	doors[11].setRoughOpening("62x82");
	doors[12].setRoughOpening("34x82");
	doors[13].setRoughOpening("30x82");
	doors[14].setRoughOpening("32x82");
	doors[15].setRoughOpening("34x82");
	doors[16].setRoughOpening("26x82");
	doors[17].setRoughOpening("NOT USED");
	doors[18].setRoughOpening("38x82");

	int userID;
	acedGetInt(_T("\nEnter door ID: "), &userID);
	if (userID < 20 && userID > 0) {
		acutPrintf(_T("\nDoor: %d RO: %s"), doors[userID - 1].getID(), doors[userID - 1].getRoughOpening());
	}
	else {
		acutPrintf(_T("\nPlease enter a valid door ID"));
	}
}

extern "C" AcRx::AppRetCode acrxEntryPoint(AcRx::AppMsgCode msg, void* appId)
{
	switch (msg)
	{
		case AcRx::kInitAppMsg:
			acrxDynamicLinker->unlockApplication(appId);
			acrxDynamicLinker->registerAppMDIAware(appId);
			// register command with group name, global and local name, and pass in function for command
			acedRegCmds->addCommand(_T("CMD Group"), _T("DOORSCHEDULE"), _T("DOORSCHEDULE"), ACRX_CMD_MODAL, doorSchedule);

			acutPrintf(_T("\nLoading CAD command\n"));
			break;
			
		case AcRx::kUnloadAppMsg:
			acutPrintf(_T("\nUnloading CAD command\n"));
			acedRegCmds->removeGroup(_T("CMD Group"));
			break;
		default:
			break;
	}
	return AcRx::kRetOK;
}