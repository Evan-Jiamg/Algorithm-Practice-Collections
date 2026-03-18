//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

struct BSTreeNode{
	struct BSTreeNode *leftchild;
	int data;
	struct BSTreeNode *rightchild;
};

struct BSTreeNode *root = NULL;

struct BSTreeNode *newBSTNode(int x){                    // 建立新的 BSTreeNode 節點
	struct BSTreeNode * node = new struct BSTreeNode;

	node->data = x;
	node->leftchild = NULL;
	node->rightchild = NULL;

	return node;
}

struct BSTreeNode *recur_searchBST(struct BSTreeNode *tree, int x){     // 遞迴二元搜尋
	if (tree == NULL) {
		return NULL;
	}

	if (x == tree->data) {
		return tree;
	}

	if (x < tree->data) {
		return recur_searchBST(tree->leftchild, x);
	}

	return recur_searchBST(tree->rightchild, x);
}

struct BSTreeNode *iter_searchBST(struct BSTreeNode *node, int x){	 // 非遞迴二元搜尋
	while (node != NULL){
		if (x == node->data) {
			return node;
		}

		if (x < node->data) {
			node = node->leftchild;
		}else{
			node = node->rightchild;
		}
	}
	return NULL;
}

struct BSTreeNode *recur_insertBSTree(struct BSTreeNode *node, int x, bool &s){     // 遞迴新增資料
	if (node == NULL) {
		return newBSTNode(x);
	}

	if (x < node->data) {
		node->leftchild = recur_insertBSTree(node->leftchild, x,s );
	}else if (x > node->data){
		node->rightchild = recur_insertBSTree(node->rightchild, x, s);
	}
	else {
        s = false ;
    }
	return node;

	if (x == node->data) {
		return NULL;
	}
}

bool iter_insertBSTree(struct BSTreeNode *node, int x){      // 非遞迴新增資料
	struct BSTreeNode *p, *q;
	p = root;
	q = NULL;
	while (p != NULL){
		q = p;
		if (x == p->data) {
			return 0;
		}

		if (x < p->data) {
			p = p->leftchild;
		}else{
			p = p->rightchild;
		}
	}

	p = newBSTNode(x);
	if (root == NULL) {
		root = p;
	}else if (x < q->data) {
		q->leftchild = p;
	}else{
		q->rightchild = p;
	}

	return 1;
}

struct BSTreeNode *InorderSucc(struct BSTreeNode *node){      // 找出中序直接後繼元素
	struct BSTreeNode *p = node;
	for (p = node->rightchild; p->leftchild != NULL; p = p->leftchild);
	return p;
}

struct BSTreeNode *recur_delBSTree(struct BSTreeNode *node, int x, bool &success){      // 遞迴刪除
	struct BSTreeNode *temp;
	if (node == NULL) {
		return node;
	}
	if (x < node->data) {
		node->leftchild = recur_delBSTree(node->leftchild, x, success);
	}else if (x > node->data) {
		node->rightchild = recur_delBSTree(node->rightchild, x, success);
	}else{
        success = true;
		if ((node->leftchild == NULL) || (node->rightchild == NULL)) {
			temp = node->leftchild ? node->leftchild : node->rightchild;
			if (temp == NULL) {
				temp =  node;
				node = NULL;
			}else{
				*node = *temp;
			}

			free(temp);
		}else{
			temp = InorderSucc(node);
			node->data = temp->data;
			node->rightchild = recur_delBSTree(node->rightchild, temp->data, success);
		}
	}
	return node;
}

