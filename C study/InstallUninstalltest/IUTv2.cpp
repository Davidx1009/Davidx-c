#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <fcntl.h>
#include <io.h>
#include <sys/stat.h>
#include <setupapi.h>
#include <Cfgmgr32.h>

int flagcheck_driverinstall(void);
int flagcheck_setup(void);
void installflag(void);
void uninstallflag(void);
int startup(char *,int);
int getdevicelist();
BOOL ShowErrorMessage(UINT nMessage);

int main(int argc, char *argv[])
{
	FILE *config,*result;
	int i=0,dc=0,j=0,count=0,df,cy;
	char command[50][300],ch,folder[300],nu;
	
	 /*==============================讀取系統當下的device lise==============================*/	
	getdevicelist();
	 /*==============================讀取result 開始==============================*/	
	result=fopen("result.txt","r");
	if(result == NULL)
	result=fopen("result.txt","wt");
	char cycle[6];

	fread(cycle,sizeof(char),6,result);
	fclose(result);

		cy =atoi(cycle);
system("CLS");
		switch(flagcheck_setup())
{
	case 3:
		printf("current cycle : 1 initializing Install\n");
		cy++;
		result=fopen("result.txt","wt");
		fprintf(result,"%d",cy);
		fclose(result);
		break;
	/*安裝流程*/	
	case 1:	
	cy++;
	printf("current cycle : %d Installing driver\n",cy);
	result=fopen("result.txt","wt");
	fprintf(result,"%d",cy);
	fclose(result);
	break;
	/*反安裝流程*/
	case 2:
	printf("current cycle : %d Uninstalling driver\n",cy);
}
	count =0;
                                   /*==============================讀取config 開始==============================*/	
	config=fopen("config.txt","rb");
		while((ch=getc(config)) != EOF)
	{	
		count++; /*取得所需空間*/
	}
	fclose(config);
	config=fopen("config.txt","rb");
	char dp[count];
	while(!feof(config))
	{
	fread(dp,sizeof(char),count,config);
	}
	fclose(config);
	
		/*初始需要自己輸入初值*/
	if(argv[1] == NULL)
	{
	printf("how many driver you would like to install?");
	scanf("%d",&df);
	}
	else
	{
		df =atoi(argv[1]);
	}
	
/*把IUT tool安裝路徑抓出來放*/
		j=13;
		while(dp[j] != '\"')
		{
				if(dp[j]== ' ')/*資料夾有空格的對策*/
				{
					command[dc][i]='\"';
					command[dc][i+1]= dp[j];
					command[dc][i+2]='\"';
					i+=2;
				}
				else
		command[dc][i]= dp[j]; 
		j++;
		i++;
		
		}
		command[dc][i] = '\0'; /*在字串結尾加上空字符(\0)確保不會讀到亂碼,(未加前會讀到)*/
		dc++;
		j+=15;
/*把install driver 的執行指令抓出來分開放*/
	while(dc<(df*2+1))
	{ 	i=0;
	
		/*抓取執行指令的路徑*/
			while(dp[j] != '\"')
			{
				if(dp[j]== ' ')
				{
					command[dc][i]='\"';
					command[dc][i+1]= dp[j];
					command[dc][i+2]='\"';
					i+=2;
				}
				else
				command[dc][i]= dp[j]; 
			j++;
			i++;
		
			}
			command[dc][i] = '\0'; 
		
		j+=15;
		dc++;
		/*抓取執行指令*/
		i=0;
		while(dp[j] != '\"')
			{	/*拿掉空格對策避免引值誤加*/
			command[dc][i]= dp[j]; 
			j++;
			i++;
		
			}
			command[dc][i] = '\0'; 

		j+=15;
		dc++;
			
	}
/*把uninstall driver 的執行指令抓出來分開放*/
	j+=2;
	while(dc<((df*4)+1))
	{ 	i=0;

		/*抓取執行指令的路徑*/
			while(dp[j] != '\"')
			{
				if(dp[j]== ' ')
				{
					command[dc][i]='\"';
					command[dc][i+1]= dp[j];
					command[dc][i+2]='\"';
					i+=2;
				}
				else
				command[dc][i]= dp[j]; 
			j++;
			i++;
		
			}
			command[dc][i] = '\0'; 

		j+=15;
		dc++;
		/*抓取執行指令*/
		i=0;
		while(dp[j] != '\"')
			{	/*拿掉空格對策避免引值誤加*/
			command[dc][i]= dp[j]; 
			j++;
			i++;
		
			}
			command[dc][i] = '\0'; 

		j+=17;
		dc++;		
	}
/* 抓取的數目跟路徑
 
	for(i=0;i<dc;i++)
	{	printf("%d\n",i);
		printf("%s\n",command[i]);
	}*/
                                              /*==============================讀取config 結束==============================*/	
	
	
	switch(flagcheck_setup())
{
	
	case 3:

	startup(command[0],df);
	system("pause");
	
	/*安裝流程*/
	case 1:
	printf("============================install process starting.============================\n");
	Sleep(5000);
	for(i=1;i<(dc/2)+1;i++)
	{
	printf("%s%s\n",command[i],command[i+1]);
	sprintf(folder, "%s%s", command[i],command[i+1]);
	system(folder);
	i++;
	flagcheck_driverinstall();
	}	
	printf("install process finish.\ngoing to do restart.\n");
	Sleep(1000);
	sprintf(folder, "cd %s", command[0]);
	system("erase /f /q INSTALL.FLG");
	system(folder);
	uninstallflag();
	for(i=0;i<10;i++)
	{
		printf("%d...\n",i);
		Sleep(1000);
	}
	system("shutdown /r");
	break;
	/*反安裝流程*/
	case 2:
	printf("============================uninstall process starting.============================\n");
	Sleep(5000);
	for(i=(1+dc/2);i<dc+1;i++)
	{
	printf("%s%s\n",command[i],command[i+1]);
	sprintf(folder, "%s%s", command[i],command[i+1]);
	system(folder);
	i++;
	flagcheck_driverinstall();
	}		
	printf("uninstall process finish.\ngoing to do restart.\n");
	Sleep(1000);
	sprintf(folder, "cd %s", command[0]);
	system(folder);
	system("erase /f /q UNINSTALL.FLG");
	installflag();
	for(i=0;i<10;i++)
	{
		printf("%d...\n",i);
		Sleep(1000);
	}
	system("shutdown /r");
}
	return 0;
	
 } 
 /*===========Driver 等待機制==============*/
 int flagcheck_driverinstall()
 {	
	system("EXIT /B \%ERRORLEVEL\%");
 }

 /*===========check 要install還是 uninstall==============*/
 int flagcheck_setup()
 {	
 	FILE *flag;
 	flag=fopen("INSTALL.FLG","rb");
 	if(flag != NULL)
 	{fclose(flag);
	return 1;	
	}	
	flag=fopen("UNINSTALL.FLG","rb");
 	if(flag != NULL)
 	{fclose(flag);
	return 2;	
	}
	fclose(flag);
	return 3;
 }
  /*===========製作flag 斷點==============*/
 void installflag()
 {	
 	int flag1;
 	flag1=creat("INSTALL.FLG",S_IWRITE);
 	close(flag1);
 }
  void uninstallflag()
 {	int flag2;
 	flag2=creat("UNINSTALL.FLG",S_IWRITE);
 	close(flag2);
 }
 
