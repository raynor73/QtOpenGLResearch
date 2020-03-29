#include <cmath>
#include "vector3f.h"

Vector3f::Vector3f(float x, float y, float z) :
    x(x),
    y(y),
    z(z)
{}

/*Vector3f::Vector3f(const Vector3f &other) :
    x(other.x),
    y(other.y),
    z(other.z)
{}

float Vector3f::length() const
{
    return sqrtf(x * x + y * y + z * z);
}

float Vector3f::dot(const Vector3f &other) const
{
    return x * other.x + y * other.y + z * other.z;
}

Vector3f& Vector3f::cross(const Vector3f &other)
{
    float newX = y * other.z - z * other.y;
    float newY = z * other.x - x * other.z;
    float newZ = x * other.y - y * other.x;

    x = newX;
    y = newY;
    z = newZ;

    return *this;
}

Vector3f& Vector3f::cross(const Vector3f &other, Vector3f& dest) const
{
    dest = *this;
    dest.cross(other);
    return dest;
}

Vector3f& Vector3f::normalize()
{
    float l = length();

    x /= l;
    y /= l;
    z /= l;

    return *this;
}

Vector3f& Vector3f::normalize(Vector3f& dest) const
{
    dest = *this;
    dest.normalize();
    return dest;
}

Vector3f& Vector3f::operator+(const Vector3f &other)
{
    x += other.x;
    y += other.y;
    z += other.z;

    return *this;
}

Vector3f& Vector3f::add(const Vector3f &other, Vector3f& dest) const
{
    dest = *this;
    dest = dest + other;
    return dest;
}

Vector3f Vector3f::operator +(float a)
{
    return Vector3f(x + a, y + a, z + a);
}

Vector3f Vector3f::operator -(const Vector3f &other)
{
    return Vector3f(x - other.x, y - other.y, z - other.z);
}

Vector3f Vector3f::operator -(float a)
{
    return Vector3f(x - a, y - a, z - a);
}

Vector3f Vector3f::operator *(const Vector3f &other)
{
    return Vector3f(x * other.x, y * other.y, z * other.z);
}

Vector3f Vector3f::operator *(float a)
{
    return Vector3f(x * a, y * a, z * a);
}

Vector3f Vector3f::operator /(const Vector3f &other)
{
    return Vector3f(x / other.x, y / other.y, z / other.z);
}

Vector3f Vector3f::operator /(float a)
{
    return Vector3f(x / a, y / a, z / a);
}

Vector3f& Vector3f::operator=(const Vector3f &other)
{
    if (&other == this)
        return *this;

    x = other.x;
    y = other.y;
    z = other.z;

    return *this;
}*/
