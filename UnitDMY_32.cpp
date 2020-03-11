//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitDMY_32.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "UnitDayMonthYear"
#pragma resource "*.dfm"
TFormDMY_32 *FormDMY_32;
//---------------------------------------------------------------------------
__fastcall TFormDMY_32::TFormDMY_32(TComponent* Owner)
        : TFormDayMonthYear(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormDMY_32::FormCreate(TObject *Sender)
{
 DateTimePicker1->DateTime=Now()-5;
}
//---------------------------------------------------------------------------
void __fastcall TFormDMY_32::BitBtn1Click(TObject *Sender)
{
Word Year1, Month1, Day1;
Word Year2, Month2, Day2;

  DecodeDate(DateTimePicker1->Date, Year1, Month1, Day1);
  DecodeDate(DateTimePicker2->Date, Year2, Month2, Day2);
       if( Day2-Day1!=4)
        {
          MessageBox(0,"Ошибка в указании даты.  Число дней в расчитываемой форме = 5",
                       "Внимание! ",MB_OK);
          FormDMY_32->ModalResult=mrNone;
        }
}
//---------------------------------------------------------------------------
