//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"

#include <stdio.h>
#include <time.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

// 多項式節點
struct PolyNode {
    int coef;
    int expo;
    PolyNode *next;
};

PolyNode *head = nullptr;
PolyNode *reverseHead = nullptr;

// 建立新節點
PolyNode *NewTerm(int coef, int expo) {
	PolyNode *r = new PolyNode;
    r->coef = coef;
    r->expo = expo;
    r->next = nullptr;
    return r;
}

// 清除多項式
void ClearPoly(PolyNode *&head) {
    while (head) {
		PolyNode *tmp = head;
        head = head->next;
        delete tmp;
	}
}

PolyNode *AttachLast(struct PolyNode *x, struct PolyNode *last) {
	x->next = last->next;
	last->next = x;
	return x;
}

PolyNode* AttachFirst(PolyNode* node, PolyNode* head) {
	node->next = head;
	return node;
}

// 用 FILE* 讀取多項式，從 a0 開始
PolyNode* ReadPolyFromFile(FILE *fp, int sel) {
	head = nullptr;
	reverseHead = nullptr;

	PolyNode *tail = nullptr;
	int coef, expo = 0;

	while (fscanf(fp, "%d", &coef) == 1) {
		if (coef != 0) {
			PolyNode* newNode = NewTerm(coef, expo);
			// 尾插法：head 儲存從 a₀ 開始的串列
			if (!head) {
				head = newNode;
				tail = newNode;
			} else {
				tail->next = newNode;
				tail = newNode;
			}

			// 頭插法：reverseHead 儲存從最高次項開始的串列
			PolyNode* revNode = NewTerm(coef, expo);
			reverseHead = AttachFirst(revNode, reverseHead);
		}
		expo++;
	}
	if (sel == 1) {
		return head;
	} else if (sel == 2) {
		return reverseHead;
	}
}

// 計算多項式在 x 的值
int EvaluatePoly(PolyNode *head, int x) {
    int result = 0;
    PolyNode *p = head;
	while (p) {
        result += p->coef * pow(x, p->expo);
        p = p->next;
	}
    return result;
}

// 顯示多項式
void ShowPoly(TMemo *Memo, PolyNode *head) {
	Memo->Lines->Clear();
	if (!head) {
		Memo->Lines->Add("0");
		return;
	}
	String output = "";
	PolyNode *p = head;
	while (p) {
		if (p->coef > 0 && output != "") output += "+";
		output += IntToStr(p->coef);
		if (p->expo > 0) {
			output += "x";
			if (p->expo > 1) {
				output += "^" + IntToStr(p->expo);
			}
		}
		output += " ";
		p = p->next;
	}
	Memo->Lines->Add(output);
}

// 快速冪函式：計算 x 的 n 次方
long long int fastPower(long long int x, int n) {
	long long int result = 1;  // 初始結果設成1
	while (n > 0) {
		if (n % 2 == 1) {   // 如果 n 是奇數
			result *= x;    // 多乘一次 x
		}
		x *= x;  // 把底數平方
		n /= 2;  // 指數除以2
	}
	return result;
}


long long int fastPowerBit(long long int x, int n) {
	long long int result = 1;  // 初始結果設成1
	while (n) {
		if (n & 1) {   // 如果 n 是奇數
			result *= x;    // 多乘一次 x
		}
		x *= x;  // 把底數平方
		n >>= 1 ;  // 指數除以2
	}
	return result;
}

long long int EvaluatePoly_Horner(PolyNode *reverseHead, int x) {
	if (!reverseHead) return 0;

	long long result = reverseHead->coef;
	PolyNode *p = reverseHead->next;

	while (p) {
		result = result * x + p->coef;
		p = p->next;
	}

	return result;
}



//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	Memo1->Clear();
	Memo2->Clear();
	Edit1->Clear();
	Edit2->Clear();
	Edit3->Clear();
	Edit4->Clear();
    Edit5->Clear();
}
//---------------------------------------------------------------------------