bool iter_delBSTree(int x){                // 非遞迴刪除
	struct BSTreeNode *p, *father, *k, *f;
	p = root;
	father = NULL;
	while (p != NULL){
		if (x == p->data) {
			if ((p->leftchild == NULL) && (p->rightchild == NULL)) {
				k = NULL;
			}else if (p->leftchild != NULL) {
				f = p;
				k = p->leftchild;
				while (k->rightchild != NULL){
					f = k;
					k = k->rightchild;
				}
				if (p == f) {
					f->leftchild = k->leftchild;
				}else{
					f->rightchild = k->leftchild;
				}
			}else{
				f = p;
				k = p->rightchild;
				while (k->leftchild != NULL){
					f = k;
					k = k->leftchild;
				}
				if (p == f) {
					f->rightchild = k->rightchild;
				}else{
					f->leftchild = k->rightchild;
				}
			}

			if (k != NULL) {
				k->leftchild = p->leftchild;
				k->rightchild = p->rightchild;
			}

			if (father == NULL) {
				root = k;
			}else if (x < father->data) {
				father->leftchild = k;
			}else{
				father->rightchild = k;
			}

			free(p);
			return 1;

		}else{
			father = p;
			if (x < p->data) {
				p = p->leftchild;
			}else{
				p = p->rightchild;
			}
		}
	}
	return 0;
}

AnsiString recur_inorder(struct BSTreeNode *node) {            // 遞迴中序走訪
	if (node == NULL) return "";

	AnsiString left = recur_inorder(node->leftchild);
	AnsiString middle = IntToStr(node->data) + "_";
	AnsiString right = recur_inorder(node->rightchild);

	return left + middle + right;
}

AnsiString recur_preorder(struct BSTreeNode *node) {            // 遞迴前序走訪
	if (node == NULL) return "";

	AnsiString middle = IntToStr(node->data) + "_";
	AnsiString left = recur_preorder(node->leftchild);
	AnsiString right = recur_preorder(node->rightchild);

	return middle + left + right;
}

AnsiString recur_postorder(struct BSTreeNode *node) {            // 遞迴後序走訪
	if (node == NULL) return "";

	AnsiString left = recur_postorder(node->leftchild);
	AnsiString right = recur_postorder(node->rightchild);
	AnsiString middle = IntToStr(node->data) + "_";

	return left + right + middle;
}

struct stackNode{                           // 二元樹走訪 (堆疊 + 迴圈)
	struct BSTreeNode *treeNode;
	struct stackNode *next;
};

struct stackNode *top;

void push_node(struct BSTreeNode *node){
	struct stackNode *old_top = top;
	top = (struct stackNode *) malloc(sizeof(struct stackNode));
	top->treeNode = node;
	top->next = old_top;
}

struct BSTreeNode *pop_node(){
	struct BSTreeNode *Tnode;
	struct stackNode *old_top;
	if (top == NULL) {
		ShowMessage("Stack is empty.");
        return NULL;
	}else{
		Tnode = top->treeNode;
		old_top = top;
		top = top->next;
		free(old_top);
		return Tnode;
	}
}

void inorder_stack(struct BSTreeNode *node, TMemo* memo){      // 非遞迴中序走訪
	AnsiString s = "";
	do{
		while (node != NULL){
			push_node(node);
			node = node->leftchild;
		}
		if (top != NULL) {
			node = pop_node();
			s += IntToStr(node->data) + "_";
			node = node->rightchild;
		}
	} while ((top != NULL) || (node != NULL));
	memo->Lines->Add("Inorder (Non-Recursively) -> " + s);
}

void preorder_stack(struct BSTreeNode *node, TMemo* memo){      // 非遞迴前序走訪
	AnsiString s = "";
	do{
		while (node != NULL){
			s += IntToStr(node->data) + "_";
			push_node(node);
			node = node->leftchild;
		}
		if (top != NULL) {
			node = pop_node();
			node = node->rightchild;
		}
	} while ((top != NULL) || (node != NULL));
	memo->Lines->Add("Preorder (Non-Recursively) -> " + s);
}

void postorder_stack(struct BSTreeNode *node, TMemo* memo){       // 非遞迴後序走訪
	AnsiString s = "";
	do{
		while (node != NULL){
			s += IntToStr(node->data) + "_";
			push_node(node);
			node = node->rightchild;
		}
		if (top != NULL) {
			node = pop_node();
			node = node->leftchild;
		}
	} while ((top != NULL) || (node != NULL));
	memo->Lines->Add("Postorder (Non-Recursively) -> " + s);
}

