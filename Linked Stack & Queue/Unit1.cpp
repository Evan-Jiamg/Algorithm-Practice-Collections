//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

// 定義 Singly linked list 結構
struct node{
	int data;
	struct node *next;  // 指向下一個節點的指標
};

//定義 Singly linked list 的指標
struct node *first;
struct node *last;
struct node *top;
struct node *front;
struct node *rear;

// 創建新的 Singly linked list 節點
struct node *newNode(int element){
	struct node *p;
	p = (struct node *) malloc(sizeof(node));

	p->data = element;
	p->next = NULL;

	return p;
}

// 定義 Doubly linked list 結構
struct Dnode{
	struct Dnode *prev;
	int data;
	struct Dnode *next;
};

struct Dnode *head;  // 指向第一個節點

// 創建新的 Doubly linked list 節點
struct Dnode *newDnode(int element){
	struct Dnode *p;
	p = (struct Dnode *) malloc(sizeof(Dnode));

	p->data = element;
	p->prev = NULL;
	p->next = NULL;

	return p;
}

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	// 初始化 Singly linked list
	first = newNode(0);
	first->next = first;
	last = first;

	// 初始化 Doubly linked list
	head = newDnode(0);
	head->next = head->prev = head;

	// 創建 stack 頂端節點 = 0
	top = newNode(0);

	// 創建 queue 的前後端節 = 0
	front = rear = newNode(0);

	// 清除各個 Memo 中的內容
	Memo1->Clear();
	Memo2->Clear();
	Memo3->Clear();
	Memo4->Clear();

	// 清除各個 Edit 中的內容
	Edit1->Clear();
	Edit2->Clear();
	Edit3->Clear();
	Edit4->Clear();
	Edit5->Clear();
	Edit6->Clear();
	Edit7->Clear();
	Edit8->Clear();
	Edit9->Clear();
	Edit10->Clear();
	Edit11->Clear();
	Edit12->Clear();
	Edit13->Clear();
	Edit14->Clear();
}
//---------------------------------------------------------------------------

// 輸出 Singly linked list 的資料
void printData(TMemo* memo){
	node *p = first->next;
	String out = "Output List: ";

	// 遍歷整個 Singly linked list
	do {
		out += IntToStr(p->data) + " -> ";
		p = p->next;
	} while (p != first);

	out += "<-||";
	memo->Lines->Add(out);
}

// 輸出 Stack 的資料
void printStack(TMemo* memo) {
	node* p = top->next;
	String out = "Stack top: ";

	// 遍歷整個 Stack
	while (p != NULL) {
		out += IntToStr(p->data) + " -> ";
		p = p->next;
	}

	out += "<-||";
	memo->Lines->Add(out);
}


void printQ(TMemo* memo) {
	node* p = front->next;
	String out = "Queue: ";

	// 遍歷整個 Queue
	while (p != NULL) {
		out += IntToStr(p->data) + " -> ";
		p = p->next;
	}

	out += "<-||";
	memo->Lines->Add(out);
}

// 清空 Stack 資料
void clearStack(){
	// 如果 Stack 為空 (僅有空白節點，則無需執行 clearStack)
	if (top == NULL || top->next == NULL)
		return;

	node* p = top->next;
	node* q;

	// 遍歷 Stakc 的每個節點，釋放記憶體空間
	while (p != NULL) {
		q = p->next;
		free(p);
		p = q;
	}

	top->next = NULL;  // 保留空白節點
}

// 清空 Queue 資料
void clearQ(){
	// 如果 front 為空 (僅有空白節點，則無需執行 clearQ)
	if (front == NULL || front->next == NULL)
		return;

	node *p = front->next;
	node *q;

	// 遍歷 Stakc 的每個節點，釋放記憶體空間
	while (p != NULL) {
		q = p->next;
		free(p);
		p = q;
	}
	rear = front = newNode(0);        // rear 和 front 重新設定為空白節點
}

// 插入節點到 Singly linked list 的尾端
void insertLast(struct node *x){
	x->next = last->next;
	last->next = x;
	last = x;
}

// 插入節點到 Singly linked list 的開頭
void insertFirst(struct node *x){
	if (first->next == first) {
		insertLast(x);
		return;
	}

	x->next = first->next;
	first->next = x;
}

