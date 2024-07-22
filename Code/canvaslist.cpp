#include "canvaslist.h"

#include <iostream>

using namespace std;

CanvasList::CanvasList() {
    // default constructer. intialize private member variables.
    this->list_size = 0;
    this->list_front = nullptr;
}

CanvasList::CanvasList(const CanvasList& other) {
    // copying elements FROM 'other' INTO 'this->' class
    
    // re-initialize variables
    this->list_front = nullptr;
    this->list_size = 0;

    // iterate through 'other' list
    ShapeNode* otherTemp = other.list_front;
    while (otherTemp != nullptr) {
        // copy the shape
        Shape* copyOfOtherShape = otherTemp->value->copy();

        // push copied shape to back of the list
        this->push_back(copyOfOtherShape);

        // increment 'other' node
        otherTemp = otherTemp->next;
    }
}

CanvasList& CanvasList::operator=(const CanvasList& other) {
    // set current canvaslist to a deep copy of the 'other' canvaslist
    if (this != &other) { // make sure memory address of parameter is not current canvaslist
        // clear current canvaslist
        this->clear();

        // deep copy 'other' into cleared canvaslist
        ShapeNode* otherTemp = other.list_front;
        while (otherTemp != nullptr) {
            // use copy function to get pointer to copy of shape
            Shape* shapeToBeCopied = otherTemp->value->copy();

            // push back copy of shape into cleared canvaslist
            this->push_back(shapeToBeCopied);

            // increment 'other' node
            otherTemp = otherTemp->next;
        }
    }

    return *this;
}

CanvasList::~CanvasList() {
    // destructor. use the clear function-- de-allocates all alloc'ed memory
    this->clear();
}

void CanvasList::clear() {
    // dealloc all alloc'ed memory. nodes and shapes.
    ShapeNode* temp = this->list_front;
    while (temp != nullptr) {
        // save pointer to next node
        ShapeNode* nextNode = temp->next;

        // free the necessary memory
        delete temp->value; // free the shape
        delete temp; // free the shapeNode

        // increment to next node
        temp = nextNode;
    }

    // set private member variables back to default
    this->list_size = 0;
    this->list_front = nullptr;
}

void CanvasList::insert_after(int index, Shape* s) {
    // check if index invalid
    if (index >= this->list_size || index < 0) {
        return;
    }

    // intialize variables before iterating
    ShapeNode* temp = this->list_front;
    ShapeNode* sNode = new ShapeNode;
    sNode->value = s;
    sNode->next = nullptr;
    
    // make next ptr of shape at index to sNode
    int currIndex = 0;
    while (temp != nullptr) {
        if (currIndex == index) {
            // insert shape node after the current index
            sNode->next = temp->next; // connect new node to right side of list
            temp->next = sNode; // connect new node to list from left side
            
            // increment the size
            this->list_size++;
            return;
        } else {
            // increment current index and node ptr
            currIndex++;
            temp = temp->next;
        }
    }

    return;
}

void CanvasList::push_front(Shape* s) {
    // declare shapenode, set value to s, and set next to the front of the list
    ShapeNode* sNode = new ShapeNode;
    sNode->value = s;
    sNode->next = this->list_front;
    
    // set front of the list to s
    this->list_front = sNode;

    // increment size
    this->list_size++;
}

void CanvasList::push_back(Shape* s) {
    // declare a new shapenode, set value to s, and set next to null
    ShapeNode* sNode = new ShapeNode;
    sNode->value = s;
    sNode->next = nullptr;

    // if the list is empty, set the front to sNode
    if (this->list_front == nullptr) {
        this->list_front = sNode;
        this->list_size = 1;
        return;
    }

    // iterate to the end of the list
    ShapeNode* temp = this->list_front;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    // set the next of the last node to sNode
    temp->next = sNode;

    // increment size
    this->list_size++;
}

