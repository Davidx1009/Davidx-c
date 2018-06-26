// CM_Get_DevNode_Status_Console.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <Windows.h>
#include <SetupAPI.h>
#include <Cfgmgr32.h>

BOOL ShowErrorMessage(UINT nMessage);

int _tmain(int argc, _TCHAR* argv[])
{
	HDEVINFO		hDevInfo;
	SP_DEVINFO_DATA DeviceInfoData;
	DWORD			i;
	DWORD			dwStatus, dwProblem;
	CONFIGRET		cr = CR_SUCCESS;

	// Create a HDEVINFO with all present devices.
	hDevInfo = SetupDiGetClassDevs(NULL, 0, 0,  DIGCF_PRESENT | DIGCF_ALLCLASSES);
	if (hDevInfo == INVALID_HANDLE_VALUE)
	{
		// Insert error handling here.
		return TRUE;
	}

	DeviceInfoData.cbSize = sizeof(DeviceInfoData);
	for (i=0; SetupDiEnumDeviceInfo(hDevInfo, i, &DeviceInfoData); i++)
	{
		DWORD	dwDataName, dwDataID ;
		LPTSTR	DEVName = NULL;
		LPTSTR	DEVHWID = NULL;
		DWORD	dwBuffersizeN = 0;
		DWORD	dwBuffersizeI = 0;
		char	szDEVName[MAX_PATH], szDEVHWID[MAX_PATH];

		//  Get Device Name
		while (!SetupDiGetDeviceRegistryProperty(hDevInfo, &DeviceInfoData, SPDRP_DEVICEDESC, &dwDataName, (PBYTE)DEVName, dwBuffersizeN, &dwBuffersizeN))
		{
			if (GetLastError() == ERROR_INSUFFICIENT_BUFFER)
			{
				// Change the buffer size.
				if (DEVName) LocalFree(DEVName);
				DEVName = (LPTSTR)LocalAlloc(LPTR, dwBuffersizeN * 2);
			}
			else
				break;
		}
		sprintf(szDEVName, "%s", DEVName);

		//  Get Device HW ID
		while (!SetupDiGetDeviceRegistryProperty(hDevInfo, &DeviceInfoData, SPDRP_HARDWAREID, &dwDataID, (PBYTE)DEVHWID, dwBuffersizeI, &dwBuffersizeI))
		{
			if (GetLastError() == ERROR_INSUFFICIENT_BUFFER)
			{
				// Change the buffer size.
				if (DEVHWID) LocalFree(DEVHWID);
				DEVHWID = (LPTSTR)LocalAlloc(LPTR, dwBuffersizeI * 2);
				
			}
			else
				break;
		}
		wsprintf(szDEVHWID, "%s", DEVHWID);

		//  Get device status
		cr = CM_Get_DevNode_Status(&dwStatus, &dwProblem, DeviceInfoData.DevInst, 0);
		if (dwStatus & DN_HAS_PROBLEM)
		{
			printf("%s, %s has problem:Error code %d ", szDEVName, szDEVHWID, dwProblem);
			ShowErrorMessage(dwProblem);
		}
		else
			printf("%s, %s is running.\n", szDEVName, szDEVHWID);

		if (DEVName) LocalFree(DEVName);
		if (DEVHWID) LocalFree(DEVHWID);
	}

	if ( GetLastError()!=NO_ERROR && GetLastError()!=ERROR_NO_MORE_ITEMS )
	{
		return 1;
	}
       
	//  Cleanup
	SetupDiDestroyDeviceInfoList(hDevInfo);
	system("pause");
	return 0;
}

