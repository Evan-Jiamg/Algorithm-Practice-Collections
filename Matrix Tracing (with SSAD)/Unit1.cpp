//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

#define min(x, y) (x < y ? x : y)
#define max_size 10000

int largest;
int n, range, max_range;
int **mtx;
int **pair;
bool **closure;
int **next = NULL;

bool generate = false;

bool *found;
int *pre, *dis;

void PrintPath(int target, TMemo *memo, int start) {
	int path[max_size];
	int pathLen = 0;
	int current = target;

	// 回溯路徑（從 target 回推到 start）
	while (current != start && pathLen < max_size) {
		path[pathLen++] = current;
		current = pre[current];
	}
	path[pathLen++] = start;  // 加入起點

	// 開始組合輸出字串
	String output = "The shortest distance from " + IntToStr(start) + " to " + IntToStr(target);
	if (dis[target] == largest) {
		memo->Lines->Add(output + " is unreachable.");
		return;
	}

	output += " is " + IntToStr(dis[target]) + " with path ";

	// 從反向的陣列印出正向路徑
	for (int i = pathLen - 1; i > 0; i--) {
		int u = path[i];
		int v = path[i - 1];
		output += IntToStr(u) + "--[" + IntToStr(mtx[u][v]) + "]-->";
	}
	output += IntToStr(path[0]);  // 最後一個節點
	memo->Lines->Add(output);
}

