//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------
USEFORM("DM.cpp", CustomerData); /* TDataModule: File Type */
USEFORM("Main.cpp", MainForm);
USEFORM("ChildWin.cpp", MDIChild);
USEFORM("about.cpp", AboutBox);
USEFORM("UnitAnalisys.cpp", FormCondition);
USEFORM("UnitInFields.cpp", FormINFields);
USEFORM("UnitOutFields.cpp", FormOUTFields);
USEFORM("UnitQuickRepIN.cpp", FormQuickRepIN);
USEFORM("UnitQuickRepOUT.cpp", FormQuickRepOUT);
USEFORM("UnitKZO.cpp", FormKZO);
USEFORM("UnitGrid.cpp", FormGrid);
USEFORM("UnitKZO2.cpp", FormKZO2);
USEFORM("UnitDayMonthYear.cpp", FormDayMonthYear);
USEFORM("UnitMonthYear.cpp", FormMonthYear);
USEFORM("ChildWin2.cpp", MDIChild2);
USEFORM("UnitDMY_32.cpp", FormDMY_32);
USEFORM("UnitDayMonthYear1.cpp", FormDayMonthYear1);
USEFORM("Unit2.cpp", FormDayMonthYear2);
USEFORM("StatisticData.cpp", StatDateForm);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	Application->Initialize();
	Application->CreateForm(__classid(TMainForm), &MainForm);
                 Application->CreateForm(__classid(TAboutBox), &AboutBox);
                 Application->CreateForm(__classid(TFormCondition), &FormCondition);
                 Application->CreateForm(__classid(TFormINFields), &FormINFields);
                 Application->CreateForm(__classid(TFormOUTFields), &FormOUTFields);
                 Application->CreateForm(__classid(TFormQuickRepIN), &FormQuickRepIN);
                 Application->CreateForm(__classid(TFormQuickRepOUT), &FormQuickRepOUT);
                 Application->CreateForm(__classid(TFormKZO), &FormKZO);
                 Application->CreateForm(__classid(TFormGrid), &FormGrid);
                 Application->CreateForm(__classid(TFormKZO2), &FormKZO2);
                 Application->CreateForm(__classid(TFormDayMonthYear), &FormDayMonthYear);
                 Application->CreateForm(__classid(TFormMonthYear), &FormMonthYear);
                 Application->CreateForm(__classid(TFormDMY_32), &FormDMY_32);
                 Application->CreateForm(__classid(TFormDayMonthYear1), &FormDayMonthYear1);
                 Application->CreateForm(__classid(TFormDayMonthYear2), &FormDayMonthYear2);
                 Application->CreateForm(__classid(TStatDateForm), &StatDateForm);
                 Application->CreateForm(__classid(TCustomerData), &CustomerData);
                 Application->Run();

	return 0;
}
//---------------------------------------------------------------------
