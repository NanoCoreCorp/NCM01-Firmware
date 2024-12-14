#ifndef VECTOR3D_H
#define VECTOR3D_H

#include "c/cvectors/point3d.h"

class Vector3D {
public:
        explicit Vector3D() 
        : _x(0), _y(0), _z(0) {}
        Vector3D(float x, float y, float z)
        : _x(x), _y(y), _z(z) {}
        Vector3D(const Vector3D& other)
        : _x(other._x), 
        _y(other._y), 
        _z(other._z) {}
        Vector3D(Point3D p1, Point3D p2)
        : _x(p2.x - p1.x), 
        _y(p2.y - p1.y), 
        _z(p2.z - p1.z) {}

        float getX() const;
        float getY() const;
        float getZ() const;

        float getLen() const;

        bool operator==(const Vector3D& other) const;

        bool operator!=(const Vector3D& other) const;

        Vector3D operator+(const Vector3D& other) const;

        Vector3D operator-(const Vector3D& other) const;

        Vector3D operator*(const Vector3D& other) const;

        Vector3D operator+(float scalar) const;

        Vector3D operator-(float scalar) const;

        Vector3D operator*(float scalar) const;

        bool collinearity(const Vector3D& other) const;

        float distance(const Vector3D& other) const;
        
        float scalar(const Vector3D& other) const;

        Vector3D normalize() const;


protected:
        float _x;
        float _y;
        float _z;

        float deg2Rad(float angle) const;

        float rad2deg(float rads) const;
};

#endif  /* VECTOR3D_H */