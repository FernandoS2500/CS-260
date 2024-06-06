#ifndef fancyhash_hpp
#define fancyhash_hpp

#include <iostream>
#include <vector>
#include <string>
#include <optional>
#include <utility>
// 
using String = std::string;

class fancyhash {
public:
    //size for hash table
    fancyhash(int size);
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
    int secondHash(const String& key);
    // vector for has table
    std::vector<std::optional<std::pair<String, String>>> table;
    // int for count of collisions
    int collisionCount = 0;
};

#endif // fancyhash_hpp
