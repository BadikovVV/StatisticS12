//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitQuickRep.h"
#include "ChildWin.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormQuickRep *FormQuickRep;
//---------------------------------------------------------------------------
__fastcall TFormQuickRep::TFormQuickRep(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
