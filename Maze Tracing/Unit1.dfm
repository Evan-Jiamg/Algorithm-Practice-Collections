object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 688
  ClientWidth = 1206
  Color = clBtnFace
  DoubleBuffered = True
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 297
    Height = 688
    Align = alLeft
    TabOrder = 0
    ExplicitLeft = 2
    ExplicitHeight = 723
    object GroupBox1: TGroupBox
      Left = 0
      Top = 0
      Width = 291
      Height = 249
      Caption = #36855#23470#38499#21015#22823#23567' ('#20677#33021#36664#20837#22855#25976')'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -21
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      object Label1: TLabel
        Left = 40
        Top = 48
        Width = 55
        Height = 30
        Caption = #39640#24230' :'
      end
      object Label2: TLabel
        Left = 40
        Top = 90
        Width = 55
        Height = 30
        Caption = #23532#24230' :'
      end
      object Label3: TLabel
        Left = 46
        Top = 136
        Width = 49
        Height = 30
        Caption = 'Grid :'
      end
      object Edit1: TEdit
        Left = 117
        Top = 45
        Width = 121
        Height = 38
        TabOrder = 0
      end
      object Edit2: TEdit
        Left = 117
        Top = 89
        Width = 121
        Height = 38
        TabOrder = 1
      end
      object Edit3: TEdit
        Left = 117
        Top = 133
        Width = 121
        Height = 38
        TabOrder = 2
      end
      object Button2: TButton
        Left = 232
        Top = 186
        Width = 47
        Height = 49
        Caption = #38568#27231#29983#25104#36855#23470
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -21
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
        TabOrder = 3
        OnClick = Button2Click
      end
      object Button1: TButton
        Left = 20
        Top = 185
        Width = 259
        Height = 51
        Caption = #38568#27231#29983#25104#36855#23470
        TabOrder = 4
        OnClick = Button1Click
      end
    end
    object Button4: TButton
      Left = 6
      Top = 271
      Width = 285
      Height = 43
      Caption = #30001#22806#37096#36617#20837#36855#23470
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -21
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
      OnClick = Button4Click
    end
    object GroupBox2: TGroupBox
      Left = 6
      Top = 335
      Width = 285
      Height = 274
      Caption = #33258#21205#23563#25214#36335#24465' :'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -21
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 2
      object Label4: TLabel
        Left = 14
        Top = 191
        Width = 216
        Height = 32
        Caption = #21205#30059#36895#24230' :  ('#24930'->'#24555')'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -24
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
      end
      object Label5: TLabel
        Left = 34
        Top = 142
        Width = 183
        Height = 35
        Caption = '  (Moving_Grid)'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -27
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
      end
      object Button5: TButton
        Left = 14
        Top = 40
        Width = 259
        Height = 57
        Caption = #38283#22987#23563#25214
        TabOrder = 0
        OnClick = Button5Click
      end
      object TrackBar1: TTrackBar
        Left = 14
        Top = 237
        Width = 259
        Height = 45
        TabOrder = 1
      end
      object CheckBox1: TCheckBox
        Left = 17
        Top = 103
        Width = 268
        Height = 41
        Caption = ' Display the Route'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -27
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
        TabOrder = 2
      end
    end
    object Button8: TButton
      Left = 6
      Top = 623
      Width = 285
      Height = 56
      Caption = 'Re-Run'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -27
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 3
      OnClick = Button8Click
    end
  end
  object PageControl1: TPageControl
    Left = 297
    Top = 0
    Width = 909
    Height = 688
    ActivePage = TabSheet2
    Align = alClient
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    object TabSheet1: TTabSheet
      Caption = 'Show_Maze'
      object Memo1: TMemo
        Left = 0
        Top = 0
        Width = 893
        Height = 628
        Align = alClient
        Lines.Strings = (
          'Memo1')
        ScrollBars = ssBoth
        TabOrder = 0
        ExplicitWidth = 883
        ExplicitHeight = 654
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'Tracing_Record'
      ImageIndex = 1
      object Memo2: TMemo
        Left = 0
        Top = 0
        Width = 893
        Height = 628
        Align = alClient
        Lines.Strings = (
          'Memo2')
        ScrollBars = ssBoth
        TabOrder = 0
        ExplicitHeight = 686
      end
    end
    object TabSheet3: TTabSheet
      Caption = 'String_Grid'
      ImageIndex = 2
      object StringGrid1: TStringGrid
        Left = 0
        Top = 0
        Width = 893
        Height = 628
        Align = alClient
        TabOrder = 0
        OnDrawCell = StringGrid1DrawCell
        ExplicitTop = 104
        ExplicitHeight = 524
      end
    end
    object TabSheet4: TTabSheet
      Caption = 'Moving_Grid'
      ImageIndex = 3
      object StringGrid2: TStringGrid
        Left = 0
        Top = 0
        Width = 893
        Height = 628
        Align = alClient
        TabOrder = 0
        OnDrawCell = StringGrid2DrawCell
        ExplicitLeft = -2
      end
    end
  end
  object OpenDialog1: TOpenDialog
    Left = 248
    Top = 280
  end
end
