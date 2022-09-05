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
  Trip() { head = NULL; }

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
    Station *newNode;
    newNode = new Station;
    newNode->next = NULL;
    newNode->name = newItem;
    newNode->next = header;
    header-> next = newNode;
  }
  void insert_back(string newItem) {
    count += 1;
    Station *newNode = new Station();
    Station *temp = head;
    newNode->name = newItem;
    newNode->next = NULL;

    if (head == NULL) {
      newNode->next = head;
      head = newNode;
    } else {
      while (temp->next != NULL) {
        temp = temp->next;
      }
      temp->next = newNode;
    }
  }

  void remove_front() {
    /*
    WRITE YOUR CODE HERE
    */
  }
  void remove_back() {
    if (count == 0) {
      return;
    }
    count--;
    Station *prev_end = NULL;
    Station *end = head;
    if (head != NULL) {
      if (count >= 1) {
        while (end->next != NULL) {
          prev_end = end;
          end = end->next;
        }
        delete end;
        prev_end->next = NULL;
      } else {
        head = NULL;
      }
    }
  }

  // Station *visit(int nStep, string stepText) {
  //   cout << "";
  // }
};