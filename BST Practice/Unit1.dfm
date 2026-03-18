object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 715
  ClientWidth = 781
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object Splitter1: TSplitter
    Left = 291
    Top = 0
    Height = 715
    ExplicitLeft = 200
    ExplicitTop = 448
    ExplicitHeight = 100
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 291
    Height = 715
    Align = alLeft
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    ExplicitHeight = 683
    object Label1: TLabel
      Left = 5
      Top = 27
      Width = 92
      Height = 30
      Caption = 'Element : '
    end
    object Button1: TButton
      Left = 0
      Top = 105
      Width = 132
      Height = 41
      Caption = #25554#20837#20803#32032
      TabOrder = 0
      OnClick = Button1Click
    end
    object Button3: TButton
      Left = 148
      Top = 105
      Width = 137
      Height = 41
      Caption = #21034#38500#20803#32032
      TabOrder = 1
      OnClick = Button3Click
    end
    object Edit1: TEdit
      Left = 103
      Top = 24
      Width = 177
      Height = 38
      TabOrder = 2
      Text = 'Edit1'
    end
    object Button10: TButton
      Left = 0
      Top = 630
      Width = 285
      Height = 33
      Caption = 'Draw BST'
      TabOrder = 3
      OnClick = Button10Click
    end
    object Button11: TButton
      Left = 0
      Top = 669
      Width = 285
      Height = 33
      Caption = 'Clear BST'
      TabOrder = 4
      OnClick = Button11Click
    end
    object GroupBox1: TGroupBox
      Left = 0
      Top = 440
      Width = 285
      Height = 136
      Caption = 'Traversal : '
      TabOrder = 5
      object Button6: TButton
        Left = 108
        Top = 84
        Width = 78
        Height = 37
        Caption = 'Infix'
        TabOrder = 0
        OnClick = Button6Click
      end
      object Button7: TButton
        Left = 3
        Top = 84
        Width = 99
        Height = 39
        Caption = 'Prefix'
        TabOrder = 1
        OnClick = Button7Click
      end
      object Button8: TButton
        Left = 192
        Top = 84
        Width = 90
        Height = 37
        Caption = 'Postfix'
        TabOrder = 2
        OnClick = Button8Click
      end
      object RadioButton1: TRadioButton
        Left = 3
        Top = 32
        Width = 113
        Height = 33
        Caption = 'Recursive'
        TabOrder = 3
      end
      object RadioButton2: TRadioButton
        Left = 122
        Top = 25
        Width = 160
        Height = 53
        Caption = 'Non-Recursive'
        TabOrder = 4
      end
    end
    object RadioButton3: TRadioButton
      Left = 6
      Top = 68
      Width = 113
      Height = 29
      Caption = 'Recursive'
      TabOrder = 6
    end
    object RadioButton4: TRadioButton
      Left = 125
      Top = 68
      Width = 160
      Height = 31
      Caption = 'Non-Recursive'
      TabOrder = 7
    end
    object GroupBox2: TGroupBox
      Left = 6
      Top = 194
      Width = 279
      Height = 240
      Caption = 'Insert '#38568#27231#29986#29983#25976#20540' :'
      TabOrder = 8
      object Label2: TLabel
        Left = 3
        Top = 35
        Width = 149
        Height = 30
        Caption = #36664#20837#20803#32032#25976#37327' : '
      end
      object Label3: TLabel
        Left = 3
        Top = 71
        Width = 120
        Height = 30
        Caption = 'Range'#20540#22495' : '
      end
      object Label4: TLabel
        Left = 43
        Top = 107
        Width = 100
        Height = 30
        Caption = #26368#22823#20540' -> '
      end
      object Label5: TLabel
        Left = 43
        Top = 152
        Width = 100
        Height = 30
        Caption = #26368#23567#20540' -> '
      end
      object Button4: TButton
        Left = 3
        Top = 196
        Width = 273
        Height = 34
        Caption = #25554#20837#20803#32032
        TabOrder = 0
        OnClick = Button4Click
      end
      object Edit2: TEdit
        Left = 158
        Top = 35
        Width = 118
        Height = 38
        TabOrder = 1
        Text = 'Edit2'
      end
      object Edit3: TEdit
        Left = 149
        Top = 108
        Width = 127
        Height = 38
        TabOrder = 2
        Text = 'Edit3'
      end
      object Edit4: TEdit
        Left = 149
        Top = 152
        Width = 127
        Height = 38
        TabOrder = 3
        Text = 'Edit4'
      end
    end
    object Button5: TButton
      Left = 0
      Top = 152
      Width = 285
      Height = 36
      Caption = #25628#23563#20803#32032
      TabOrder = 9
      OnClick = Button5Click
    end
    object Button2: TButton
      Left = 0
      Top = 582
      Width = 285
      Height = 42
      Caption = 'Level-Order Traversal'
      TabOrder = 10
      OnClick = Button2Click
    end
  end
  object PageControl1: TPageControl
    Left = 294
    Top = 0
    Width = 487
    Height = 715
    ActivePage = TabSheet2
    Align = alClient
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    ExplicitWidth = 477
    ExplicitHeight = 683
    object TabSheet1: TTabSheet
      Caption = 'Tracing Record'
      object Memo1: TMemo
        Left = 0
        Top = 0
        Width = 471
        Height = 657
        Align = alClient
        Lines.Strings = (
          'Memo1')
        ScrollBars = ssBoth
        TabOrder = 0
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'Binary Tree Drawing'
      ImageIndex = 1
      object ScrollBox1: TScrollBox
        Left = 0
        Top = 0
        Width = 471
        Height = 657
        Align = alClient
        TabOrder = 0
        ExplicitWidth = 461
        ExplicitHeight = 625
        object Image1: TImage
          Left = 0
          Top = 0
          Width = 467
          Height = 653
          Align = alClient
          ExplicitLeft = 176
          ExplicitTop = 280
          ExplicitWidth = 105
          ExplicitHeight = 105
        end
      end
    end
  end
end
