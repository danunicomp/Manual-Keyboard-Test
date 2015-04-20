#include <iostream>
#include <vector>
#include <cstdlib>

#include "cls_UniCodes.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    vector<int> buffer;
    
    cls_UniCodes Keyboard;

    do{    
        system("stty -echo");
        buffer = Keyboard.GetUnicodeBuffer();

        cout << "Buffer: ";
    for (unsigned int x=0; x<buffer.size(); ++x) {
        cout << buffer[x] << " " ;     
    }
    cout << endl;
    system("stty echo");
    } while (buffer[1] !=45);
    system("stty echo");
    return 0;
}

