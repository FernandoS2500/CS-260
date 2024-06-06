#ifndef simplehash_hpp
#define simplehash_hpp

#include <iostream>
#include <vector>
#include <string>
#include <optional>
// 
using String = std::string;

class simplehash {
public:
    //size for hash table
    simplehash(int size);
    // add to hashtable
    void insert(const String& key, const String& value);
    //checks if key is in the has table
    bool contains(const String& key);
    // grabs the information that is stored with the key
    std::optional<std::string> get(const String& keyy);
    // Gets the number of collesions 
    int collisionTracker() const;
    // makes the value of the hash key.
    int hash(const String& key);
    // vector for has table
    std::vector<std::optional<String>> table;
    // int for count of collisions
    int collisionCount = 0;
};

#endif // simplehash_hpp
