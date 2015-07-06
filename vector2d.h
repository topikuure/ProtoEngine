#ifndef VECTOR2D_INCLUDED
 #define VECTOR2D_INCLUDED
#define PI 3.1415926535897932
#define RAD(degrees) ( (degrees) * PI / 180 )
struct Vector2D
    {
    double x, y;

    Vector2D(double x = 0.0, double y = 0.0);
    Vector2D(const Vector2D &other);

    Vector2D& operator=(const Vector2D &rhs);
    Vector2D& operator+=(const Vector2D &rhs);
    Vector2D& operator-=(const Vector2D &rhs);
    Vector2D& operator*=(const double &scalar);
    Vector2D& operator/=(const double &scalar);
    Vector2D operator+(const Vector2D &rhs);
    Vector2D operator-(const Vector2D &rhs);
    Vector2D operator*(const double &scalar);
    Vector2D operator/(const double &scalar);

    double getMagnitude();
    void normalize();
    };

double dotProduct(const Vector2D &vec1, const Vector2D &vec2);
void rotatePoint(Vector2D &vec, const double rad);
void rotateAroundAxis(Vector2D &vec, const Vector2D &xAxis, const Vector2D &yAxis, const Vector2D &pivot);
#endif