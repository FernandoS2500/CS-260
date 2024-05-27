#include <iostream>
#include <string>

using namespace std;

 //Node structure for the List class
struct Node {
string data;     // Data 
Node* next;   // Pointer to the next node
 };


class List {
private:
    Node* head;   // Pointer to the head of the list

public:
    List() {
        head = nullptr;
    }

    // Arranges the list in Alpabetical order
    void arrangeABC(const string& data) {
        // Creates a new node and sets pointer to null
        Node* new_node = new Node;
        new_node->data = data;
        new_node->next = nullptr;

        // when list is empty and we need to set that node to head
        if (head == nullptr) {
            head = new_node;
        } else {
            // compares the ascii valus
            // If data is less than head, insert at the beginning of the list
            if (data < head->data) {
                new_node->next = head;
                head = new_node;
            } else {
                // Finds the node where node->next->data, 
                Node* current = head;
                // first checks that is not past the list and then checks current ascii value with new  to order
                while (current->next != nullptr && current->next->data < data) {
                    current = current->next;
                }

                // Insert the new node at the position
                new_node->next = current->next;
                current->next = new_node;
            }
        }
    }

    // Removes element from the array
    // bool for testing
    bool remove(const string& data) {
        // checks if it is empty first
        if (head == nullptr) {
            return false; // List is empty
        }

        // If the node to be removed is the head
        if (head->data == data) { //If data is the head it  saves to tempary pointer.
            Node* temp = head;
            head = head->next; // pointers to next node
            delete temp; // deletes 
            return true;
        }

        //any node except for head
        Node* current = head;  // sets pointer to head
        while (current->next != nullptr && current->next->data != data) {
            current = current->next;    // loops through and moves the pointer each time
        }
        // if can find what I want to remove
        if (current->next == nullptr) {
            return false; // Not found
        }

        // Removes the node once it has been found
        Node* temp = current->next;  
        current->next = current->next->next;
        delete temp; // deletes
        return true;
    }


// Function to print the current list
    void print() {
        Node* current = head;
        // checks that it isnt empty first
        while (current != nullptr) {
            // runs through the whole list and prints it each time
            std::cout << current->data << ", ";
            //moves pointers to next in the list
            current = current->next;
        }
        // to  tell us when its the end
        std::cout << "end" << std::endl;
    }


    // Search for name in the list and returns position
    int search(const string& data) const {
        Node* current = head; // sets pointer
        int index = 0; // keeps track of position
        // only loops when not null
        while (current != nullptr) {
            // when it matchs it returns position
            if (current->data == data) {
                return index;
            }
            //moves the pointer to next
            current = current->next;
            // position tracking
            index++;
        }
        return -1; // Return -1 if not found
    }
};

// Test functions
void testAutoSortingList() {
    List pokedex;

    //  Pokémon
    cout << "alphabetical Pokémon List\n";
    std::cout << std::endl;
    // array 
    string pokemonList[] = {
        "Bulbasaur", "Ivysaur", "Venusaur", "Charmander", "Charmeleon", "Charizard",
        "Squirtle", "Wartortle", "Blastoise", "Caterpie", "Metapod", "Butterfree",
        "Weedle", "Kakuna", "Beedrill", "Pidgey", "Pidgeotto", "Pidgeot", "Rattata",
        "Raticate", "Spearow", "Fearow", "Ekans", "Arbok", "Pikachu", "Raichu",
        "Sandshrew", "Sandslash", "Nidoran♀", "Nidorina", "Nidoqueen", "Nidoran♂",
        "Nidorino", "Nidoking", "Clefairy", "Clefable", "Vulpix", "Ninetales",
        "Jigglypuff", "Wigglytuff", "Zubat", "Golbat", "Oddish", "Gloom", "Vileplume",
        "Paras", "Parasect", "Venonat", "Venomoth", "Diglett", "Dugtrio", "Meowth",
        "Persian", "Psyduck", "Golduck", "Mankey", "Primeape", "Growlithe", "Arcanine",
        "Poliwag", "Poliwhirl", "Poliwrath", "Abra", "Kadabra", "Alakazam", "Machop",
        "Machoke", "Machamp", "Bellsprout", "Weepinbell", "Victreebel", "Tentacool",
        "Tentacruel", "Geodude", "Graveler", "Golem", "Ponyta", "Rapidash", "Slowpoke",
        "Slowbro", "Magnemite", "Magneton", "Farfetch'd", "Doduo", "Dodrio", "Seel",
        "Dewgong", "Grimer", "Muk", "Shellder", "Cloyster", "Gastly", "Haunter",
        "Gengar", "Onix", "Drowzee", "Hypno", "Krabby", "Kingler", "Voltorb", "Electrode",
        "Exeggcute", "Exeggutor", "Cubone", "Marowak", "Hitmonlee", "Hitmonchan",
        "Lickitung", "Koffing", "Weezing", "Rhyhorn", "Rhydon", "Chansey", "Tangela",
        "Kangaskhan", "Horsea", "Seadra", "Goldeen", "Seaking", "Staryu", "Starmie",
        "Mr. Mime", "Scyther", "Jynx", "Electabuzz", "Magmar", "Pinsir", "Tauros",
        "Magikarp", "Gyarados", "Lapras", "Ditto", "Eevee", "Vaporeon", "Jolteon",
        "Flareon", "Porygon", "Omanyte", "Omastar", "Kabuto", "Kabutops", "Aerodactyl",
        "Snorlax", "Articuno", "Zapdos", "Moltres", "Dratini", "Dragonair", "Dragonite",
        "Mewtwo", "Mew"
    };

    // sorts the array list
    for (const auto& pokemon : pokemonList) {
        pokedex.arrangeABC(pokemon);
    }
    // will printed sorted list
    pokedex.print();
    std::cout << std::endl;

    // Test search function
    // searchs at end and being because they are easy to spot and it test head and rest of nodes
    cout << "\nTesting search function:\n";
    cout << "Index of 'Zubat': " << pokedex.search("Zubat") << endl;
    cout << "Index of 'Abra': " << pokedex.search("Abra") << endl;
    // testing not found
    cout << "Index of 'MissingNo': " << pokedex.search("MissingNo") << endl; // Should be -1
    std::cout << std::endl;

    // Test remove function
    // searchs at end and being because they are easy to spot and it test head and rest of nodes
    cout << "\nTesting remove function:\n";
    cout << "Removing 'Zubat': " << (pokedex.remove("Zubat") ? "Success" : "Failed") << endl;
    cout << "Removing 'Abra': " << (pokedex.remove("Abra") ? "Success" : "Failed") << endl;
    //testing not found
    cout << "Removing 'MissingNo': " << (pokedex.remove("MissingNo") ? "Success" : "Failed") << endl; // Should  fail
    std::cout << std::endl;
    // check if removal worked
    pokedex.print();
    std::cout << std::endl;
}


// runs test function
int main() {
    testAutoSortingList();
    return 0;
}
