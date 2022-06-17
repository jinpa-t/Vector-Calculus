/**
 * file: calculus.hpp
 * Author: Jinpa Tsering
 * Date: 6/17/2022
 * Description: File contains.
 *              Calculus namespace definition,
 *              Point3D definition and operators,
 *              vector functions are defined here.
*/

#ifndef CALCULUS_HPP
#define CALCULUS_HPP

namespace calculus{
    // Point3D is same as math vector <x,y,z>
    struct Point3D {
        double x = 0, y= 0, z = 0;
        
        // define vector subtraction so we can use: p3 = p1 - p2;
        Point3D operator-(const Point3D &p) const {
            Point3D res = {this->x - p.x, this->y - p.y, this->z - p.z};
            return res;
        }
        
        // define vector addition so we can use: p3 = p1 + p2;
        Point3D operator+(const Point3D &p) const {
            Point3D res = {this->x + p.x, this->y + p.y, this->z + p.z};
            return res;
        }
        
        // define vector scalar multiplication so we can use: p3 = p1 * scalar;
        Point3D operator*(const int scalar) const {
            Point3D res = {this->x * scalar, this->y * scalar, this->z * scalar};
            return res;
        }
        
        // define vector scalar multiplication so we can use: p3 *= scalar;
        Point3D* operator*=( int scalar)  {
            this->x *= scalar;
            this->y *= scalar;
            this->z *= scalar;
            return this;
        }
        
        // define vector comparision so we can use: p3 == p2;
        friend bool operator==(const Point3D &lhs , const Point3D &rhs);
    };
    
    bool operator==(const Point3D &lhs , const Point3D &rhs){
        return (typeid(lhs) == typeid(rhs)) && lhs.x ==rhs.x && lhs.y ==rhs.y && lhs.z ==rhs.z;
    }
    
    bool isParallel(const Point3D &p, const Point3D &q) {
        return ((((p.y*q.z)-(p.z*q.y))+((p.x*q.z)-(p.z*q.x))+((p.y*q.x)-(p.x*q.y)))== 0.0)?1:0;
    }
    
    bool isOrthagonal(const Point3D &p, const Point3D &q) {
        // aka perpendicular
        return (((p.x*q.x)+(p.y*q.y)+(p.z*q.z)) == 0.0)?1:0;
    }
    
    double magnitude(const Point3D &p) {
        // aka length or distance
        return sqrt(pow((p.x),2) + pow((p.y),2) + pow((p.z),2));
    }
    
    Point3D normalize(Point3D &p) {
        // aka unit vector
        double mag = magnitude(p);
        p.x /= mag;
        p.y /= mag;
        p.z /= mag;
        return p;
    }
    
    Point3D crossProductVec(const Point3D &p, const Point3D &q) {
        // aka vector product
        Point3D res = {((p.y*q.z)-(p.z*q.y)),((p.z*q.x)-(p.x*q.z)),((p.x*q.y)-(p.y*q.x))};
        return res;
    }
    
    /**
     * Dot product of two vector.
     *
     * @param values Container whose values are summed.
     * @return new vector with respective `values` multiplied.
    */
    Point3D dotProductVectorProduct(const Point3D &p, const Point3D &q) { 
        //aka vector product
        Point3D res = {(p.x*q.x),(p.y*q.y),(p.z*q.z)};
        return res;
    }
    
    double dotProductScalar(const Point3D &p, const Point3D &q) { 
        //aka scalar product
        return ((p.x*q.x)+(p.y*q.y)+(p.z*q.z));
    }
    
    double crossProduct(const Point3D &p, const Point3D &q) { 
        //aka scalar product
        return (((p.y*q.z)-(p.z*q.y))+((p.x*q.z)-(p.z*q.x))+((p.x*q.y)-(p.y*q.x)));
    }
    
    // distance is same as magnitude
    double distance(const Point3D &p,const Point3D &q ) {
        return sqrt(pow((q.x - p.x),2) + pow((q.y - p.y),2) + pow((q.z - p.z),2));
    }
    
    double angeBet2Vector(const Point3D &p,const Point3D &q) {
        return (180/M_PI)*acos((dotProductScalar(p,q)/(magnitude(p)*magnitude(q))));
    }
    
    void findLineEqu(Point3D &p,Point3D &q) {
        int x = q.x - p.x;
        int y = q.y - p.y;
        int z = q.z - p.z;
        std::cout << "<" << p.x << "," << p.y << "," << p.z << ">" << "+t" <<
                    "<" << x << "," << y << "," << z << ">" << "\n";
    }
    
    // Plane equation finder
    void findPlaneEqu(const Point3D &p, const Point3D &q, const Point3D &r) {
        // get two points
        Point3D pq = q - p;
        Point3D pr = r - p;
        
        // get cross product of two points
        Point3D crossP = crossProductVec(pq,pr);
        
        std::cout << "(" << crossP.x << "x" << ") + (" 
                  << crossP.y << "y) + (" << crossP.z << "z) = " ;
        int right = (-1 * ( crossP.x * (-1 * p.x)));
        right += (-1 * ( crossP.y * (-1 * p.y)));
        right += (-1 * ( crossP.z * (-1 * p.z)));
        std::cout << right << std::endl;
    }
    
    // print vector coordinates in <x ,y ,z > form 
    void displayVector(const Point3D &scaledVec) {
        std::cout << "<" << scaledVec.x <<", "<<scaledVec.y << ", " << scaledVec.z << ">\n";
    }
} // namespace calculus

#endif // end CALCULUS_HPP
