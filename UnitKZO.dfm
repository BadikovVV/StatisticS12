object FormKZO: TFormKZO
  Left = 344
  Top = 171
  Width = 513
  Height = 89
  HorzScrollBar.Visible = False
  VertScrollBar.Visible = False
  BorderIcons = [biSystemMenu]
  Caption = #1055#1088#1086#1089#1084#1086#1090#1088' '#1050#1047#1054' '#1089' 10:00 '#1076#1086' 11:00'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnActivate = FormActivate
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Bevel1: TBevel
    Left = 0
    Top = 0
    Width = 505
    Height = 55
    Align = alClient
  end
  object Label1: TLabel
    Left = 456
    Top = 24
    Width = 32
    Height = 13
    Caption = 'Label1'
  end
  object ComboBox1: TComboBox
    Left = 158
    Top = 16
    Width = 145
    Height = 21
    ItemHeight = 13
    TabOrder = 0
    Items.Strings = (
      #1071#1085#1074#1072#1088#1100
      #1060#1077#1074#1088#1072#1083#1100
      #1052#1072#1088#1090
      #1040#1087#1088#1077#1083#1100
      #1052#1072#1081
      #1048#1102#1085#1100
      #1048#1102#1083#1100
      #1040#1074#1075#1091#1089#1090
      #1057#1077#1085#1090#1103#1073#1088#1100
      #1054#1082#1090#1103#1073#1088#1100
      #1053#1086#1103#1073#1088#1100
      #1044#1077#1082#1072#1073#1088#1100)
  end
  object MaskEdit1: TMaskEdit
    Left = 306
    Top = 16
    Width = 41
    Height = 21
    EditMask = '0000;1;_'
    MaxLength = 4
    TabOrder = 1
    Text = '    '
  end
  object StaticText1: TStaticText
    Left = 6
    Top = 16
    Width = 153
    Height = 24
    Caption = #1055#1088#1086#1089#1084#1086#1090#1088' '#1050#1047#1054' '#1079#1072
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clNavy
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 2
  end
  object StaticText2: TStaticText
    Left = 357
    Top = 16
    Width = 44
    Height = 24
    Caption = #1075#1086#1076#1072
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clNavy
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 3
  end
  object BitBtn1: TBitBtn
    Left = 411
    Top = 14
    Width = 75
    Height = 25
    TabOrder = 4
    OnClick = BitBtn1Click
    Kind = bkOK
  end
end
