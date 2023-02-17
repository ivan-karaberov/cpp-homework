#include <iostream>
#include "stack.h"

int main() {
    my::stack<double> stk;
    stk.push(1);
    stk.push(4);
    stk.push(3.61);

    std::cout << "Please enter, finder element: " << std::endl;
    double  findElement;
    std::cin >> findElement;

    for (int i = 0; i < stk.size();) {
        if (findElement == stk.pop()) {
            std::cout << findElement << " Element, finded" << std::endl;
            break;
        }
    }
   
    return 0;
}