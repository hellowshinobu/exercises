#include "vector3f.h"

namespace RTracer
{

float Vector3F::magnitude() const
{
    return sqrtf(e_[0]*e_[0] + e_[1]*e_[1] +e_[2]*e_[2]);
}

void Vector3F::normalize()
{
    float n= magnitude();
    n = 1.0f / n;
    e_[0] *= n;
    e_[1] *= n;
    e_[2] *= n;
}

}
