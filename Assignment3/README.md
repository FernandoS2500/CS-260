Assignment 3 (Linked Queue):

Based on what we know about linked lists, stacks, and queues, design a linked queue (a queue using a linked-list to store the data in the structure)

Design, implement, and test a Queue data structure that:

uses a linked-list to store values in the queue

has an enqueue method that will appropriately add a value to the back of the queue as an appropriate element

has a dequeue method that will appropriately remove an element from the front of the queue and return its value

Optionally has a peek method that returns the value at the front of the queue without removing it
Bonus if you also create an array based Queue!

Tests: Be sure to include at least one test for each piece of functionality that should verify that your code is working!

Be sure to commit changes regularly to your git repo

Once you have implemented and tested your code, add to the README file what line(s) of code or inputs and outputs show your work meeting each of the above requirements (or better, include a small screen snip of where it meets the requirement!).

Remember to submit a link to this project in Moodle to remind us to grade it!

Note: This assignment is partly to get you some practice with basic pointers if you have not used them much, to get you thinking about dynamically sizing containers, and to think about what might be efficient and what might be able to be improved.

// What is being done in Assignment 3

// Design information from assigment 2  , template start for Assignemt 3

2:Based on what we know about linked lists, stacks, and queues, design a queue data structure:

    2.1What functions are we likely to need for a queue to function like the one discussed in class?
    A que is first in first out.

    Add function: A function to add a new item to the end of the line.

    remove function: A function that will remove the item at is at the front of the line.

    empty furntion:  A function that will check if the que is empty.

    number function: A function that keeps track of the size of the que so it is know what the last item is before 
    a new one is added or removed.


    2.2What values will we need to know about the structure for our queue to function properly?

    Count:  integer for que size

    front object: a value that has the last object in and its number place?

    Last object: A value that has what object is in the front of the line?

    probably more but these are the obvious ones.


// changes  

add function  renamed to enqueue

remove function renamed to dequeue

empty function stays empty function

added peak function to see values

number function renamed to size    // they should now better follow naming conventions.

// requirements for assigment 3 

uses a linked-list to store values in the queue
 This piece code acts a list for me to store the data in
 // Node  to store elements in
    struct Node {
        int data;     // Data
        Node* next;   // Pointer to the next node
    };

has an enqueue method that will appropriately add a value to the back of the queue as an appropriate element

//adds an element to the back of the queue
    void enqueue(int value) {
        Node* newNode = new Node();  // new node
        newNode->data = value; // adds data
        newNode->next = nullptr; // sets pointer to null

        // sets whats the  pointer goes to next
        if (isEmpty()) {      // empty
            front = newNode;
        } else {
            back->next = newNode; // back
        }
        back = newNode;  
        count++;     // adds to the count
    }


has a dequeue method that will appropriately remove an element from the front of the queue and return its value

// removes and returns the front element of the queue
    int dequeue() {  // what happens if it is empty
        if (isEmpty()) {
            std::cout << "Queue is empty." << std::endl;
            return -1; // Return an error value
        }

        Node* temp = front;  // points pointer to front
        int value = front->data; // gets data 
        front = front->next; // moves pointer over
        delete temp; // deletes
        count--;   // lowers the count by one.

        //sets back to null when empty
        if (isEmpty()) {
            back = nullptr;
        }

        return value;
    }

Optionally has a peek method that returns the value at the front of the queue without removing it
Bonus if you also create an array based Queue!

  // looks at the front element 
    int peek() {
        // if empty return txt
        if (isEmpty()) {
            std::cout << "Queue is empty." << std::endl;
            return -1; // Return an error value
        }
        return front->data;
    }

Tests: Be sure to include at least one test for each piece of functionality that should verify that your code is working!

// all test code for each functions and test results that showed that it worked.

// Test functions
void testQueue() {
    // makes que list
    Queue q;
    // test 1  adds two times to que
    std::cout << "Testing enqueue and size..." << std::endl;
    q.enqueue(1);
    q.enqueue(2);
    // test size funtion 
    std::cout << "Expected size: 2, Actual size: " << q.size() << std::endl;
    // tests the peek function
    std::cout << "Testing peek..." << std::endl;
    std::cout << "Expected front: 1, Actual front: " << q.peek() << std::endl;
    // testing dequeue 
    std::cout << "Testing dequeue..." << std::endl;
    std::cout << "Expected dequeue: 1, Actual dequeue: " << q.dequeue() << std::endl;
    std::cout << "Expected size: 1, Actual size: " << q.size() << std::endl;
    // removes a second one for tesing
    std::cout << "Expected dequeue: 2, Actual dequeue: " << q.dequeue() << std::endl;
    std::cout << "Expected size: 0, Actual size: " << q.size() << std::endl;
    // checks if its empty
    std::cout << "Expected isEmpty: 1, Actual isEmpty: " << q.isEmpty() << std::endl;

    std::cout << "Testing dequeue on empty queue..." << std::endl;
    q.dequeue();
}


//results 


PS C:\Users\ferna\Documents\CS-260\Assignment3>  & 'c:\Users\ferna\.vscode\extensions\ms-vscode.cpptools-1.20.5-win32-x64\debugAdapters\bin\WindowsDebugLauncher.exe' '--stdin=Microsoft-MIEngine-In-jf35ue2u.5i2' '--stdout=Microsoft-MIEngine-Out-yyo3mk2m.nbq' '--stderr=Microsoft-MIEngine-Error-nuihqfmy.r51' '--pid=Microsoft-MIEngine-Pid-qygmpjh1.4os' '--dbgExe=C:\msys64\ucrt64\bin\gdb.exe' '--interpreter=mi'
Testing enqueue and size...
Expected size: 2, Actual size: 2
Testing peek...
Expected front: 1, Actual front: 1
Testing dequeue...
Expected dequeue: 1, Actual dequeue: 1
Expected size: 1, Actual size: 1
Expected dequeue: 2, Actual dequeue: 2
Expected size: 0, Actual size: 0
Expected isEmpty: 1, Actual isEmpty: 1
Testing dequeue on empty queue...
Queue is empty.










   




