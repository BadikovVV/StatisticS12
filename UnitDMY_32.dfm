inherited FormDMY_32: TFormDMY_32
  Left = 266
  Top = 220
  Width = 591
  Height = 147
  Caption = #1055#1088#1080#1083#1086#1078#1077#1085#1080#1077' 3.2'
  OldCreateOrder = True
  PixelsPerInch = 96
  TextHeight = 13
  inherited Bevel1: TBevel
    Top = 4
    Width = 573
    Height = 113
  end
  inherited StaticText1: TStaticText
    Left = 36
    Width = 63
    Caption = #1044#1072#1090#1099' '#1089
  end
  inherited BitBtn1: TBitBtn
    Left = 490
    OnClick = BitBtn1Click
  end
  inherited DateTimePicker1: TDateTimePicker
    Left = 110
    Width = 160
  end
  object DateTimePicker2: TDateTimePicker
    Left = 307
    Top = 16
    Width = 160
    Height = 21
    CalAlignment = dtaLeft
    Date = 38691.6165784144
    Time = 38691.6165784144
    DateFormat = dfShort
    DateMode = dmComboBox
    Kind = dtkDate
    ParseInput = False
    TabOrder = 3
  end
  object StaticText2: TStaticText
    Left = 276
    Top = 16
    Width = 24
    Height = 24
    Caption = #1087#1086
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clNavy
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 4
  end
  object RadioGroup1: TRadioGroup
    Left = 37
    Top = 62
    Width = 433
    Height = 41
    Caption = #1053#1072#1087#1088#1072#1074#1083#1077#1085#1080#1103
    Columns = 2
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clNavy
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 5
  end
  object RB_IN: TRadioButton
    Left = 161
    Top = 78
    Width = 113
    Height = 17
    Caption = #1042#1093#1086#1076#1103#1097#1080#1077
    Checked = True
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clNavy
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 6
    TabStop = True
  end
  object RB_OUT: TRadioButton
    Left = 344
    Top = 78
    Width = 113
    Height = 17
    Caption = #1048#1089#1093#1086#1076#1103#1097#1080#1077
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clNavy
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 7
  end
  object BitBtn2: TBitBtn
    Left = 490
    Top = 48
    Width = 75
    Height = 25
    Caption = #1054#1090#1084#1077#1085#1072
    TabOrder = 8
    Kind = bkCancel
  end
end
