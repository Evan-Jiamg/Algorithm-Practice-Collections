//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TEdit *Edit1;
	TButton *Button1;
	TEdit *Edit2;
	TEdit *Edit3;
	TLabel *Label2;
	TLabel *Label3;
	TMemo *Memo1;
	TPageControl *PageControl1;
	TTabSheet *TabSheet1;
	TTabSheet *TabSheet2;
	TMemo *Memo2;
	TStringGrid *StringGrid1;
	TButton *Button2;
	TButton *Button3;
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
