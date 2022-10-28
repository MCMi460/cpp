#include <iostream>

struct chain {
  chain *last;
  int data;
  chain *next;
};

void push_back(chain *back, int value)
{
  chain *link = new chain();
  link->data = value;
  link->next = NULL;
  chain *iterator = back;
  while (iterator->next != NULL)
  {
    iterator = iterator->next;
  }
  link->last = iterator;
  iterator->next = link;
}

int main(int argc, char *argv[])
{
  chain *head = new chain();

  // Values assignment
  head->data = 1;

  // Pointers
  head->last = NULL;
  head->next = NULL;

  // Testing
  for (int i = 2; i <= 3; i++)
  {
    push_back(head, i); // Any point in the linked list can be entered as an argument here
  }

  // Iterate forwards using head
  chain *iterator = head;
  while (iterator->next != NULL)
  {
    std::cout << iterator->data << std::endl;
    iterator = iterator->next;
  }
  std::cout << iterator->data << std::endl;

  // And backwards, too!
  // Iterate forwards using head
  while (iterator->last != NULL)
  {
    std::cout << iterator->data << std::endl;
    iterator = iterator->last;
  }
  std::cout << iterator->data << std::endl;

  return 0;
}
