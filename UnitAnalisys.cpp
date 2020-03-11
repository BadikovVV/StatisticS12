//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitAnalisys.h"
#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CSPIN"
#pragma resource "*.dfm"
TFormCondition *FormCondition;
//---------------------------------------------------------------------------
__fastcall TFormCondition::TFormCondition(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormCondition::BitBtn1Click(TObject *Sender)
{
        if(DateTimePicker1->Date > DateTimePicker2->Date)
        {
          MessageBox(0,"Ошибка в указании даты.  Попробуйте еще раз.",
                       "Внимание! ",MB_OK);
//          MessageDlg("Ошибка в указании даты.  Попробуйте еще раз.", mtWarning, TMsgDlgButtons() << mbOK, 0);
          FormCondition->ModalResult=mrNone;
        }
        if(CSpinEdit1->Value > CSpinEdit2->Value)
        {
         MessageBox(0,"Ошибка в указании времени.  Попробуйте еще раз.",
                       "Внимание! ",MB_OK);
          FormCondition->ModalResult=mrNone;
        }
        MainForm->ToolButtonPrint->Enabled=True;
}
//---------------------------------------------------------------------------

void __fastcall TFormCondition::RB1DirectionClick(TObject *Sender)
{
    ComboBoxDirection->Visible=True;        
}
//---------------------------------------------------------------------------

void __fastcall TFormCondition::RBAllDirectionClick(TObject *Sender)
{
    ComboBoxDirection->Visible=False;        
}
//---------------------------------------------------------------------------

void __fastcall TFormCondition::RBConditionClick(TObject *Sender)
{
    ComboBoxFields->Visible=True;
    ComboBox3->Visible=True;
    ComboBox4->Visible=True;
}
//---------------------------------------------------------------------------

void __fastcall TFormCondition::RBWithoutConditionsClick(TObject *Sender)
{
    ComboBoxFields->Visible=False;
    ComboBox3->Visible=False;
    ComboBox4->Visible=False;
}
//---------------------------------------------------------------------------

void __fastcall TFormCondition::FormCreate(TObject *Sender)
{
      ComboBoxFields->ItemIndex=0;
      ComboBox3->ItemIndex=0;
      ComboBox4->ItemIndex=0;
      RBAllDirection->Checked=True;
      RBWithoutConditions->Checked=True;
      DateTimePicker1->Date=Now();
      DateTimePicker2->Date=Now();
}
//---------------------------------------------------------------------------


