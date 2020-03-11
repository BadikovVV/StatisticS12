//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------
USEFORM("about.cpp", AboutBox);
USEFORM("ChildWin.cpp", MDIChild);
USEFORM("Main.cpp", MainForm);
USEFORM("UnitKZO.cpp", FormKZO);
USEFORM("DM.cpp", CustomerData); /* TDataModule: File Type */
USEFORM("StatisticData.cpp", StatDateForm);
USEFORM("UnitAnalisys.cpp", FormCondition);
USEFORM("UnitDayMonthYear.cpp", FormDayMonthYear);
USEFORM("UnitDayMonthYear1.cpp", FormDayMonthYear1);
USEFORM("UnitDMY_32.cpp", FormDMY_32);
USEFORM("UnitGrid.cpp", FormGrid);
USEFORM("UnitInFields.cpp", FormINFields);
USEFORM("UnitKZO2.cpp", FormKZO2);
USEFORM("UnitMonthYear.cpp", FormMonthYear);
USEFORM("UnitOutFields.cpp", FormOUTFields);
USEFORM("UnitQuickRep.cpp", FormQuickRep);
USEFORM("UnitQuickRepIN.cpp", FormQuickRepIN);
USEFORM("UnitQuickRepOUT.cpp", FormQuickRepOUT);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	Application->Initialize();
	Application->CreateForm(__classid(TMainForm), &MainForm);
		Application->CreateForm(__classid(TAboutBox), &AboutBox);
		Application->CreateForm(__classid(TFormKZO), &FormKZO);
		Application->CreateForm(__classid(TCustomerData), &CustomerData);
		Application->CreateForm(__classid(TStatDateForm), &StatDateForm);
		Application->CreateForm(__classid(TFormCondition), &FormCondition);
		Application->CreateForm(__classid(TFormDayMonthYear), &FormDayMonthYear);
		Application->CreateForm(__classid(TFormDayMonthYear1), &FormDayMonthYear1);
		Application->CreateForm(__classid(TFormDMY_32), &FormDMY_32);
		Application->CreateForm(__classid(TFormGrid), &FormGrid);
		Application->CreateForm(__classid(TFormINFields), &FormINFields);
		Application->CreateForm(__classid(TFormKZO2), &FormKZO2);
		Application->CreateForm(__classid(TFormMonthYear), &FormMonthYear);
		Application->CreateForm(__classid(TFormOUTFields), &FormOUTFields);
		Application->CreateForm(__classid(TFormQuickRep), &FormQuickRep);
		Application->CreateForm(__classid(TFormQuickRepIN), &FormQuickRepIN);
		Application->CreateForm(__classid(TFormQuickRepOUT), &FormQuickRepOUT);
		Application->Run();
	return 0;
}
//---------------------------------------------------------------------
