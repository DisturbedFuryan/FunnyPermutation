#include <iostream>
#include <cstdlib>

#include "App.h"

int main(int argc, char** argv) {
    CApp app(4, CApp::SteinhausJohnsonTrotter);
    
    return EXIT_SUCCESS;
}
