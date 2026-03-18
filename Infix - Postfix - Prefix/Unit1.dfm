object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 417
  ClientWidth = 1369
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
    Width = 1369
    Height = 417
    ActivePage = TabSheet1
    Align = alClient
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    ExplicitWidth = 1359
    ExplicitHeight = 385
    object TabSheet1: TTabSheet
      Caption = 'Infix'
      object Panel1: TPanel
        Left = 0
        Top = 0
        Width = 848
        Height = 359
        Align = alClient
        TabOrder = 0
        object Label3: TLabel
          Left = 24
          Top = 67
          Width = 153
          Height = 37
          Caption = 'Infix '#36939#31639#24335' :'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -27
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
        end
        object Label1: TLabel
          Left = 24
          Top = 16
          Width = 446
          Height = 37
          Caption = 'Infix '#36939#31639#24335#36681' Postfix / Prefix '#36939#31639#24335' :'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -27
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
        end
        object Button1: TButton
          Left = 24
          Top = 136
          Width = 185
          Height = 41
          Caption = 'Infix -> Postfix'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -27
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
          TabOrder = 0
          OnClick = Button1Click
        end
        object Button2: TButton
          Left = 24
          Top = 210
          Width = 185
          Height = 41
          Caption = 'Infix -> Prefix'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -27
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
          TabOrder = 1
          OnClick = Button2Click
        end
        object Edit4: TEdit
          Left = 232
          Top = 70
          Width = 593
          Height = 38
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -21
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
          TabOrder = 2
          Text = 'a+b*d+c/e'
        end
        object Memo6: TMemo
          Left = 232
          Top = 120
          Width = 593
          Height = 65
          Lines.Strings = (
            'Memo4')
          TabOrder = 3
        end
        object Memo7: TMemo
          Left = 232
          Top = 200
          Width = 593
          Height = 65
          Lines.Strings = (
            'Memo4')
          TabOrder = 4
        end
        object Button9: TButton
          Left = 24
          Top = 288
          Width = 801
          Height = 43
          Caption = 'Re-Run'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -27
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
          TabOrder = 5
          OnClick = Button9Click
        end
      end
      object Memo1: TMemo
        Left = 848
        Top = 0
        Width = 505
        Height = 359
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
        TabOrder = 1
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'Postfix'
      ImageIndex = 1
      object Panel2: TPanel
        Left = 0
        Top = 0
        Width = 856
        Height = 359
        Align = alClient
        TabOrder = 0
        object Label2: TLabel
          Left = 24
          Top = 16
          Width = 446
          Height = 37
          Caption = 'Postfix '#36939#31639#24335#36681' Infix / Prefix '#36939#31639#24335' :'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -27
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
        end
        object Label4: TLabel
          Left = 24
          Top = 72
          Width = 181
          Height = 37
          Caption = 'Postfix '#36939#31639#24335' :'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -27
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
        end
        object Edit5: TEdit
          Left = 248
          Top = 70
          Width = 593
          Height = 38
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -21
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
          TabOrder = 0
          Text = 'abd*+ce/+'
        end
        object Button3: TButton
          Left = 24
          Top = 136
          Width = 201
          Height = 41
          Caption = 'Postfix -> Infix'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -27
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
          TabOrder = 1
          OnClick = Button3Click
        end
        object Button4: TButton
          Left = 24
          Top = 218
          Width = 201
          Height = 41
          Caption = 'Postfix -> Prefix'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -27
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
          TabOrder = 2
          OnClick = Button4Click
        end
        object Memo4: TMemo
          Left = 248
          Top = 124
          Width = 593
          Height = 61
          Lines.Strings = (
            'Memo4')
          TabOrder = 3
        end
        object Memo5: TMemo
          Left = 248
          Top = 210
          Width = 593
          Height = 61
          Lines.Strings = (
            'Memo5')
          TabOrder = 4
        end
        object Button8: TButton
          Left = 24
          Top = 288
          Width = 817
          Height = 42
          Caption = 'Re-Run'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -27
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
          TabOrder = 5
          OnClick = Button8Click
        end
      end
      object Memo2: TMemo
        Left = 856
        Top = 0
        Width = 497
        Height = 359
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
        TabOrder = 1
      end
    end
    object TabSheet3: TTabSheet
      Caption = 'Prefix'
      ImageIndex = 2
      object Memo3: TMemo
        Left = 849
        Top = 0
        Width = 504
        Height = 359
        Align = alClient
        Lines.Strings = (
          'Memo3')
        ScrollBars = ssBoth
        TabOrder = 0
        ExplicitWidth = 494
        ExplicitHeight = 327
      end
      object Panel3: TPanel
        Left = 0
        Top = 0
        Width = 849
        Height = 359
        Align = alLeft
        TabOrder = 1
        ExplicitHeight = 327
        object Label6: TLabel
          Left = 24
          Top = 16
          Width = 446
          Height = 37
          Caption = 'Prefix '#36939#31639#24335#36681' Infix / Postfix '#36939#31639#24335' :'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -27
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
        end
        object Label7: TLabel
          Left = 24
          Top = 72
          Width = 169
          Height = 37
          Caption = 'Prefix '#36939#31639#24335' :'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -27
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
        end
        object Edit7: TEdit
          Left = 240
          Top = 75
          Width = 593
          Height = 38
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -21
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
          TabOrder = 0
          Text = '+a+*bd/ce'
        end
        object Button5: TButton
          Left = 24
          Top = 140
          Width = 193
          Height = 41
          Caption = 'Prefix -> Infix'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -27
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
          TabOrder = 1
          OnClick = Button5Click
        end
        object Button6: TButton
          Left = 24
          Top = 224
          Width = 193
          Height = 41
          Caption = 'Prefix -> Postfix'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -27
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
          TabOrder = 2
          OnClick = Button6Click
        end
        object Memo9: TMemo
          Left = 240
          Top = 212
          Width = 593
          Height = 61
          Lines.Strings = (
            'Memo4')
          TabOrder = 3
        end
        object Button7: TButton
          Left = 24
          Top = 296
          Width = 809
          Height = 41
          Caption = 'Re-Run'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -27
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
          TabOrder = 4
          OnClick = Button7Click
        end
        object Memo8: TMemo
          Left = 240
          Top = 128
          Width = 593
          Height = 65
          Lines.Strings = (
            'Memo8')
          TabOrder = 5
        end
      end
    end
  end
end
