object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 589
  ClientWidth = 854
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object Label1: TLabel
    Left = 25
    Top = 20
    Width = 113
    Height = 30
    Caption = 'Matrix Size :'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 68
    Top = 80
    Width = 38
    Height = 30
    Caption = 'X = '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object Label3: TLabel
    Left = 68
    Top = 136
    Width = 38
    Height = 30
    Caption = 'Y = '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object Edit1: TEdit
    Left = 144
    Top = 17
    Width = 121
    Height = 38
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    Text = 'Edit1'
  end
  object Button1: TButton
    Left = 25
    Top = 192
    Width = 240
    Height = 41
    Caption = 'Knight Tour'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    OnClick = Button1Click
  end
  object Edit2: TEdit
    Left = 112
    Top = 77
    Width = 121
    Height = 38
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    Text = 'Edit2'
  end
  object Edit3: TEdit
    Left = 112
    Top = 133
    Width = 121
    Height = 38
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 3
    Text = 'Edit3'
  end
  object PageControl1: TPageControl
    Left = 288
    Top = 0
    Width = 566
    Height = 589
    ActivePage = TabSheet2
    Align = alRight
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 4
    ExplicitLeft = 278
    ExplicitHeight = 557
    object TabSheet1: TTabSheet
      Caption = 'Tour in Memo'
      object Memo1: TMemo
        Left = 0
        Top = 0
        Width = 550
        Height = 531
        Align = alClient
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -21
        Font.Name = 'Segoe UI'
        Font.Style = []
        Lines.Strings = (
          'Memo1')
        ParentFont = False
        ScrollBars = ssBoth
        TabOrder = 0
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'Tour in StringGrid'
      ImageIndex = 1
      object Memo2: TMemo
        Left = 0
        Top = 0
        Width = 550
        Height = 531
        Align = alClient
        Lines.Strings = (
          'Memo2')
        TabOrder = 0
        ExplicitHeight = 499
      end
      object StringGrid1: TStringGrid
        Left = 0
        Top = 0
        Width = 550
        Height = 531
        Align = alClient
        TabOrder = 1
        ExplicitHeight = 499
      end
    end
  end
  object Button2: TButton
    Left = 25
    Top = 256
    Width = 240
    Height = 41
    Caption = #29983#25104' StringGrid'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 5
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 25
    Top = 320
    Width = 240
    Height = 41
    Caption = 'Re-Run / Clear All'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 6
    OnClick = Button3Click
  end
end
