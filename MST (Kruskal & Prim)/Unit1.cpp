//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

#define min(x, y) (x < y ? x : y)
#define max_size 10000000
#include <ctime>    // for time()
#include <algorithm>  // for qsort
#define MAX_EDGE 1000000000
#define INF 10000000
#define MAX_NODE 100000000

int largest;
int n, range, max_range, repeat;
int **mtx = nullptr;
bool generate = false;

struct Edge {
	int u, v, weight;
};

// Edge 比較函式，用於 qsort
int cmp(const void* a, const void* b) {
	return ((Edge*)a)->weight - ((Edge*)b)->weight;
}

int *parent = nullptr;

int find(int x) {
	if (parent[x] != x)
		parent[x] = find(parent[x]);
	return parent[x];
}

void unite(int a, int b) {
	parent[a] = b ;
}

int kruskal(int** mtx, int n, Edge mst[]) {
    const int maxEdges = n * (n - 1) / 2;
	Edge* edges = new Edge[maxEdges];
	int edgeCount = 0;

	// 產生邊的清單（上三角）

	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			if (mtx[i][j] < INF) {
				edges[edgeCount++] = {i, j, mtx[i][j]};
			}
		}
	}

	// 插入排序邊
	qsort(edges, edgeCount, sizeof(Edge), cmp);

	// 初始化 union-find
	parent = new int[n];
	for (int i = 0; i < n; ++i) parent[i] = i;

	int mstCount = 0, totalWeight = 0;
	for (int i = 0; i < edgeCount && mstCount < n - 1; ++i) {
		Edge& e = edges[i];
		if (find(e.u) != find(e.v)) {
			unite(e.u, e.v);
			mst[mstCount++] = e;
			totalWeight += e.weight;
		}
	}

	delete[] edges;
    delete[] parent ;
	return totalWeight;
}

// Prim 演算法
int prim(int** mtx, int n, Edge mst[]) {
	int *key = new int[n];      // 儲存到每個點的最小權重
	int *parent_local = new int[n];   // 儲存該點在 MST 中的父節點
	bool *inMST = new bool[n];   // 是否已加入 MST
	int totalWeight = 0;

	// 初始化
	for (int i = 0; i < n; i++) {
        key[i] = INF;
		parent_local[i] = -1;
		inMST[i] = false;
	}

	key[0] = 0;  // 從節點 0 開始

	for (int count = 0; count < n - 1; count++) {
		// 找出尚未加入 MST 中、key 值最小的節點 u
		int minKey = INF, u = -1;
		for (int v = 0; v < n; v++) {
			if (!inMST[v] && key[v] < minKey) {
				minKey = key[v];
				u = v;
			}
		}

		if (u == -1) {
			break;
		}
		inMST[u] = true;

		// 更新與 u 相鄰的節點的 key 值
		for (int v = 0; v < n; v++) {
			if (mtx[u][v] < key[v] && !inMST[v]) {
				key[v] = mtx[u][v];
				parent_local[v] = u;
			}
		}
	}

	// 建立最小生成樹邊集合
	int mstCount = 0;
	for (int i = 1; i < n; i++) {
		mst[mstCount++] = {parent_local[i], i, mtx[parent_local[i]][i]};
		totalWeight += mtx[parent_local[i]][i];
	}

	delete[] key;
	delete[] parent_local;
	delete[] inMST;

	return totalWeight;
}

int *heap = nullptr;
int heapSize = 0;

int pop(Edge* edges) {
	int last = heap[heapSize--];
	int i = 1, child, ans = heap[1];
	while (i * 2 <= heapSize) {
		child = i * 2;
		if (child < heapSize && edges[heap[child + 1]].weight < edges[heap[child]].weight)
			child++;
		if (edges[last].weight <= edges[heap[child]].weight)
			break;
		heap[i] = heap[child];
		i = child;
	}
	heap[i] = last;
	return ans ;
}

void heapifyDown(int i, Edge* edges) {
	int temp = heap[i];
	int child;
	while (i * 2 <= heapSize) {
		child = i * 2;
		if (child < heapSize && edges[heap[child + 1]].weight < edges[heap[child]].weight)
			child++;
		if (edges[temp].weight <= edges[heap[child]].weight)
			break;
		heap[i] = heap[child];
		i = child;
	}
	heap[i] = temp;
}

void buildHeap(Edge* edges) {
	for (int i = heapSize / 2; i >= 1; i--) {
		heapifyDown(i, edges);
	}
}

