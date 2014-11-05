#ifndef _prog1_h
#define _prog1_h

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

class Node {
  private:
    int data;
    bool dlt;
    Node *next;

  public:
    Node() {
        data = 0;
        dlt = 0;
    }
    Node(int d) {
        data = d;
        dlt = 0;
    }
    
    int isDeleted() {
        //cout << "Is it deleted?" << endl;
        if(dlt == 1) {
            //cout << "Yes." << endl;
            return 1;
        }
        else {
            //cout << "No." << endl;
            return 0;
        }
    }
    void setDelete(bool d) {
        //cout << "Marked as deleted." << endl;
        dlt = d;
    }
    void setData(int d) {
        //cout << "Setting data..." << endl;
        data = d;
        //cout << "data set" << endl;
    }
    int getData() const {
        //cout << "Getting data..." << endl;
        return data;
    }
    void setNext(Node *n) {
        next = n;
    }
    Node *getNext() const {
        return next;
    }
};

//----------------

class HashTable {
  private:
    Node **table;
    int size;
    
  public:
    HashTable(int size) {
        this->size = size;
        table = new Node*[size];
        for (int i=0; i<size; i++)
            table[i] = NULL;
    }
    
    int insert(int d) { //table
        int index =0;
        if (d < 0) {
            int pos = d * -1;
            index = (pos % size);
        }
        else {
            index = (d % size);
        }
        int initIndex = index;
    
        do {
            //cout << "Entered insert while loop." << endl;
            if (table[index] == NULL) {
                table[index] = new Node(d);
                cout << d << " inserted" << endl;
                return 1;
            }
            else if (table[index]->isDeleted()==1) {
                table[index]->setDelete(0);
                table[index]->setData(d);
                cout << d << " inserted" << endl;
                return 1;
            }
            else if (table[index]->getData() == d && table[index]->isDeleted() == 0) {
                table[index]->setDelete(0);
                cout << d << " already present" << endl;
                return 1;
            }
            else if (table[index]->getData() == d && table[index]->isDeleted() == 1) {
                table[index]->setDelete(0);
                cout << d << " inserted" << endl;
                return 1;
            }
            else
                index = (index + 1) % size;
                
        } while (initIndex != index);
        cout << "Error: Could not insert " << d << endl;
        return 0;
    }
    
    int lookup(int d) const { //
        //cout << "Looking up..." << endl;
        int index = (d % size);
        int initIndex = index;
        //cout << "Looking in index = " << index << endl;
        
        do {
            //cout << "In lookup do-while loop." << endl;
            if (table[index] == NULL) {
                cout << d << " not found" << endl;
                return 0;
            }
            else if(table[index]->getData() == d && table[index]->isDeleted() == 0) {
                cout << d << " found" << endl;
                return 1;
            }
            else {
                //cout << "Rehashing..." << endl;
                index = (index + 1) % size;
            }
        } while (table[index] != NULL && index != initIndex);
        cout << d << " not found" << endl;
        return 0;
    }
    
    int deleteMin() { //heap
        int mIndex = -1;
        for (int i=0; i<size; i++) {
            if (table[i]!=NULL && table[i]->isDeleted()!=1) {
                if (mIndex == -1)
                    mIndex = i;
                else if (table[i]->getData() < table[mIndex]->getData()) {
                    mIndex = i;
                }
            }
        }
        if (mIndex == -1) {
            return 0;
        }
        else {
            table[mIndex]->setDelete(1);
            //cout << "Minimum value " << table[mIndex]->getData() << " deleted" << endl;
            return 1;
        }
    }
    
    int deleteKey(int d) { //table
        int index = (d % size);
        int initIndex = index;
        //cout << "Looking in index = " << index << endl;
        if (table[index] == NULL) {
            cout << d << " not found" << endl;
            return 0;
        }
        
        do {
            //cout << "In lookup do-while loop." << endl;
            if(table[index]->getData() == d && table[index]->isDeleted() == 0) {
                table[index]->setDelete(1);
                cout << d << " deleted" << endl;
                return 1;
            }
            else {
                //cout << "Rehashing..." << endl;
                index = (index + 1) % size;
            }
        } while (table[index] != NULL && index != initIndex);
        cout << d << " not found" << endl;
        return 0;
    }
    
    void print() const {
        //cout << "HashTable = ";
        for (int i=0; i<size; i++) {
            if (table[i] != NULL && table[i]->isDeleted() == 0) {
                cout << table[i]->getData() << " ";
            }
        }
        cout << endl;
    }
};

//--------------------

class MinHeap {
private:
    Node **heap;
    int size;
    
public:
    MinHeap(int size) {
        this->size = size;
        heap = new Node*[size];
        for (int i=0; i<size; i++) {
            heap[i] = NULL;
        }
    }
    
