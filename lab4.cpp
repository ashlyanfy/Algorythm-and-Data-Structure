#include <iostream>
using namespace std;

int main() {
    int arr[] = {29, 10, 14, 37, 13, 8};
    int n = 6;
    int swaps = 0;

    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        cout << "Pass " << i + 1 << ": min = " << arr[minIndex] << endl;

        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
            swaps++;
        }

        cout << "List: ";
        for (int k = 0; k < n; k++) {
            cout << arr[k] << " ";
        }
        cout << endl;
    }

    cout << "Sorted list: ";
    for (int k = 0; k < n; k++) {
        cout << arr[k] << " ";
    }
    cout << endl;
    cout << "Total swaps: " << swaps << endl;
    return 0;
}