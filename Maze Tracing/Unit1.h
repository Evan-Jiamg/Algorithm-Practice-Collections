//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Dialogs.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TGroupBox *GroupBox1;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TEdit *Edit1;
	TEdit *Edit2;
	TEdit *Edit3;
	TButton *Button2;
	TButton *Button4;
	TGroupBox *GroupBox2;
	TButton *Button5;
	TOpenDialog *OpenDialog1;
	TButton *Button8;
	TPageControl *PageControl1;
	TTabSheet *TabSheet1;
	TTabSheet *TabSheet2;
	TTabSheet *TabSheet3;
	TTabSheet *TabSheet4;
	TMemo *Memo1;
	TMemo *Memo2;
	TStringGrid *StringGrid1;
	TStringGrid *StringGrid2;
	TTrackBar *TrackBar1;
	TLabel *Label4;
	TCheckBox *CheckBox1;
	TButton *Button1;
	TLabel *Label5;
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall Button8Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall StringGrid2DrawCell(TObject *Sender, System::LongInt ACol, System::LongInt ARow,
          TRect &Rect, TGridDrawState State);
	void __fastcall StringGrid1DrawCell(TObject *Sender, System::LongInt ACol, System::LongInt ARow,
          TRect &Rect, TGridDrawState State);
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
