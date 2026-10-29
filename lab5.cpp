#include <iostream>
using namespace std;
void insertionSort(int a[], int n, int& comparisons, int& shifts) {
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0) {
            comparisons++;
            if (a[j] <= key) break;
            a[j + 1] = a[j];
            shifts++;
            j--;
        }
        a[j + 1] = key;
    }
}
void showResult(const char* name, int a[], int n) {
    int comparisons = 0, shifts = 0;
    insertionSort(a, n, comparisons, shifts);
    cout << name << ": ";
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << "\nComparisons: " << comparisons;
    cout << "\nShifts: " << shifts << "\n\n";
}
int main() {
    int a[] = {12, 18, 24, 21, 30, 36, 42, 48};
    int b[] = {48, 42, 36, 30, 24, 21, 18, 12};
    int n = sizeof(a) / sizeof(a[0]);
    showResult("A", a, n);
    showResult("B", b, n);
    return 0;
}