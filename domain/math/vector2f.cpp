#include <cmath>
#include "vector2f.h"

Vector2f::Vector2f(float x, float y) :
    x(x),
    y(y)
{}

/*Vector2f::Vector2f(const Vector2f &other) :
    x(other.x),
    y(other.y)
{}

float Vector2f::length() const
{
    return sqrtf(x * x + y * y);
}

float Vector2f::dot(const Vector2f &other) const
{
    return x * other.x + y * other.y;
}

Vector2f& Vector2f::normalize()
{
    float l = length();

    x /= l;
    y /= l;

    return *this;
}

Vector2f& Vector2f::normalize(Vector2f& dest) const
{
    dest = *this;
    return dest.normalize();
}

Vector2f& Vector2f::rotate(float angle)
{
    float rad = angle * M_PI / 180;
    float cos = cosf(rad);
    float sin = sinf(rad);
    float newX = x * cos - y * sin;
    float newY = x * sin + y * cos;
    x = newX;
    y = newY;
    return *this;
}

Vector2f& Vector2f::rotate(float angle, Vector2f& dest) const
{
    float rad = angle * M_PI / 180;
    float cos = cosf(rad);
    float sin = sinf(rad);
    dest.x = x * cos - y * sin;
    dest.y = x * sin + y * cos;
    return dest;
}

Vector2f& Vector2f::operator +(const Vector2f &other)
{
    x += other.x;
    y += other.y;
    return *this;
}

Vector2f& Vector2f::add(const Vector2f &other, Vector2f& dest) const
{
    dest = *this;
    dest.x += other.x;
    dest.y += other.y;
    return dest;
}

Vector2f& Vector2f::operator +(float a)
{
    x += a;
    y += a;
    return *this;
}

Vector2f& Vector2f::operator -(const Vector2f &other)
{
    x -= other.x;
    y -= other.y;
    return *this;
}

Vector2f& Vector2f::sub(const Vector2f &other, Vector2f& dest) const
{
    dest = *this;
    dest.x -= other.x;
    dest.y -= other.y;
    return dest;
}

Vector2f& Vector2f::operator-(float a)
{
    x -= a;
    y -=a;
    return *this;
}

Vector2f& Vector2f::sub(float a, Vector2f& dest) const
{
    dest = *this;
    dest.x -= a;
    dest.y -= a;
    return dest;
}

Vector2f& Vector2f::operator*(const Vector2f &other)
{
    x *= other.x;
    y *= other.y;
    return *this;
}

Vector2f& Vector2f::mul(const Vector2f &other, Vector2f&dest) const
{
    dest = *this;
    dest.x *= other.x;
    dest.y *= other.y;
    return dest;
}

Vector2f& Vector2f::mul(float a, Vector2f& dest) const
{
    dest = *this;
    dest.x *= a;
    dest.y *= a;
    return dest;
}

Vector2f& Vector2f::operator/(const Vector2f &other)
{
    x /= other.x;
    y /= other.y;
    return *this;
}

Vector2f& Vector2f::div(const Vector2f &other, Vector2f& dest) const
{
    dest = *this;
    dest.x /= other.x;
    dest.y /= other.y;
    return dest;
}

Vector2f& Vector2f::operator/(float a)
{
    x /= a;
    y /= a;
    return *this;
}

Vector2f& Vector2f::div(float a, Vector2f& dest) const
{
    dest = *this;
    dest.x /= a;
    dest.y /= a;
    return dest;
}

Vector2f& Vector2f::operator=(const Vector2f &other)
{
    if (&other == this)
        return *this;

    x = other.x;
    y = other.y;

    return *this;
}*/