BOOL ShowErrorMessage(UINT nMessage)
{
	switch(nMessage)
	{
	case 1:
		printf("This device is not configured correctly.\n");
		break;

	case 2:
		printf("Windows could not load the driver for this device because the computer is reporting two bus types.\n");
		break;

	case 3:
		printf("The driver for this device may be bad, or your system may be running low on memory or other resources.\n");
		break;

	case 4:
		printf("This device is not working properly because one of its drivers may be bad, or your registry may be bad.\n");
		break;

	case 5:
		printf("The driver for this device requested a resource that Windows does not know how to handle.\n");
		break;

	case 6:
		printf("Another device is using the resources this device needs.\n");
		break;

	case 7:
		printf("The drivers for this device need to be reinstalled.\n");
		break;

	case 8:
		printf("This device is not working properly because Windows cannot load the file that loads the drivers for the device.\n");
		break;

	case 9:
		printf("This device is not working properly because the BIOS in your computer is reporting the resources for the device incorrectly.\n");
		break;


	case 10:
		printf("This device is either not present, not working properly, or does not have all the drivers installed.\n");
		break;

	case 11:
		printf("Windows stopped responding while attempting to start this device, and therefore will never attempt to start this device again.\n");
		break;

	case 12:
		printf("This device cannot find any free resources to use.\n");
		break;

	case 13:
		printf("This device is either not present, not working properly, or does not have all the drivers installed.\n");
		break;

	case 14:
		printf("This device cannot work properly until you restart your computer.\n");
		break;

	case 15:
		printf("This device is causing a resource conflict.\n");
		break;

	case 16:
		printf("Windows could not identify all the resources this device uses.\n");
		break;

	case 17:
		printf("The driver information file is telling this child device to use a resource that the parent device does not have or recognize.\n");
		break;

	case 18:
		printf("The drivers for this device need to be reinstalled.\n");
		break;

	case 19:
		printf("Your registry may be bad Windows could not load one of the drivers for this device.\n");
		break;

	case 20:
		printf("Windows could not load one of the drivers for this device.\n");
		break;

	case 21:
		printf("Windows is removing this device.\n");
		break;

	case 22:
		printf("This device is disabled or This device is not started.\n");
		break;

	case 23:
		printf("This display adapter is functioning correctly. This device is not started.\n");
		break;

	case 24:
		printf("This device is either not present, not working properly, or does not have all the drivers installed.\n");
		break;

	case 25:
		printf("Windows is in the process of setting up this device.\n");
		break;

	case 26:
		printf("Windows is in the process of setting up this device. \n");
		break;

	case 27:
		printf("Windows can't specify the resources for this device.\n");
		break;

	case 28:
		printf("The drivers for this device are not installed.\n");
		break;

	case 29:
		printf("This device is disabled because the BIOS for the device did not give it any resources.\n");
		break;

	case 30:
		printf("This device is using an Interrupt Request IRQ resource that is in use by another device and cannot be shared.\n");
		break;

	case 31:
		printf("This device is not working properly because Windows cannot load the drivers required for this device.\n");
		break;

	case 32:
		printf("Windows cannot install the drivers for this device because it cannot access the drive or network location that has the setup files on it.\n");
		break;

	case 33:
		printf("This device isn't responding to its driver.\n");
		break;

	case 34:
		printf("Windows cannot determine the settings for this device.\n");
		break;

	case 35:
		printf("Your computer's system firmware does not include enough information to properly configure and use this device.\n");
		break;

	case 36:
		printf("This device is requesting a PCI interrupt but is configured for an ISA interrupt.\n");
		break;

	case 37:
		printf("Windows cannot initialize the device driver for this hardware.\n");
		break;

	case 38:
		printf("Windows cannot load the device driver for this hardware because a previous instance of the device driver is still in memory.\n");
		break;

	case 39:
		printf("Windows cannot load the device driver for this hardware The driver may be corrupted or missing.\n");
		break;

	case 40:
		printf("Windows cannot access this hardware because its service key information in the registry is missing or recorded incorrectly.\n");
		break;

	case 41:
		printf("Windows successfully loaded the device driver for this hardware but cannot find the hardware device.\n");
		break;

	case 42:
		printf("Windows cannot load the device driver for this hardware because there is a duplicate device already running in the system.\n");
		break;

	case 43:
		printf("Windows has stopped this device because it has reported problems.\n");
		break;

	case 44:
		printf("An application or service has shut down this hardware device.\n");
		break;

	case 45:
		printf("Currently, this hardware device is not connected to the computer.\n");
		break;

	case 46:
		printf("Windows cannot gain access to this hardware device because the operating system is in the process of shutting down.\n");
		break;

	case 47:
		printf("Windows cannot use this hardware device because it has been prepared for \"safe removal\", but it has not been removed from the computer.\n");
		break;

	case 48:
		printf("The software for this device has been blocked from starting because it is known to have problems with Windows.\n");
		break;

	case 49:
		printf("Windows cannot start new hardware devices because the system hive is too large exceeds the Registry Size Limit.\n");
		break;

	case 50:
		printf("Failed to apply one or more registry properties.\n");
		break;

	case 51:
		printf("This device is currently waiting on another device or set of devices to start.\n");
		break;

	case 52:
		printf("Windows cannot verify the digital signature for the drivers required for this device.\n");
		break;

	}
	return 0;
}
