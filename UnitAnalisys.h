//---------------------------------------------------------------------------

#ifndef UnitAnalisysH
#define UnitAnalisysH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include "CSPIN.h"
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TFormCondition : public TForm
{
__published:	// IDE-managed Components
        TBevel *Bevel1;
        TComboBox *ComboBoxDirection;
        TGroupBox *GroupBox1;
        TRadioButton *RB1Direction;
        TRadioButton *RBAllDirection;
        TGroupBox *GroupBox2;
        TRadioButton *RBCondition;
        TRadioButton *RBWithoutConditions;
        TComboBox *ComboBoxFields;
        TComboBox *ComboBox3;
        TComboBox *ComboBox4;
        TBevel *Bevel2;
        TDateTimePicker *DateTimePicker1;
        TDateTimePicker *DateTimePicker2;
        TCSpinEdit *CSpinEdit1;
        TCSpinEdit *CSpinEdit2;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TBevel *Bevel3;
        TBitBtn *BitBtn1;
        TBitBtn *BitBtn2;
        void __fastcall BitBtn1Click(TObject *Sender);
        void __fastcall RB1DirectionClick(TObject *Sender);
        void __fastcall RBAllDirectionClick(TObject *Sender);
        void __fastcall RBConditionClick(TObject *Sender);
        void __fastcall RBWithoutConditionsClick(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFormCondition(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormCondition *FormCondition;
//---------------------------------------------------------------------------
#endif
