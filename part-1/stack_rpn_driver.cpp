#include <iostream>

#include "stack.hpp"
#include "stack_rpn.hpp" // Put your code in this file
#include "iomanip"

int main(int argc, char **argv)
{
    // Basic interface
    auto stack = Stack<double>(100);    // Set to double to ensure that division output is not rounded
    stack.push(3);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    plus(stack);
    multiplies(stack);
    divides(stack);
    negates(stack);
    //std::cout << std::fixed << std::showpoint;
    //std::cout << std::setprecision(5);
    std::cout << "3 2 3 4 + * / neg = " << stack.top() << '\n';

    // Advanced interface (optional)
    // stack << 2 << 2 << 3 << plus << multiplies;
    // std::cout << "2 2 2 + * = " << stack.top() << '\n';

    return 0;
}
