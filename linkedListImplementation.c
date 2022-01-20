#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// to linked list
// 1 - max Value in list
// 2 - min Value in list
// 3 - add to the front
// 4 - add to the tail
// 5 - add in the particular place
// 6 - add sorted
// 7 - remove form the head
// 8 - remove from the tail
// 9 - reverse linked list
// 10 - print sum 
// 11 - print average
// 12 - print linked list

typedef struct e {
	double value;
	struct e* next;

}*list_t;

list_t head;
list_t tail;

double maxValue() { 			// 1
	list_t temp = head;
	if (temp == NULL) {
		return NAN;
	}
	
	double maxValue = temp->value;
	while (temp != NULL) {
		if (temp->value > maxValue) {
			maxValue = temp->value;
		}
		temp = temp->next;
	}
	return maxValue;
}

double minValue() {   			// 2
	list_t temp = head;
	if (temp == NULL) {
		return NAN;
	}

	double minValue = temp->value;
	while (temp != NULL) {
		if (temp->value < minValue) {
			minValue = temp->value;
		}
		temp = temp->next;
	}
	return minValue;
}

void addToTheFront(double value) {	// 3
	list_t newNode = (list_t)malloc(sizeof(struct e));
	newNode->value = value;
	
	if (head == NULL) {
		head = newNode;
		tail = newNode;
		newNode->next = NULL;
	}

	else {
		newNode->next = head;
		head = newNode;
	}
}

void addToTheTail(double value) {	// 4
	list_t newNode = (list_t)malloc(sizeof(struct e));
	newNode->value = value;
	
	if (head == NULL) {
		head = newNode;
		tail = newNode;
		newNode->next = NULL;
	}

	else {
		tail->next = newNode;
		newNode->next = NULL;
		tail = newNode;
	}
}

void addInTheParticularPlace(int number, double value) {	//5
	list_t temp = head;
	list_t newNode = (list_t)malloc(sizeof(struct e));
	newNode->value = value;
	if (temp == NULL) {
		head = newNode;
		tail = newNode;
		newNode->next = NULL;
	} 

	else {
		for (int i=0; i<number; i++) {
			temp = temp->next;	
		}
		if(temp != NULL && temp != tail && temp != head) {
			newNode->next = temp->next;
			temp->next = newNode;
		} else if (temp != NULL && temp == tail) {
			addToTheTail(value);
		} 
	
	}
}


void reverseLinkedList() {		// 9

	list_t temp1 = NULL;
	list_t temp2 = NULL;
	tail = head;
	while (head != NULL) {
		temp2 = head->next;
		head->next = temp1;
		temp1 = head;
		head = temp2;
	}
	head = temp1;
}

double sum() {		// 10
	double sum = 0.0;
	list_t temp = head;
	while (temp != NULL) {
		sum += temp->value;
		temp = temp->next;
	}
	return sum;
}

double average() {		// 11
	list_t temp = head;
	int counter = 0;
	while (temp != NULL) {
		counter++;
		temp = temp->next;
	}
	return sum() / counter;
}

void addSorted(double value) {		// 6 (works only if list is already sorted ASCENDING) 
	list_t newNode = (list_t) malloc(sizeof(struct e));
	newNode->value = value;
	newNode->next = NULL;

	if (head == NULL) {
		head = newNode;
		tail = newNode;
		newNode->next = NULL;
	} else if (value < head->value) {
		addToTheFront(value);
	}
       
	else if (value > tail->value) {
		addToTheTail(value);
	}

	else {
		list_t temp1 = head;
		list_t temp2 = head;
	
		while (temp2->value < newNode->value) {
			temp1 = temp2;
			temp2 = temp2->next;
		}
		temp1->next = newNode;
		newNode->next = temp2;
	}
}

void removeFromTheFront() {  		// 7
	list_t temp = head->next;
	head->next = NULL;
	head = temp;

}

void removeFromTheTail() {		// 8
	list_t temp = head;
	while (temp->next != tail) {
		temp = temp->next;
	}
	temp->next = NULL;
	tail = temp;
}


void printLinkedList(FILE* outPutFile) {		// 12
fprintf(outPutFile, "\n");
	list_t temp = head;
	while (temp != NULL) {
		fprintf(outPutFile, "%f-->", temp->value);
		temp = temp->next;
	}

fprintf(outPutFile, "NULL\n");
}


int main(int argc, char* argv[]) {
	FILE* testOutPut = argc > 1 ? fopen(argv[1], "w") : stdout;

	addToTheFront(10);
	addToTheFront(5);
	addSorted(50);
	addSorted(70);
	addToTheTail(90);

	printLinkedList(testOutPut);

	fprintf(testOutPut,"\n\n");

	reverseLinkedList();
	printLinkedList(testOutPut);
	addToTheFront(1000);
	printLinkedList(testOutPut);
	removeFromTheFront();
	
	removeFromTheTail();
	printLinkedList(testOutPut);

	fprintf(testOutPut,"\n\n\t Min value --> %f\n", minValue());
        fprintf(testOutPut, "\tMax value --> %f\n", maxValue());
	fprintf(testOutPut, "\tSum value --> %f\n", sum());
	fprintf(testOutPut, "\tAverage value --> %f\n", average());	
	
	
return 0;
}


