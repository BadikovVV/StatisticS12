object CustomerData: TCustomerData
  OldCreateOrder = False
  Left = 614
  Top = 393
  Height = 261
  Width = 311
  object Database1: TDatabase
    DatabaseName = 'repviews12'
    DriverName = 'MSSQL'
    LoginPrompt = False
    SessionName = 'Default'
    Left = 24
    Top = 8
  end
  object Query1: TQuery
    DatabaseName = 'repviews12'
    Left = 32
    Top = 96
  end
  object Query2: TQuery
    DatabaseName = 'repviews12'
    Left = 80
    Top = 88
  end
  object QueryExec: TQuery
    DatabaseName = 'repviews12'
    Left = 136
    Top = 88
  end
  object QueryBook: TQuery
    DatabaseName = 'repviews12'
    Left = 184
    Top = 88
  end
  object DataSource1: TDataSource
    DataSet = Query1
    Left = 136
    Top = 32
  end
end
