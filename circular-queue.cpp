#include "circular-queue.h"
#include <iostream>
using namespace std;
const CircularQueue::QueueItem CircularQueue::EMPTY_QUEUE = -999;

CircularQueue::CircularQueue() {
    capacity_=16;
    size_=0;
    head_=0;
    tail_=0;
    items_= new QueueItem[capacity_];
}

CircularQueue::CircularQueue(unsigned int capacity) {
    capacity_=capacity;
    size_=0;
    head_=0;
    tail_=0;
    items_= new QueueItem[capacity_];
}

CircularQueue::~CircularQueue() {
    delete [] items_;
    items_ = nullptr;
}

unsigned int CircularQueue::size() const {
return size_;
}

bool CircularQueue::empty() const {
    if( size_==0)
        return true;

    else
        return false;
}

bool CircularQueue::full() const {
    if( size_==capacity_)
        return true;

    else
        return false;
}

CircularQueue::QueueItem CircularQueue::peek() const {
if (size_==0)
    return EMPTY_QUEUE;
else
    return items_[head_];
}

bool CircularQueue::enqueue(QueueItem value) {
if (size_<capacity_)
{
    items_[tail_]=value;
    tail_++;
    size_++;
    if (tail_==capacity_)
        tail_=0;
    return true;
}
else
    return false;

}

CircularQueue::QueueItem CircularQueue::dequeue() {
if (size_==0)
    return EMPTY_QUEUE;

QueueItem dequeue = items_[head_];
items_[head_]=NULL;
head_++;
size_--;
if (head_==capacity_)
    head_=0;
return dequeue;
}

void CircularQueue::print() const {
    for (int ind  = 0; ind <=size_-1; ind++) {
        cout << items_[ind] <<endl;
    }
}
