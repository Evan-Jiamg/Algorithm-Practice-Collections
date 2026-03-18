//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

#include <stdlib.h>  // for rand()
#include <time.h>    // for time()

// 隨機整數範圍 [min, max]
int RandInRange(int min, int max) {
	return rand() % (max - min + 1) + min;
}

struct PolyNode {
	int coef;
	int expo;
	struct PolyNode* next;
};

struct PolyNode *head_a, *head_b, *head_c;
struct PolyNode *last_a, *last_b, *last_c;

// 建立新節點
struct PolyNode* NewTerm(int coefficient, int exponent) {
    struct PolyNode* r = new struct PolyNode;
    r->coef = coefficient;
    r->expo = exponent;
    r->next = r; // circular node
    return r;
}

// 複製節點
struct PolyNode* CopyTerm(struct PolyNode* p) {
    struct PolyNode* q = new struct PolyNode;
    *q = *p;
    return q;
}

// 插入至尾端，並更新 last
void InsertLast(struct PolyNode* x, struct PolyNode*& last) {
    x->next = last->next;
    last->next = x;
    last = x;
}

// 初始化多項式 A 和 B 的頭節點與尾節點
void Initilization() {
    head_a = NewTerm(0, -1); last_a = head_a;
    head_b = NewTerm(0, -1); last_b = head_b;
}

// 多項式相加
struct PolyNode* PolyAdd(struct PolyNode* head_a, struct PolyNode* head_b) {
    struct PolyNode *p, *q, *r;
    int coef;
    struct PolyNode* head_c = NewTerm(0, -1);  // 假設這是虛擬頭節點
    struct PolyNode* last_c = head_c;

    p = head_a->next;
    q = head_b->next;

    while (p != head_a && q != head_b) {
        if (p->expo > q->expo) {
            r = CopyTerm(p);
            InsertLast(r, last_c);
            p = p->next;
        } else if (p->expo < q->expo) {
            r = CopyTerm(q);
            InsertLast(r, last_c);
            q = q->next;
        } else {
            coef = p->coef + q->coef;
            if (coef != 0) {
                r = CopyTerm(p);
                r->coef = coef;
                InsertLast(r, last_c);
            }
            p = p->next;
            q = q->next;
        }
    }

    while (p != head_a) {
        r = CopyTerm(p);
        InsertLast(r, last_c);
        p = p->next;
    }

    while (q != head_b) {
        r = CopyTerm(q);
        InsertLast(r, last_c);
        q = q->next;
    }

    return head_c;
}

void ShowPoly(PolyNode* head, TMemo* memo, AnsiString polyName) {
	polyName += "-> ";

	if (head == nullptr || head->next == head) {
		memo->Lines->Add(polyName + "None");
		return;
	}

	// 建立一個臨時排序串列（單向，非環狀）
	PolyNode* sortedHead = nullptr;

	// 複製非 0 節點，並插入到 sortedHead（由大到小插入）
	PolyNode* p = head->next;
	while (p != head) {
		if (p->coef != 0) {
			PolyNode* newNode = new PolyNode;
			newNode->coef = p->coef;
			newNode->expo = p->expo;
			newNode->next = nullptr;

			// 插入到 sortedHead 中，保持 exponent 由大到小
			if (!sortedHead || newNode->expo > sortedHead->expo) {
				newNode->next = sortedHead;
				sortedHead = newNode;
			} else {
				PolyNode* curr = sortedHead;
				while (curr->next && curr->next->expo >= newNode->expo)
					curr = curr->next;
				newNode->next = curr->next;
				curr->next = newNode;
			}
		}
		p = p->next;
	}

	// 若排序後仍是空的（全部為 0）
	if (!sortedHead) {
		polyName += "0";
		memo->Lines->Add(polyName);
		return;
	}

	// 輸出格式
	bool firstTerm = true;
	PolyNode* curr = sortedHead;
	while (curr) {
		int coef = curr->coef;
		int expo = curr->expo;
		int absCoef = abs(coef);

		// 加減號
		if (!firstTerm) {
			if (coef > 0)
				polyName += " + ";
			else
				polyName += " - ";
		} else {
			if (coef < 0)
				polyName += "-";
		}

		// 格式化係數與次方
		if (expo == 0) {
			polyName += IntToStr(absCoef);
		} else if (expo == 1) {
			if (absCoef == 1)
				polyName += "x";
			else
				polyName += IntToStr(absCoef) + "x";
		} else {
			if (absCoef == 1)
				polyName += "x^" + IntToStr(expo);
			else
				polyName += IntToStr(absCoef) + "x^" + IntToStr(expo);
		}

		firstTerm = false;
		curr = curr->next;
	}

	memo->Lines->Add(polyName);

	// 清理臨時排序串列的記憶體
	while (sortedHead) {
		PolyNode* tmp = sortedHead;
		sortedHead = sortedHead->next;
		delete tmp;
	}
}

// 初始化多項式並隨機加入項
void GenerateRandomPoly(int maxExp, int coeff) {
	// 初始化 A 與 B 頭節點
	if (!head_a) { head_a = NewTerm(0, -1); last_a = head_a; }
	if (!head_b) { head_b = NewTerm(0, -1); last_b = head_b; }

	// 以亂數產生項目
	for (int e = maxExp; e >= 0; --e) {
		// 50% 機率跳過該項（不產生）
		if (RandInRange(0, 1) == 0) continue;

		int coef_a = RandInRange(coeff * -1, coeff);
		if (coef_a != 0) {
			PolyNode* termA = NewTerm(coef_a, e);
			InsertLast(termA, last_a);
		}

		int coef_b = RandInRange(coeff * -1, coeff);
		if (coef_b != 0) {
			PolyNode* termB = NewTerm(coef_b, e);
			InsertLast(termB, last_b);
		}
	}
}

