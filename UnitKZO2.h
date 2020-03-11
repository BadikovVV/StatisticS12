//---------------------------------------------------------------------------

#ifndef UnitKZO2H
#define UnitKZO2H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "UnitKZO.h"
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <Mask.hpp>
//---------------------------------------------------------------------------
class TFormKZO2 : public TFormKZO
{
__published:	// IDE-managed Components
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall BitBtn1Click(TObject *Sender);
	void __fastcall ComboBox1Change(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFormKZO2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormKZO2 *FormKZO2;
//---------------------------------------------------------------------------
#endif
