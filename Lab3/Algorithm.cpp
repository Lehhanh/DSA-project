#include <iostream>
#include <time.h>
#include <cstdlib>
#include "Algorithm.h"
using namespace std;
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void selection_sort(int a[], int n, int &cnt_compare)
{
	cnt_compare = 0;
	int i, j, min_idx;
	for(int i = 0; ++cnt_compare && i < n - 1; i++)
	{
		min_idx = i;
		for(int j = i + 1; ++cnt_compare && j < n; j++)
		{
			if(++cnt_compare && a[j] < a[min_idx])
			{
				min_idx = j;
			}
		}
		swap(a[i], a[min_idx]);
	}
	cnt_compare++;
}

void insertionSort(int a[], int n, int &count_compare) {
    count_compare = 0;
    for (int i = 1; ++count_compare && i < n; i++) {
        int x = a[i];
        int j = i - 1;
        while (++count_compare && j >= 0 && ++count_compare && a[j] > x) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = x;
    }
}

void merge(int a[], int left, int mid, int right, int &count_compare) {
    int* temp_arr = new int[right - left + 1];
    int i1 = left, i2 = mid + 1;
    int i = 0;
    while (++count_compare && i1 <= mid && ++count_compare && i2 <= right) {
        if (++count_compare && a[i1] <= a[i2])
            temp_arr[i++] = a[i1++];
        else
            temp_arr[i++] = a[i2++];
    }
    while (++count_compare && i1 <= mid) {
        temp_arr[i++] = a[i1++];
    }
    while (++count_compare && i2 <= right) {
        temp_arr[i++] = a[i2++];
    }
    i = 0;
    for (int j = left; ++count_compare && j <= right; j++) {
        a[j] = temp_arr[i++];
    }
    delete[] temp_arr;
}

void mergeSort(int a[], int left, int right, int &count_compare) {
    if (++count_compare && left >= right)
        return;
    int mid = (left + right) / 2;
    mergeSort(a, left, mid, count_compare);
    mergeSort(a, mid + 1, right, count_compare);
    merge(a, left, mid, right, count_compare);
}

int partition(int a[], int l, int r, int &cnt_compare)
{
	int i = l - 1;
	int pivot = a[r];
	for(int j = l; ++cnt_compare && j < r; j++)
	{
		//Neu a[j] > pivot => bo qua
		if(++cnt_compare && a[j] <= pivot)
		{
			//Dua a[j] len dau
			i++;
			swap(a[i], a[j]);
		}
	}
	i++; //Tang i len 1 don vi de swap pivot ve giua mang
	swap(a[i], a[r]);
	return i;
}

void quick_sort(int a[], int l, int r, int &cnt_compare)
{
	cnt_compare = 0;
	if(l < r)
	{
		int pos = partition(a, l, r, cnt_compare);
		quick_sort(a, l, pos - 1, cnt_compare); //De quy ben trai
		quick_sort(a, pos + 1, r, cnt_compare); //De quy ben phai
	}
}

void shakerSort(int a[], int n, int &count_compare) {
    count_compare = 0;
    int left = 0;
    int right = n - 1;
    int x = 0;
    while (++count_compare && left < right) {
        for (int i = left; ++count_compare && i < right; i++) {
            if (++count_compare && a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                x = i;
            }
        }
        right = x;
        for (int i = right; ++count_compare && i > left; i--) {
            if (++count_compare && a[i] < a[i - 1]) {
                swap(a[i], a[i - 1]);
                x = i;
            }
        }
        left = x;
    }
}

void shell_sort(int a[], int n, int &cnt_compare) //codelearn.io
{
	cnt_compare = 0;
	int interval, i, j, tmp;
	for(interval = n / 2; ++cnt_compare && interval > 0; interval /= 2)
	{
		cnt = 0;
		for(i = interval; ++cnt_compare && i < n; i++)
		{
			tmp = a[i];
			for(j = i; ++cnt_compare && j >= interval && ++cnt_compare && a[j - interval] > tmp ; j -= interval)
			{
				a[j] = a[j - interval];
			}
			a[j] = tmp;
		}
	}
}

void count_radixSort(int a[], int n, int d, int &count_compare) {
    int* output = new int[n] {0};
    int count[10] = { 0 };
    for (int i = 0; ++count_compare && i < n; i++) {
        count[(a[i] / d) % 10]++;
    }
    for (int i = 1; ++count_compare && i < 10; i++) {
        count[i] += count[i - 1];
    }
    for (int i = n - 1; ++count_compare && i >= 0; i--) {
        output[count[(a[i] / d) % 10] - 1] = a[i];
        count[(a[i] / d) % 10]--;
    }
    for (int i = 0; ++count_compare && i < n; i++) {
        a[i] = output[i];
    }
    delete[] output;
}

