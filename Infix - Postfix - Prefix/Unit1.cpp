//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#define max_size 1000       // 定義 stack 最大容量
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	Memo1->Clear();		Memo2->Clear();		Memo3->Clear();
	Memo4->Clear();		Memo5->Clear();		Memo6->Clear();
	Memo7->Clear();		Memo8->Clear();		Memo9->Clear();
}
//---------------------------------------------------------------------------
String stack1[max_size];    // 優先處理 operators
String stack2[max_size];    // 儲存運算式中的 operands
int top1 = -1;
int top2 = -1;

String trace(int flag, TMemo* memo){
	String s1 = "Stack1 -> ";
	String s2 = "Stack2 -> ";

	if (flag == 1) {
		for (int i = 0; i <= top1; i++) {
			s1 += stack1[i] + " ";
		}
		memo->Lines->Add(s1);
	}else if (flag == 2) {
		for (int i = 0; i <= top2; i++) {
			s2 += stack2[i] + " ";
		}
		memo->Lines->Add(s2);
	}
	return "";
}


// push elemnet into the top of stack
void push(int flag, String e, TMemo* memo){
	if (top1 == max_size-1) {
		ShowMessage("Stack 1 is Full~");
		return;
	}else if (top2 == max_size-1) {
		ShowMessage("Stack 2 is Full~") ;
		return;
	}else if (flag == 1) {
		stack1[++top1] = e;
		trace(1, memo);  // 傳入對應的 memo
	}else if (flag == 2) {
		stack2[++top2] = e;
		trace(2, memo);  // 傳入對應的 memo;
	}
}

// pop element from the top of stack
String pop(int flag, TMemo* memo){
	String result = "";
	if (flag == 1 && top1 == -1) {
		ShowMessage("Stack 1 is Empty~");
		return "";
	}else if (flag == 2 && top2 == -1) {
		ShowMessage("Stack 2 is Empty~");
		return "";
	}else if (flag == 1) {
		result += stack1[top1--];
		trace(1, memo);
	}else if (flag == 2) {
		result += stack2[top2--];
		trace(2, memo);
	}
	return result;
}

// 清空兩個 stack
void clearStack() {
	top1 = -1;
	top2 = -1;
}

// 將輸入 String 內部字元逐一轉換成 String 陣列內的 element，並回傳陣列大小 index
int parsing(String s, String arr[]){
	int index = 0;
	for (int i = 1; i <= s.Length(); i++) {
		arr[index++] = s[i];
	}
	return index;
}

// 判斷是否為 operand
bool isOperand(String e){
	if (e == "+" || e == "-" || e == "*" || e == "/" ||
		e == "%" || e == "&&" || e == "||" ||
		e == "#" || e == "^" || e == "(" || e == ")"){
		return false;
	}
	return true;
}

// 將兩個 operand 和 operator 合併，並存入 stack2
void get_fix(int flag, String e, TMemo* memo){
	String a = pop(2, memo);
	String b = pop(2, memo);
	if (flag == 1) {
		a = e + b + a;
	}else if (flag == 2) {
		a = b + a + e;
	}
	push(2, a, memo);
}

// 建立 operator 在 push 入 stack1 "之前"，operator 的優先權
int p(String e){
	if (e == "+" || e == "-") return 6;
	else if (e == "*" || e == "/" || e == "%") return 7;
	else if (e == "(") return 10;
	else if (e == "&&") return 2;
	else if (e == "||") return 1;
	else if (e == "#") return -1;
	else if (e == "^") return 9;
}

// 建立 operator 在 push 入 stack1 "之後"，operator 的優先權
int q(String e){
	if (e == "(") return 0;
	else if (e == "^") return 8;
	else if (e == "*" || e == "/" || e == "%") return 7;
	else if (e == "+" || e == "-") return 6;
	else if (e == "&&") return 2;
	else if (e == "||") return 1;
	else if (e == "#") return -1;
}

