//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitKZO.h"
#include "Main.h"
#include "DM.h"
#include "UnitGrid.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormKZO *FormKZO;
//---------------------------------------------------------------------------
__fastcall TFormKZO::TFormKZO(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormKZO::FormCreate(TObject *Sender)
{
  ComboBox1->ItemIndex=StrToInt(FormatDateTime("mm",Now()).c_str())-1;
  MaskEdit1->Text=FormatDateTime("yyyy",Now());
}
//---------------------------------------------------------------------------
void TFormKZO::QueryBookToFormKzo1(int kol)
{
float answer_sum, seiz_sum;
char  *s=NULL;
       s = (char *) calloc(300, sizeof(char));
       answer_sum=0; seiz_sum=0;

  while (!CustomerData->QueryBook->Eof)
  {
         CustomerData->Query1->Close();
         CustomerData->Query1->SQL->Clear();
// вставка строки в таблицу s12_form_kzo1
         s[0]='\0';
         strcpy(s,"insert into s12_form_kzo1 (name) values ('");
         strcat(s,CustomerData->QueryBook->FieldByName("mnemo_o")->AsString.c_str());
         strcat(s,"')");
         CustomerData->Query1->SQL->Add(s);
         CustomerData->Query1->ExecSQL();
           MainForm->ProgressBar2->Position=0;
           MainForm->ProgressBar2->Max=31;

         answer_sum=0; seiz_sum=0;
         for( int i=1;i<=kol;i++)
         {
           CustomerData->Query1->SQL->Clear();
         s[0]='\0';
         strcpy(s,"update s12_form_kzo1 set d");
         strcat(s,IntToStr(i).c_str());
         strcat(s,"= (select  distinct [ANSWER%SEIZ] from maket_out where");
         strcat(s," t_begin='10:00' and data = '");
         strcat(s,MaskEdit1->Text.c_str());
         strcat(s,"-");
         // добавить 0 если номер месяца меньше 10 (9 т.к. с нуля отсчет начинается)
         if ( ComboBox1->Items->IndexOf(ComboBox1->Text)<9 ) strcat(s,"0");
         strcat(s, IntToStr(ComboBox1->Items->IndexOf(ComboBox1->Text)+1).c_str() );
         strcat(s,"-"); //         2004-08-");
         // добавлние дня
         if(i<10) strcat(s,"0");
         strcat(s,IntToStr(i).c_str());
         strcat(s,"' and out_tkg='");
         strcat(s,CustomerData->QueryBook->FieldByName("mnemo_o")->AsString.c_str());
         strcat(s,"' ) where s12_form_kzo1.name='");
         strcat(s,CustomerData->QueryBook->FieldByName("mnemo_o")->AsString.c_str());
         strcat(s,"'");
          CustomerData->Query1->SQL->Add(s);
          CustomerData->Query1->ExecSQL();

// подсчет Answer, Seiz
           CustomerData->Query1->SQL->Clear();
         s[0]='\0';
         strcat(s," select  distinct ANSWER,SEIZ from maket_out where");
         strcat(s," t_begin='10:00' and data = '");
         strcat(s,MaskEdit1->Text.c_str());
         strcat(s,"-");
         // добавить 0 если номер месяца меньше 10 (9 т.к. с нуля отсчет начинается)
         if ( ComboBox1->Items->IndexOf(ComboBox1->Text)<9 ) strcat(s,"0");
         strcat(s, IntToStr(ComboBox1->Items->IndexOf(ComboBox1->Text)+1).c_str() );
         strcat(s,"-"); //         2004-08-");
         // добавлние дня
         if(i<10) strcat(s,"0");
         strcat(s,IntToStr(i).c_str());
         strcat(s,"' and out_tkg='");
         strcat(s,CustomerData->QueryBook->FieldByName("mnemo_o")->AsString.c_str());
         strcat(s,"'  ");
          CustomerData->Query1->SQL->Add(s);
          CustomerData->Query1->Open();

          answer_sum+=CustomerData->Query1->Fields->Fields[0]->AsFloat;
          seiz_sum+=CustomerData->Query1->Fields->Fields[1]->AsFloat;

// Запись среднего
         if(seiz_sum>0)
         {
            CustomerData->Query1->SQL->Clear();
            s[0]='\0';
            strcpy(s,"update s12_form_kzo1 set d32");
            strcat(s,"= (");
            strcat(s,FloatToStr(answer_sum/seiz_sum*100).c_str());
            strcat(s,") where s12_form_kzo1.name='");
            strcat(s,CustomerData->QueryBook->FieldByName("mnemo_o")->AsString.c_str());
            strcat(s,"'");
            CustomerData->Query1->SQL->Add(s);
            CustomerData->Query1->ExecSQL();
         }

         MainForm->ProgressBar2->Position=i;
         }
 //        ShowMessage(CustomerData->QueryBook->FieldByName("mnemo_o")->AsString.c_str());
         CustomerData->QueryBook->Next();
         MainForm->ProgressBar1->Position=MainForm->ProgressBar1->Position+1;
  }
  free(s);
};


void __fastcall TFormKZO::BitBtn1Click(TObject *Sender)
{
int kol;
//char  *s=NULL;
//       s = (char *) calloc(300, sizeof(char));

         kol=30;
         if(ComboBox1->Items->IndexOf(ComboBox1->Text)==1) kol=28;
         if( (ComboBox1->Items->IndexOf(ComboBox1->Text)==0) ||
             (ComboBox1->Items->IndexOf(ComboBox1->Text)==2) ||
             (ComboBox1->Items->IndexOf(ComboBox1->Text)==4) ||
             (ComboBox1->Items->IndexOf(ComboBox1->Text)==6) ||
             (ComboBox1->Items->IndexOf(ComboBox1->Text)==7) ||
             (ComboBox1->Items->IndexOf(ComboBox1->Text)==9) ||
             (ComboBox1->Items->IndexOf(ComboBox1->Text)==11)) kol=31;

  FormGrid->Close();
  MainForm->ProgressBar1->Visible=true;
  MainForm->ProgressBar2->Visible=true;
  CustomerData->QueryBook->Close();
  CustomerData->QueryBook->SQL->Clear();
  CustomerData->QueryBook->SQL->Add("select * from s12_book2 where mnemo_o<>'' order by ");
  CustomerData->QueryBook->SQL->Add("order_");

  CustomerData->QueryBook->Open();
  CustomerData->QueryBook->First();
  MainForm->ProgressBar1->Max=CustomerData->QueryBook->RecordCount;

  // очищение таблицы
         CustomerData->Query1->Close();
         CustomerData->Query1->SQL->Clear();
         CustomerData->Query1->SQL->Add("delete from s12_form_kzo1");
         CustomerData->Query1->ExecSQL();
         CustomerData->Query1->SQL->Clear();

  for(int i=1;i<=3;i++)
  {
    CustomerData->QueryBook->Close();
    CustomerData->QueryBook->SQL->Clear();
    CustomerData->QueryBook->SQL->Add("select * from s12_book2 where mnemo_o<>'' ");
    CustomerData->QueryBook->SQL->Add(" and order_=");
    CustomerData->QueryBook->SQL->Add(IntToStr(i));
    CustomerData->QueryBook->SQL->Add(" order by mnemo_o");
    CustomerData->QueryBook->Open();
    CustomerData->QueryBook->First();

         CustomerData->Query1->Close();
         CustomerData->Query1->SQL->Clear();
         // вставка строки в таблицу s12_form_kzo1
         switch(i)
         {
          case 1: CustomerData->Query1->SQL->Add(
                      "insert into s12_form_kzo1 (name) values ('Магистраль')"); break;
          case 2: CustomerData->Query1->SQL->Add(
                      "insert into s12_form_kzo1 (name) values ('Зона')");break;
          case 3: CustomerData->Query1->SQL->Add(
                      "insert into s12_form_kzo1 (name) values ('АТС')");break;
         }
         CustomerData->Query1->ExecSQL();

     QueryBookToFormKzo1(kol);
  }

    MainForm->ProgressBar1->Visible=false;
    MainForm->ProgressBar2->Visible=false;
  ShowMessage("Расчет закончен. Нажмите ОК");
  FormGrid->Show();

}
//---------------------------------------------------------------------------

void __fastcall TFormKZO::FormActivate(TObject *Sender)
{
//  FormGrid->Close();
}
//---------------------------------------------------------------------------

