#include <iostream>
#include <vector>

#include "Algorithm1.h"
#include "Algorithm2.h"
using namespace std;

int main() {
    int choice;
    cout << "Which Algorithm do you want to test? Enter the number. (1 or 2)" << endl;
    cin >> choice;

    switch (choice) {
        //Algorithm 1 test cases
    case 1: {
        cout << "---Test 1---" << endl;
        NewPriorityQueue pq("priority");
        pq.push(10, 1);
        pq.push(20, 2);
        pq.push(30, 3); // Same priority test
        pq.push(40, 3); // Same priority test
        pq.push(50);    // No priority specified test

        // Test loop
        while (!pq.is_empty())
        {
            int priorityNum = 1;
            cout << "Priority #" << priorityNum << ": " << pq.pop() << endl;
            priorityNum++;
        }

        cout << endl;

        // Stack Mode
        NewPriorityQueue stack_("stack");
        stack_.push(10);
        stack_.push(20);
        stack_.push(30);

        // Test loop
        while (!stack_.is_empty())
        {
            int priorityNum = 1;
            cout << "FILO Order #" << priorityNum << ": " << stack_.pop() << endl;
            priorityNum++;
        }

        cout << endl;

        // Queue Mode
        NewPriorityQueue queue_("queue");
        queue_.push(10);
        queue_.push(20);
        queue_.push(30);

        // Test loop
        while (!queue_.is_empty())
        {
            int priorityNum = 1;
            cout << "FIFO Order #" << priorityNum << ": " << queue_.pop() << endl;
            priorityNum++;
        }
    }
          break;

          //Algorithm 2 Test Cases
    case 2: {
        int input;
        int a, b;
        vector<int> list1 = { 2, 4, 3 };
        vector<int> list2 = { 5, 6, 9 };
        cout << "---Test 2---" << endl;
        if (list1.size() != list2.size()) {
            cout << "Both lists have to be in the same size, ending program now." << endl;
            exit(0);
        }
        singly_list temp;
        singly_list temp2;
        singly_list result;
        for (int i = 0; i < list1.size(); ++i)
        {
            temp.insert(list1.at(i));
        }
        for (int i = 0; i < list2.size(); ++i)
        {
            temp2.insert(list2.at(i));
        }

        cout << "List 1: ";
        temp.print();
        cout << "List 2: ";
        temp2.print();

        result = result.add(temp.reverse(), temp2.reverse(), result);
        cout << "Result is: " << endl;
        result.reverse().print();
    }
          break;
    }
}
