#include <iostream>

struct link {
  int data;
  link *next;
};

void push_back(link *back, int value)
{
  link *last = new link();
  last->data = value;
  last->next = NULL;
  link *iterator = back;
  while (iterator->next != NULL)
  {
    iterator = iterator->next;
  }
  iterator->next = last;
}

int main(int argc, char *argv[])
{
  link *head = new link();

  // Values assignment
  head->data = 1;

  // Pointers
  head->next = NULL;

  // Testing
  for (int i = 2; i <= 3; i++)
  {
    push_back(head, i); // Any point in the linked list can be entered as an argument here
  }

  link *iterator = head;
  while (iterator->next != NULL)
  {
    std::cout << iterator->data << std::endl;
    iterator = iterator->next;
  }
  std::cout << iterator->data << std::endl;

  return 0;
}
