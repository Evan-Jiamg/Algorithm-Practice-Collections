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
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TPageControl *PageControl1;
	TTabSheet *TabSheet1;
	TTabSheet *TabSheet2;
	TTabSheet *TabSheet3;
	TPanel *Panel1;
	TMemo *Memo1;
	TButton *Button1;
	TButton *Button2;
	TPanel *Panel2;
	TMemo *Memo2;
	TLabel *Label2;
	TEdit *Edit4;
	TLabel *Label3;
	TLabel *Label4;
	TEdit *Edit5;
	TButton *Button3;
	TButton *Button4;
	TMemo *Memo3;
	TPanel *Panel3;
	TLabel *Label6;
	TLabel *Label7;
	TEdit *Edit7;
	TButton *Button5;
	TButton *Button6;
	TLabel *Label1;
	TMemo *Memo4;
	TMemo *Memo5;
	TMemo *Memo6;
	TMemo *Memo7;
	TMemo *Memo9;
	TButton *Button7;
	TButton *Button8;
	TButton *Button9;
	TMemo *Memo8;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
	void __fastcall Button7Click(TObject *Sender);
	void __fastcall Button8Click(TObject *Sender);
	void __fastcall Button9Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
