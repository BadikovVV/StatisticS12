//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitMonthYear.h"
#include "Main.h"
#include "DM.h"
#include "UnitGrid.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormMonthYear *FormMonthYear;
//---------------------------------------------------------------------------
__fastcall TFormMonthYear::TFormMonthYear(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormMonthYear::FormCreate(TObject *Sender)
{
  ComboBox1->ItemIndex=StrToInt(FormatDateTime("mm",Now()).c_str())-1;
  MaskEdit1->Text=FormatDateTime("yyyy",Now());
}
//---------------------------------------------------------------------------