void radixSort(int a[], int n, int &count_compare) {
    count_compare = 0;
    for (int d = 1; ++count_compare && n / d > 0; d *= 10) {
        count_radixSort(a, n, d, count_compare);
    }
}

void bubbleSort(int a[], int n, int& count_compare)
{
	count_compare = 0;
	
	 for (int i = 0; ++count_compare && i < n - 1; i++)
	 {
        for (int j = 0; ++count_compare && j < n - i - 1; j++)
	{
	    ++count_compare;
            if (a[j] > a[j + 1])
	    {
                swap(a[j], a[j + 1]);
            }
        }
    }
}

void flashSort(int a[], int n, int& count_compare)
{
	count_compare = 0;
	int minVal = a[0];
	int max = 0;
	int m = int(0.45 * n);
	int* l = new int[m];
	
	for (int i = 0; ++count_compare && i < m; i++)
		l[i] = 0;
	for (int i = 1; ++count_compare && i < n; i++)
	{
		++count_compare;
		if (a[i] < minVal)
			minVal = a[i];
		++count_compare;
		if (a[i] > a[max])
			max = i;
	}
	++count_compare;
	if (a[max] == minVal)
		return;
	double c1 = (double)(m - 1) / (a[max] - minVal);
	for (int i = 0; ++count_compare && i < n; i++)
	{
		int k = int(c1 * (a[i] - minVal));
		++l[k];
	}
	for (int i = 1; ++count_compare && i < m; i++)
		l[i] += l[i - 1];
	swap(a[max], a[0]);
	int nmove = 0;
	int j = 0;
	int k = m - 1;
	int t = 0;
	int flash;
	while ( ++count_compare && nmove < n - 1)
	{
		while (++count_compare && j > l[k] - 1)
		{
			j++;
			k = int(c1*(a[j] - minVal));
		}
		flash = a[j];
		++count_compare;// for the command if behind
		if (k < 0) break;
		while ( ++count_compare && j != l[k])
		{
			k = int(c1*(flash - minVal));
			int hold = a[t = --l[k]];
			a[t] = flash;
			flash = hold;
			++nmove;
		}
	}
	delete[] l;
	//insertionSort
	// sau buoc hoan vi thi khoang cach phai duy chuyen giua cac phan tu khong lon, vi the insertionSort se co uu the
	for (int i = 1; ++count_compare && i < n; i++)
	{
		int k = i - 1;
		int key = a[i];
		while ( ++count_compare && a[k] > key && ++count_compare && k >= 0)
		{
			a[k + 1] = a[k];
			k--;
		}
		a[k + 1] = key;
	}

}

void heapRebuild(int a[], int pos, int n, int& count_compare)
{

	while (++count_compare && (2 * pos + 1 < n))
	{
		int j = 2 * pos + 1;
		++count_compare;
		if (j < n - 1)
		{
			++count_compare;
			if (a[j] < a[j + 1])
			j = j + 1;
		}
		++count_compare;
		if (a[pos] >= a[j])
			return;
		swap(a[pos], a[j]);
		pos = j;
	}
}

void heapConstruct(int a[], int n, int& count_compare)
{
	for (int i = (n - 1) / 2; ++count_compare && i >= 0; i--)
		heapRebuild(a, i, n, count_compare);
}

void heapSort(int a[], int n, int& count_compare)
{
	count_compare = 0;
	heapConstruct(a, n, count_compare);
	int r = n - 1;
	while (++count_compare && r > 0)
	{
		swap(a[0], a[r]);
		heapRebuild(a, 0, r, count_compare);
		r--;
	}
}

void counting_sort(int input[], int n, int& count_compare)
{
    count_compare = 0;
    int *output = new int [n];
    int max = input[0];
    int min = input[0];
    int i;
	
    for(i = 1; ++count_compare && i < n; i++)
    {
        if(++count_compare && input[i] > max)
            max = input[i];
        else if(++count_compare && input[i] < min)
            min = input[i];
    }

    int k = max - min + 1;

    int count_array[k];
    for(i = 0; ++count_compare && i < k; i++)
        count_array[i] = 0;

    for(i = 0; ++count_compare && i < n; i++)
        count_array[input[i] - min]++;
    for(i = 1; ++count_compare && i < k; i++)
        count_array[i] += count_array[i - 1];
    for(i = 0; ++count_compare && i < n; i++)
    {
        output[count_array[input[i] - min] - 1] = input[i];
        count_array[input[i] - min]--;
    }

    for(i = 0; ++count_compare && i < n; i++)
        input[i] = output[i];
    delete[] output;
}
