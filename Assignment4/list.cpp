#include <iostream>

class List {
private:
    //Node structure for the List class
    struct Node {
        int data;     // Data 
        Node* next;   // Pointer to the next node
    };

    Node* head;     // Pointer to the head of the list
    int count;      // keep track of elements 

public:
    // start of the list
    List() {
        head = nullptr;  // Set head pointer to null
        count = 0;       // set count to zero
    }

  
    // Add function that lets you pick location in list
    void add(int value, int position) {  // needs data and location
        if (position < 0) { // checks if the position is in range //less then zero
            throw std::out_of_range("position out of range");
        }
        if (position > count) { // checks if the position is in range // greater than count
            throw std::out_of_range("position out of range");
        }

        Node* newNode = new Node();  //  new node
        newNode->data = value;       // Sets the dat in node.

        // sets postion at front of list
        if (position == 0) {
            newNode->next = head;    //  points to current head
            head = newNode; // becomes new head
        } else {
            Node* current = head;
            // loops through the list to the point to just before you want it
            for (int i = 0; i < position - 1; ++i) {
                // this makes the  node poin to the next in the list
                current = current->next;
            }

            newNode->next = current->next; 
            current->next = newNode;  // points to new newnode
        }

        count++;  // adds one to the count
    }

    // Function to remove an element at any postion
    // very similar to add function
    int remove(int position) {
        if (position < 0) { // checks if the position is in range //less then zero
            throw std::out_of_range("position out of range");
        }
        if (position > count) { // checks if the position is in range // greater than count
            throw std::out_of_range("position out of range");
        }

        Node* temp; // pointer for node to be deleted
        int value; // for data in node to be deleted

        if (position == 0) {
            temp = head; // saves
            value = head->data; // saves data
            head = head->next; // updates head pointer to  next node
        } else {
            Node* current = head;
            // loops through the list to the point to just before you want it
            for (int i = 0; i < position - 1; ++i) {
                current = current->next;
            }
            temp = current->next;  // saves the node data etc
            value = temp->data;
            current->next = temp->next;
        }

        delete temp;  // Deletes the node
        count--;      // lowers count

        return value; // Returns the removed node value
    }

    // gets the value at a given position
    int get(int position) {
        if (position < 0) { // checks if the position is in range //less then zero
            throw std::out_of_range("position out of range");
        }
        if (position > count) { // checks if the position is in range // greater than count
            throw std::out_of_range("position out of range");
        }

        Node* current = head; // places pointer at head of ist
        // loops through the list till it get to right before you want it.
        for (int i = 0; i < position; ++i) { 
            current = current->next;
        }

        return current->data;  // Return the value
    }

    // Function to print the current list
    void print() {
        Node* current = head;
        // checks that it isnt empty first
        while (current != nullptr) {
            // runs through the whole list and prints it each time
            std::cout << current->data << " , ";
            //moves pointers to next in the list
            current = current->next;
        }
        // to  tell us when its the end
        std::cout << "end" << std::endl;
    }
};

// All Test functions
void testList() {
    List list;

    
    //adds 3 items to the list
    list.add(1, 0);
    list.add(2, 1);
    //should replace 2 
    list.add(3, 1);

    // Test add function
    std::cout << "Testing add function:\n";
    std::cout << "Expected list: 1 , 3 , 2 , end, Actual list: ";
    list.print();
    std::cout << std::endl;

    // Test get function
    std::cout << "Testing get function:\n";
    //checks all 3 positions
    std::cout << "Expected get(0): 1, Actual get(0): " << list.get(0) << std::endl;
    std::cout << "Expected get(1): 3, Actual get(1): " << list.get(1) << std::endl;
    std::cout << "Expected get(2): 2, Actual get(2): " << list.get(2) << std::endl;
    std::cout << std::endl;

    // Test remove function
    //removes postion 1 
    std::cout << "Testing remove function:\n";
    std::cout << "Expected remove(1): 3, Actual remove(1): " << list.remove(1) << std::endl;
    std::cout << "Expected list after remove: 1 , 2, end, Actual list: ";
    list.print();
    std::cout << std::endl;

    // exception handling less than 0
    // try catch
    std::cout << "Testing exception handling for get:\n";
    try {
        list.get(-1);
    } catch (const std::out_of_range& e) {
        std::cout << "Caught expected exception for get(-1): " << e.what() << std::endl;
    }
    std::cout << std::endl;

    // longer than list
    std::cout << "Testing exception handling for remove:\n";
    try {
        list.remove(10);
    } catch (const std::out_of_range& e) {
        std::cout << "Caught expected exception for remove(10): " << e.what() << std::endl;
    }
    std::cout << std::endl;
   
}

// runs test funtions
int main() {
    testList();
    return 0;
}
