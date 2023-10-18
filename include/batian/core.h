#include "precision.h"

namespace batian {
    /**
     * Meant to hold a vector in three dimensions. 4 data members allocated to ensure
     * alignment in array.
     * **/
    class Vector3 {
        public:
            real x; //x coordinate
            real y; //y coordinate
            real z; //z coordinate
        private:
            real pad; //padding to ensure four word alignment

        public:

            //default constructor that creates the zero vector
            Vector3() : x(0), y(0), z(0) {}

            //explicit constructor
            Vector3(const real x, const real y, const real z)
                : x(x), y(y), z(z) {}
                //inverts the vector
            void invert() {
                x = -x;
                y = -y;
                z = -z;
            }

            //finds the magnitude
            real magnitude() const {
                return real_sqrt(x * x + y * y + z * z);
            }

            //magnitude squared
             real squareMagnitude() const {
                return x * x + y * y + z * z;
            }

            //gets you the unit vector
            void normalize() {
                real l = magnitude();

                if (l > 0) {
                    (*this) *= ((real) 1) / l;
                }
            }

            //multiplies the vector by the given scalar
            void operator*=(const real value){
                x *= value;
                y *= value;
                z *= value;
            }

            Vector3 operator*(const real value) const{
                return Vector3(x*value, y*value, z*value);
            }
            //vector addition. Takes vector v and adds to the given vector
            void operator+=(const Vector3& v){
                x += v.x;
                y += v.y;
                z += v.z;
            }

            Vector3 operator+(const Vector3& v) const{
                return Vector3(x+v.x,y+v.y+z+v.z);
            }

            //vector subtraction. Takes vector v and adds to the given vector
            void operator-=(const Vector3& v){
                x -= v.x;
                y -= v.y;
                z -= v.z;
            }

            Vector3 operator-(const Vector3& v) const{
                return Vector3(x-v.x,y-v.y-z+v.z);
            }

            //adds given vector to a scaled vector
            void addScaledVector(const Vector3& vector, real scale) {
                x += vector.x * scale;
                y += vector.y * scale;
                z += vector.z * scale;
            }
            //component product
            Vector3 componentProduct(const Vector3 &vector) const{
                return Vector3(x*vector.x,y*vector.y,z*vector.z);
            }

            //sets the vector to the component product of itself and another
            void componentProductUpdate(const Vector3 &vector){
                x *= vector.x;
                y *= vector.y;
                z *= vector.z;
            }

            //scalar or dot product of two vectors
            real scalarProduct(const Vector3 &vector) const{
                return x*vector.x +y*vector.y +z*vector.z;
            }

            //calculates and returns the scalar product of this vector with the given vector
            //a.b = |a||b|cos(theta)
            real operator *(const Vector3 &vector) const{
                return x*vector.x + y*vector.y+z*vector.z;
            }

            //vector product or cross product
            Vector3 vectorProduct(const Vector3 &vector) const{
                return Vector3(y*vector.z-z*vector.y,
                               z*vector.x-x*vector.z,
                               x*vector.y-y*vector.x);
            }
            //updates the vector to be the vector product of its current values and the given vector
            // '%' typically reserved for cross product
            //in this cas it had been overloaded to represent vector or cross product
            // axb = |a||b|sin(theta)
            //the vector that results is orthogonal to a and b
            void operator %=(const Vector3 &vector){
                *this = vectorProduct(vector);
            }

            //calculates and returns the vector product of the vector with the given vector
            Vector3 operator%(const Vector3 &vector) const{
                return Vector3(y*vector.z-z*vector.y,
                               z*vector.x-x*vector.z,
                               x*vector.y-y*vector.x);
            }

            //the orthonormal basis
            //when you want to create a triple of mutually orthogonal vectors
            //designed for right-handed coordinate system
            //might change if you are working with the left-handed coordinate system
            //change the operands for both the cross products
            void makeOrthonormalBasis(Vector3 *a, Vector3 *b, Vector3 *c){
                a->normalize();
                (*c) = (*a) % (*b);
                if (c->squareMagnitude() == 0.0) return; // or generate an error
                c->normalize();
                (*b) = (*c) % (*a);
            }

    };
}