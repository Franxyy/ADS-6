// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
 public:
 TPQueue() : head(nullptr) {}

 void push(const T& v) {
   Node* n = new Node(v);
   if (!head || v.prior > head->val.prior) {
     n->next = head;
     head = n;
   } else {
     Node* cur = head;
     while (cur->next && cur->next->val.prior >= v.prior)
       cur = cur->next;
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
 private:
  struct Node {
    T val;
    Node* next;
    explicit Node(const T& v) : val(v), next(nullptr) {}
  };
  Node* head;
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
