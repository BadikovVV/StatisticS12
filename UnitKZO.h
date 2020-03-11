//---------------------------------------------------------------------------

#ifndef UnitKZOH
#define UnitKZOH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <Mask.hpp>
//---------------------------------------------------------------------------
class TFormKZO : public TForm
{
__published:	// IDE-managed Components
        TComboBox *ComboBox1;
        TMaskEdit *MaskEdit1;
        TStaticText *StaticText1;
        TStaticText *StaticText2;
        TBevel *Bevel1;
        TBitBtn *BitBtn1;
        TLabel *Label1;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall BitBtn1Click(TObject *Sender);
        void __fastcall FormActivate(TObject *Sender);
private:	// User declarations
public:		// User declarations
        void TFormKZO::QueryBookToFormKzo1(int kol);
        __fastcall TFormKZO(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormKZO *FormKZO;
//---------------------------------------------------------------------------
#endif
