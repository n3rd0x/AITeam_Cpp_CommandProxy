#include "app.h"
#include <iostream>
#include <stdexcept>

int main(int argc, char* argv[]) {
    aiteam::App app;

    try {
        if(!app.init(argc, argv)) {
            std::cerr << "Failed to initialize application\n";
            return 1;
        }

        if(!app.run()) {
            std::cerr << "Application terminated with errors\n";
            return 1;
        }
    } catch(const std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
        return 1;
    } catch(...) {
        std::cerr << "Unknown exception occurred\n";
        return 1;
    }

    return 0;
}