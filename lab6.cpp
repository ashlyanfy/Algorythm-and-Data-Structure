#include <iostream>
#include <string>
using namespace std;

struct Node {
    int id;
    string name;
    Node* next;
};

Node* head = nullptr;

Node* findStudent(int id) {
    Node* current = head;
    while (current != nullptr) {
        if (current->id == id) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

void addAtEnd(int id, string name) {
    if (findStudent(id) != nullptr) {
        cout << "Error: ID " << id << " already exists" << endl;
        return;
    }
    Node* newNode = new Node{id, name, nullptr};
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
    cout << "Student added at the end" << endl;
}

void addAtBeginning(int id, string name) {
    if (findStudent(id) != nullptr) {
        cout << "Error: ID " << id << " already exists" << endl;
        return;
    }
    Node* newNode = new Node{id, name, head};
    head = newNode;
    cout << "Student added at the beginning" << endl;
}

void searchStudent(int id) {
    Node* student = findStudent(id);
    if (student == nullptr) {
        cout << "Not found" << endl;
    } else {
        cout << "Found: ID = " << student->id << ", Name = " << student->name << endl;
    }
}

void deleteStudent(int id) {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }
    if (head->id == id) {
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Student deleted" << endl;
        return;
    }
    Node* current = head;
    while (current->next != nullptr && current->next->id != id) {
        current = current->next;
    }
    if (current->next == nullptr) {
        cout << "Not found" << endl;
        return;
    }
    Node* temp = current->next;
    current->next = temp->next;
    delete temp;
    cout << "Student deleted" << endl;
}

void updateName(int id, string newName) {
    Node* student = findStudent(id);
    if (student == nullptr) {
        cout << "Not found" << endl;
    } else {
        student->name = newName;
        cout << "Name updated" << endl;
    }
}

void displayAll() {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        cout << "Total students: 0" << endl;
        return;
    }
    Node* current = head;
    int count = 0;
    while (current != nullptr) {
        cout << current->id << " - " << current->name << endl;
        count++;
        current = current->next;
    }
    cout << "Total students: " << count << endl;
}

void freeList() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    int choice;
    int id;
    string name;

    do {
        cout << endl;
        cout << "===== Student Record Management =====" << endl;
        cout << "1. Add student at end" << endl;
        cout << "2. Insert student at beginning" << endl;
        cout << "3. Search student by ID" << endl;
        cout << "4. Delete student by ID" << endl;
        cout << "5. Update student name" << endl;
        cout << "6. Display all students" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1 || choice == 2) {
            cout << "Enter ID: ";
            cin >> id;
            cout << "Enter name: ";
            getline(cin >> ws, name);
            if (choice == 1) {
                addAtEnd(id, name);
            } else {
                addAtBeginning(id, name);
            }
        } else if (choice == 3) {
            cout << "Enter ID: ";
            cin >> id;
            searchStudent(id);
        } else if (choice == 4) {
            cout << "Enter ID: ";
            cin >> id;
            deleteStudent(id);
        } else if (choice == 5) {
            cout << "Enter ID: ";
            cin >> id;
            cout << "Enter new name: ";
            getline(cin >> ws, name);
            updateName(id, name);
        } else if (choice == 6) {
            displayAll();
        } else if (choice != 0) {
            cout << "Invalid choice" << endl;
        }
    } while (choice != 0);

    freeList();
    cout << "Memory released. Goodbye!" << endl;
    return 0;
}