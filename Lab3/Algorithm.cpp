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

void selection_sort(int a[], int n, long long &cnt_compare)
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
}

void insertionSort(int a[], int n, long long &count_compare) {
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

void merge(int a[], int left, int mid, int right, long long &count_compare) {
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

void mergeSort(int a[], int left, int right, long long &count_compare) {
    if (++count_compare && left >= right)
        return;
    int mid = (left + right) / 2;
    mergeSort(a, left, mid, count_compare);
    mergeSort(a, mid + 1, right, count_compare);
    merge(a, left, mid, right, count_compare);
}

void quick_sort(int a[], int l, int r, long long& cnt_compare){
	int p = a[(l + r) / 2];
	int i = l, j = r;
	while (++cnt_compare && i < j){
		while (++cnt_compare && a[i] < p){
			i++;
		}
		while (++cnt_compare && a[j] > p){
			j--;
		}
		if (++cnt_compare && i <= j){
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++;
			j--;
		}
	}
	if (++cnt_compare && i < r){
		quick_sort(a, i, r, cnt_compare);
	}
	if (++cnt_compare && l < j){
		quick_sort(a, l, j, cnt_compare);
	}
} 

void shakerSort(int a[], int n, long long &count_compare) {
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

void shell_sort(int a[], int n, long long &cnt_compare) //codelearn.io
{
	cnt_compare = 0;
	int interval, i, j, tmp;
	for(interval = n / 2; ++cnt_compare && interval > 0; interval /= 2)
	{
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

void count_radixSort(int a[], int n, int d, long long &count_compare) {
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

void radixSort(int a[], int n, long long &count_compare) {
    count_compare = 0;
    int max = a[0];
    for (int i = 1; ++count_compare && i < n; i++) {
        if (a[i] > max)
		max = a[i];
    }
    for (int d = 1; ++count_compare && max / d > 0; d *= 10) {
        count_radixSort(a, n, d, count_compare);
    }
}

void bubbleSort(int a[], int n, long long& count_compare)
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

void flashSort(int a[], int n, long long& count_compare)
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

void heapRebuild(int a[], int pos, int n, long long& count_compare)
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

void heapConstruct(int a[], int n, long long& count_compare)
{
	for (int i = (n - 1) / 2; ++count_compare && i >= 0; i--)
		heapRebuild(a, i, n, count_compare);
}

void heapSort(int a[], int n, long long& count_compare)
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

void counting_sort(int input[], int n, long long& count_compare)
{

    int* output = new int [n]; // The output will have sorted input array
    int max = input[0];
    int min = input[0];

    for(int i = 1; ++count_compare && i < n; i++)
    {
        if(++count_compare && input[i] > max)
            max = input[i]; // Maximum value in array
        else if(++count_compare && input[i] < min)
            min = input[i]; // Minimum value in array
    }

    int k = max - min + 1; // Size of count array

    int* count_array = new int [k]; // Create a count_array to store count of each individual input value
    fill_n(count_array, k, 0); // Initialize count_array elements as zero

    for(int i = 0;++count_compare &&  i < n; i++)
        count_array[input[i] - min]++; // Store count of each individual input value

    /* Change count_array so that count_array now contains actual
     position of input values in output array */
    for(int i = 1;++count_compare && i < k; i++)
        count_array[i] += count_array[i - 1];


    // Populate output array using count_array and input array
    for(int i = 0;++count_compare && i < n; i++)
    {
        output[count_array[input[i] - min] - 1] = input[i];
        count_array[input[i] - min]--;
    }


    for(int i = 0;++count_compare && i < n; i++)
        input[i] = output[i]; // Copy the output array to input, so that input now contains sorted values

 delete [] output;
 delete [] count_array;
}