struct QNode{                                                 	// LevelOrder 走訪
	struct BSTreeNode *treeNode;
	struct QNode *next;
};

struct QNode *front, *rear;

void AddQueue(struct BSTreeNode *TNode){
	struct QNode *node;
	node = (struct QNode *)malloc(sizeof(struct QNode));
	node->treeNode = TNode;
	node->next = NULL;
	if (front == NULL) {
		front = node;
	} else{
		rear->next = node;
	}
	rear = node;
}

struct BSTreeNode *delQueue(){
	struct BSTreeNode *TNode;
	struct QNode *old_front;
	if (rear == NULL) {
		ShowMessage("Queue is Empty!");
	} else{
		TNode = front->treeNode;
		old_front = front;
		front = front->next;
		free(old_front);
	}
	return TNode;
}

void levelOrder(struct BSTreeNode *node, TMemo *memo){
	AnsiString s = "";
	if (node != NULL) {
		AddQueue(node);
		while (front != NULL){
			node = delQueue();
			s += IntToStr(node->data)  + "_";
			if (node->leftchild != NULL) {
				AddQueue(node->leftchild);
			}
			if (node->rightchild != NULL) {
				AddQueue(node->rightchild);
			}
		}
	}
	memo->Lines->Add("Level-Order Traversal -> " + s);
}

void Random_Insert_Inorder(int minVal, int maxVal, int count, TMemo *memo) {
	AnsiString originalSequence = "";

	for (int i = 0; i < count; ++i) {
		int x = Random(maxVal - minVal + 1) + minVal;

		// 累加原始數列字串
		originalSequence += IntToStr(x) + "_";

		// 插入 BST
		bool success = false ;
		root = recur_insertBSTree(root, x, success);
	}

	// 顯示插入順序
	memo->Lines->Add("Random Sequence -> " + originalSequence);

	// 顯示排序後結果
	AnsiString sortedSequence = "";
	sortedSequence += recur_inorder(root);
	memo->Lines->Add("Inorder (Recursively) -> " + sortedSequence);
	memo->Lines->Add("----------------------------");
}

void Clear_BST(struct BSTreeNode* BSTnode){
	if (BSTnode != NULL){
		Clear_BST(BSTnode->leftchild);
		Clear_BST(BSTnode->rightchild);
		delete(BSTnode);
	}
}

// 畫畫用的東東

struct DrawTreeNode{
	struct DrawTreeNode* leftchild;

	int data;
	int index;
	// int x;
	// int y;
	struct DrawTreeNode* rightchild;

};

struct BSTreeCNode *Croot;
struct DrawTreeNode* DrawRoot;

int* X;
int* Y;

String tree;

int count_node;
int** treenode;

void Clear_DBST(struct DrawTreeNode* DBSTnode){
	if (DBSTnode != NULL){
		Clear_DBST(DBSTnode->leftchild);
		Clear_DBST(DBSTnode->rightchild);
		delete(DBSTnode);
	}
}

int tempcount;

int Depth_BTree(struct BSTreeNode* node, int level)

{   int depth, l_depth, r_depth;

	if (node!=NULL){
	   l_depth = Depth_BTree(node->leftchild, (level+1));
	   r_depth = Depth_BTree(node->rightchild, (level+1));
	   depth = l_depth>r_depth? l_depth : r_depth;
	   return depth;
	}
	else return (level-1);
}

void determine_X(struct DrawTreeNode* node, int left, int right){
	if (node != NULL){
		int m = (left+right)/2;
		X[node->index] = (m == 0) ? left : m;
		determine_X(node->leftchild, left, (m-1<left)?left:m-1);
		determine_X(node->rightchild, (m+1<right)?m+1:right, right);
	}
}

