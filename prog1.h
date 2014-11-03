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
        cout << "Is it deleted?" << endl;
        if(dlt == 1) {
            cout << "Yes." << endl;
            return 1;
        }
        else {
            cout << "No." << endl;
            return 0;
        }
    }
    
    int setDelete() {
        cout << "Marked as deleted." << endl;
        return dlt;
    }

    void setData(int d) {
        cout << "Setting data..." << endl;
        data = d;
    }

    int getData() const {
        cout << "Getting data..." << endl;
        return data;
    }
};

//----------------

class LinkedList {
private:
    Node **table;
    int tableSize;
    
public:
    LinkedList(int tableSize) {
        this->tableSize = tableSize;
        table = new Node*[tableSize];
        for (int i=0; i<tableSize; i++)
            table[i] = NULL;
    }
    
    int insert(int d) {
        if (this->lookup(d) == 1) {
            cout << d << " already present" << endl;
            return 0;
        }
        else {
            int index = (d % tableSize);
            int initIndex = index;
            cout << "index = " << index << endl;
        
            do {
                cout << "Entered insert while loop." << endl;
                if (table[index] == NULL) {
                    table[index]->setData(d);
                    cout << d << " inserted" << endl;
                }
                
                if (table[index]->getData() == d && table[index]->isDeleted() == 1) {
                    table[index]->setData(d);
                    cout << d << " inserted" << endl;
                    return 1;
                }
                else if (initIndex != index)
                    index = (index + 1) % tableSize;
            } while (initIndex != index);
        return 0;
        }
    }
    
    int lookup(int d) const {
        cout << "Looking up..." << endl;
        int index = (d % tableSize);
        int initIndex = index;
        cout << "Index = " << index << endl;
        if (table[index] == NULL) {
            return 0;
        }
        
        do {
            cout << "In lookup do-while loop." << endl;
            if(table[index]->getData() == d && table[index]->isDeleted() == 0) {
                cout << d << " found" << endl;
                return 1;
            }
            else {
                cout << "Rehashing..." << endl;
                index = (index + 1) % tableSize;
            }
        } while (table[index] != NULL && index != initIndex);
        cout << d << " not found" << endl;
        return 0;
    }
    
    int deleteMin() {
        return 0;
    }
    
    int deleteKey(int d) {
        for(int i=0; i<tableSize; i++) {
            if(table[i]->getData() == d) {
                table[i]->setDelete();
                return 1;
            }
        }
        return 0;
    }
    
    void print() const {
        for (int i=0; i<tableSize; i++) {
            cout << table[i] << " ";
        }
        cout << endl;
    }
};

#endif
