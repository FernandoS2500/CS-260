#include <iostream>
#include <string>

using namespace std;

// Node BST struture
struct Node {
    string sauce; // Hot sauce
    int SHU; // Scoville rating
    Node* front; // Pointer to front 
    Node* back; // Pointer to back 

     Node(string n, int s) {// default values
        sauce = n;
        SHU = s;
        front = nullptr;
        back = nullptr;
    }
};

class BST {
public:
    Node* root;

    BST() : root(nullptr) {}

    // places information in node
    void insert(Node*& node, const string& sauce, int SHU) {
       // creates new node when null
    if (node == nullptr) {
        node = new Node(sauce, SHU);
        return;
    }

   
    if (SHU <= node->SHU) { // checks and compares shu number, if its small it will place in front
        insert(node->front, sauce, SHU);
    } else { // back if not
        insert(node->back, sauce, SHU);
    }

    }


    //Finds the node with the smallest value
    Node* findSmallest(Node* node) {

        while (node->front != nullptr) { // loops through till it reaches the very front
        node = node->front; 
        }

        return node; // returns the smallest node
    }

    // removes hot sauce
    Node* remove(Node* node, int SHU) {
        // checks for empty node
        if (node == nullptr) {
        return node;
        }

        // tree search
        if (SHU < node->SHU) {
            //searchs the tree by going towards the front
            node->front = remove(node->front, SHU);

        } else if (SHU > node->SHU) {
            //search toward the back
            node->back = remove(node->back, SHU);

        } else {
            //  nodes with one only front side
            if (node->front == nullptr) {
                Node* temp = node->back;
                delete node;  // deletes
                return temp;

            // same as font but for back
            } else if (node->back == nullptr) {
                Node* temp = node->front;
                delete node; // deletes
                return temp;
            }

            // Node with  both front and back
            Node* temp = findSmallest(node->back); //finds smallest
            node->sauce = temp->sauce; //saves to temp
            node->SHU = temp->SHU; // saves to temp
            node->back = remove(node->back, temp->SHU);
        }
        return node;
    }
    // search function
    bool search(Node* node, const string& sauce, int& SHU) const {
        //checks if null
        if (node == nullptr){
            return false;

        } 

        // when it matches it assignes the shu value and returns 
        if (node->sauce == sauce) {
            SHU = node->SHU; // assigns value
            return true;
        }
        // the front of the tree
        if (sauce < node->sauce){
            
            return search(node->front, sauce, SHU);
        } 
        // the back of the tree
        return search(node->back, sauce, SHU);
    }

    void inOrderTraversal(Node* node) const {
        //checks if null
        if (node == nullptr){
            return;
        } 

        inOrderTraversal(node->front); // loops to it reach the end
        // prints the sauce and shu value
        cout << node->sauce << " (" << node->SHU << " SHU), ";

        inOrderTraversal(node->back); // loops on the back till it reachs the end.
    }

 

};
// All Test functions
void testBSTTraversal() {
    // startes by puting 10 hot sauces into tree
    BST bst;
    bst.insert(bst.root,"Sriracha", 2200); // meh
    bst.insert(bst.root,"Tabasco", 3500); //okay
    bst.insert(bst.root,"Cholula", 3600); // great
    bst.insert(bst.root,"Frank's RedHot", 450); // sucks
    bst.insert(bst.root,"Crystal", 800);  // n/a
    bst.insert(bst.root,"Valentina", 900); // okay
    bst.insert(bst.root,"Tapatío", 3000); // number one hot sauce
    bst.insert(bst.root,"El Yucateco", 11600); //n/a
    bst.insert(bst.root,"Louisiana", 450); //n/a
    bst.insert(bst.root,"Dave's Insanity Sauce", 180000); // no thanks

    // start by listing hot sauce in how they are traveld
    std::cout << "In-order traversal of hot sauces (sorted by SHU):\n";
    std::cout << std::endl;
    bst.inOrderTraversal(bst.root);
    std::cout << std::endl;
    std::cout << std::endl;

}

void testBSTSearch() {
    // startes by puting 10 hot sauces into tree
    BST bst;
    bst.insert(bst.root,"Sriracha", 2200); // meh
    bst.insert(bst.root,"Tabasco", 3500); //okay
    bst.insert(bst.root,"Cholula", 3600); // great
    bst.insert(bst.root,"Frank's RedHot", 450); // sucks
    bst.insert(bst.root,"Crystal", 800);  // n/a
    bst.insert(bst.root,"Valentina", 900); // okay
    bst.insert(bst.root,"Tapatío", 3000); // number one hot sauce
    bst.insert(bst.root,"El Yucateco", 11600); //n/a
    bst.insert(bst.root,"Louisiana", 450); //n/a
    bst.insert(bst.root,"Dave's Insanity Sauce", 180000); // no thanks

    
    // testing search function and the expected values returned
    int SHU;
    std::cout << "Search for 'Tabasco': " << (bst.search(bst.root,"Tabasco", SHU) ? "Found, SHU = " + to_string(SHU) : "Not Found") << endl;
    std::cout << std::endl;
    std::cout << "Search for 'Mega Sauce': " << (bst.search(bst.root,"Mega Sauce", SHU) ? "Found, SHU = " + to_string(SHU) : "Not Found") << endl;
    std::cout << std::endl;

   
}
void testBSTRemoval() {
    // startes by puting 10 hot sauces into tree
    BST bst;
    bst.insert(bst.root,"Sriracha", 2200); // meh
    bst.insert(bst.root,"Tabasco", 3500); //okay
    bst.insert(bst.root,"Cholula", 3600); // great
    bst.insert(bst.root,"Frank's RedHot", 450); // sucks
    bst.insert(bst.root,"Crystal", 800);  // n/a
    bst.insert(bst.root,"Valentina", 900); // okay
    bst.insert(bst.root,"Tapatío", 3000); // number one hot sauce
    bst.insert(bst.root,"El Yucateco", 11600); //n/a
    bst.insert(bst.root,"Louisiana", 450); //n/a
    bst.insert(bst.root,"Dave's Insanity Sauce", 180000); // no thanks

    
    // test removing hot sauce and checking if it in fact gone on high sauce so back
    std::cout << "Removing 'Tabasco'\n";
    std::cout << std::endl;
    bst.remove(bst.root,3500);
    std::cout << " after removal:\n";
    bst.inOrderTraversal(bst.root);
    std::cout << std::endl;
    std::cout << std::endl;
   
}
// runs test funtions
int main() {
    testBSTTraversal();
    testBSTSearch();
    testBSTRemoval();
    return 0;
}
