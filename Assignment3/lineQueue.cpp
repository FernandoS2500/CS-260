#include <iostream>

class lineQueue {
public:
    // Node  to store elements in
    struct Node {
        int data;     // Data
        Node* next;   // Pointer to the next node
    };

    Node* front;     // Pointer to the front 
    Node* back;      // Pointer to the back
    int counter;       // keep track of elements 


    // start the queue
    lineQueue() {
        front = nullptr; // set to null for both
        back = nullptr;
        counter = 0;       // starts at zero
    }


    //adds an element to the back of the queue
    void enqueue(int value) {
        Node* newNode = new Node();  // new node
        newNode->data = value; // adds data
        newNode->next = nullptr; // sets pointer to null

        // sets whats the  pointer goes to next
        if (front == nullptr) {      // empty
            front = newNode;
        } else {
            back->next = newNode; // back
        }
        back = newNode;  
        counter++;     // adds to the count
    }

    // removes and returns the front element of the queue
    int dequeue() {  // what happens if it is empty
        if (front == nullptr) {
            std::cout << "Queue is empty." << std::endl;
            return -1; // Return an error value
        }

        Node* temp = front;  // points pointer to front
        int value = front->data; // gets data 
        front = front->next; // moves pointer over
        delete temp; // deletes
        counter--;   // lowers the count by one.

        //sets back to null when empty
        if (front == nullptr) {
            back = nullptr;
        }

        return value;
    }

    
    // Checks the number of elements in the queue
    int size() {
        return counter;
    }

    // looks at the front element 
    int peek() {
        // if empty return txt
        if (front == nullptr) {
            std::cout << "Queue is empty." << std::endl;
        }
        return front->data;
    }
};

// Test functions

void testenQueueSize() {
    // makes que list
    lineQueue testsize;
    // test 1  adds two times to que
    std::cout << "Testing enqueue and size" << std::endl;
    testsize.enqueue(1);
    testsize.enqueue(2);
    // test size funtion 
    std::cout << "Expected: 2, value: " << testsize.size() << std::endl;
    std::cout << std::endl;
}

void testPeek() {
    // makes que list
    lineQueue testpeek;
    // test 1  adds two times to que
    testpeek.enqueue(1);
    testpeek.enqueue(2);
    // tests the peek function
    std::cout << "Testing peek" << std::endl;
    std::cout << "Expected: 1, value : " << testpeek.peek() << std::endl;
    std::cout << std::endl;
}

void testDequeue() {
    // makes que list
    lineQueue testdequeue;
    // adds 1
    testdequeue.enqueue(1);
     // testing dequeue 
    std::cout << "Testing dequeue" << std::endl;
    std::cout << "Expected : 1, value : " << testdequeue.dequeue() << std::endl;
    // runes a second time to check if its empty
    std::cout << "Expected : is empty, value : " << testdequeue.dequeue() << std::endl;
    std::cout << std::endl;
}

// runs the tests for the functions
int main() {
    testenQueueSize();
    testPeek();
    testDequeue();
    return 0;
}
