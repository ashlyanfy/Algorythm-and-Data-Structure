#include <iostream>
using namespace std;

int main() {
    int numbers[6] = {7, 3, 9, 2, 6, 1};
    int n = 6;
    int totalSwaps = 0;

    cout << "Original list: ";
    for (int i = 0; i < n; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    for (int pass = 0; pass < n - 1; pass++) {
        int passSwaps = 0;

        for (int i = 0; i < n - 1 - pass; i++) {
            if (numbers[i] > numbers[i + 1]) {
                int temp = numbers[i];
                numbers[i] = numbers[i + 1];
                numbers[i + 1] = temp;
                passSwaps++;
            }
        }

        totalSwaps += passSwaps;
        cout << "Pass " << pass + 1 << ": ";
        for (int i = 0; i < n; i++) {
            cout << numbers[i] << " ";
        }
        cout << " | swaps: " << passSwaps << endl;
    }
    cout << "Sorted list: ";
    for (int i = 0; i < n; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;
    cout << "Total swaps: " << totalSwaps << endl;
    return 0;
}