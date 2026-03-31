#include <vector>

class LinkedList {
private:
  struct Node {
    int val;
    Node *next;

    Node(int value) : val(value), next(nullptr) {}
  };

  Node *head;
  Node *tail;

public:
  LinkedList() : head(nullptr), tail(nullptr) {}

  ~LinkedList() {
    Node *curr = head;
    while (curr != nullptr) {
      Node *next = curr->next;
      delete curr;
      curr = next;
    }
  }

  int get(int index) {
    if (index < 0) {
      return -1;
    }

    Node *curr = head;
    for (int i = 0; i < index; i++) {
      if (curr == nullptr) {
        return -1;
      }
      curr = curr->next;
    }

    if (curr == nullptr) {
      return -1;
    }

    return curr->val;
  }

  void insertHead(int val) {
    Node *newNode = new Node(val);
    newNode->next = head;
    head = newNode;

    if (tail == nullptr) {
      tail = newNode;
    }
  }

  void insertTail(int val) {
    Node *newNode = new Node(val);

    if (tail == nullptr) {
      head = newNode;
      tail = newNode;
      return;
    }

    tail->next = newNode;
    tail = newNode;
  }

  bool remove(int index) {
    if (index < 0 || head == nullptr) {
      return false;
    }

    if (index == 0) {
      Node *toRemove = head;
      head = head->next;
      if (head == nullptr) {
        tail = nullptr;
      }
      delete toRemove;
      return true;
    }

    Node *prev = head;
    for (int i = 0; i < index - 1; i++) {
      if (prev == nullptr || prev->next == nullptr) {
        return false;
      }
      prev = prev->next;
    }

    Node *toRemove = prev->next;
    if (toRemove == nullptr) {
      return false;
    }

    prev->next = toRemove->next;
    if (toRemove == tail) {
      tail = prev;
    }

    delete toRemove;
    return true;
  }

  std::vector<int> getValues() {
    std::vector<int> values;
    Node *curr = head;

    while (curr != nullptr) {
      values.push_back(curr->val);
      curr = curr->next;
    }

    return values;
  }
};