void InsertAndCombine(PolyNode* head, PolyNode*& last, int coef, int expo) {
    if (coef == 0) return; // 0 不插入

    PolyNode* p = head->next;
    PolyNode* prev = head;

    // 找是否有同樣的 exponent
    while (p != head) {
        if (p->expo == expo) {
            p->coef += coef;
            if (p->coef == 0) {
                // 若相加為 0，則刪除該節點
                prev->next = p->next;
                if (p == last) last = prev;
                delete p;
            }
            return;
        }
        prev = p;
        p = p->next;
    }

    // 沒有相同次方項，則插入尾端
    PolyNode* newNode = NewTerm(coef, expo);
    InsertLast(newNode, last);
}

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	Edit1->Clear();
	Edit2->Clear();
	Edit3->Clear();
	Edit4->Clear();
	Memo1->Clear();
	Memo2->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	PageControl1->ActivePageIndex = 0;

	int coef, expon;
	if(!TryStrToInt(Edit1->Text, coef)){
		PageControl1->ActivePageIndex = 0;
		Memo1->Lines->Add("請輸入整數至 \"Coefficient\" 欄位!!!");
		Memo1->Lines->Add("----------------------------");
		return;
	}
	if(!TryStrToInt(Edit2->Text, expon) || expon < 0){
		PageControl1->ActivePageIndex = 0;
		Memo1->Lines->Add("請輸入整數至 \"Exponent\" 欄位!!!");
		Memo1->Lines->Add("----------------------------");
		return;
	}

	AnsiString poly = "";

	bool check = false;
	if (CheckBox1->Checked){
		if (!head_a) {
			head_a = NewTerm(0, -1);
			last_a = head_a;
		}
		PolyNode* term = NewTerm(coef, expon);
		InsertAndCombine(head_a, last_a, coef, expon);

		check = true;
		PolyAdd(head_a, last_a);

        poly = "A";
		ShowPoly(head_a, Memo1, poly);
	}

	if (CheckBox2->Checked){
		if (!head_b) {
			head_b = NewTerm(0, -1);
			last_b = head_b;
		}
		PolyNode* term = NewTerm(coef, expon);
        InsertAndCombine(head_b, last_b, coef, expon);

		check = true;
		PolyAdd(head_b, last_b);

		poly = "B";
		ShowPoly(head_b, Memo1, poly);
	}

    Memo1->Lines->Add("----------------------------");

	if (check == false) {
        PageControl1->ActivePageIndex = 0;
		Memo1->Lines->Add("請選擇要加入 A 或 B 的多項式！");
		return;
	}

}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button3Click(TObject *Sender)
{
	PageControl1->ActivePageIndex = 0;
	srand(time(NULL));  // 初始化隨機種子（一次即可）

    int coef, expon;
	if(!TryStrToInt(Edit4->Text, coef) || coef <= 0){
		PageControl1->ActivePageIndex = 0;
		Memo1->Lines->Add("請輸入正整數至 \"Max range\" 欄位!!!");
		Memo1->Lines->Add("----------------------------");
		return;
	}
	if(!TryStrToInt(Edit3->Text, expon) || expon < 0){
		PageControl1->ActivePageIndex = 0;
		Memo1->Lines->Add("請輸入大於等於 0 的整數至 \"最大指數數值\" 欄位!!!");
		Memo1->Lines->Add("----------------------------");
		return;
	}


	head_a = head_b = last_a = last_b = nullptr; // 重設
	GenerateRandomPoly(expon, coef);  // 最大次方數為 10，係數範圍 -5 到 5

	ShowPoly(head_a, Memo1, "A");
	ShowPoly(head_b, Memo1, "B");
	Memo1->Lines->Add("----------------------------");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
    PageControl1->ActivePageIndex = 1;

	if (!head_a || head_a->next == head_a) {
		PageControl1->ActivePageIndex = 1;
		Memo2->Lines->Add("多項式 A 是空的，無法相加！");
		return;
	}
	if (!head_b || head_b->next == head_b) {
		PageControl1->ActivePageIndex = 1;
		Memo2->Lines->Add("多項式 B 是空的，無法相加！");
        return;
    }

    // 相加結果存在 head_c
    head_c = PolyAdd(head_a, head_b);

	Memo2->Lines->Add("====== 多項式相加結果 ======");
	ShowPoly(head_a, Memo2, "A");
	ShowPoly(head_b, Memo2, "B");

	Memo2->Lines->Add("A + B = C");
	ShowPoly(head_c, Memo2, "");
	Memo2->Lines->Add("========================");
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button5Click(TObject *Sender)
{
	Edit1->Clear();
	Edit2->Clear();
	Edit3->Clear();
    Edit4->Clear();
	Memo1->Clear();
	Memo2->Clear();
	CheckBox1->Checked = false;
	CheckBox2->Checked = false;

	head_a = NULL;
	head_b = NULL;
    head_c = NULL;
}
//---------------------------------------------------------------------------

