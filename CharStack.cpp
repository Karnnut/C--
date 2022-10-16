class CharStack {

public:
  char it[10];
  int top;
  CharStack() { // constructor
    int top = -1;
  }

  void push(char new_item) {
    if (isEmpty()) {
      top++;
      it[top] = new_item;
    } else {
      top++;
      it[top] = new_item;
    }
  }

  char pop() {
    if (isEmpty()) {
      return false;
    } else {
      top--;
      return it[top - 1];
    }
  }

  char top() {
    if (isEmpty()) {
      return false;
    } else {
      return it[top];
    }
  }

  bool isEmpty() {
    if (top == -1) {
      return false;
    } else {
      return true;
    }
  }
};