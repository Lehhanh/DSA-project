#pragma once
void insertionSort(int a[], int n, int &count_compare);
void merge(int a[], int left, int mid, int right, int& count_compare);
void mergeSort(int a[], int left, int right, int& count_compare);
void shakerSort(int a[], int n, int& count_compare);
void count_radixSort(int a[], int n, int d, int& count_compare);
void radixSort(int a[], int n, int& count_compare);
void bubbleSort(int a[], int n, int& comparisons);
void flashSort(int a[], int n, int& comparisons);
void heapRebuild(int a[], int pos, int n, int& comparisons);
void heapConstruct(int a[], int n, int& comparisons);
void heapSort(int a[], int n, int& comparisons);
