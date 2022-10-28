# Linked List

*I wrote this for a friend.*

Basically, a structure is like this:
```cpp
struct chain {
  chain *last;
  int data;
  chain *next;
};
```
It's a custom data type that will store the things you give it. `last` and `next` are both pointers towards other `chain` objects.  
This is allocating memory and creating a new `chain` object and putting the pointer into the variable known as `head`.
```cpp
chain *head = new chain();
```
We assign its stored integer value which is the thing that you kind of want to be looking for (if you want an array of strings, you'd do strings. In this case, I want a linked list of integers going from 1 to 3), then we set the `last` and `next` values to `NULL`, so basically no pointer.
```cpp
// Values assignment
head->data = 1;

// Pointers
head->last = NULL;
head->next = NULL;
```
Now, we want to add something to the end of our list.  
I'm using a function named `push_back` that will essentially just add your value to the end of the list.
```cpp
// Testing
for (int i = 2; i <= 3; i++)
{
  push_back(head, i); // Any point in the linked list can be entered as an argument here
}
```
In this case, it is adding the numbers `2` and `3` since i already added `1` when i created `head`.  
Okay, so how does `push_back` work?  
Glad you asked.
```cpp
void push_back(chain *back, int value)
```
First, as you can see above, we take a `chain` *pointer*. Only a pointer to an object. This means that `head` is a viable pointer. Then, we take the value that we want to add to our linked list.  
Now, we create our new "link" in our "chain" (HAHHAHAHAHAHAA)
```cpp
chain *link = new chain();
link->data = value;
link->next = NULL;
```
By setting `next` to `NULL`, it is therefore the last element in our list. That is our goal because we are pushing `push_back` (BACK) (HAHAHAHAHHAHA)  
Anyways, now that we've made `link` to add to our `chain`, we're going to make sure that the last element of `chain` points to our new link.  
We do that with this
```cpp
chain *iterator = back;
while (iterator->next != NULL)
{
  iterator = iterator->next;
}
```
Basically, we create a BS variable and use it to run through all of the `link`s in our `chain` until we find one that does not have a pointer to the next `link` in the `chain`. If there are no more `next`, then that must mean that we've found the end of the chain.  
Then, we change our new `link`'s `last` pointer to refer to the end of the chain, and we set the end of the chain's `next` pointer to point to our new end of the chain, which is `link`.
```cpp
link->last = iterator;
iterator->next = link;
```
Therefore, a linked list that was previously `1 2` and our value `3` become affixed to each other via our crappy appending and now the entire `chain` is `1 2 3`.  
Now, we can read it in a very similar way.  
We're going to `while` loop until we find the end of chain, and as we go through it, we send to the console the value's, er, well, *value*.
```cpp
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
```
The reason why there are `std::cout`s hanging off the ends is because it will end the `while` loop the immediate moment there is a `NULL` at `next`, meaning we do not get the end of chain's value.
