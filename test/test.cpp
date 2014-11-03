//
//  test.cpp
//  
//
//  Created by Jeffrey Chen on 10/31/14.
//
//

#include "test.h"
using namespace std;

int main() {
    
    cout << "<op> <key>\n";
    cout << "0: insert(i)\n";
    cout << "1: lookup(i)\n";
    cout << "2: deleteMin()\n";
    cout << "3: delete(i)\n";
    cout << "4: print()\n";
    cout << "5: exit\n";
    
    int sel = 0, i = 0;
    cin >> sel;
    while (sel != 5) {
        if (sel == 0) {
            cout << "insert(i) selected\n";
            cin >> i;
            cout << "given key " << i << "\n";
            cin >> sel;
        }
        else if (sel == 1) {
            cout << "lookup(i) selected\n";
            cin >> sel;
        }
        else if (sel == 2) {
            cout << "deleteMin() selected\n";
            cin >> sel;
        }
        else if (sel == 3) {
            cout << "delete(i) selected\n";
            cin >> sel;
        }
        else if (sel == 4) {
            cout << "print() selected\n";
            cin >> sel;
        }
    }
    return 0;
}