// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitKZO2.h"
#include "UnitGrid.h"
#include "Main.h"
#include "DM.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "UnitKZO"
#pragma resource "*.dfm"
TFormKZO2 *FormKZO2;

class TDataNN {
public:
	AnsiString val[32];

	void SetData(int i, AnsiString s) {
		val[i] = s;
	}

	DataNN() {
	}
	// ~DataNN(){}
};

// ---------------------------------------------------------------------------
__fastcall TFormKZO2::TFormKZO2(TComponent* Owner) : TFormKZO(Owner) {
}

// ---------------------------------------------------------------------------
void __fastcall TFormKZO2::FormCreate(TObject *Sender) {
	ComboBox1->ItemIndex = StrToInt(FormatDateTime("mm", Now()).c_str()) - 1;
	MaskEdit1->Text = FormatDateTime("yyyy", Now());
}

// ---------------------------------------------------------------------------
void __fastcall TFormKZO2::BitBtn1Click(TObject *Sender) {
	int kol;
	char *s = NULL;
	s = (char *) calloc(300, sizeof(char));
	TDataNN TNN;
	TNN.SetData(1, "12.34");
	kol = 30;
	if (ComboBox1->Items->IndexOf(ComboBox1->Text) == 1)
		kol = 28;
	if ((ComboBox1->Items->IndexOf(ComboBox1->Text) == 0) ||
		(ComboBox1->Items->IndexOf(ComboBox1->Text) == 2) ||
		(ComboBox1->Items->IndexOf(ComboBox1->Text) == 4) ||
		(ComboBox1->Items->IndexOf(ComboBox1->Text) == 6) ||
		(ComboBox1->Items->IndexOf(ComboBox1->Text) == 7) ||
		(ComboBox1->Items->IndexOf(ComboBox1->Text) == 9) ||
		(ComboBox1->Items->IndexOf(ComboBox1->Text) == 11))
		kol = 31;

	FormGrid->Close();
	MainForm->ProgressBar1->Visible = true;
	MainForm->ProgressBar2->Visible = true;
	CustomerData->QueryBook->Close();
	CustomerData->QueryBook->SQL->Clear();
	CustomerData->QueryBook->SQL->Add
		("select * from s12_book2 where mnemo_o<>'' order by ");
	CustomerData->QueryBook->SQL->Add("mnemo_o");

	CustomerData->QueryBook->Open();
	CustomerData->QueryBook->First();
	MainForm->ProgressBar1->Max = CustomerData->QueryBook->RecordCount;

	// �������� �������
	CustomerData->Query1->Close();
	CustomerData->Query1->SQL->Clear();
	CustomerData->Query1->SQL->Add("delete from s12_form_kzo2");
	// CustomerData->Query1->SQL->Add("truncate table s12_form_kzo2 ");
	CustomerData->Query1->ExecSQL();
	CustomerData->Query1->SQL->Clear();

	while (!CustomerData->QueryBook->Eof)
		// ���� �� ���� ������������ � �����������
	{
		CustomerData->Query1->Close();
		CustomerData->Query1->SQL->Clear();
		// ������� ������ � ������� s12_form_kzo2
		s[0] = '\0';
		strcpy(s, "insert into s12_form_kzo2 (name) values ('");
		strcat(s, CustomerData->QueryBook->FieldByName("mnemo_o")
			->AsString.c_str());
		strcat(s, "')");
		CustomerData->Query1->SQL->Add(s);
		CustomerData->Query1->ExecSQL();
		MainForm->ProgressBar2->Position = 0;
		MainForm->ProgressBar2->Max = 31;

		for (int i = 1; i <= kol; i++) {
			CustomerData->Query1->SQL->Clear();
			s[0] = '\0';
			strcpy(s, "update s12_form_kzo2 set d");
			strcat(s, IntToStr(i).c_str());
			strcat(s, "= (select  distinct [ANSWER%SEIZ] from maket_out where");
			strcat(s, " data = '");
			strcat(s, MaskEdit1->Text.c_str());
			strcat(s, "-");
			// �������� 0 ���� ����� ������ ������ 10 (9 �.�. � ���� ������ ����������)
			if (ComboBox1->Items->IndexOf(ComboBox1->Text) < 9)
				strcat(s, "0");
			strcat(s, IntToStr(ComboBox1->Items->IndexOf(ComboBox1->Text) + 1)
				.c_str());
			strcat(s, "-"); // 2004-08-");
			// ��������� ���
			if (i < 10)
				strcat(s, "0");
			strcat(s, IntToStr(i).c_str());
			strcat(s, "' and out_tkg='");
			strcat(s, CustomerData->QueryBook->FieldByName("mnemo_o")
				->AsString.c_str());
			// ---        strcat(s,"' where s12_form_kzo2.name='");
			// ---         strcat(s,CustomerData->QueryBook->FieldByName("mnemo_o")->AsString.c_str());
			strcat(s, "'");
			// ������� ������ ���
			strcat(s,
				" and offd=(select max(offd) from maket_out where data='");
			// and out_tkg='ALEX_O' and offd>0)");
			strcat(s, MaskEdit1->Text.c_str());
			strcat(s, "-");
			// �������� 0 ���� ����� ������ ������ 10 (9 �.�. � ���� ������ ����������)
			if (ComboBox1->Items->IndexOf(ComboBox1->Text) < 9)
				strcat(s, "0");
			strcat(s, IntToStr(ComboBox1->Items->IndexOf(ComboBox1->Text) + 1)
				.c_str());
			strcat(s, "-"); // 2004-08-");
			// ��������� ���
			if (i < 10)
				strcat(s, "0");
			strcat(s, IntToStr(i).c_str());

			strcat(s, "' and out_tkg='");
			strcat(s, CustomerData->QueryBook->FieldByName("mnemo_o")
				->AsString.c_str());
			// strcat(s,"' ) where s12_form_kzo2.name='");
			// strcat(s,CustomerData->QueryBook->FieldByName("mnemo_o")->AsString.c_str());
			strcat(s, "' and offd>0)");

			strcat(s, " ) where s12_form_kzo2.name='");
			strcat(s, CustomerData->QueryBook->FieldByName("mnemo_o")
				->AsString.c_str());
			strcat(s, "'");
			CustomerData->Query1->SQL->Add(s);

			ShowMessage(s);
			CustomerData->Query1->ExecSQL();
			MainForm->ProgressBar2->Position = i;
		}
		// ShowMessage(CustomerData->QueryBook->FieldByName("mnemo_o")->AsString.c_str());
		CustomerData->QueryBook->Next();
		MainForm->ProgressBar1->Position = MainForm->ProgressBar1->Position + 1;
	}
	free(s);
	MainForm->ProgressBar1->Visible = false;
	MainForm->ProgressBar2->Visible = false;
	ShowMessage("������ ��������. ������� ��");
	FormGrid->Show();
}
// ---------------------------------------------------------------------------


//---------------------------------------------------------------------------

