//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

#include <time.h>
#define max_size 10000000
#define swap(x, y , z) (z = x, x = y, y = z)
int data[max_size] = {0};       // Original
int data2[max_size] = {0};      // Copy

void clear(int arr[]){
	for(int i = 0; i < max_size; i++){
		arr[i] = 0;
	}
}

void copy(int arr[], int n){
	for(int i = 0; i < n; i++){
		data2[i] = arr[i];
	}
}

// 產生隨機數值的函式
void GenRanData(int arr[], int n, int r){
	if(r <= max_size){
		for(int i = 0; i < n; i++){
			arr[i] = rand() % r + 1;    // 產生 1 到 r 的隨機數值
		}
	}else{
		for(int i = 0; i < n; i++){
			arr[i] = rand() % max_size + 1;		// 產生 1 到 MAX_SIZE 的隨機數值
		}
	}
}

void selectionSort(int arr[], int n){
	for(int i = 0; i < n; i++){
		int min = i, temp;
		for(int j = i+1; j < n; j++){
			if (arr[min] > arr[j]) {
				min = j;
			}
		}
		swap(arr[min], arr[i], temp);
	}
}

void insertionSort(int arr[], int n){
	for(int i = 1; i < n; i++){
		int key = arr[i];
		int j = i-1;
		while (j >= 0 && arr[j] > key){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	}
}

void bubbleSort(int arr[], int n){
	for(int i = n-1; i >= 0; i--){
		for(int j = 0; j < i; j++){
			int temp;
			if(arr[j] > arr[j+1]){
				swap(arr[j], arr[j+1], temp);
			}
		}
	}
}

int partition(int arr[], int low, int high) {
	int pivot = arr[high];
	int i = low - 1;
	for (int j = low; j < high; j++) {
		if (arr[j] < pivot) {
			i++;
			int tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
		}
	}
	int tmp = arr[i + 1];
	arr[i + 1] = arr[high];
	arr[high] = tmp;
	return i + 1;
}

void quick_recur(int arr[], int low, int high) {
	if (low < high) {
		int pi = partition(arr, low, high);
		quick_recur(arr, low, pi - 1);
		quick_recur(arr, pi + 1, high);
	}
}

void quick_iter(int arr[], int n) {
	// 建立堆疊
	int* stack = new int[n];
	int top = -1;

	// 初始 push low 和 high
	stack[++top] = 0;
	stack[++top] = n - 1;

	while (top >= 0) {
		int high = stack[top--];
        int low = stack[top--];

        int pi = partition(arr, low, high);

        // 如果左子陣列存在，推入堆疊
		if (pi - 1 > low) {
            stack[++top] = low;
            stack[++top] = pi - 1;
        }

		// 如果右子陣列存在，推入堆疊
		if (pi + 1 < high) {
            stack[++top] = pi + 1;
            stack[++top] = high;
        }
	}

	delete[] stack;
}

void merge(int arr[], int left, int mid, int right) {
	int n1 = mid - left + 1;
	int n2 = right - mid;
	int *L = new int[n1];
	int *R = new int[n2];

	for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    // 合併 L[] 和 R[]
    while (i < n1 && j < n2)
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];

    // 複製剩餘元素（如果有）
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
		arr[k++] = R[j++];

	delete[] L;
	delete[] R;
}

