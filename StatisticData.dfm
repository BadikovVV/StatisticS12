object StatDateForm: TStatDateForm
  Left = 510
  Top = 272
  Width = 237
  Height = 110
  HorzScrollBar.Visible = False
  VertScrollBar.Visible = False
  Caption = #1044#1072#1090#1072' '#1089#1090#1072#1090#1080#1089#1090#1080#1082#1080':'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  KeyPreview = True
  OldCreateOrder = False
  Position = poDesktopCenter
  OnKeyPress = FormKeyPress
  PixelsPerInch = 96
  TextHeight = 13
  object DateTimePicker1: TDateTimePicker
    Left = 8
    Top = 8
    Width = 217
    Height = 21
    CalAlignment = dtaLeft
    Date = 39863.962074456
    Time = 39863.962074456
    DateFormat = dfShort
    DateMode = dmComboBox
    Kind = dtkDate
    ParseInput = False
    TabOrder = 0
  end
  object Button1: TButton
    Left = 56
    Top = 48
    Width = 75
    Height = 25
    Caption = #1054#1050
    TabOrder = 1
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 144
    Top = 48
    Width = 75
    Height = 25
    Caption = #1054#1090#1084#1077#1085#1072
    TabOrder = 2
    OnClick = Button2Click
  end
end
