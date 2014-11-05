#include "prog1.h"
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
    int size = 0, keys = 0;
    
    //Read from input1.txt
    if (argc == 2) {
        FILE *file;
        file = fopen(argv[1],"r");
        cin >> size;
        cin >> keys;
    }
    else {
        cin >> size;
        cin >> keys;
    }
    
    /*
    cout << "Table Size = " << tableSize << endl;
    cout << "nKeys = " << keys << endl;
    */
    
    
    HashTable *table = new HashTable(size); //Initialize hash table.
    MinHeap *heap = new MinHeap(size); //Initialize min-heap.
    
    //Parse!
    int sel = 0, i = 0;
    cin >> sel;
    while (sel != 5) {
        i = 0;
        if (sel == 0) { //insert(i)
            cin >> i;
            table->insert(i);
            heap->insert(i);
            cin >> sel;
        }
        else if (sel == 1) { //lookup(i)
            cin >> i;
            table->lookup(i);
            heap->lookup(i);
            cin >> sel;
        }
        else if (sel == 2) { //deleteMin()
            heap->deleteMin();
            table->deleteMin();
            cin >> sel;
        }
        else if (sel == 3) { //delete()
            cin >> i;
            table->deleteKey(i);
            heap->deleteKey(i);
            cin >> sel;
        }
        else if (sel == 4) { //print()
            //table->print();
            heap->print();
            cin >> sel;
        }
    }
    //Deallocate memory
    free(table);
    free(heap);
    return 0;
}