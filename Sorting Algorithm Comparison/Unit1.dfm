object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 766
  ClientWidth = 982
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object Splitter1: TSplitter
    Left = 289
    Top = 0
    Height = 766
    ExplicitLeft = 344
    ExplicitTop = 480
    ExplicitHeight = 100
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 289
    Height = 766
    Align = alLeft
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    ExplicitHeight = 744
    object GroupBox1: TGroupBox
      Left = 0
      Top = 0
      Width = 283
      Height = 161
      Caption = 'Input'
      TabOrder = 0
      object Label1: TLabel
        Left = 37
        Top = 120
        Width = 108
        Height = 30
        Caption = #24490#29872#27425#25976' ='
      end
      object Label2: TLabel
        Left = 18
        Top = 76
        Width = 135
        Height = 30
        Caption = 'Range(1, N) = '
      end
      object Label3: TLabel
        Left = 14
        Top = 32
        Width = 42
        Height = 30
        Caption = 'N = '
      end
      object Label6: TLabel
        Left = 128
        Top = 32
        Width = 74
        Height = 30
        Caption = 'Times ='
      end
      object Edit1: TEdit
        Left = 54
        Top = 32
        Width = 68
        Height = 38
        TabOrder = 0
        Text = '500'
      end
      object Edit2: TEdit
        Left = 208
        Top = 29
        Width = 68
        Height = 38
        TabOrder = 1
        Text = 'Edit2'
      end
      object Edit3: TEdit
        Left = 159
        Top = 73
        Width = 121
        Height = 38
        TabOrder = 2
        Text = 'Edit3'
      end
      object Edit4: TEdit
        Left = 159
        Top = 117
        Width = 121
        Height = 38
        TabOrder = 3
        Text = 'Edit4'
      end
    end
    object GroupBox2: TGroupBox
      Left = 3
      Top = 161
      Width = 283
      Height = 496
      Caption = 'Sorting_Selection'
      TabOrder = 1
      object Label4: TLabel
        Left = 35
        Top = 232
        Width = 147
        Height = 30
        Caption = '(Non-Recursive)'
      end
      object Label5: TLabel
        Left = 35
        Top = 344
        Width = 147
        Height = 30
        Caption = '(Non-Recursive)'
      end
      object CheckBox1: TCheckBox
        Left = 11
        Top = 32
        Width = 159
        Height = 41
        Caption = 'Selection Sort'
        TabOrder = 0
      end
      object CheckBox2: TCheckBox
        Left = 10
        Top = 79
        Width = 151
        Height = 34
        Caption = 'Insertion Sort'
        TabOrder = 1
      end
      object CheckBox3: TCheckBox
        Left = 10
        Top = 119
        Width = 137
        Height = 33
        Caption = 'Bubble Sort'
        TabOrder = 2
      end
      object CheckBox4: TCheckBox
        Left = 13
        Top = 158
        Width = 235
        Height = 33
        Caption = 'Quick Sort (Recursive)'
        TabOrder = 3
      end
      object CheckBox5: TCheckBox
        Left = 13
        Top = 197
        Width = 122
        Height = 36
        Caption = 'Quick Sort'
        TabOrder = 4
      end
      object CheckBox6: TCheckBox
        Left = 13
        Top = 268
        Width = 232
        Height = 29
        Caption = 'Merge Sort (Recursive)'
        TabOrder = 5
      end
      object CheckBox7: TCheckBox
        Left = 13
        Top = 312
        Width = 129
        Height = 33
        Caption = 'Merge Sort'
        TabOrder = 6
      end
      object CheckBox8: TCheckBox
        Left = 13
        Top = 380
        Width = 137
        Height = 33
        Caption = 'Heap Sort'
        TabOrder = 7
      end
      object CheckBox9: TCheckBox
        Left = 14
        Top = 419
        Width = 121
        Height = 33
        Caption = 'Radix Sort'
        TabOrder = 8
      end
      object CheckBox10: TCheckBox
        Left = 13
        Top = 458
        Width = 168
        Height = 29
        Caption = 'Counting Sort'
        TabOrder = 9
      end
    end
    object CheckBox11: TCheckBox
      Left = 54
      Top = 660
      Width = 161
      Height = 34
      Caption = 'Display Data'
      TabOrder = 2
    end
    object CheckBox12: TCheckBox
      Left = 54
      Top = 690
      Width = 168
      Height = 34
      Caption = 'Draw Diagram'
      TabOrder = 3
    end
    object Button1: TButton
      Left = 3
      Top = 725
      Width = 283
      Height = 33
      Caption = 'Execute'
      TabOrder = 4
      OnClick = Button1Click
    end
  end
  object PageControl1: TPageControl
    Left = 292
    Top = 0
    Width = 690
    Height = 766
    ActivePage = TabSheet1
    Align = alClient
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    ExplicitWidth = 680
    ExplicitHeight = 744
    object TabSheet1: TTabSheet
      Caption = 'Data'
      object Memo1: TMemo
        Left = 0
        Top = 0
        Width = 674
        Height = 708
        Align = alClient
        Lines.Strings = (
          'Memo1')
        ScrollBars = ssVertical
        TabOrder = 0
        ExplicitHeight = 718
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'Diagram'
      ImageIndex = 1
      object Chart1: TChart
        Left = 0
        Top = 0
        Width = 674
        Height = 708
        Title.Text.Strings = (
          'TChart')
        Align = alClient
        TabOrder = 0
        ExplicitWidth = 664
        ExplicitHeight = 686
        DefaultCanvas = 'TGDIPlusCanvas'
        ColorPaletteIndex = 13
        object Series1: TLineSeries
          Brush.BackColor = clDefault
          Pointer.InflateMargins = True
          Pointer.Style = psRectangle
          XValues.Name = 'X'
          XValues.Order = loAscending
          YValues.Name = 'Y'
          YValues.Order = loNone
        end
      end
    end
  end
end
