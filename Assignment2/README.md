Salazar 

2:Based on what we know about linked lists, stacks, and queues, design a queue data structure:

    2.1What functions are we likely to need for a queue to function like the one discussed in class?
    A que is first in first out.

    Add function: A function to add a new item to the end of the line.

    remove function: A function that will remove the item at is at the front of the line.

    empty furntion:  A function that will check if the que is empty.

    number function: A function that keeps track of the size of the que so it is know what the last item is before 
    a new one is added or removed.


    2.2What values will we need to know about the structure for our queue to function properly?

    Count:  integer for que size

    front object: a value that has the last object in and its number place?

    Last object: A value that has what object is in the front of the line?

    probably more but these are the obvious ones.


3:Based on what we know about linked lists, design a list data structure that allows us to add (insert) or remove (delete) values at a given location in the list (instead of the top of a stack or the front or back of a queue):

    3.1What functions are we likely to need for a list to function like this?
    A linked list list the next item in que 

    Add function: This function will need to add the new object and update the prevous object so it links to this one

    remove function: can remove objects from the list, using some kind of id so it can search for it. If it remove an item from middle of list needs to update link info?

    update function: this might be its on function that updates the links after a change to a list object. Called by add and remvoe funtion.

    size function: To keep track of size of list and maybe limit list size. A long list could become unusable.

    3.2What values will we need to know about the structure for our list to function properly?

    default list object: depending on how the link list is set up, I need a starting point to start going through them.

    object id: A uqnie id for each object.

    count: int for the length of the list.
    