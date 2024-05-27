#include <iostream>

class Queue {
private:
    // Node  to store elements in
    struct Node {
        int data;     // Data
        Node* next;   // Pointer to the next node
    };

    Node* front;     // Pointer to the front 
    Node* back;      // Pointer to the back
    int count;       // keep track of elements 

public:
    // start the queue
    Queue() {
        front = nullptr; // set to null for both
        back = nullptr;
        count = 0;       // starts at zero
    }


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

    // checks if the queue is empty
    bool isEmpty() {
        return front == nullptr; // does this by checking if front is null
    }

    // Checks the number of elements in the queue
    int size() {
        return count;
    }

    // looks at the front element 
    int peek() {
        // if empty return txt
        if (isEmpty()) {
            std::cout << "Queue is empty." << std::endl;
            return -1; // Return an error value
        }
        return front->data;
    }
};

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

// runs the tests for the functions
int main() {
    testQueue();
    return 0;
}
