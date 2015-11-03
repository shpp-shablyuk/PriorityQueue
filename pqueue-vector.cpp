/*************************************************************
 * File: pqueue-vector.cpp
 *
 * Implementation file for the VectorPriorityQueue
 * class.
 */
 
#include "pqueue-vector.h"
#include "error.h"
#include <vector>
#include <stdexcept>



VectorPriorityQueue::VectorPriorityQueue() {
	// TODO: Fill this in!
}

VectorPriorityQueue::~VectorPriorityQueue() {
	// TODO: Fill this in!
}

int VectorPriorityQueue::size() {
    return queue.size();
}

bool VectorPriorityQueue::isEmpty() {	
	return queue.size() == 0;
}

void VectorPriorityQueue::enqueue(string value) {
    queue.push_back(value);
}

string VectorPriorityQueue::peek() {	
    return queue.at(getMinElement());
}

string VectorPriorityQueue::dequeueMin() {
    int minElement = getMinElement();	
    string ret = queue.at(minElement);
    queue.erase(queue.begin() + minElement);
    
    return ret;
}

int VectorPriorityQueue::getMinElement() {
    if (queue.empty()) {
        throw ErrorException("empty !!!");
    }    
    
    int min = 0;
    for(int i = 1; i < queue.size(); i++) {
        if (queue.at(min) > queue.at(i)) {
            min = i;
        }
    }
	
    return min;
}



