# Pointers

QSharedDataPointer
QExplicitlySharedDataPointer




## Pointers in Qt

### Thoughts

Maybe use a [QScopedPointer](https://doc.qt.io/qt-6/qscopedpointer.html#details) 
(or maybe a collection / array / bunch of QScoped Pointers)
on the parent object to hold the actual, original pointer to the child object.

That way, when the parent object is gone, the QScopedPointer
goes out of scope, and the objects get deleted.

And then have a regular [QPointer](https://doc.qt.io/qt-6/qpointer.html#details)
(which was generated from the QScopedPointer) 
as a foreign key on the other objects.

### QScopedPointer

[QScopedPointer](https://doc.qt.io/qt-6/qscopedpointer.html#details) is 
a pointer that goes on the stack, but object it points to
goes on the heap.

### QPointer

From [this page](https://www.kdab.com/psa-qpointer-has-a-terrible-name/) - 
QPointer is ... a smart pointer that does not participate in the ownership 
of a given object. Destroying the weak pointer has no effect whatsoever 
on the pointed-to object.

So we can do this, provided we don't share the object 
across threads via pointers:

```c_cpp

QPointer<MyQObject> ptr;

if (ptr)               // is the object still alive?
  ptr->doSomething();  // use it!

```

A guarded pointer, [QPointer](https://doc.qt.io/qt-6/qpointer.html#details), 
behaves like a normal C++ pointer T *, except that 
it is automatically cleared when the referenced object is destroyed 
(unlike normal C++ pointers, which become "dangling pointers" in such cases). 

T must be a subclass of QObject.

Guarded pointers are useful whenever you need to store a pointer to a QObject 
that is owned by someone else, and therefore might be destroyed 
while you still hold a reference to it. 

You can safely test the pointer for validity.

### QSharedPointer

[QSharedPointer](https://doc.qt.io/qt-6/qsharedpointer.html#details) holds 
a shared pointer by means of an external reference count 
(i.e., a reference counter placed outside the object). 

Like its name indicates, the pointer value is shared among all instances 
of QSharedPointer and QWeakPointer. 

The contents of the object pointed to by the pointer 
should not be considered shared, however: there is only one object. 
For that reason, QSharedPointer does not provide a way to detach 
or make copies of the pointed object.

So - probs not ideal for me just now. The object is shared equally, with
no one true owner.

I want each object - each fixture, state, cue, etc - to be owned by 
exactly one other item. 

Even if other items point to it, or it points to other items, 
I want it to be *owned* by exactly one item.

### Implicit Sharing

Implicit Sharing is effectively completely separate objects. There is some 
cleverness to share memory when copies are unchanged; 
but effectively all separate, independent objects.

See the QSharedData and QSharedDataPointer classes.

## Don't Use These

### QScopedPointerArray

Just a QScopedPointer that's designed to point to an array.

### QWeakPointer

Not directly usable to get the contents of the pointer. Only real
use case is to check if a pointer is still valid. Then you make a 
real pointer from this QWeakPointer.

[This page](https://web.archive.org/web/20170210074420/http://www.macieira.org/blog/2012/07/continue-using-qpointer/) 
says "Moreover, don’t use QWeakPointer except in conjunction with QSharedPointer."

### QSharedDataPointer

Used only for Implicit Sharing (see above).

### QExplicitlySharedDataPointer

QExplicitlySharedDataPointer is just like QSharedDataPointer except that 
member functions of QExplicitlySharedDataPointer do not do the automatic 
copy on write operation (detach()) that non-const members of QSharedDataPointer do
before allowing the shared data object to be modified.

This means that QExplicitlySharedDataPointers behave like regular C++ pointers, 
except that by doing reference counting and not deleting the shared data object 
until the reference count is 0, they avoid the dangling pointer problem.


## Regular C++ Pointers

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
