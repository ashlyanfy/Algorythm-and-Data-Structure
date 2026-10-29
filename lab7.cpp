#include <iostream>
#include <string>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    ~LinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    int length() const {
        int count = 0;
        Node* current = head;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }

    void display() const {
        cout << "List: ";
        if (head == nullptr) {
            cout << "(empty)";
        }
        Node* current = head;
        while (current != nullptr) {
            cout << current->data;
            if (current->next != nullptr) {
                cout << " -> ";
            }
            current = current->next;
        }
        cout << " | Nodes: " << length() << endl;
    }

    bool insertAt(int position, int value) {
        if (position < 1 || position > length() + 1) {
            cout << "Error: invalid position " << position << " for insertion" << endl;
            return false;
        }
        Node* newNode = new Node{value, nullptr};
        if (position == 1) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* previous = head;
            for (int i = 1; i < position - 1; i++) {
                previous = previous->next;
            }
            newNode->next = previous->next;
            previous->next = newNode;
        }
        return true;
    }

    bool deleteAt(int position) {
        if (head == nullptr) {
            cout << "Error: cannot delete, the list is empty" << endl;
            return false;
        }
        if (position < 1 || position > length()) {
            cout << "Error: invalid position " << position << " for deletion" << endl;
            return false;
        }
        Node* target;
        if (position == 1) {
            target = head;
            head = head->next;
        } else {
            Node* previous = head;
            for (int i = 1; i < position - 1; i++) {
                previous = previous->next;
            }
            target = previous->next;
            previous->next = target->next;
        }
        delete target;
        return true;
    }

    void reverse() {
        Node* previous = nullptr;
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            current->next = previous;
            previous = current;
            current = nextNode;
        }
        head = previous;
    }
};

void printStep(const string& title, LinkedList& list) {
    cout << title << endl;
    list.display();
    cout << endl;
}

int main() {
    LinkedList list;
    int initialValues[] = {15, 30, 45, 60, 75};
    for (int value : initialValues) {
        list.insertAt(list.length() + 1, value);
    }

    cout << "===== Part B: Required Demonstration =====" << endl << endl;
    printStep("Initial list:", list);

    list.insertAt(1, 10);
    printStep("Step 1: insert 10 at position 1", list);

    list.insertAt(5, 50);
    printStep("Step 2: insert 50 at position 5", list);

    list.deleteAt(3);
    printStep("Step 3: delete position 3", list);

    list.reverse();
    printStep("Step 4: reverse the list", list);

    cout << "===== Edge Case Tests =====" << endl << endl;

    cout << "Test 1: delete at invalid position 10" << endl;
    list.deleteAt(10);
    list.display();
    cout << endl;

    cout << "Test 2: insert at invalid position 0" << endl;
    list.insertAt(0, 99);
    list.display();
    cout << endl;

    cout << "Test 3: delete all remaining nodes" << endl;
    while (list.length() > 0) {
        list.deleteAt(1);
        list.display();
    }
    cout << endl;

    cout << "Test 4: delete from the empty list" << endl;
    list.deleteAt(1);
    list.display();

    return 0;
}