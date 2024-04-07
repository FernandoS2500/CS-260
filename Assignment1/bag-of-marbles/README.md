// Bag of marbles Planning
Fernando Salazar


Marbles are going to be represnted by var that has the color, size and maybe some id that is assigned by the program

A function that will add new marbles, each marble added must have the color and size.

A function to remove a marble, Will be done by assigned ID, not sure if it will be random or somekind of marble in first out first rule.
Need to check if bag is empty before attemping remove marble


A function to list all the marbles with ID 

Im not sure yet IF the marbles information will be stored in a list or someother method yet to test the functions for adding and removal. I will check marble count. and if all the fields are filled.

For the list function , I can compare what the list should be to what has been added.

All of this will be done using the cmd prompt for input.

// How to use

Run the program in the cmd prompt from its directory by typing .\marbles.exe

When the program loads, the default menu gives you 4 options.

1. Add a marble
2. Remove a marble
3. Show all marbles
4. Exit

Enter 1-4 based of what you want to do

After each function is finished running it will go back to main menu till the program 
is exited.

// added 5th option for start of some auto testing.
for now its only checks if the array gets larger than 10 if it will till that the bag is full





// requirements meet

1. what makes a marble 
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

2.  A way to add marbles
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
3.     A way to remove marbles
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
4. Way to show that its working correctly, only has one test for now
 void testMarbles(){

        BagOfMarbles testbag;
        // test #1
        // Simulate adding more than max marbles
        count = 10;
        testbag.addMarble(); 
        count = 0;
        
        // test #2

    }



