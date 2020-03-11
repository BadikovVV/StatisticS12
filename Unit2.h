//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "UnitDayMonthYear1.h"
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TFormDayMonthYear2 : public TFormDayMonthYear1
{
__published:	// IDE-managed Components
private:	// User declarations
public:		// User declarations
        __fastcall TFormDayMonthYear2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormDayMonthYear2 *FormDayMonthYear2;
//---------------------------------------------------------------------------
#endif
