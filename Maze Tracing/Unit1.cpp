//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#define possible_direction 8

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	Memo1->Clear();
	Memo2->Clear();
}
//---------------------------------------------------------------------------
int maze [100][100];
int mark [100][100];
int generate_time = 0;

int enter_x, enter_y, exit_x, exit_y;
int m, n, gridSize;
bool generate_maze = false;

int top = -1;
struct position *stack;

void push(position);
position pop();

enum directions {N, NE, E, SE, S, SW, W, NW};

// 定義迷宮中的位置，每個位置包含 x、y 坐標和方向
struct position{
	int x, y;
	directions dir;
};

// 將位置推入堆疊
void push(position element){
	if (top == m*n-1) {
		ShowMessage("Stack is FULL! /  top = " + IntToStr(top));
	}
	stack[++top] = element;
}

// 將堆疊頂部的元素彈出
position pop(){
	if (top == -1) {
		ShowMessage("Stack is EMPTY! ");
	}
	return stack[top--];
}

struct offset{   // 移動方向
	int dx, dy;
};

// 定義 8 個可能移動的方向
offset move[possible_direction] ={{-1, 0}, {-1, 1},{0, 1}, {1, 1},
									{1, 0}, {1, -1}, {0, -1}, {-1, -1}};
offset f1[4] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
offset f2[4] = {{0, -2}, {0, 2}, {-2, 0}, {2, 0}};

void __fastcall TForm1::Button4Click(TObject *Sender)
{
	generate_maze = false;
	FILE *fp;
	AnsiString out, fname;
	int i, j;

	if (OpenDialog1->Execute()) {
		fname = OpenDialog1->FileName;
		fp = fopen(fname.c_str(), "r+");

		// 讀取迷宮大小
		fscanf(fp, "%d %d", &m, &n);

		// 讀取入口和出口座標
		fscanf(fp, "%d %d", &enter_x, &enter_y);
		fscanf(fp, "%d %d", &exit_x, &exit_y);

		// 設定 StringGrid 的大小
		StringGrid1->RowCount = m;
		StringGrid1->ColCount = n;
		StringGrid2->RowCount = m;
		StringGrid2->ColCount = n;

		// 印出迷宮資訊
		Memo1->Lines->Add(String().StringOfChar('=', 3 * m + 3));
		Memo1->Lines->Add("讀取的迷宮 Information: ");
		Memo1->Lines->Add("Maze: Height->" + IntToStr(m) + " / Width->" + IntToStr(n));
		Memo1->Lines->Add(String().StringOfChar('-', 3 * m + 3));

		for (i = 0; i < m; i++) {
			out = "";
			for (j = 0; j < n; j++) {
				fscanf(fp, "%d", &maze[i][j]);  // 讀取數據

				// **確保索引合法**
				StringGrid1->Cells[j][i] = IntToStr(maze[i][j]);
				StringGrid2->Cells[j][i] = IntToStr(maze[i][j]);

				out += "  " + IntToStr(maze[i][j]);
			}
			Memo1->Lines->Add(out);
		}
		fclose(fp);

		generate_maze = true;

		// 設定格子大小       -> StringGrid out of range??
		int gridSize = 50;
		StringGrid1->GridLineWidth = 1;  // 設定格線寬度
		StringGrid1->DefaultDrawing = false;  // 關閉預設繪製方式 (改由 `OnDrawCell` 處理)

		StringGrid2->GridLineWidth = 1;  // 設定格線寬度
		StringGrid2->DefaultDrawing = false;  // 關閉預設繪製方式 (改由 `OnDrawCell` 處理)

		// **修正行列設定**
		for (int i = 0; i < n; i++){ // 欄數應該是 `n`
			StringGrid1->ColWidths[i] = gridSize;
			StringGrid2->ColWidths[i] = gridSize;
		}
		for (int i = 0; i < m; i++){ // 列數應該是 `m`
			StringGrid1->RowHeights[i] = gridSize;
			StringGrid2->RowHeights[i] = gridSize;
		}

		// 強制重新繪製
		StringGrid1->Repaint();
		StringGrid2->Repaint() ;
	}
}

//---------------------------------------------------------------------------


