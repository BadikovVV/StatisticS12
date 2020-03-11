//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitOutFields.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "RXSwitch"
#pragma resource "*.dfm"
TFormOUTFields *FormOUTFields;
extern TStringList* S12OUT;
extern char fields_OUT[660];
//---------------------------------------------------------------------------
__fastcall TFormOUTFields::TFormOUTFields(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormOUTFields::FormCreate(TObject *Sender)
{
  for(int i=0;i<36;i++)
   dynamic_cast<TCheckBox*>(Components[i+3])->Caption=S12OUT->Strings[i];

/* old code    CheckBox1->Caption=S12OUT->Strings[0];*/
// заполнение строки fields_IN
  fields_OUT[0]='\0';
  if(CheckBox1->Checked){ strcat(fields_OUT,CheckBox1->Caption.c_str());
                          }
  if(CheckBox2->Checked){ strcat(fields_OUT,", "),
                          strcat(fields_OUT,CheckBox2->Caption.c_str());
                           }
  if(CheckBox3->Checked){ strcat(fields_OUT,", "),
                          strcat(fields_OUT,CheckBox3->Caption.c_str());}
  if(CheckBox4->Checked){ strcat(fields_OUT,", "),
                          strcat(fields_OUT,CheckBox4->Caption.c_str());}
  if(CheckBox5->Checked){ strcat(fields_OUT,", b.out as ASS ");}
//  if(CheckBox5->Checked){ strcat(fields_OUT,", [ASS]='' ");}
  if(CheckBox6->Checked){ strcat(fields_OUT,", "),
                          strcat(fields_OUT,CheckBox6->Caption.c_str());}
  if(CheckBox7->Checked){ strcat(fields_OUT,", round(b.out-AVLB_OCC,2) as DIFA ");}
//  if(CheckBox7->Checked){ strcat(fields_OUT,", DIFA='' ");}
  if(CheckBox8->Checked){ strcat(fields_OUT,", "),
                        strcat(fields_OUT,CheckBox8->Caption.c_str());}
  if(CheckBox9->Checked){ strcat(fields_OUT,", ");
                          strcat(fields_OUT,CheckBox9->Caption.c_str());}
  if(CheckBox10->Checked){ strcat(fields_OUT,", ");
                          strcat(fields_OUT,CheckBox10->Caption.c_str());}
  if(CheckBox11->Checked){ strcat(fields_OUT,", ");
                          strcat(fields_OUT,CheckBox11->Caption.c_str());}
  if(CheckBox12->Checked){ strcat(fields_OUT,", ");
                          strcat(fields_OUT,CheckBox12->Caption.c_str());}
  if(CheckBox13->Checked){ strcat(fields_OUT,", "),
                        strcat(fields_OUT,CheckBox13->Caption.c_str());}
  if(CheckBox14->Checked){ strcat(fields_OUT,", ");
                          strcat(fields_OUT,CheckBox14->Caption.c_str());}
  if(CheckBox15->Checked){ strcat(fields_OUT,", "),
                        strcat(fields_OUT,CheckBox15->Caption.c_str());}
  if(CheckBox16->Checked){ strcat(fields_OUT,", ");
                          strcat(fields_OUT,CheckBox16->Caption.c_str());}
  if(CheckBox17->Checked){ strcat(fields_OUT,", ");
                          strcat(fields_OUT,CheckBox17->Caption.c_str());}
  if(CheckBox18->Checked){ strcat(fields_OUT,", "),
                        strcat(fields_OUT,CheckBox18->Caption.c_str());}
  if(CheckBox19->Checked){ strcat(fields_OUT,", "),
                        strcat(fields_OUT,CheckBox19->Caption.c_str());}
  if(CheckBox20->Checked){ strcat(fields_OUT,", ");
                          strcat(fields_OUT,CheckBox20->Caption.c_str());}
  if(CheckBox21->Checked){ strcat(fields_OUT,", "),
                        strcat(fields_OUT,CheckBox21->Caption.c_str());}
  if(CheckBox22->Checked){ strcat(fields_OUT,", "),
                        strcat(fields_OUT,CheckBox22->Caption.c_str());}
  if(CheckBox23->Checked){ strcat(fields_OUT,", "),
                        strcat(fields_OUT,CheckBox23->Caption.c_str());}
  if(CheckBox24->Checked){ strcat(fields_OUT,", "),
                        strcat(fields_OUT,CheckBox24->Caption.c_str());}
  if(CheckBox25->Checked){ strcat(fields_OUT,", "),
                        strcat(fields_OUT,CheckBox25->Caption.c_str());}
  if(CheckBox26->Checked){ strcat(fields_OUT,", "),
                        strcat(fields_OUT,CheckBox26->Caption.c_str());}
  if(CheckBox27->Checked){ strcat(fields_OUT,", "),
                        strcat(fields_OUT,CheckBox27->Caption.c_str());}
  if(CheckBox28->Checked){ strcat(fields_OUT,", "),
                        strcat(fields_OUT,CheckBox28->Caption.c_str());}
  if(CheckBox29->Checked){ strcat(fields_OUT,", "),
                        strcat(fields_OUT,CheckBox29->Caption.c_str());}
  if(CheckBox30->Checked){ strcat(fields_OUT,", "),
                        strcat(fields_OUT,CheckBox30->Caption.c_str());}
  if(CheckBox31->Checked){ strcat(fields_OUT,", "),
                        strcat(fields_OUT,CheckBox31->Caption.c_str());}
  if(CheckBox32->Checked){ strcat(fields_OUT,", ");
                          strcat(fields_OUT,CheckBox32->Caption.c_str());}
  if(CheckBox33->Checked){ strcat(fields_OUT,", ");
                          strcat(fields_OUT,CheckBox33->Caption.c_str());}
  if(CheckBox34->Checked){ strcat(fields_OUT,", "),
                        strcat(fields_OUT,CheckBox34->Caption.c_str());}
  if(CheckBox35->Checked){ strcat(fields_OUT,", ");
                          strcat(fields_OUT,CheckBox35->Caption.c_str());}
  if(CheckBox36->Checked){ strcat(fields_OUT,", ");
                          strcat(fields_OUT,CheckBox36->Caption.c_str());}
}
//---------------------------------------------------------------------------
void __fastcall TFormOUTFields::BitBtn1Click(TObject *Sender)
{
  fields_OUT[0]='\0';
CheckBox12->Checked=True; // ANSWER/SEIZ
  if(CheckBox1->Checked){ strcat(fields_OUT,CheckBox1->Caption.c_str());
                          }
  if(CheckBox2->Checked){ strcat(fields_OUT,", "),
                          strcat(fields_OUT,CheckBox2->Caption.c_str());}
  if(CheckBox3->Checked){ strcat(fields_OUT,", "),
                          strcat(fields_OUT,CheckBox3->Caption.c_str());}
  if(CheckBox4->Checked){ strcat(fields_OUT,", "),
                          strcat(fields_OUT,CheckBox4->Caption.c_str());}
  if(CheckBox5->Checked){ strcat(fields_OUT,", b.out as ASS ");}
//  if(CheckBox5->Checked){ strcat(fields_OUT,", [ASS]='' ");}
  if(CheckBox6->Checked){ strcat(fields_OUT,", "),
                          strcat(fields_OUT,CheckBox6->Caption.c_str());}
  if(CheckBox7->Checked){ strcat(fields_OUT,", round(b.out-AVLB_OCC,2) as DIFA ");}
//  if(CheckBox7->Checked){ strcat(fields_OUT,", DIFA='' ");}
  if(CheckBox8->Checked){ strcat(fields_OUT,", "),
                        strcat(fields_OUT,CheckBox8->Caption.c_str());}
  if(CheckBox9->Checked){ strcat(fields_OUT,", ");
                          strcat(fields_OUT,CheckBox9->Caption.c_str());}
  if(CheckBox10->Checked){ strcat(fields_OUT,", ");
                          strcat(fields_OUT,CheckBox10->Caption.c_str());}
  if(CheckBox11->Checked){ strcat(fields_OUT,", ");
                          strcat(fields_OUT,CheckBox11->Caption.c_str());}
  if(CheckBox12->Checked){ strcat(fields_OUT,", ");
                          strcat(fields_OUT,CheckBox12->Caption.c_str());}
  if(CheckBox13->Checked){ strcat(fields_OUT,", "),
                        strcat(fields_OUT,CheckBox13->Caption.c_str());}
  if(CheckBox14->Checked){ strcat(fields_OUT,", ");
                          strcat(fields_OUT,CheckBox14->Caption.c_str());}
  if(CheckBox15->Checked){ strcat(fields_OUT,", "),
                        strcat(fields_OUT,CheckBox15->Caption.c_str());}
  if(CheckBox16->Checked){ strcat(fields_OUT,", ");
                          strcat(fields_OUT,CheckBox16->Caption.c_str());}
  if(CheckBox17->Checked){ strcat(fields_OUT,", ");
                          strcat(fields_OUT,CheckBox17->Caption.c_str());}
  if(CheckBox18->Checked){ strcat(fields_OUT,", "),
                        strcat(fields_OUT,CheckBox18->Caption.c_str());}
  if(CheckBox19->Checked){ strcat(fields_OUT,", "),
                        strcat(fields_OUT,CheckBox19->Caption.c_str());}
  if(CheckBox20->Checked){ strcat(fields_OUT,", ");
                          strcat(fields_OUT,CheckBox20->Caption.c_str());}
  if(CheckBox21->Checked){ strcat(fields_OUT,", "),
                        strcat(fields_OUT,CheckBox21->Caption.c_str());}
  if(CheckBox22->Checked){ strcat(fields_OUT,", "),
                        strcat(fields_OUT,CheckBox22->Caption.c_str());}
  if(CheckBox23->Checked){ strcat(fields_OUT,", "),
                        strcat(fields_OUT,CheckBox23->Caption.c_str());}
  if(CheckBox24->Checked){ strcat(fields_OUT,", "),
                        strcat(fields_OUT,CheckBox24->Caption.c_str());}
  if(CheckBox25->Checked){ strcat(fields_OUT,", "),
                        strcat(fields_OUT,CheckBox25->Caption.c_str());}
  if(CheckBox26->Checked){ strcat(fields_OUT,", "),
                        strcat(fields_OUT,CheckBox26->Caption.c_str());}
  if(CheckBox27->Checked){ strcat(fields_OUT,", "),
                        strcat(fields_OUT,CheckBox27->Caption.c_str());}
  if(CheckBox28->Checked){ strcat(fields_OUT,", "),
                        strcat(fields_OUT,CheckBox28->Caption.c_str());}
  if(CheckBox29->Checked){ strcat(fields_OUT,", "),
                        strcat(fields_OUT,CheckBox29->Caption.c_str());}
  if(CheckBox30->Checked){ strcat(fields_OUT,", "),
                        strcat(fields_OUT,CheckBox30->Caption.c_str());}
  if(CheckBox31->Checked){ strcat(fields_OUT,", "),
                        strcat(fields_OUT,CheckBox31->Caption.c_str());}
  if(CheckBox32->Checked){ strcat(fields_OUT,", ");
                          strcat(fields_OUT,CheckBox32->Caption.c_str());}
  if(CheckBox33->Checked){ strcat(fields_OUT,", ");
                          strcat(fields_OUT,CheckBox33->Caption.c_str());}
  if(CheckBox34->Checked){ strcat(fields_OUT,", "),
                        strcat(fields_OUT,CheckBox34->Caption.c_str());}
  if(CheckBox35->Checked){ strcat(fields_OUT,", ");
                          strcat(fields_OUT,CheckBox35->Caption.c_str());}
  if(CheckBox36->Checked){ strcat(fields_OUT,", ");
                          strcat(fields_OUT,CheckBox36->Caption.c_str());}
}
//---------------------------------------------------------------------------

void __fastcall TFormOUTFields::CheckBox32Click(TObject *Sender)
{
  if(CheckBox32->Checked)
  { CheckBox31->Checked=True; // OCC
    CheckBox6->Checked=True; // AVLB_OCC
  }
}
//---------------------------------------------------------------------------

void __fastcall TFormOUTFields::RxSwitch1On(TObject *Sender)
{
int i;
  for(i=7;i<39;i++)
   dynamic_cast<TCheckBox*>(Components[i])->Checked=False;
}
//---------------------------------------------------------------------------

void __fastcall TFormOUTFields::RxSwitch1Off(TObject *Sender)
{
int i;
  for(i=7;i<39;i++)
   dynamic_cast<TCheckBox*>(Components[i])->Checked=True;
}
//---------------------------------------------------------------------------