// infix -> postfix
String in_to_post(String s, int flag, TMemo* memo){
	clearStack();

	String token[max_size];
	int n = parsing(s, token);

	push(1, "#", memo);

	for (int i = 0; i < n; i++) {
		String e = token[i];

		if (isOperand(token[i])) {
			push(2, e, memo);                 	// operand 直接存入 stack2
		}else if (e == ")") {
			String x;
			while ((x = pop(1, memo)) != "(" ) {    // 括號內的運算符號處理
				get_fix(flag, x, memo);
			}
		}else{
			while (stack1[top1] != "#" && p(e) <= q(stack1[top1])){      // 比較優先權
				String x = pop(1, memo);
				get_fix(flag, x, memo);
			}
			push(1, e, memo);                     // operator 存入 stack1
		}
	}

	// 處理 stack1 最後剩餘的 operator
	while (stack1[top1] != "#"){
		String x = pop(1, memo);
		get_fix(flag, x, memo);
	}

	pop(1, memo);         						// 移除 stack1 底部 operator "#"
	return pop(2, memo);                          // return result
}

// 反轉括號及順序 (作為 prefix 轉換使用)
String reverse(String s){
	String rev = "";
	for (int i = s.Length(); i >= 1; i--) {
		if (s[i] == '(')
			rev += ")";
		else if (s[i] == ')')
			rev += "(";
		else
			rev += s[i];
	}
	return rev;
}

// infix -> prefix
String in_to_pre(String s, int flag, TMemo* memo){
	clearStack();

	String reversed = reverse(s);   // reverse first
	memo->Lines->Add("I try to reverse the prefix into : " + reversed);

	String result = in_to_post(reversed, 2, memo);   // we want post fix here

	String ans = reverse(result) ;
	memo->Lines->Add("I reverse it back to the final answer: " + ans) ;

	return ans ;
}

// postfix -> prefix
String post_to_pre(String e, TMemo* memo){
	clearStack();
	int n = e.Length();

	for (int i = 0; i < n; i++) {
		String s = e[i+1];   // String index from 1
		if (isOperand(s)) {
			push(2, s, memo);
		}else{
			get_fix(1, s, memo);        // flag 1 代表 prefix
		}
	}
	return pop(2, memo);
}

// postfix -> infix
String post_to_in(String e, TMemo* memo){
	clearStack();
	int n = e.Length();

	String s, s1, s2, x, y;
	for (int i = 1; i <= n; i++) {
		String s = e[i];
		if (isOperand(s)) {
			push(2, s, memo);
			push(1, "#", memo);
		}else{
			s1 = pop(1, memo);
			s2 = pop(1, memo);
			x = pop(2, memo);
			y = pop(2, memo);

			// 判斷是否需要加括號
			if (s1 != "#" && p(s) > q(s1)) x = "(" + x + ")";
			if (s2 != "#" && p(s) > q(s2)) y = "(" + y + ")";

			push(2, y + s + x, memo);
			push(1, s, memo);
		}
	}

	while (top1 != -1) x = pop(1, memo);    // 清空 stack1
	return pop(2, memo);
}

// prefix -> postfix
String pre_to_post(String e, TMemo* memo){
	clearStack();

	int n = e.Length();
	push(1, "#", memo);

	for (int i = n; i >= 1; i--) {
		String s = e[i];
		if (isOperand(s)) {
			push(1, s, memo);
		} else {
			String left = pop(1, memo);
			String right = pop(1, memo);
			String expr = left + right + s;

			push(1, expr, memo);
		}
	}

	return pop(1, memo);
}

// prefix -> infix
String pre_to_in(String e, TMemo* memo) {
	clearStack();
	int n = e.Length();
	String s, s1, s2, x, y;

	for (int i = n; i >= 1; i--) {
		String s = e[i];
		if (isOperand(s)) {
			push(2, s, memo);
			push(1, "#", memo);
		}else{

			s1 = pop(1, memo);
			s2 = pop(1, memo);
			x = pop(2, memo);
			y = pop(2, memo);

			// 判斷是否需要加括號
			if (s1 != "#" && p(s) > q(s1)) x = "(" + x + ")";
			if (s2 != "#" && p(s) > q(s2)) y = "(" + y + ")";

			push(2, x + s + y, memo);
			push(1, s, memo);
		}
	}

	while (top1 != -1) x = pop(1, memo);    // 清空 stack1
	return pop(2, memo);
}


