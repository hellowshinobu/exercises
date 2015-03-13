inline Vector3F::Vector3F() {
    e_[0] = 0.0f;
    e_[1] = 0.0f;
    e_[2] = 0.0f;
}

inline Vector3F::Vector3F(float x, float y, float z) {
    e_[0] = x;
    e_[1] = y;
    e_[2] = z;
}

inline Vector3F& Vector3F::operator += (const Vector3F& v) {
    for (int i = 0; i < 3; ++i)
        e_[i] += v.e_[i];
    return *this;
}

inline Vector3F& Vector3F::operator -= (const Vector3F& v) {
    for (int i = 0; i < 3; ++i)
        e_[i] -= v.e_[i];
    return *this;
}

inline const Vector3F Vector3F::operator + (const Vector3F& v) {
    Vector3F result(*this);
    result += v;
    return result;
}

inline const Vector3F Vector3F::operator - (const Vector3F& v) {
    Vector3F result(*this);
    result -= v;
    return result;
}

inline Vector3F& Vector3F::operator *= (float factor) {
    for (int i = 0; i < 3; ++i)
        e_[i] *= factor;

    return *this;
}

inline Vector3F& Vector3F::operator /= (float factor) {
    //assert(fabs(factor - 0.0f) < FLT_EPSLION);
    for (int i = 0; i < 3; ++i)
        e_[i] /= factor;

    return *this;
}

inline const Vector3F Vector3F::operator - () {
    Vector3F result(*this);
    for (int i = 0; i < 3; ++i)
        result.e_[i] = -result.e_[i];

    return result;
}

inline float Vector3F::operator [] (int index) const {
    assert(index >= 0 && index < 3);
    return e_[index];
}

inline float& Vector3F::operator [] (int index) {
    assert(index >=0 && index < 3);
    return e_[index];
}

inline float Vector3F::operator * (const Vector3F& v) {
    return (e_[0] * v[0] + e_[1] * v[1] + e_[2] * v[2]);
}

inline const Vector3F Vector3F::operator % (const Vector3F& v) {
    Vector3F result;
    result[0] = e_[1] * v[2] - e_[2] * v[1];
    result[1] = e_[0] * v[2] - e_[2] * v[0];
    result[2] = e_[0] * v[1] - e_[1] * v[0];

    return result;
}

inline const Vector3F Vector3F::operator * (float s) {
    Vector3F result(*this);
    result *= s;
    return result;
}

inline const Vector3F Vector3F::operator / (float s) {
    Vector3F result(*this);
    result /= s;
    return result;
}

inline const Vector3F operator * (float s, const Vector3F& v) {
    Vector3F result(v);
    result *= s;
    return result;
}

inline std::ostream& operator<< (std::ostream& os, const Vector3F& v) {
    os << "(" << v[0] << ", "
              << v[1] << ", "
              << v[2] << ")";
    return os;
}

inline std::istream& operator >> (std::istream& is, Vector3F& v) {
    is >> v[0] >> v[1] >> v[2];
    return is;
}


