#include "HW01.cpp"
#include <iostream>
using namespace std;

int main() {
  CardList L;
  L.insert_back("eieie");
  L.pop_back();
  L.printCardList();
  Card *curr = L.head;
  while (curr != NULL) {
    cout << curr->name << endl;
    curr = curr->next;
  }
  return 0;
}