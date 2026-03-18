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
#include <Vcl.Dialogs.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TEdit *Edit1;
	TLabel *Label1;
	TEdit *Edit2;
	TLabel *Label2;
	TButton *Button1;
	TMemo *Memo1;
	TGroupBox *GroupBox1;
	TCheckBox *CheckBox1;
	TCheckBox *CheckBox2;
	TCheckBox *CheckBox3;
	TCheckBox *CheckBox4;
	TPageControl *PageControl1;
	TTabSheet *TabSheet1;
	TTabSheet *TabSheet2;
	TMemo *Memo2;
	TButton *Button2;
	TLabel *Label3;
	TPanel *Panel1;
	TSplitter *Splitter1;
	TEdit *Edit3;
	TLabel *Label4;
	TButton *Button3;
	TLabel *Label5;
	TPanel *Panel2;
	TOpenDialog *OpenDialog1;
	TLabel *Label6;
	TEdit *Edit4;
	TLabel *Label7;
	TLabel *Label8;
	TEdit *Edit5;
	TCheckBox *CheckBox5;
	TCheckBox *CheckBox6;
	TGroupBox *GroupBox2;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
