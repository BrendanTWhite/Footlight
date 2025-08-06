# Pointers in C++

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
