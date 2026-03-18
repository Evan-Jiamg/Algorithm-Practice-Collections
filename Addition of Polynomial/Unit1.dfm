object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 639
  ClientWidth = 982
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object Label5: TLabel
    Left = 8
    Top = 486
    Width = 144
    Height = 32
    Caption = #22810#38917#24335#21152#32317' : '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object GroupBox1: TGroupBox
    Left = 8
    Top = 8
    Width = 273
    Height = 217
    Caption = #25163#21205#36664#20837#22810#38917#24335' : '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    object Label1: TLabel
      Left = 16
      Top = 40
      Width = 111
      Height = 30
      Caption = 'Coefficient :'
    end
    object Label2: TLabel
      Left = 29
      Top = 84
      Width = 104
      Height = 30
      Caption = 'Exponent : '
    end
    object Button1: TButton
      Left = 16
      Top = 167
      Width = 244
      Height = 34
      Caption = 'New Term in Polynomial'
      TabOrder = 0
      OnClick = Button1Click
    end
    object Edit1: TEdit
      Left = 139
      Top = 37
      Width = 121
      Height = 38
      TabOrder = 1
      Text = 'Edit1'
    end
    object Edit2: TEdit
      Left = 139
      Top = 81
      Width = 121
      Height = 38
      TabOrder = 2
      Text = 'Edit2'
    end
    object CheckBox1: TCheckBox
      Left = 38
      Top = 125
      Width = 95
      Height = 33
      Caption = 'Poly A'
      TabOrder = 3
    end
    object CheckBox2: TCheckBox
      Left = 130
      Top = 128
      Width = 97
      Height = 26
      Caption = 'Poly B'
      TabOrder = 4
    end
  end
  object GroupBox2: TGroupBox
    Left = 8
    Top = 231
    Width = 273
    Height = 249
    Caption = #33258#21205#38568#27231#36664#20837#22810#38917#24335' : '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    object Label3: TLabel
      Left = 16
      Top = 41
      Width = 149
      Height = 30
      Caption = #26368#22823#25351#25976#25976#20540' : '
    end
    object Label4: TLabel
      Left = 16
      Top = 121
      Width = 233
      Height = 30
      Caption = 'Max range of '#38917#25976' (+/-) :'
    end
    object Edit3: TEdit
      Left = 64
      Top = 77
      Width = 196
      Height = 38
      TabOrder = 0
      Text = 'Edit3'
    end
    object Edit4: TEdit
      Left = 64
      Top = 157
      Width = 196
      Height = 38
      TabOrder = 1
      Text = 'Edit4'
    end
    object Button3: TButton
      Left = 5
      Top = 201
      Width = 265
      Height = 37
      Caption = 'Random '#29983#25104' Poly A and B'
      TabOrder = 2
      OnClick = Button3Click
    end
  end
  object Button4: TButton
    Left = 8
    Top = 524
    Width = 268
    Height = 49
    Caption = 'C = A + B'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 8
    Top = 579
    Width = 268
    Height = 51
    Caption = 'Clear All'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 3
    OnClick = Button5Click
  end
  object PageControl1: TPageControl
    Left = 287
    Top = 8
    Width = 687
    Height = 633
    ActivePage = TabSheet2
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 4
    object TabSheet1: TTabSheet
      Caption = 'Display the Polynomials'
      object Memo1: TMemo
        Left = 0
        Top = 0
        Width = 671
        Height = 575
        Align = alClient
        Lines.Strings = (
          'Memo1')
        ScrollBars = ssBoth
        TabOrder = 0
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'Addition of Polynomials'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -21
      Font.Name = 'Segoe UI'
      Font.Style = []
      ImageIndex = 1
      ParentFont = False
      object Memo2: TMemo
        Left = 0
        Top = 0
        Width = 671
        Height = 575
        Align = alClient
        Lines.Strings = (
          'Memo2')
        ScrollBars = ssBoth
        TabOrder = 0
      end
    end
  end
end
