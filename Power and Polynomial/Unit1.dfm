object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 556
  ClientWidth = 971
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object PageControl1: TPageControl
    Left = 0
    Top = 0
    Width = 971
    Height = 556
    ActivePage = TabSheet1
    Align = alClient
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    ExplicitWidth = 961
    ExplicitHeight = 524
    object TabSheet1: TTabSheet
      Caption = 'Power / Exponentiation'
      object Panel1: TPanel
        Left = 0
        Top = 0
        Width = 955
        Height = 498
        Align = alClient
        TabOrder = 0
        ExplicitWidth = 945
        ExplicitHeight = 466
        object Label1: TLabel
          Left = 24
          Top = 24
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
        object Label2: TLabel
          Left = 24
          Top = 77
          Width = 42
          Height = 30
          Caption = 'N = '
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -21
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
        end
        object Splitter1: TSplitter
          Left = 1
          Top = 1
          Width = 7
          Height = 496
          ExplicitLeft = -3
          ExplicitHeight = 483
        end
        object Label6: TLabel
          Left = 24
          Top = 128
          Width = 99
          Height = 30
          Caption = #24490#29872#27425#25976': '
        end
        object Memo1: TMemo
          Left = 255
          Top = 1
          Width = 699
          Height = 496
          Align = alRight
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
          ExplicitLeft = 245
          ExplicitHeight = 464
        end
        object GroupBox1: TGroupBox
          Left = 24
          Top = 208
          Width = 225
          Height = 281
          Caption = 'Algorithm Options : '
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -21
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
          TabOrder = 1
          object CheckBox1: TCheckBox
            Left = 24
            Top = 82
            Width = 161
            Height = 49
            Caption = 'pow(X, N)'
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -24
            Font.Name = 'Segoe UI'
            Font.Style = []
            ParentFont = False
            TabOrder = 0
          end
          object CheckBox2: TCheckBox
            Left = 24
            Top = 137
            Width = 129
            Height = 33
            Caption = 'for-loop'
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -24
            Font.Name = 'Segoe UI'
            Font.Style = []
            ParentFont = False
            TabOrder = 1
          end
          object CheckBox3: TCheckBox
            Left = 24
            Top = 184
            Width = 129
            Height = 33
            Caption = 'Squaring'
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -24
            Font.Name = 'Segoe UI'
            Font.Style = []
            ParentFont = False
            TabOrder = 2
          end
          object CheckBox4: TCheckBox
            Left = 24
            Top = 229
            Width = 161
            Height = 33
            Caption = 'Squaring_>>'
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -24
            Font.Name = 'Segoe UI'
            Font.Style = []
            ParentFont = False
            TabOrder = 3
          end
          object Button1: TButton
            Left = 16
            Top = 35
            Width = 193
            Height = 41
            Caption = 'X^N'
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -21
            Font.Name = 'Segoe UI'
            Font.Style = []
            ParentFont = False
            TabOrder = 4
            OnClick = Button1Click
          end
        end
        object Edit1: TEdit
          Left = 63
          Top = 21
          Width = 170
          Height = 38
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -21
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
          TabOrder = 2
          Text = 'Edit1'
        end
        object Edit2: TEdit
          Left = 63
          Top = 74
          Width = 170
          Height = 38
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -21
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
          TabOrder = 3
          Text = 'Edit2'
        end
        object Edit4: TEdit
          Left = 63
          Top = 164
          Width = 170
          Height = 38
          TabOrder = 4
          Text = 'Edit4'
        end
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'Polynomials'
      ImageIndex = 1
      object Memo2: TMemo
        Left = 256
        Top = 0
        Width = 699
        Height = 498
        Align = alRight
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -21
        Font.Name = 'Segoe UI'
        Font.Style = []
        Lines.Strings = (
          'Memo2')
        ParentFont = False
        ScrollBars = ssBoth
        TabOrder = 0
      end
      object Panel2: TPanel
        Left = 0
        Top = 0
        Width = 256
        Height = 498
        Align = alClient
        TabOrder = 1
        object Label3: TLabel
          Left = 17
          Top = 15
          Width = 121
          Height = 30
          Caption = #22810#38917#24335#20418#25976' :'
        end
        object Label4: TLabel
          Left = 34
          Top = 115
          Width = 38
          Height = 30
          Caption = 'X = '
        end
        object Label8: TLabel
          Left = 17
          Top = 164
          Width = 99
          Height = 30
          Caption = #24490#29872#27425#25976' :'
        end
        object Edit3: TEdit
          Left = 78
          Top = 112
          Width = 172
          Height = 38
          TabOrder = 0
          Text = 'Edit3'
        end
        object Button2: TButton
          Left = 53
          Top = 55
          Width = 197
          Height = 36
          Caption = #35712#21462#20418#25976#27284#26696
          TabOrder = 1
          OnClick = Button2Click
        end
        object Edit5: TEdit
          Left = 78
          Top = 200
          Width = 172
          Height = 38
          TabOrder = 2
          Text = 'Edit5'
        end
        object GroupBox2: TGroupBox
          Left = 17
          Top = 243
          Width = 233
          Height = 246
          Caption = 'Algorithm Options : '
          TabOrder = 3
          object Label5: TLabel
            Left = 14
            Top = 117
            Width = 57
            Height = 30
            Caption = 'f(X) = '
          end
          object Label7: TLabel
            Left = 17
            Top = 37
            Width = 199
            Height = 60
            Caption = #35336#31639#24478' 1 ~ X '#30340#25152#26377' '#13#10'f(X) '#25976#20540' :'
          end
          object CheckBox5: TCheckBox
            Left = 17
            Top = 164
            Width = 183
            Height = 33
            Caption = 'Naive'#39's method'
            TabOrder = 0
          end
          object CheckBox6: TCheckBox
            Left = 17
            Top = 203
            Width = 183
            Height = 33
            Caption = 'Horner'#39's method'
            TabOrder = 1
          end
          object Button3: TButton
            Left = 77
            Top = 115
            Width = 146
            Height = 41
            Caption = #35336#31639' f(X) '#25976#20540
            TabOrder = 2
            OnClick = Button3Click
          end
        end
      end
    end
  end
  object OpenDialog1: TOpenDialog
    Left = 144
    Top = 106
  end
end
