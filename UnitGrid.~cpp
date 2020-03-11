//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <ComObj.hpp>
#include "utilcls.h"
//#include "xlauto2.h"

#include "UnitGrid.h"
#include "DM.h"
#include "UnitKZO.h"
#include "UnitKZO2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "PicClip"
#pragma resource "*.dfm"
TFormGrid *FormGrid;

Variant FX,v0,v1,v2;
//---------------------------------------------------------------------------
__fastcall TFormGrid::TFormGrid(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormGrid::BitBtn1Click(TObject *Sender)
{
   FormKZO->ShowModal();
   FormKZO2->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TFormGrid::FormCreate(TObject *Sender)
{
/*        CustomerData->Query1->Close();
        CustomerData->Query1->SQL->Clear();
        CustomerData->Query1->SQL->Add("select * from s12_form_kzo1");
        CustomerData->Query1->Open();
        StatusBar1->Panels->Items[1]->Text =
                        IntToStr(CustomerData->Query1->RecordCount);
*/
}
//---------------------------------------------------------------------------

void __fastcall TFormGrid::FormActivate(TObject *Sender)
{
        CustomerData->Query1->Close();
        CustomerData->Query1->SQL->Clear();
        CustomerData->Query1->SQL->Add("select * from s12_form_kzo1");
        CustomerData->Query1->Open();
        StatusBar1->Panels->Items[1]->Text =
                        IntToStr(CustomerData->Query1->RecordCount);

}
//---------------------------------------------------------------------------

void __fastcall TFormGrid::BitBtn2Click(TObject *Sender)
{
char s[50];

FX=CreateOleObject("Excel.Application");
FX.OlePropertySet("Visible",true);

v0=FX.OlePropertyGet("Workbooks");
v0.OleProcedure("Add");
v1=v0.OlePropertyGet("Item",1);
v0=v1.OlePropertyGet("Worksheets") ;
v0.OlePropertyGet("Item",1).OlePropertySet("Name","Значения КЗО с 10 до 11");

//v0.OlePropertyGet("Item",2).OlePropertySet("Name","Бухгалтерия красная");
//for (int j=1;j<3;j++)
//{
//v1=v0.OlePropertyGet("Item",j);
//DBGrid1->Fields[0]->AsString
/*for (int i=1;i<11;i++)
{
v1.OlePropertyGet("Cells").OlePropertyGet("Item",i,1).OlePropertySet("Value",i);
v1.OlePropertyGet("Cells").OlePropertyGet("Item",i,2).OlePropertySet("Value",i*5);
v2=v1.OlePropertyGet("Cells").OlePropertyGet("Item",i,2);
v2.OlePropertyGet("Font").OlePropertySet("Color",clBlue);
v2.OlePropertyGet("Font").OlePropertySet("Bold",true);
v2.OlePropertyGet("Interior").OlePropertySet("ColorIndex",9-3*j);
} */

//CustomerData->Query1->Fields->Fields->AsString;
//v1.OlePropertyGet("Cells").OlePropertyGet("Item",1,1).OlePropertySet(
//"Value",CustomerData->Query1->Fields->Fields[0]->AsString);
// Получить число полей и число записей

//===    Columns("F:F").ColumnWidth = 8
//v1.OlePropertyGet("Columns").OlePropertyGet("Value","A:A");
//OlePropertyGet("ColumnWidth").OlePropertySet("Value","14");
//=================
v1=v0.OlePropertyGet("Item",1);

s[0]='\0';
strcat(s,"Значения КЗО с 10:00 до 11:00 за ");
strcat(s,FormKZO->ComboBox1->Text.c_str());
strcat(s," ");
strcat(s,FormKZO->MaskEdit1->Text.c_str());
v1.OlePropertyGet("Cells").OlePropertyGet("Item",1,3).
   OlePropertySet("Value",s);
// жирный шрифт
 v2=v1.OlePropertyGet("Cells").OlePropertyGet("Item",1,3);
 v2.OlePropertyGet("Font").OlePropertySet("Bold",true);

// вывод чисел дней
 for(int i=1; i<=30;i++)
 v1.OlePropertyGet("Cells").OlePropertyGet("Item",2,i+1).OlePropertySet("Value",
                    IntToStr(i));

CustomerData->Query1->First();
 for(int i=1; i<=CustomerData->Query1->RecordCount; i++)
{
  for(int j=0;j<=32; j++)
  {
//  D[i,j+1] = CustomerData->Query1->Fields->Fields[j]->AsString;
  v1.OlePropertyGet("Cells").OlePropertyGet("Item",i+2,j+1).OlePropertySet("Value",
                    CustomerData->Query1->Fields->Fields[j]->AsString);
  }
  if(!CustomerData->Query1->Eof) CustomerData->Query1->Next();
}

//v1.OlePropertyGet("Cells").OlePropertyGet("Item",12,1).OlePropertySet("Value",DBGrid1->Fields[0]->AsString);
/*v1.OlePropertyGet("Cells").OlePropertyGet("Item",11,1).OlePropertySet("Value","=СУММ(A1:A10)");
v1.OlePropertyGet("Cells").OlePropertyGet("Item",11,2).OlePropertySet("Value","=СУММ(B1:B10)");*/
//}
FX.OlePropertySet("DisplayAlerts",false); //отключить диагностику при закрытии сервера
s[0]='\0';
strcat(s,"KZO_10_11_");
strcat(s,FormKZO->ComboBox1->Text.c_str());
strcat(s," ");
strcat(s,FormKZO->MaskEdit1->Text.c_str());

FX.OlePropertyGet("Workbooks").OlePropertyGet("Item",1).OleProcedure("SaveAs",s);

//FX.OleProcedure("Quit");
FX.Clear();

}
//---------------------------------------------------------------------------

void __fastcall TFormGrid::FormResize(TObject *Sender)
{
  DBGrid1->Height=FormGrid->Height-237;
  Bevel1->Height=FormGrid->Height-213;
  Bevel2->Top =Bevel1->Height+59;
  DBNavigator1->Top=Bevel2->Top+7;
  BitBtn1->Top=Bevel2->Top+12;
  BitBtn2->Top=Bevel2->Top+12;

  DBGrid1->Width=FormGrid->Width-40;
  Bevel1->Width=FormGrid->Width-24;
  Bevel2->Width=FormGrid->Width-24;
  Image1->Width=FormGrid->Width-24;

  if(FormGrid->Width<870) FormGrid->Width=870;
}
//---------------------------------------------------------------------------

