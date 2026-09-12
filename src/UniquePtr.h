#ifndef UNIQUE_PTR_H
#define UNIQUE_PTR_H

#include <utility>

// Your implementation here
template <typename T>
class UniquePtr{
    public:
        // init constructor
        UniquePtr(T* p = nullptr) : mPtr{p}{
        }

        // destructor
        ~UniquePtr(){
            if (mPtr != nullptr){
                delete mPtr;
                mPtr = nullptr;
            }
        }

        // move constructor
        UniquePtr(UniquePtr &&uniquePtr){
            T* temp = uniquePtr.release();
            reset(temp);
        }

        // dereference operator
        T& operator*() const{
            return *mPtr;
        }

        // get pointer using arrow operator
        T* operator->() const{
            return mPtr;
        }

        // get pointer using function
        T* get() const{
            return mPtr;
        }

        // comparison operator
        bool operator==(const UniquePtr<T>& other) const{
            return mPtr == other.get();
        }

        // release method
        T* release(){
            T* temp = mPtr;
            mPtr = nullptr;
            return temp;
        }

        // reset unique ptr with a new pointer
        void reset(T* newPtr = nullptr){
            if (mPtr != nullptr){
                delete mPtr;
            }
            mPtr = newPtr;
        }

        void swap(UniquePtr<T>& other){
            std::swap(this, other);
        }

        operator bool() const{
            return mPtr == nullptr;
        }

    private:
        T* mPtr;
};

// creates a T object on the heap with arguments "Args", and makes a new UniquePtr that points to it
template <typename T, typename... Args>
UniquePtr<T> makeUnique(Args&&... args){
    T* ptr = new T(std::forward<Args>(args)...); // instantiate T object on heap with args
    return UniquePtr<T>(ptr); // make a unique ptr out of it
}



#endif
