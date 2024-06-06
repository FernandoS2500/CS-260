#include "fancyhash.hpp"

using String = std::string;

fancyhash::fancyhash(int size) : table(size) {}
 
void fancyhash::insert(const String& key, const String& value) {
    // calls hash functions to generate location
    int index = hash(key);
    int stepSize = secondHash(key);
    // adds to the collisionCount if it already has a value
    while (table[index].has_value() && table[index]->first != key) {
        std::cout << "collision at index " << index << " for " << key << std::endl;
        collisionCount++;
        //new index that generated from by adding both hashes and making sure its not bigger than table
        index = (index + stepSize) % table.size();
    }
    //place value into table at location
    //by default collison not an issue, will override
    table[index] = std::make_pair(key, value);
}

bool fancyhash::contains(const String& key) {
    // calls hash functions to generate location
    int index = hash(key);
    int stepSize = secondHash(key);
    //saves the orginal index
    int initialIndex = index;
    // loops for key using double hash 
    while (table[index].has_value()) {
        // checks with first hash
        if (table[index]->first == key) {
            return true;
        }
        //  using the second hash fuction
        index = (index + stepSize) % table.size();
        if (index == initialIndex) {
            break;
        }
    }
    return false;
}

std::optional<String> fancyhash::get(const String& key) {
    // calls hash functions to generate location
    int index = hash(key);
    int stepSize = secondHash(key);
    //saves the orginal index
    int initialIndex = index;
    // loops for key using double hash 
    while (table[index].has_value()) {
        if (table[index]->first == key) {
            //returns value when found
            return table[index]->second;
        }
        // second hash
        index = (index + stepSize) % table.size();
        //checks for change in index
        if (index == initialIndex) {
            break;
        }
    }
    return std::nullopt;
}


// hash magic
int fancyhash::hash(const String& key) {
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
// has magic 2 repeat of 1
int fancyhash::secondHash(const String& key) {
    int hash_value = 0;
     // a different prime number for the second hash function
    for (char c : key) {
        hash_value = (hash_value * 7 + c) % table.size();
    }
    // extra step to make sure step size is not zero
    return hash_value == 0 ? 1 : hash_value;
}


// keeps track of collisons, just an int 
int fancyhash::collisionTracker()const{
    return collisionCount;
}