void CanvasList::remove_at(int index) {
    // check if index invalid
    if (index >= this->list_size || index < 0) {
        return;
    }
    
    // edge case: removing first element
    if (index == 0) {
        ShapeNode* temp = this->list_front; // so we can free it after re-assigning front of list
        this->list_front = this->list_front->next;
        this->list_size--;
        delete temp->value; // free shape
        delete temp; // free shape node
        return;
    }

    // iterate through list until index before the one to be removed
    ShapeNode* temp = this->list_front;
    for (int i = 0; i < index - 1; ++i) {
        temp = temp->next;
    }

    ShapeNode* toBeRemoved = temp->next;
    temp->next = temp->next->next; // set next node to be the one after this removed node
    delete toBeRemoved->value; // free shape
    delete toBeRemoved; // free shape node
    this->list_size--;
}

void CanvasList::remove_every_other() {
    // edge case: only one item, or no items
    if (this->list_size <= 1) {
        return;
    }
    
    // edge case: three items
    if (this->list_size == 3) {
        this->remove_at(1);
        return;
    }

    // iterate through list in reverse order to avoid errors when changes occur to indexes of shapes by the remove_at() func
    for (int i = this->list_size - 1; i > 0; i = i - 2) {
        this->remove_at(i);
    }

    return;
}

Shape* CanvasList::pop_front() {
    // list is empty, return null
    if (this->empty()) {
        return nullptr;
    }

    // memory management
    Shape* shapePopped = this->list_front->value; // to return at end of function
    ShapeNode* frontRemoved = this->list_front; // to be free'd

    // set head to second element
    this->list_front = this->list_front->next;

    delete frontRemoved; // free shape node

    // decrement size
    this->list_size--;

    return shapePopped; // return the removed element
}

Shape* CanvasList::pop_back() {
    // list is empty, return null
    if (this->empty()) {
        return nullptr;
    }

    // only one element in the list
    if (this->list_front->next == nullptr) {
        Shape* shapePopped = this->list_front->value; // save the shape popped to return at end of func
        delete this->list_front; // free the Node

        // update private member variables
        this->list_front = nullptr;
        this->list_size = 0;

        return shapePopped; // return the shape popped
    }

    // iterate to the second-to-last node
    ShapeNode* temp = this->list_front;
    ShapeNode* prev = nullptr;
    while (temp->next != nullptr) {
        prev = temp;
        temp = temp->next;
    }

    Shape* shapePopped = temp->value; // save the value to return
    delete temp; // free the Node

    // reset private member variables
    if (prev != nullptr) {
        prev->next = nullptr; // set the next of the second-to-last node to null
    } else {
        this->list_front = nullptr; // if there's only one element, set front to null
    }
    this->list_size--;


    return shapePopped; // return the removed element

}

ShapeNode* CanvasList::front() const {
    return this->list_front;
}

bool CanvasList::empty() const {
    return this->list_size == 0;
}

int CanvasList::size() const {
    return this->list_size;
}

int CanvasList::find(int x, int y) const {
    // iterate through list
    ShapeNode* temp = this->list_front;
    int index = 0;
    while (temp != nullptr) {
        if (temp->value->getX() == x && temp->value->getY() == y) { // check x and y values
            return index;
        } else {
            index++;
            temp = temp->next;
        }
    }

    return -1; // no matching shape found
}

Shape* CanvasList::shape_at(int index) const {
    // check if index invalid
    if (index >= this->list_size || index < 0) {
        return nullptr;
    }

    // iterate and find the index
    int currIndex = 0;
    ShapeNode* temp = this->list_front;
    while (temp != nullptr) {
        if (index == currIndex) {
            return temp->value; // return shape at that index
        } else {
            currIndex++;
            temp = temp->next;
        }
    }

    return nullptr; // in case for some reason index not found
    
}

void CanvasList::draw() const {
    ShapeNode* temp = this->list_front;
    while(temp != nullptr) {
        cout << temp->value->as_string() << endl;
        temp = temp->next; // increment to next node
    }
}

void CanvasList::print_addresses() const {
    ShapeNode* temp = this->list_front;
    while(temp != nullptr) {
        cout << "Node Address: " << temp << " Shape Address: " << temp->value << endl;
        temp = temp->next; // increment to next node
    }
}