// 將資料推入 Stack
void Linkpush(int x){
	struct node *p = newNode(x);
	p->next = top->next;
	top->next = p;
}

// 將資料推出 Stack
int Linkpop(TMemo *memo){
	if (top->next == NULL) {
		memo->Lines->Add("Stack is empty!");
		return NULL;
	}
	node *p = top->next;
	int info = p->data;

	top->next = p->next;
	free(p);

	return info;
}

// 將資料插入 Queue
void insertQ(int x){
	struct node *p = newNode(x);
	rear->next = p;
	rear = p;
}

// 將資料從 Queue 移除
int delQ(TMemo *memo){
	if (front->next == NULL) {
		memo->Lines->Add("Queue is Empty!!!");
		return NULL;
	}

	struct node *p = front->next;
	int info = p->data;

	front->next = p->next;    // 將 front 指向下一個節點
	if (p == rear) {          // 若刪除的是尾節點，rear 回到空白節點
		rear = front;
	}

	free(p);
	return info;
}

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	int n;

	// 防呆機制
	if(!TryStrToInt(Edit1->Text, n)){
		Memo1->Lines->Add("請輸入整數至 \"元素\" 欄位!!!");
		return;
	}

	node *x = (struct node *) malloc(sizeof(node));  // 動態分配節點記憶體位址
	x->data = n;

	insertFirst(x);     // 新節點插入至 list 前端

	printData(Memo1);   // 顯示當前 Singly linked list 內容
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
	int n;

	// 防呆機制
	if(!TryStrToInt(Edit1->Text, n)){
		Memo1->Lines->Add("請輸入整數至 \"元素\" 欄位!!!");
		return;
	}

	node *x = (struct node *) malloc(sizeof(node));  // 動態分配節點記憶體位址
	x->data = n;

	insertLast(x);      // 新節點插入至 list 後端

	printData(Memo1);   // 顯示當前 Singly linked list 內容
}
//---------------------------------------------------------------------------
#define max_size 1000

// 生成隨機數值
void genRanData(int arr[], int n, int range){
	for(int i = 0; i < n; i++){
		arr[i] = rand() % range + 1;    // 產生 1 到 r 的隨機數值
	}
}

