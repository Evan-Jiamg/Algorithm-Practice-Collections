object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 628
  ClientWidth = 865
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object Splitter1: TSplitter
    Left = 249
    Top = 0
    Width = 5
    Height = 628
    ExplicitLeft = 202
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 249
    Height = 628
    Align = alLeft
    TabOrder = 0
    ExplicitHeight = 596
    object Label1: TLabel
      Left = 22
      Top = 72
      Width = 63
      Height = 30
      Caption = 'Size = '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -21
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
    end
    object Label2: TLabel
      Left = 32
      Top = 113
      Width = 170
      Height = 32
      Caption = '( 1 < Size < 30 )'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -24
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
    end
    object Button1: TButton
      Left = 10
      Top = 222
      Width = 233
      Height = 41
      Caption = 'Solve n-Queen problem'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -21
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      OnClick = Button1Click
    end
    object Edit1: TEdit
      Left = 91
      Top = 69
      Width = 142
      Height = 38
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -21
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
      Text = 'Edit1'
    end
    object CheckBox1: TCheckBox
      Left = 10
      Top = 151
      Width = 233
      Height = 65
      Caption = 'Solve and Show in Grid'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -21
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 2
    end
  end
  object PageControl1: TPageControl
    Left = 254
    Top = 0
    Width = 611
    Height = 628
    ActivePage = TabSheet3
    Align = alClient
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    ExplicitWidth = 601
    ExplicitHeight = 596
    object TabSheet1: TTabSheet
      Caption = 'Queens Positions'
      object Memo1: TMemo
        Left = 0
        Top = 0
        Width = 595
        Height = 570
        Align = alClient
        Lines.Strings = (
          'Memo1')
        ScrollBars = ssBoth
        TabOrder = 0
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'Queens in Chess'
      ImageIndex = 1
      object Memo2: TMemo
        Left = 0
        Top = 0
        Width = 595
        Height = 570
        Align = alClient
        Lines.Strings = (
          'Memo2')
        ScrollBars = ssBoth
        TabOrder = 0
      end
    end
    object TabSheet3: TTabSheet
      Caption = 'Queen in Grid'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -21
      Font.Name = 'Segoe UI'
      Font.Style = []
      ImageIndex = 2
      ParentFont = False
      object StringGrid1: TStringGrid
        Left = 0
        Top = 0
        Width = 595
        Height = 570
        Align = alClient
        TabOrder = 0
      end
    end
  end
end
