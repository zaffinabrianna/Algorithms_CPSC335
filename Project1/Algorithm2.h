// Suanna Shih
// CPSC 335
// Professor Sugandha Bhandari

#pragma once
#include <iostream>
using namespace std;

// singly linked list
class singly_list
{
public:

  // a basic node
  struct node
  {
    int data;
    node *next; // next pointer
  };

  // insert function, for reverse function we only need insert at head & null
  void insert(int value)
  {
    node *n = new node;
    n->data = value;
    //insert at null
    if (head == nullptr && tail == nullptr)
    {
      n->next = nullptr;
      head = n;
      tail = n;

    }
    else  //insert at head
    {
      n->next = head; // new node's next to old head
      head = n;       // set head

    }
  }

  //reverse the list, read the data from each node and constantly insert at head
  singly_list reverse(){
    node* a = head;
    singly_list result;
    while (a != nullptr)
    {
      result.insert(a->data);
      a = a->next;
    }
    return result;
  }


  // add function
  singly_list add(singly_list list1, singly_list list2, singly_list result){
    node* a = list1.head;
    node *b = list2.head;
    int carry_on = 0;    //might be 1 or 2, 3?
    while (a != nullptr && b != nullptr)
    {
      int num = a->data + b->data;
      if(carry_on > 0 ){
        result.insert(num % 10 + carry_on);
      }
      else
      {
        result.insert(num % 10);    //last digit
      }
      carry_on = num / 10;
      a = a->next;
      b = b->next;
    }
    result.insert(carry_on);
    return result;
  }

  void print()
  {
    node *n = head;
    while (n != nullptr)
    {
      cout << n->data << " "; //space is for tracing, we can also use arrow
      n = n->next;
    }
    cout << endl;
  }

private:
  node* head = nullptr; // head pointer
  node* tail = nullptr; // tail pointer
};