// infix -> postfix
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	Memo6->Clear();
	String infix = Edit4->Text;

	Form1->Memo1->Lines->Add("Tracing: Infix -> Postfix");
	String postfix = in_to_post(infix, 2, Memo1);
    Form1->Memo1->Lines->Add("---------------------");
	Form1->Memo1->Lines->Add("");

	Form1->Memo6->Lines->Add(postfix);
}
//---------------------------------------------------------------------------

// infix -> prefix
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	Memo7->Clear();
	String infix = Edit4->Text;

	Form1->Memo1->Lines->Add("Tracing: Infix -> Prefix");
	String prefix = in_to_pre(infix, 1, Memo1);
	Form1->Memo1->Lines->Add("---------------------");
	Form1->Memo1->Lines->Add("");

	Form1->Memo7->Lines->Add(prefix);
}
//---------------------------------------------------------------------------

// postfix -> infix
void __fastcall TForm1::Button3Click(TObject *Sender)
{
	Memo4->Clear();
	String postfix = Edit5->Text;

	Form1->Memo2->Lines->Add("Tracing: Postfix -> Infix");
	String infix = post_to_in(postfix, Memo2);
	Form1->Memo2->Lines->Add("---------------------");
	Form1->Memo2->Lines->Add("");

	Form1->Memo4->Lines->Add(infix);
}
//---------------------------------------------------------------------------

// postfix -> prefix
void __fastcall TForm1::Button4Click(TObject *Sender)
{
	Memo5->Clear();
	String postfix = Edit5->Text;

	Form1->Memo2->Lines->Add("Tracing: Postfix -> Prefix");
	String prefix = post_to_pre(postfix, Memo2);
	Form1->Memo2->Lines->Add("---------------------");
	Form1->Memo2->Lines->Add("");

	Form1->Memo5->Lines->Add(prefix);
}
//---------------------------------------------------------------------------

// prefix -> infix
void __fastcall TForm1::Button5Click(TObject *Sender)
{
	Memo8->Clear();
	String prefix = Edit7->Text;

	Form1->Memo3->Lines->Add("Tracing: Prefix -> Infix");
	String infix = pre_to_in(prefix, Memo3);
	Form1->Memo3->Lines->Add("---------------------");
	Form1->Memo3->Lines->Add("");

	Form1->Memo8->Lines->Add(infix);
}
//---------------------------------------------------------------------------

// prefix -> postfix
void __fastcall TForm1::Button6Click(TObject *Sender)
{
	Memo9->Clear();
	String prefix = Edit7->Text;

	Form1->Memo3->Lines->Add("Tracing: Prefix -> Postfix");
	String postfix = pre_to_post(prefix, Memo3);
	Form1->Memo3->Lines->Add("---------------------");
	Form1->Memo3->Lines->Add("");

	Form1->Memo9->Lines->Add(postfix);
}
//---------------------------------------------------------------------------

// 清除 "prefix" 分頁的所有內容
void __fastcall TForm1::Button7Click(TObject *Sender)
{
	Memo8->Clear();
	Memo9->Clear();
	Memo3->Clear();
	Edit7->Clear();
}
//---------------------------------------------------------------------------

// 清除 "postfix" 分頁的所有內容
void __fastcall TForm1::Button8Click(TObject *Sender)
{
	Memo4->Clear();
	Memo5->Clear();
	Memo2->Clear();
	Edit5->Clear();
}
//---------------------------------------------------------------------------

// 清除 "infix" 分頁的所有內容
void __fastcall TForm1::Button9Click(TObject *Sender)
{
	Memo6->Clear();
	Memo7->Clear();
	Memo1->Clear();
	Edit4->Clear();
}
//---------------------------------------------------------------------------

