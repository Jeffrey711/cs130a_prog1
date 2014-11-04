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
        //cout << "Insert into index = " << index << endl;
    
        do {
            //cout << "Entered insert while loop." << endl;
            if (table[index] == NULL) {
                table[index] = new Node(d);
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
    
    void deleteMin() { //heap
        cout << "Minimum key " << "i" << " deleted" << endl;
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
        for (int i=0; i<size; i++) {
            if (table[i] != NULL && table[i]->isDeleted() == 0) {
                cout << table[i]->getData() << " ";
            }
        }
        cout << endl;
    }
};

//--------------------
/*
class MinHeap {
private:
    Node **heap;
    int Size;
    
public:
    MinHeap(int size) {
        this->size = size;
        heap = new Node*[size];
        for (int i=0; i<size; i++) {
            heap[i] = NULL;
        }
    }
    
    int insert(int d) {
        if (heap[size])
        for (int i=0; i<size; i++) {
            if (heap[i] == NULL) {
                heap[i] = new Node(d);
                cout << d << " inserted" << endl;
                return 1;
            }
            
        }
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
    
    void deleteMin() { //heap
        cout << "Minimum key " << "i" << " deleted" << endl;
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
        for (int i=0; i<size; i++) {
            if (table[i] != NULL && table[i]->isDeleted() == 0) {
                cout << table[i]->getData() << " ";
            }
        }
        cout << endl;
    }
};
*/
 
#endif
