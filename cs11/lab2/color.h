#ifndef COLOR_H_
#define COLOR_H_

#include <iostream>

namespace RTracer {
class Color {
public:
    inline Color();
    inline Color(float red, float green, float blue);

    inline void set_red(float red);
    inline void set_green(float green);
    inline void set_blue(float blue);
    inline float get_red() const;
    inline float get_green() const;
    inline float get_blue() const;

    inline Color& operator += (const Color& c);
    inline Color& operator -= (const Color& c);
    inline Color& operator *= (const Color& c);

    inline const Color operator + (const Color& c);
    inline const Color operator - (const Color& c);
    inline const Color operator * (const Color& c);

    inline Color& operator *= (float factor);
    inline Color& operator /= (float factor);
    inline const Color operator * (float factor);
    inline const Color operator / (float factor);
private:
    float red_;
    float green_;
    float blue_;
};

inline const Color operator * (float factor, const Color& c);
inline std::ostream& operator << (std::ostream& os, const Color& c);

#include "color.inl"
}

#endif
