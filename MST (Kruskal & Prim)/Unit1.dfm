object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 760
  ClientWidth = 1108
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object Splitter1: TSplitter
    Left = 377
    Top = 0
    Height = 760
    ExplicitLeft = 192
    ExplicitTop = 512
    ExplicitHeight = 100
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 377
    Height = 760
    Align = alLeft
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    ExplicitHeight = 670
    object GroupBox1: TGroupBox
      Left = 2
      Top = 0
      Width = 369
      Height = 438
      Caption = 'Directed Graph G=(V, E)'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -27
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      object Label1: TLabel
        Left = 21
        Top = 39
        Width = 264
        Height = 37
        Caption = 'Randomly Generated: '
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -27
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
      end
      object Label2: TLabel
        Left = 24
        Top = 82
        Width = 61
        Height = 37
        Caption = '|V| = '
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -27
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
      end
      object Label3: TLabel
        Left = 24
        Top = 136
        Width = 173
        Height = 37
        Caption = 'Range(w(e)) = '
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -27
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
      end
      object Label4: TLabel
        Left = 24
        Top = 187
        Width = 104
        Height = 37
        Caption = 'If w(e) > '
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -27
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
      end
      object Label5: TLabel
        Left = 21
        Top = 238
        Width = 153
        Height = 37
        Caption = 'Then, w(e) = '
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -27
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
      end
      object Label6: TLabel
        Left = 24
        Top = 289
        Width = 154
        Height = 37
        Caption = 'Repetition = '
      end
      object Edit1: TEdit
        Left = 203
        Top = 82
        Width = 153
        Height = 45
        TabOrder = 0
        Text = 'Edit1'
      end
      object Edit2: TEdit
        Left = 203
        Top = 133
        Width = 153
        Height = 45
        TabOrder = 1
        Text = 'Edit2'
      end
      object Edit3: TEdit
        Left = 203
        Top = 184
        Width = 153
        Height = 45
        TabOrder = 2
        Text = 'Edit3'
      end
      object Button2: TButton
        Left = 21
        Top = 376
        Width = 332
        Height = 43
        Caption = 'Generate Graph'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -27
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
        TabOrder = 3
        OnClick = Button2Click
      end
      object Edit4: TEdit
        Left = 203
        Top = 235
        Width = 153
        Height = 45
        TabOrder = 4
        Text = 'Edit4'
      end
      object CheckBox1: TCheckBox
        Left = 24
        Top = 337
        Width = 264
        Height = 33
        Caption = 'Echo Print Graph G'
        TabOrder = 5
      end
      object Edit5: TEdit
        Left = 203
        Top = 286
        Width = 153
        Height = 45
        TabOrder = 6
        Text = 'Edit5'
      end
    end
    object GroupBox2: TGroupBox
      Left = 5
      Top = 444
      Width = 366
      Height = 250
      Caption = 'MST Solver'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -27
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
      object Button3: TButton
        Left = 12
        Top = 83
        Width = 335
        Height = 49
        Caption = 'Kruskal Algorithm (Min)'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -27
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
        TabOrder = 0
        OnClick = Button3Click
      end
      object Button4: TButton
        Left = 12
        Top = 138
        Width = 335
        Height = 50
        Caption = 'Kruskal Algorithm (Heap)'
        TabOrder = 1
        OnClick = Button4Click
      end
      object Button5: TButton
        Left = 12
        Top = 194
        Width = 335
        Height = 44
        Caption = 'Prim Algorithm'
        TabOrder = 2
        OnClick = Button5Click
      end
      object CheckBox2: TCheckBox
        Left = 15
        Top = 43
        Width = 218
        Height = 34
        Caption = 'Echo Print MST'
        TabOrder = 3
      end
    end
    object Button1: TButton
      Left = 17
      Top = 700
      Width = 335
      Height = 45
      Caption = 'Comparison By Diagram'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -27
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 2
      OnClick = Button1Click
    end
  end
  object PageControl1: TPageControl
    Left = 380
    Top = 0
    Width = 728
    Height = 760
    ActivePage = TabSheet4
    Align = alClient
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    ExplicitWidth = 718
    ExplicitHeight = 670
    object TabSheet1: TTabSheet
      Caption = 'MST Record'
      object Memo1: TMemo
        Left = 0
        Top = 0
        Width = 712
        Height = 702
        Align = alClient
        Lines.Strings = (
          'Memo1')
        ScrollBars = ssBoth
        TabOrder = 0
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'Adjacent Matrix'
      ImageIndex = 1
      object Memo3: TMemo
        Left = 0
        Top = 0
        Width = 712
        Height = 702
        Align = alClient
        Lines.Strings = (
          'Memo3')
        ScrollBars = ssBoth
        TabOrder = 0
      end
    end
    object TabSheet3: TTabSheet
      Caption = 'Edges Matrix'
      ImageIndex = 2
      object Memo2: TMemo
        Left = 0
        Top = 0
        Width = 712
        Height = 702
        Align = alClient
        Lines.Strings = (
          'Memo2')
        ScrollBars = ssBoth
        TabOrder = 0
      end
    end
    object TabSheet4: TTabSheet
      Caption = 'Diagram'
      ImageIndex = 3
      object Chart1: TChart
        Left = 0
        Top = 0
        Width = 712
        Height = 702
        Title.Text.Strings = (
          'TChart')
        Align = alClient
        TabOrder = 0
        ExplicitWidth = 702
        ExplicitHeight = 612
        DefaultCanvas = 'TGDIPlusCanvas'
        ColorPaletteIndex = 13
        object Series1: TBarSeries
          Marks.OnTop = True
          XValues.Name = 'X'
          XValues.Order = loAscending
          YValues.Name = 'Bar'
          YValues.Order = loNone
        end
      end
    end
  end
end
