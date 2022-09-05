#include "card.cpp"
#include <iostream>
#include <string>

using namespace std;

class CardList {

public:
  Card *head;
  int count = 0;

  CardList() { head = NULL; }
  void pop_back() {
    count--;
    if (head != NULL) {
      Card *end = head;
      Card *prev_end;
      while (end->next != NULL) {
        prev_end = end;
        end = end->next;
      }
      prev_end->next = 0;
      delete end;
    }
  }

  void insert_back(string newItem) {
    count += 1;
    Card *newNode = new Card();
    newNode->name = newItem;
    newNode->next = NULL;
    if (head == NULL) {
      newNode->next = head;
      head = newNode;
    } else {
      Card *temp = head;
      while (temp->next != NULL)
        temp = temp->next;
      temp->next = newNode;
    }
  }

  void shuffle(int pos) { // 1<=pos<=size-1
    Card *front = head;
    Card *back = head;
    Card *back2 = head;
    int size = count;

    if (pos > 0 && pos <= size - 1 && head != NULL) {
      for (int i = 1; i < pos; i++) {
        front = front->next;
      }
      head = front->next;
      Card *res = head;
      while (res->next != NULL) {
        res = res->next;
      }
      for (int i = 1; i < pos; i++) {
        back = back->next;
      }
      back->next = NULL;
      res->next = back2;
    } else {
    }
  }

  void printCardList() {
    /*
     DO NOT DELETE OR EDIT
     */
    cout << "[ ";
    Card *ptr = head;
    while (ptr != NULL) {
      cout << ptr->name << " ";
      ptr = ptr->next;
    }
    cout << "]\n";
  }
};