void merge_recur(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

		merge_recur(arr, left, mid);
        merge_recur(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

void merge_iter(int arr[], int n) {
    // curr_size 是每輪合併的子陣列大小（1, 2, 4, 8...）
    for (int curr_size = 1; curr_size < n; curr_size *= 2) {
        // 每次從左往右處理陣列
        for (int left_start = 0; left_start < n - 1; left_start += 2 * curr_size) {
            int mid = left_start + curr_size - 1;
            int right_end = (left_start + 2 * curr_size - 1 < n - 1) ?
                            (left_start + 2 * curr_size - 1) : (n - 1);

            if (mid < right_end)
                merge(arr, left_start, mid, right_end);
        }
    }
}

void heapify(int arr[], int n, int i) {
    int largest = i;          // 假設目前節點是最大
    int left = 2 * i + 1;     // 左子節點
    int right = 2 * i + 2;    // 右子節點

    // 檢查左子節點是否比目前最大值還大
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // 檢查右子節點是否比目前最大值還大
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // 如果最大值不是原本的節點，就交換並遞迴修正堆
    if (largest != i) {
        int tmp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = tmp;

        // 遞迴修正子堆
        heapify(arr, n, largest);
    }
}

void heap_sort(int arr[], int n) {
    // 第一步：從底部往上建最大堆
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // 第二步：反覆將堆頂（最大值）換到陣列尾部
    for (int i = n - 1; i >= 0; i--) {
        // 將最大元素（堆頂）放到最後
		int temp;
		swap(arr[0], arr[i], temp);

        // 重建剩餘堆（長度為 i）
        heapify(arr, i, 0);
    }
}

void counting_sort_by_digit(int arr[], int n, int exp) {
	int *output = new int[n];     // 暫存排序結果
    int count[10] = {0};  // 計數陣列（數位 0~9）

    // 計算各數字出現次數
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // 將 count[i] 變成實際位置
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // 從右往左（穩定排序）建立 output[]
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[--count[digit]] = arr[i];
    }

    // 複製回原陣列
    for (int i = 0; i < n; i++)
		arr[i] = output[i];

	delete[] output;
}

void radix_sort(int arr[], int n) {
    // 找出最大值，用來決定最大位數
    int max_val = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max_val)
            max_val = arr[i];

    // 對每個位數（個、十、百、千…）做 Counting Sort
    for (int exp = 1; max_val / exp > 0; exp *= 10)
        counting_sort_by_digit(arr, n, exp);
}

void counting_sort(int arr[], int n) {
    if (n <= 0) return;

    // 找出最大值（以決定計數陣列大小）
    int max_val = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max_val)
            max_val = arr[i];

    // 配置記憶體
    int *count = (int *)calloc(max_val + 1, sizeof(int));
	int *output = (int *)malloc(n * sizeof(int));

    // 計數每個元素出現次數
    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    // 計數陣列累加轉為位置資訊（prefix sum）
    for (int i = 1; i <= max_val; i++)
        count[i] += count[i - 1];

    // 從右往左填入 output，確保穩定排序
    for (int i = n - 1; i >= 0; i--) {
        output[--count[arr[i]]] = arr[i];
    }

    // 將 output 複製回原始陣列
    for (int i = 0; i < n; i++)
        arr[i] = output[i];

    // 釋放記憶體
    free(count);
    free(output);
}

void printData(int arr[], int n, TMemo* memo){
	String s = "";
	for(int i = 0; i < n; i++){
		s += IntToStr(arr[i]) + " ";
	}
	memo->Lines->Add(s);
}

