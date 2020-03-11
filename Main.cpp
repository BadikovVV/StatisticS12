//---------------------------------------------------------------------------
// Statistic for station S12
//                  2.16  Приложение 3.2
//                  2.15  Формы статистики
//                  2.142 PABX
//                  2.141 формы 4,5 ежедневно
//          Version 2.14  добавлен Экспорт в Excel
//          Version 2.13  потери вызовов (из таблицы maket_out, outgoing_traffic)
//                        потери в ЧНН (не учитывать TT_AUT_DMI_DTG
//          Version 2.12  потери вызовов (из таблицы outgoing_traffic)
//          Version 2.11  определение ЧНН, откорретированы формы, Add Offd (в Печати исходящих)
//          Version 2.0   потреи в ЧНН станции (2005 год)
//          version 1.9.4 (расчет КЗО за месяц+среднее по всем дням+
//                          сортировка по категориям магист., зона, атс)
//              2004  2005
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "utilcls.h"  // добавлено для Экспорта в  Excel
//#include "Sysutils.hpp" // добавлено 19.10.05 для FloatToStr
#include <inifiles.hpp>
#include <stdlib.h>
#include <stdio.h>

#include "Main.h"
#include "About.h"
#include "UnitAnalisys.h"
#include "ChildWin.h"
#include "StatisticData.h"
#include "UnitInFields.h"
#include "UnitOutFields.h"
#include "UnitQuickRep.h"
#include "UnitQuickRepIN.h"
#include "UnitQuickRepOUT.h"
#include "UnitGrid.h"
#include "UnitKZO.h"
#include "UnitMonthYear.h"
#include "UnitDayMonthYear.h"
#include "ChildWin2.h"
#include "UnitDMY_32.h"
#include "UnitDayMonthYear1.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TMainForm *MainForm;

Variant FX,v0,v1,v2;  // для экспорта в Excel

char sqls[1600];
char sqls2[1300];        // строка запроса для расчета КИС
//AnsiString str_fields[290];
char fields_IN[600];
char fields_OUT[660];

char fields_toPABX[500];
char fields_fromPABX[500];

AnsiString ProgrammPath;
AnsiString BDName,BDServer,BDUser,BDPassword;

TStringList* S12IN = new TStringList();
TStringList* S12OUT = new TStringList();

TStringList* S12fromPABX = new TStringList();
TStringList* S12toPABX = new TStringList();


char ListDirection[850]; // список направлений
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent *Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
//void TMeasure::book_direction(int num,char* fieldname);
//void in_out_menu(int num);
//void Select(char* derection,char* fields);

