//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "DM.h"
#include "ChildWin2.h"
#include "UnitAnalisys.h"
#include "Main.h"
#include "UnitQuickRepIN.h"

#include <string.h>
//---------------------------------------------------------------------
#pragma link "RXDBCtrl"
#pragma link "DbPrgrss"
#pragma resource "*.dfm"
//---------------------------------------------------------------------
__fastcall TMDIChild2::TMDIChild2(TComponent *Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------
void __fastcall TMDIChild2::FormClose(TObject *Sender, TCloseAction &Action)
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
void __fastcall TMDIChild2::FormCreate(TObject *Sender)
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


void __fastcall TMDIChild2::RxDBGrid1CellClick(TColumn *Column)
{
  MainForm->STFieldName->Caption=RxDBGrid1->SelectedField->FullName;
}
//---------------------------------------------------------------------------

void __fastcall TMDIChild2::RxDBGrid1ColEnter(TObject *Sender)
{
 MainForm->STFieldName->Caption=RxDBGrid1->SelectedField->FullName;
}
//---------------------------------------------------------------------------


void __fastcall TMDIChild2::RxDBGrid1Enter(TObject *Sender)
{
 MainForm->STFieldName->Caption=RxDBGrid1->SelectedField->FullName;
}
//---------------------------------------------------------------------------

void __fastcall TMDIChild2::FormActivate(TObject *Sender)
{
  // Назавание поля
  MainForm->STFieldName->Caption=RxDBGrid1->SelectedField->FullName;
  RxDBGrid1->Repaint();
}
//---------------------------------------------------------------------------


