//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

char **Table = NULL;
TList *Solutions = NULL;
int Counts = 0;
int CurrentSolutionIndex = 0;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	Memo1->Clear();
	Memo2->Clear();
	Edit1->Clear();
}
//---------------------------------------------------------------------------
void createTable(int n)
{
	Table = new char*[n];
	for (int i = 0; i < n; i++) {
		Table[i] = new char[n];
		memset(Table[i], 0, n);
	}
}

void deleteTable(int n)
{
	for (int i = 0; i < n; i++) {
		delete[] Table[i];
	}
	delete[] Table;
	Table = NULL;
}

bool checkqueen(int x, int y, int n)
{
    for (int i = 0; i < y; i++)
		if (Table[i][x])
            return false;
    for (int i = x-1, j = y-1; i>=0 && j>=0; i--, j--)
        if (Table[j][i])
            return false;
    for (int i = x+1, j = y-1; i<n && j>=0; i++, j--)
        if (Table[j][i])
            return false;
    return true;
}


void printTable(int n, TMemo *Memo2, TMemo *Memo1, TObject* Sender)
{
	for (int i = 0; i < n; i++) {
		String line = "";
        for (int j = 0; j < n; j++) {
			if (Table[i][j])
				line += "Q ";
            else
                line += ". ";
		}
        Memo2->Lines->Add(line);
	}
    Memo2->Lines->Add("");

    String pos = "";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (Table[i][j]) {
				pos += IntToStr(j+1) + " ";
                break;
			}
        }
	}
	pos += "[" + IntToStr(Counts) + "]";
	Memo1->Lines->Add(pos);

	if (Form1->CheckBox1->Checked) {
		Form1->PageControl1->ActivePageIndex = 2;
		Form1->StringGrid1->RowCount = n ;
		Form1->StringGrid1->ColCount = n ;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (Table[i][j])
					Form1->StringGrid1->Cells[j][i] = "Q" ;
				else
					Form1->StringGrid1->Cells[j][i] = "-" ;
			}
		}
		ShowMessage("this is the solution # " + IntToStr(Counts)) ;
	}
}

void nqueen(int line, int n, bool saveMode, TMemo *Memo2, TMemo *Memo1, TCheckBox *checkbox, TObject* Sender)
{
	for (int list = 0; list < n; list++) {
		if (checkqueen(list, line, n)) {
			Table[line][list] = 'Q';
			if (line == n-1) {
				Counts++;
				Memo2->Lines->Add("(" + IntToStr(Counts) + ")");
				printTable(n, Memo2, Memo1, Form1);

				Table[line][list] = 0x00;
                return;
            }
			nqueen(line+1, n, saveMode, Memo2, Memo1, checkbox, Form1);
            Table[line][list] = 0x00;
        }
    }
}

void showSolution(int *solution, int n, TMemo *Memo1, TStringGrid *grid)
{
    Memo1->Lines->Clear();
    for (int i = 0; i < n; i++) {
        String line = "";
        for (int j = 0; j < n; j++) {
            if (solution[i] == j)
				line += "Q ";
            else
                line += ". ";
        }
        Memo1->Lines->Add(line);
    }
    String pos = "";
    for (int i = 0; i < n; i++) {
        pos += IntToStr(solution[i] + 1) + " ";
	}
    pos += "[" + IntToStr(CurrentSolutionIndex + 1) + "]";
	Memo1->Lines->Add(pos);

    grid->Invalidate();
}

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	Memo1->Clear();
	Memo2->Clear();
    Counts = 0;

	int n;
	if(!TryStrToInt(Edit1->Text, n) || n <= 1 || n >= 30){
		PageControl1->ActivePage = TabSheet1;
		Form1->Memo1->Lines->Add("請輸入 1 < n < 30 的正整數!");
		Form1->Memo2->Lines->Add("請輸入 1 < n < 30 的正整數!");
		return;
	}

    // 清除舊的Solutions
    if (!Solutions)
        Solutions = new TList();
    else {
        for (int i = 0; i < Solutions->Count; i++)
            delete[] (int*)Solutions->Items[i];
		Solutions->Clear();
	}
	CurrentSolutionIndex = 0;

	createTable(n);
	PageControl1->ActivePage = TabSheet1;

	nqueen(0, n, CheckBox1->Checked, Memo2, Memo1, CheckBox1, Form1);
	Memo1->Lines->Add("# Solutions -> " + IntToStr(Counts) + " for the " + IntToStr(n) + "-Queen problem");
    Memo2->Lines->Add("# Solutions -> " + IntToStr(Counts) + " for the " + IntToStr(n) + "-Queen problem");

	deleteTable(n);
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

