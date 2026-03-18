object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 604
  ClientWidth = 1014
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
    Width = 1014
    Height = 604
    ActivePage = TabSheet1
    Align = alClient
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    ExplicitWidth = 1004
    ExplicitHeight = 572
    object TabSheet1: TTabSheet
      Caption = 'Singly Linked List'
      object Memo1: TMemo
        Left = 0
        Top = 304
        Width = 998
        Height = 242
        Align = alBottom
        Lines.Strings = (
          'Memo1')
        ScrollBars = ssBoth
        TabOrder = 0
      end
      object Panel1: TPanel
        Left = 0
        Top = 0
        Width = 998
        Height = 304
        Align = alClient
        TabOrder = 1
        object Label1: TLabel
          Left = 9
          Top = 20
          Width = 99
          Height = 30
          Caption = #36664#20837#20803#32032': '
        end
        object Label2: TLabel
          Left = 9
          Top = 70
          Width = 143
          Height = 30
          Caption = #38568#27231#29986#29983#25976#20540': '
        end
        object Label3: TLabel
          Left = 25
          Top = 188
          Width = 83
          Height = 30
          Caption = 'Target = '
        end
        object Label4: TLabel
          Left = 253
          Top = 109
          Width = 85
          Height = 30
          Caption = 'Range = '
        end
        object Label5: TLabel
          Left = 70
          Top = 113
          Width = 38
          Height = 30
          Caption = 'n = '
        end
        object Edit1: TEdit
          Left = 114
          Top = 17
          Width = 121
          Height = 38
          TabOrder = 0
          Text = 'Edit1'
        end
        object Edit2: TEdit
          Left = 114
          Top = 110
          Width = 121
          Height = 38
          TabOrder = 1
          Text = 'Edit2'
        end
        object Edit3: TEdit
          Left = 114
          Top = 185
          Width = 121
          Height = 38
          TabOrder = 2
          Text = 'Edit3'
        end
        object Button1: TButton
          Left = 253
          Top = 17
          Width = 135
          Height = 38
          Caption = 'Insert as First'
          TabOrder = 3
          OnClick = Button1Click
        end
        object Button2: TButton
          Left = 401
          Top = 17
          Width = 136
          Height = 38
          Caption = 'Insert as Last'
          TabOrder = 4
          OnClick = Button2Click
        end
        object Button3: TButton
          Left = 481
          Top = 109
          Width = 232
          Height = 38
          Caption = 'Randomly Insert as First'
          TabOrder = 5
          OnClick = Button3Click
        end
        object Edit4: TEdit
          Left = 344
          Top = 109
          Width = 121
          Height = 38
          TabOrder = 6
          Text = 'Edit4'
        end
        object Button8: TButton
          Left = 719
          Top = 109
          Width = 233
          Height = 38
          Caption = 'Randomly Insert as Last'
          TabOrder = 7
          OnClick = Button8Click
        end
        object Button9: TButton
          Left = 631
          Top = 256
          Width = 321
          Height = 42
          Caption = 'Clear Singly Linked List / Re-Run'
          TabOrder = 8
          OnClick = Button9Click
        end
        object Button10: TButton
          Left = 344
          Top = 256
          Width = 264
          Height = 42
          Caption = 'Print the Singly Linked List'
          TabOrder = 9
          OnClick = Button10Click
        end
        object Button11: TButton
          Left = 56
          Top = 256
          Width = 264
          Height = 42
          Caption = 'Reversed Linked List'
          TabOrder = 10
          OnClick = Button11Click
        end
        object GroupBox1: TGroupBox
          Left = 253
          Top = 153
          Width = 740
          Height = 88
          Caption = #21151#33021#36984#25799' : '
          TabOrder = 11
          object CheckBox1: TCheckBox
            Left = 599
            Top = 35
            Width = 126
            Height = 29
            Caption = #21034#38500' Target'
            TabOrder = 0
            OnClick = CheckBox1Click
          end
          object CheckBox2: TCheckBox
            Left = 368
            Top = 35
            Width = 225
            Height = 35
            Caption = #22312' Target '#24460#25554#20837#20803#32032
            TabOrder = 1
            OnClick = CheckBox2Click
          end
          object CheckBox3: TCheckBox
            Left = 132
            Top = 35
            Width = 230
            Height = 35
            Caption = #22312' Target '#21069#25554#20837#20803#32032
            TabOrder = 2
            OnClick = CheckBox3Click
          end
          object Button5: TButton
            Left = 10
            Top = 32
            Width = 103
            Height = 41
            Caption = #38283#22987#23563#25214
            TabOrder = 3
            OnClick = Button5Click
          end
        end
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'Doubly Linked List'
      ImageIndex = 1
      object Memo2: TMemo
        Left = 0
        Top = 271
        Width = 998
        Height = 275
        Align = alBottom
        Lines.Strings = (
          'Memo2')
        ScrollBars = ssBoth
        TabOrder = 0
      end
      object Panel2: TPanel
        Left = 0
        Top = 0
        Width = 998
        Height = 271
        Align = alClient
        TabOrder = 1
        object Label6: TLabel
          Left = 16
          Top = 16
          Width = 105
          Height = 30
          Caption = #36664#20837#20803#32032' : '
        end
        object Label7: TLabel
          Left = 38
          Top = 168
          Width = 83
          Height = 30
          Caption = 'Target = '
        end
        object Label8: TLabel
          Left = 16
          Top = 57
          Width = 143
          Height = 30
          Caption = #38568#27231#29986#29983#25976#20540' :'
        end
        object Label9: TLabel
          Left = 83
          Top = 93
          Width = 38
          Height = 30
          Caption = 'n = '
        end
        object Label10: TLabel
          Left = 270
          Top = 93
          Width = 85
          Height = 30
          Caption = 'Range = '
        end
        object Edit5: TEdit
          Left = 127
          Top = 13
          Width = 121
          Height = 38
          TabOrder = 0
          Text = 'Edit5'
        end
        object Edit6: TEdit
          Left = 127
          Top = 165
          Width = 121
          Height = 38
          TabOrder = 1
          Text = 'Edit6'
        end
        object Button4: TButton
          Left = 270
          Top = 14
          Width = 155
          Height = 36
          Caption = 'Insert as First'
          TabOrder = 2
          OnClick = Button4Click
        end
        object GroupBox2: TGroupBox
          Left = 270
          Top = 136
          Width = 563
          Height = 82
          Caption = #21151#33021#36984#25799' : '
          TabOrder = 3
          object RadioButton1: TRadioButton
            Left = 407
            Top = 40
            Width = 138
            Height = 27
            Caption = #21034#38500' Target'
            TabOrder = 0
          end
          object Button6: TButton
            Left = 15
            Top = 35
            Width = 155
            Height = 35
            Caption = #38283#22987#23563#25214
            TabOrder = 1
            OnClick = Button6Click
          end
          object RadioButton2: TRadioButton
            Left = 176
            Top = 37
            Width = 225
            Height = 33
            Caption = #22312' Target '#24460#25554#20837#20803#32032
            TabOrder = 2
          end
        end
        object Button7: TButton
          Left = 327
          Top = 224
          Width = 297
          Height = 41
          Caption = 'Print the Doubly Linked List'
          TabOrder = 4
          OnClick = Button7Click
        end
        object Button12: TButton
          Left = 640
          Top = 224
          Width = 337
          Height = 41
          Caption = 'Clear Doubly Linked List / Re-Run'
          TabOrder = 5
          OnClick = Button12Click
        end
        object Button13: TButton
          Left = 504
          Top = 88
          Width = 249
          Height = 42
          Caption = 'Randomly Insert as First'
          TabOrder = 6
          OnClick = Button13Click
        end
        object Edit7: TEdit
          Left = 127
          Top = 93
          Width = 121
          Height = 38
          TabOrder = 7
          Text = 'Edit7'
        end
        object Edit8: TEdit
          Left = 361
          Top = 90
          Width = 121
          Height = 38
          TabOrder = 8
          Text = 'Edit8'
        end
        object Button22: TButton
          Left = 16
          Top = 224
          Width = 297
          Height = 41
          Caption = 'Reversed Doubly Linked List'
          TabOrder = 9
          OnClick = Button22Click
        end
      end
    end
    object TabSheet3: TTabSheet
      Caption = 'Linked Stack'
      ImageIndex = 2
      object Memo3: TMemo
        Left = 0
        Top = 223
        Width = 998
        Height = 323
        Align = alBottom
        Lines.Strings = (
          'Memo3')
        ScrollBars = ssBoth
        TabOrder = 0
        ExplicitTop = 191
        ExplicitWidth = 988
      end
      object Panel3: TPanel
        Left = 0
        Top = 0
        Width = 998
        Height = 223
        Align = alClient
        TabOrder = 1
        ExplicitWidth = 988
        ExplicitHeight = 191
        object Label11: TLabel
          Left = 37
          Top = 24
          Width = 99
          Height = 30
          Caption = #36664#20837#20803#32032' :'
        end
        object Label12: TLabel
          Left = 37
          Top = 78
          Width = 143
          Height = 30
          Caption = #38568#27231#29986#29983#25976#20540' :'
        end
        object Label13: TLabel
          Left = 98
          Top = 125
          Width = 38
          Height = 30
          Caption = 'n = '
        end
        object Label14: TLabel
          Left = 296
          Top = 125
          Width = 85
          Height = 30
          Caption = 'Range = '
        end
        object Label15: TLabel
          Left = 37
          Top = 182
          Width = 105
          Height = 30
          Caption = #36664#20986#32080#26524' : '
        end
        object Edit9: TEdit
          Left = 142
          Top = 21
          Width = 121
          Height = 38
          TabOrder = 0
          Text = 'Edit9'
        end
        object Edit10: TEdit
          Left = 387
          Top = 122
          Width = 121
          Height = 38
          TabOrder = 1
          Text = 'Edit10'
        end
        object Button14: TButton
          Left = 296
          Top = 21
          Width = 121
          Height = 38
          Caption = 'Push '#20803#32032
          TabOrder = 2
          OnClick = Button14Click
        end
        object Button15: TButton
          Left = 537
          Top = 122
          Width = 192
          Height = 38
          Caption = 'Push n '#20491#38568#27231#20803#32032
          TabOrder = 3
          OnClick = Button15Click
        end
        object Button16: TButton
          Left = 142
          Top = 179
          Width = 121
          Height = 38
          Caption = 'Pop '#20803#32032
          TabOrder = 4
          OnClick = Button16Click
        end
        object Edit11: TEdit
          Left = 142
          Top = 122
          Width = 121
          Height = 38
          TabOrder = 5
          Text = 'Edit11'
        end
        object Button17: TButton
          Left = 296
          Top = 176
          Width = 433
          Height = 41
          Caption = 'Clear Linked Stack / Re-Run'
          TabOrder = 6
          OnClick = Button17Click
        end
      end
    end
    object TabSheet4: TTabSheet
      Caption = 'Linked Queue'
      ImageIndex = 3
      object Memo4: TMemo
        Left = 0
        Top = 222
        Width = 998
        Height = 324
        Align = alBottom
        Lines.Strings = (
          'Memo4')
        ScrollBars = ssBoth
        TabOrder = 0
      end
      object Panel4: TPanel
        Left = 0
        Top = 0
        Width = 998
        Height = 222
        Align = alClient
        TabOrder = 1
        object Label16: TLabel
          Left = 43
          Top = 16
          Width = 99
          Height = 30
          Caption = #36664#20837#20803#32032' :'
        end
        object Label17: TLabel
          Left = 43
          Top = 76
          Width = 143
          Height = 30
          Caption = #38568#27231#29986#29983#25976#20540' :'
        end
        object Label18: TLabel
          Left = 104
          Top = 115
          Width = 38
          Height = 30
          Caption = 'n = '
        end
        object Label19: TLabel
          Left = 320
          Top = 115
          Width = 85
          Height = 30
          Caption = 'Range = '
        end
        object Label20: TLabel
          Left = 43
          Top = 180
          Width = 105
          Height = 30
          Caption = #36664#20986#32080#26524' : '
        end
        object Edit12: TEdit
          Left = 148
          Top = 13
          Width = 150
          Height = 38
          TabOrder = 0
          Text = 'Edit12'
        end
        object Edit13: TEdit
          Left = 148
          Top = 112
          Width = 150
          Height = 38
          TabOrder = 1
          Text = 'Edit13'
        end
        object Edit14: TEdit
          Left = 409
          Top = 112
          Width = 121
          Height = 38
          TabOrder = 2
          Text = 'Edit14'
        end
        object Button18: TButton
          Left = 320
          Top = 13
          Width = 145
          Height = 38
          Caption = 'Insert Queue'
          TabOrder = 3
          OnClick = Button18Click
        end
        object Button19: TButton
          Left = 552
          Top = 112
          Width = 249
          Height = 38
          Caption = 'Insert n '#20491#20803#32032' in Queue'
          TabOrder = 4
          OnClick = Button19Click
        end
        object Button20: TButton
          Left = 148
          Top = 171
          Width = 149
          Height = 39
          Caption = 'Delete Queue'
          TabOrder = 5
          OnClick = Button20Click
        end
        object Button21: TButton
          Left = 320
          Top = 168
          Width = 481
          Height = 42
          Caption = 'Clear Linked Queue / Re-Run'
          TabOrder = 6
          OnClick = Button21Click
        end
      end
    end
  end
end