Edge* prepare_edges(int** mtx, int n, int& edgeCount) {
	edgeCount = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (mtx[i][j] < INF) {
				edgeCount++ ;
			}
		}
	}

	// 預留最大邊數空間
	Edge* edges = new Edge[edgeCount];
	edgeCount = 0 ;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (mtx[i][j] < INF) {
				edges[edgeCount++] = {i, j, mtx[i][j]};
			}
		}
	}
	return edges;
}

int kruskal_heap(Edge* edges, int edgeCount, int n, Edge mst[]) {
	heap = new int[edgeCount + 1]; // 1-based index
	heapSize = edgeCount;

	// 將 edges[] 複製到 heap[1..heapSize]
	for (int i = 0; i < edgeCount; i++) {
		heap[i + 1] = i;
	}

	buildHeap(edges); // O(n) 建堆

	// 初始化並查集
	parent = new int[n];
	for (int i = 0; i < n; i++) parent[i] = i;

	int mstCount = 0, totalWeight = 0;
	while (mstCount < n - 1 && heapSize > 0) {
		int e = pop(edges);
		int a = find(edges[e].u), b =  find(edges[e].v) ;
		if (a != b) {
			unite(a, b);
			mst[mstCount++] = edges[e];
			totalWeight += edges[e].weight;
		}
	}
	
	delete [] heap ;
	delete[] parent;
	delete[] edges ;
	return totalWeight;
}

void matrix(int n){

	mtx = new int *[n];
	for (int i = 0; i < n; i++) {
		mtx[i] = new int [n];
	}

	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {             // 上三角
			mtx[i][j] = rand() % range + 1;
			if (mtx[i][j] > max_range) {
				mtx[i][j] = largest;
			}
			mtx[j][i] = mtx[i][j];    // 對稱下三角
		}
		mtx[i][i] = largest;   // 對角
	}

}

