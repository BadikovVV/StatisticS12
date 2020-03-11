object FormCondition: TFormCondition
  Left = 200
  Top = 156
  HorzScrollBar.Visible = False
  VertScrollBar.Visible = False
  BorderStyle = bsDialog
  Caption = #1040#1085#1072#1083#1080#1079'  '#1085#1072#1087#1088#1072#1074#1083#1077#1085#1080#1081
  ClientHeight = 403
  ClientWidth = 586
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
    Left = 8
    Top = 8
    Width = 569
    Height = 337
  end
  object Bevel2: TBevel
    Left = 40
    Top = 280
    Width = 521
    Height = 50
  end
  object Label1: TLabel
    Left = 224
    Top = 298
    Width = 6
    Height = 16
    Caption = '-'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label2: TLabel
    Left = 477
    Top = 300
    Width = 6
    Height = 16
    Caption = '-'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label3: TLabel
    Left = 368
    Top = 299
    Width = 44
    Height = 16
    Caption = #1042#1088#1077#1084#1103':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clNavy
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label4: TLabel
    Left = 50
    Top = 297
    Width = 35
    Height = 16
    Caption = #1044#1072#1090#1072':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clNavy
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Bevel3: TBevel
    Left = 8
    Top = 347
    Width = 569
    Height = 50
    Style = bsRaised
  end
  object ComboBoxDirection: TComboBox
    Left = 240
    Top = 72
    Width = 305
    Height = 24
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ItemHeight = 16
    ParentFont = False
    TabOrder = 0
    Text = 'ComboBoxDirection'
  end
  object GroupBox1: TGroupBox
    Left = 40
    Top = 32
    Width = 185
    Height = 105
    Caption = #1042#1099#1073#1086#1088' '#1085#1072#1087#1088#1072#1074#1083#1077#1085#1080#1081
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    object RB1Direction: TRadioButton
      Left = 15
      Top = 30
      Width = 153
      Height = 17
      Caption = #1054#1076#1085#1086' '#1085#1072#1087#1088#1072#1074#1083#1077#1085#1080#1077
      TabOrder = 0
      OnClick = RB1DirectionClick
    end
    object RBAllDirection: TRadioButton
      Left = 15
      Top = 70
      Width = 145
      Height = 17
      Caption = #1042#1089#1077' '#1085#1072#1087#1088#1072#1074#1083#1077#1085#1080#1103
      TabOrder = 1
      OnClick = RBAllDirectionClick
    end
  end
  object GroupBox2: TGroupBox
    Left = 40
    Top = 160
    Width = 185
    Height = 105
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    object RBCondition: TRadioButton
      Left = 16
      Top = 32
      Width = 137
      Height = 17
      Caption = #1059#1089#1083#1086#1074#1080#1077' '#1086#1090#1073#1086#1088#1072
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      OnClick = RBConditionClick
    end
    object RBWithoutConditions: TRadioButton
      Left = 16
      Top = 70
      Width = 145
      Height = 17
      Caption = #1041#1077#1079' '#1086#1075#1088#1072#1085#1080#1095#1077#1085#1080#1081
      TabOrder = 1
      OnClick = RBWithoutConditionsClick
    end
  end
  object ComboBoxFields: TComboBox
    Left = 240
    Top = 192
    Width = 145
    Height = 24
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ItemHeight = 16
    ParentFont = False
    TabOrder = 3
    Text = 'ComboBoxFields'
  end
  object ComboBox3: TComboBox
    Left = 400
    Top = 192
    Width = 65
    Height = 24
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ItemHeight = 16
    ParentFont = False
    TabOrder = 4
    Items.Strings = (
      '<'
      '<='
      '>'
      '>='
      '=')
  end
  object ComboBox4: TComboBox
    Left = 480
    Top = 192
    Width = 65
    Height = 24
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ItemHeight = 16
    ParentFont = False
    TabOrder = 5
    Items.Strings = (
      '30'
      '0'
      '0.1'
      '0.2'
      '0.3'
      '0.4'
      '')
  end
  object DateTimePicker1: TDateTimePicker
    Left = 88
    Top = 296
    Width = 137
    Height = 21
    CalAlignment = dtaLeft
    Date = 38020.6392250231
    Time = 38020.6392250231
    DateFormat = dfShort
    DateMode = dmComboBox
    Kind = dtkDate
    ParseInput = False
    TabOrder = 6
  end
  object DateTimePicker2: TDateTimePicker
    Left = 232
    Top = 296
    Width = 129
    Height = 21
    CalAlignment = dtaLeft
    Date = 38020.6427837268
    Time = 38020.6427837268
    DateFormat = dfShort
    DateMode = dmComboBox
    Kind = dtkDate
    ParseInput = False
    TabOrder = 7
  end
  object CSpinEdit1: TCSpinEdit
    Left = 417
    Top = 296
    Width = 55
    Height = 22
    MaxValue = 24
    TabOrder = 8
    Value = 10
  end
  object CSpinEdit2: TCSpinEdit
    Left = 490
    Top = 296
    Width = 55
    Height = 22
    MaxValue = 24
    TabOrder = 9
    Value = 11
  end
  object BitBtn1: TBitBtn
    Left = 176
    Top = 359
    Width = 81
    Height = 25
    Caption = #1055#1091#1089#1082
    TabOrder = 10
    OnClick = BitBtn1Click
    Kind = bkOK
  end
  object BitBtn2: TBitBtn
    Left = 328
    Top = 359
    Width = 89
    Height = 25
    Caption = #1054#1090#1084#1077#1085#1080#1090#1100
    TabOrder = 11
    Kind = bkCancel
  end
end
