object Avertissement_Form: TAvertissement_Form
  Left = 238
  Top = 220
  BorderIcons = [biMinimize, biMaximize]
  BorderStyle = bsSingle
  Caption = 'Avertissement !'
  ClientHeight = 148
  ClientWidth = 435
  Color = clRed
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 40
    Top = 32
    Width = 56
    Height = 22
    Caption = 'Label1'
    Font.Charset = ANSI_CHARSET
    Font.Color = clLime
    Font.Height = -19
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object BitBtn1: TBitBtn
    Left = 136
    Top = 96
    Width = 177
    Height = 41
    Caption = 'Annuler l'#39'op'#233'ration '
    Font.Charset = ANSI_CHARSET
    Font.Color = clBlue
    Font.Height = -16
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 0
    OnClick = BitBtn1Click
    Kind = bkCancel
  end
end
