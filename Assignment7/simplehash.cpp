#include "simplehash.hpp"

using String = std::string;

simplehash::simplehash(int size) : table(size) {}
 
void simplehash::insert(const String& key, const String& value) {
    // calls hash function to generate location
    int index = hash(key); 
    // adds to the collisionCount if it already has a value
    if (table[index].has_value()) {
        //notice 
        std::cout << "collision at index " << index << " for " << key << std::endl; 
        collisionCount++; 
    }
    //place value into table at location
    //by default collison not an issue, will override
    table[index] = value;
}

bool simplehash::contains(const String& key) {
     // calls hash function to generate location
    int index = hash(key);
    // returns the value at the postion.
    return table[index].has_value();
}

std::optional<String> simplehash::get(const String& key) {
     // calls hash function to generate location
    int index = hash(key);
    // pops it into table to return
    return table[index];
}

// hash magic
int simplehash::hash(const String& key) {
    // starting hash value
    int hash_value = 0;
    // loops through every char in key
    for (char c : key) {
        // each loop it multipies the starting hash value  by 11 and adds the value of the char itself.
        //then it finishs off by using  modulo  to keep it in the table size.
        hash_value = (hash_value * 11 + c) % table.size();
    }
    return hash_value; // returned value
}
// keeps track of collisons, just an int 
int simplehash::collisionTracker()const{
    return collisionCount;
}