void __fastcall TMainForm::CreateMDIChild(String Name)
{
	TMDIChild *Child;
	//--- create a new MDI child window ----
	Child = new TMDIChild(Application);
	Child->Caption = Name+" => "+
                      Child->StatusBar1->Panels->Items[0]->Text+
                      Child->StatusBar1->Panels->Items[1]->Text+" "+
                      Child->StatusBar1->Panels->Items[2]->Text+
                      Child->StatusBar1->Panels->Items[3]->Text+" "+
                      Child->StatusBar1->Panels->Items[4]->Text+
                      Child->StatusBar1->Panels->Items[5]->Text+" "+
                      Child->StatusBar1->Panels->Items[6]->Text+
                      Child->StatusBar1->Panels->Items[7]->Text;
//        Child->DBGrid1->DataSource->DataSet->FieldByName("Seiz/Answer")->AsFloat=150;
//        Child->DBGrid1->Columns->Items[1]->Width=90;
//        Child->DBGrid1->Columns->Items[2]->Width=90;
}
void __fastcall TMainForm::CreateMDIChildP(String Name)
{
	TMDIChild2 *Child;
	//--- create a new MDI child window ---- for PABX
	Child = new TMDIChild2(Application);
	Child->Caption = Name+" => "+
                      Child->StatusBar1->Panels->Items[0]->Text+
                      Child->StatusBar1->Panels->Items[1]->Text+" "+
                      Child->StatusBar1->Panels->Items[2]->Text+
                      Child->StatusBar1->Panels->Items[3]->Text+" "+
                      Child->StatusBar1->Panels->Items[4]->Text+
                      Child->StatusBar1->Panels->Items[5]->Text+" "+
                      Child->StatusBar1->Panels->Items[6]->Text+
                      Child->StatusBar1->Panels->Items[7]->Text;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FileNew1Execute(TObject *Sender)
{
//	CreateMDIChild("NONAME" + IntToStr(MDIChildCount + 1));
        FormCondition->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FileOpen1Execute(TObject *Sender)
{
//	if (OpenDialog->Execute())
//		CreateMDIChild(OpenDialog->FileName);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::HelpAbout1Execute(TObject *Sender)
{
	AboutBox->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FileExit1Execute(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N6IN_MagistralClick(TObject *Sender)
{
    MenuItem(1,"IN");
//    FormQuickRep->QuickRep1->Preview();

//    book_direction(1,"mnemo_i");
//    FormCondition->Caption="Магистраль. Анализ входящих направлений";
//    in_out_menu(1);
//    if (FormCondition->ShowModal()==mrOk)
//    {
 //       Select("inc_tkg",fields_IN);
//        CreateMDIChild(FormCondition->Caption);
  //  }
}
//---------------------------------------------------------------------------

void TMeasure::book_direction(int num, char* fieldname)
{
// открытие таблицы s12_book
  // сортировка
  CustomerData->QueryBook->Close();
  CustomerData->QueryBook->SQL->Clear();
  CustomerData->QueryBook->SQL->Add("select * from s12_book2 order by ");
  CustomerData->QueryBook->SQL->Add(fieldname);
  CustomerData->QueryBook->Open();
  FormCondition->ComboBoxDirection->Clear();
  CustomerData->QueryBook->First();
  ListDirection[0]='\0';
  strcpy(ListDirection,"(");
  while (!CustomerData->QueryBook->Eof)
  {
         if(CustomerData->QueryBook->FieldByName("order_")->AsInteger==num &&
            CustomerData->QueryBook->FieldByName(fieldname)->AsString!="")
         {
              FormCondition->ComboBoxDirection->Items->Add(
                CustomerData->QueryBook->FieldByName(fieldname)->AsString);
              // заполнение списка нименований направлений ListDirection
              if(strlen(ListDirection)>2) strcat(ListDirection,",");
              strcat(ListDirection,"'");
              strcat(ListDirection,
               CustomerData->QueryBook->FieldByName(fieldname)->AsString.c_str());
              strcat(ListDirection,"'");
         }
         CustomerData->QueryBook->Next();
  }
  FormCondition->ComboBoxDirection->ItemIndex=0;
  strcat(ListDirection,")");
}

void TMeasure::in_out_menu(int num)
{
  if(num==1) // ВХОДЯЩИЕ
  {
    FormCondition->ComboBoxFields->Clear();
    FormCondition->ComboBoxFields->Items->Add("[ANSWER%SEIZ]");
    FormCondition->ComboBoxFields->Items->Add("AVLB_OCC");
    FormCondition->ComboBoxFields->Items->Add("CALLS");
    FormCondition->ComboBoxFields->Items->Add("SEIZ");
    FormCondition->ComboBoxFields->Items->Add("INJECTIONS");
    FormCondition->ComboBoxFields->Items->Add("RETRIES");
    FormCondition->ComboBoxFields->Items->Add("ANSWER");
    FormCondition->ComboBoxFields->Items->Add("[SEIZ/ANSWER]");
//    FormCondition->ComboBoxFields->Items->Add("[ANSWER%SEIZ]"); перемещено на первую позицию 11.08.04
    FormCondition->ComboBoxFields->Items->Add("CD_BUSY");
    FormCondition->ComboBoxFields->Items->Add("[CD_BUSY%SEIZ]");
    FormCondition->ComboBoxFields->Items->Add("NO_ANSWER");
    FormCondition->ComboBoxFields->Items->Add("[NO_ANSWER%SEIZ]");
    FormCondition->ComboBoxFields->Items->Add("NO_SIG_FRL");
    FormCondition->ComboBoxFields->Items->Add("NO_SIG_OVL");
    FormCondition->ComboBoxFields->Items->Add("[NO_SIG_OVL%SEIZ]");
    FormCondition->ComboBoxFields->Items->Add("PSIG_CLF");
    FormCondition->ComboBoxFields->Items->Add("PSIG_FRL");
    FormCondition->ComboBoxFields->Items->Add("INVC");
    FormCondition->ComboBoxFields->Items->Add("REJ_FOR_NM");
    FormCondition->ComboBoxFields->Items->Add("OGREJ_NART");
    FormCondition->ComboBoxFields->Items->Add("DSN_BLK");
    FormCondition->ComboBoxFields->Items->Add("CONG_DIST");
    FormCondition->ComboBoxFields->Items->Add("FRL_DIST");
    FormCondition->ComboBoxFields->Items->Add("INVC_DIST");
    FormCondition->ComboBoxFields->Items->Add("OTHER_FAIL");
    FormCondition->ComboBoxFields->Items->Add("REDIRECTED");
    FormCondition->ComboBoxFields->Items->Add("SU_SY_CALL");
    FormCondition->ComboBoxFields->Items->Add("CALL_RE_OV");
    FormCondition->ComboBoxFields->Items->Add("OCC");
    FormCondition->ComboBoxFields->Items->Add("KIS");
    FormCondition->ComboBoxFields->Items->Add("OCC_N7");
    FormCondition->ComboBoxFields->Items->Add("CHCONV_OCC");
    FormCondition->ComboBoxFields->Items->Add("[CHCONV%OCC]");
    FormCondition->ComboBoxFields->Items->Add("DIFO");
    FormCondition->ComboBoxFields->Items->Add("DIFA");
  }
  if(num==2)
  {           // ИСХОДЯЩИЕ
    FormCondition->ComboBoxFields->Clear();
    FormCondition->ComboBoxFields->Items->Add("[ANSWER%SEIZ]");
    FormCondition->ComboBoxFields->Items->Add("OFFD");
    FormCondition->ComboBoxFields->Items->Add("SEIZ");
    FormCondition->ComboBoxFields->Items->Add("ANSWER");
    FormCondition->ComboBoxFields->Items->Add("[SEIZ/ANSWER]");
//  FormCondition->ComboBoxFields->Items->Add("[ANSWER%SEIZ]"); перемещено на первую позицию
    FormCondition->ComboBoxFields->Items->Add("CD_BUSY");
    FormCondition->ComboBoxFields->Items->Add("[CD_BUSY%SEIZ]");
    FormCondition->ComboBoxFields->Items->Add("NO_ANSWER");
    FormCondition->ComboBoxFields->Items->Add("[NO_ANSWER%SEIZ]");
    FormCondition->ComboBoxFields->Items->Add("OFFD_ATG");
    FormCondition->ComboBoxFields->Items->Add("[OFFD_ATG%OFFD]");
    FormCondition->ComboBoxFields->Items->Add("REJ_NART");
    FormCondition->ComboBoxFields->Items->Add("[REJ_NART%OFFD]");
    FormCondition->ComboBoxFields->Items->Add("INVC");
    FormCondition->ComboBoxFields->Items->Add("PSIG");
    FormCondition->ComboBoxFields->Items->Add("CONG_DIST");
    FormCondition->ComboBoxFields->Items->Add("FRL_DIST");
    FormCondition->ComboBoxFields->Items->Add("INVC_DIST");
    FormCondition->ComboBoxFields->Items->Add("OTHER_FAIL");
    FormCondition->ComboBoxFields->Items->Add("CALL_RE_NM");
    FormCondition->ComboBoxFields->Items->Add("CLASH");
    FormCondition->ComboBoxFields->Items->Add("COC_FAIL");
    FormCondition->ComboBoxFields->Items->Add("DSN_BLK");
    FormCondition->ComboBoxFields->Items->Add("OCC");
    FormCondition->ComboBoxFields->Items->Add("KIS");
    FormCondition->ComboBoxFields->Items->Add("OCC_N7");
    FormCondition->ComboBoxFields->Items->Add("CHCONV_OCC");
    FormCondition->ComboBoxFields->Items->Add("[CHCONV%OCC]");
    FormCondition->ComboBoxFields->Items->Add("DIFO");
    FormCondition->ComboBoxFields->Items->Add("DIFA");
  }

  FormCondition->ComboBoxFields->ItemIndex=0;
  FormCondition->ComboBox3->ItemIndex=0;
  FormCondition->ComboBox4->ItemIndex=0;

}

// ======
void TPABX::in_out_menu(int num)
{
  if(num==3) // от PABX
  {
    FormCondition->ComboBoxFields->Clear();
    FormCondition->ComboBoxFields->Items->Add("O_CALLS");
    FormCondition->ComboBoxFields->Items->Add("O_C_INJECT");
    FormCondition->ComboBoxFields->Items->Add("O_C_RETRIE");
    FormCondition->ComboBoxFields->Items->Add("O_ANSW");
    FormCondition->ComboBoxFields->Items->Add("[O_ANSW%O_CALLS]");
    FormCondition->ComboBoxFields->Items->Add("O_CD_BSY");
    FormCondition->ComboBoxFields->Items->Add("[O_CD_BSY%O_CALLS]");
    FormCondition->ComboBoxFields->Items->Add("O_NO_ANSW");
    FormCondition->ComboBoxFields->Items->Add("[O_NO_ANSW%O_CALLS]");
    FormCondition->ComboBoxFields->Items->Add("O_NSIG_FRL");
    FormCondition->ComboBoxFields->Items->Add("O_NSIG_CLF");
    FormCondition->ComboBoxFields->Items->Add("O_PSIG_CLF");
    FormCondition->ComboBoxFields->Items->Add("O_PSIG_FRL");
    FormCondition->ComboBoxFields->Items->Add("O_INVC");
    FormCondition->ComboBoxFields->Items->Add("O_B_CONG");
    FormCondition->ComboBoxFields->Items->Add("O_CNG_DIST");
    FormCondition->ComboBoxFields->Items->Add("O_FRL_DIST");
    FormCondition->ComboBoxFields->Items->Add("O_INVC_DST");
    FormCondition->ComboBoxFields->Items->Add("O_OTH_FAIL");
    FormCondition->ComboBoxFields->Items->Add("O_SUCC_SYS");
    FormCondition->ComboBoxFields->Items->Add("O_OCC");
    FormCondition->ComboBoxFields->Items->Add("O_CONV_OCC");
    FormCondition->ComboBoxFields->Items->Add("O_REDIRECT");
    FormCondition->ComboBoxFields->Items->Add("O_B_CONG");

  }
  if(num==4)
  {           // к PABX
    FormCondition->ComboBoxFields->Clear();
    FormCondition->ComboBoxFields->Items->Add("T_CALL_ATT");
    FormCondition->ComboBoxFields->Items->Add("T_ANSW");
    FormCondition->ComboBoxFields->Items->Add("[T_ANSW%T_CALL_ATT]");
    FormCondition->ComboBoxFields->Items->Add("T_CD_BSY");
    FormCondition->ComboBoxFields->Items->Add("[T_CD_BSY%T_CALL_ATT]");
    FormCondition->ComboBoxFields->Items->Add("T_NO_ANSW");
    FormCondition->ComboBoxFields->Items->Add("[T_NO_ANSW%T_CALL_ATT]");
    FormCondition->ComboBoxFields->Items->Add("T_CONG");
    FormCondition->ComboBoxFields->Items->Add("[T_CONG%T_CALL_ATT]");
    FormCondition->ComboBoxFields->Items->Add("T_PSIG_CLF");
    FormCondition->ComboBoxFields->Items->Add("T_PSIG_FRL");
    FormCondition->ComboBoxFields->Items->Add("T_OTH_FAIL");
    FormCondition->ComboBoxFields->Items->Add("T_OCC");
    FormCondition->ComboBoxFields->Items->Add("T_CONV_OCC");
  }

//O_CALLS     O_C_INJECT  O_C_RETRIE  O_ANSW      O_CD_BSY    O_NO_ANSW   O_SUCC_SYS
//  O_NSIG_CLF  O_NSIG_FRL  O_PSIG_CLF  O_PSIG_FRL  O_INVC      O_REDIRECT  O_B_CONG
//  O_CNG_DIST  O_FRL_DIST  O_INVC_DST  O_OTH_FAIL  O_OCC       O_CONV_OCC
// T_CALL_ATT  T_ANSW      T_CD_BSY    T_NO_ANSW   T_CONG      T_PSIG_CLF  T_PSIG_FRL
// T_OTH_FAIL  T_OCC       T_CONV_OCC  O_ANSW%O_CALLS O_CD_BSY%O_CALLS O_NO_ANSW%O_CALLS
// T_ANSW%T_CALL_ATT T_CD_BSY%T_CALL_ATT T_NO_ANSW%T_CALL_ATT T_CONG%T_CALL_ATT

  FormCondition->ComboBoxFields->ItemIndex=0;
  FormCondition->ComboBox3->ItemIndex=0;
  FormCondition->ComboBox4->ItemIndex=0;

}

void TPABX::Select(char* direction, char* fields)
{
char str[3];
     strcpy(sqls,"select distinct ");
//        strcat(sqls,"b.inc, ");
     strcat(sqls,fields);
     if(strcmp(direction,"inc_tkg")==0)
     {
     // ,round((t_occ+o_occ)/b.inc*100,2) as KIS
         strcat(sqls," from ACTIVATE_PPXGRP_REPORT_all a (index=ic_data), s12_book2 b where ");
         strcat(sqls,"a.inc_tkg=b.mnemo_i and ");
     }
     if(strcmp(direction,"out_tkg")==0)
     {
//       strcat(sqls," from maket_out (index=ic_data) where ");
         strcat(sqls," from ACTIVATE_PPXGRP_REPORT_all a (index=ic_data), s12_book2 b where ");
         strcat(sqls,"a.inc_tkg=b.mnemo_o and ");
      }
     // Дата
     strcat(sqls," data between '");
     strcat(sqls,FormatDateTime("yyyy-mm-dd",FormCondition->DateTimePicker1->Date).c_str() );
     strcat(sqls,"' and '");
     strcat(sqls,FormatDateTime("yyyy-mm-dd",FormCondition->DateTimePicker2->Date).c_str() );
     strcat(sqls,"' and ");
     strcat(sqls,"t_begin >= '");
     // Время
     itoa(FormCondition->CSpinEdit1->Value,str,10);
     if(FormCondition->CSpinEdit1->Value < 10) strcat(sqls,"0");
     strcat(sqls,str); strcat(sqls,":00' and t_end<='");
     itoa(FormCondition->CSpinEdit2->Value,str,10);
     if(FormCondition->CSpinEdit2->Value < 10) strcat(sqls,"0");
     strcat(sqls,str); strcat(sqls,":00' ");
     // Если выбрали  одно направление
     if(FormCondition->RB1Direction->Checked)
     {
      strcat(sqls,"and "); strcat(sqls,direction); strcat(sqls,"='");
      strcat(sqls,FormCondition->ComboBoxDirection->Text.c_str() );
      strcat(sqls,"' ");
     }
     // Если есть условия отбора
     if(FormCondition->RBCondition->Checked)
     {
      strcat(sqls," and "); //[
      strcat(sqls,FormCondition->ComboBoxFields->Text.c_str() );
      strcat(sqls," ");  //]
      strcat(sqls,FormCondition->ComboBox3->Text.c_str() );
      strcat(sqls,FormCondition->ComboBox4->Text.c_str() );
     }
     if(FormCondition->RBAllDirection->Checked)
     {
          strcat(sqls," and ");
          strcat(sqls, "inc_tkg"); strcat(sqls," in ");
          strcat(sqls,ListDirection);
     }
     strcat(sqls," order by ");
     strcat(sqls,"inc_tkg");
     strcat(sqls," ,data, t_begin");
     // -------------------------------------------
     // Формирование строки sqls2 - для расчета КИС
     // -------------------------------------------

}


//=====

void TMeasure::Select(char* direction, char* fields)
{
char str[3];
     strcpy(sqls,"select distinct ");
     strcat(sqls,fields);
//    ShowMessage(sqls);
     if(strcmp(direction,"inc_tkg")==0)
     {
         strcat(sqls," from maket_inc a (index=ic_data), s12_book2 b where ");
         strcat(sqls,"a.inc_tkg=b.mnemo_i and ");
     }
     else
     {
//       strcat(sqls," from maket_out (index=ic_data) where ");
         strcat(sqls," from maket_out a (index=ic_data), s12_book2 b where ");
         strcat(sqls,"a.out_tkg=b.mnemo_o and ");
      }
     // Дата
     strcat(sqls," data between '");
     strcat(sqls,FormatDateTime("yyyy-mm-dd",FormCondition->DateTimePicker1->Date).c_str() );
     strcat(sqls,"' and '");
     strcat(sqls,FormatDateTime("yyyy-mm-dd",FormCondition->DateTimePicker2->Date).c_str() );
     strcat(sqls,"' and ");
     strcat(sqls,"t_begin >= '");
     // Время
     itoa(FormCondition->CSpinEdit1->Value,str,10);
     if(FormCondition->CSpinEdit1->Value < 10) strcat(sqls,"0");
     strcat(sqls,str); strcat(sqls,":00' and t_end<='");
     itoa(FormCondition->CSpinEdit2->Value,str,10);
     if(FormCondition->CSpinEdit2->Value < 10) strcat(sqls,"0");
     strcat(sqls,str); strcat(sqls,":00' ");
     // Если выбрали  одно направление
     if(FormCondition->RB1Direction->Checked)
     {
      strcat(sqls,"and "); strcat(sqls,direction); strcat(sqls,"='");
      strcat(sqls,FormCondition->ComboBoxDirection->Text.c_str() );
      strcat(sqls,"' ");
     }
     // Если есть условия отбора
     if(FormCondition->RBCondition->Checked)
     {
      strcat(sqls," and "); //[
      strcat(sqls,FormCondition->ComboBoxFields->Text.c_str() );
      strcat(sqls," ");  //]
      strcat(sqls,FormCondition->ComboBox3->Text.c_str() );
      strcat(sqls,FormCondition->ComboBox4->Text.c_str() );
      // если [ANSWER%SEIZ] то добавляем условие SEIZ > 0
        if(strcmp(FormCondition->ComboBoxFields->Text.c_str(),"[ANSWER%SEIZ]")==0)
        {
             strcat(sqls," and SEIZ>0 ");
        }
     }
     if(FormCondition->RBAllDirection->Checked)
     {
          strcat(sqls," and ");
          strcat(sqls, direction); strcat(sqls," in ");
          strcat(sqls,ListDirection);
     }
     strcat(sqls," order by ");
     strcat(sqls,direction);
     strcat(sqls," ,data, t_begin");
     
     // -------------------------------------------
     // Формирование строки sqls2 - для расчета КИС
     // -------------------------------------------
       strcpy(sqls2,"select data, t_begin, t_end, occ,");
           // (выбор OCC из противоположного направления)
       if(strcmp(direction,"inc_tkg")==0)
         strcat(sqls2," out_tkg from maket_out (index=ic_data) where ");
       else
         strcat(sqls2," inc_tkg from maket_inc (index=ic_data) where ");
       // Дата
       strcat(sqls2," data between '");
       strcat(sqls2,FormatDateTime("yyyy-mm-dd",FormCondition->DateTimePicker1->Date).c_str() );
       strcat(sqls2,"' and '");
       strcat(sqls2,FormatDateTime("yyyy-mm-dd",FormCondition->DateTimePicker2->Date).c_str() );
       strcat(sqls2,"' and ");
       strcat(sqls2,"t_begin >= '");
       // Время
       itoa(FormCondition->CSpinEdit1->Value,str,10);
       if(FormCondition->CSpinEdit1->Value < 10) strcat(sqls2,"0");
       strcat(sqls2,str); strcat(sqls2,":00' and t_end<='");
       itoa(FormCondition->CSpinEdit2->Value,str,10);
       if(FormCondition->CSpinEdit2->Value < 10) strcat(sqls2,"0");
       strcat(sqls2,str); strcat(sqls2,":00' ");
       // Если выбрали  одно направление
       if(FormCondition->RB1Direction->Checked)
       {
         if(strcmp(direction,"inc_tkg")==0)
         {
           strcat(sqls2,"and "); strcat(sqls2,"out_tkg"); strcat(sqls2,"='");
           strcat(sqls2,FormCondition->ComboBoxDirection->Text.c_str() );
           strcat(sqls2,"' ");
         }
         else
         {
           strcat(sqls2,"and "); strcat(sqls2,"inc_tkg"); strcat(sqls2,"='");
           strcat(sqls2,FormCondition->ComboBoxDirection->Text.c_str() );
           strcat(sqls2,"' ");
         }
       }
     if(FormCondition->RBAllDirection->Checked)
     {
          strcat(sqls2,"and ");
          if(strcmp(direction,"inc_tkg")==0)
             { strcat(sqls2, "out_tkg"); strcat(sqls2," in "); }
          else
             { strcat(sqls2, "inc_tkg"); strcat(sqls2," in "); }
          strcat(sqls2,ListDirection);
     }
}
void __fastcall TMainForm::N18Click(TObject *Sender)
{
  FormINFields->ShowModal();

}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FormCreate(TObject *Sender)
{
TStrings * IniList;
TIniFile * Fini;
//Load some ini

 ProgrammPath=GetCurrentDir();
 Fini= new TIniFile(ProgrammPath+"\\statistic.ini");
 try {IniList = new TStringList();}
 catch(...) {ShowMessage("Не могу создать Лист Данных");Fini->~TIniFile();return; }
   //continue
 IniList->Clear();
 Fini->ReadSectionValues("BASE",IniList);
 if (IniList->Count==0) {ShowMessage("Не могу прочитать BASE в ini ");IniList->~TStrings();Fini->~TIniFile();return;}
 BDServer=IniList->Values["SERVER"];
 BDUser=IniList->Values["USERNAME"];
 BDName=IniList->Values["DATABASE"];
 BDPassword=IniList->Values["PASSWORD"];
 IniList->Clear();
 Fini->ReadSectionValues("ATC",IniList);
 if (IniList->Count==0) {ShowMessage("Не могу прочитать BASE в ini ");IniList->~TStrings();Fini->~TIniFile();return;}
 MainForm->Caption="Статистика для "+IniList->Values["ATCNAME"];
 //Starrt DataBase;
 IniList->~TStrings();
 Fini->~TIniFile();
// CustomerData->Database1->Close();
 //Activate DataBase
 /* CustomerData->Database1->Connected=false;
  CustomerData->Database1->Params->Values["User Name"]=BDUser;
  CustomerData->Database1->Params->Values["Database Name"]=BDName;
  CustomerData->Database1->Params->Values["Server Name"]=BDServer;
  CustomerData->Database1->Params->Values["Password"]=BDPassword;

  try {CustomerData->Database1->Connected=true;}
  catch(...) {ShowMessage("Не могу подключится к "+BDServer+" алиас "+CustomerData->Database1->DatabaseName);return;}
   */
        // заполнение списка полей (входящие)
        S12IN->Add("INC_TKG");
        S12IN->Add("DATA");
        S12IN->Add("T_BEGIN");
        S12IN->Add("T_END");
        S12IN->Add("ASS");
        S12IN->Add("AVLB_OCC");
        S12IN->Add("DIFA");
        S12IN->Add("CALLS");
        S12IN->Add("SEIZ");
        S12IN->Add("INJECTIONS");
        S12IN->Add("RETRIES");
        S12IN->Add("ANSWER");
        S12IN->Add("[SEIZ/ANSWER]"); //Для вычисляемого поля
        S12IN->Add("[ANSWER%SEIZ]"); //Для вычисляемого поля
        S12IN->Add("CD_BUSY");
        S12IN->Add("[CD_BUSY%SEIZ]");
        S12IN->Add("NO_ANSWER");
        S12IN->Add("[NO_ANSWER%SEIZ]");
        S12IN->Add("NO_SIG_FRL");
        S12IN->Add("NO_SIG_OVL");
        S12IN->Add("[NO_SIG_OVL%SEIZ]");
        S12IN->Add("PSIG_CLF");
        S12IN->Add("PSIG_FRL");
        S12IN->Add("INVC");
        S12IN->Add("REJ_FOR_NM");
        S12IN->Add("OGREJ_NART");
        S12IN->Add("DSN_BLK");
        S12IN->Add("CONG_DIST");
        S12IN->Add("FRL_DIST");
        S12IN->Add("INVC_DIST");
        S12IN->Add("OTHER_FAIL");
        S12IN->Add("REDIRECTED");
        S12IN->Add("SU_SY_CALL");
        S12IN->Add("CALL_RE_OV");
        S12IN->Add("OCC");
        S12IN->Add("KIS"); //Для вычисляемого поля
        S12IN->Add("OCC_N7");
        S12IN->Add("CHCONV_OCC");
        S12IN->Add("[CHCONV%OCC]");
        S12IN->Add("DIFO");

    //    S12IN->Add("[SEIZ/ANSW]=SEIZ/ANSWER");
        // заполнение списка полей (исходящие)
        S12OUT->Add("OUT_TKG");
        S12OUT->Add("DATA");
        S12OUT->Add("T_BEGIN");
        S12OUT->Add("T_END");
        S12OUT->Add("ASS");
        S12OUT->Add("AVLB_OCC");
        S12OUT->Add("DIFA");
        S12OUT->Add("OFFD");
        S12OUT->Add("SEIZ");
        S12OUT->Add("ANSWER");
        S12OUT->Add("[SEIZ/ANSWER]"); //Для вычисляемого поля
        S12OUT->Add("[ANSWER%SEIZ]"); //Для вычисляемого поля
        S12OUT->Add("CD_BUSY");
        S12OUT->Add("[CD_BUSY%SEIZ]");
        S12OUT->Add("NO_ANSWER");
        S12OUT->Add("[NO_ANSWER%SEIZ]");
        S12OUT->Add("OFFD_ATG");
        S12OUT->Add("[OFFD_ATG%OFFD]");
        S12OUT->Add("REJ_NART");
        S12OUT->Add("[REJ_NART%OFFD]");
        S12OUT->Add("INVC");
        S12OUT->Add("PSIG");
        S12OUT->Add("CONG_DIST");
        S12OUT->Add("FRL_DIST");
        S12OUT->Add("INVC_DIST");
        S12OUT->Add("OTHER_FAIL");
        S12OUT->Add("CALL_RE_NM");
        S12OUT->Add("CLASH");
        S12OUT->Add("COC_FAIL");
        S12OUT->Add("DSN_BLK");
        S12OUT->Add("OCC");
        S12OUT->Add("KIS"); //Для вычисляемого поля
        S12OUT->Add("OCC_N7");
        S12OUT->Add("CHCONV_OCC");
        S12OUT->Add("[CHCONV%OCC]");
        S12OUT->Add("DIFO");
// PABX

        S12fromPABX->Add("b.out as ASS");
        S12fromPABX->Add("O_CALLS");
        S12fromPABX->Add("O_C_INJECT");
        S12fromPABX->Add("O_C_RETRIE");
        S12fromPABX->Add("O_ANSW");
        S12fromPABX->Add("[O_ANSW%O_CALLS]");
        S12fromPABX->Add("O_CD_BSY");
        S12fromPABX->Add("[O_CD_BSY%O_CALLS]");
        S12fromPABX->Add("O_NO_ANSW");
        S12fromPABX->Add("[O_NO_ANSW%O_CALLS]");
        S12fromPABX->Add("O_NSIG_FRL");
        S12fromPABX->Add("O_NSIG_CLF");
        S12fromPABX->Add("O_PSIG_CLF");
        S12fromPABX->Add("O_PSIG_FRL");
        S12fromPABX->Add("O_INVC");
        S12fromPABX->Add("O_B_CONG");
        S12fromPABX->Add("O_CNG_DIST");
        S12fromPABX->Add("O_FRL_DIST");
        S12fromPABX->Add("O_INVC_DST");
        S12fromPABX->Add("O_OTH_FAIL");
        S12fromPABX->Add("O_REDIRECT");
        S12fromPABX->Add("O_SUCC_SYS");
        S12fromPABX->Add("O_OCC");
        S12fromPABX->Add("O_CONV_OCC");

        S12toPABX->Add("b.inc as ASS");
        S12toPABX->Add("T_CALL_ATT");
        S12toPABX->Add("T_ANSW");
        S12toPABX->Add("[T_ANSW%T_CALL_ATT]");
        S12toPABX->Add("T_CD_BSY");
        S12toPABX->Add("[T_CD_BSY%T_CALL_ATT]");
        S12toPABX->Add("T_NO_ANSW");
        S12toPABX->Add("[T_NO_ANSW%T_CALL_ATT]");
        S12toPABX->Add("T_CONG");
        S12toPABX->Add("[T_CONG%T_CALL_ATT]");
        S12toPABX->Add("T_PSIG_CLF");
        S12toPABX->Add("T_PSIG_FRL");
        S12toPABX->Add("T_OTH_FAIL");
        S12toPABX->Add("T_OCC");
        S12toPABX->Add("T_CONV_OCC");

        MainForm->WindowState=biMaximize;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FormCloseQuery(TObject *Sender, bool &CanClose)
{
        delete S12IN,S12OUT;
        delete S12fromPABX,S12toPABX; // PABX
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N19Click(TObject *Sender)
{
  FormOUTFields->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N11OUT_MagistralClick(TObject *Sender)
{
  MenuItem(1,"OUT"); // Исходящие -> Магистраль
 // book_direction(1/* магистраль*/,"mnemo_o");
//    FormCondition->Caption="Магистраль. Анализ исходящих направлений";
//    in_out_menu(2/* исходящие*/);
//    if (FormCondition->ShowModal()==mrOk)
//    {
//        Select("out_tkg",fields_OUT);
//        CreateMDIChild(FormCondition->Caption);
 //   }
}
//---------------------------------------------------------------------------

void TMainForm::MenuItem(int num, char* direction)
{
TMeasure M;
TPABX P;
AnsiString s;
char fields_toPABX[500];
char fields_fromPABX[500];
int i;
    switch(num)
    {
//      case 0: s = " "; break;
      case 1: s = "Магистраль."; break;
      case 2: s = "Зона."; break;
      case 3: s = "АТС."; break;
      case 4: s = "АРМ."; break;
    }
if (!CustomerData->Database1->Connected)
        {
          try {CustomerData->Database1->Connected=true;}
          catch(...) {ShowMessage("Не могу подключится к "+BDServer+" алиас "+CustomerData->Database1->DatabaseName+" User "+BDUser );return;}
        }
    if(strcmp(direction,"IN")==0)
    {
        if(num>0) M.book_direction(num,"mnemo_i");
        FormCondition->Caption=s+" Анализ входящих направлений";
        M.in_out_menu(1);
        if (FormCondition->ShowModal()==mrOk)
        {
            M.Select("inc_tkg",fields_IN);
            CreateMDIChild(FormCondition->Caption);
        }
    }
    if(strcmp(direction,"OUT")==0)
    {
        if(num>0) M.book_direction(num,"mnemo_o");
        FormCondition->Caption=s+" Анализ исходящих направлений";
        M.in_out_menu(2);
        if (FormCondition->ShowModal()==mrOk)
        {
            M.Select("out_tkg",fields_OUT);
            CreateMDIChild(FormCondition->Caption);
        }
    }

// PABX

        fields_toPABX[0]='\0';
        strcat(fields_toPABX,"inc_tkg,data,t_begin,t_end,");
        for(i=0;i< S12toPABX->Count-1;i++)
        {
             strcat(fields_toPABX, S12toPABX->Strings[i].c_str());
             strcat(fields_toPABX,",");
        }
        strcat(fields_toPABX, S12toPABX->Strings[S12toPABX->Count-1].c_str());

        fields_fromPABX[0]='\0';
        strcat(fields_fromPABX,"inc_tkg,data,t_begin,t_end, ");
        for(i=0;i< S12fromPABX->Count-1;i++)
        {
             strcat(fields_fromPABX, S12fromPABX->Strings[i].c_str());
             strcat(fields_fromPABX,",");
        }
        strcat(fields_fromPABX, S12fromPABX->Strings[S12fromPABX->Count-1].c_str());

//ShowMessage(fields_toPABX);
       if(strcmp(direction,"toPABX")==0)
    {
        if(num>0) P.book_direction(num,"mnemo_i");
        FormCondition->Caption=s+" Анализ направлений к PABX";
        P.in_out_menu(4);
        if (FormCondition->ShowModal()==mrOk)
        {
            P.Select("inc_tkg",fields_toPABX);
            CreateMDIChildP(FormCondition->Caption);
        }
    }
//
       if(strcmp(direction,"fromPABX")==0)
    {
        if(num>0) P.book_direction(num,"mnemo_o");
        FormCondition->Caption=s+" Анализ направлений от PABX";
        P.in_out_menu(3);
        if (FormCondition->ShowModal()==mrOk)
        {
//            P.Select("out_tkg",fields_fromPABX);
            P.Select("out_tkg",fields_fromPABX);
            CreateMDIChildP(FormCondition->Caption);
        }
    }



}


void __fastcall TMainForm::N7IN_ZonaClick(TObject *Sender)
{
  MenuItem(2,"IN"); // Входящие -> Зона
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N8IN_AtsClick(TObject *Sender)
{
  MenuItem(3,"IN"); // Входящие -> АТС
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N9IN_ArmClick(TObject *Sender)
{
  MenuItem(4,"IN"); // Входящие -> АРМ
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N12OUT_ZonaClick(TObject *Sender)
{
   MenuItem(2,"OUT"); // Исходящие -> Зона
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N13OUT_AtsClick(TObject *Sender)
{
  MenuItem(3,"OUT"); // Исходящие -> АТС
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N14OUT_ArmClick(TObject *Sender)
{
    MenuItem(4,"OUT"); // Исходящие -> АРМ
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N10Click(TObject *Sender)
{
  FormCondition->GroupBox1->Visible=False;
  FormCondition->RBAllDirection->Checked=False;
  FormCondition->RB1Direction->Checked=False;
  FormCondition->ComboBoxDirection->Visible=False;
  MenuItem(0,"IN"); // Входящие -> Все направления
  FormCondition->GroupBox1->Visible=True;
  FormCondition->RBAllDirection->Checked=True;  
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N15Click(TObject *Sender)
{
  FormCondition->GroupBox1->Visible=False;
  FormCondition->RBAllDirection->Checked=False;
  FormCondition->RB1Direction->Checked=False;
  FormCondition->ComboBoxDirection->Visible=False;
  MenuItem(0,"OUT"); // Исходящие -> Все направления
  FormCondition->GroupBox1->Visible=True;
  FormCondition->RBAllDirection->Checked=True;
}
//---------------------------------------------------------------------------






void __fastcall TMainForm::N6FieldsClick(TObject *Sender)
{
 if(N6Fields->Checked==False) N6Fields->Checked=True;
 else  N6Fields->Checked=False;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Print1Execute(TObject *Sender)
{
 // if(MDIChildCount==0) return;
  if(ActiveMDIChild->Tag ==1)
  {
     FormQuickRepIN->QRLabelTitle->Caption=ActiveMDIChild->Caption;
     FormQuickRepIN->SetDataSet(dynamic_cast<TQuery*>(ActiveMDIChild->Components[3]));
     FormQuickRepIN->QuickRep1->Preview();
  }
  else
  {
     FormQuickRepOUT->QRLabelTitle->Caption=ActiveMDIChild->Caption;
     FormQuickRepOUT->SetDataSet(dynamic_cast<TQuery*>(ActiveMDIChild->Components[3]));
     FormQuickRepOUT->QuickRep1->Preview();
  }
}
//---------------------------------------------------------------------------




void __fastcall TMainForm::N6Click(TObject *Sender)
{
  FormGrid->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N10111Click(TObject *Sender)
{
   FormKZO->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N9Click(TObject *Sender)
{

Variant FX,v0,v1,v2;
char s[50];
int i,j;
AnsiString sFile = GetCurrentDir()+"\\потери_вызовов_в_ЧНН.xls";

FormMonthYear->ShowModal(); // форма выбора месяца и года
if (FormMonthYear->ModalResult==mrCancel) return;

FX=CreateOleObject("Excel.Application");

// открытие файла
try{
FX.OlePropertyGet("WorkBooks").OleProcedure("Open",sFile.c_str(),0,false,1);
} catch(...){
Application->MessageBox(
"Ошибка открытия файла: потери_вызовов_в_ЧНН.xls!","Ошибка",MB_OK+MB_ICONERROR);
}

FX.OlePropertySet("Visible",true);
//FX.OlePropertyGet("WorkBooks").OleProcedure("Open",sFile.c_str(),0,false,1);
v0=FX.OlePropertyGet("WorkSheets",1);

CustomerData->Query2->SQL->Clear();
// установка первого дня недели - понедельник
CustomerData->Query2->SQL->Add("SET DATEFIRST 1 ");
CustomerData->Query2->SQL->Add("select * from outgoing_traffic where t_begin='10:00' ");
CustomerData->Query2->SQL->Add(" and year(now_add)=");
CustomerData->Query2->SQL->Add(FormMonthYear->MaskEdit1->Text);
CustomerData->Query2->SQL->Add(" and month(now_add)=");
CustomerData->Query2->SQL->Add(IntToStr(
      FormMonthYear->ComboBox1->Items->IndexOf(FormMonthYear->ComboBox1->Text)+1).c_str() );
CustomerData->Query2->SQL->Add(" and DATEPART(dw,now_add)=3"); // выбор за все среды
CustomerData->Query2->SQL->Add(" order by now_add");
CustomerData->Query2->Open();

CustomerData->Query2->First();
v0=FX.OlePropertyGet("Worksheets") ;
v1=v0.OlePropertyGet("Item",1);

for (int i=0;i<=CustomerData->Query2->RecordCount-1;i++)
{
 v1.OlePropertyGet("Cells").OlePropertyGet("Item",9+i,1).OlePropertySet("Value",
               CustomerData->Query2->FieldByName("NOW_ADD")->AsString.c_str() );

 v1.OlePropertyGet("Cells").OlePropertyGet("Item",9+i,2).OlePropertySet("Value",
            (CustomerData->Query2->FieldByName("T_BEGIN")->AsString+"-"+
            CustomerData->Query2->FieldByName("T_END")->AsString).c_str() );
// v1.OlePropertyGet("Cells").OlePropertyGet("Item",9+i,3).OlePropertySet("Value",
//            CustomerData->Query2->FieldByName("TOTAL")->AsString);
// v1.OlePropertyGet("Cells").OlePropertyGet("Item",9+i,4).OlePropertySet("Value",
//            CustomerData->Query2->FieldByName("OG_REJECT_NO_ALTERNATE_ROUTE")->AsString);
 v1.OlePropertyGet("Cells").OlePropertyGet("Item",9+i,5).OlePropertySet("Value",
            CustomerData->Query2->FieldByName("OG_DSN_BLOCKED")->AsString.c_str());
 v1.OlePropertyGet("Cells").OlePropertyGet("Item",9+i,6).OlePropertySet("Value",
            CustomerData->Query2->FieldByName("OG_SENDER_BUSY")->AsString.c_str());
 v1.OlePropertyGet("Cells").OlePropertyGet("Item",9+i,7).OlePropertySet("Value",
            CustomerData->Query2->FieldByName("OG_FAIL_DISTANT")->AsString.c_str());
 v1.OlePropertyGet("Cells").OlePropertyGet("Item",9+i,8).OlePropertySet("Value",
        IntToStr(CustomerData->Query2->FieldByName("OROG_NACC")->AsInteger+
                 CustomerData->Query2->FieldByName("TRNS_NACC")->AsInteger).c_str()  );
//
 v1.OlePropertyGet("Cells").OlePropertyGet("Item",9+i,9).OlePropertySet("Value",
         IntToStr(CustomerData->Query2->FieldByName("OROG_NASS")->AsInteger+
                 CustomerData->Query2->FieldByName("TRNS_NASS")->AsInteger).c_str()  );
 v1.OlePropertyGet("Cells").OlePropertyGet("Item",9+i,10).OlePropertySet("Value",
            CustomerData->Query2->FieldByName("OG_OTHER_FAIL")->AsString.c_str());
 v1.OlePropertyGet("Cells").OlePropertyGet("Item",9+i,11).OlePropertySet("Value",
            CustomerData->Query2->FieldByName("OG_CALLED_BUSY")->AsString.c_str());
 CustomerData->Query2->Next();
}

// Учесть количество записей - 4 или 5
  j=CustomerData->Query2->RecordCount;

// ------------------------------------------------------------------
// Число исходящих вызовов и "нет альтер. пути" из таблицы maket out
//ShowMessage("2 table");
CustomerData->Query1->SQL->Clear();
// установка первого дня недели - понедельник
CustomerData->Query1->SQL->Add("SET DATEFIRST 1 ");
CustomerData->Query1->SQL->Add("select data,sum(offd) as offd_s,sum(rej_nart)as rej_nart_s from ");
CustomerData->Query1->SQL->Add("  maket_out a, s12_book2 b where t_begin='10:00' ");
CustomerData->Query1->SQL->Add(" and year(data)=");
CustomerData->Query1->SQL->Add(FormMonthYear->MaskEdit1->Text);
CustomerData->Query1->SQL->Add(" and month(data)=");
CustomerData->Query1->SQL->Add(IntToStr(
      FormMonthYear->ComboBox1->Items->IndexOf(FormMonthYear->ComboBox1->Text)+1).c_str() );
CustomerData->Query1->SQL->Add(" and a.out_tkg=b.mnemo_o");
CustomerData->Query1->SQL->Add(" and DATEPART(dw,data)=3"); // выбор за все среды
CustomerData->Query1->SQL->Add(" and b.name not in ('TT_AUT_DMI_DTG') ");
CustomerData->Query1->SQL->Add(" group by data  order by data");
CustomerData->Query1->Open();
CustomerData->Query1->First();

for (int i=0;i<=CustomerData->Query1->RecordCount-1;i++)
{
 v1.OlePropertyGet("Cells").OlePropertyGet("Item",9+i,1).OlePropertySet("Value",
                    CustomerData->Query1->FieldByName("data")->AsString.c_str());

 v1.OlePropertyGet("Cells").OlePropertyGet("Item",9+i,3).OlePropertySet("Value",
            CustomerData->Query1->FieldByName("offd_s")->AsString.c_str() );
 v1.OlePropertyGet("Cells").OlePropertyGet("Item",9+i,4).OlePropertySet("Value",
            CustomerData->Query1->FieldByName("rej_nart_s")->AsString.c_str());
 CustomerData->Query1->Next();
}


// A
  v1.OlePropertyGet("Cells").OlePropertyGet("Item",14,3).
                                        OlePropertySet("Value","=СУММ(C9:C13)");
  v1.OlePropertyGet("Cells").OlePropertyGet("Item",16,3).
                                               OlePropertySet("Value",("=C14/"+
                                               IntToStr(j)).c_str() );
//ShowMessage("итого");
// столбец "Итого"
  v1.OlePropertyGet("Cells").OlePropertyGet("Item",9,12).
                                        OlePropertySet("Value","=СУММ(D9:K9)");
  v1.OlePropertyGet("Cells").OlePropertyGet("Item",10,12).
                                       OlePropertySet("Value","=СУММ(D10:K10)");
  v1.OlePropertyGet("Cells").OlePropertyGet("Item",11,12).
                                       OlePropertySet("Value","=СУММ(D11:K11)");
  v1.OlePropertyGet("Cells").OlePropertyGet("Item",12,12).
                                        OlePropertySet("Value","=СУММ(D12:K12");
  v1.OlePropertyGet("Cells").OlePropertyGet("Item",13,12).
                                        OlePropertySet("Value","=СУММ(D13:K13");
// Столбец "процент вызовов ..."
  v1.OlePropertyGet("Cells").OlePropertyGet("Item",9,13).
                                        OlePropertySet("Value","=L9/C9*100");
  v1.OlePropertyGet("Cells").OlePropertyGet("Item",10,13).
                                        OlePropertySet("Value","=L10/C10*100");
  v1.OlePropertyGet("Cells").OlePropertyGet("Item",11,13).
                                        OlePropertySet("Value","=L11/C11*100");
  v1.OlePropertyGet("Cells").OlePropertyGet("Item",12,13).
                                        OlePropertySet("Value","=L12/C12*100");
  v1.OlePropertyGet("Cells").OlePropertyGet("Item",13,13).
                                        OlePropertySet("Value","=L13/C13*100");

// Столбец "Потери вызовов ..."
  v1.OlePropertyGet("Cells").OlePropertyGet("Item",9,14).
                                        OlePropertySet("Value","=K9/C9*100");
  v1.OlePropertyGet("Cells").OlePropertyGet("Item",10,14).
                                        OlePropertySet("Value","=K10/C10*100");
  v1.OlePropertyGet("Cells").OlePropertyGet("Item",11,14).
                                        OlePropertySet("Value","=K11/C11*100");
  v1.OlePropertyGet("Cells").OlePropertyGet("Item",12,14).
                                        OlePropertySet("Value","=K12/C12*100");
  v1.OlePropertyGet("Cells").OlePropertyGet("Item",13,14).
                                        OlePropertySet("Value","=K13/C13*100");

// t
  v1.OlePropertyGet("Cells").OlePropertyGet("Item",14,11).
                                        OlePropertySet("Value","=СУММ(K9:K13)");

// B
  v1.OlePropertyGet("Cells").OlePropertyGet("Item",14,12).
                                        OlePropertySet("Value","=СУММ(L9:L13)");
  v1.OlePropertyGet("Cells").OlePropertyGet("Item",16,12).
                                        OlePropertySet("Value",("=L14/"+
                                        IntToStr(j)).c_str() );

// если 4 среды в месяце (меньше 5) то удаляем 13-ю строку
//if (CustomerData->Query2->RecordCount<5)
if (j<5)
  v1.OlePropertyGet("Rows","13:13").OlePropertyGet("Delete");

//отключить диагностику при закрытии сервера
FX.OlePropertySet("DisplayAlerts",false);
s[0]='\0';
strcat(s,"Потери вызовов в ЧНН станции_");
strcat(s,FormMonthYear->ComboBox1->Text.c_str());
strcat(s," ");
strcat(s,FormMonthYear->MaskEdit1->Text.c_str());

FX.OlePropertyGet("Workbooks").OlePropertyGet("Item",1).OleProcedure("SaveAs",s);
//FX.OleProcedure("Quit");
FX.Clear();

}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N8Click(TObject *Sender)
{
Variant FX,v0,v1,v2;
char s[150];
int i,j;
AnsiString m[6];

Word Year1, Month1, Day1;

m[1]="06";
m[2]="07";
m[3]="08";
m[4]="09";
m[5]="10";

AnsiString sFile = GetCurrentDir()+"\\ЧНН по станции.xls";

FormDMY_32->Caption="Определение ЧНН";
FormDMY_32->RadioGroup1->Enabled=False;
FormDMY_32->RB_IN->Enabled=False;
FormDMY_32->RB_OUT->Enabled=False;

FormDMY_32->ShowModal(); // форма выбора месяца и года

FormDMY_32->RadioGroup1->Enabled=True;
FormDMY_32->RB_IN->Enabled=True;
FormDMY_32->RB_OUT->Enabled=True;
FormDMY_32->Caption="Приложение 3.2";

if (FormDMY_32->ModalResult==mrCancel) return;

DecodeDate(FormDMY_32->DateTimePicker1->Date, Year1, Month1, Day1);
        for(i=1;i<=5;i++)
        {
          if(Day1+i-1<10) {m[i]="0"+IntToStr(Day1+i-1);}
          else {m[i]=IntToStr(Day1+i-1);}
        }
//FormMonthYear->ShowModal(); // форма выбора месяца и года
//if (FormMonthYear->ModalResult==mrCancel) return;

FX=CreateOleObject("Excel.Application");

// открытие файла
try{
FX.OlePropertyGet("WorkBooks").OleProcedure("Open",sFile.c_str(),0,false,1);
} catch(...){
Application->MessageBox(
"Ошибка открытия файла: потери_вызовов_в_ЧНН.xls!","Ошибка",MB_OK+MB_ICONERROR);
}

FX.OlePropertySet("Visible",true);
//FX.OlePropertyGet("WorkBooks").OleProcedure("Open",sFile.c_str(),0,false,1);
v0=FX.OlePropertyGet("WorkSheets",1);

CustomerData->Query2->SQL->Clear();
CustomerData->Query2->SQL->Add("select * from hourly_report");
CustomerData->Query2->SQL->Add(" where now_add in ('2005-05-18') order by t_begin");
CustomerData->Query2->Open();

CustomerData->Query2->First();
v0=FX.OlePropertyGet("Worksheets") ;
v1=v0.OlePropertyGet("Item",1);

  for(int j=1;j<=5; j++)
  {
        CustomerData->Query2->SQL->Clear();
        s[0]='\0';
        strcat(s,"select * from hourly_report ");
        strcat(s," where now_add in ('");
        strcat(s,IntToStr(Year1).c_str() ); // год
        strcat(s,"-");
        if(Month1<10) strcat(s,"0");        // месяц
        strcat(s,IntToStr(Month1).c_str() );
        strcat(s,"-");
        strcat(s,m[j].c_str());             // день
        strcat(s,"') ");
        CustomerData->Query2->SQL->Add(s);
        CustomerData->Query2->SQL->Add(" order by t_begin");
        CustomerData->Query2->Open();
        CustomerData->Query2->First();

    for (int i=0;i<=CustomerData->Query2->RecordCount-1;i++)
    {
     v1.OlePropertyGet("Cells").OlePropertyGet("Item",5+i,1).OlePropertySet("Value",
            (CustomerData->Query2->FieldByName("T_BEGIN")->AsString+"-"+
            CustomerData->Query2->FieldByName("T_END")->AsString).c_str() );
     v1.OlePropertyGet("Cells").OlePropertyGet("Item",5+i,j*2).OlePropertySet("Value",
            CustomerData->Query2->FieldByName("TOTAL_EXCHANGE_TRIGGERS")->AsString.c_str());
     v1.OlePropertyGet("Cells").OlePropertyGet("Item",5+i,j*2+1).OlePropertySet("Value",
            CustomerData->Query2->FieldByName("OG_TK")->AsString.c_str());

     CustomerData->Query2->Next();
    }
     v1.OlePropertyGet("Cells").OlePropertyGet("Item",3,j*2).OlePropertySet("Value",
                    ("Дата: "+CustomerData->Query2->FieldByName("NOW_ADD")->AsString).c_str());
//       v1.OlePropertyGet("Cells").OlePropertyGet("Item",8,j*2).OlePropertySet("Value",
//                    "Дата:"+CustomerData->Query1->FieldByName("data")->AsString);

  }

// v1.OlePropertyGet("Cells").OlePropertyGet("Item",3,2).OlePropertySet("Value",
//                    "Дата: "+CustomerData->Query2->FieldByName("NOW_ADD")->AsString);

// подсчет сумм
   for(i=1;i<=24;i++)
   {
         s[0]='\0';
         strcat(s,"=(");
         strcat(s,"B");
         strcat(s,IntToStr(i+4).c_str());       strcat(s,"+");
         strcat(s,"D");
         strcat(s,IntToStr(i+4).c_str());       strcat(s,"+");
         strcat(s,"F");
         strcat(s,IntToStr(i+4).c_str());       strcat(s,"+");
         strcat(s,"H");
         strcat(s,IntToStr(i+4).c_str());       strcat(s,"+");
         strcat(s,"J");
         strcat(s,IntToStr(i+4).c_str());
         strcat(s,")/5");
         v1.OlePropertyGet("Cells").OlePropertyGet("Item",4+i,12).
                                    OlePropertySet("Value",s);
         s[0]='\0';
         strcat(s,"=(");
         strcat(s,"C");
         strcat(s,IntToStr(i+4).c_str());       strcat(s,"+");
         strcat(s,"E");
         strcat(s,IntToStr(i+4).c_str());       strcat(s,"+");
         strcat(s,"G");
         strcat(s,IntToStr(i+4).c_str());       strcat(s,"+");
         strcat(s,"I");
         strcat(s,IntToStr(i+4).c_str());       strcat(s,"+");
         strcat(s,"K");
         strcat(s,IntToStr(i+4).c_str());
         strcat(s,")/5");
         v1.OlePropertyGet("Cells").OlePropertyGet("Item",4+i,13).
                                    OlePropertySet("Value",s);
   }
//отключить диагностику при закрытии сервера
FX.OlePropertySet("DisplayAlerts",false);
s[0]='\0';
strcat(s,"ЧНН станции_");
strcat(s,FormMonthYear->ComboBox1->Text.c_str());
strcat(s," ");
strcat(s,FormMonthYear->MaskEdit1->Text.c_str());

FX.OlePropertyGet("Workbooks").OlePropertyGet("Item",1).OleProcedure("SaveAs",s);
//FX.OleProcedure("Quit");
FX.Clear();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N11Click(TObject *Sender)
{
Variant FX,v0,v1,v2;
char s[300];
int i,j;
AnsiString m[6];

m[1]="01";
m[2]="02";
m[3]="03";
m[4]="04";
m[5]="05";
/*
AnsiString sFile = GetCurrentDir()+"\\ЧНН по станции.xls";

ShowMessage("Показатели за июнь");
//FormMonthYear->ShowModal(); // форма выбора месяца и года
//if (FormMonthYear->ModalResult==mrCancel) return;

FX=CreateOleObject("Excel.Application");

// открытие файла
try{
FX.OlePropertyGet("WorkBooks").OleProcedure("Open",sFile.c_str(),0,false,1);
} catch(...){
Application->MessageBox(
"Ошибка открытия файла: потери_вызовов_в_ЧНН.xls!","Ошибка",MB_OK+MB_ICONERROR);
}

FX.OlePropertySet("Visible",true);
//FX.OlePropertyGet("WorkBooks").OleProcedure("Open",sFile.c_str(),0,false,1);
v0=FX.OlePropertyGet("WorkSheets",1);

CustomerData->Query2->SQL->Clear();
CustomerData->Query2->SQL->Add("select * from hourly_report");
CustomerData->Query2->SQL->Add(" where now_add in ('2005-05-18') order by t_begin");
CustomerData->Query2->Open();

CustomerData->Query2->First();
v0=FX.OlePropertyGet("Worksheets") ;
v1=v0.OlePropertyGet("Item",1);
*/
  for(j=1;j<=31; j++)
  {
        CustomerData->Query2->SQL->Clear();
        s[0]='\0';

        strcat(s,"insert into H_R_2(now_add,TOTAL_EXCHANGE_TRIGGERS) ");
        strcat(s,"values( ");
        strcat(s," '2005-01-");
        strcat(s,IntToStr(j).c_str());
        strcat(s,"',");
        strcat(s,"select max(convert(int,TOTAL_EXCHANGE_TRIGGERS)) from ");
        strcat(s," hourly_report where now_add='2005-01-");
        strcat(s,IntToStr(j).c_str());
        strcat(s,"') ");
        ShowMessage(IntToStr(j).c_str() );
        ShowMessage(s);
//        strcat(s,m[j].c_str());
        CustomerData->Query2->SQL->Add(s);
        CustomerData->Query2->Open();
        CustomerData->Query2->First();
   }
   ShowMessage("OK");
/*    for (int i=0;i<=CustomerData->Query2->RecordCount-1;i++)
    {
     v1.OlePropertyGet("Cells").OlePropertyGet("Item",5+i,1).OlePropertySet("Value",
            CustomerData->Query2->FieldByName("T_BEGIN")->AsString+"-"+
            CustomerData->Query2->FieldByName("T_END")->AsString);
     v1.OlePropertyGet("Cells").OlePropertyGet("Item",5+i,j*2).OlePropertySet("Value",
            CustomerData->Query2->FieldByName("TOTAL_EXCHANGE_TRIGGERS")->AsString);
     v1.OlePropertyGet("Cells").OlePropertyGet("Item",5+i,j*2+1).OlePropertySet("Value",
            CustomerData->Query2->FieldByName("OG_TK")->AsString);

     CustomerData->Query2->Next();
    }
  }

 v1.OlePropertyGet("Cells").OlePropertyGet("Item",3,2).OlePropertySet("Value",
                    "Дата: "+CustomerData->Query2->FieldByName("NOW_ADD")->AsString);

// подсчет сумм
   for(i=1;i<=24;i++)
   {
         s[0]='\0';
         strcat(s,"=(");
         strcat(s,"B");
         strcat(s,IntToStr(i+4).c_str());       strcat(s,"+");
         strcat(s,"D");
         strcat(s,IntToStr(i+4).c_str());       strcat(s,"+");
         strcat(s,"F");
         strcat(s,IntToStr(i+4).c_str());       strcat(s,"+");
         strcat(s,"H");
         strcat(s,IntToStr(i+4).c_str());       strcat(s,"+");
         strcat(s,"J");
         strcat(s,IntToStr(i+4).c_str());
         strcat(s,")/5");
         v1.OlePropertyGet("Cells").OlePropertyGet("Item",4+i,12).
                                    OlePropertySet("Value",s);
         s[0]='\0';
         strcat(s,"=(");
         strcat(s,"C");
         strcat(s,IntToStr(i+4).c_str());       strcat(s,"+");
         strcat(s,"E");
         strcat(s,IntToStr(i+4).c_str());       strcat(s,"+");
         strcat(s,"G");
         strcat(s,IntToStr(i+4).c_str());       strcat(s,"+");
         strcat(s,"I");
         strcat(s,IntToStr(i+4).c_str());       strcat(s,"+");
         strcat(s,"K");
         strcat(s,IntToStr(i+4).c_str());
         strcat(s,")/5");
         v1.OlePropertyGet("Cells").OlePropertyGet("Item",4+i,13).
                                    OlePropertySet("Value",s);
   }
//отключить диагностику при закрытии сервера
FX.OlePropertySet("DisplayAlerts",false);
s[0]='\0';
strcat(s,"ЧНН станции_");
strcat(s,FormMonthYear->ComboBox1->Text.c_str());
strcat(s," ");
strcat(s,FormMonthYear->MaskEdit1->Text.c_str());

FX.OlePropertyGet("Workbooks").OlePropertyGet("Item",1).OleProcedure("SaveAs",s);
//FX.OleProcedure("Quit");
FX.Clear();*/
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N12Click(TObject *Sender)
{

Variant FX,v0,v1,v2;
char s[50];
int i,j;
AnsiString sFile = GetCurrentDir()+"\\КЗО_исходящие.xls";

FormMonthYear->ShowModal(); // форма выбора месяца и года
if (FormMonthYear->ModalResult==mrCancel) return;

FX=CreateOleObject("Excel.Application");

// открытие файла
try{
FX.OlePropertyGet("WorkBooks").OleProcedure("Open",sFile.c_str(),0,false,1);
} catch(...){
Application->MessageBox(
"Ошибка открытия файла: потери_вызовов_в_ЧНН.xls!","Ошибка",MB_OK+MB_ICONERROR);
}

FX.OlePropertySet("Visible",true);
//FX.OlePropertyGet("WorkBooks").OleProcedure("Open",sFile.c_str(),0,false,1);
v0=FX.OlePropertyGet("WorkSheets",1);


CustomerData->Query1->SQL->Clear();
// установка первого дня недели - понедельник
CustomerData->Query1->SQL->Add("SET DATEFIRST 1 ");
CustomerData->Query1->SQL->Add(" select data,sum(offd) as offd, ");
CustomerData->Query1->SQL->Add(" sum(seiz) as seiz,sum(answer) as answer from ");
CustomerData->Query1->SQL->Add(" maket_out a, s12_book2 b where t_begin='10:00' ");
CustomerData->Query1->SQL->Add(" and year(data)=");
CustomerData->Query1->SQL->Add(FormMonthYear->MaskEdit1->Text);
CustomerData->Query1->SQL->Add(" and month(data)=");
CustomerData->Query1->SQL->Add(IntToStr(
      FormMonthYear->ComboBox1->Items->IndexOf(FormMonthYear->ComboBox1->Text)+1).c_str() );
CustomerData->Query1->SQL->Add(" and a.out_tkg=b.mnemo_o ");
CustomerData->Query1->SQL->Add(" and DATEPART(dw,data)=3"); // выбор за все среды
CustomerData->Query1->SQL->Add(" and b.name not in ('TT_AUT_DMI_DTG') ");
CustomerData->Query1->SQL->Add(" group by data");
CustomerData->Query1->Open();

CustomerData->Query1->First();
v0=FX.OlePropertyGet("Worksheets") ;
v1=v0.OlePropertyGet("Item",1);

for (int i=0;i<=CustomerData->Query1->RecordCount-1;i++)
{
 v1.OlePropertyGet("Cells").OlePropertyGet("Item",11+i,1).OlePropertySet("Value",
                    CustomerData->Query1->FieldByName("data")->AsString.c_str());
 v1.OlePropertyGet("Cells").OlePropertyGet("Item",11+i,2).OlePropertySet("Value",
                                            "10:00-11:00");
 v1.OlePropertyGet("Cells").OlePropertyGet("Item",11+i,3).OlePropertySet("Value",
            CustomerData->Query1->FieldByName("offd")->AsString.c_str());
 v1.OlePropertyGet("Cells").OlePropertyGet("Item",11+i,4).OlePropertySet("Value",
            CustomerData->Query1->FieldByName("seiz")->AsString.c_str());
 v1.OlePropertyGet("Cells").OlePropertyGet("Item",11+i,5).OlePropertySet("Value",
            CustomerData->Query1->FieldByName("answer")->AsString.c_str());

 CustomerData->Query1->Next();
}
// Учесть количество записей - 4 или 5
  j=CustomerData->Query1->RecordCount;
// A
  v1.OlePropertyGet("Cells").OlePropertyGet("Item",16,3).
                                        OlePropertySet("Value","=СУММ(C11:C15)");
  v1.OlePropertyGet("Cells").OlePropertyGet("Item",17,3).
                                               OlePropertySet("Value",("=C16/"+
                                               IntToStr(j)).c_str());
  v1.OlePropertyGet("Cells").OlePropertyGet("Item",16,4).
                                        OlePropertySet("Value","=СУММ(D11:D15)");
  v1.OlePropertyGet("Cells").OlePropertyGet("Item",17,4).
                                               OlePropertySet("Value",("=D16/"+
                                               IntToStr(j)).c_str());
  v1.OlePropertyGet("Cells").OlePropertyGet("Item",16,5).
                                        OlePropertySet("Value","=СУММ(E11:E15)");
  v1.OlePropertyGet("Cells").OlePropertyGet("Item",17,5).
                                               OlePropertySet("Value",("=E16/"+
                                               IntToStr(j)).c_str() );


// Столбец "процент вызовов ..."
  v1.OlePropertyGet("Cells").OlePropertyGet("Item",11,6).
                                        OlePropertySet("Value","=E11/C11*100");
  v1.OlePropertyGet("Cells").OlePropertyGet("Item",12,6).
                                        OlePropertySet("Value","=E12/C12*100");
  v1.OlePropertyGet("Cells").OlePropertyGet("Item",13,6).
                                        OlePropertySet("Value","=E13/C13*100");
  v1.OlePropertyGet("Cells").OlePropertyGet("Item",14,6).
                                        OlePropertySet("Value","=E14/C14*100");
  v1.OlePropertyGet("Cells").OlePropertyGet("Item",15,6).
                                        OlePropertySet("Value","=E15/C15*100");

// Столбец "процент занятий ..."
  v1.OlePropertyGet("Cells").OlePropertyGet("Item",11,7).
                                        OlePropertySet("Value","=E11/D11*100");
  v1.OlePropertyGet("Cells").OlePropertyGet("Item",12,7).
                                        OlePropertySet("Value","=E12/D12*100");
  v1.OlePropertyGet("Cells").OlePropertyGet("Item",13,7).
                                        OlePropertySet("Value","=E13/D13*100");
  v1.OlePropertyGet("Cells").OlePropertyGet("Item",14,7).
                                        OlePropertySet("Value","=E14/D14*100");
  v1.OlePropertyGet("Cells").OlePropertyGet("Item",15,7).
                                        OlePropertySet("Value","=E15/D15*100");

// если 4 среды в месяце (меньше 5) то удаляем 13-ю строку
if (CustomerData->Query1->RecordCount<5)
  v1.OlePropertyGet("Rows","15:15").OlePropertyGet("Delete");

//
s[0]='\0';
strcat(s,"за ");
strcat(s,FormMonthYear->ComboBox1->Text.c_str());
strcat(s," месяц ");
strcat(s,FormMonthYear->MaskEdit1->Text.c_str());
strcat(s," г.");

v1.OlePropertyGet("Cells").OlePropertyGet("Item",3,1).
                                        OlePropertySet("Value",s);

//отключить диагностику при закрытии сервера
FX.OlePropertySet("DisplayAlerts",false);
s[0]='\0';
strcat(s,"КЗО исходящие_");
strcat(s,FormMonthYear->ComboBox1->Text.c_str());
strcat(s," ");
strcat(s,FormMonthYear->MaskEdit1->Text.c_str());

FX.OlePropertyGet("Workbooks").OlePropertyGet("Item",1).OleProcedure("SaveAs",s);
//FX.OleProcedure("Quit");
FX.Clear();

}
//---------------------------------------------------------------------------


void __fastcall TMainForm::Excel1Click(TObject *Sender)
{
// Экспорт в Excel
char s[200];

if (MDIChildCount==0) return;
FX=CreateOleObject("Excel.Application");
FX.OlePropertySet("Visible",true);

v0=FX.OlePropertyGet("Workbooks");
v0.OleProcedure("Add");
v1=v0.OlePropertyGet("Item",1);
v0=v1.OlePropertyGet("Worksheets") ;
v0.OlePropertyGet("Item",1).OlePropertySet("Name","Лист1");

//=================
v1=v0.OlePropertyGet("Item",1);
v1.OlePropertyGet("Columns").OlePropertyGet("Item",1).OlePropertySet("ColumnWidth", 15);
v1.OlePropertyGet("Columns").OlePropertyGet("Item",2).OlePropertySet("ColumnWidth", 10);

s[0]='\0';
strcat(s,ActiveMDIChild->Caption.c_str());
v1.OlePropertyGet("Cells").OlePropertyGet("Item",1,3).
   OlePropertySet("Value",s);
// жирный шрифт
 v2=v1.OlePropertyGet("Cells").OlePropertyGet("Item",1,3);
 v2.OlePropertyGet("Font").OlePropertySet("Bold",true);

 v2=v1.OlePropertyGet("Rows","2:2");
 v2.OlePropertyGet("Font").OlePropertySet("Bold",true);


dynamic_cast<TQuery*>(ActiveMDIChild->Components[3])->First();

// вывод названия полей
 for(int i = 0; i < dynamic_cast<TQuery*>(ActiveMDIChild->Components[3])->FieldCount; i++)
  v1.OlePropertyGet("Cells").OlePropertyGet("Item",2,i+1).OlePropertySet("Value",
                    dynamic_cast<TQuery*>(ActiveMDIChild->Components[3])->Fields->Fields[i]->FieldName.c_str() );

// Вывод данных
for(int i=1; i<=dynamic_cast<TQuery*>(ActiveMDIChild->Components[3])->RecordCount; i++)
{
  for(int j=0;j<dynamic_cast<TQuery*>(ActiveMDIChild->Components[3])->FieldCount; j++)
  {
  v1.OlePropertyGet("Cells").OlePropertyGet("Item",i+2,j+1).OlePropertySet("Value",
                    dynamic_cast<TQuery*>(ActiveMDIChild->Components[3])->Fields->Fields[j]->AsString.c_str() );
  }
  if(!dynamic_cast<TQuery*>(ActiveMDIChild->Components[3])->Eof)
  dynamic_cast<TQuery*>(ActiveMDIChild->Components[3])->Next();
}


FX.OlePropertySet("DisplayAlerts",false); //отключить диагностику при закрытии сервера
s[0]='\0';
strcat(s,"k_pokazateli");

FX.OlePropertyGet("Workbooks").OlePropertyGet("Item",1).OleProcedure("SaveAs",s);

//FX.OleProcedure("Quit");
FX.Clear();
free(s);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N41Click(TObject *Sender)
{

Variant FX,v0,v1,v2;
char s[100];
int i,j;
AnsiString sFile = GetCurrentDir()+"\\форма4_ed.xls";

FormMonthYear->ShowModal(); // форма выбора месяца и года
if (FormMonthYear->ModalResult==mrCancel) return;


FX=CreateOleObject("Excel.Application");

// открытие файла
try{
FX.OlePropertyGet("WorkBooks").OleProcedure("Open",sFile.c_str(),0,false,1);
} catch(...){
Application->MessageBox(
"Ошибка открытия файла: форма4_ed.xls!","Ошибка",MB_OK+MB_ICONERROR);
}

FX.OlePropertySet("Visible",true);
v0=FX.OlePropertyGet("WorkSheets",1);

//========== Формирование списка направлений
  CustomerData->QueryBook->Close();
  CustomerData->QueryBook->SQL->Clear();
  CustomerData->QueryBook->SQL->Add("select * from s12_book2 where mnemo_o is not null ");
  CustomerData->QueryBook->SQL->Add("and mnemo_o <>'' order by ");
  CustomerData->QueryBook->SQL->Add("mnemo_o");

  CustomerData->QueryBook->Open();
  CustomerData->QueryBook->First();
//==========

while(!CustomerData->QueryBook->Eof)
{
  FX.OlePropertyGet("Cells").OlePropertyGet("Select"); // NEW
  FX.OlePropertyGet("Selection").OleProcedure("Copy");
  v0=FX.OlePropertyGet("Worksheets") ;
        v0.OlePropertyGet("Add");
        v1=v0.OlePropertyGet("Item",1);
        v1.OlePropertySet("Name", CustomerData->QueryBook->FieldByName("name")->AsString.c_str() );
  FX.OlePropertyGet("ActiveSheet").OleProcedure("Paste");

  v1.OlePropertyGet("Cells").OlePropertyGet("Item",3,2).OlePropertySet("Value",
                   CustomerData->QueryBook->FieldByName("mnemo_o")->AsString.c_str() );

// очищение данных предыдущего направления
  v1.OlePropertyGet("Range","A7:P40").OlePropertyGet("ClearContents"); // ver 2.4

  CustomerData->Query1->SQL->Clear();
//
CustomerData->Query1->SQL->Add("select data, ");
CustomerData->Query1->SQL->Add("SEIZ, ANSWER, [ANSWER%SEIZ], CD_BUSY, [CD_BUSY%SEIZ], ");
CustomerData->Query1->SQL->Add("NO_ANSWER, [NO_ANSWER%SEIZ], CONG,  [CONG%SEIZ], ");
CustomerData->Query1->SQL->Add("REJ_NART, [REJ_NART%OFFD], PSIG,  [PSIG%SEIZ] ");
CustomerData->Query1->SQL->Add("from form4_sum ");
CustomerData->Query1->SQL->Add("where ");

CustomerData->Query1->SQL->Add("  year(data)=");
CustomerData->Query1->SQL->Add(FormMonthYear->MaskEdit1->Text);
CustomerData->Query1->SQL->Add(" and month(data)=");
CustomerData->Query1->SQL->Add(IntToStr(
      FormMonthYear->ComboBox1->Items->IndexOf(FormMonthYear->ComboBox1->Text)+1).c_str() );

 s[0]='\0';
 strcat(s," and out_tkg='");
 strcat(s,CustomerData->QueryBook->FieldByName("mnemo_o")->AsString.c_str());
 strcat(s,"'");
 CustomerData->Query1->SQL->Add(s);
 CustomerData->Query1->SQL->Add("order by out_tkg, data ");

CustomerData->Query1->Open();
CustomerData->Query1->First();

for (i=0;i<=CustomerData->Query1->RecordCount-1;i++)
{

  for(j=0;j<=13; j++)
  {
  v1.OlePropertyGet("Cells").OlePropertyGet("Item",i+7,j+2).OlePropertySet("Value",
                    CustomerData->Query1->Fields->Fields[j]->AsString.c_str() );
  }
  if(!CustomerData->Query1->Eof) CustomerData->Query1->Next();
}


  v1.OlePropertyGet("Cells").OlePropertyGet("Item",i+7,5).
                                               OlePropertySet("Value",("=D"+
                           IntToStr(i+7)+"/C"+IntToStr(i+7)+"*100").c_str() );

  v1.OlePropertyGet("Cells").OlePropertyGet("Item",i+7,7).
                                               OlePropertySet("Value",("=F"+
                           IntToStr(i+7)+"/C"+IntToStr(i+7)+"*100").c_str() );

  v1.OlePropertyGet("Cells").OlePropertyGet("Item",i+7,9).
                                               OlePropertySet("Value",("=H"+
                           IntToStr(i+7)+"/C"+IntToStr(i+7)+"*100").c_str() );

  v1.OlePropertyGet("Cells").OlePropertyGet("Item",i+7,11).
                                               OlePropertySet("Value",("=J"+
                           IntToStr(i+7)+"/C"+IntToStr(i+7)+"*100").c_str() );

  v1.OlePropertyGet("Cells").OlePropertyGet("Item",i+7,13).
                                               OlePropertySet("Value",("=L"+
                           IntToStr(i+7)+"/C"+IntToStr(i+7)+"*100").c_str() );

  v1.OlePropertyGet("Cells").OlePropertyGet("Item",i+7,15).
                                               OlePropertySet("Value",("=N"+
                           IntToStr(i+7)+"/C"+IntToStr(i+7)+"*100").c_str() );
// ПОДСЧЕТ СУММ
v1.OlePropertyGet("Cells").OlePropertyGet("Item",i+7,2).OlePropertySet("Value",
                    "Итого:");

v1.OlePropertyGet("Cells",i+7,3).
   OlePropertySet("FormulaR1C1",("=СУММ(R[-"+ IntToStr(i) +"]C:R[-1]C)").c_str());

v1.OlePropertyGet("Cells",i+7,4).
   OlePropertySet("FormulaR1C1",("=СУММ(R[-"+ IntToStr(i) +"]C:R[-1]C)").c_str());

v1.OlePropertyGet("Cells",i+7,6).
   OlePropertySet("FormulaR1C1",("=СУММ(R[-"+ IntToStr(i) +"]C:R[-1]C)").c_str());

v1.OlePropertyGet("Cells",i+7,8).
   OlePropertySet("FormulaR1C1",("=СУММ(R[-"+ IntToStr(i) +"]C:R[-1]C)").c_str());

v1.OlePropertyGet("Cells",i+7,10).
   OlePropertySet("FormulaR1C1",("=СУММ(R[-"+ IntToStr(i) +"]C:R[-1]C)").c_str());

v1.OlePropertyGet("Cells",i+7,12).
   OlePropertySet("FormulaR1C1",("=СУММ(R[-"+ IntToStr(i) +"]C:R[-1]C)").c_str());

v1.OlePropertyGet("Cells",i+7,14).
   OlePropertySet("FormulaR1C1",("=СУММ(R[-"+ IntToStr(i) +"]C:R[-1]C)").c_str());

  CustomerData->QueryBook->Next();
}// while   !CustomerData->QueryBook->Eof
//=====================

//отключить диагностику при закрытии сервера
FX.OlePropertySet("DisplayAlerts",false);
s[0]='\0';
strcat(s,"форма4_");
strcat(s,FormatDateTime("mmmm_d_yyyy",FormDayMonthYear->DateTimePicker1->Date).c_str() );

FX.OlePropertyGet("Workbooks").OlePropertyGet("Item",1).OleProcedure("SaveAs",s);
FX.Clear();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N51Click(TObject *Sender)
{
Variant FX,v0,v1,v2;
char s[100];
int i,j;
AnsiString sFile = GetCurrentDir()+"\\форма5_ed.xls";


FormMonthYear->ShowModal(); // форма выбора месяца и года
if (FormMonthYear->ModalResult==mrCancel) return;

FX=CreateOleObject("Excel.Application");

// открытие файла
try{
FX.OlePropertyGet("WorkBooks").OleProcedure("Open",sFile.c_str(),0,false,1);
} catch(...){
Application->MessageBox(
"Ошибка открытия файла: форма5_ed.xls!","Ошибка",MB_OK+MB_ICONERROR);
}

FX.OlePropertySet("Visible",true);
v0=FX.OlePropertyGet("WorkSheets",1);

//========== Формирование списка направлений
  CustomerData->QueryBook->Close();
  CustomerData->QueryBook->SQL->Clear();
  CustomerData->QueryBook->SQL->Add("select * from s12_book2 where mnemo_i is not null ");
  CustomerData->QueryBook->SQL->Add("and mnemo_i <>'' order by ");
  CustomerData->QueryBook->SQL->Add("mnemo_i");

  CustomerData->QueryBook->Open();
  CustomerData->QueryBook->First();
//==========

while(!CustomerData->QueryBook->Eof)
{
  FX.OlePropertyGet("Cells").OlePropertyGet("Select"); // NEW
  FX.OlePropertyGet("Selection").OleProcedure("Copy");
  v0=FX.OlePropertyGet("Worksheets") ;
        v0.OlePropertyGet("Add");
        v1=v0.OlePropertyGet("Item",1);
        v1.OlePropertySet("Name", CustomerData->QueryBook->FieldByName("name")->AsString.c_str());
  FX.OlePropertyGet("ActiveSheet").OleProcedure("Paste");

  v1.OlePropertyGet("Cells").OlePropertyGet("Item",3,2).OlePropertySet("Value",
                   CustomerData->QueryBook->FieldByName("mnemo_i")->AsString.c_str());
// очищение данных предыдущего направления
  v1.OlePropertyGet("Range","A7:P40").OlePropertyGet("ClearContents"); // ver 2.4

  CustomerData->Query1->SQL->Clear();
//
CustomerData->Query1->SQL->Add("select data, ");
CustomerData->Query1->SQL->Add("SEIZ, ANSWER, [ANSWER%SEIZ], CD_BUSY, [CD_BUSY%SEIZ], ");
CustomerData->Query1->SQL->Add("NO_ANSWER, [NO_ANSWER%SEIZ], NO_SIG_OVL, [NO_SIG_OVL%SEIZ], ");
CustomerData->Query1->SQL->Add("INVC, [INVC%SEIZ], PSIG, [PSIG%SEIZ] ");
CustomerData->Query1->SQL->Add(" from form5_sum ");
CustomerData->Query1->SQL->Add("where ");

CustomerData->Query1->SQL->Add("  year(data)=");
CustomerData->Query1->SQL->Add(FormMonthYear->MaskEdit1->Text);
CustomerData->Query1->SQL->Add(" and month(data)=");
CustomerData->Query1->SQL->Add(IntToStr(
      FormMonthYear->ComboBox1->Items->IndexOf(FormMonthYear->ComboBox1->Text)+1).c_str() );


 s[0]='\0';
 strcat(s," and inc_tkg='");
 strcat(s,CustomerData->QueryBook->FieldByName("mnemo_i")->AsString.c_str());
 strcat(s,"'");
 CustomerData->Query1->SQL->Add(s);
 CustomerData->Query1->SQL->Add("order by inc_tkg,data ");

CustomerData->Query1->Open();
CustomerData->Query1->First();

for (i=0;i<=CustomerData->Query1->RecordCount-1;i++)
{

  for(j=0;j<=13; j++)
  {
  v1.OlePropertyGet("Cells").OlePropertyGet("Item",i+7,j+2).OlePropertySet("Value",
                    CustomerData->Query1->Fields->Fields[j]->AsString.c_str() );
  }
  if(!CustomerData->Query1->Eof) CustomerData->Query1->Next();
}

 v1.OlePropertyGet("Cells").OlePropertyGet("Item",i+7,5).
                                               OlePropertySet("Value",("=D"+
                           IntToStr(i+7)+"/C"+IntToStr(i+7)+"*100").c_str() );

  v1.OlePropertyGet("Cells").OlePropertyGet("Item",i+7,7).
                                               OlePropertySet("Value",("=F"+
                           IntToStr(i+7)+"/C"+IntToStr(i+7)+"*100").c_str() );

  v1.OlePropertyGet("Cells").OlePropertyGet("Item",i+7,9).
                                               OlePropertySet("Value",("=H"+
                           IntToStr(i+7)+"/C"+IntToStr(i+7)+"*100").c_str() );

  v1.OlePropertyGet("Cells").OlePropertyGet("Item",i+7,11).
                                               OlePropertySet("Value",("=J"+
                           IntToStr(i+7)+"/C"+IntToStr(i+7)+"*100").c_str() );

  v1.OlePropertyGet("Cells").OlePropertyGet("Item",i+7,13).
                                               OlePropertySet("Value",("=L"+
                           IntToStr(i+7)+"/C"+IntToStr(i+7)+"*100").c_str() );

  v1.OlePropertyGet("Cells").OlePropertyGet("Item",i+7,15).
                                               OlePropertySet("Value",("=N"+
                           IntToStr(i+7)+"/C"+IntToStr(i+7)+"*100").c_str() );
// ПОДСЧЕТ СУММ
v1.OlePropertyGet("Cells").OlePropertyGet("Item",i+7,2).OlePropertySet("Value",
                    "Итого:");

v1.OlePropertyGet("Cells",i+7,3).
   OlePropertySet("FormulaR1C1",("=СУММ(R[-"+ IntToStr(i) +"]C:R[-1]C)").c_str());

v1.OlePropertyGet("Cells",i+7,4).
   OlePropertySet("FormulaR1C1",("=СУММ(R[-"+ IntToStr(i) +"]C:R[-1]C)").c_str());

v1.OlePropertyGet("Cells",i+7,6).
   OlePropertySet("FormulaR1C1",("=СУММ(R[-"+ IntToStr(i) +"]C:R[-1]C)").c_str());

v1.OlePropertyGet("Cells",i+7,8).
   OlePropertySet("FormulaR1C1",("=СУММ(R[-"+ IntToStr(i) +"]C:R[-1]C)").c_str());

v1.OlePropertyGet("Cells",i+7,10).
   OlePropertySet("FormulaR1C1",("=СУММ(R[-"+ IntToStr(i) +"]C:R[-1]C)").c_str());

v1.OlePropertyGet("Cells",i+7,12).
   OlePropertySet("FormulaR1C1",("=СУММ(R[-"+ IntToStr(i) +"]C:R[-1]C)").c_str());

v1.OlePropertyGet("Cells",i+7,14).
   OlePropertySet("FormulaR1C1",("=СУММ(R[-"+ IntToStr(i) +"]C:R[-1]C)").c_str());

  CustomerData->QueryBook->Next();
}// while   !CustomerData->QueryBook->Eof
//=====================

//отключить диагностику при закрытии сервера
FX.OlePropertySet("DisplayAlerts",false);
s[0]='\0';
strcat(s,"форма5_");
strcat(s,IntToStr(
      FormMonthYear->ComboBox1->Items->IndexOf(FormMonthYear->ComboBox1->Text)+1).c_str() );
strcat(s,"_");
strcat(s,FormMonthYear->MaskEdit1->Text.c_str() );

FX.OlePropertyGet("Workbooks").OlePropertyGet("Item",1).OleProcedure("SaveAs",s);
//FX.OleProcedure("Quit");
FX.Clear();

}
//---------------------------------------------------------------------------

void __fastcall TMainForm::PABX3Click(TObject *Sender)
{
 MenuItem(5,"toPABX");
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::PABX2Click(TObject *Sender)
{
  MenuItem(5,"fromPABX");
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N321Click(TObject *Sender)
{
// Приложение 3.2
Variant FX,v0,v1,v2;
char s[160];
int i,j;
AnsiString m[6];
Word Year1, Month1, Day1;

float m1[25],c;
int e,d[24]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23};

m[1]="05";
m[2]="06";
m[3]="07";
m[4]="08";
m[5]="09";

AnsiString sFile = GetCurrentDir()+"\\Приложение 3_2.xls";
//AnsiString sFile = GetCurrentDir()+"\\форма4_АТС_makros.xls";

FormDMY_32->ShowModal(); // форма выбора месяца и года
if (FormDMY_32->ModalResult==mrCancel) return;

DecodeDate(FormDMY_32->DateTimePicker1->Date, Year1, Month1, Day1);
        for(i=1;i<=5;i++)
        {
          if(Day1+i-1<10) {m[i]="0"+IntToStr(Day1+i-1);}
          else {m[i]=IntToStr(Day1+i-1);}
        }

FX=CreateOleObject("Excel.Application");

// открытие файла
try{
FX.OlePropertyGet("WorkBooks").OleProcedure("Open",sFile.c_str(),0,false,1);
} catch(...){
Application->MessageBox(
"Ошибка открытия файла: Приложение 3_2.xls!","Ошибка",MB_OK+MB_ICONERROR);
}

FX.OlePropertySet("Visible",true);
//FX.OleProcedure("Run","Форма4_АТС"); TRUE
v0=FX.OlePropertyGet("WorkSheets",1);

v0=FX.OlePropertyGet("Worksheets") ;
//========== Формирование списка направлений
  CustomerData->QueryBook->Close();
  CustomerData->QueryBook->SQL->Clear();
  if(FormDMY_32->RB_IN->Checked)
  {
    CustomerData->QueryBook->SQL->Add("select * from s12_book2 where mnemo_i is not null order by ");
    CustomerData->QueryBook->SQL->Add("mnemo_i");
  }
  else
  {
    CustomerData->QueryBook->SQL->Add("select * from s12_book2 where mnemo_o is not null order by ");
    CustomerData->QueryBook->SQL->Add("mnemo_o");
  }

  CustomerData->QueryBook->Open();
  CustomerData->QueryBook->First();

  while(!CustomerData->QueryBook->Eof)
  {
FX.OlePropertyGet("Cells").OlePropertyGet("Select"); // NEW
FX.OlePropertyGet("Selection").OleProcedure("Copy");
        v0.OlePropertyGet("Add");
        v1=v0.OlePropertyGet("Item",1);
        v1.OlePropertySet("Name", CustomerData->QueryBook->FieldByName("name")->AsString);
FX.OlePropertyGet("ActiveSheet").OleProcedure("Paste");

// Название заголовка листа
  v1.OlePropertyGet("Cells").OlePropertyGet("Item",4,5).OlePropertySet("Value",
      CustomerData->QueryBook->FieldByName("name")->AsString);
 if(FormDMY_32->RB_IN->Checked)
   v1.OlePropertyGet("Cells").OlePropertyGet("Item",4,8).OlePropertySet("Value",
      "Входящие");
  else
   v1.OlePropertyGet("Cells").OlePropertyGet("Item",4,8).OlePropertySet("Value",
      "Исходящие");
// жирный шрифт
 v1.OlePropertyGet("Cells").OlePropertyGet("Item",4,5).
   OlePropertyGet("Font").OlePropertySet("Bold",true);
 v1.OlePropertyGet("Cells").OlePropertyGet("Item",4,8).
   OlePropertyGet("Font").OlePropertySet("Bold",true);


 for(j=1;j<=5; j++)
  {
//ShowMessage(CustomerData->QueryBook->FieldByName("name")->AsString);
        CustomerData->Query1->SQL->Clear();
        s[0]='\0';
        strcat(s,"select data,t_begin,t_end,avlb_occ,occ from ");
    if(FormDMY_32->RB_IN->Checked) strcat(s," maket_inc ");
    else strcat(s," maket_out ");
        strcat(s," where data in ('");//2005-");//11-");
        strcat(s,IntToStr(Year1).c_str() ); // год
        strcat(s,"-");
        if(Month1<10) strcat(s,"0");        // месяц
        strcat(s,IntToStr(Month1).c_str() );
        strcat(s,"-");
        strcat(s,m[j].c_str());             // день
        strcat(s,"') ");
    if(FormDMY_32->RB_IN->Checked)
    {
      strcat(s," and inc_tkg='");
      strcat(s,CustomerData->QueryBook->FieldByName("mnemo_i")->AsString.c_str());
    }
    else
    {
      strcat(s," and out_tkg='");
      strcat(s,CustomerData->QueryBook->FieldByName("mnemo_o")->AsString.c_str());
    }
          strcat(s,"' ");
        CustomerData->Query1->SQL->Add(s);
        CustomerData->Query1->SQL->Add(" order by t_begin");
        CustomerData->Query1->Open();
        CustomerData->Query1->First();

    for (int i=0;i<=CustomerData->Query1->RecordCount-1;i++)
    {
     v1.OlePropertyGet("Cells").OlePropertyGet("Item",11+i,1).OlePropertySet("Value",
            CustomerData->Query1->FieldByName("T_BEGIN")->AsString+"-"+
            CustomerData->Query1->FieldByName("T_END")->AsString);
     v1.OlePropertyGet("Cells").OlePropertyGet("Item",11+i,j*2).OlePropertySet("Value",
            CustomerData->Query1->FieldByName("avlb_occ")->AsString);
     v1.OlePropertyGet("Cells").OlePropertyGet("Item",11+i,j*2+1).OlePropertySet("Value",
            CustomerData->Query1->FieldByName("occ")->AsString);

     CustomerData->Query1->Next();
    }
     v1.OlePropertyGet("Cells").OlePropertyGet("Item",8,j*2).OlePropertySet("Value",
                    "Дата:"+CustomerData->Query1->FieldByName("data")->AsString);

  }

// подсчет сумм
   for(i=1;i<=24;i++)
   {
         s[0]='\0';
         strcat(s,"=(");
         strcat(s,"C");
         strcat(s,IntToStr(i+10).c_str());       strcat(s,"+");
         strcat(s,"E");
         strcat(s,IntToStr(i+10).c_str());       strcat(s,"+");
         strcat(s,"G");
         strcat(s,IntToStr(i+10).c_str());       strcat(s,"+");
         strcat(s,"I");
         strcat(s,IntToStr(i+10).c_str());       strcat(s,"+");
         strcat(s,"K");
         strcat(s,IntToStr(i+10).c_str());
         strcat(s,")/5");
         v1.OlePropertyGet("Cells").OlePropertyGet("Item",10+i,12).
                                    OlePropertySet("Value",s);
         m1[i-1]=v1.OlePropertyGet("Cells").OlePropertyGet("Item",10+i,12);
         d[i-1]=i-1;        // инициализация

   }
// MAX
        for(i=0;i<24;i++)
        {
          for(j=i+1;j<24;j++)
          {
            if(m1[i]<m1[j])
            {
                c=m1[j];  m1[j]=m1[i];  m1[i]=c;
                e=d[j];   d[j]=d[i];    d[i]=e;
            }
          } // end j
        }  // end i
   v1.OlePropertyGet("Cells").OlePropertyGet("Item",36,4).
      OlePropertySet("Value",
         v1.OlePropertyGet("Cells").OlePropertyGet("Item",d[0]+11,1));

   v1.OlePropertyGet("Cells").OlePropertyGet("Item",36,10).
      OlePropertySet("Value",
         v1.OlePropertyGet("Cells").OlePropertyGet("Item",d[1]+11,1));
// -- end MAX

CustomerData->QueryBook->Next();
  }
//отключить диагностику при закрытии сервера
FX.OlePropertySet("DisplayAlerts",false);
s[0]='\0';
    if(FormDMY_32->RB_IN->Checked)
    {
        strcat(s,"П32_Входящие_");
    }
    else
    {
        strcat(s,"П32_Исходящие_");
    }

FX.OlePropertyGet("Workbooks").OlePropertyGet("Item",1).OleProcedure("SaveAs",s);
//FX.OleProcedure("Quit");
FX.Clear();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N14Click(TObject *Sender)
{
        RunForm(GetCurrentDir()+"\\форма4_АТС_makros.xls","Форма4_АТС");
}
//---------------------------------------------------------------------------

bool TMainForm::RunForm(String sFile, AnsiString sMakros)
{
Variant FX;
//AnsiString sFile = GetCurrentDir()+"\\форма4_АТС_makros.xls";


FX=CreateOleObject("Excel.Application");

// открытие файла
try{
FX.OlePropertyGet("WorkBooks").OleProcedure("Open",sFile.c_str() );//,0,false,1);
} catch(...){
Application->MessageBox(sFile.c_str(),
                        "Ошибка открытия файла",MB_OK+MB_ICONERROR);
return false;
}

FX.OlePropertySet("Visible",true);
FX.OleProcedure("Run",sMakros.c_str() ); // Запуск макроса

//отключить диагностику при закрытии сервера
FX.OlePropertySet("DisplayAlerts",false);

FX.OleProcedure("Quit");
FX.Clear();
return true;
}

void __fastcall TMainForm::N20Click(TObject *Sender)
{
   RunForm(GetCurrentDir()+"\\форма4_зона_makros.xls","Форма4_Зона");
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N21Click(TObject *Sender)
{
   RunForm(GetCurrentDir()+"\\форма4_makros.xls","форма4");
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N22Click(TObject *Sender)
{
   RunForm(GetCurrentDir()+"\\форма5_АТС_makros.xls","форма5_АТС");
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N23Click(TObject *Sender)
{
   RunForm(GetCurrentDir()+"\\форма5_зона_makros.xls","форма5_Зона");
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N24Click(TObject *Sender)
{
   RunForm(GetCurrentDir()+"\\форма5_makros.xls","Форма5");
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N25Click(TObject *Sender)
{
   RunForm(GetCurrentDir()+"\\makros forma 7 ЮТК АТС.xls",
           "формирование_формы_7_для_ЮТК_АТС");
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N26Click(TObject *Sender)
{
   RunForm(GetCurrentDir()+"\\makros forma 7 ЮТК Зона.xls",
           "формирование_формы_7_для_ЮТК_Зона");
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N27Click(TObject *Sender)
{
   RunForm(GetCurrentDir()+"\\makros forma 7 ЮТК.xls",
           "формирование_формы_7_для_ЮТК");
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N72Click(TObject *Sender)
{
   RunForm(GetCurrentDir()+"\\форма7_makros.xls","форма7");
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N28Click(TObject *Sender)
{
     RunForm(GetCurrentDir()+"\\form_svodka.xls","Сводка");        
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N29Click(TObject *Sender)
{
char sq[13];   // '2006-03-21'
  if(FormDayMonthYear1->ShowModal()==mrCancel) return;
  else
   {
   CustomerData->QueryExec->SQL->Clear();
   CustomerData->QueryExec->SQL->Add("exec sp_CalcOnDate_in_out ");
   strcpy(sq,"'");
   strcat(sq,
     FormatDateTime("yyyy-mm-dd",FormDayMonthYear1->DateTimePicker1->Date).c_str() );
   strcat(sq,"'");
   CustomerData->QueryExec->SQL->Add(sq);
   CustomerData->QueryExec->ExecSQL();
   ShowMessage("Расчет закончен");
  }

}
//---------------------------------------------------------------------------


void __fastcall TMainForm::N30Click(TObject *Sender)
{
CustomerData->Query2->Active=false;
CustomerData->Query2->SQL->Clear();
CustomerData->Query2->SQL->Add("select * from Date");
CustomerData->Query2->Active=true;
CustomerData->Query2->First();
if (!CustomerData->Query2->Eof) StatDateForm->DateTimePicker1->DateTime=CustomerData->Query2->FieldByName("date")->AsDateTime;
else StatDateForm->DateTimePicker1->DateTime=Date();
CustomerData->Query2->Active=false;
StatDateForm->Result=0;
StatDateForm->ShowModal();

if (StatDateForm->Result==12)
        {
         CustomerData->Query2->Active=false;
         CustomerData->Query2->SQL->Clear();
         CustomerData->Query2->SQL->Add("delete from Date");
         CustomerData->Query2->ExecSQL();
         CustomerData->Query2->Active=false;
         CustomerData->Query2->SQL->Clear();
         CustomerData->Query2->SQL->Add("insert Date Values (\""+StatDateForm->DateTimePicker1->DateTime.FormatString("mm.dd.yyyy")+"\")");
         CustomerData->Query2->ExecSQL();
        }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FormShow(TObject *Sender)
{
CustomerData->Database1->Connected=false;
  CustomerData->Database1->Params->Values["User Name"]=BDUser;
  CustomerData->Database1->Params->Values["Database Name"]=BDName;
  CustomerData->Database1->Params->Values["Server Name"]=BDServer;
  CustomerData->Database1->Params->Values["Password"]=BDPassword;

  try {CustomerData->Database1->Connected=true;}
          catch(...) {ShowMessage("Не могу подключится к "+BDServer+" алиас "+CustomerData->Database1->DatabaseName+" User "+BDUser );return;}
       
}
//---------------------------------------------------------------------------

