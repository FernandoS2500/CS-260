#include <iostream>
#include "simplehash.cpp"
#include "fancyhash.cpp"

//  simple hash testing 
void testInsertGet(simplehash& simple) {
    std::cout << std::endl;
    std::cout << "Testing insert and get" << std::endl;
    std::cout << std::endl;
    //test duck data
    std::cout << "data inserted and retretived" << std::endl;
    simple.insert("Mallard", "A common duck breed.");
    simple.insert("Pekin", "A popular breed for meat.");
    simple.insert("yellow","A rubber ducky.");
    simple.insert("10", "A number of ducks.");

    // checks if in table
    
    std::cout << "checking if key is there " << std::endl;
    std::cout << "return of 1 if true" << std::endl;
    
    std::cout << "Mallard: " << simple.contains("Mallard") << std::endl;
    std::cout << "yellow: " << simple.contains("yellow") << std::endl;
    std::cout << "Pekin: " << simple.contains("Pekin") << std::endl;
    std::cout << "10: " << simple.contains("10") << std::endl;
    std::cout << std::endl;
    //test data retrival
    std::cout << "Grabs information for each key" << std::endl;
    std::cout << "yellow: " << simple.get("yellow").value() << std::endl;
    std::cout << "10: " << simple.get("10").value() << std::endl;
    std::cout << "Mallard: " << simple.get("Mallard").value() << std::endl;
    std::cout << std::endl;
}

void testReplacement(simplehash& simple) {
    //Test replaceing key , using information with key to show it works
    std::cout << "Testing Replacing key" << std::endl;
    simple.insert("Mallard", "A different description for Mallard.");
    std::cout << "Mallard Info after replacement: " << simple.get("Mallard").value() << std::endl;
    std::cout << std::endl;
}
        // test the collsion count by causing a collision
void testCollisionCount(simplehash& simple) {
    std::cout << "Testing Collision" << std::endl;
    // adds another pekin
    simple.insert("Pekin", "Another description for Pekin.");
    std::cout << "Collision Count: " << simple.collisionTracker() << std::endl;
    std::cout << std::endl;
}


// fancy hash testing 
// first 2 test are a rehash of simple test, to make sure it still works like expected
void testInsertGetFancy(fancyhash& fancy) {
    std::cout << std::endl;
    std::cout << "Testing insert and get for fancyhash" << std::endl;
    std::cout << std::endl;
    fancy.insert("Mallard", "A common duck breed.");
    fancy.insert("Pekin", "A popular breed for meat.");
    fancy.insert("yellow", "A rubber ducky.");
    fancy.insert("10", "A number of ducks.");

    std::cout << "Mallard: " << fancy.contains("Mallard") << std::endl;
    std::cout << "yellow: " << fancy.contains("yellow") << std::endl;
    std::cout << "Pekin: " << fancy.contains("Pekin") << std::endl;
    std::cout << "10: " << fancy.contains("10") << std::endl;
    std::cout << std::endl;

    std::cout << "yellow: " << fancy.get("yellow").value() << std::endl;
    std::cout << "10: " << fancy.get("10").value() << std::endl;
    std::cout << "Mallard: " << fancy.get("Mallard").value() << std::endl;
    std::cout << std::endl;
}

void testReplacementFancy(fancyhash& fancy) {
    std::cout << "Testing Replacing key in fancyhash" << std::endl;
    fancy.insert("Mallard", "A different description for Mallard.");
    std::cout << "Mallard Info after replacement: " << fancy.get("Mallard").value() << std::endl;
    std::cout << std::endl;
}
// added a little more to collision test, I made sure I could retrive the data after it was placed the new position after collsion
void testCollisionCountFancy(fancyhash& fancy) {
    std::cout << "Testing Collision in fancyhash" << std::endl;
    fancy.insert("Pekin", "Another description for Pekin.");
    fancy.insert("test1", "This should cause a collision");
    fancy.insert("test2", "This should cause another collision");
    std::cout << "Collision Count: " << fancy.collisionTracker() << std::endl;
    std::cout << std::endl;
    std::cout << "Grabs information for each key" << std::endl;
    std::cout << "test1: " << fancy.get("test1").value() << std::endl;
    std::cout << "test2: " << fancy.get("test2").value() << std::endl;
}

int main() {
    std::cout << "Simple" << std::endl;

    simplehash simple(10);

    testInsertGet(simple);
    testReplacement(simple);
    testCollisionCount(simple);

    std::cout << "Fancy" << std::endl;

    fancyhash fancy(10);

    testInsertGetFancy(fancy);
    testReplacementFancy(fancy);
    testCollisionCountFancy(fancy);
 

    return 0;
}
