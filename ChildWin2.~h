//----------------------------------------------------------------------------
#ifndef ChildWin2H
#define ChildWin2H
//----------------------------------------------------------------------------
#include <vcl\Controls.hpp>
#include <vcl\Forms.hpp>
#include <vcl\Graphics.hpp>
#include <vcl\Classes.hpp>
#include <vcl\Windows.hpp>
#include <vcl\System.hpp>
#include <StdCtrls.hpp>
#include <ExtCtrls.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <Db.hpp>
#include <DBTables.hpp>
#include <ComCtrls.hpp>
#include "RXDBCtrl.hpp"
#include <DB.hpp>
//----------------------------------------------------------------------------
class TMDIChild2 : public TForm
{
__published:
        TBevel *Bevel1;
        TQuery *Query1;
        TDataSource *DataSource1;
        TStatusBar *StatusBar1;
        TRxDBGrid *RxDBGrid1;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall RxDBGrid1CellClick(TColumn *Column);
        void __fastcall RxDBGrid1ColEnter(TObject *Sender);
        void __fastcall RxDBGrid1Enter(TObject *Sender);
        void __fastcall FormActivate(TObject *Sender);
private:
        char Field1Query1[8];
        char Field1Query2[8];
public:
	virtual __fastcall TMDIChild2(TComponent *Owner);
};
extern char sqls[1600];
extern char sqls2[1300];
//----------------------------------------------------------------------------
#endif
