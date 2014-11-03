#include "prog1.h"
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
    /*
    FILE *file;
    if(argc != 3) {
        cout << "usage: ./prog1 < input.txt > output.txt" << endl;
        exit(1);
    }
    if((file=fopen(argv[1],"r"))==NULL) {
        printf("Could not open file %s\n",argv[1]);
        exit(1);
    }
    */
    
    int tableSize = 0, keys = 0;
    
    cin >> tableSize;
    cin >> keys;
    
    /*
    cout << "Table Size = " << tableSize << endl;
    cout << "nKeys = " << keys << endl;
    */
    
    LinkedList *table = new LinkedList(tableSize);
    
    
    int sel = 0, i = 0;
    cin >> sel;
    while (sel != 5) {
        i = 0;
        if (sel == 0) {
            cin >> i;
            table->insert(i);
            cin >> sel;
        }
        else if (sel == 1) {
            cin >> i;
            table->lookup(i);
            cin >> sel;
        }
        else if (sel == 2) {
            table->deleteMin();
            cin >> sel;
        }
        else if (sel == 3) {
            cin >> i;
            table->deleteKey(i);
            cin >> sel;
        }
        else if (sel == 4) {
            table->print();
            cin >> sel;
        }
    }
    return 0;
}