#pragma once
void selection_sort(int a[], int n, int &cnt_compare);
void insertionSort(int a[], int n, int &count_compare);
void merge(int a[], int left, int mid, int right, int& count_compare);
void mergeSort(int a[], int left, int right, int& count_compare);
int partition(int a[], int l, int r, int &cnt_compare);
void quick_sort(int a[], int l, int r, int &cnt_compare);
void shakerSort(int a[], int n, int& count_compare);
void shell_sort(int a[], int n, int &cnt_compare);
void count_radixSort(int a[], int n, int d, int& count_compare);
void radixSort(int a[], int n, int& count_compare);
void bubbleSort(int a[], int n, int& count_compare);
void flashSort(int a[], int n, int& count_compare);
void heapRebuild(int a[], int pos, int n, int& count_compare);
void heapConstruct(int a[], int n, int& count_compare);
void heapSort(int a[], int n, int& count_compare);
void counting_sort(int input[], int n, int& count_compare);