void determine_Y(struct DrawTreeNode* node, int top, int bottom, int depth){
	int detH = (top+bottom)/(depth+1);
	for (int i = 0; i < depth + 1; i++) {
		Y[i] = (detH < 10) ? 10*i : detH*i;
	}
}

struct DrawTreeNode* CopyBSTtoDT(struct BSTreeNode* TreeRoot, int index, int depth){
	if (TreeRoot==NULL){
		return NULL;
	}

	struct DrawTreeNode* copyRoot = (struct DrawTreeNode*)malloc(sizeof(DrawTreeNode));
	copyRoot->data = TreeRoot->data;
	copyRoot->index = index;

	copyRoot->leftchild = CopyBSTtoDT(TreeRoot->leftchild, 2*index, depth);
    copyRoot->rightchild = CopyBSTtoDT(TreeRoot->rightchild, 2*index+1, depth);

	return copyRoot;
}

void Draw_BST(struct DrawTreeNode* DrawRoot, int node_radius){
	if (DrawRoot!=NULL){
		int level = ceil(log(DrawRoot->index+1)/log(2.0));
		if (DrawRoot->leftchild!=NULL){
			Form1->Image1->Canvas->MoveTo(X[DrawRoot->index], Y[level]);
			Form1->Image1->Canvas->LineTo(X[DrawRoot->leftchild->index], Y[level+1]);
		}

		if (DrawRoot->rightchild){
			Form1->Image1->Canvas->MoveTo(X[DrawRoot->index], Y[level]);

			Form1->Image1->Canvas->LineTo(X[DrawRoot->rightchild->index], Y[level+1]);
		}

		Form1->Image1->Canvas->Ellipse(X[DrawRoot->index]- node_radius,
		   Y[level] - node_radius,
		   X[DrawRoot->index]+ node_radius,
           Y[level] + node_radius);

	   Form1->Image1->Canvas->TextOut(X[DrawRoot->index]-5, Y[level]-7, IntToStr(DrawRoot->data));  // TextOutA 蝦 ?
	   Draw_BST(DrawRoot->leftchild, node_radius);
	   Draw_BST(DrawRoot->rightchild, node_radius);
	}
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

//	count_node = 0;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	PageControl1->ActivePageIndex = 0;
	int x;
	if(!TryStrToInt(Edit1->Text, x)){
		PageControl1->ActivePageIndex = 0;
		Memo1->Lines->Add("請輸入整數至 \"Element\" 欄位!!!");
		Memo1->Lines->Add("----------------------------");
		return;
	}

	// 插入元素

	if (RadioButton3->Checked) {
		// 將新元素插入到 BST 中
		bool success = true;
		root = recur_insertBSTree(root, x, success);
		if (success == false) {
			Memo1->Lines->Add("串列中已有" + IntToStr(x) + "數值，無法插入!");
			Memo1->Lines->Add("----------------------------");
			return;
		}
	}else if (RadioButton4->Checked) {
		// 將新元素插入到 BST 中
		bool success = false;
		success = iter_insertBSTree(root, x);
		if (success == 0) {
			Memo1->Lines->Add("串列中已有" + IntToStr(x) + "數值，無法插入!");
			Memo1->Lines->Add("----------------------------");
			return;
		}
	}else{
		Memo1->Lines->Add("請先選擇插入方式~");
		Memo1->Lines->Add("----------------------------");
		return;
    }

	AnsiString s = "";
	s += recur_inorder(root);
	Memo1->Lines->Add("Inorder (Recursively) ->" + s);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
	PageControl1->ActivePageIndex = 0;
	int x;
	if(!TryStrToInt(Edit1->Text, x)){
		PageControl1->ActivePageIndex = 0;
		Memo1->Lines->Add("請輸入整數至 \"Element\" 欄位!!!");
		Memo1->Lines->Add("----------------------------");
		return;
	}

	// 刪除元素

	if (RadioButton3->Checked) {
		bool success = false;
		root = recur_delBSTree(root, x, success);
		if (success == false) {
			Memo1->Lines->Add("串列中並未有 " + IntToStr(x) + " 數值，無法刪除!");
			Memo1->Lines->Add("----------------------------");
			return;
		}
	}else if (RadioButton4->Checked) {
		bool success = false;
		success = iter_delBSTree(x);
		if (success == 0) {
			Memo1->Lines->Add("串列中並未有 " + IntToStr(x) + " 數值，無法刪除!");
			Memo1->Lines->Add("----------------------------");
			return;
		}
	} else{
	   Memo1->Lines->Add("請先選擇刪除方式~");
	   Memo1->Lines->Add("----------------------------");
	   return;
    }

	AnsiString s = "";
	s += recur_inorder(root);
	Memo1->Lines->Add("----------------------------");
	Memo1->Lines->Add("刪除 " + IntToStr(x) + " 後的串列:");
	Memo1->Lines->Add("Inorder (Recursively) ->" + s);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
	PageControl1->ActivePageIndex = 0;
	int x;
	if(!TryStrToInt(Edit1->Text, x)){
		PageControl1->ActivePageIndex = 0;
		Memo1->Lines->Add("請輸入整數至 \"Element\" 欄位!!!");
		Memo1->Lines->Add("----------------------------");
		return;
	}

	// 搜尋元素
	BSTreeNode *target = NULL;

	if (RadioButton3->Checked) {
		target = recur_searchBST(root, x);
	}else if (RadioButton4->Checked) {
		target = iter_searchBST(root, x);
	}else {
		Memo1->Lines->Add("請先選擇搜尋方式~");
		Memo1->Lines->Add("----------------------------");
		return;
	}

	if (target == NULL) {
		PageControl1->ActivePageIndex = 0;
		Memo1->Lines->Add("元素 : " + IntToStr(x) + " 不存在!");
		Memo1->Lines->Add("----------------------------");
		return;
	}else{
		Memo1->Lines->Add(IntToStr(x) + " -> Found it!");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender)
{
	if (root == NULL) {
		PageControl1->ActivePageIndex = 0;
		Memo1->Lines->Add("目前二元樹為空，請先插入元素~");
		Memo1->Lines->Add("----------------------------");
		return;
	}
	PageControl1->ActivePageIndex = 0;
	AnsiString out = "";

	if (RadioButton1->Checked) {
		out += recur_preorder(root);
		Memo1->Lines->Add("Preorder (Recursively) -> " + out);
	}else if (RadioButton2->Checked) {
		preorder_stack(root, Memo1);
	}else{
		PageControl1->ActivePageIndex = 0;
        Memo1->Lines->Add("請先選擇 Traversal 方式~");
		Memo1->Lines->Add("----------------------------");
		return;
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
	if (root == NULL) {
		PageControl1->ActivePageIndex = 0;
		Memo1->Lines->Add("目前二元樹為空，請先插入元素~");
		Memo1->Lines->Add("----------------------------");
		return;
	}
	PageControl1->ActivePageIndex = 0;
	AnsiString out = "";

	if (RadioButton1->Checked) {
		out += recur_inorder(root);
		Memo1->Lines->Add("Inorder (Recursively) -> " + out);
	}else if (RadioButton2->Checked) {
		inorder_stack(root, Memo1);
	}else{
		PageControl1->ActivePageIndex = 0;
        Memo1->Lines->Add("請先選擇 Traversal 方式~");
		Memo1->Lines->Add("----------------------------");
		return;
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button8Click(TObject *Sender)
{
	if (root == NULL) {
        PageControl1->ActivePageIndex = 0;
		Memo1->Lines->Add("目前二元樹為空，請先插入元素~");
		Memo1->Lines->Add("----------------------------");
		return;
	}
	PageControl1->ActivePageIndex = 0;
	AnsiString out = "";

	if (RadioButton1->Checked) {
		out += recur_postorder(root);
		Memo1->Lines->Add("Postorder (Recursively) -> " + out);
	}else if (RadioButton2->Checked) {
		postorder_stack(root, Memo1);
	}else{
        PageControl1->ActivePageIndex = 0;
		Memo1->Lines->Add("請先選擇 Traversal 方式~");
		Memo1->Lines->Add("----------------------------");
		return;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
	if (root == NULL) {
		PageControl1->ActivePageIndex = 0;
		Memo1->Lines->Add("目前二元樹為空，請先插入元素~");
        Memo1->Lines->Add("----------------------------");
		return;
	}
	PageControl1->ActivePageIndex = 0;

	levelOrder(root, Memo1);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
	int min, max, n;
	PageControl1->ActivePageIndex = 0;
	if(!TryStrToInt(Edit2->Text, n) || n <= 0){
		PageControl1->ActivePageIndex = 0;
		Memo1->Lines->Add("請輸入正整數至 \"輸入元素數量\" 欄位!!!");
		Memo1->Lines->Add("----------------------------");
		return;
	}

	if(!TryStrToInt(Edit3->Text, max)){
		PageControl1->ActivePageIndex = 0;
		Memo1->Lines->Add("請輸入整數至 \"最大值\" 欄位!!!");
		Memo1->Lines->Add("----------------------------");
		return;
	}

	if(!TryStrToInt(Edit4->Text, min)){
		PageControl1->ActivePageIndex = 0;
		Memo1->Lines->Add("請輸入整數至 \"最小值\" 欄位!!!");
		Memo1->Lines->Add("----------------------------");
		return;
	}

	if (max < min) {
		PageControl1->ActivePageIndex = 0;
		Memo1->Lines->Add("注意: \"最大值必須大於等於最小值\" !!!");
		Memo1->Lines->Add("----------------------------");
		return;
	}

	Random_Insert_Inorder(min, max, n, Memo1);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button11Click(TObject *Sender)
{
	Edit1->Clear();
	Edit2->Clear();
	Edit3->Clear();
	Edit4->Clear();

	RadioButton1->Checked = false;
	RadioButton2->Checked = false;
	RadioButton3->Checked = false;
	RadioButton4->Checked = false;

	Memo1->Clear();

	Clear_BST(root);
    root = NULL ;
	Clear_DBST(DrawRoot);

	Image1->Picture->Assign(NULL);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button10Click(TObject *Sender) {
	 Image1->Picture->Assign(NULL);
	 Image1->Canvas->Pen->Color = TColor(RGB(0, 0, 255));

	 tempcount=0;
	 int depth = Depth_BTree(root, 1);

     PageControl1->ActivePageIndex = 1;
	 Memo1->Lines->Add("----------------------------");
	 Memo1->Lines->Add("~~已生成樹狀圖~~");
	 Memo1->Lines->Add("Tree's Depth:"+IntToStr(depth));


	 //Tree Height & Width

	 int tree_Height = ScrollBox1->Height;
	 int tree_Width = ScrollBox1->Width;

	 int total_node = pow(2, depth)-1;
	 int detW = tree_Width/(total_node+1);

	 int detH = tree_Height/(depth+1);

	 //Node Size

	 int node_radius = (detW*5/6 > detH/2) ? detH/2 : detW*5/6;

	 Image1->Top = 0;
	 Image1->Left = 0;

	 Image1->Height = tree_Height;
	 Image1->Width = tree_Width;

	 DrawRoot = CopyBSTtoDT(root, 1, depth);

	 X = new int [total_node+2];
	 Y = new int [depth+1];

	 determine_X(DrawRoot, 0+node_radius, tree_Width-node_radius);
	 determine_Y(DrawRoot, 0, tree_Height, depth);

	 Draw_BST(DrawRoot, node_radius);

	 delete(X);
	 delete(Y);
}

//---------------------------------------------------------------------------

