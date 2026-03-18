//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

const int MAX = 100;
const int max_size = 10000;
int move_dx[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int move_dy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	Memo1->Clear();
    Memo2->Clear();
	Edit1->Clear();
	Edit2->Clear();
	Edit3->Clear();
    Button2->Enabled = false;
}
//---------------------------------------------------------------------------

bool KnightTour(int n, int startX, int startY, int K[MAX][MAX])
{
    // 初始化棋盤
    for (int i = 0; i < MAX; ++i)
        for (int j = 0; j < MAX; ++j)
            K[i][j] = 0;

    int x = startX;
    int y = startY;
    K[x][y] = 1; // 起始位置

    for (int step = 2; step <= n * n; ++step)
    {
        int next_x[8], next_y[8], next_moves[8];
        int cnt = 0;

        // 找出目前可走的所有合法位置
        for (int k = 0; k < 8; ++k) {
            int tx = x + move_dx[k];
            int ty = y + move_dy[k];
            if (tx >= 0 && tx < n && ty >= 0 && ty < n && K[tx][ty] == 0) {
                next_x[cnt] = tx;
                next_y[cnt] = ty;
                next_moves[cnt] = 0;
                cnt++;
            }
        }

        if (cnt == 0) return false; // 無路可走，巡迴失敗

        // 檢查每個可選點的下一步可能性數量
        for (int t = 0; t < cnt; ++t) {
            int tx = next_x[t];
            int ty = next_y[t];
            for (int k = 0; k < 8; ++k) {
                int nx = tx + move_dx[k];
                int ny = ty + move_dy[k];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && K[nx][ny] == 0) {
                    next_moves[t]++;
                }
            }
        }

        // 選擇下一步移動：Warnsdorff法則
        int min = 0;
        for (int t = 1; t < cnt; ++t) {
            if (next_moves[t] < next_moves[min])
                min = t;
        }

        x = next_x[min];
        y = next_y[min];
        K[x][y] = step;
    }

    return true; // 成功找到完整路徑
}

bool IsValidKnightTour(int n, int K[MAX][MAX])
{
    const int size = n * n;
	bool seen[max_size] = { false }; // 記錄是否已出現該步數
	int posX[max_size]; // 第 step 步在 X 的位置
    int posY[max_size]; // 第 step 步在 Y 的位置

    // 驗證每個格子的編號合法性並記下座標
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int step = K[i][j];
            if (step < 1 || step > size || seen[step]) {
                return false; // 超出範圍或重複
            }
            seen[step] = true;
            posX[step] = i;
            posY[step] = j;
        }
    }

    // 檢查每一步是否為合法的騎士走法
    for (int step = 1; step < size; ++step) {
        int dx = abs(posX[step] - posX[step + 1]);
        int dy = abs(posY[step] - posY[step + 1]);
        if (!((dx == 2 && dy == 1) || (dx == 1 && dy == 2))) {
            return false; // 不是合法的騎士步
        }
    }

    return true;
}

int n = MAX;
int K[MAX][MAX]; // 棋盤

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	Memo1->Clear();
	int x, y;
	PageControl1->ActivePage = TabSheet1;

	if(!TryStrToInt(Edit1->Text, n) || n <= 0){
		Memo1->Lines->Add("請輸入正整數至 \"n\" 欄位!!!");
		return;
	}

	if(!TryStrToInt(Edit2->Text, x) || x < 0){
		Memo1->Lines->Add("請輸入大於等於 0 的整數至 \"X\" 欄位!!!");
		return;
	}

	if(!TryStrToInt(Edit3->Text, y) || y < 0){
		Memo1->Lines->Add("請輸入大於等於 0 的整數至 \"Y\" 欄位!!!");
		return;
	}

    if (n <= 0 || n > MAX || x < 0 || y < 0 || x >= n || y >= n) {
        Memo1->Lines->Add("輸入錯誤：請輸入 0 <= x,y < n 且 1 <= n <= 8");
        return;
	}

    if (!KnightTour(n, x, y, K)) {
		Memo1->Lines->Add(Format("自 (%d, %d) 出發無騎士巡迴路徑", ARRAYOFCONST((x, y))));
		Button2->Enabled = false;
        return;
    }

    // 顯示棋盤結果
    for (int i = 0; i < n; ++i) {
		String line = "";
		for (int j = 0; j < n; ++j) {
			line += Format("%10d", ARRAYOFCONST((K[i][j]))); // 每格寬度4，靠右對齊
		}
		Memo1->Lines->Add(line);
	}

	// 檢查是否為正確的 Knight Tour
	if (IsValidKnightTour(n, K)) {
		Memo1->Lines->Add("Valid Knight Tour！");
		Button2->Enabled = true;
	} else {
		Memo1->Lines->Add("Invalid Knight Tour！");
		Button2->Enabled = false;
	}

}
//---------------------------------------------------------------------------



void __fastcall TForm1::Button2Click(TObject *Sender)
{
    PageControl1->ActivePage = TabSheet2;

	const int CellSize = 100; // 每格寬高

    // 設定格子數量
    StringGrid1->ColCount = n;
    StringGrid1->RowCount = n;

    // 格子大小與整體控制
    StringGrid1->DefaultColWidth = CellSize;
    StringGrid1->DefaultRowHeight = CellSize;
    StringGrid1->Width = CellSize * n + 4;
    StringGrid1->Height = CellSize * n + 4;

    // 關閉標題列與使用者編輯功能
    StringGrid1->FixedCols = 0;
    StringGrid1->FixedRows = 0;
    StringGrid1->Options = StringGrid1->Options >> goEditing;

    // 美化：背景色、格線、字型
    StringGrid1->GridLineWidth = 1;
    StringGrid1->ScrollBars = ssNone;
    StringGrid1->Color = clWhite;
    StringGrid1->Font->Size = 10;
    StringGrid1->Font->Name = "Consolas"; // 等寬字體更整齊

    // 填入騎士巡迴步數
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            StringGrid1->Cells[j][i] = IntToStr(K[i][j]); // 注意順序是 [col][row]
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
    // 清除 StringGrid 內容
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            StringGrid1->Cells[j][i] = "";  // 清除內容
        }
    }

	// 重新設置 StringGrid 的行列數
	StringGrid1->RowCount = n;
	StringGrid1->ColCount = n;

	// 設置每格的大小
	const int CellSize = 40;  // 每格大小
	StringGrid1->DefaultColWidth = CellSize;
	StringGrid1->DefaultRowHeight = CellSize;

	// 設置 StringGrid 大小
	StringGrid1->Width = CellSize * n + 4;
	StringGrid1->Height = CellSize * n + 4;

	// 設置表格其他屬性
	StringGrid1->FixedCols = 0;
	StringGrid1->FixedRows = 0;
	StringGrid1->Options = StringGrid1->Options >> goEditing;

	StringGrid1->GridLineWidth = 1;
	StringGrid1->ScrollBars = ssNone;
	StringGrid1->Color = clWhite;
	StringGrid1->Font->Size = 10;
	StringGrid1->Font->Name = "Consolas";  // 等寬字體

	Memo1->Clear();
	Edit1->Clear();
	Edit2->Clear();
	Edit3->Clear();

	Button2->Enabled = false;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

