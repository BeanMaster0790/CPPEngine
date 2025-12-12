#include "Utils/Vector2.h"

Vector2::Vector2(float x, float y) : X(x), Y(y) {}

float Vector2::Distance(const Vector2& one, const Vector2& two)
{
    float xDist = one.X - two.X;

    float yDist = one.Y - two.Y;

    float distSqr = (xDist * xDist) + (yDist * yDist);

    float dist = sqrt(distSqr);

    return dist;
}

Vector2 Vector2::operator*(const Vector2& by)
{
    Vector2 r;

    r.X = this->X * by.X;
    r.Y = this->Y * by.Y;

    return r;
}

Vector2 Vector2::operator*(const float by)
{
    return Vector2{ X * by, Y * by };
}

Vector2 Vector2::operator+(const Vector2& by)
{
    return Vector2{ X + by.X, Y + by.Y };
}