//---------------------------------------------------------------------------


void __fastcall TForm1::Button5Click(TObject *Sender)
{
	// 檢查是否已產生迷宮
	if (generate_maze == false) {
		PageControl1->ActivePage = TabSheet1;
		Form1->Memo1->Lines->Add("尚未產生迷宮，請先 隨機生成 / 外部載入 迷宮!!!");
		Form1->Memo2->Lines->Add("尚未產生迷宮，請先 隨機生成 / 外部載入 迷宮!!!");
		return;
	}

	// 禁用操作按鈕
	Button1->Enabled = false;
	Button4->Enabled = false;
	Button5->Enabled = false;
	Button8->Enabled = false;
	CheckBox1->Enabled = false;

	// 初始化堆疊，大小為 m*n
	stack = new struct position[m * n];
	top = -1 ;
	struct position step;
	directions d;

	// 重置 mark 陣列
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			mark[i][j] = 0;
		}
	}

	// 設定起點座標 (1,1)，方向設為東 (E)
	step.x = step.y = 1;
	mark[step.x][step.y] = 1 ;  // 起點: 走過
	step.dir = N;
	push(step);

	int former_x = 1, former_y = 0 ;  // 記住之前的位置

	if (CheckBox1->Checked) {
		PageControl1->ActivePage = TabSheet4;
		StringGrid2->Cells[0][1] = "3";
		DoubleBuffered = true;
		Sleep(50 + (5 - TrackBar1->Position));
	}

	// 顯示標題
	Form1->Memo2->Lines->Add(String().StringOfChar('=', 3 * m + 3));

	// 當堆疊不為空時，執行 DFS 搜索
	while (top != -1) {
		step = pop(); // 取出堆疊頂端元素

		// animation
		if (CheckBox1->Checked) {
			StringGrid2->Cells[former_y][former_x] = "4" ;
			StringGrid2->Cells[step.y][step.x] = "3" ;
			former_x = step.x, former_y = step.y  ;

			StringGrid2->Refresh();
			Application->ProcessMessages();
			Sleep(50 + (5 - TrackBar1->Position) * 5);
		}


		// 紀錄 pop 出來的座標與方向
		Form1->Memo2->Lines->Add("Pop 出: (" + IntToStr(step.x) + ", " + IntToStr(step.y) + ") -> 方向: " + IntToStr(step.dir));

		int i = step.x;
		int j = step.y;
		d = step.dir;

		// 嘗試所有方向 (N, NE, E, SE, S, SW, W, NW)
		while (d <= NW) {
			int u = i + move[d].dx;
			int v = j + move[d].dy;

			Form1->Memo2->Lines->Add("嘗試移動到: (" + IntToStr(i) + ", " + IntToStr(j) + ") -> 方向: " + IntToStr(d));

			// 如果該位置可通行 (maze[u][v] == 0) 且尚未走過 (mark[u][v] == 0)
			if ((!maze[u][v]) && (!mark[u][v])) {

				mark[u][v] = 1; // 標記該點已訪問
				step.x = i;
				step.y = j;
				step.dir = directions(d + 1); // 轉向下一個方向
				push(step); // 儲存當前節點

				if (CheckBox1->Checked) {

					StringGrid2->Cells[former_y][former_x] = "2" ;
					StringGrid2->Cells[v][u] = "3" ;
					former_x = u, former_y = v ;
					StringGrid2->Cells[0][1] = "2";

					StringGrid2->Refresh();
					Application->ProcessMessages();
					Sleep(50 + (5 - TrackBar1->Position) * 5);

				}

				Form1->Memo2->Lines->Add("Push 進 stack: (" + IntToStr(step.x) + ", " + IntToStr(step.y) + ") -> 方向: " + IntToStr(step.dir));

				// 成功抵達終點
				if ((u == exit_x) && (v == exit_y)) {

					// 顯示路徑中的所有點
					for(i = top; i >= 0; i--){
						Form1->Memo2->Lines->Add("Pop 出: (" + IntToStr(stack[i].x) + ", " + IntToStr(stack[i].y) + ") -> 方向: " + IntToStr(stack[i].dir));
						if (CheckBox1->Checked)	StringGrid2->Cells[stack[i].y][stack[i].x] = "2" ;
					}

					Form1->Memo2->Lines->Add(String().StringOfChar('-', 3 * m + 3));
					Form1->Memo2->Lines->Add("Maze: Height->" + IntToStr(m) + " / Width->" + IntToStr(n));
					Form1->Memo2->Lines->Add("~ Final 座標 pop 輸出結果 ~");

					String record;
					record += ("起點: (1, 0) ->");


					// 記錄整個路徑，並將路徑標記為 2
					for (int i = 0; i <= top; i++) {
						maze[stack[i].x][stack[i].y] = 2;
						StringGrid1->Cells[stack[i].y][stack[i].x] = "2";
						record += (IntToStr(i + 1) + ". (" + IntToStr(stack[i].x) + ", " + IntToStr(stack[i].y) + ") ->");
					}
					record += ("終點: (" + IntToStr(exit_x) + ", " + IntToStr(exit_y) + ")");
					Form1->Memo2->Lines->Add(record);

					// 標記起點終點
					StringGrid1->Cells[0][1] = "2";
					StringGrid1->Cells[n-1][m-2] = "2";
					delete[] stack; 						// 釋放堆疊記憶體

					// 設定起點與終點為 2
					maze[enter_x][enter_y] = 2;
					maze[exit_x][exit_y] = 2;

					// 顯示迷宮資訊
					Form1->Memo1->Lines->Add(String().StringOfChar('=', 3 * m + 3));
					Form1->Memo1->Lines->Add("自動巡路的迷宮路徑 Information: ");
					Form1->Memo1->Lines->Add("Maze: Height->" + IntToStr(m) + " / Width->" + IntToStr(n));
					Form1->Memo1->Lines->Add(String().StringOfChar('-', 3 * m + 3));


					// 輸出迷宮路徑
					maze[1][0] = 2;
					maze[0][0] = 1;
					for (int i = 0; i < m; i++) {
						String s;
						for (int j = 0; j < n; j++) {
							s += "  ";
							s += IntToStr(maze[i][j]);
						}
						Form1->Memo1->Lines->Add(s);
					}
					generate_maze = false;

					// 恢復按鈕狀態
					Button1->Enabled = true;
					Button4->Enabled = true;
					Button5->Enabled = true;
					Button8->Enabled = true;
					CheckBox1->Enabled = true;

					return;
				}

				// 更新當前座標並設定下一步為北 (N)
				i = u;
				j = v;
				d = N;
			}
			else
				d = directions(d + 1); // 如果無法前進，嘗試下一個方向
		}
	}

	delete[] stack; // 如果搜尋失敗，釋放記憶體

	// 恢復按鈕狀態
	Button1->Enabled = true;
	Button4->Enabled = true;
	Button5->Enabled = true;
	Button8->Enabled = true;
	CheckBox1->Enabled = true;

	generate_maze = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button8Click(TObject *Sender)
{
	// 清空 Memo1 和 Memo2 的內容
	Memo1->Clear();
	Memo2->Clear();

	// 清空 StringGrid1 內的所有 StringGrid
	int rows = StringGrid1->RowCount;
	int cols = StringGrid1->ColCount;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			StringGrid1->Cells[j][i] = "";
		}
	}

	// 清空 StringGrid2 內的所有 StringGrid
	rows = StringGrid2->RowCount;
	cols = StringGrid2->ColCount;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			StringGrid2->Cells[j][i] = "";
		}
	}

    // 設置 generate_maze 為 false，表示迷宮尚未生成
	generate_maze = false;
}
//---------------------------------------------------------------------------
int nextMove(int, int);

