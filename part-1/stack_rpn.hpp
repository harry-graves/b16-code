#ifndef __stack_rpn__
#define __stack_rpn__

#include "stack.hpp"
#include <cassert>
#include <functional>

template <typename T>
void plus(Stack<T> &stack)
{
    T value1 = stack.top();
    stack.pop();

    T value2 = stack.top();
    stack.pop();
    
    stack.push(value1 + value2);
};

template <typename T>
void minus(Stack<T> &stack)
{
    T value1 = stack.top();
    stack.pop();

    T value2 = stack.top();
    stack.pop();

    stack.push(value1 - value2);
};

template <typename T>
void multiplies(Stack<T> &stack)
{
    T value1 = stack.top();
    stack.pop();

    T value2 = stack.top();
    stack.pop();
    
    stack.push(value1 * value2);
};

template <typename T>
void divides(Stack<T> &stack)
{
    T value1 = stack.top();
    stack.pop();

    T value2 = stack.top();
    stack.pop();

    stack.push(value2 / value1);
};

template <typename T>
void negates(Stack<T> &stack)
{
    T value1 = stack.top();
    stack.pop();

    stack.push(-value1);    
};

#endif // __stack_rpn__