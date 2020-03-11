//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "DM.h"
//---------------------------------------------------------------------
#pragma resource "*.dfm"
TCustomerData *CustomerData;
//--------------------------------------------------------------------- 
__fastcall TCustomerData::TCustomerData(TComponent* AOwner)
	: TDataModule(AOwner)
{
}
//---------------------------------------------------------------------
void __fastcall TCustomerData::LineItemsCalcFields(TDataSet *DataSet)
{
//	LineItemsExtendedPrice->Value =
//		LineItemsPrice->Value * ((100 - LineItemsDiscount->Value) / 100);


}
//---------------------------------------------------------------------


