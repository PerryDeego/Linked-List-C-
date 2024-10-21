/* Author: D. Perry */

#include <iostream>
using namespace std;

/* Node structure definition */
struct node {
    int number; // Data part of the node
    struct node *next; // Pointer to the next node
};

/*  Function prototypes */
char menu();
bool isEmpty(node *head);
void printList(node *current);
void insert(node *&head, node *&last, int number);
void remove(node *&head, node *&last);
void insertAsFirstElement(node *&head, node *&last, int number);

int main() {
    node *head = NULL; // Initialize head of the list to null
    node *last = NULL; // Initialize last of the list to null
    char option;
    int number;

    do {
        option = menu(); // Display menu and get user choice

        switch (option) {
            case '1':
                cout << "PLEASE ENTER A NUMBER: ";
                cin >> number;
                insert(head, last, number); // Insert number into the list option
                break;
            case '2':
                remove(head, last); // Remove the first element from the list option
                break;
            case '3':
                printList(head); // Display the list option
                break;
            default:
                break; // Break for invalid input option
        }

    } while (option != '0'); // Continue until user chooses to exit

    cout << "\n\n";
    system("pause"); // Pause the system before exiting
    return 0;
}

// Function to display the menu and get user choice
char menu() {
    char choice;

    cout << "\n\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
    cout << "\n\t\t~~                  <LINKED LIST MENU>                    ~~";
    cout << "\n\t\t~~          <CHOOSE YOUR OPTION FROM MENU BELOW>          ~~";
    cout << "\n\t\t~~          ->1. ADD AN ITEM                              ~~";
    cout << "\n\t\t~~          ->2. REMOVE AN ITEM                           ~~";
    cout << "\n\t\t~~          ->3. DISPLAY THE LIST                         ~~";
    cout << "\n\t\t~~          ->0. EXIT MENU                                ~~";
    cout << "\n\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
    cout << "\n\n";

    cin >> choice; // Get user choice
    return choice;
}

/* Function to check if the list is empty */
bool isEmpty(node *head) {
    return head == NULL; // Return true if head is NULL
}

/* Function to insert the first element into the list */
void insertAsFirstElement(node *&head, node *&last, int number) {
    node *temp = new node; // Create a new node
    
    temp->number = number;
    temp->next = NULL;
    head = temp; // Update head
    last = temp; // Update last
}

/* Function to insert a new element at the end of the list */
void insert(node *&head, node *&last, int number) {
    if (isEmpty(head)) {
        insertAsFirstElement(head, last, number); // Insert as first element if list is empty
    } else {
        node *temp = new node;
        
        temp->number = number;
        temp->next = NULL;
        last->next = temp; // Link new node to the end of the list
        last = temp; // Update last
    }
}

/* Function to remove the first element from the list */
void remove(node *&head, node *&last) {
    if (isEmpty(head)) {
        cout << "The list is already empty.\n"; // List is empty
    } else {
        node *temp = head; // Store the current head
        head = head->next;
        delete temp;
        if (head == NULL) { // If the list is now empty
            last = NULL; // Update last to NULL
        }
    }
}

/* Function to print the elements of the list */
void printList(node *current) {
    if (isEmpty(current)) {
        cout << "The list is empty.\n"; // List is empty
    } else {
        cout << "The list contains:\n";
        while (current != NULL) {
            cout << current->number << endl; // Print each element
            current = current->next; // Move to the next node
        }
    }
}
