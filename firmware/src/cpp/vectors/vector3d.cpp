#include "c/math.h"
#include "cpp/vectors/vector3d.h"

bool isClose(float a, float b, float epsilon = 1e-7) {
        return fabs(a - b) < epsilon;
}

float Vector3D::getX() const {
        return this->_x;
}

float Vector3D::getY() const {
        return this->_y;
}
float Vector3D::getZ() const {
        return this->_z;
}

float Vector3D::getLen() const {
        return sqrt(
                pow(this->_x, 2) + pow(this->_y, 2) + pow(this->_z, 2)
        );
}

bool Vector3D::operator==(const Vector3D& other) const {
        return this->_x == other._x && this->_y == other._y && this->_z == other._z;
}

bool Vector3D::operator!=(const Vector3D& other) const {
        return this->_x != other._x || this->_y != other._y || this->_z != other._z;
}

Vector3D Vector3D::operator+(const Vector3D& other) const {
        return Vector3D(
                this->_x + other._x, 
                this->_y + other._y, 
                this->_z + other._z
        );
}

Vector3D Vector3D::operator-(const Vector3D& other) const {
        return Vector3D(
                this->_x - other._x, 
                this->_y - other._y, 
                this->_z - other._z
        );
}

Vector3D Vector3D::operator*(const Vector3D& other) const {
        return Vector3D(
                this->_x * other._x, 
                this->_y * other._y, 
                this->_z * other._z
        );
}

Vector3D Vector3D::operator+(float scalar) const {
        return Vector3D(
                this->_x + scalar, 
                this->_y + scalar, 
                this->_z + scalar
        );
}

Vector3D Vector3D::operator-(float scalar) const {
        return Vector3D(
                this->_x - scalar, 
                this->_y - scalar, 
                this->_z - scalar
        );
}

Vector3D Vector3D::operator*(float scalar) const {
        return Vector3D(
                this->_x * scalar, 
                this->_y * scalar, 
                this->_z * scalar
        );
}

bool Vector3D::collinearity(const Vector3D& other) const {
        if ((this->_x == 0 && this->_y == 0 && this->_z == 0) 
        || (other._x == 0 && other._y == 0 && other._z == 0)) {
                return true;
        }

        float xyk = this->_x * other._y;
        float yxk = this->_y * other._x;
        float yzk = this->_y * other._z;
        float zyk = this->_z * other._y;

        return isClose(xyk, yxk) && isClose(yzk, zyk);
}

float Vector3D::distance(const Vector3D& other) const {
        return sqrt(
                pow((other._x - this->_x), 2) + 
                pow((other._y - this->_y), 2) + 
                pow((other._z - this->_z), 2)
        );
}

float Vector3D::scalar(const Vector3D& other) const {
        return this->_x * other._x + this->_y * other._y + this->_z * other._z;
}

Vector3D Vector3D::normalize() const {
        float localLen = this->getLen();
        return localLen > 0 ? *this * (1.0f / localLen) : Vector3D();
}

float Vector3D::deg2Rad(float angle) const {
        return angle * (3.14159265359 / 180);
}

float Vector3D::rad2deg(float rads) const {
        return rads * (180 / 3.14159265359);
}

Vector3D constructVec(Point3D p1, Point3D p2) {
        return Vector3D(
                p2.x - p1.x,
                p2.y - p1.y,
                p2.z - p1.z
        );
}