double timing(double arr[], int n){         // <- 用到這個 function 會自己跳出去，沒有警告 !?
	for(int i = n-1; i >= 0; i--){
		for(int j = 0; j < i; j++){
			double temp;
			if(arr[j] > arr[j+1]){
				swap(arr[j], arr[j+1], temp);
			}
		}
	}
	double sum = 0;
	for(int i = 2; i < n-2; i++){
		sum += arr[i];
	}
	double avg = sum / (n-4);
	return  avg;
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
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	clear(data);
	clear(data2);

	Memo1->Clear();

	int n1, range, time, repeat, ct;

	// 防呆機制
	if (!TryStrToInt(Edit1->Text, n1) || n1 < 1) {
		ShowMessage("請輸入非 0 正整數到 N！");
		return;
	}
	if (!TryStrToInt(Edit2->Text, time) || time < 1) {
		ShowMessage("請輸入大於 0 正整數到 Time！");
		return;
	}
	if (!TryStrToInt(Edit3->Text, range) || range <= 1) {
		ShowMessage("請輸入大於 1 正整數到 Range！");
		return;
	}
	if (!TryStrToInt(Edit4->Text, repeat) || repeat < 1) {
		ShowMessage("請輸入大於 0 正整數到 循環次數 欄位！");
		return;
	}

	if ((!CheckBox1->Checked) && (!CheckBox2->Checked)
		 && (!CheckBox3->Checked) && (!CheckBox7->Checked)
		 && (!CheckBox4->Checked) && (!CheckBox8->Checked)
		 && (!CheckBox5->Checked) && (!CheckBox9->Checked)
		 && (!CheckBox6->Checked) && (!CheckBox10->Checked)) {
		ShowMessage("請至少勾選 Sorting_Selection 其中一個 Sorting Algorithm！");
		return;
	}

	double *c1_data = new double[time];
	double *c2_data = new double[time];
	double *c3_data = new double[time];
	double *c4_data = new double[time];
	double *c5_data = new double[time];
	double *c6_data = new double[time];
	double *c7_data = new double[time];
	double *c8_data = new double[time];
	double *c9_data = new double[time];
	double *c10_data = new double[time];

	Button1->Enabled = false;
	clock_t st, sp;

	int n = n1;  // modify

	if (CheckBox12->Checked)
		PageControl1->ActivePageIndex = 1;
	else
		PageControl1->ActivePageIndex = 0;


	if (CheckBox1->Checked) {
		ct = 0;

		while (ct < time){
			GenRanData(data, n, range);

			if (CheckBox11->Checked) {
				Memo1->Lines->Add("Unsorted -> ");
				printData(data, n, Memo1);
			}

			int i = 0;
			double* record = new double[max_size];

			while (i < repeat){
				clear(data2);
				copy(data, n);

				st = clock();       // 記錄開始時間
				selectionSort(data2, n);
				sp = clock();       // 記錄結束時間

				record[i] = (float)(sp-st)/CLOCKS_PER_SEC;
				i += 1;
			}

			double result = 0;
			if (repeat >= 10) {
				result = timing(record, repeat);
			}else{
				double sum = 0;
				for(int i = 0; i < repeat; i++){
					sum += record[i];
				}
				result = sum / repeat;
			}

			if (CheckBox11->Checked) {
				Memo1->Lines->Add("Sorted -> ");
				printData(data2, n, Memo1);
			}

			Memo1->Lines->Add("Selection Sort (n = " + IntToStr(n) + ") -> ");
			Memo1->Lines->Add("CPU time (Sec.) = " + FloatToStr(result));
			Memo1->Lines->Add("");

			c1_data[ct] = result;

			ct += 1;
			n += 1500;

			delete[] record;
		}
	}

	n = n1;
	if (CheckBox2->Checked) {
		ct = 0;

		while (ct < time){
			GenRanData(data, n, range);

			if (CheckBox11->Checked) {
				Memo1->Lines->Add("Unsorted -> ");
				printData(data, n, Memo1);
			}

			int i = 0;
			double* record = new double[max_size];

			while (i < repeat){
				clear(data2);
				copy(data, n);

				st = clock();       // 記錄開始時間
				insertionSort(data2, n);
				sp = clock();       // 記錄結束時間

				record[i] = (float)(sp-st)/CLOCKS_PER_SEC;
				i += 1;
			}

			double result = 0;
			if (repeat >= 10) {
				result = timing(record, repeat);
			}else{
				double sum = 0;
				for(int i = 0; i < repeat; i++){
					sum += record[i];
				}
				result = sum / repeat;
			}

			if (CheckBox11->Checked) {
				Memo1->Lines->Add("Sorted -> ");
				printData(data2, n, Memo1);
			}

			Memo1->Lines->Add("Insertion Sort (n = " + IntToStr(n) + ") -> ");
			Memo1->Lines->Add("CPU time (Sec.) = " + FloatToStr(result));
			Memo1->Lines->Add("");

			c2_data[ct] = result;

			ct += 1;
			n += 1500;
			delete[] record;
		}
	}

	n = n1;
	if (CheckBox3->Checked) {
		ct = 0;
		while (ct < time){
			GenRanData(data, n, range);
			if (CheckBox11->Checked) {
				Memo1->Lines->Add("Unsorted -> ");
				printData(data, n, Memo1);
			}

			double* record = new double[max_size];

			int i = 0;
			while (i < repeat){
				clear(data2);
				copy(data, n);

				st = clock();       // 記錄開始時間
				bubbleSort(data2, n);
				sp = clock();       // 記錄結束時間

				record[i] = (float)(sp-st)/CLOCKS_PER_SEC;
				i += 1;
			}

			double result = 0;
			if (repeat >= 10) {
				result = timing(record, repeat);
			}else{
				double sum = 0;
				for(int i = 0; i < repeat; i++){
					sum += record[i];
				}
				result = sum / repeat;
			}

			if (CheckBox11->Checked) {
				Memo1->Lines->Add("Sorted -> ");
				printData(data2, n, Memo1);
			}

			Memo1->Lines->Add("Bubble Sort (n = " + IntToStr(n) + ") -> ");
			Memo1->Lines->Add("CPU time (Sec.) = " + FloatToStr(result));
			Memo1->Lines->Add("");

			c3_data[ct] = result;

			ct += 1;
			n += 1500;
			delete[] record;
		}
	}

	n = n1;
	if (CheckBox4->Checked) {
		ct = 0;
		while (ct < time){
			GenRanData(data, n, range);
			if (CheckBox11->Checked) {
				Memo1->Lines->Add("Unsorted -> ");
				printData(data, n, Memo1);
			}

			double * record = new double[max_size];  // Time Data

			int i = 0;
			while (i < repeat){
				clear(data2);
				copy(data, n);

				st = clock();       // 記錄開始時間
				quick_recur(data2, 0, n-1);
				sp = clock();       // 記錄結束時間

				record[i] = (float)(sp-st)/CLOCKS_PER_SEC;
				i += 1;
			}

			double result = 0;
			if (repeat >= 10) {
				result = timing(record, repeat);
			}else{
				double sum = 0;
				for(int i = 0; i < repeat; i++){
					sum += record[i];
				}
				result = sum / repeat;
			}

			if (CheckBox11->Checked) {
				Memo1->Lines->Add("Sorted -> ");
				printData(data2, n, Memo1);
			}

			Memo1->Lines->Add("Quick Sort (Recursive) (n = " + IntToStr(n) + ") -> ");
			Memo1->Lines->Add("CPU time (Sec.) = " + FloatToStr(result));
			Memo1->Lines->Add("");

			c4_data[ct] = result;

			ct += 1;
			n += 1500;
			delete []record;
		}
	}

	n = n1;
	if (CheckBox5->Checked) {
		ct = 0;
		while (ct < time){
			GenRanData(data, n, range);
			if (CheckBox11->Checked) {
				Memo1->Lines->Add("Unsorted -> ");
				printData(data, n, Memo1);
			}

			double * record = new double[max_size];     // Time Data

			int i = 0;
			while (i < repeat){
				clear(data2);
				copy(data, n);

				st = clock();       // 記錄開始時間
				quick_iter(data2, n);
				sp = clock();       // 記錄結束時間

				record[i] = (float)(sp-st)/CLOCKS_PER_SEC;
				i += 1;
			}

			double result = 0;
			if (repeat >= 10) {
				result = timing(record, repeat);
			}else{
				double sum = 0;
				for(int i = 0; i < repeat; i++){
					sum += record[i];
				}
				result = sum / repeat;
			}

			if (CheckBox11->Checked) {
				Memo1->Lines->Add("Sorted -> ");
				printData(data2, n, Memo1);
			}

			Memo1->Lines->Add("Quick Sort (Non-Recursive) (n = " + IntToStr(n) + ") -> ");
			Memo1->Lines->Add("CPU time (Sec.) = " + FloatToStr(result));
			Memo1->Lines->Add("");

			c5_data[ct] = result;

			ct += 1;
			n += 1500;
			delete[] record;
		}
	}

	n = n1;
	if (CheckBox6->Checked) {
		ct = 0;
		while (ct < time){
			GenRanData(data, n, range);
			if (CheckBox11->Checked) {
				Memo1->Lines->Add("Unsorted -> ");
				printData(data, n, Memo1);
			}

			double  *record = new double[max_size];     // Time Data

			int i = 0;
			while (i < repeat){
				clear(data2);
				copy(data, n);

				st = clock();       // 記錄開始時間
				merge_recur(data2, 0, n-1);
				sp = clock();       // 記錄結束時間

				record[i] = (float)(sp-st)/CLOCKS_PER_SEC;
				i += 1;
			}

			double result = 0;
			if (repeat >= 10) {
				result = timing(record, repeat);
			}else{
				double sum = 0;
				for(int i = 0; i < repeat; i++){
					sum += record[i];
				}
				result = sum / repeat;
			}

			if (CheckBox11->Checked) {
				Memo1->Lines->Add("Sorted -> ");
				printData(data2, n, Memo1);
			}

			Memo1->Lines->Add("Merge Sort (Recursive) (n = " + IntToStr(n) + ") -> ");
			Memo1->Lines->Add("CPU time (Sec.) = " + FloatToStr(result));
			Memo1->Lines->Add("");

			c6_data[ct] = result;

			ct += 1;
			n += 1500;
			delete[] record;
		}
	}

	n = n1;
	if (CheckBox7->Checked) {
		ct = 0;
		while (ct < time){
			GenRanData(data, n, range);
			if (CheckBox11->Checked) {
				Memo1->Lines->Add("Unsorted -> ");
				printData(data, n, Memo1);
			}

			double *record = new double[max_size];     // Time Data

			int i = 0;
			while (i < repeat){
				clear(data2);
				copy(data, n);

				st = clock();       // 記錄開始時間
				merge_iter(data2, n);
				sp = clock();       // 記錄結束時間

				record[i] = (float)(sp-st)/CLOCKS_PER_SEC;
				i += 1;
			}

			double result = 0;
			if (repeat >= 10) {
				result = timing(record, repeat);
			}else{
				double sum = 0;
				for(int i = 0; i < repeat; i++){
					sum += record[i];
				}
				result = sum / repeat;
			}

            if (CheckBox11->Checked) {
				Memo1->Lines->Add("Sorted -> ");
				printData(data2, n, Memo1);
			}

			Memo1->Lines->Add("Merge Sort (Non-Recursive) (n = " + IntToStr(n) + ") -> ");
			Memo1->Lines->Add("CPU time (Sec.) = " + FloatToStr(result));
			Memo1->Lines->Add("");

			c7_data[ct] = result;

			ct += 1;
			n += 1500;
			delete[] record;
		}
	}

	n = n1;
	if (CheckBox8->Checked) {
		ct = 0;
		while (ct < time){
			GenRanData(data, n, range);
			if (CheckBox11->Checked) {
				Memo1->Lines->Add("Unsorted -> ");
				printData(data, n, Memo1);
			}

			double *record = new double[max_size];     // Time Data

			int i = 0;
			while (i < repeat){
				clear(data2);
				copy(data, n);

				st = clock();       // 記錄開始時間
				heap_sort(data2, n);
				sp = clock();       // 記錄結束時間

				record[i] = (float)(sp-st)/CLOCKS_PER_SEC;
				i += 1;
			}

			double result = 0;
			if (repeat >= 10) {
				result = timing(record, repeat);
			}else{
				double sum = 0;
				for(int i = 0; i < repeat; i++){
					sum += record[i];
				}
				result = sum / repeat;
			}

			if (CheckBox11->Checked) {
				Memo1->Lines->Add("Sorted -> ");
				printData(data2, n, Memo1);
			}

			Memo1->Lines->Add("Heap Sort (n = " + IntToStr(n) + ") -> ");
			Memo1->Lines->Add("CPU time (Sec.) = " + FloatToStr(result));
			Memo1->Lines->Add("");

			c8_data[ct] = result;

			ct += 1;
			n += 1500;
			delete[] record;
		}
	}

	n = n1;
	if (CheckBox9->Checked) {
		ct = 0;
		while (ct < time){
			GenRanData(data, n, range);
			if (CheckBox11->Checked) {
				Memo1->Lines->Add("Unsorted -> ");
				printData(data, n, Memo1);
			}

			double *record = new double[max_size];     // Time Data

			int i = 0;
			while (i < repeat){
				clear(data2);
				copy(data, n);

				st = clock();       // 記錄開始時間
				radix_sort(data2, n);
				sp = clock();       // 記錄結束時間

				record[i] = (float)(sp-st)/CLOCKS_PER_SEC;
				i += 1;
			}

			double result = 0;
			if (repeat >= 10) {
				result = timing(record, repeat);
			}else{
				double sum = 0;
				for(int i = 0; i < repeat; i++){
					sum += record[i];
				}
				result = sum / repeat;
			}

			if (CheckBox11->Checked) {
				Memo1->Lines->Add("Sorted -> ");
				printData(data2, n, Memo1);
			}

			Memo1->Lines->Add("Radix Sort (n = " + IntToStr(n) + ") -> ");
			Memo1->Lines->Add("CPU time (Sec.) = " + FloatToStr(result));
			Memo1->Lines->Add("");

			c9_data[ct] = result;

			ct += 1;
			n += 1500;
			delete[] record;
		}
	}

	n = n1;
	if (CheckBox10->Checked) {
		ct = 0;
		while (ct < time){
			GenRanData(data, n, range);
			if (CheckBox11->Checked) {
				Memo1->Lines->Add("Unsorted -> ");
				printData(data, n, Memo1);
			}

			double *record = new double[max_size];     // Time Data

			int i = 0;
			while (i < repeat){
				clear(data2);
				copy(data, n);

				st = clock();       // 記錄開始時間
				counting_sort(data2, n);
				sp = clock();       // 記錄結束時間

				record[i] = (float)(sp-st)/CLOCKS_PER_SEC;
				i += 1;
			}

			double result = 0;
			if (repeat >= 10) {
				result = timing(record, repeat);
			}else{
				double sum = 0;
				for(int i = 0; i < repeat; i++){
					sum += record[i];
				}
				result = sum / repeat;
			}

			if (CheckBox11->Checked) {
				Memo1->Lines->Add("Sorted -> ");
				printData(data2, n, Memo1);
			}

			Memo1->Lines->Add("Counting Sort (Recursive) (n = " + IntToStr(n) + ") -> ");
			Memo1->Lines->Add("CPU time (Sec.) = " + FloatToStr(result));
			Memo1->Lines->Add("");

			c10_data[ct] = result;

			ct += 1;
			n += 1500;

			delete[] record;
		}
	}

	if (CheckBox12->Checked) {
		double *size = new double[time];
		for (int i = 0; i < time; i++) {
			size[i] = n1 + 1500 * i;
		}

	// 清除現有圖表
	Chart1->RemoveAllSeries();
	Chart1->Title->Text->Clear();
	Chart1->Title->Text->Add("Sorting Algorithm Performance");
	Chart1->BottomAxis->Title->Caption = "Data Size";
	Chart1->LeftAxis->Title->Caption = "CPU time (sec.)";

	// 定義演算法名稱（按你的要求）
	AnsiString algorithmNames[] = {
		"Selection sort",
		"Insertion sort",
		"Bubble sort",
		"Quick sort (recursive)",
		"Quick sort (non-recursive)",
		"Merge sort (recursive)",
		"Merge sort (non-recursive)",
		"Heap sort",
		"Radix sort",
		"Counting sort"
	};

	// 定義顏色（不同演算法用不同顏色區分）
	TColor seriesColors[] = {
		clRed, clGreen, clBlue, clYellow, clFuchsia,
		clTeal, clNavy, clMaroon, clOlive, clPurple
	};

	// 檢查每個 CheckBox 是否被勾選，並繪製對應的演算法數據
	double* cpuTimeArrays[] = {c1_data, c2_data, c3_data, c4_data, c5_data,
							  c6_data, c7_data, c8_data, c9_data, c10_data};

	TCheckBox* checkBoxes[] = {CheckBox1, CheckBox2, CheckBox3, CheckBox4, CheckBox5,
							  CheckBox6, CheckBox7, CheckBox8, CheckBox9, CheckBox10};

	for (int i = 0; i < 10; i++) {
		// 只有當 CheckBox 被勾選「且」數據陣列不為 NULL 時，才繪製
		if (checkBoxes[i]->Checked && cpuTimeArrays[i] != NULL && size != NULL) {
			// 創建新系列
			TLineSeries* series = new TLineSeries(this);
			series->Title = algorithmNames[i]; // 設定演算法名稱
			series->Color = seriesColors[i];   // 設定顏色

			// 添加數據點（X: size[j], Y: cpuTimeArrays[i][j]）
			int dataSize = time;

			for (int j = 0; j < dataSize; j++) {
				double N = size[j];                  // X 軸：數據規模
				double cpuTime = cpuTimeArrays[i][j]; // Y 軸：CPU 時間
				series->AddXY(N, cpuTime);
			}

			// 添加到圖表
			Chart1->AddSeries(series);
		}
	}

	// 顯示圖例
	Chart1->Legend->Visible = true;

	delete[] c1_data;
	delete[] c2_data;
	delete[] c3_data;
	delete[] c4_data;
	delete[] c5_data;
	delete[] c6_data;
	delete[] c7_data;
	delete[] c8_data;
	delete[] c9_data;
	delete[] c10_data;

	}

	Button1->Enabled = true;
}
//---------------------------------------------------------------------------
