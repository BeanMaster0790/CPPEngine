#pragma once

#include <math.h>
#include <string>
   
struct Vector2
{
    public:

    float X = 0;

    float Y = 0;

    Vector2() = default;
    Vector2(float x, float y);

    static float Distance(const Vector2& one, const Vector2& two);

    Vector2 operator*(const Vector2& by);

    Vector2 operator*(const float by);

    Vector2 operator+(const Vector2& by);

    std::string ToString();
};