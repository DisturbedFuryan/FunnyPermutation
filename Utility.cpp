#include <iostream>
#include <limits>
#include "Utility.hpp"

using namespace std;

void IUtility::printAdditionalZeros(const unsigned number, const unsigned digitsNumber) {
    for (unsigned u = 1, multiple = 10; u < digitsNumber; ++u, multiple *= 10) {
        if (number < multiple) {
            cout << "0";
        }
    }
}

unsigned IUtility::getUnsigned(const char* statement) {
    long number;
    
    while (((cout << statement) && !(cin >> number)) || (number < 0)) {
        cout << "That wasn't an unsigned number!\n";
        
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    cout << endl;
    
    return static_cast<unsigned>(number);
}

unsigned short IUtility::getUnsignedShort(const char* statement) {
    long number;
    
    while (((cout << statement) && !(cin >> number)) || (number < 0)
           || (number > numeric_limits<unsigned short>::max())) {
        cout << "That wasn't an unsigned short number!\n";
        
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    cout << endl;
    
    return static_cast<unsigned short>(number);
}