void freeMatrix(int**& mtx, int size) {
	if (mtx) {
		for (int i = 0; i < size; i++) {
			delete[] mtx[i];
		}
		delete[] mtx;
		mtx = nullptr;
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
	Edit5->Clear();
	Memo1->Clear();
	Memo2->Clear();
	Memo3->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	int i, j, k;
	Memo3->Clear();
	Memo2->Clear();
	int prev_n = n;

	if (mtx != nullptr && prev_n > 0) {
		freeMatrix(mtx, prev_n);
	}

	if(!TryStrToInt(Edit1->Text, n) || n <= 0 ){
		ShowMessage("請輸入 正整數 至 n 值欄位!");
		Edit1->Clear();
		return;
	}

	if(!TryStrToInt(Edit2->Text, range) || range <= 0 ){
		ShowMessage("請輸入 正整數 至 Range(w(e)) 欄位!");
		Edit2->Clear();
		return;
	}

	if(!TryStrToInt(Edit3->Text, max_range) || max_range <= 0 ){
		ShowMessage("請輸入 正整數 至 Max Range 欄位!");
		Edit3->Clear();
		return;
	}

	if(!TryStrToInt(Edit4->Text, largest) || largest <= 0 ){
		ShowMessage("請輸入 正整數 至 w(e) 欄位!");
		Edit4->Clear();
		return;
	}

	if(!TryStrToInt(Edit5->Text, repeat) || repeat < 1 ){
		ShowMessage("請輸入 正整數 至 Repetition 欄位!");
		Edit5->Clear();
		return;
	}

	Button2->Enabled = false;

	matrix(n);

	if (CheckBox1->Checked) {
		PageControl1->ActivePageIndex = 1;
		
		Memo3->Font->Name = "Courier New";
		int width = IntToStr(largest).Length() + 1; // 欄寬：最大數字長度 + 1

		// 輸出欄標題（橫軸）
		String header = Format("%*s", ARRAYOFCONST((width, ""))); // 左上角空白
		for (int j = 0; j < n; j++) {
			header += Format("%*d", ARRAYOFCONST((width, j)));
		}
		Memo3->Lines->Add(header);

		// 輸出矩陣內容
		for (int i = 0; i < n; i++) {
			String line = Format("%*d", ARRAYOFCONST((width, i))); // 行標題（縱軸）
			for (int j = 0; j < n; j++) {
				line += Format("%*d", ARRAYOFCONST((width, mtx[i][j])));
			}
			Memo3->Lines->Add(line);
		}
	
		Memo2->Lines->Add("U\t->\tV\tCost");
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < 10; k++) {
				if (mtx[i][j] != largest)
					Memo2->Lines->Add(IntToStr(j) + "\t->\t" + IntToStr(k) + "\t" + IntToStr(mtx[j][k]));
			}
		}

	}else {
		PageControl1->ActivePageIndex = 2;
		Memo2->Lines->Add("初始 Graph G 已成功生成!");
	}

	Button2->Enabled = true;
	generate = true;
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
	Memo1->Clear();

	if (generate == false) {
		ShowMessage("請先按下 Generate Graph 的 Button，生成初始 Matrix");
		return;
	}

	clock_t st, sp;
	PageControl1->ActivePageIndex = 0;

	int ctt = 0;
	int n1 = n;

	do{
		Memo1->Lines->Add("Repetition = " + IntToStr(ctt+1));

		st = clock();
		// 執行 Kruskal
		Edge* mst = new Edge[n1] ;
		int totalWeight = kruskal(mtx, n1, mst);
		sp = clock();

		if (CheckBox2->Checked) {
			// 輸出結果
			Memo1->Lines->Add("Kruskal (Min) MST Total Weight = " + IntToStr(totalWeight) + " ; |V| = " + IntToStr(n1))	;

			Memo1->Lines->Add("Spanning Tree: ");
			for (int i = 0; i < n1 - 1; i++) {
				Memo1->Lines->Add(IntToStr(mst[i].u) + " - " + IntToStr(mst[i].v) + " : " + IntToStr(mst[i].weight));
			}

			Memo1->Lines->Add("Time (sec.) ->" + FloatToStr((float)(sp-st)/CLOCKS_PER_SEC));
			Memo1->Lines->Add("");
		}else{
			// 輸出結果
			Memo1->Lines->Add("Kruskal (Min) MST Total Weight = " + IntToStr(totalWeight))	;
			Memo1->Lines->Add("Time (sec.) ->" + FloatToStr((float)(sp-st)/CLOCKS_PER_SEC));
			Memo1->Lines->Add("");
		}

		if (mtx != nullptr) {
			for (int i = 0; i < n1; i++) {
				delete[] mtx[i];
			}
			delete[] mtx;
		}

		delete [] mst ;

		n1 += 1000;
		ctt += 1;

		matrix(n1);
	}
	while (ctt < repeat);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
	Memo1->Clear();

    if (generate == false) {
		ShowMessage("請先按下 Generate Graph 的 Button，生成初始 Matrix");
		return;
	}

	clock_t st, sp;

	PageControl1->ActivePageIndex = 0;
	int n1 = n;

	int ctt = 0;
	do {
		Memo1->Lines->Add("Repetition = " + IntToStr(ctt+1));

		st = clock();
		// 執行 Prim
		Edge *mst = new Edge[n1];
		int totalWeight = prim(mtx, n1, mst);
		sp = clock();

		if (CheckBox2->Checked) {
			Memo1->Lines->Add("Prim MST total weight = " + IntToStr(totalWeight) + " ; |V| = " + IntToStr(n1));
			if (CheckBox2->Checked) {
				Memo1->Lines->Add("Spanning Tree: ");
				for (int i = 0; i < n1 - 1; i++) {
					Memo1->Lines->Add(IntToStr(mst[i].u) + " - " + IntToStr(mst[i].v) + " : " + IntToStr(mst[i].weight));
				}
			}

			Memo1->Lines->Add("Time (sec.) ->" + FloatToStr((float)(sp-st)/CLOCKS_PER_SEC));
			Memo1->Lines->Add("");
		}else{
			Memo1->Lines->Add("Prim MST total weight = " + IntToStr(totalWeight));
			Memo1->Lines->Add("Time (sec.) ->" + FloatToStr((float)(sp-st)/CLOCKS_PER_SEC));
			Memo1->Lines->Add("");
		}

		if (mtx != nullptr) {
			for (int i = 0; i < n1; i++) {
				delete[] mtx[i];
			}
			delete[] mtx;
		}

		delete[] mst;

		n1 += 1000;
		ctt += 1;

		matrix(n1);
	} while (ctt < repeat);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
	Memo1->Clear();

    if (generate == false) {
		ShowMessage("請先按下 Generate Graph 的 Button，生成初始 Matrix");
		return;
	}

	clock_t st, sp;
	PageControl1->ActivePageIndex = 0;

	int ctt = 0;
	int n1 = n;
	int edgeCount;

	do{
		Memo1->Lines->Add("Repetition = " + IntToStr(ctt+1));
		Edge* edges = prepare_edges(mtx, n1, edgeCount);

		Edge *mst = new Edge[n1];
		// 執行 Kruskal

		st = clock();
		int totalWeight = kruskal_heap(edges, edgeCount, n1, mst);
		sp = clock();
		
		if (CheckBox2->Checked) {
			// 輸出結果
			Memo1->Lines->Add("Kruskal (Heap) MST Total Weight = " + IntToStr(totalWeight) + " ; |V| = " + IntToStr(n1))	;
			if (CheckBox2->Checked) {
				Memo1->Lines->Add("Spanning Tree: ");
				for (int i = 0; i < n1 - 1; i++) {
					Memo1->Lines->Add(IntToStr(mst[i].u) + " - " + IntToStr(mst[i].v) + " : " + IntToStr(mst[i].weight));
				}
			}

			Memo1->Lines->Add("Time (sec.) ->" + FloatToStr((float)(sp-st)/CLOCKS_PER_SEC));
			Memo1->Lines->Add("");
		}else{
			Memo1->Lines->Add("Kruskal (Heap) MST Total Weight = " + IntToStr(totalWeight))	;
			Memo1->Lines->Add("Time (sec.) ->" + FloatToStr((float)(sp-st)/CLOCKS_PER_SEC));
			Memo1->Lines->Add("");
		}

		if (mtx != nullptr) {
			for (int i = 0; i < n1; i++) {
				delete[] mtx[i];
			}
			delete[] mtx;
		}

		delete[] mst ;

		n1 += 1000;
		ctt += 1;

		matrix(n1);
	}while(ctt < repeat);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	if (generate == false) {
		ShowMessage("請先按下 Generate Graph 的 Button，生成初始 Matrix");
		return;
	}

	Button1->Enabled = false;

	PageControl1->ActivePageIndex = 3;
	clock_t st, sp;
	double *rep1 = new double[repeat];
	double *rep2 = new double[repeat];
	double *rep3 = new double[repeat];
	int *node = new int[repeat];

	int ct = 0;
	int n1 = n;

	while (ct < repeat){
		st = clock();
		Edge* mst = new Edge[n1] ;
		int totalWeight = kruskal(mtx, n1, mst);
		sp = clock();
		rep1[ct] = (float)(sp-st)/CLOCKS_PER_SEC;
		delete[] mst;

		int edgeCount;
		Edge* edges = prepare_edges(mtx, n1, edgeCount);
		mst = new Edge[n1];

		st = clock();
		kruskal_heap(edges, edgeCount, n1, mst);
		sp = clock();
		rep2[ct] = (float)(sp-st)/CLOCKS_PER_SEC;
		delete[] mst;

		st = clock();
		mst = new Edge[n1];
		prim(mtx, n1, mst);
		sp = clock();
		rep3[ct] = (float)(sp-st)/CLOCKS_PER_SEC;

		delete[] mst;

		if (mtx != nullptr) {
			for (int i = 0; i < n1; i++) {
				delete[] mtx[i];
			}
			delete[] mtx;
		}

		node[ct] = n1;
		n1 += 1000;
		ct += 1;
		matrix(n1);
	}

	// 清除圖表
	Chart1->RemoveAllSeries();
	Chart1->Title->Text->Clear();
	Chart1->Title->Text->Add("Minimum Spanning Tree Algorithms Performance");
	Chart1->BottomAxis->Title->Caption = "|V| (Number of Nodes)";
	Chart1->LeftAxis->Title->Caption = "CPU time (sec.)";

	// 設定演算法名稱與對應顏色
	AnsiString algorithmNames[] = {"Kruskal (Min)", "Kruskal (Heap)", "Prim"};
	TColor seriesColors[] = {clRed, clBlue, clGreen};

	// 將 rep1, rep2, rep3 整合成陣列指標方便處理
	double* repData[] = {rep1, rep2, rep3};

	for (int i = 0; i < 3; i++) {
		TBarSeries* series = new TBarSeries(this);
		series->Title = algorithmNames[i];
		series->Color = seriesColors[i];

		for (int j = 0; j < repeat; j++) {
			series->AddXY(node[j], repData[i][j]);  // 正確：X 是節點數，Y 是時間
		}

		Chart1->AddSeries(series);
	}

	// 顯示圖例
	Chart1->Legend->Visible = true;

    Button1->Enabled = true;

	delete[] rep1;
	delete[] rep2;
	delete[] rep3;
	delete[] node;
}
//---------------------------------------------------------------------------

