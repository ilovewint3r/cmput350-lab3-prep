#include "UniquePtr.h"
#include <iostream>

int main() {
    UniquePtr<int> ptr(new int(5));
    std::cout << "UniquePtr directly initialized with new int 5: " << *ptr << std::endl;
    auto newPtr = makeUnique<int>(52);

    std::cout << "makeUnique initialized int, should print 52: " << *newPtr << std::endl;

    UniquePtr<int> moved(std::move(ptr));
    UniquePtr<int> blankUniquePtr;
    if (ptr == blankUniquePtr){
        std::cout << "Old pointer is correctly set to blank." << std::endl;
    }

    std::cout << "New pointer that was moved to should be 5" << *moved << std::endl;
    return 0;
}
