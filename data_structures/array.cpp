#include <iostream>

struct chain { // Linked list data structure
  chain* last;
  int data;
  chain* next;
};

class Array {
  public:
    // Methods
    void push_back(int);
    void pop(int);
    void erase(int);
    int* convert();
    chain* index(int);

    // Variables
    int length;

    Array(); // Constructor
  private:
    chain* head;
};

Array::Array() {
  head = new chain();
  head->data = 0;
  head->last = NULL;
  head->next = NULL;
  length = 1;
}

void Array::push_back(int value) {
  chain* link = new chain();
  link->next = NULL;
  link->data = value;
  // Iterate through list
  chain* iterator = head;
  while (iterator->next != NULL)
  {
    iterator = iterator->next;
  }
  link->last = iterator;
  iterator->next = link;
  length++;
}

chain* Array::index(int indice) {
  if (indice < 0 || indice > length - 1)
  {
    throw std::out_of_range("index value is out of range");
  }
  chain* iterator = head;
  for (int i = 0; i < indice; i++)
  {
    iterator = iterator->next;
  }
  return iterator;
}

void Array::pop(int indice) {
  if (length < 2)
  {
    throw std::length_error("cannot pop head");
  }
  chain* iterator = index(indice);
  if (iterator->last != NULL && iterator->next != NULL) { // Middle of list
    iterator->last->next = iterator->next;
    iterator->next->last = iterator->last;
  } else if (iterator->next == NULL) { // End of list
    iterator->last->next = NULL;
  }  else { // Beginning of list
    iterator->next->last = NULL;
    head = iterator->next;
  }
  delete iterator;
}

void Array::erase(int value) {
  int i = 0;
  for (chain* iterator = head; iterator != NULL && length > 1; iterator = iterator->next)
  {
    if (iterator->data == value)
    {
      pop(i);
      i--;
    }
    i++;
  }
}

int* Array::convert() {
  int* list = new int[length];
  int i = 0;
  for (chain* iterator = index(0); iterator != NULL; iterator = iterator->next)
  {
    list[i] = iterator->data;
    i++;
  }
  return list;
}

int main(int argc, const char* argv[]) {
  Array my_list;

  std::cout << "As a linked list:" << std::endl;
  for (chain* iterator = my_list.index(0); iterator != NULL; iterator = iterator->next)
  {
    std::cout << iterator->data << std::endl;
  }

  std::cout << "As an array:" << std::endl;
  int* array = my_list.convert();
  for (int i = 0; i < sizeof(array)/sizeof(int*); i++)
  {
    std::cout << array[i] << std::endl;
  }
  delete[] array;

  return 0;
}