/*===========startup 迴圈準備 在startup folder 做出bat檔讓系統可以在restart後自動執行IUT.exe==============*/
int startup(char *start,int a)
{	
FILE *f1;
char b[10],e;
int i=strlen(start);
f1=fopen("IUT.bat","wt");
fprintf(f1,"cd %s",start);
fprintf(f1,"\nIUTV1.exe %d",a);
fclose(f1);

system("xcopy IUT.bat \"C:\\ProgramData\\Microsoft\\Windows\\Start Menu\\Programs\\StartUp\" /y");

}
/*===========抓取device list==============*/
int getdevicelist()
{	HDEVINFO devlist;
	SP_DEVINFO_DATA devinfo;
	DWORD regdataname,regdataid;

	DWORD devstatus,devcode;
	
	int i;

	devlist = SetupDiGetClassDevs(NULL, NULL, NULL, DIGCF_ALLCLASSES | DIGCF_PRESENT);
	if(devlist != INVALID_HANDLE_VALUE )
	{
		printf("get dev list success\n");
		system("pause");
	}
	devinfo.cbSize = sizeof(SP_DEVINFO_DATA);
	for(i=0;SetupDiEnumDeviceInfo(devlist,i,&devinfo);i++)
	{	PBYTE devhwname=NULL,devhwid=NULL;
		DWORD buffername=0,bufferid=0;
		//取得device name 
		while (!SetupDiGetDeviceRegistryPropertyA(devlist,&devinfo,SPDRP_DEVICEDESC,&regdataname,devhwname,buffername,&buffername))
		{		//printf("%d\n",GetLastError());
				if (GetLastError() == ERROR_INSUFFICIENT_BUFFER)
			{
				//對應資料大小更改buffer 的大小 
				if (devhwname) LocalFree(devhwname);
				{
				devhwname =(PBYTE) LocalAlloc(LPTR, buffername * 2);
				}
	
			}
			else
				break;
	
			
		}
			//sprintf(szDEVName, "%s", devhwname);
			//	printf("%s\n", devhwname);
			//取得device ID
				while (!SetupDiGetDeviceRegistryPropertyA(devlist,&devinfo,SPDRP_HARDWAREID,&regdataid,devhwid,bufferid,&bufferid))
		{	
				if (GetLastError() == ERROR_INSUFFICIENT_BUFFER)
			{
				//對應資料大小更改buffer 的大小
				if (devhwid) LocalFree(devhwid);
				devhwid =(PBYTE) LocalAlloc(LPTR, bufferid * 2);
			
			}
			else
				break;
		
		}
			//sprintf(szDEVName, "%s", devhwname);
		//	printf("%s\n", devhwid);
		
		CM_Get_DevNode_Status(&devstatus, &devcode, devinfo.DevInst, 0);
		if (devstatus & DN_HAS_PROBLEM)
		{
			printf("%s, %s has problem:Error code %d ", devhwname, devhwid, devcode);
			ShowErrorMessage(devcode);
		}
		else
			printf("%s, %s is running.\n", devhwname, devhwid);

		if (devhwname) LocalFree(devhwname);
		if (devhwid) LocalFree(devhwid);

	}
				//清除抓取devlist所佔用的memory// 
			SetupDiDestroyDeviceInfoList(devlist);
				system("pause");
		
		 

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
 
 
