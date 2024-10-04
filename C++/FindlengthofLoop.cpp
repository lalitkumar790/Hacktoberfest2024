#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int data;
    ListNode* next;
    ListNode(int x) : data(x), next(NULL) {}
};

// Function to detect the loop and return its length
int findLoopLength(ListNode* head) {
    if (!head) return 0;  // If the list is empty

    ListNode* slow = head;
    ListNode* fast = head;

    // Detect loop using Floyd's Cycle Detection algorithm
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;            // Move slow pointer by 1
        fast = fast->next->next;     // Move fast pointer by 2
        
        if (slow == fast) {           // Loop detected
            // Count the number of nodes in the loop
            int loopLength = 1;
            ListNode* current = slow;
            while (current->next != slow) {
                loopLength++;
                current = current->next;
            }
            return loopLength;         // Return the length of the loop
        }
    }
    
    return 0;  // No loop detected
}

// Function to create a loop for testing
void createLoop(ListNode* head, int c) {
    if (c == 0) return;  // No loop to create

    ListNode* loopNode = head;
    for (int i = 1; i < c; i++) {
        loopNode = loopNode->next;  // Get the c-th node
    }
    
    ListNode* tail = head;
    while (tail->next != NULL) {
        tail = tail->next;  // Get to the last node
    }
    
    tail->next = loopNode;  // Create a loop
}

int main() {
    // Example input creation
    ListNode* head = new ListNode(25);
    head->next = new ListNode(14);
    head->next->next = new ListNode(19);
    head->next->next->next = new ListNode(33);
    head->next->next->next->next = new ListNode(10);
    head->next->next->next->next->next = new ListNode(21);
    head->next->next->next->next->next->next = new ListNode(39);
    head->next->next->next->next->next->next->next = new ListNode(90);
    head->next->next->next->next->next->next->next->next = new ListNode(58);
    head->next->next->next->next->next->next->next->next->next = new ListNode(45);

    // Create a loop by connecting the last node to the 4th node
    createLoop(head, 4);  // c = 4

    // Find the length of the loop
    int loopLength = findLoopLength(head);
    cout << "Length of the loop: " << loopLength << endl;

    // Cleanup: Not necessary for the demo but good practice
    // Normally, you would need to break the loop before deleting nodes
    return 0;
}
