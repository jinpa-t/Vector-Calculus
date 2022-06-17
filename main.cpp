/**
 * file: main.hpp
 * Author: Jinpa Tsering
 * Date: 6/17/2022
 * Description: Test functinos from calculus.h
 * 
*/

#include <iostream>
#include <cmath>
#include "calculus.hpp"

int main() {
    calculus::Point3D p = {4,4,4};
    calculus::Point3D q = {2,2,2};
    calculus::Point3D a = {2,2,-2};
    calculus::Point3D b = {-2,1,-1};
    
    calculus::Point3D i = {4,2,-1};
    calculus::Point3D j = {2,2,-2};
    
    calculus::Point3D w = {1,-2,0};
    calculus::Point3D x = {3,1,4};
    calculus::Point3D y = {0, -1,2};
    
    // scope is not required for functions with argument that is defined inside a namespace
    calculus::Point3D scaledVec = {20,24,-22};
    std::cout << "Scaled: <" << scaledVec.x<< ","<< scaledVec.y<< "," 
              << scaledVec.z << "> Normalized: ";
    normalize(scaledVec);
    displayVector(scaledVec);
    scaledVec *= 3;
    std::cout << "Normalized * 3: ";
    displayVector(scaledVec);
    std::cout << "P: "; displayVector(p);
    std::cout << "Q: "; displayVector(q);
    std::cout << "Distance bet. P and Q:" <<  distance(p,q) << std::endl;
    
    std::cout << "P: "; displayVector(p);
    std::cout << "Q: "; displayVector(q);
    std::cout << "Dot Product of P and Q: " << dotProductScalar(p,q) << std::endl;
    std::cout << "I: "; displayVector(i);
    std::cout << "J: "; displayVector(j);
    std::cout << "Angle Bet I and J:" << angeBet2Vector(i,j) << std::endl;
    std::cout << "A: "; displayVector(a);
    std::cout << "B: "; displayVector(b);
    std::cout << "A and B orthagonal? " << (isOrthagonal(a,b)?"Yes: perpendicular":"No: perpendicular") << std::endl;
    std::cout << "Cross Product of P and Q: " << crossProduct(p,q) << std::endl;
    std::cout << "P and Q parallel? "<<(isParallel(p,q)?"Yes: parallel":"No: parallel") << std::endl;
    std::cout << "Equation of line passing through point A and B: ";
    findLineEqu(a,b);
    std::cout << "W: "; 
    displayVector(w);
    std::cout << "X: "; 
    displayVector(x);
    std::cout << "Y: ";
    displayVector(y);
    std::cout << "Equation of plane passing through the point W, X, and Y: ";
    findPlaneEqu(w,x,y);
    
    return 0;
}


