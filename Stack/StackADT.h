// Array-based stack implementation

#include <QString>
template <typename E>
class StackADT {
private:
    StackADT(const StackADT&) {}// Constructor
public:
    StackADT() {}// Constructor
    virtual ~StackADT() {} // Destructor

    // Reinitialize the stack.  The user is responsible for
    // reclaiming the storage used by the stack elements.
    virtual void clear() = 0;

    // Push an element onto the top of the stack.
    // it: The element being pushed onto the stack.
    virtual void push(const E& it) = 0;

    // Remove the element at the top of the stack.
    // Return: The element at the top of the stack.
    virtual E pop() = 0;

    // Return: A copy of the top element.
    virtual const E& topValue() const = 0;

    // Return: The number of elements in the stack.
    virtual int length() const = 0;

    //Return: True if the stack has size 0; otherwise returns false.
    virtual bool isEmpty() = 0;

//    //Return: A string which contains the actual state of the stack

//    //Example:
//    ///QStack<int> test;
//    ///test.push(1);
//    ///test.push(2);
//    ///test.push(3);
//    ///test.toString();
//    //Returns: 3"\n"2"\n"1"\n"

//    //Doesn't change the state of the stack!!

    virtual QString toString() = 0;
};

