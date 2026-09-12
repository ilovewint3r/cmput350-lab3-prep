#include "UniquePtr.h"
#include <iostream>

int main() {
    UniquePtr<int> ptr(new int(5));
    auto newPtr = makeUnique<int>(52);
    std::cout << *newPtr << std::endl;
    // they test all methods here...
    return 0;
}
