#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList() {
        head = NULL;
    }

    void insertAtTail(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }

    void printList() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    void sortList() {
        vector<int> values;
        Node* temp = head;

        // Bước 1: đưa toàn bộ giá trị vào vector
        while (temp) {
            values.push_back(temp->data);
            temp = temp->next;
        }

        // Bước 2: sắp xếp
        sort(values.begin(), values.end());

        // Bước 3: gán ngược lại
        temp = head;
        int i = 0;
        while (temp) {
            temp->data = values[i++];
            temp = temp->next;
        }
    }
};

int main() {
    LinkedList list;
    list.insertAtTail(5);
    list.insertAtTail(2);
    list.insertAtTail(8);
    list.insertAtTail(1);

    cout << "Truoc khi sap xep:\n";
    list.printList();

    list.sortList();

    cout << "Sau khi sap xep tang dan:\n";
    list.printList();

    return 0;
}
