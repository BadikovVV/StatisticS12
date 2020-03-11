//---------------------------------------------------------------------------

#ifndef StatisticDataH
#define StatisticDataH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TStatDateForm : public TForm
{
__published:	// IDE-managed Components
        TDateTimePicker *DateTimePicker1;
        TButton *Button1;
        TButton *Button2;
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall FormKeyPress(TObject *Sender, char &Key);
private:	// User declarations
public:		// User declarations
        __fastcall TStatDateForm(TComponent* Owner);
        int Result;
};
//---------------------------------------------------------------------------
extern PACKAGE TStatDateForm *StatDateForm;
//---------------------------------------------------------------------------
#endif
