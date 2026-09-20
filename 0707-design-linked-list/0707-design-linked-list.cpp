class MyLinkedList {
private:
    struct Node {
        int val;
        Node* next;
        Node(int val) : val(val), next(nullptr) {}
    };

    Node* head;
    int size;

public:
    MyLinkedList() {
        head = nullptr;
        size = 0;
    }

    int get(int index) {
        if (index < 0 || index >= size) {
            return -1;
        }

        Node* temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        return temp->val;
    }

    void addAtHead(int val) {
        Node* neww = new Node(val);
        neww->next = head;
        head = neww;
        size++;
    }

    void addAtTail(int val) {
        if (size == 0) {
            addAtHead(val);
            return;
        }

        Node* neww = new Node(val);
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = neww;
        size++;
    }

    void addAtIndex(int index, int val) {
        if (index < 0 || index > size) {
            return;
        }
        if (index == 0) {
            addAtHead(val);
            return;
        }

        Node* neww = new Node(val);
        Node* temp = head;
        // Move to node at (index - 1)
        for (int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }
        neww->next = temp->next;
        temp->next = neww;
        size++;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) {
            return;
        }

        if (index == 0) {
            Node* del = head;
            head = head->next;
            delete del;
            size--;
            return;
        }

        Node* temp = head;
        // Move to node at (index - 1)
        for (int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }

        Node* del = temp->next;
        temp->next = temp->next->next;
        delete del;
        size--;
    }
};