#include <iostream> 
#include <bits/stdc++.h>
 
using namespace std;
 
class Node {
  public:
  int value;
  Node* next;
  
  Node(int value) {
    this->value = value;
    this->next = NULL;
  }
};

bool isEmpty(Node* head) {
  return head == NULL;
}

class MinStack {
public:
  Node* head;
  
  MinStack() {
    this->head = NULL;
  }

  void push(int value) {
    Node* node = new Node(value);
    if (isEmpty(this->head)) {
      this->head = node;
    } else {
      Node* tmp = head;
      head = node;
      head->next = tmp;
    }
  }

  void pop() {
    if (!isEmpty(this->head))
      this->head = this->head->next;
    return;
  }

  int top() {
    if(!isEmpty(this->head))
      return head->value;
    return -1;
  }

  int getMin() {
    int minVal = numeric_limits<int>::max();
    Node* currPos = this->head;
    while(currPos != NULL) {
      minVal = min(minVal, currPos->value);
      currPos = currPos->next;
    }
    return minVal;
  }
};