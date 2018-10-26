//
//  AdditionScriptingInterface.cpp
//  interface
//
//  Created by Raveena Jain on 10/25/18.
//

#include <stdio.h>
#include <typeinfo>
#include <iostream>

#include "AdditionScriptingInterface.h"

using namespace std;


template <class T>
// takes two values and returns result of adding them
T addTwo (T x, T y) {
    if (typeid(x) == typeid(1) || typeid(y) == typeid(1) ||
        typeid(x) == typeid((float)1.234) || typeid(y) == typeid((float)1.234) ||
        typeid(x) == typeid((double)1.2) || typeid(y) == typeid((double)1.2)) {
        return x + y;
    } else if (typeid(x) == typeid("x") || typeid(y) == typeid("x") ||
               typeid(x) == typeid('y') || typeid(y) == typeid('y')) {
        return x + y;
    } else {
        std::cout << "Error in adding values" << std::endl;
        return 0;
    }
}

// pseudocode example tests:
// int ix = 1, iy = 2;
// double dx = 2.1, dy = 2.2;
// float fx = 3.456, fy = 7.809;
// char cx = 'hello', cy = 'world;
// string sx = "hello", sy = "world";
// vector vx = [1, 2], vy = [3, 4];
// boolean bx = true, by = false;
//
// addTwo(ix, iy) -> 3
// addTwo(dx, dy) -> 3.3
// addTwo(fx, fy) -> 11.265
// addTwo(cx + cy) -> 'helloworld'
// addTwo(sx, sy) -> "helloworld"
//
//addTwo(ix, dy) -> 3.2
//addTwo(dx, fy) -> 9.909
//addTwo(fx, iy) -> 2.456
//addTwo(cx + sy) -> "helloworld"
//
//addTwo(ix, sy) -> "Error in adding values"
//addTwo(dx, cy) -> "Error in adding values"
//addTwo(fx, sy) -> "Error in adding values"
//addTwo(cx + iy) -> "Error in adding values"
//addTwo(bx, by) -> "Error in adding values"
//addTwo(vx, vy) -> "Error in adding values"


