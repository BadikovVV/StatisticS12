object FormDayMonthYear: TFormDayMonthYear
  Left = 344
  Top = 171
  Width = 518
  Height = 92
  HorzScrollBar.Visible = False
  VertScrollBar.Visible = False
  BorderIcons = [biSystemMenu]
  Caption = #1055#1088#1086#1089#1084#1086#1090#1088' '#1089#1090#1072#1090#1080#1089#1090#1080#1082#1080' '#1092#1086#1088#1084#1072' 4'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Bevel1: TBevel
    Left = 4
    Top = 2
    Width = 501
    Height = 55
  end
  object StaticText1: TStaticText
    Left = 39
    Top = 16
    Width = 112
    Height = 24
    Caption = #1055#1088#1086#1089#1084#1086#1090#1088' '#1079#1072
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clNavy
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 0
  end
  object BitBtn1: TBitBtn
    Left = 395
    Top = 14
    Width = 75
    Height = 25
    TabOrder = 1
    Kind = bkOK
  end
  object DateTimePicker1: TDateTimePicker
    Left = 184
    Top = 16
    Width = 186
    Height = 21
    CalAlignment = dtaLeft
    Date = 38656.6131522917
    Time = 38656.6131522917
    DateFormat = dfShort
    DateMode = dmComboBox
    Kind = dtkDate
    ParseInput = False
    TabOrder = 2
  end
end
