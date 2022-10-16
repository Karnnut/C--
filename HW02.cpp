#include "station.cpp"
#include <iostream>
#include <string>
using namespace std;

class Trip {
  Station *head;

public:
  Station *header;
  Station *trailer;
  int count;
  Trip() {
    header = new Station;
    trailer = new Station;

    header->prev = NULL;
    header->next = trailer;
    trailer->prev = header;
    trailer->next = NULL;
  }

  void printList() {

    cout << "[ ";
    Station *ptr = header->next;
    while (ptr != trailer) {
      cout << ptr->name << " ";
      ptr = ptr->next;
    }
    cout << "]\n";
  }

  void insert_front(string newItem) {
    count++;
    Station *newNode = new Station;
    newNode->prev = header;
    newNode->next = header->next;
    header->next->prev = newNode;
    //At new Item to linked list
    header->next = newNode;
    newNode->name = newItem;
  }

  void insert_back(string newItem) {
    count--;
    Station *newNode = new Station();
    newNode->next = trailer;
    newNode->prev = trailer->prev;
    trailer->prev->next = newNode;
    trailer->prev = newNode;
    newNode->name = newItem;
  }

  void remove_front() {
    if (count == 0) {
      return;
    }
    Station *cur = header->next; 
    header -> next = cur -> next;
    delete cur;
    count--;
  }
  void remove_back() {
    if (count == 0) {
      return;
    }
    Station *cur = trailer->prev;
    trailer->prev->prev->next = trailer;
    trailer->prev = trailer->prev->prev;
    delete cur;
    count--;
  }

  Station *visit(int nStep, string stepText) {
    Station *cur = header->next;

    for (int i = 0; i < nStep; i++) {
      if (stepText[i] == 'R') {
        if (cur->next == trailer) {
          continue;
        }
        cur = cur->next;
      } else if (stepText[i] == 'L') {
        if (cur->prev == header) {
          continue;
        }
        cur = cur->prev;
      }
    }
    return cur;
  }
};