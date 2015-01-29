#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <cassert>
#include <climits>
#include <cmath>
#include <cfloat>
#include <iostream>


namespace RTracer
{

class Vector3F
{
public:
    inline Vector3F();
    inline Vector3F(float x, float y, float z);

    inline Vector3F& operator += (const Vector3F& v);
    inline Vector3F& operator -= (const Vector3F& v);
    inline const Vector3F  operator + (const Vector3F& v);
    inline const Vector3F  operator - (const Vector3F& v);

    inline Vector3F& operator *= (float factor);
    inline Vector3F& operator /= (float factor);
    inline const Vector3F  operator * (float factor);
    inline const Vector3F  operator / (float factor);

    inline const Vector3F operator - ();

    inline float operator [] (int index) const;
    inline float& operator [] (int index);

    // dot product
    inline float operator * (const Vector3F& v);

    // cross product
    inline const Vector3F operator % (const Vector3F& v);

    // magnitude
    float magnitude() const;

    // normalize
    void normalize();
private:
    float e_[3];
};

inline const Vector3F operator * (const Vector3F& v, float s);
inline const Vector3F operator * (float s, const Vector3F& v);
inline std::ostream& operator<< (std::ostream& os, const Vector3F& v);
inline std::istream& operator>> (std::istream& is, Vector3F& v);


} // Ray tracer

#include "vector3f.inl"
#endif
