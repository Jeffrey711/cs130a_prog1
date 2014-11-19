#include "prog1.h"
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
    int size = 0, commands = 0;
    cin >> size;
    cin >> commands;
    
    HashTable *table = new HashTable(size); //Initialize hash table.
    MinHeap *heap = new MinHeap(size); //Initialize min-heap.
    
    //User input
    int sel = 0, i = 0, count=0;
    cin >> sel;
    
    while (count < commands && sel != 5) {
        i = 0;
        if (sel == 0) { //insert(i)
            cin >> i;
            table->insert(i);
            heap->insert(i);
            cin >> sel;
            count++;
        }
        else if (sel == 1) { //lookup(i)
            cin >> i;
            table->lookup(i);
            heap->lookup(i);
            cin >> sel;
            count++;
        }
        else if (sel == 2) { //deleteMin()
            heap->deleteMin();
            table->deleteMin();
            cin >> sel;
            count++;
        }
        else if (sel == 3) { //delete()
            cin >> i;
            table->deleteKey(i);
            heap->deleteKey(i);
            cin >> sel;
            count++;
        }
        else if (sel == 4) { //print()
            //table->print();
            heap->print();
            cin >> sel;
            count++;
        }
        //If invalid command...
        else if (sel !=5) {
            cout << "Error: Invalid command." <<endl;
            cout << "0: insert key" << endl;
            cout << "1: lookup key" << endl;
            cout << "2: delete minimum key" << endl;
            cout << "3: delete key" << endl;
            cout << "4: print keys" << endl;
            cout << "5: end program" << endl;
            cin >> sel;
        }
    }
    //Deallocate memory
    free(table);
    free(heap);
    return 0;
}