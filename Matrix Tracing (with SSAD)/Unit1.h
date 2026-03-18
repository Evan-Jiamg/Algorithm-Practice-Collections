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
	TSplitter *Splitter1;
	TGroupBox *GroupBox1;
	TButton *Button1;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TEdit *Edit1;
	TEdit *Edit2;
	TEdit *Edit3;
	TLabel *Label5;
	TButton *Button2;
	TEdit *Edit4;
	TLabel *Label6;
	TEdit *Edit5;
	TGroupBox *GroupBox2;
	TButton *Button3;
	TButton *Button4;
	TButton *Button5;
	TCheckBox *CheckBox1;
	TOpenDialog *OpenDialog1;
	TPageControl *PageControl1;
	TTabSheet *TabSheet1;
	TStringGrid *StringGrid1;
	TTabSheet *TabSheet2;
	TMemo *Memo2;
	TTabSheet *TabSheet3;
	TStringGrid *StringGrid2;
	TTabSheet *TabSheet4;
	TStringGrid *StringGrid3;
	TTabSheet *TabSheet6;
	TMemo *Memo3;
	TTabSheet *TabSheet7;
	TMemo *Memo4;
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
