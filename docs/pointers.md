# Pointers

## Pointers in Qt

### QSharedPointer

QSharedPointer holds a shared pointer by means of an external reference count 
(i.e., a reference counter placed outside the object). 

Like its name indicates, the pointer value is shared among all instances 
of QSharedPointer and QWeakPointer. 

The contents of the object pointed to by the pointer 
should not be considered shared, however: there is only one object. 
For that reason, QSharedPointer does not provide a way to detach 
or make copies of the pointed object.

### QPointer

A guarded pointer, QPointer<T>, behaves like a normal C++ pointer T *, except that 
it is automatically cleared when the referenced object is destroyed 
(unlike normal C++ pointers, which become "dangling pointers" in such cases). 

T must be a subclass of QObject.

Guarded pointers are useful whenever you need to store a pointer to a QObject 
that is owned by someone else, and therefore might be destroyed 
while you still hold a reference to it. 

You can safely test the pointer for validity.





## Pointers in C++

```c_cpp
    #include <iostream>
    #include <string>

    int main() {
        std::string food = "Pizza";  // Variable declaration
        std::string* ptr = &food;    // Pointer declaration

        // Plain old string
        std::cout << "food: " << food << "\n";
        // food: Pizza

        // Reference: Output the memory address of food with the pointer
        std::cout << "ptr: " << ptr << "\n";
        // ptr: 0x7ffc9187a730

        // Dereference: Output the value of food with the pointer
        std::cout << "*ptr: " << *ptr << "\n";
        // *ptr: Pizza

        return 0;
    }
```
