//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitQuickRepIN.h"
#include "ChildWin.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormQuickRepIN *FormQuickRepIN;
//---------------------------------------------------------------------------
__fastcall TFormQuickRepIN::TFormQuickRepIN(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void TFormQuickRepIN::SetDataSet(TDataSet* Data)
{
        QuickRep1->DataSet=Data;
        QRDBText1->DataSet=Data;
        QRDBText2->DataSet=Data;
        QRDBText3->DataSet=Data;
        QRDBText4->DataSet=Data;
        QRDBText5->DataSet=Data;
        QRDBText6->DataSet=Data;
        QRDBText7->DataSet=Data;
        QRDBText8->DataSet=Data;
        QRDBText9->DataSet=Data;
        QRDBText10->DataSet=Data;
        QRDBText11->DataSet=Data;
        QRDBText12->DataSet=Data;
        QRDBText13->DataSet=Data;
        QRDBText14->DataSet=Data;
        QRDBText15->DataSet=Data;
        QRDBText16->DataSet=Data;
        QRDBText17->DataSet=Data;
        QRDBText18->DataSet=Data;
        QRDBText19->DataSet=Data;
        QRDBText20->DataSet=Data;
        QRDBText21->DataSet=Data;
        QRDBText22->DataSet=Data;
        QRDBText23->DataSet=Data;
        QRDBText24->DataSet=Data;        
}








