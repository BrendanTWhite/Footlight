# Sharing

<https://doc.qt.io/qt-6/implicit-sharing.html>

## Implicit Sharing

See <https://doc.qt.io/qt-6/implicit-sharing.html>

Data is duplicated ONLY when it is changed.

So you can pass round many copies of an object, and (if none are changed)
they are all pointers to the same object in memory. So no memory is wasted.

They are still logically separate though. If any one of them is altered,
that one is extracted to its own copy before its data is altered.

So effectively they are all separate copies, and can be modified independently.
"you should treat separate instances of them as separate objects".

"Object assignment (with operator=()) for implicitly shared objects is implemented using shallow copies",
ie only a new pointer.

MIGHT be OK for eg fixtures, PROVIDED we can be confident it's never modified.

## QSharedPointer

## QSharedDataPointer
