/*************************************************************
 * File: pqueue-linkedlist.cpp
 *
 * Implementation file for the LinkedListPriorityQueue
 * class.
 */
 
#include "pqueue-linkedlist.h"
#include "error.h"

LinkedListPriorityQueue::LinkedListPriorityQueue() {
    qSize = 0;
    head = new List;
//    head->next  = NULL;
}

LinkedListPriorityQueue::~LinkedListPriorityQueue() {
	// TODO: Fill this in!
}

int LinkedListPriorityQueue::size() {	
    return qSize;
}

bool LinkedListPriorityQueue::isEmpty() {
    return qSize == 0;
}

void LinkedListPriorityQueue::enqueue(string value) {
    for (List* item = head; item != NULL; item = item->next) {
        if (item->next == NULL || item->next->value > value) {
            insertAt(item, value);
            break;
        }
    }    
  
    qSize++;    
}

string LinkedListPriorityQueue::peek() {     
    if (head->next == NULL) {
        throw ErrorException("empty!");
    } 
    
    return head->next->value;
}

string LinkedListPriorityQueue::dequeueMin() {
    if (head->next == NULL) {
        throw ErrorException("empty!");
    } 
    
    string result = head->next->value;
    
    List* newHead = head->next->next;
    delete head->next;
    
    head->next = newHead;
    qSize--;
            
    return result;
}

void LinkedListPriorityQueue::insertAt(List* item, string value) {
    List* newCell = new List;
    newCell->value = value;
    newCell->next = item->next;

    item->next = newCell;
}

