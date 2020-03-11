//---------------------------------------------------------------------------

#ifndef UnitQuickRepOUTH
#define UnitQuickRepOUTH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <QuickRpt.hpp>
#include <Qrctrls.hpp>
#include <Db.hpp>
#include <DBTables.hpp>
//---------------------------------------------------------------------------
class TFormQuickRepOUT : public TForm
{
__published:	// IDE-managed Components
        TQuickRep *QuickRep1;
        TQRBand *QRBand1;
        TQRBand *QRBand2;
        TQRBand *QRBand3;
        TQRDBText *QRDBText1;
        TQRDBText *QRDBText2;
        TQRDBText *QRDBText3;
        TQRLabel *QRLabel1;
        TQRDBText *QRDBText4;
        TQRDBText *QRDBText5;
        TQRDBText *QRDBText6;
        TQRDBText *QRDBText7;
        TQRDBText *QRDBText8;
        TQRDBText *QRDBText9;
        TQRDBText *QRDBText10;
        TQRDBText *QRDBText18;
        TQRDBText *QRDBText19;
        TQRDBText *QRDBText20;
        TQRDBText *QRDBText21;
        TQRDBText *QRDBText11;
        TQRDBText *QRDBText12;
        TQRDBText *QRDBText14;
        TQRDBText *QRDBText15;
        TQRDBText *QRDBText16;
        TQRDBText *QRDBText17;
        TQRDBText *QRDBText13;
        TQRLabel *QRLabel2;
        TQRLabel *QRLabel3;
        TQRLabel *QRLabel4;
        TQRLabel *QRLabel5;
        TQRLabel *QRLabel7;
        TQRLabel *QRLabelTitle;
        TQRLabel *QRLabel8;
        TQRLabel *QRLabel9;
        TQRLabel *QRLabel10;
        TQRLabel *QRLabel11;
        TQRLabel *QRLabel12;
        TQRLabel *QRLabel13;
        TQRLabel *QRLabel14;
        TQRLabel *QRLabel15;
        TQRLabel *QRLabel16;
        TQRLabel *QRLabel17;
        TQRLabel *QRLabel18;
        TQRLabel *QRLabel19;
        TQRLabel *QRLabel20;
        TQRLabel *QRLabel21;
        TQRLabel *QRLabel22;
        TQRLabel *QRLabel23;
        TQRLabel *QRLabel24;
        TQRLabel *QRLabel25;
        TQRLabel *QRLabel26;
        TQRLabel *QRLabel27;
        TQRLabel *QRLabel28;
        TQRLabel *QRLabel31;
        TQRLabel *QRLabel32;
        TQRLabel *QRLabel33;
        TQRShape *QRShape1;
        TQRShape *QRShape2;
        TQRShape *QRShape3;
        TQRShape *QRShape4;
        TQRShape *QRShape5;
        TQRShape *QRShape6;
        TQRShape *QRShape7;
        TQRShape *QRShape8;
        TQRShape *QRShape9;
        TQRShape *QRShape10;
        TQRShape *QRShape11;
        TQRShape *QRShape12;
        TQRShape *QRShape13;
        TQRShape *QRShape15;
        TQRShape *QRShape16;
        TQRBand *QRBand4;
        TQRLabel *QRLabel34;
        TQRExpr *QRExpr1;
        TQRLabel *QRLabel35;
        TQRExpr *QRExpr2;
        TQRLabel *QRLabel36;
        TQRExpr *QRExpr3;
        TQRBand *QRBand5;
        TQRSysData *QRSysData1;
        TQRLabel *QRLabel37;
        TQRShape *QRShape17;
        TQRShape *QRShape18;
        TQRShape *QRShape19;
        TQRShape *QRShape20;
        TQRShape *QRShape21;
        TQRShape *QRShape22;
        TQRShape *QRShape23;
        TQRShape *QRShape24;
        TQRShape *QRShape25;
        TQRShape *QRShape26;
        TQRShape *QRShape27;
        TQRShape *QRShape28;
        TQRShape *QRShape29;
        TQRShape *QRShape30;
        TQRShape *QRShape31;
        TQRShape *QRShape32;
        TQRShape *QRShape33;
        TQRShape *QRShape34;
        TQRShape *QRShape35;
        TQRShape *QRShape36;
        TQRShape *QRShape37;
        TQRShape *QRShape38;
        TQRShape *QRShape39;
        TQRLabel *QRLabel6;
        TQRLabel *QRLabel29;
        TQRShape *QRShape14;
        TQRShape *QRShape40;
        TQRLabel *QRLabel30;
        TQRExpr *QRExpr4;
private:	// User declarations
public:		// User declarations
        __fastcall TFormQuickRepOUT(TComponent* Owner);
        void SetDataSet(TDataSet* Data);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormQuickRepOUT *FormQuickRepOUT;
//---------------------------------------------------------------------------
#endif
