//----------------------------------------------------------------------------
#ifndef MainH
#define MainH
//----------------------------------------------------------------------------
#include "ChildWin.h"
#include <vcl\ComCtrls.hpp>
#include <vcl\ExtCtrls.hpp>
#include <vcl\Messages.hpp>
#include <vcl\Buttons.hpp>
#include <vcl\Dialogs.hpp>
#include <vcl\StdCtrls.hpp>
#include <vcl\Menus.hpp>
#include <vcl\Controls.hpp>
#include <vcl\Forms.hpp>
#include <vcl\Graphics.hpp>
#include <vcl\Classes.hpp>
#include <vcl\SysUtils.hpp>
#include <vcl\Windows.hpp>
#include <vcl\System.hpp>
#include <ActnList.hpp>
#include <ImgList.hpp>
#include <StdActns.hpp>
#include <ToolWin.hpp>
#include <Grids.hpp>

#include "utilcls.h"
#include "DM.h"
#include <System.Actions.hpp>
#include <System.ImageList.hpp>
//----------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:
	TMainMenu *MainMenu1;
	TMenuItem *File1;
	TMenuItem *FileNewItem;
	TMenuItem *FileOpenItem;
	TMenuItem *FileCloseItem;
	TMenuItem *Window1;
	TMenuItem *Help1;
	TMenuItem *N1;
	TMenuItem *FileExitItem;
	TMenuItem *WindowCascadeItem;
	TMenuItem *WindowTileItem;
	TMenuItem *WindowArrangeItem;
	TMenuItem *HelpAboutItem;
	TOpenDialog *OpenDialog;
	TMenuItem *FileSaveItem;
	TMenuItem *FileSaveAsItem;
	TMenuItem *Edit1;
	TMenuItem *CutItem;
	TMenuItem *CopyItem;
	TMenuItem *PasteItem;
	TMenuItem *WindowMinimizeItem;
        TStatusBar *StatusBar;
        TActionList *ActionList1;
        TEditCut *EditCut1;
        TEditCopy *EditCopy1;
        TEditPaste *EditPaste1;
        TAction *FileNew1;
        TAction *FileSave1;
        TAction *FileExit1;
        TAction *FileOpen1;
        TAction *FileSaveAs1;
        TWindowCascade *WindowCascade1;
        TWindowTileHorizontal *WindowTileHorizontal1;
        TWindowArrange *WindowArrangeAll1;
        TWindowMinimizeAll *WindowMinimizeAll1;
        TAction *HelpAbout1;
        TWindowClose *FileClose1;
        TWindowTileVertical *WindowTileVertical1;
        TMenuItem *WindowTileItem2;
        TToolBar *ToolBar2;
        TToolButton *ToolButton1;
        TToolButton *ToolButton2;
        TToolButton *ToolButton3;
        TToolButton *ToolButton4;
        TToolButton *ToolButton5;
        TToolButton *ToolButton6;
        TToolButton *ToolButton7;
        TToolButton *ToolButton8;
        TToolButton *ToolButton9;
        TToolButton *ToolButton10;
        TToolButton *ToolButton11;
        TImageList *ImageList1;
        TMenuItem *N2;
        TMenuItem *N3;
        TMenuItem *N4;
        TMenuItem *N5;
        TMenuItem *N6IN_Magistral;
        TMenuItem *N7IN_Zona;
        TMenuItem *N8IN_Ats;
        TMenuItem *N9IN_Arm;
        TMenuItem *N10;
        TMenuItem *N11OUT_Magistral;
        TMenuItem *N12OUT_Zona;
        TMenuItem *N13OUT_Ats;
        TMenuItem *N14OUT_Arm;
        TMenuItem *N15;
        TMenuItem *N16;
        TMenuItem *N17;
        TMenuItem *N18;
        TMenuItem *N19;
        TMenuItem *N6Fields;
        TStaticText *STFieldName;
        TToolButton *ToolButton13;
        TToolButton *ToolButtonPrint;
        TMenuItem *PrintItem;
        TToolButton *ToolButton12;
        TProgressBar *ProgressBar1;
        TProgressBar *ProgressBar2;
        TMenuItem *N10111;
        TMenuItem *N6;
        TMenuItem *N7;
        TMenuItem *N8;
        TMenuItem *N9;
        TMenuItem *N11;
        TMenuItem *N12;
        TToolButton *ToolButton14;
        TMenuItem *Excel1;
        TMenuItem *N13;
        TMenuItem *N41;
        TMenuItem *N51;
        TMenuItem *PABX1;
        TMenuItem *PABX2;
        TMenuItem *PABX3;
        TMenuItem *N321;
        TMenuItem *N42;
        TMenuItem *N14;
        TMenuItem *N20;
        TMenuItem *N21;
        TMenuItem *N52;
        TMenuItem *N22;
        TMenuItem *N23;
        TMenuItem *N24;
        TMenuItem *N71;
        TMenuItem *N25;
        TMenuItem *N26;
        TMenuItem *N27;
        TMenuItem *N72;
        TMenuItem *N28;
        TMenuItem *N29;
        TMenuItem *N30;
        void __fastcall FileNew1Execute(TObject *Sender);
        void __fastcall FileOpen1Execute(TObject *Sender);
        void __fastcall HelpAbout1Execute(TObject *Sender);
        void __fastcall FileExit1Execute(TObject *Sender);
        void __fastcall N6IN_MagistralClick(TObject *Sender);
        void __fastcall N18Click(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
        void __fastcall N19Click(TObject *Sender);
        void __fastcall N11OUT_MagistralClick(TObject *Sender);
        void __fastcall N7IN_ZonaClick(TObject *Sender);
        void __fastcall N8IN_AtsClick(TObject *Sender);
        void __fastcall N9IN_ArmClick(TObject *Sender);
        void __fastcall N12OUT_ZonaClick(TObject *Sender);
        void __fastcall N13OUT_AtsClick(TObject *Sender);
        void __fastcall N14OUT_ArmClick(TObject *Sender);
        void __fastcall N10Click(TObject *Sender);
        void __fastcall N15Click(TObject *Sender);
        void __fastcall N6FieldsClick(TObject *Sender);
        void __fastcall Print1Execute(TObject *Sender);
        void __fastcall N6Click(TObject *Sender);
        void __fastcall N10111Click(TObject *Sender);
        void __fastcall N9Click(TObject *Sender);
        void __fastcall N8Click(TObject *Sender);
        void __fastcall N11Click(TObject *Sender);
        void __fastcall N12Click(TObject *Sender);
        void __fastcall Excel1Click(TObject *Sender);
        void __fastcall N41Click(TObject *Sender);
        void __fastcall N51Click(TObject *Sender);
        void __fastcall PABX3Click(TObject *Sender);
        void __fastcall PABX2Click(TObject *Sender);
        void __fastcall N321Click(TObject *Sender);
        void __fastcall N14Click(TObject *Sender);
        void __fastcall N20Click(TObject *Sender);
        void __fastcall N21Click(TObject *Sender);
        void __fastcall N22Click(TObject *Sender);
        void __fastcall N23Click(TObject *Sender);
        void __fastcall N24Click(TObject *Sender);
        void __fastcall N25Click(TObject *Sender);
        void __fastcall N26Click(TObject *Sender);
        void __fastcall N27Click(TObject *Sender);
        void __fastcall N72Click(TObject *Sender);
        void __fastcall N28Click(TObject *Sender);
        void __fastcall N29Click(TObject *Sender);
        void __fastcall N30Click(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
private:
	void __fastcall CreateMDIChild(const String Name);
	void __fastcall CreateMDIChildP(const String Name);
        void MenuItem(int num, // тип направления: 1-магистраль 2-зона 3-атс 4-арм 0-все
               char* direction // направление: IN-входящие, OUT-исходящие
              );
        bool RunForm(String sFile, AnsiString sMakros);

public:
	virtual __fastcall TMainForm(TComponent *Owner);
};

 class TMeasure
 {
  public:

  void book_direction(int num,char* fieldname);
  void in_out_menu(int num);
  void Select(char* direction,char* fields);

  ~TMeasure(){};
 };

 class TPABX : public TMeasure
 {
   public:
   TPABX(){};
   void in_out_menu(int num);
   void Select(char* direction,char* fields);
// ~TPABX(){};
 };
//----------------------------------------------------------------------------
extern TMainForm *MainForm;
extern TMDIChild *__fastcall MDIChildCreate(void);
//extern char sqls[250];
//----------------------------------------------------------------------------
#endif


















                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                

                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                

                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                

                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                

                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                

                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                






