#include <iostream>
using namespace std;

int main() {
    int numbers[10];
    cout << "Enter 10 integers in ascending order:" << endl;
    for (int i = 0; i < 10; i++) {
        cout << "Number " << i + 1 << ": ";
        cin >> numbers[i];
    }

    int target;
    cout << "Enter the value to search for: ";
    cin >> target;
    int low = 0;
    int high = 9;
    int foundIndex = -1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (numbers[mid] == target) {
            foundIndex = mid;
            break;
        }
        else if (numbers[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    if (foundIndex != -1) {
        cout << "Found at index " << foundIndex << endl;
    }
    else {
        cout << "Not found" << endl;
    }

    return 0;
}