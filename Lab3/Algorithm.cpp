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
    while (++count_compare && i1 <= mid && count_compare && i2 <= right) {
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

void bubbleSort(int a[], int n, int& comparisons)
{
	comparisons = 0;
	
	 for (int i = 0; ++comparisons && i < n - 1; i++)
	 {
        for (int j = 0; ++comparisons && j < n - i - 1; j++)
		{
			++comparisons;
            if (a[j] > a[j + 1])
			{
                swap(a[j], a[j + 1]);
            }
        }
    }
}

void flashSort(int a[], int n, int& comparisons)
{
	comparisons = 0;
	int minVal = a[0];
	int max = 0;
	int m = int(0.45 * n);
	int* l = new int[m];
	
	for (int i = 0; ++comparisons && i < m; i++)
		l[i] = 0;
	for (int i = 1; ++comparisons && i < n; i++)
	{
		++comparisons;
		if (a[i] < minVal)
			minVal = a[i];
		++comparisons;
		if (a[i] > a[max])
			max = i;
	}
	++comparisons;
	if (a[max] == minVal)
		return;
	double c1 = (double)(m - 1) / (a[max] - minVal);
	for (int i = 0; ++comparisons && i < n; i++)
	{
		int k = int(c1 * (a[i] - minVal));
		++l[k];
	}
	for (int i = 1; ++comparisons && i < m; i++)
		l[i] += l[i - 1];
	swap(a[max], a[0]);
	int nmove = 0;
	int j = 0;
	int k = m - 1;
	int t = 0;
	int flash;
	while ( ++comparisons && nmove < n - 1)
	{
		while (++comparisons && j > l[k] - 1)
		{
			j++;
			k = int(c1*(a[j] - minVal));
		}
		flash = a[j];
		++comparisons;// for the command if behind
		if (k < 0) break;
		while ( ++comparisons && j != l[k])
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
	for (int i = 1; ++comparisons && i < n; i++)
	{
		int k = i - 1;
		int key = a[i];
		while ( ++comparisons && a[k] > key && ++comparisons && k >= 0)
		{
			a[k + 1] = a[k];
			k--;
		}
		a[k + 1] = key;
	}

}

void heapRebuild(int a[], int pos, int n, int& comparisons)
{

	while (++comparisons && (2 * pos + 1 < n))
	{
		int j = 2 * pos + 1;
		++comparisons;
		if (j < n - 1)
		{
			++comparisons;
			if (a[j] < a[j + 1])
			j = j + 1;
		}
		++comparisons;
		if (a[pos] >= a[j])
			return;
		swap(a[pos], a[j]);
		pos = j;
	}
}

void heapConstruct(int a[], int n, int& comparisons)
{
	for (int i = (n - 1) / 2; ++comparisons && i >= 0; i--)
		heapRebuild(a, i, n, comparisons);
}

void heapSort(int a[], int n, int& comparisons)
{
	comparisons = 0;
	heapConstruct(a, n, comparisons);
	int r = n - 1;
	while (comparisons && r > 0)
	{
		swap(a[0], a[r]);
		heapRebuild(a, 0, r, comparisons);
		r--;
	}
}
