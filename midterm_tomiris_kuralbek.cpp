#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

struct Student {
    int id;
    string name;
    int marks;
};

bool addStudent(vector<Student>& list, int id, const string& name, int marks) {
    if (marks < 0 || marks > 100) {
        cout << "REJECTED: ID " << id << " (" << name << ") - marks " << marks
             << " are outside 0-100\n";
        return false;
    }
    for (const Student& s : list) {
        if (s.id == id) {
            cout << "REJECTED: ID " << id << " (" << name << ") - duplicate ID\n";
            return false;
        }
    }
    list.push_back({id, name, marks});
    return true;
}

void printHeader() {
    cout << left << setw(10) << "ID" << setw(15) << "Name" << "Marks\n";
    cout << string(32, '-') << '\n';
}

void printRecord(const Student& s) {
    cout << left << setw(10) << s.id << setw(15) << s.name << s.marks << '\n';
}

void printAll(const vector<Student>& list, const string& title) {
    cout << "\n=== " << title << " ===\n";
    printHeader();
    for (const Student& s : list) printRecord(s);
}

void showStatistics(const vector<Student>& list) {
    if (list.empty()) return;

    int sum = 0;
    int highest = list[0].marks;
    int lowest  = list[0].marks;

    for (const Student& s : list) {
        sum += s.marks;
        if (s.marks > highest) highest = s.marks;
        if (s.marks < lowest)  lowest  = s.marks;
    }

    cout << "\nClass average: " << fixed << setprecision(2)
         << static_cast<double>(sum) / list.size() << '\n';
    cout << "Highest marks: " << highest << '\n';
    cout << "Lowest marks:  " << lowest << '\n';
}

void bubbleSortByMarksDesc(vector<Student>& list) {
    int n = list.size();
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - 1 - i; j++) {
            if (list[j].marks < list[j + 1].marks) {
                swap(list[j], list[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

int linearSearch(const vector<Student>& list, int id) {
    for (int i = 0; i < (int)list.size(); i++) {
        if (list[i].id == id) return i;
    }
    return -1;
}

void insertionSortById(vector<Student>& list) {
    for (int i = 1; i < (int)list.size(); i++) {
        Student key = list[i];
        int j = i - 1;
        while (j >= 0 && list[j].id > key.id) {
            list[j + 1] = list[j];
            j--;
        }
        list[j + 1] = key;
    }
}

int binarySearch(const vector<Student>& list, int id) {
    int low = 0, high = list.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (list[mid].id == id) return mid;
        if (list[mid].id < id) low = mid + 1;
        else                   high = mid - 1;
    }
    return -1;
}

void showSearchResult(const vector<Student>& list, int index, int id, const string& method) {
    cout << method << " for ID " << id << ": ";
    if (index == -1) {
        cout << "Not found\n";
    } else {
        cout << "Found\n";
        printHeader();
        printRecord(list[index]);
    }
}

int main() {
    vector<Student> students;

    cout << "=== Adding records ===\n";
    addStudent(students, 42585, "Tomiris",   92);
    addStudent(students, 42101, "Aruzhan",   78);
    addStudent(students, 42760, "Daniyar",   85);
    addStudent(students, 42333, "Alikhan",   64);
    addStudent(students, 42999, "Madina",    99);
    addStudent(students, 42050, "Yerlan",    55);
    addStudent(students, 42444, "Dana",      71);
    addStudent(students, 42612, "Nursultan", 88);

    addStudent(students, 42585, "Copy",    80);
    addStudent(students, 42700, "Arman",  105);
    addStudent(students, 42701, "Aigerim", -5);
    cout << "Accepted records: " << students.size() << '\n';

    printAll(students, "All student records");
    showStatistics(students);

    vector<Student> byMarks = students;
    bubbleSortByMarksDesc(byMarks);
    printAll(byMarks, "Sorted by marks (descending) - Bubble Sort");

    cout << "\n=== Linear Search ===\n";
    showSearchResult(students, linearSearch(students, 42585), 42585, "Linear Search");
    showSearchResult(students, linearSearch(students, 99999), 99999, "Linear Search");

    vector<Student> byId = students;
    insertionSortById(byId);
    printAll(byId, "Sorted by ID (ascending) - Insertion Sort");

    cout << "\n=== Binary Search ===\n";
    showSearchResult(byId, binarySearch(byId, 42585), 42585, "Binary Search");
    showSearchResult(byId, binarySearch(byId, 11111), 11111, "Binary Search");

    return 0;
}