    int insert(int d) {
        //Check if heap is full
        if (heap[size-1]!=NULL && heap[size-1]->isDeleted()==0) {
            cout << "Error: Heap full; cannot insert " << d << endl;
            return 0;
        }
        //Loop to find insertion point
        for (int i=0; i<size; i++) {
            //If no node with value greater than d was found,
            //and if the current node has not been initialized.
            //Create a new node with value d.
            if (heap[i] == NULL) {
                heap[i] = new Node(d);
                heap[i]->setDelete(0);
                //cout << d << " inserted" << endl;
                return 1;
            }
            else if (heap[i]!=NULL && heap[i]->isDeleted()==1) {
                heap[i]->setData(d);
                heap[i]->setDelete(0);
                //cout << d << " inserted" << endl;
                return 1;
            }
            //Check if key already in heap
            else if (heap[i]!=NULL && heap[i]->getData()==d && heap[i]->isDeleted()==0) {
                //If a live node with value d is in heap.
                if (heap[i]->isDeleted()==0) {
                    //cout << d << " already present" << endl;
                    return 0;
                }
                //If last node in heap has value d, but was deleted.
                else if (heap[i]->isDeleted()==1) {
                    heap[i]->setDelete(0);
                    //cout << d << " inserted" << endl;
                    return 1;
                }
            }
            //If value in index is greater than key, then key is not present - insert.
            else if (heap[i]!=NULL && heap[i]->isDeleted()==0 && heap[i]->getData()>d) {
                //Shift all nodes after index (i-1) right. Begin at penultimate node.
                for (int j=size-2; j>=i; j--) {
                    if (heap[j]!=NULL && heap[j]->isDeleted()==0 && heap[j+1]==NULL) {
                        heap[j+1] = new Node(heap[j]->getData()); //Would only run on first loop.
                    }
                    //If the next node is not empty.
                    else if (heap[j]!=NULL && heap[j]->isDeleted()==0 && heap[j+1]!=NULL){
                        heap[j+1]->setData(heap[j]->getData());
                        heap[j+1]->setDelete(0);
                    }
                }
                //After all nodes have been shifted...
                //i should be index of first node in heap that was greater than d.
                //Change value of this node to d.
                heap[i]->setData(d);
                //cout << d << " inserted" << endl;
                return 1;
            }
            
        }
        //If by some fluke the loop completes...
        cout << "Error: Could not insert " << d << endl;
        return 0;
    }
    
    int lookup(int d) const {
        for (int i=0; i<size; i++) {
            if (heap[i]!=NULL && heap[i]->isDeleted()==0 && heap[i]->getData()>d) {
                //cout << d << " not found" << endl;
                return 0;
            }
            else if (heap[i] != NULL && heap[i]->isDeleted() == 0 && heap[i]->getData() == d) {
                //cout << d << " found" << endl;
                return 1;
            }
        }
        //cout << d << " not found" << endl;
        return 0;
    }
    
    int deleteMin() { //Heap is superior
        if (heap[0] != NULL) {
            int minValue = heap[0]->getData();
            int i=0;
            for (i=0; heap[i+1]!=NULL && heap[i+1]->isDeleted()==0; i++) {
                heap[i]->setData(heap[i+1]->getData()); //Shift all nodes towards root.
            }
            heap[i]->setDelete(1); //Delete last key in heap.
            cout << "Minimum key " << minValue << " deleted" << endl;
            return 1;
        }
        //cout << "Heap is empty; nothing to delete." << endl;
        return 0;
    }
    
    int deleteKey(int d) { //table
        //If key is at root, run deleteMin()
        /*if (heap[0]!=NULL && heap[0]->getData()==d) {
            int i=0;
            for (i=0; heap[i+1]!=NULL && heap[i+1]->isDeleted()==0; i++) {
                heap[i]->setData(heap[i+1]->getData());
                heap[i]->setDelete(0);
            }
            heap[i]->setDelete(1);
            cout << d << " deleted" << endl;
            return 1;
        }*/
        for (int i=0; i<size; i++) {
            //If heap[i] > key
            //cout << "For loop: " << i << endl;
            if (heap[i]!=NULL && heap[i]->isDeleted()==0 && heap[i]->getData()>d) {
                //cout << d << " not found" << endl;
                return 0;
            }
            //If heap[i] = key
            else if (heap[i]!=NULL && heap[i]->isDeleted()==0 && heap[i]->getData()==d) {
                int j=i;
                //cout << "key found in index " << i << endl;
                for (j=i; heap[j]!=NULL || heap[j]->isDeleted()==0; j++) {
                    //cout << "Shifting index " << j << endl;
                    if (heap[j+1] == NULL || heap[j+1]->isDeleted()==1) {
                        //cout << "Next node is NULL." << endl;
                        heap[j]->setDelete(1);
                        break;
                    }
                    else if (heap[j+1]!=NULL && heap[j+1]->isDeleted()==0) {
                        heap[j]->setData(heap[j+1]->getData());
                    }
                }
                //cout << "Shifting done." << endl;
                heap[j]->setDelete(1);
                //cout << d << " deleted" << endl;
                return 1;
            }
        }
        //cout << d << " not found" << endl;
        return 0;
    }
    
    void print() const {
        //cout << "Min-Heap  = ";
        for (int i=0; i<size; i++) {
            if (heap[i] != NULL && heap[i]->isDeleted() == 0) {
                cout << heap[i]->getData() << " ";
            }
        }
        cout << endl;
    }
};

#endif
