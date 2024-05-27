Salazar

Assignment 5 (Auto-sorting list operations)
Completion requirements
Follow along with the in-class exercise on this, do your best to get it working, and turn in what you come up with here!

Be sure to include at least one test for each function or piece of functionality that should verify that your code is working!  No slacking smile, you should start writing some tests before you write your implementations (just spend a few minutes thinking about the design and then write a few tests using natural language (English is preferred for me to be able to read it smile ))

Create an array-based list or a linked-list (and a bonus for attempting both) that:

automatically inserts values in the correct position based on some order of sorting (perhaps ascending integers or lexicographical sorting of words)

efficiently searches for elements (likely binary search for the array list, but what about the linked-list?)

Make a chart to compare the algorithmic complexity (use Big-O notation) of your insert, remove, and search algorithms you used for your structures

Once you have implemented and tested your code, add to the README file what line(s) of code or inputs and outputs show your work meeting each of the above requirements (or better, include a small screen snip of where it meets the requirement!).

Note: This assignment is to get you to think about and practice with structures that have automatically enforced properties (perhaps auto sorted, since we know sorting can be expensive... and how these might be able to be spread out over time)



// Goal is to keep as simple as possible
// Sort the starting 151 pokemon from an array list

// first function is an auto sorting that will organinze everthing lexicographical

//A search function based on binary search

//Remove funcntion

// added a print function  to see results


// requirements 

//sort 

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


   // Remove function

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

    //search function

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


// all the testing functions, one for each function except for print


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

