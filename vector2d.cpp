#include "vector2d.h"
#include "cmath"
Vector2D::Vector2D(double x, double y): x(x), y(y)
    {
    }
Vector2D::Vector2D(const Vector2D &other)
    {
    this->x = other.x;
    this->y = other.y;
    }
Vector2D& Vector2D::operator=(const Vector2D &rhs)
    {
    this->x = rhs.x;
    this->y = rhs.y;
    return *this;
    }
Vector2D& Vector2D::operator+=(const Vector2D &rhs)
    {
    this->x += rhs.x;
    this->y += rhs.y;
    return *this;
    }
Vector2D& Vector2D::operator-=(const Vector2D &rhs)
    {
    this->x -= rhs.x;
    this->y -= rhs.y;
    return *this;
    }
Vector2D& Vector2D::operator*=(const double &scalar)
    {
    this->x *= scalar;
    this->y *= scalar;
    return *this;
    }
Vector2D& Vector2D::operator/=(const double &scalar)
    {
    this->x /= scalar;
    this->y /= scalar;
    return *this;
    }
Vector2D Vector2D::operator+(const Vector2D &rhs)
    {
    Vector2D result;
    result.x += rhs.x;
    result.y += rhs.y;
    return result;
    }
Vector2D Vector2D::operator-(const Vector2D &rhs)
    {
    Vector2D result;
    result.x -= rhs.x;
    result.y -= rhs.y;
    return result;
    }
Vector2D Vector2D::operator*(const double &scalar)
    {
    Vector2D result;
    result.x = this->x * scalar;
    result.y = this->y * scalar;
    return result;
    }
Vector2D Vector2D::operator/(const double &scalar)
    {
    Vector2D result;
    result.x = this->x / scalar;
    result.y = this->y / scalar;
    return result;
    }
double Vector2D::getMagnitude()
    {
    return sqrt(this->x*this->x + this->y*this->y);
    //return sqrt(pow(this->x, 2) + pow(this->y, 2));
    }
void Vector2D::normalize()
    {
    //*this /= this->getMagnitude();
    double mag = this->getMagnitude();
    this->x /= mag;
    this->y /= mag;
    }
double dotProduct(const Vector2D &vec1, const Vector2D &vec2)
    {
    return vec1.x * vec2.x + vec1.y * vec2.y;
    }
void rotatePoint(Vector2D &vec, const double rad)
    {
    double newX, newY;
    
    newX = vec.x * cos(rad) - vec.y * sin(rad);
    newY = vec.x * sin(rad) + vec.y * cos(rad);
    
    vec.x = newX;
    vec.y = newY;
    }
void rotateAroundAxis(Vector2D &vec, const Vector2D &xAxis, const Vector2D &yAxis, const Vector2D &pivot)
    {
    Vector2D newVec;
    
    vec.x -= vec.x;
    vec.y -= vec.y;
    
    newVec.x = (vec.x * xAxis.x);
    newVec.y = (vec.x * xAxis.y);
    newVec.x += (vec.y * yAxis.x);
    newVec.y += (vec.y * yAxis.y);
    
    vec.x = newVec.x + pivot.x;
    vec.y = newVec.y + pivot.y;
    }