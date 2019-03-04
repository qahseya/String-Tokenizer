This is the README file for Assignment 0 of Systems Programming.

This program focuses on tokenizing a string inputted from the command line, and outputting the words it contains in alphabetical order.
To tokenize the string, I copied the string into memory that I allocated using the calloc function. Then, I iterated through it and copied all alphaebtical characters into another string that was malloced with the length of the original string (to account for the possibility of the string being one large token). As soon as a non-character separator was encountered, the main method would pass the string to an insert function that would sort it into a reversely alphabetical sorted linked list. I maintained 2 Linked Lists-- one for upper case words, and one for lower case words -- in order to use their askii values when comparing words and printing all upper case words before lower case. At the end, I freed all the memory I had allocated including nodes and strings as well.

I used a linked list as the data structure because they are convenient for dynamic memory allocation and sorting. I conidered using an array to keep the words, but it would be less efficient to allocate a fixed amount of memory to store words like "supercalafragalisticexpialadocious" and "to" in the same array. It is also more convenient to sort linked lists because nodes can be easily moved around through pointers and their data is also easily compared. Each node of the linked list stored: 1. the word itself using char* with the space for the character array being allocated later in the newNode function. 2. The length of the word. This was used when comparing two words so as not to run into overflow errors (I used the smaller word for the parameters of the for loop) and also to break ties between words that were almost the same like "march" and "marching". 3. The first character of the word used to quickly check whether a node was larger than another based on the first letter. A pointer to the next node... because this is a linked list and this is how these beauties wok.


Below, I will describe the functions that I used:

1. void clearOut(char*, int); //this function empties any character array

This function empties any character array and replaces ALL of its entires with '\0'. By taking in the array as char* and its length as int, I use a for loop to iterate through the array and replace each character. I included this function because I wanted to use only ONE string while tokenizing the input, in order to use as little memory as possible.

2. int goDeep(struct listnode*, struct listnode*);

This function is a compare function that I created becaue the C library compareTo function was inadequate for this assignment. To account for the case of words containing upper-case letters within them (example: gHost v. ghost) I used this to compare to strings and return whichever string was larger. I called this as a helper method to my insert function in order to enter new nodes into an already sorted linked list. It is called "goDeep" because I only used it when the first letters of the words being compared were different at first, but I later modified my code to use it in nearly all cases because it simplified the process. goDeep returns an int and takes in two separate nodes of my linked list, because it iterates through their datas and compares them to each other in order to determine which is the larger value. It returns three different int cases for when the first value is larger, the second value is larger, or when the two strings are exactly equal.

3. struct listnode* insert (struct listnode*, struct listnode*);

This function was the most difficult to write because of all the different cases it needed to account for, including but not limited to when I inserted into an empty linked list, when the new node was larger than the head, inserting somewhere in the middle, encountering two equal words and where to insert in that case, or inserting at the end of the linked list. It took in two different nodes-- the head of the list I wanted to insert into, and the new node that was going to be inserted -- and returned a node to my linked list as well in order to contantly maintain a handle on the head node of the Linked List.

4. struct listnode* newNode (char* word, int length);

This function creates a new node. It takes in the length of the word and the char array that will be stored in the array, and then derives the first letter using char[0]. These three are stored into the data portions of the linked list node. It also mallocs a new string of size length + 1 and then stores the word that's being inputted into that string. This dynamic memory allocation exists in order to account for extremely large tokens that may crash my code.

5. void printLL(struct listnode*);

This simply prints the linked list. It takes in the head of the linked list, and then iterates through all the nodes using a pointer in order to print out their word values. I called it on the upper linked list first and on the lower linked list second in order to output it according to the assignment specs.

A big thank you to Professor Hidalgo for helping me so much with this project.
