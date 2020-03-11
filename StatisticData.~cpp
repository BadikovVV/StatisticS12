//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "StatisticData.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TStatDateForm *StatDateForm;
//---------------------------------------------------------------------------
__fastcall TStatDateForm::TStatDateForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TStatDateForm::Button1Click(TObject *Sender)
{
Result=12;
Close();
}
//---------------------------------------------------------------------------
void __fastcall TStatDateForm::Button2Click(TObject *Sender)
{
Result=0;
Close();
}
//---------------------------------------------------------------------------
void __fastcall TStatDateForm::FormKeyPress(TObject *Sender, char &Key)
{
if (Key==27)
        {
        Result=0;
        Close();
        }

}
//---------------------------------------------------------------------------