void Dijkstra(int start, TMemo *memo, TCheckBox *check) {
	found = new bool[n];
	pre = new int[n];
	dis = new int[n];

	// 初始化
	for (int i = 0; i < n; i++) {
		pre[i] = start;
		found[i] = false;
		dis[i] = mtx[start][i];
	}
	found[start] = true;
	dis[start] = 0;

	if (check->Checked) {
		memo->Lines->Add("==== Start Dijkstra from node " + IntToStr(start) + " ====");
	}

	// 主迴圈
	for (int step = 1; step < n; step++) {
		int node = -1, minDis = largest;

		// 找出目前最短距離且未處理的節點
		for (int j = 0; j < n; j++) {
			if (!found[j] && dis[j] < minDis) {
				node = j;
				minDis = dis[j];
			}
		}

		if (node == -1) {
			if (check->Checked) {
				memo->Lines->Add("No more reachable nodes. Ending early.");
			}
			break;
		}

		found[node] = true;

		if (check->Checked) {
			memo->Lines->Add("Step " + IntToStr(step) + ": Chose node " + IntToStr(node) +
							 " with current shortest distance = " + IntToStr(minDis));
		}

		for (int j = 0; j < n; j++) {
			if (!found[j] && mtx[node][j] != largest) {
				int newDis = dis[node] + mtx[node][j];
				if (newDis < dis[j]) {
					if (check->Checked) {
						memo->Lines->Add("  Update: dis[" + IntToStr(j) + "] = " +
							IntToStr(dis[j]) + " → " + IntToStr(newDis) +
							", via node " + IntToStr(node));
					}
					dis[j] = newDis;
					pre[j] = node;
				}
			}
		}

		if (check->Checked) {
			String disStr = "  Current Distance Matrix : ";
			for (int i = 0; i < n; i++) {
				disStr += (dis[i] >= largest ) ? "∞ " : IntToStr(dis[i]) + " ";
			}
			memo->Lines->Add(disStr);
		}
	}

	memo->Lines->Add("\n==== Final Result from node " + IntToStr(start) + " ====");
	for (int i = 0; i < n; i++) {
		if (i == start) continue;
		PrintPath(i, memo, start);
	}
	memo->Lines->Add("");

	delete[] found;
	delete[] pre;
	delete[] dis;
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
	Memo2->Clear();
	Memo3->Clear();
	Memo4->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	generate = false;

	PageControl1->ActivePageIndex = 0;
	int i, j, k;
	if (mtx != NULL) {
		for(i = 0; i < n; i++) delete mtx[i];
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

	mtx = new int *[n];
	for (i = 0; i < n; i++) {
		mtx[i] = new int [n];
	}

	for (i = 0; i < n; i++) {
		for (j = i+1; j < n; j++) {             // 上三角
			mtx[i][j] = rand() % range + 1;
			if (mtx[i][j] > max_range) {
				mtx[i][j] = largest;
			}
			mtx[j][i] = mtx[i][j];    // 對稱下三角
		}
		mtx[i][i] = largest;   // 對角
	}

	// 設定 StringGrid 大小
	StringGrid1->RowCount = n;
	StringGrid1->ColCount = n;

	// 將 mtx 的值顯示到 StringGrid
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			StringGrid1->Cells[j][i] = IntToStr(mtx[i][j]);
		}
	}

	generate = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
    if (CheckBox1->Checked) {
		PageControl1->ActivePage = TabSheet6;
	}else{
		PageControl1->ActivePage = TabSheet3;
	}

	int i, j, k;

	if (generate == false) {
		ShowMessage ("尚未生成或讀取 Graph!!!");
		return;
	}

	// 分配記憶體
	pair = new int*[n];
	next = new int*[n];
	for (i = 0; i < n; i++) {
		pair[i] = new int[n];
		next[i] = new int[n];
	}

	// 初始化 pair[] 與 next[]
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			pair[i][j] = mtx[i][j];

			if (mtx[i][j] >= largest || i == j)
				next[i][j] = -1;
			else
				next[i][j] = j;
		}
	}

	// 輸出開始提示
	if (CheckBox1->Checked) {
		Memo3->Lines->Add("=== Start Floyd-Warshall All-Pairs Shortest Path ===");
	}

	// Floyd-Warshall 主迴圈
	for (k = 0; k < n; k++) {
		if (CheckBox1->Checked) {
			Memo3->Lines->Add("\n--- Using intermediate node k = " + IntToStr(k) + " ---");
		}

		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				if (pair[i][k] < largest && pair[k][j] < largest) {
					int via_k = pair[i][k] + pair[k][j];
					if (via_k < pair[i][j]) {
						int before = pair[i][j];
						pair[i][j] = via_k;
						next[i][j] = next[i][k];

						if (CheckBox1->Checked) {
							Memo3->Lines->Add("Update: pair[" + IntToStr(i) + "][" + IntToStr(j) + "] = " +
								IntToStr(before) + " → " + IntToStr(via_k) +
								" (via " + IntToStr(k) + ")");
						}
					}
				}
			}
		}

		// 印出目前 pair[] 矩陣
		if (CheckBox1->Checked) {
			Memo3->Lines->Add("Current pair matrix:");
			for (i = 0; i < n; i++) {
				String row = "";
				for (j = 0; j < n; j++) {
					if (pair[i][j] >= largest)
						row += "∞\t";
					else
						row += IntToStr(pair[i][j]) + "\t";
				}
				Memo3->Lines->Add(row);
			}
		}
	}

	if (CheckBox1->Checked) {
		Memo3->Lines->Add("\n=== All Pairs Shortest Paths ===");

		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				if (i == j) continue;

				Memo3->Lines->Add("From " + IntToStr(i) + " to " + IntToStr(j) + ":");

				if (pair[i][j] >= largest || next[i][j] == -1) {
					Memo3->Lines->Add("  No path.");
				} else {
					// 回推路徑
					String path = "  Path: " + IntToStr(i);
					int u = i;
					while (u != j) {
						u = next[u][j];
						if (u == -1) break;
						path += " → " + IntToStr(u);
					}
					Memo3->Lines->Add(path);
					Memo3->Lines->Add("  Total Cost: " + IntToStr(pair[i][j]));
				}
			}
		}

		Memo3->Lines->Add("\n=== Done Floyd-Warshall ===");


	for (i = 0; i < n; i++) delete[] pair[i];
	delete[] pair;

	for (i = 0; i < n; i++) delete[] next[i];
	delete[] next;
	}

    // 設定 StringGrid 大小
	StringGrid2->RowCount = n;
	StringGrid2->ColCount = n;

	// 將 mtx 的值顯示到 StringGrid
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			StringGrid2->Cells[j][i] = IntToStr(pair[i][j]);
		}
	}

	generate = true;
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
	if (CheckBox1->Checked) {
        PageControl1->ActivePage = TabSheet7;
	}else{
		PageControl1->ActivePage = TabSheet4;
    }

    if (generate == false) {
		ShowMessage ("尚未生成或讀取 Graph!!!");
		return;
	}

    Memo4->Clear();
	int i, j, k;


	// 建立新的 closure 矩陣
	closure = new bool *[n];
	for (i = 0; i < n; i++) {
		closure[i] = new bool [n];
		for (j = 0; j < n; j++) {
			closure[i][j] = (mtx[i][j] != largest);  // 有邊即可達
		}
	}

	// 自己一定可達自己
	for (i = 0; i < n; i++) {
		closure[i][i] = true;
	}

	if (CheckBox1->Checked) {
		Memo4->Lines->Add("=== Start Transitive Closure with Floyd-Warshall ===");
	}

	// Floyd-Warshall 演算法計算傳遞閉包
	for (k = 0; k < n; k++) {
		if (CheckBox1->Checked) {
			Memo4->Lines->Add("\n-- Using intermediate node k = " + IntToStr(k) + " --");
		}

		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				bool before = closure[i][j];
				bool updated = closure[i][j] || (closure[i][k] && closure[k][j]);
				if (!before && updated) {
					closure[i][j] = true;

					if (CheckBox1->Checked) {
						Memo4->Lines->Add("closure[" + IntToStr(i) + "][" + IntToStr(j) + "] updated to true (via " +
										  IntToStr(k) + ")");
					}
				}
			}
		}

		// 每次中繼點更新完後印出目前矩陣
		if (CheckBox1->Checked) {
			Memo4->Lines->Add("Current closure matrix:");
			for (i = 0; i < n; i++) {
				String row = "";
				for (j = 0; j < n; j++) {
					row += (closure[i][j] ? "1\t" : "0\t");
				}
				Memo4->Lines->Add(row);
			}
		}
	}

	if (CheckBox1->Checked) {
		Memo4->Lines->Add("\n=== Done Transitive Closure ===");
	}

	// 顯示結果於 StringGrid3
	StringGrid3->RowCount = n;
	StringGrid3->ColCount = n;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			StringGrid3->Cells[j][i] = closure[i][j] ? "1" : "0";
		}
	}

	for(i = 0; i < n; i++) delete closure[i];
}

