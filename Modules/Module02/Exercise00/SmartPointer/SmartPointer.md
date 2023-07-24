❓ What is memory leak? And what is a dangling pointer? What is a smart pointer?

A memory leak and a dangling pointer are both issues related to memory management in a program. 

### 1. Memory Leak:
Memory leaks occur when dynamically allocated memory is not properly deallocated or freed when it is no longer needed. 
This means that memory that was allocated during the program's execution remains allocated.
Memory leaks can happen when memory is dynamically allocated using functions like `new` or `malloc` and the corresponding deallocation (using `delete` or `free`) is either forgotten. 
If memory leaks accumulate over time, they can cause a program to consume excessive memory and eventually lead to performance issues or even crashes.

Here's an example of a memory leak in C++. 
In this example, memory is allocated using `new int`, but there is no corresponding `delete` statement to free the allocated memory. 
As a result, each time `foo()` is called, memory is leaked because it is never deallocated.
    <code>
    void foo() {
        // Memory allocation
        int* ptr = new int;  
        // forget to deallocate ptr
    }
    int main() {
        foo();
        return 0;
    }
    </code>
<aside> 💡 Ensure that memory allocated dynamically is properly deallocated when it is no longer needed. </aside>

### 2. Dangling Pointer:
A dangling pointer is a pointer that points to a memory location that has been freed or deallocated. 
It occurs when a pointer is accessed after the object it was pointing to has been deleted or has gone out of scope.
Accessing a dangling pointer can lead to undefined behavior, as the memory it points to may have been reallocated for other purposes or may no longer be accessible.

Here's an example of a dangling pointer in C++. 
In this example, the `createInt()` function returns a pointer to a local variable `x`. 
However, once the function returns, the local variable goes out of scope, and the pointer `ptr` becomes a dangling pointer. 
Accessing `danglingPtr` in `main()` will result in undefined behavior since the memory it points to is no longer valid.
    <code>
        int* createInt() {
            int x = 5;
            int* ptr = &x;  // ptr points to a local variable on the stack
            return ptr;
        }
        int main() {
            int* danglingPtr = createInt();
            // Here, danglingPtr points to a memory location that is no longer valid
            // Accessing it can lead to undefined behavior
            return 0;
        }
    </code>

<aside> 💡 To avoid dangling pointers, ensure that pointers are not used to access memory locations that have been deallocated or gone out of scope. It is a good practice to set pointers to `nullptr` after deallocating the memory they point to, to avoid accidentally accessing them. </aside>

### 3. Smart Pointer

Smart Pointer (unique & shared) can be helpful when working with memory allocation in C++.

1. Unique Pointers (std::unique_ptr):
   - Unique pointers are a type of smart pointer that manage the ownership of a dynamically allocated object.
   - They ensure exclusive ownership of the object, meaning that only one unique pointer can own the object at a time.
   - When the unique pointer goes out of scope or is explicitly reset, it automatically deletes the managed object.
   - Unique pointers provide lightweight and efficient memory management without the need for manual memory deallocation.

2. Shared Pointers (std::shared_ptr):
   - Shared pointers are another type of smart pointer that manage the ownership of a dynamically allocated object.
   - They enable multiple shared pointers to own and reference the same object.
   - Shared pointers keep track of the number of references to the object using reference counting.
   - When the reference count reaches zero (i.e., when all shared pointers are destroyed or reset), the managed object is automatically deleted.
   - Shared pointers provide automatic memory management for objects shared among multiple parts of the program, preventing premature deallocation and memory leaks.

<aside> 💡 
Key points:
- Both unique pointers and shared pointers automatically deallocate the managed objects when they go out of scope or are explicitly reset.
- Unique pointers provide exclusive ownership, while shared pointers allow multiple shared owners.
- Unique pointers are generally more efficient and have lower overhead compared to shared pointers.
- Shared pointers offer the flexibility of sharing objects between multiple parts of the program but come with a small performance cost due to the reference counting mechanism.</aside> 

It's important to choose the appropriate smart pointer based on the ownership semantics and requirements of your program to ensure proper memory management and prevent memory leaks or dangling pointers.

See Module 01 Exercise 0 for an example with smart (shared) pointers.
