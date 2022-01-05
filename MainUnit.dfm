object MainForm: TMainForm
  Left = 249
  Top = 151
  BorderIcons = [biMinimize, biMaximize]
  BorderStyle = bsDialog
  Caption = 'ZM AutoShutdown'
  ClientHeight = 232
  ClientWidth = 493
  Color = clSilver
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnActivate = FormActivate
  PixelsPerInch = 96
  TextHeight = 13
  object Reglage_SpeedButton: TSpeedButton
    Left = 8
    Top = 8
    Width = 113
    Height = 33
    Caption = '&R'#233'glage'
    OnClick = Reglage_SpeedButtonClick
  end
  object Fermer_SpeedButton: TSpeedButton
    Left = 400
    Top = 8
    Width = 89
    Height = 33
    Caption = '&Fermer/R'#233'duit'
    OnClick = Fermer_SpeedButtonClick
  end
  object Label2: TLabel
    Left = 208
    Top = 208
    Width = 83
    Height = 22
    Cursor = crHandPoint
    Caption = 'A propos...'
    Font.Charset = ANSI_CHARSET
    Font.Color = clLime
    Font.Height = -19
    Font.Name = 'Monotype Corsiva'
    Font.Style = [fsBold, fsItalic, fsUnderline]
    ParentFont = False
    OnClick = Label2Click
  end
  object Operation_RadioGroup: TRadioGroup
    Left = 8
    Top = 56
    Width = 113
    Height = 145
    Caption = 'Fonction :'
    Items.Strings = (
      '&Eteindre'
      'Re&d'#233'marrer'
      'Mettre en &veille'
      'Fermer la &session')
    TabOrder = 0
  end
  object Temps_RadioGroup: TRadioGroup
    Left = 128
    Top = 56
    Width = 361
    Height = 97
    Caption = 'Temps :'
    Items.Strings = (
      'Effectuez  cette op'#233'ration  apr'#233's :'
      'Effectuez cette op'#233'ration '#224' :')
    TabOrder = 1
    OnClick = Temps_RadioGroupClick
  end
  object Apres_Panel: TPanel
    Left = 320
    Top = 72
    Width = 161
    Height = 33
    BevelInner = bvLowered
    Color = clMoneyGreen
    Enabled = False
    TabOrder = 2
    object nbr_heur_minute_Edit: TEdit
      Left = 8
      Top = 8
      Width = 41
      Height = 21
      BevelOuter = bvNone
      TabOrder = 0
      Text = '1'
    end
    object Heur_Minute_ComboBox: TComboBox
      Left = 64
      Top = 8
      Width = 89
      Height = 21
      ItemHeight = 13
      TabOrder = 1
      Text = 'Heurs'
      Items.Strings = (
        'Minutes'
        'Heurs'
        'Secondes')
    end
  end
  object a_Panel: TPanel
    Left = 296
    Top = 112
    Width = 185
    Height = 33
    BevelInner = bvLowered
    Color = clMoneyGreen
    Enabled = False
    TabOrder = 3
    object Label1: TLabel
      Left = 88
      Top = 8
      Width = 80
      Height = 13
      Caption = 'de la forme h:m:s'
    end
    object Heur_Edit: TEdit
      Left = 8
      Top = 8
      Width = 65
      Height = 21
      TabOrder = 0
    end
  end
  object Informations_Panel: TPanel
    Left = 128
    Top = 8
    Width = 265
    Height = 41
    BevelInner = bvLowered
    Color = clMoneyGreen
    TabOrder = 4
    Visible = False
    object Informations_Label: TLabel
      Left = 16
      Top = 4
      Width = 106
      Height = 13
      Caption = 'ZM AutoShutDown v1'
    end
  end
  object Panel3: TPanel
    Left = 128
    Top = 160
    Width = 361
    Height = 41
    BevelInner = bvLowered
    Color = clMoneyGreen
    TabOrder = 5
    object Ok_SpeedButton: TSpeedButton
      Left = 16
      Top = 8
      Width = 161
      Height = 25
      Caption = '&Ok'
      OnClick = Ok_SpeedButtonClick
    end
    object Annuler_SpeedButton: TSpeedButton
      Left = 200
      Top = 8
      Width = 145
      Height = 25
      Caption = 'A&nnuler'
      OnClick = Annuler_SpeedButtonClick
    end
  end
  object Timer1: TTimer
    Enabled = False
    OnTimer = Timer1Timer
    Left = 48
    Top = 216
  end
  object Timer2: TTimer
    Enabled = False
    OnTimer = Timer2Timer
    Left = 80
    Top = 216
  end
  object PopupMenu: TPopupMenu
    Left = 112
    Top = 216
    object Montrer1: TMenuItem
      Caption = '&Montrer'
      OnClick = Montrer1Click
    end
    object Rglage1: TMenuItem
      Caption = '&R'#233'glage'
      OnClick = Rglage1Click
    end
  end
end
