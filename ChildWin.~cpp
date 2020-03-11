//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "ChildWin.h"
#include "DM.h"
#include "UnitAnalisys.h"
#include "Main.h"
#include "UnitQuickRepIN.h"

#include <string.h>
//---------------------------------------------------------------------
#pragma link "RXDBCtrl"
#pragma link "DbPrgrss"
#pragma resource "*.dfm"
//---------------------------------------------------------------------
__fastcall TMDIChild::TMDIChild(TComponent *Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------
void __fastcall TMDIChild::FormClose(TObject *Sender, TCloseAction &Action)
{
	Action = caFree;
        Query1->Close();
       if(MainForm->MDIChildCount==1)
       {
         MainForm->ToolButtonPrint->Enabled=False;
         MainForm->STFieldName->Caption="";
       }
}
//---------------------------------------------------------------------
void __fastcall TMDIChild::FormCreate(TObject *Sender)
{
TStrings* ListFields = new TStringList();

    try
    {
        Query1->SQL->Clear();
        Query1->SQL->Add(sqls);
        if (!Query1->Prepared) Query1->Prepare();
        Query1->Open();
          // заполнение переменных Field1Query1,Field1Query2
          Query1->GetFieldNames((TStrings *)ListFields);
          strcpy(Field1Query1,ListFields->Strings[0].c_str() );
          delete ListFields;
          if(strcmp(Field1Query1,"INC_TKG")==0)
          {
            strcpy(Field1Query2,"OUT_TKG");
            this->Tag=1; // входящие
          }
          else
          {
             strcpy(Field1Query2,"INC_TKG");
            this->Tag=2; // исходящие
          }
        // ---------------------------------
        // открытие запроса для расчета КИС
        // ---------------------------------
           Query2->SQL->Clear();
           Query2->SQL->Add(sqls2);
           if (!Query2->Prepared) Query2->Prepare();
           Query2->Open();

        // ---------------------------------
        // Число записей
        StatusBar1->Panels->Items[1]->Text=IntToStr(Query1->RecordCount);
        // Условие отбора
        if(FormCondition->RBCondition->Checked)
         StatusBar1->Panels->Items[3]->Text=" "+FormCondition->ComboBoxFields->Text+
                                           FormCondition->ComboBox3->Text+
                                           FormCondition->ComboBox4->Text;
        // Период
        if(strcmp(DateToStr(FormCondition->DateTimePicker1->Date).c_str(),
                  DateToStr(FormCondition->DateTimePicker2->Date).c_str())==0)
        {
           StatusBar1->Panels->Items[5]->Text=
                       " "+DateToStr(FormCondition->DateTimePicker1->Date);
        }
        else
        {
           StatusBar1->Panels->Items[5]->Text=" c "+
                        DateToStr(FormCondition->DateTimePicker1->Date)+" по "+
                        DateToStr(FormCondition->DateTimePicker2->Date);
        }
        // Время
        StatusBar1->Panels->Items[7]->Text=" c "+
                        IntToStr(FormCondition->CSpinEdit1->Value)+" до "+
                        IntToStr(FormCondition->CSpinEdit2->Value);

        if (MainForm->N6Fields->Checked==True)
        {
            for(int i=1;i<RxDBGrid1->Columns->Count-3;i++)
               RxDBGrid1->Columns->Items[i+3]->Width=35;
        }
        else
        {
            for(int i=1;i<RxDBGrid1->Columns->Count-3;i++)
               RxDBGrid1->Columns->Items[i+3]->Width=50;

        }


/*        RxDBGrid1->Columns->Items[5]->Width=40;
        RxDBGrid1->Columns->Items[6]->Width=40;
        RxDBGrid1->Columns->Items[10]->Width=40;*/
    }
    catch (...)
    {
     MessageDlg("Ошибка в запросе.  Попробуйте еще раз. \n Если это не поможет обратитесь к программисту.(Модуль ChildWin)", mtWarning, TMsgDlgButtons() << mbOK, 0);
    }
/*    __finally
    {
       delete ListFields;
    }*/
}
//---------------------------------------------------------------------------

void __fastcall TMDIChild::DBGrid1DrawColumnCell(TObject *Sender,
      const TRect &Rect, int DataCol, TColumn *Column,
      TGridDrawState State)
{
TLocateOptions Opts;   // для задания опций поиска
Variant locvalues[2]; // для параметров поиска
char strFields[13]; // для строки "inc_tkg;data" или "out_tkg;data"

Opts << loCaseInsensitive;
locvalues[0]=Variant(Column->Field->DataSet->FieldByName(Field1Query1)->AsString);
locvalues[1]=Variant(Column->Field->DataSet->FieldByName("data")->AsString);
        strcpy(strFields,Field1Query2);
        strcat(strFields,";data");
        if(Column->Field->FieldName=="KIS")
        {
          if (Column->Field->DataSet->FieldByName("AVLB_OCC")->Value>0)
          {
             if(
                Column->Field->DataSet->FieldByName(Field1Query1)->AsString.Pos("_N7")>0 )
             {
                     if(Query2->Locate(strFields, // поиск
                       VarArrayOf(locvalues,1),
                       Opts))
                     {
                       RxDBGrid1->Canvas->TextOut(Rect.Left+2,Rect.Top+2,
                         (Query2->FieldByName("occ")->AsFloat+
                         Column->Field->DataSet->FieldByName("OCC")->AsFloat)/
                         Column->Field->DataSet->FieldByName("AVLB_OCC")->AsFloat);

                     }

             }
             else
             {
                RxDBGrid1->Canvas->TextOut(Rect.Left+2,Rect.Top+2,
                RxDBGrid1->DataSource->DataSet->FieldByName("OCC")->AsFloat/
                RxDBGrid1->DataSource->DataSet->FieldByName("AVLB_OCC")->AsFloat);
             }
          }

        }
}
//---------------------------------------------------------------------------


void __fastcall TMDIChild::RxDBGrid1DrawColumnCell(TObject *Sender,
      const TRect &Rect, int DataCol, TColumn *Column,
      TGridDrawState State)
{
TLocateOptions Opts;   // для задания опций поиска
Variant locvalues[2]; // для параметров поиска
char strFields[13]; // для строки "inc_tkg;data" или "out_tkg;data"

Opts << loCaseInsensitive;
locvalues[0]=Variant(Column->Field->DataSet->FieldByName(Field1Query1)->AsString);
locvalues[1]=Variant(Column->Field->DataSet->FieldByName("data")->AsString);
        strcpy(strFields,Field1Query2);
        strcat(strFields,";data");
/*        if(Column->Field->FieldName=="KIS")
        {
          if (Column->Field->DataSet->FieldByName("AVLB_OCC")->Value>0)
          {
             if(
                Column->Field->DataSet->FieldByName(Field1Query1)->AsString.Pos("_N7")>0 )
             {
                locvalues[0]=Variant(Column->Field->DataSet->FieldByName(Field1Query1)->AsString);
                locvalues[1]=Variant(Column->Field->DataSet->FieldByName("data")->AsString);

                     if(Query2->Locate(strFields, // поиск
                       VarArrayOf(locvalues,1),
                       Opts))
                     {
                       RxDBGrid1->Canvas->TextOut(Rect.Left+2,Rect.Top+2,
                         (Query2->FieldByName("occ")->AsFloat+
                         Column->Field->DataSet->FieldByName("OCC")->AsFloat)/
                         Column->Field->DataSet->FieldByName("AVLB_OCC")->AsFloat);

                     }

             }
             else
             {
                RxDBGrid1->Canvas->TextOut(Rect.Left+2,Rect.Top+2,
                RxDBGrid1->DataSource->DataSet->FieldByName("OCC")->AsFloat/
                RxDBGrid1->DataSource->DataSet->FieldByName("AVLB_OCC")->AsFloat);
             }
          }

        } рабочий код */
        // -----   Вывод OCC_N7   ------
/*        if(Column->Field->FieldName=="OCC_N7")
        {
            if(
                Column->Field->DataSet->FieldByName(Field1Query1)->AsString.Pos("_N7")>0 )
             {
                     if(Query2->Locate(strFields, // поиск
                       VarArrayOf(locvalues,1),
                       Opts))
                     {
                       RxDBGrid1->Canvas->TextOut(Rect.Left+2,Rect.Top+2,
                         Query2->FieldByName("occ")->AsFloat);
                     }

             }

        } работающий код - убран за ненадобностью*/
        // ----- Вывод ASS -----
/*        if(Column->Field->FieldName=="OCC_N7")
        {
              if(CustomerData->QueryBook->Locate("mnemo_i", // поиск
                Column->Field->DataSet->FieldByName(Field1Query1)->AsString,
              //                 VarArrayOf(locvalues,0),
                  Opts))
              {
                RxDBGrid1->Canvas->TextOut(Rect.Left+2,Rect.Top+2,
                CustomerData->QueryBook->FieldByName("inc")->AsFloat);
              }
        }  /* работает для входящих*/
        // =====

//        ShowMessage(StatusBar1->Panels->Items[8]->Text);
//  try
//  {
//  if(strcmp(StatusBar1->Panels->Items[8]->Text.c_str(),"PABX")==0)
//  {
    if(Query1->RecordCount>0)
    {
        if ( ( Query1->FieldByName("ANSWER%SEIZ")->Value <30) &&
             (Query1->FieldByName("SEIZ")->Value >0 ) )

        {
            RxDBGrid1->Canvas->Brush->Color=clYellow;
            RxDBGrid1->Canvas->Font->Color=clWindowText;
            RxDBGrid1->Canvas->FillRect(Rect);
                if (Column->Alignment==taRightJustify)
                {
                  RxDBGrid1->Canvas->TextOut(Rect.Right-2-
                  RxDBGrid1->Canvas->TextWidth(Column->Field->Text),
                  Rect.Top+2,Column->Field->Text);
                }
                else
                {
                  RxDBGrid1->Canvas->TextOut(Rect.Left+2,Rect.Top+2,Column->Field->Text);
                }
        } /* желтый */
    } // Query1->RecordCount>0
//  } // проверка PABX
//  }
//  catch(...){
//   ;//ShowMessage(StatusBar1->Panels->Items[8]->Text);
// }


         //RxDBGrid1->DefaultDrawColumnCell(Rect,DataCol,Column,State);

}
//---------------------------------------------------------------------------




void __fastcall TMDIChild::RxDBGrid1CellClick(TColumn *Column)
{
  MainForm->STFieldName->Caption=RxDBGrid1->SelectedField->FullName;
}
//---------------------------------------------------------------------------

void __fastcall TMDIChild::RxDBGrid1ColEnter(TObject *Sender)
{
 MainForm->STFieldName->Caption=RxDBGrid1->SelectedField->FullName;
}
//---------------------------------------------------------------------------


void __fastcall TMDIChild::RxDBGrid1Enter(TObject *Sender)
{
 MainForm->STFieldName->Caption=RxDBGrid1->SelectedField->FullName;
}
//---------------------------------------------------------------------------

void __fastcall TMDIChild::FormActivate(TObject *Sender)
{
//char* ptr=strrchr(this->Caption.c_str(),'P');
//    ptr=strrchr(this->Caption.c_str(),'P');
//    if(ptr==NULL) ShowMessage("NULL");
//    else   ShowMessage(ptr);
//    ShowMessage(this->Caption.c_str());
//         strncpy( ,ptr,4)
//   if(strcmp(this->Caption.c_str(),"PABX")==0) ShowMessage("PABX!");

  // Назавание поля
  MainForm->STFieldName->Caption=RxDBGrid1->SelectedField->FullName;
  RxDBGrid1->Repaint();


}
//---------------------------------------------------------------------------


