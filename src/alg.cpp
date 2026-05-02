template <typename T>
class TPQueue {
public:
  struct Node {
    T val;
      Node* next;
      Node(const T& v) {
      val = v;
      next = nullptr;
      }
  };
  Node* head;
  TPQueue() {
  head = nullptr;
  }
  void push(const T& v) {
    Node* n = new Node(v);
      if (!head || v.prior > head->val.prior) {
        n->next = head;
        head = n;
      } else {
          Node* cur = head;
          while (cur->next && cur->next->val.prior >= v.prior) {
            cur = cur->next;
          }
          n->next = cur->next;
          cur->next = n;
        }
  }
  T pop() {
    T res = head->val;
    Node* old = head;
    head = head->next;
    delete old;
    return res;
  }
};