// 自動生成迷宮
void __fastcall TForm1::Button2Click(TObject *Sender) {
	// 讀取使用者輸入的迷宮大小並加上外圍牆壁 (+2)

	// 防呆機制 -> 檢查輸入的 m 值、 n 值和 gridSize 值皆為正整數且大於等於 5 且為奇數
	if(!TryStrToInt(Edit1->Text, m) || m % 2 == 0 || m < 5 ){
			PageControl1->ActivePage = TabSheet1;
			Form1->Memo1->Lines->Add("請輸入正整數到 Height(高度) 且數值必須為奇數且大於等於 5!");
			Form1->Memo2->Lines->Add("請輸入正整數到 Height(高度) 且數值必須為奇數且大於等於 5!");
			return;
	}

	if(!TryStrToInt(Edit2->Text, n) || n % 2 == 0 || n < 5){
			PageControl1->ActivePage = TabSheet1;
			Form1->Memo1->Lines->Add("請輸入正整數到 Width(寬度) 且數值必須為奇數且大於等於 5!");
			Form1->Memo2->Lines->Add("請輸入正整數到 Width(寬度) 且數值必須為奇數且大於等於 5!");
			return;
	}

	if(!TryStrToInt(Edit3->Text, gridSize) || gridSize <=  0){
			PageControl1->ActivePage = TabSheet1;
			Form1->Memo1->Lines->Add("請輸入正整數到 Grid 且數值必須為整數! (注意: 輸入數值過小，可能無法顯示)");
            Form1->Memo2->Lines->Add("請輸入正整數到 Grid 且數值必須為整數! (注意: 輸入數值過小，可能無法顯示)");
			return;
	}

	// 建立堆疊，用於深度優先搜尋 (DFS)
	stack = new struct position[m * n];
	struct position step;
	struct position next;

	// 設定 StringGrid 的行數與列數
	StringGrid1->RowCount = m;
	StringGrid1->ColCount = n;

	StringGrid2->RowCount = m;
	StringGrid2->ColCount = n;

	// 初始化迷宮：所有格子預設為牆壁 (1)
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			maze[i][j] = 1;
			StringGrid1->Cells[j][i] = "1";
			StringGrid2->Cells[j][i] = "1";
		}
	}

	// 設定起點 (1,1) 為通道 (0)
    step.x = 1, step.y = 1;
	maze[step.x][step.y] = 0;
	StringGrid1->Cells[step.y][step.x] = "0";
	StringGrid2->Cells[step.y][step.x] = "0";

	// 設定入口 (左邊邊界)
	maze[1][0] = 0;
	StringGrid1->Cells[0][1] = "0";
	StringGrid2->Cells[0][1] = "0";

	// 設定出口 (右邊邊界)
	exit_x = m-2, exit_y = n-1 ;
	maze[m-2][n-1] = 0;
	StringGrid1->Cells[n-1][m-2] = "0";
	StringGrid2->Cells[n-1][m-2] = "0";
	push(step); // 將起點推入堆疊


	// 使用 DFS 來產生迷宮
	while (top != -1) { // 只要堆疊不為空
		step = pop(); // 取出當前位置

		while (nextMove(step.x, step.y)) { // 檢查是否有可移動的方向
			int d = random(4); // 隨機選擇一個方向 (0~3)
            next.x = step.x + f2[d].dx;
            next.y = step.y + f2[d].dy;

			// 防止下一步超出邊界
			while (next.x < 0 || next.y < 0 || next.x >= m || next.y >= n) {
				d = random(4);
				next.x = step.x + f2[d].dx;
				next.y = step.y + f2[d].dy;
            }

			// 如果新位置是牆壁 (1)，則打通該路徑
			if (maze[next.x][next.y] == 1) {
                maze[step.x + f1[d].dx][step.y + f1[d].dy] = 0; // 破壞牆壁
				maze[next.x][next.y] = 0; // 標記新位置為路徑

				// 更新 StringGrid 顯示
				StringGrid1->Cells[step.y + f1[d].dy][step.x + f1[d].dx] = "0";
				StringGrid1->Cells[next.y][next.x] = "0";

				StringGrid2->Cells[step.y + f1[d].dy][step.x + f1[d].dx] = "0";
				StringGrid2->Cells[next.y][next.x] = "0";

				push(next); // 將新位置推入堆疊，繼續搜尋
				step = next;
			}
		}
	}

	// 在 Memo1 列印迷宮陣列
	if (generate_time % 2 == 0) {
		Memo1->Lines->Add(String().StringOfChar('=', 3 * m + 3));
		Memo1->Lines->Add("讀取的迷宮 Information: ");
		Memo1->Lines->Add("Maze: Height->" + IntToStr(m) + " / Width->" + IntToStr(n));
		Memo1->Lines->Add(String().StringOfChar('-', 3 * m + 3));

		for (int i = 0; i < m; i++) {
			String out = "";
			for (int j = 0; j < n; j++)
				out += "  " + IntToStr(maze[i][j]);
			Memo1->Lines->Add(out);
		}
	}


	// 固定標題列、標題欄
	StringGrid1->FixedCols = 2;
	StringGrid1->FixedRows = 2;
	StringGrid1->GridLineWidth = 1;
	StringGrid1->DefaultDrawing = false;

	StringGrid2->FixedCols = 2;
	StringGrid2->FixedRows = 2;
	StringGrid2->GridLineWidth = 1;
	StringGrid2->DefaultDrawing = false;

	// 設定格子大小
	for (int i = 0; i < n; i++){
		StringGrid1->ColWidths[i] = gridSize;
		StringGrid2->ColWidths[i] = gridSize;
	}
	for (int i = 0; i < m; i++){
		StringGrid1->RowHeights[i] = gridSize;
		StringGrid2->RowHeights[i] = gridSize;
	}

	// 重新繪製 StringGrid1 以更新顯示
	StringGrid1->Refresh();

	generate_maze = true;
	delete [] stack ;
}

