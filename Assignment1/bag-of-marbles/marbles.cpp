#include <iostream>
#include <string>
using namespace std;

//  object class/contructor for marble
class Marble {
public:
    string color;
    string size;

    Marble(string colo = "", string siz = "") {
        //  assign the values
        color = colo;
        size = siz;
    }
};

class BagOfMarbles {
public:
    // array for bag of marbles, hard code cap
    Marble marbles[10];
    int count;
    
    //function for adding marbles
    void addMarble() {
        //checks if more marbles can be added
        if (count >= 10) {
            cout << "Bag is full." << endl;
            return;
        }
        // ask for user input
        string color, size;
        cout << "Enter marble color: ";
        cin >> color;
        cout << "Enter marble size: ";
        cin >> size;
        // save  input to array, auto adds count up
        marbles[count++] = Marble(color, size);
        cout << "Marble added: Color = " << color << ", Size = " << size << endl;
    }
    // remove marvel function
    void removeMarble() {
        // checks if bag is empty 
        if (count <= 0) {
            cout << "Bag is empty." << endl;
            return;
        }
        // remove the last item  put in bag, kinda still there till it get over writen
        count--;
         // maybe add choice option later
         //print for whats being removed
        cout << "Marble removed: Color = " << marbles[count].color << ", Size = " << marbles[count].size << endl;
    }
    // list all marble functions
    void showMarbles() {
         // checks if bag is empty 
        if (count == 0) {
            cout << "The bag is empty." << endl;
            return;
        }
        // loops through the marbles in bag
        for (int i = 0; i < count; i++) {
            cout << "Marble " << i+1 << ": Color = " << marbles[i].color << ", Size = " << marbles[i].size << endl;
        }
    }
    // test unit
    void testMarbles(){

        BagOfMarbles testbag;
        // test #1
        // Simulate adding more than max marbles
        count = 10;
        testbag.addMarble(); 
        count = 0;
        
        // test #2

    }

};
// main loop
int main() {
    // create object
    BagOfMarbles bag;
    char choice;

    // menu for all choices.
    while (true) {
        cout << "\nChoose an action:\n"
             << "1. Add a marble\n"
             << "2. Remove a marble\n"
             << "3. Show all marbles\n"
             << "4. Exit\n"
             << "5. Test Code\n"
             << "Enter your choice (1-5): ";
        cin >> choice;
        // active function based of user choice
        switch (choice) {
            case '1':
                bag.addMarble();
                break;
            case '2':
                bag.removeMarble();
                break;
            case '3':
                bag.showMarbles();
                break;
            case '4':
                cout << "Good Bye." << endl;
                return 0;
            case '5':
                bag.testMarbles();
                break;
            default:
                cout << "Please enter 1, 2, 3, 4, 5" << endl;
                break;
        }
    }

    return 0;
}
