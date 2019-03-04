 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <ctype.h>
 
 /********** LL NODE STRUCT **************/

struct listnode {
		char* word;
		int length;
		int first; //this stores the ascii value of the first letter
		struct listnode* next;

}; 
 
/********** FUNCTION SIGNATURES **********/
void clearOut(char*, int); //this function empties any character array
int goDeep(struct listnode*, struct listnode*);
struct listnode* insert (struct listnode*, struct listnode*);
struct listnode* newNode (char* word, int length);
void printLL(struct listnode*);
void freeLL(struct listnode*);

/********** HELPER FUNCTIONS ***********/
void freeLL(struct listnode* head){
	struct listnode* temp;
	while (head != NULL) {
		temp = head;
		head = head->next;
		free(temp);
	}
}

void printLL (struct listnode* head) {
	//LL is empty
	/*
	if(head == NULL) {
		printf("\n");
		return;	
	}
	*/
	
	//traverse from beg to end, printing out until the pointer hits the null 
	struct listnode* t1 = head;
	
	while (t1 != NULL) {
		printf("%s\n", t1->word);
		t1 = t1->next;	
	}

	return;
}
struct listnode* newNode(char* token, int length) {
	struct listnode* temp = (struct listnode*) malloc(1*sizeof(struct listnode));
                     	temp->word = (char*)malloc(length+1);
                        strcpy(temp->word, token);
                        temp->length = length;
                        temp->first = token[1]; //does this work? or must I also pass the first value of word as an argument somehow?
						//This should work. It should upgrade the char value to an int when assigning as such.
                        temp->next = NULL;
	return temp;
};
struct listnode* insert (struct listnode* head, struct listnode* new) {
	
	struct listnode* ptr;
	