long long int power(long long int a, long long int b) {
    switch(b) {
    case 0: return 1;
    case 1: return a;
    default: return (a * power(a, b - 1));
    }
}

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	int x, n, repeat;

    Memo1->Lines->Add("-------------------------------");

	if(!TryStrToInt(Edit1->Text, x) || x < 0){
		Memo1->Lines->Add("請輸入大於等於 0 的整數至 \"X\" 欄位!!!");
		return;
	}
	if(!TryStrToInt(Edit2->Text, n) || n < 0){
		Memo1->Lines->Add("請輸入大於等於 0 的整數至 \"n\" 欄位!!!");
		return;
	}
	if(!TryStrToInt(Edit4->Text, repeat) || repeat <= 0){
		Memo1->Lines->Add("請輸入正整數至 \"循環次數\" 欄位!!!");
		return;
	}


	if (x == 0 && n == 0) {
		Memo1->Lines->Add("0 的 0 次方不存在!!!");
		return;
	}

	bool find = false;
	long long int sum = 0;
	clock_t st, sp;

	if (CheckBox1->Checked || CheckBox2->Checked || CheckBox3->Checked || CheckBox4->Checked) {
		Memo1->Lines->Add(IntToStr(x) + " 的 " + IntToStr(n) + " 次方:" + " / Repetition: " + IntToStr(repeat) + "次");
	}

	if (CheckBox1->Checked) {
		st = clock();
		int time = 1;
		while(time <= repeat){
			sum = 0;
			sum = power(x, n);
			time ++;
		}
		sp = clock();

		Memo1->Lines->Add("Result of pow(x, y) -> " + IntToStr(sum) + " CPU time (Sec.) = " + FloatToStr((float)(sp-st)/CLOCKS_PER_SEC) + "s.");

		find = true;
	}

	if (CheckBox2->Checked) {
		find = true;

		if (x == 0) {
			st = clock();
			sum = 0;
			st = clock();
		}

		if (n == 0){
			st = clock();
			sum = 1;
			sp = clock();
		}else {
			st = clock();
			sum = 1;
			int time = 1;
			while (time <= repeat) {
				sum = 1;
				for (int i = 1; i <= n; i++) {
					sum *= x;
				}
				time ++;
			}
			sp = clock();
		}

		Memo1->Lines->Add("Result of for-looping -> " + IntToStr(sum) + " CPU time (Sec.) = " + FloatToStr((float)(sp-st)/CLOCKS_PER_SEC) + "s.");

	}

	if (CheckBox3->Checked) {
		st = clock();
		sum = 1;
		int time = 1;
		while (time <= repeat) {
			sum = fastPower(x, n);
			time ++;
		}
		sp = clock();

		Memo1->Lines->Add("Result of Squaring -> " + IntToStr(sum) + " CPU time (Sec.) = " + FloatToStr((float)(sp-st)/CLOCKS_PER_SEC) + "s.");
		find = true;
	}

	if (CheckBox4->Checked) {
		st = clock();
		sum = 1;
		int time = 1;
		while (time <= repeat) {
			sum = fastPowerBit(x, n);
			time ++;
		}
		sp = clock();

		Memo1->Lines->Add("Result of Squaring_>> -> " + IntToStr(sum) + " CPU time (Sec.) = " + FloatToStr((float)(sp-st)/CLOCKS_PER_SEC) + "s.");
		find = true;
	}

	if (find == false) {
		Memo1->Lines->Add("請先點勾選至少一個 Options");
        return;
	}
}
//---------------------------------------------------------------------------

bool open_success = false;

void __fastcall TForm1::Button2Click(TObject *Sender)
{
    if (OpenDialog1->Execute()) {
		open_success = false;

		String fname = OpenDialog1->FileName;
		FILE *fp = _wfopen(fname.c_str(), L"r");
        if (!fp) {
			Memo2->Lines->Add("檔案無法開啟！");
			return;
		}

		// 清除舊的多項式
		ClearPoly(head);
		ClearPoly(reverseHead);

		// 讀新多項式
		head = ReadPolyFromFile(fp, 1);

		fclose(fp);

		if (!head) {
			Memo2->Lines->Add("多項式資料讀取失敗，請重新讀取！");
            return;
        }

        // 顯示多項式
        ShowPoly(Memo2, head);

		// 取得 x 值
		open_success = true;
	}

}


//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
	int x;
	if(!TryStrToInt(Edit3->Text, x) || x <= 0){
		Memo2->Lines->Add("請輸入正整數至 \"X\" 欄位!!!");
		return;
	}

	// 計算結果
	int repeat;
	if(!TryStrToInt(Edit5->Text, repeat) || repeat < 1){
		Memo2->Lines->Add("請輸入正整數至 \"循環次數\" 欄位!!!");
		return;
	}

	if (open_success == false) {
		Memo2->Lines->Add("未順利讀取係數檔案，請重新讀取!!!");
		return;
	}

    clock_t st, sp;

    if(CheckBox5->Checked == false && CheckBox6->Checked == false){
		Memo2->Lines->Add("請先點勾選至少一個 Options");
        return;
	}

	Memo2->Lines->Add("--------------------------------------");
	Memo2->Lines->Add("Repetition: " + IntToStr(repeat) + "次");

	if (CheckBox5->Checked) {

		int time = 1;
		Memo2->Lines->Add(" --> By Naive's method <--");
		st = clock();
		while (time <= repeat)
		{
			for (int i = 1; i <= x; i++) {
				int value = EvaluatePoly(head, i);
				if (time == repeat) {
					Memo2->Lines->Add("Result of f(" + IntToStr(i) + ") -> " + IntToStr(value));
				}

			}
			time++;
		}
		sp = clock();
		Memo2->Lines->Add("CPU time: " + FloatToStr((float)(sp-st)/CLOCKS_PER_SEC) + "s." );

	}

	if (CheckBox6->Checked) {
		if (CheckBox5->Checked) {
            Memo2->Lines->Add("");
		}

		int time = 1;
		Memo2->Lines->Add(" --> Horner's method <--");
		st = clock();
		while (time <= repeat)
		{
			for (int i = 1; i <= x; i++) {
				long long value = EvaluatePoly_Horner(reverseHead, i);
				if (time == repeat) {
					Memo2->Lines->Add("Result of f(" + IntToStr(i) + ") -> " + IntToStr(value));
				}

			}
			time++;
		}
		sp = clock();
		Memo2->Lines->Add("CPU time: " + FloatToStr((float)(sp-st)/CLOCKS_PER_SEC) + "s." );
	}

    Memo2->Lines->Add("");

}
//---------------------------------------------------------------------------

