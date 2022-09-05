#include<iostream>
class CharStack {
private:
  int top_s;
  char it[10];

public:
  CharStack() { // constructor
      top_s = -1;
  }

  void push(char new_item) {
    // std::cout<<"\nnew_item : "<<new_item<<"\n";
    /*if (!isEmpty()) {
      
    } else {*/
      top_s++;
      it[top_s] = new_item;
    // }
  }

  char pop() {
    if (isEmpty()) {
      return ' ';
    } else {
      char x = it[top_s];
      top_s--;
      return x;
    }
  }

  char top() {
    if (isEmpty()) {
      return ' ';
    } else {
      return it[top_s];
    }
  }

  bool isEmpty() {
    // if (top_s == -1) {
    //   return false;
    // } else {
    //   return true;
    // }
    return top_s==-1;
  }
};