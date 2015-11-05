/*************************************************************
 * File: pqueue-doublylinkedlist.cpp
 *
 * Implementation file for the DoublyLinkedListPriorityQueue
 * class.
 */
 
#include "pqueue-doublylinkedlist.h"
#include "error.h"

DoublyLinkedListPriorityQueue::DoublyLinkedListPriorityQueue() {
}

DoublyLinkedListPriorityQueue::~DoublyLinkedListPriorityQueue() {
	// TODO: delete LinkedList
}

int DoublyLinkedListPriorityQueue::size() {
    return qSize;
}

bool DoublyLinkedListPriorityQueue::isEmpty() {
    return qSize == 0;
}

void DoublyLinkedListPriorityQueue::enqueue(string value) {
    Node* newNode = new Node;
    newNode->value = value;
    
    if (head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        head = newNode;
        
        head->next->prev = head;
    }    
      
    qSize++;       
}

string DoublyLinkedListPriorityQueue::peek() {
    if (head == NULL) {
        throw ErrorException("empty!");
    }  
    
    Node* minNode = findMinNode();
    return minNode->value;
}

string DoublyLinkedListPriorityQueue::dequeueMin() {
    if (head == NULL) {
        throw ErrorException("empty!");
    }
    
    Node* minNode = findMinNode();    
    string value = minNode->value;
    
    popNode(minNode);

    qSize--;    
    
    return value;
}

void DoublyLinkedListPriorityQueue::popNode(Node* node) {    
    if (node == head) {
        if (head->next == NULL) {
            head = NULL;
        } else {
            head = head->next;
            head->prev = NULL;
        }
    } else {
        node->prev->next = node->next;
        if (node->next != NULL) {
            node->next->prev = node->prev;
        }
    }
    
    delete node; 
}

Node* DoublyLinkedListPriorityQueue::findMinNode() {
    if (qSize == 1) {
        return head;
    }
    
    Node* min = head;
    for(Node* item = head->next; item != NULL; item = item->next) {
        if (min->value > item->value) {
            min = item;
        }
    }    
    
    return min;
}

