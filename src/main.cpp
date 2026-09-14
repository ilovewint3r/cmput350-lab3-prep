#include "UniquePtr.h"
#include <iostream>

class A{
    public:
        int a;
};

class B : public A {
};

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
    std::cout << "New pointer that was moved to should be 5: " << *moved << std::endl;

    delete newPtr.release();
    // equality with nullptr
    if (newPtr == blankUniquePtr){
        std::cout << "Another old pointer is correctly set to blank." << std::endl;
    }

    ptr.reset();
    if (!ptr){
        std::cout << "Again another old pointer is correctly set to blank." << std::endl;
    }

    ptr.reset(new int(123));
    std::cout << "Reset with new value: " << *ptr << std::endl;

    ptr.swap(moved);
    std::cout << "Swapped with moved, ptr should hold 5: " << *ptr << std::endl;
    std::cout << "Swapped with ptr, moved should hold 123: " << *moved << std::endl;

    auto useGet = moved.get();
    std::cout << "Dereferenced raw pointer from moved, should hold 123: " << *useGet << std::endl;

    UniquePtr<B> bPtr = makeUnique<B>();
    bPtr->a = 67;
    UniquePtr<A> aPtr(std::move(bPtr));
    std::cout << "Convert constructor result: " << aPtr->a << std::endl;
    if (!bPtr){
        std::cout << "bPtr correctly set to nullptr" << std::endl;
    }

    return 0;
}
