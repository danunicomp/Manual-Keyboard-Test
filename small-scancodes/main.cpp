#include <iostream>
#include <vector>


#include "cls_UniCodes.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    vector<int> buffer;
    
    cls_UniCodes Keyboard;

    do{    
        buffer = Keyboard.GetUnicodeBuffer();

        cout << "Buffer: ";
    for (unsigned int x=0; x<buffer.size(); ++x) {
        cout << buffer[x] << " " ;     
    }
    cout << endl;
    } while (buffer[1] !=45);
    
    return 0;
}

