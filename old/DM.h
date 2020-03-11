//----------------------------------------------------------------------------
#ifndef DMH
#define DMH
//----------------------------------------------------------------------------
#include <vcl\System.hpp>
#include <vcl\SysUtils.hpp>
#include <vcl\Windows.hpp>
#include <vcl\Messages.hpp>
#include <vcl\Classes.hpp>
#include <vcl\Graphics.hpp>
#include <vcl\Controls.hpp>
#include <vcl\Forms.hpp>
#include <vcl\Dialogs.hpp>
#include <vcl\DBTables.hpp>
#include <vcl\DB.hpp>
#include <Db.hpp>
//----------------------------------------------------------------------------
class TCustomerData : public TDataModule
{
__published:
        TQuery *Query1;
        TDataSource *DataSource1;
        TQuery *QueryBook;
        TQuery *Query2;
        TQuery *QueryExec;
        TDatabase *Database1;
	void __fastcall LineItemsCalcFields(TDataSet *DataSet);
private:
public:
	virtual __fastcall TCustomerData(TComponent* AOwner);
};
//----------------------------------------------------------------------------
extern PACKAGE TCustomerData *CustomerData;
//----------------------------------------------------------------------------
#endif