// 判斷是否有可以前進的路
int nextMove(int x, int y){
	for (int i = 0; i < 4; i++) {
		if (x + f2[i].dx < 0 || y + f2[i].dy < 0) {
			continue ;
		}
		if (x + f2[i].dx >= m || y + f2[i].dy >= n) {
			continue ;
		}
		if (maze[x + f2[i].dx][y + f2[i].dy] == 1) {
			return 1;
		}
	}
	return 0;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::StringGrid2DrawCell(TObject *Sender, System::LongInt ACol,
		  System::LongInt ARow, TRect &Rect, TGridDrawState State)
{
	String text = StringGrid2->Cells[ACol][ARow];

	if (text == "0") StringGrid2->Canvas->Brush->Color = TColor RGB(255, 255, 255);        // 路徑：白色

	else if (text == "1") StringGrid2->Canvas->Brush->Color = TColor (RGB(0, 0, 0));       // 牆壁：黑色

	else if (text == "2") StringGrid2->Canvas->Brush->Color = TColor (RGB(65, 105, 225));  // 起點：藍色

	else if (text == "3") StringGrid2->Canvas->Brush->Color = TColor (RGB(255, 0 ,0));     // 終點：紅色

	else if (text == "4") StringGrid2->Canvas->Brush->Color = TColor (RGB(176, 224 ,230));   // 過去走過，但為死路的路徑：淡藍色

	else StringGrid1->Canvas->Brush->Color = TColor RGB(192, 192, 192);    // 終點：紅色

	StringGrid2->Canvas->FillRect(Rect) ;           // 填滿格子
	StringGrid2->Canvas->Font->Color = clBlack ; 	// 字體顏色：黑色
}
//---------------------------------------------------------------------------


void __fastcall TForm1::StringGrid1DrawCell(TObject *Sender, System::LongInt ACol,
		  System::LongInt ARow, TRect &Rect, TGridDrawState State)
{
	String text = StringGrid1->Cells[ACol][ARow];

	if (text == "0") StringGrid1->Canvas->Brush->Color = TColor (RGB(255, 255, 255));   // 路徑：白色

	else if (text == "1") StringGrid1->Canvas->Brush->Color = TColor (RGB(0, 0, 0));    // 牆壁：黑色

	else if (text == "2") StringGrid1->Canvas->Brush->Color = TColor (RGB(65, 105, 225));    // 起點：藍色

	else StringGrid1->Canvas->Brush->Color = TColor RGB(192, 192, 192);      // 終點：紅色

	StringGrid1->Canvas->FillRect(Rect) ;           // 填滿格子
	StringGrid1->Canvas->Font->Color = clBlack ; 	// 字體顏色：黑色
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button1Click(TObject *Sender)
{
	generate_time++;
	Button2->Click();      // 執行 Button2 的點擊事件

	generate_time++;
	Button2->Click();      // 執行 Button2 的點擊事件

}
//---------------------------------------------------------------------------