	if ( head == NULL || (goDeep(head, new) == 5) ) {//if the head is null, or if the new node's word is greater than the head's word
		new->next = head;
		head = new; 
	} else {
		ptr = head;
		
		while (ptr->next != NULL && (goDeep(ptr->next, new) == 3) ) {
			ptr = ptr->next;
		}
		//now for three cases: 1. appending to the end of the list, 2. they are the same word and thus equal, 3. new is indeed bigger
		if (ptr->next == NULL) {
		//	printf("im at the end of the list\n");
			new->next = NULL;
			ptr->next = new;		
		} else if ( (goDeep(ptr->next, new) == 7) ) {
		//	printf("they're the same word\n");
			new->next = ptr->next;		
			ptr->next = new;
		} else if ( (goDeep(ptr->next, new) == 5) ) {
		//	printf("new node is bigger\n");
			new->next = ptr->next;
			ptr->next = new;
		}
	}
	return head;
}
/*
struct listnode* insert(listnode* head, listnode* new) {
	int compare = 0;
	//when list is empty
	if (head == NULL) {
		head = new;
		return head;	
	} else if (new->first-> head->first->value) { //if it's greater than the head
	//goDeep(ptr->word, new->word)
	} else if (new->first == head->first) { //if the first letters of the new node and the head are the same
		//use godeep
	
	}else {
		
		struct listnode* ptr;
		while (ptr->next != NULL && (ptr->next->first > new->first) ) { //while i'm not at the end of the list or the next one after pointer is not smaller 
			ptr = ptr->next;	
		}
	
	
		if (ptr->next->first == new->first) { //case 1: the first letters are equal
		//what about the test case of heart -> heard -> hear ??		
				compare = goDeep(ptr->next, new);
			if (compare == 3) { //ptr->next is bigger 
			
			} else if (compare == 5) { //if new is bigger
				//check if the ptr->next->next is bigger too and then go again.
		
			} else if (compare == 7) { //if new and the node->ptr are the same word
			
			}
		
		} else if (ptr->next->first < ptr->first) { //case 2: ptr->next is smaller than the first
	
	
		} else if (ptr-> next = NULL) { //case 3: I'm at the end of the list 
			new = ptr->next;
			new->next = NULL;
			return head;
	
		}
	}
}
*/
int goDeep (struct listnode* ptr, struct listnode* new) {
	/*
	* i will return 3 if the ptr is bigger. 5 if the new node is bigger. 7 if theyre the same word.
	*/
	int length = 0; int i = 0; int which = 3; //this will tell me which node's length i'm using for the case of "march" v. "marching" or when they're equal
	/*
	* which: 0-> used ptr's length; 1 -> used new's length; 5 -> used either because the lengths are equal
	*/
	if ((ptr->length) > (new->length)) {
		length = new-> length; //im using the smaller length	
	} else {
		length = ptr->length;
		which = 0;
		if ((ptr->length) - (new->length) == 0 ) {
		which = 5;		
		}	
	}
	//now iterate thru the words and find whichever is bigger. if i exit the for loop without having returned anything, i will know that it's the edge case/ words r same	  
 	for (i = 0; i < length; i++) {
		if (isupper(ptr->word[i]) && islower(new->word[i])) {
			return 3; //ptr is larger bc words with caps are held in higher esteem		
		} else if (isupper(new->word[i]) && islower(ptr->word[i])) {
			return 5; //the new word has an upper case which makes it larger		
		/*} 
		else if (isupper(new->word[i]) && isupper(ptr->word[i])){
			//if ptr = Alex and new = Zayn
			if ((ptr->word[i] < )
			//if ptr = Norman and new = Callie
			*/
		} else if ((ptr->word[i]) > (new->word[i]) ) {
			return 3; //the ptr's letter is larger, so i will return ptr as larger		
		} else if ((new->word[i]) > (ptr->word[i])) {
			return 5; //the new node's letter is larger, so i will return the new as larger		
		}	 
 	
 	}
 	//if i've exited the for loop without returning i'm in one of two cases: 1. "march" v. "marching" 2. they are the same exact word

	//case 1: "march v. marching". in this case, i should go with the longer word. i know this is NOT the one whose length i used to iterate thru the for loop
	
	if (which == 5) return 7; //equal 
	if (which == 0) return 5; //new is bigger word
	if (which == 1) return 3; //ptr is the larger word 
 
 return 0;
 }
 void clearOut( char* array, int size) {
	int i = 0;
	for (i = 0; i < size; i++) {
		array[i] = '\0';	
	}
	return; 
 }

 int main (int argc, char** argv) {
	struct listnode* upper = NULL;
	struct listnode* lower = NULL;
	int i = 0; int strsize = 0; //int j = 0;
	char* original; char* new;

 
 	if ( argc != 2) { //error check to make sure i'm only taking in one string
		printf("error: wrong number of arguments\n");
		return 0; 
 	}
 
	strsize = strlen(argv[1]); //save length of string for for loop iteration
	strsize+=1; //add a space for the end
	
	//account for empty string case
	
	if (strsize == 1) {
		printf("\n");
		return 0;	
	}
	
	original = (char*) calloc(strsize+1, sizeof(char));  //I added in a +1 since we want to make room for the null terminator this shifts the spot for the null terminator from strsize-1 to strsize
	original[strsize] = '\0'; //make sure to put an end to the string
	
	for (i = 0; i <strsize; i++) { //copy argv into new string
		original[i] = argv[1][i];	//is this the wrong order? should it be reversed?

	} 
	
	original[strsize] = '\0';
	//I did the same for new as I did for original
 	new = (char*) calloc (strsize+1, sizeof(char)); //this is where i will store the word. max length will be max length of the string, logically.
 	new[strsize] = '\0';
 	int firstSep = 1; 
 	
 	/*this is a marker that I will use to determine when the string needs to be inserted into the LL or not. 
 	It safeguards against the case of multiple separators being inputted right after each other.
 	*/
 	int j = 0;
 	
 	for (i = 0; i < strsize; i++) {
		if (isalpha(original[i])) {
			//printf("index:%d has char:%c is alpha\n",i,original[i]);
			new[j] = original[i];	
			j++;
			//firstSep = 0;
		} else if (!isalpha(original[i])) {
		//	printf("index:%d has char:%c is not alpha\n",i,original[i]);
			new[j] = '\0';	
			firstSep = 0;
			if(j==0){ //Here is where I think we want to stop creating nodes for the empty string
				firstSep = 1;				
				continue;
			}
		}	
		//why am i not jumping into this if statement????
			if ((firstSep == 0)) {
					if (isupper(new[0])) {
						struct listnode* temp = newNode(new, j);  
						upper = insert(upper, temp); //add a node to the upper LL			
					} else {
						struct listnode* temp = newNode(new, j);
						lower = insert(lower, temp);				
					}
					clearOut(new, strsize);
					j = 0;		
					firstSep = 1;	
			}	
 	}

 	/*
 	struct listnode* pointer = lower;
 	while (pointer != NULL) {
		printf("%s\n", pointer->word); 
		pointer = pointer->next;	
 	}
 	
 	struct listnode* pointer2 = upper;
 	while (pointer2 != NULL) {
		printf("%s\n", pointer2->word); 
		pointer2 = pointer2->next;	
 	}
 	*/
 	
 	
 	
 	
 	printLL(upper);
	printLL(lower);
	
	freeLL(upper);
	freeLL(lower);
	free(original);
	free(new);
	
	
	return 0; 
 }