//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
	PageControl1->ActivePageIndex = 1;
	Memo2->Clear();

	int start;

	if (generate == false) {
		ShowMessage ("尚未生成或讀取 Graph!!!");
		return;
	}

	if (!TryStrToInt(Edit5->Text, start) || start < 0 || start >= n) {
		ShowMessage("起點編號 source no. 不合法，請重新輸入！");
		Edit5->Clear();
		return;
	}

	Dijkstra(start, Memo2, CheckBox1);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	PageControl1->ActivePageIndex = 0;
	int i, j, k;
	if (mtx != NULL) {
		for(i = 0; i < n; i++) delete mtx[i];
	}

	generate = false;

	FILE *fp;
	AnsiString fname;

	if (OpenDialog1->Execute()) {
		fname = OpenDialog1->FileName;
		fp = fopen(fname.c_str(), "r+");

		// 讀取方陣大小
		fscanf(fp, "%d %d", &n, &largest);

		mtx = new int *[n];
		for (int i = 0; i < n; i++) {
			mtx[i] = new int [n];
		}

        // 設定 StringGrid 大小
		StringGrid1->RowCount = n;
		StringGrid1->ColCount = n;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				fscanf(fp, "%d", &mtx[i][j]);  // 讀取數據

				// 將方陣內數據 讀入 StringGrid
				StringGrid1->Cells[j][i] = IntToStr(mtx[i][j]);
				StringGrid1->Cells[j][i] = IntToStr(mtx[i][j]);
			}
		}
		fclose(fp);

		generate = true;
	}

	if (generate == false) {
		ShowMessage ("檔案未成功讀取!!!");
        return;
	}
}
//---------------------------------------------------------------------------

