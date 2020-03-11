//---------------------------------------------------------------------------

#ifndef UnitGridH
#define UnitGridH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DBCtrls.hpp>
#include <DBGrids.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <jpeg.hpp>
#include <Data.DB.hpp>
//---------------------------------------------------------------------------
class TFormGrid : public TForm
{
__published:	// IDE-managed Components
        TDBGrid *DBGrid1;
        TBevel *Bevel1;
        TDBNavigator *DBNavigator1;
        TBevel *Bevel2;
        TBitBtn *BitBtn1;
        TBitBtn *BitBtn2;
        TStatusBar *StatusBar1;
        TImage *Image1;
        void __fastcall BitBtn1Click(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormActivate(TObject *Sender);
        void __fastcall BitBtn2Click(TObject *Sender);
        void __fastcall FormResize(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFormGrid(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormGrid *FormGrid;
//---------------------------------------------------------------------------
#endif
