//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitInFields.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "RXSwitch"
#pragma resource "*.dfm"
TFormINFields *FormINFields;
extern TStringList* S12IN;
extern char fields_IN[600];
//---------------------------------------------------------------------------
__fastcall TFormINFields::TFormINFields(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormINFields::FormCreate(TObject *Sender)
{
  // «аполнение названий полей
    for(int i=0;i<40;i++)
      dynamic_cast<TCheckBox*>(Components[i+3])->Caption=S12IN->Strings[i];
/* old code       CheckBox1->Caption=S12IN->Strings[0]; */

// заполнение строки fields_IN
  fields_IN[0]='\0';
  if(CheckBox1->Checked){ strcat(fields_IN,CheckBox1->Caption.c_str());
                          }
  if(CheckBox2->Checked){ strcat(fields_IN,", "),
                          strcat(fields_IN,CheckBox2->Caption.c_str());
                           }
  if(CheckBox3->Checked){ strcat(fields_IN,", "),
                          strcat(fields_IN,CheckBox3->Caption.c_str());}
  if(CheckBox4->Checked){ strcat(fields_IN,", "),
                          strcat(fields_IN,CheckBox4->Caption.c_str());}
  if(CheckBox5->Checked){ strcat(fields_IN,", b.inc as ASS");}
//  if(CheckBox5->Checked){ strcat(fields_IN,", [ASS]=''");}
  if(CheckBox6->Checked){ strcat(fields_IN,", "),
                          strcat(fields_IN,CheckBox6->Caption.c_str());}
  if(CheckBox7->Checked){ strcat(fields_IN,", round(b.inc-AVLB_OCC,2) as DIFA ");}
//  if(CheckBox7->Checked){ strcat(fields_IN,", [ASS-AVLB_OCC] as 'DIFA' ");}
  if(CheckBox8->Checked){ strcat(fields_IN,", "),
                         strcat(fields_IN,CheckBox8->Caption.c_str());}
  if(CheckBox9->Checked){ strcat(fields_IN,", ");
                        strcat(fields_IN,CheckBox9->Caption.c_str());}
  if(CheckBox10->Checked){ strcat(fields_IN,", ");
                        strcat(fields_IN,CheckBox10->Caption.c_str());}
  if(CheckBox11->Checked){ strcat(fields_IN,", ");
                        strcat(fields_IN,CheckBox11->Caption.c_str());}
  if(CheckBox12->Checked){ strcat(fields_IN,", ");
                        strcat(fields_IN,CheckBox12->Caption.c_str());}
  if(CheckBox13->Checked){ strcat(fields_IN,", ");
                        strcat(fields_IN,CheckBox13->Caption.c_str());}
  if(CheckBox14->Checked){ strcat(fields_IN,", ");
                        strcat(fields_IN,CheckBox14->Caption.c_str());}
  if(CheckBox15->Checked){ strcat(fields_IN,", "),
                        strcat(fields_IN,CheckBox15->Caption.c_str());}
  if(CheckBox16->Checked){ strcat(fields_IN,", ");
                        strcat(fields_IN,CheckBox16->Caption.c_str());}
  if(CheckBox17->Checked){ strcat(fields_IN,", "),
                        strcat(fields_IN,CheckBox17->Caption.c_str());}
  if(CheckBox18->Checked){ strcat(fields_IN,", ");
                        strcat(fields_IN,CheckBox18->Caption.c_str());}
  if(CheckBox19->Checked){ strcat(fields_IN,", "),
                        strcat(fields_IN,CheckBox19->Caption.c_str());}
  if(CheckBox20->Checked){ strcat(fields_IN,", "),
                        strcat(fields_IN,CheckBox20->Caption.c_str());}
  if(CheckBox21->Checked){ strcat(fields_IN,", "),
                        strcat(fields_IN,CheckBox21->Caption.c_str());}
  if(CheckBox22->Checked){ strcat(fields_IN,", "),
                        strcat(fields_IN,CheckBox22->Caption.c_str());}
  if(CheckBox23->Checked){ strcat(fields_IN,", "),
                        strcat(fields_IN,CheckBox23->Caption.c_str());}
  if(CheckBox24->Checked){ strcat(fields_IN,", "),
                        strcat(fields_IN,CheckBox24->Caption.c_str());}
  if(CheckBox25->Checked){ strcat(fields_IN,", "),
                        strcat(fields_IN,CheckBox25->Caption.c_str());}
  if(CheckBox26->Checked){ strcat(fields_IN,", "),
                        strcat(fields_IN,CheckBox26->Caption.c_str());}
  if(CheckBox27->Checked){ strcat(fields_IN,", "),
                        strcat(fields_IN,CheckBox27->Caption.c_str());}
  if(CheckBox28->Checked){ strcat(fields_IN,", "),
                        strcat(fields_IN,CheckBox28->Caption.c_str());}
  if(CheckBox29->Checked){ strcat(fields_IN,", "),
                        strcat(fields_IN,CheckBox29->Caption.c_str());}
  if(CheckBox30->Checked){ strcat(fields_IN,", "),
                        strcat(fields_IN,CheckBox30->Caption.c_str());}
  if(CheckBox31->Checked){ strcat(fields_IN,", "),
                        strcat(fields_IN,CheckBox31->Caption.c_str());}
  if(CheckBox32->Checked){ strcat(fields_IN,", "),
                        strcat(fields_IN,CheckBox32->Caption.c_str());}
  if(CheckBox33->Checked){ strcat(fields_IN,", "),
                        strcat(fields_IN,CheckBox33->Caption.c_str());}
  if(CheckBox34->Checked){ strcat(fields_IN,", "),
                        strcat(fields_IN,CheckBox34->Caption.c_str());}
  if(CheckBox35->Checked){ strcat(fields_IN,", ");
                        strcat(fields_IN,CheckBox35->Caption.c_str());}
  if(CheckBox36->Checked){ strcat(fields_IN,", ");
                        strcat(fields_IN,CheckBox36->Caption.c_str());}
  if(CheckBox37->Checked){ strcat(fields_IN,", "),
                        strcat(fields_IN,CheckBox37->Caption.c_str());}
  if(CheckBox38->Checked){ strcat(fields_IN,", ");
                        strcat(fields_IN,CheckBox38->Caption.c_str());}
  if(CheckBox39->Checked){ strcat(fields_IN,", ");
                        strcat(fields_IN,CheckBox39->Caption.c_str());}
  if(CheckBox40->Checked){ strcat(fields_IN,", ");
                        strcat(fields_IN,CheckBox40->Caption.c_str());}

  //  ShowMessage(fields_IN);
}
//---------------------------------------------------------------------------
void __fastcall TFormINFields::BitBtn1Click(TObject *Sender)
{
  fields_IN[0]='\0';
 CheckBox14->Checked=True; // ANSWER/SEIZ
  if(CheckBox1->Checked){ strcat(fields_IN,CheckBox1->Caption.c_str());
                          }
  if(CheckBox2->Checked){ strcat(fields_IN,", "),
                          strcat(fields_IN,CheckBox2->Caption.c_str());
                           }
  if(CheckBox3->Checked){ strcat(fields_IN,", "),
                          strcat(fields_IN,CheckBox3->Caption.c_str());}
  if(CheckBox4->Checked){ strcat(fields_IN,", "),
                          strcat(fields_IN,CheckBox4->Caption.c_str());}
  if(CheckBox5->Checked){ strcat(fields_IN,", b.inc as ASS");}
//  if(CheckBox5->Checked){ strcat(fields_IN,", [ASS]=''");}
  if(CheckBox6->Checked){ strcat(fields_IN,", "),
                          strcat(fields_IN,CheckBox6->Caption.c_str());}
  if(CheckBox7->Checked){ strcat(fields_IN,", round(b.inc-AVLB_OCC,2) as DIFA ");}
//  if(CheckBox7->Checked){ strcat(fields_IN,", [ASS-AVLB_OCC] as 'DIFA' ");}
  if(CheckBox8->Checked){ strcat(fields_IN,", "),
                         strcat(fields_IN,CheckBox8->Caption.c_str());}
  if(CheckBox9->Checked){ strcat(fields_IN,", ");
                        strcat(fields_IN,CheckBox9->Caption.c_str());}
  if(CheckBox10->Checked){ strcat(fields_IN,", ");
                        strcat(fields_IN,CheckBox10->Caption.c_str());}
  if(CheckBox11->Checked){ strcat(fields_IN,", ");
                        strcat(fields_IN,CheckBox11->Caption.c_str());}
  if(CheckBox12->Checked){ strcat(fields_IN,", ");
                        strcat(fields_IN,CheckBox12->Caption.c_str());}
  if(CheckBox13->Checked){ strcat(fields_IN,", ");
                        strcat(fields_IN,CheckBox13->Caption.c_str());}
  if(CheckBox14->Checked){ strcat(fields_IN,", ");
                        strcat(fields_IN,CheckBox14->Caption.c_str());}
  if(CheckBox15->Checked){ strcat(fields_IN,", "),
                        strcat(fields_IN,CheckBox15->Caption.c_str());}
  if(CheckBox16->Checked){ strcat(fields_IN,", ");
                        strcat(fields_IN,CheckBox16->Caption.c_str());}
  if(CheckBox17->Checked){ strcat(fields_IN,", "),
                        strcat(fields_IN,CheckBox17->Caption.c_str());}
  if(CheckBox18->Checked){ strcat(fields_IN,", ");
                        strcat(fields_IN,CheckBox18->Caption.c_str());}
  if(CheckBox19->Checked){ strcat(fields_IN,", "),
                        strcat(fields_IN,CheckBox19->Caption.c_str());}
  if(CheckBox20->Checked){ strcat(fields_IN,", "),
                        strcat(fields_IN,CheckBox20->Caption.c_str());}
  if(CheckBox21->Checked){ strcat(fields_IN,", "),
                        strcat(fields_IN,CheckBox21->Caption.c_str());}
  if(CheckBox22->Checked){ strcat(fields_IN,", "),
                        strcat(fields_IN,CheckBox22->Caption.c_str());}
  if(CheckBox23->Checked){ strcat(fields_IN,", "),
                        strcat(fields_IN,CheckBox23->Caption.c_str());}
  if(CheckBox24->Checked){ strcat(fields_IN,", "),
                        strcat(fields_IN,CheckBox24->Caption.c_str());}
  if(CheckBox25->Checked){ strcat(fields_IN,", "),
                        strcat(fields_IN,CheckBox25->Caption.c_str());}
  if(CheckBox26->Checked){ strcat(fields_IN,", "),
                        strcat(fields_IN,CheckBox26->Caption.c_str());}
  if(CheckBox27->Checked){ strcat(fields_IN,", "),
                        strcat(fields_IN,CheckBox27->Caption.c_str());}
  if(CheckBox28->Checked){ strcat(fields_IN,", "),
                        strcat(fields_IN,CheckBox28->Caption.c_str());}
  if(CheckBox29->Checked){ strcat(fields_IN,", "),
                        strcat(fields_IN,CheckBox29->Caption.c_str());}
  if(CheckBox30->Checked){ strcat(fields_IN,", "),
                        strcat(fields_IN,CheckBox30->Caption.c_str());}
  if(CheckBox31->Checked){ strcat(fields_IN,", "),
                        strcat(fields_IN,CheckBox31->Caption.c_str());}
  if(CheckBox32->Checked){ strcat(fields_IN,", "),
                        strcat(fields_IN,CheckBox32->Caption.c_str());}
  if(CheckBox33->Checked){ strcat(fields_IN,", "),
                        strcat(fields_IN,CheckBox33->Caption.c_str());}
  if(CheckBox34->Checked){ strcat(fields_IN,", "),
                        strcat(fields_IN,CheckBox34->Caption.c_str());}
  if(CheckBox35->Checked){ strcat(fields_IN,", ");
                        strcat(fields_IN,CheckBox35->Caption.c_str());}
  if(CheckBox36->Checked){ strcat(fields_IN,", ");
                        strcat(fields_IN,CheckBox36->Caption.c_str());}
  if(CheckBox37->Checked){ strcat(fields_IN,", "),
                        strcat(fields_IN,CheckBox37->Caption.c_str());}
  if(CheckBox38->Checked){ strcat(fields_IN,", ");
                        strcat(fields_IN,CheckBox38->Caption.c_str());}
  if(CheckBox39->Checked){ strcat(fields_IN,", ");
                        strcat(fields_IN,CheckBox39->Caption.c_str());}
  if(CheckBox40->Checked){ strcat(fields_IN,", ");
                        strcat(fields_IN,CheckBox40->Caption.c_str());}
}
//---------------------------------------------------------------------------

void __fastcall TFormINFields::CheckBox35Click(TObject *Sender)
{
  if(CheckBox35->Checked)
  { CheckBox34->Checked=True; // OCC
    CheckBox6->Checked=True; // AVLB_OCC
  }
}
//---------------------------------------------------------------------------

void __fastcall TFormINFields::RxSwitch1On(TObject *Sender)
{
int i;
  for(i=7;i<43;i++)
   dynamic_cast<TCheckBox*>(Components[i])->Checked=False;
}
//---------------------------------------------------------------------------

void __fastcall TFormINFields::RxSwitch1Off(TObject *Sender)
{
int i;
  for(i=7;i<43;i++)
   dynamic_cast<TCheckBox*>(Components[i])->Checked=True;
}
//---------------------------------------------------------------------------