void __fastcall TForm1::Button3Click(TObject *Sender)
{
	int n, range;

	// 防呆機制
	if(!TryStrToInt(Edit2->Text, n) || n <= 0){
		Memo1->Lines->Add("請輸入正整數至 \"n\" 欄位!!!");
		return;
	}
	if(!TryStrToInt(Edit4->Text, range) || range <= 0){
		Memo1->Lines->Add("請輸入正整數至 \"range\" 欄位!!!");
		return;
	}

	// 初始化陣列
	int data[max_size] = {-1};
	genRanData(data, n, range);     // 乎叫生成隨機數值的函式

	// 將隨機數值插入至 list "前端"
	for(int i = 0; i < n; i++){
		node *x = (struct node *) malloc(sizeof(node));
		x->data = data[i];
		insertFirst(x);
	}
	printData(Memo1);     // 顯示更新後 Singly linked list 內容
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button8Click(TObject *Sender)
{
	int n, range;

	// 防呆機制
	if(!TryStrToInt(Edit2->Text, n) || n <= 0){
		Memo1->Lines->Add("請輸入正整數至 \"n\" 欄位!!!");
		return;
	}
	if(!TryStrToInt(Edit2->Text, range) || range <= 0){
		Memo1->Lines->Add("請輸入正整數至 \"range\" 欄位!!!");
		return;
	}

	// 初始化陣列
	int data[max_size] = {-1};
	genRanData(data, n, range);     // 乎叫生成隨機數值的函式

	// 將亂數依序插入至 list "後端"
	for(int i = 0; i < n; i++){
		node *x = (struct node *) malloc(sizeof(node));
		x->data = data[i];
		insertLast(x);
	}
	printData(Memo1);       // 顯示更新後 Singly linked list 內容
}
//---------------------------------------------------------------------------
void searchData(int t, TMemo* memo, TCheckBox* checkBox3, TCheckBox* checkBox2, TCheckBox* checkBox1, TEdit* edit1){
	node *p, *q;

	// 遍歷 list，以此搜尋目標節點
	for(q = first, p = first->next; (p->data != t) && (p != first); q = p, p = p->next);

	if (p == first) {       // 沒找到目標節點
		memo->Lines->Add("Target does not exist in List!!!");
		return;
	}else if (checkBox3->Checked || checkBox2->Checked){         // 找到目標節點
		memo->Lines->Add(IntToStr(p->data) + " -> Successfully found!!!");

		int n;

		// 防呆機制
		if(!TryStrToInt(edit1->Text, n)){
			memo->Lines->Add("請先輸入整數至 \"元素\" 欄位!!!");
			return;
		}

		// 在目標節點前插入新節點
		if(checkBox3->Checked){
			node *x = (struct node *) malloc(sizeof(node));
			x->data = n;

			x->next = p;
			q->next = x;
			memo->Lines->Add(IntToStr(x->data) + " -> Implemented!!!");
		}
		// 在目標節點後插入新節點
		else if (checkBox2->Checked) {
			node *x = (struct node *) malloc(sizeof(node));
			x->data = n;

			x->next = p->next;
			p->next = x;
			memo->Lines->Add(IntToStr(x->data) + " -> Implemented!!!");
		}
		printData(memo);   // 顯示更新後 Singly linked list 內容
	}
	// 刪除找到的目標節點
	else if (checkBox1->Checked) {
		q->next = p->next;
		free(p);
		memo->Lines->Add(IntToStr(t) + " -> Deleted!!!");
		printData(memo);
	}
	// 找到目標節點，但不做多餘操作
	else{
		memo->Lines->Add(IntToStr(p->data) + " -> Successfully found!!!");
	}
	return;
}

void __fastcall TForm1::Button5Click(TObject *Sender)
{
	int target;

	// 防呆機制
	if(!TryStrToInt(Edit3->Text, target)){
		Memo1->Lines->Add("請輸入整數至 \"Target\" 欄位!!!");
		return;
	}

	// 搜尋目標節點
	searchData(target, Memo1, CheckBox3, CheckBox2, CheckBox1, Edit1);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button10Click(TObject *Sender)
{
	printData(Memo1);
}
//---------------------------------------------------------------------------

// 清空 list 內節點資料，但保留空白節點
void clearData() {
	if (first == NULL || first->next == first)
		return;

	node *p, *q;

	// 遍歷整個 list
	for (p = first->next; p != first; ) {
		q = p->next;
		free(p);
		p = q;
	}
	first->next = first;
    last = first;
}

void __fastcall TForm1::Button9Click(TObject *Sender)
{
	clearData();
	Memo1->Clear();
	printData(Memo1);
}
//---------------------------------------------------------------------------

// 當勾選此 CheckBox 時，自動取消其他兩個 CheckBox 的勾選狀態
void __fastcall TForm1::CheckBox3Click(TObject *Sender)
{
	if (CheckBox3->Checked) {
		CheckBox1->Checked = false;
		CheckBox2->Checked = false;
	}
}
//---------------------------------------------------------------------------

// 當勾選此 CheckBox 時，自動取消其他兩個 CheckBox 的勾選狀態
void __fastcall TForm1::CheckBox2Click(TObject *Sender)
{
	if (CheckBox2->Checked) {
		CheckBox1->Checked = false;
		CheckBox3->Checked = false;
	}
}
//---------------------------------------------------------------------------

// 當勾選此 CheckBox 時，自動取消其他兩個 CheckBox 的勾選狀態
void __fastcall TForm1::CheckBox1Click(TObject *Sender)
{
    if (CheckBox1->Checked) {
		CheckBox2->Checked = false;
		CheckBox3->Checked = false;
	}
}
//---------------------------------------------------------------------------

// 反轉串列 (但不包含開頭空白節點)
void Invert() {
	if (first == NULL || first->next == first || first->next->next == first)
		return; // 空 or 一個資料節點，無需反轉

	node *prev = first;           // 初始化指向開頭空白節點
	node *curr = first->next;     // 第一個資料節點
	node *next = NULL;
	node *head = curr;            // 原本第一個節點，反轉後變最後一個節點

	// 反轉串列
	while (curr != first) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}

	first->next = prev; // 開頭空白節點指向新節點
	last = head;        // 更新 last 為原本的第一個資料節點
}

void __fastcall TForm1::Button11Click(TObject *Sender)
{
	Invert();
	printData(Memo1);
}
//---------------------------------------------------------------------------

// 輸出 Doubly linked list 的節點資料內容
void printDList(TMemo *memo){
	Dnode *p = head->next;
	String out = "Output List: ";

	// 遍歷整個串列
	do {
		out += IntToStr(p->data) + " -> ";
		p = p->next;    // 移動到下一個節點
	} while (p != head);

	out += "<-||";
	memo->Lines->Add(out);
}

// 在 Doubly linked list 中插入新節點
void insertDList(struct Dnode *x, struct Dnode *p){
	p->prev = x;
	p->next = x->next;
	x->next->prev = p;
	x->next = p;
}

void __fastcall TForm1::Button4Click(TObject *Sender)
{
	int n;

	// 防呆機制
	if(!TryStrToInt(Edit5->Text, n)){
		Memo2->Lines->Add("請輸入整數至 \"元素\" 欄位!!!");
		return;
	}

	// 創建新節點
	Dnode *x = (struct Dnode *) malloc(sizeof(Dnode));
	x->data = n;       // 設定節點內的資料內容

	insertDList(head, x);
	printDList(Memo2);
}
//---------------------------------------------------------------------------

// 搜尋 Doubly linked list 內的節點資料內容
struct Dnode *searchDList(int target, TMemo* memo){
	Dnode *p = head;

	// 遍歷整個 list，來尋找目標值
	while ((p->data != target) && (p->next != head))
		p = p->next;

	// 在 list 中找到目標值
	if (p->data == target) {
		memo->Lines->Add(IntToStr(p->data) + " -> Successfully found!!!");
		return p;
	}

	// 未找到目標值
	memo->Lines->Add(IntToStr(target) + " -> do NOT exist!!!");
	return head;
}

void __fastcall TForm1::Button6Click(TObject *Sender)
{
	int target;

	// 防呆機制
	if(!TryStrToInt(Edit6->Text, target)){
		Memo2->Lines->Add("請輸入整數至 \"Target\" 欄位!!!");
		return;
	}

	Dnode *k = (struct Dnode *) malloc(sizeof(Dnode));
	k = searchDList(target, Memo2);   // 搜尋目標節點，並回傳該節點資訊

	// 若成功找到 target 節點
	if (k != head) {
		if (RadioButton2->Checked) {   // 插入新節點至 target 之前
			int n;

			// 防呆機制
			if(!TryStrToInt(Edit5->Text, n)){
				Memo2->Lines->Add("請輸入整數至 \"元素\" 欄位!!!");
				return;
			}

			Dnode *x = (struct Dnode *) malloc(sizeof(Dnode));
			x->data = n;

			insertDList(k, x);
			printDList(Memo2);

		}else if (RadioButton1->Checked) {   // 找到 target 後，刪除該節點
			k->prev->next = k->next;
			k->next->prev = k->prev;
			free(k);

			printDList(Memo2);
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender)
{
	printDList(Memo2);
}
//---------------------------------------------------------------------------

// 清空 Doubly linked list，但保留開頭空白節點
void clearDList() {

	// 檢查串列是否為空 (僅存在開頭空白節點)
	if (head == NULL || head->next == head)
		return;

	Dnode *p = head->next;

	// 遍歷整個串列
	while (p != head) {
		Dnode *q = p;
		p = p->next;
		delete q;
	}

	// 重置開頭節點的前後指標
	head->next = head;
	head->prev = head;
}


void __fastcall TForm1::Button12Click(TObject *Sender)
{
	clearDList();
	Memo2->Clear();
	printDList(Memo2);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button13Click(TObject *Sender)
{
	int n, range;

	// 防呆機制
	if(!TryStrToInt(Edit7->Text, n) || n <= 0){
		Memo2->Lines->Add("請輸入正整數至 \"n\" 欄位!!!");
		return;
	}
	if(!TryStrToInt(Edit8->Text, range) || range <= 0){
		Memo2->Lines->Add("請輸入正整數至 \"Range\" 欄位!!!");
		return;
	}

	int data[max_size] = {-1};      // 初始化陣列
	genRanData(data, n, range);      // 呼叫產生隨機數值的函式

	// 將亂數依序插入 Doubly linked list
	for(int i = 0; i < n; i++){
		Dnode *x = (struct Dnode *) malloc(sizeof(Dnode));
		x->data = data[i];
		insertDList(head, x);
	}
	printDList(Memo2);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button14Click(TObject *Sender)
{
	int n;

	// 防呆機制
	if(!TryStrToInt(Edit9->Text, n)){
		Memo3->Lines->Add("請輸入整數至 \"元素\" 欄位!!!");
		return;
	}

	Linkpush(n);    // 呼叫推入 Stack 函式
	printStack(Memo3);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button15Click(TObject *Sender)
{
	int n, range;

	// 防呆機制
	if(!TryStrToInt(Edit11->Text, n) || n <= 0){
		Memo3->Lines->Add("請輸入正整數至 \"n\" 欄位!!!");
		return;
	}
	if(!TryStrToInt(Edit10->Text, range) || range <= 0){
		Memo3->Lines->Add("請輸入正整數至 \"Range\" 欄位!!!");
		return;
	}

	int data[max_size] = {-1};     // 初始化陣列
	genRanData(data, n, range);     // 呼叫產生隨機數值的函式

	// 將亂數依序推入 Stack
	for(int i = 0; i < n; i++){
		Linkpush(data[i]);
	}
	printStack(Memo3);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button17Click(TObject *Sender)
{
	Memo3->Clear();
	clearStack();
	printStack(Memo3);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button16Click(TObject *Sender)
{
	// 執行 pop 出 Stack 的操作，並將數值回傳給 target
	int target = Linkpop(Memo3);
	if (target != NULL) {
		Memo3->Lines->Add("Result -> " + IntToStr(target));    // 顯示 pop 出 Stack 的元素
	}

	printStack(Memo3);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button18Click(TObject *Sender)
{
	int n;

	// 防呆機制
	if(!TryStrToInt(Edit12->Text, n)){
		Memo4->Lines->Add("請輸入整數至 \"元素\" 欄位!!!");
		return;
	}

	insertQ(n);     // 呼叫插入 Queue 的函式
	printQ(Memo4);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button19Click(TObject *Sender)
{
    int n, range;

	// 防呆機制
	if(!TryStrToInt(Edit13->Text, n) || n <= 0){
		Memo4->Lines->Add("請輸入正整數至 \"n\" 欄位!!!");
		return;
	}
	if(!TryStrToInt(Edit14->Text, range) || range <= 0){
		Memo4->Lines->Add("請輸入正整數至 \"Range\" 欄位!!!");
		return;
	}

	int data[max_size] = {-1};     // 初始化陣列
	genRanData(data, n, range);     // 呼叫產生隨機數值的函式

	// 將亂數依序插入 Queue
	for(int i = 0; i < n; i++){
		insertQ(data[i]);
	}
	printQ(Memo4);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button20Click(TObject *Sender)
{
	// 執行推出 Queue 的操作，並將數值回傳給 target
	int target = delQ(Memo4);
	if (target != NULL) {
		Memo4->Lines->Add("Output -> " + IntToStr(target));     // 顯示推出 Queue 的元素
	}
	printQ(Memo4);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button21Click(TObject *Sender)
{
	Memo4->Clear();
	clearQ();
	printQ(Memo4);
}
//---------------------------------------------------------------------------
void InvertDList() {
	if (head == NULL || head->next == head || head->next->next == head)
		return; // 若僅剩空白節點或一個資料節點時，不需要反轉

	Dnode *p = head->next;
	Dnode *temp;

	// 遍歷並交換每個節點的 prev 和 next
	while (p != head) {
		temp = p->next;
		p->next = p->prev;
		p->prev = temp;
		p = temp;
	}

	// 最後交換 head 自己的 prev 與 next
	temp = head->next;
	head->next = head->prev;
	head->prev = temp;
}

void __fastcall TForm1::Button22Click(TObject *Sender)
{
	InvertDList();
	printDList(Memo2);
}
//---------------------------------------------------------------------------

