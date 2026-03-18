object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 726
  ClientWidth = 1186
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
    Height = 726
    ExplicitLeft = 192
    ExplicitTop = 512
    ExplicitHeight = 100
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 377
    Height = 726
    Align = alLeft
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    ExplicitHeight = 753
    object GroupBox1: TGroupBox
      Left = 2
      Top = 0
      Width = 369
      Height = 409
      Caption = 'Directed Graph G=(V, E)'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -27
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      object Label1: TLabel
        Left = 18
        Top = 87
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
        Top = 130
        Width = 47
        Height = 37
        Caption = 'n = '
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -27
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
      end
      object Label3: TLabel
        Left = 24
        Top = 184
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
        Top = 235
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
        Left = 24
        Top = 290
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
      object Button1: TButton
        Left = 18
        Top = 42
        Width = 338
        Height = 39
        Caption = 'Read Graph G'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -27
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
        TabOrder = 0
        OnClick = Button1Click
      end
      object Edit1: TEdit
        Left = 203
        Top = 130
        Width = 153
        Height = 45
        TabOrder = 1
        Text = 'Edit1'
      end
      object Edit2: TEdit
        Left = 203
        Top = 184
        Width = 153
        Height = 45
        TabOrder = 2
        Text = 'Edit2'
      end
      object Edit3: TEdit
        Left = 203
        Top = 235
        Width = 153
        Height = 45
        TabOrder = 3
        Text = 'Edit3'
      end
      object Button2: TButton
        Left = 24
        Top = 349
        Width = 332
        Height = 43
        Caption = 'Generate Graph'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -27
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
        TabOrder = 4
        OnClick = Button2Click
      end
      object Edit4: TEdit
        Left = 203
        Top = 290
        Width = 153
        Height = 45
        TabOrder = 5
        Text = 'Edit4'
      end
    end
    object GroupBox2: TGroupBox
      Left = 5
      Top = 415
      Width = 366
      Height = 362
      Caption = 'Shortest Path Solver'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -27
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
      object Label6: TLabel
        Left = 21
        Top = 51
        Width = 156
        Height = 37
        Caption = 'Source no. = '
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -27
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
      end
      object Button3: TButton
        Left = 18
        Top = 152
        Width = 335
        Height = 49
        Caption = 'Single Source All Destinations'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -24
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
        TabOrder = 0
        OnClick = Button3Click
      end
      object Button4: TButton
        Left = 18
        Top = 207
        Width = 335
        Height = 40
        Caption = 'All Pairs'
        TabOrder = 1
        OnClick = Button4Click
      end
      object Button5: TButton
        Left = 18
        Top = 253
        Width = 335
        Height = 41
        Caption = 'Transitive Closure'
        TabOrder = 2
        OnClick = Button5Click
      end
      object CheckBox1: TCheckBox
        Left = 21
        Top = 100
        Width = 324
        Height = 34
        Caption = 'Tracing Detailed Process'
        TabOrder = 3
      end
      object Edit5: TEdit
        Left = 200
        Top = 49
        Width = 153
        Height = 45
        TabOrder = 4
        Text = 'Edit5'
      end
    end
  end
  object PageControl1: TPageControl
    Left = 380
    Top = 0
    Width = 806
    Height = 726
    ActivePage = TabSheet3
    Align = alClient
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    object TabSheet1: TTabSheet
      Caption = 'Adjacent Matrix'
      object StringGrid1: TStringGrid
        Left = 0
        Top = 0
        Width = 790
        Height = 673
        Align = alClient
        TabOrder = 0
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'SSAD Solution'
      ImageIndex = 1
      object Memo2: TMemo
        Left = 0
        Top = 0
        Width = 790
        Height = 673
        Align = alClient
        Lines.Strings = (
          'Memo2')
        ScrollBars = ssBoth
        TabOrder = 0
      end
    end
    object TabSheet3: TTabSheet
      Caption = 'All Pairs Matrix'
      ImageIndex = 2
      object StringGrid2: TStringGrid
        Left = 0
        Top = 0
        Width = 790
        Height = 673
        Align = alClient
        TabOrder = 0
      end
    end
    object TabSheet4: TTabSheet
      Caption = 'Transitive Closure Matrix'
      ImageIndex = 3
      object StringGrid3: TStringGrid
        Left = 0
        Top = 0
        Width = 790
        Height = 673
        Align = alClient
        TabOrder = 0
      end
    end
    object TabSheet6: TTabSheet
      Caption = 'All Pairs Tracing Record'
      ImageIndex = 5
      object Memo3: TMemo
        Left = 0
        Top = 0
        Width = 790
        Height = 673
        Align = alClient
        Lines.Strings = (
          'Memo3')
        ScrollBars = ssBoth
        TabOrder = 0
      end
    end
    object TabSheet7: TTabSheet
      Caption = 'Transitive Closure Tracing Record'
      ImageIndex = 6
      object Memo4: TMemo
        Left = 0
        Top = 0
        Width = 790
        Height = 673
        Align = alClient
        Lines.Strings = (
          'Memo4')
        ScrollBars = ssBoth
        TabOrder = 0
      end
    end
  end
  object OpenDialog1: TOpenDialog
    Left = 306
    Top = 48
  end
end
