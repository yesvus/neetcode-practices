#include <vector>

class LinkedList {
private:
   struct Node {
    int val;
    Node* next;
    Node(int v) : val(v), next(nullptr) {}
   };

    Node* head; 
    Node* tail;

public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    int get(int index) {
        Node* curr = head;

        // check if the list is empty

        if (head == nullptr || index < 0) {
            return -1;
        }

        int i = 0;
        while (i != index) {
            if (curr != nullptr) {
                curr = curr->next;
                i++;
            } else {
                return -1;
            }
        }
        if (curr == nullptr) {
            return -1;
        }
        else {
            return curr->val;
        }
    }

    void insertHead(int val) {
        Node* newNode = new Node(val);
        
        if (head == nullptr) {
            tail = newNode;
        }

        newNode->next = head;
        head = newNode;
        
    }
    
    void insertTail(int val) {
        Node* newNode = new Node(val);

        if (head == nullptr) {
            head = newNode;
        } else {
            tail->next = newNode;
        }
        newNode->next = nullptr;
        tail = newNode;
    }

    bool remove(int index) {
        
        // if the list empty or index is negative
        if (head == nullptr || index < 0) {
            return false;
        }

        // if the head asked
        if (index == 0) {
            Node* toBeRemoved = head;
            head = head->next;
            
            if (head == nullptr) {
                tail = nullptr;
            }

            delete toBeRemoved;
            return true;
        }
        // when toBeRemoved on the middle condition
        else {
            int i = 0;
            Node* curr = head;

            // catch the node before the toBeRemoved node
            while (i < (index - 1)) {
                if (curr->next == nullptr) {
                    return false;
                }
                curr = curr->next;
                i++;
            }

            // if trying to delete the last element
            if (curr->next != nullptr && curr->next->next == nullptr) {
                delete curr->next;
                curr->next = nullptr;
                tail = curr;
                return true;
            }
            else if (curr->next == nullptr) {
                return false;
            }
            else {
                Node* toBeRemoved = curr->next;
                curr->next = curr->next->next;
                delete toBeRemoved;
                return true;
            }
        }
        return false;
    }

    std::vector<int> getValues() {
        std::vector<int> arr;
        Node* curr = head;

        while(curr != nullptr) {
            arr.push_back(curr->val);
            curr = curr->next;
        }

        return arr;
    }
};
