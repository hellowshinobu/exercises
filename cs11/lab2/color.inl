inline Color::Color()
    : red_(0.0f)
    , green_(0.0f)
    , blue_(0.0f)
{}

inline Color::Color(float red, float green, float blue)
    : red_(red)
    , green_(green)
    , blue_(blue)
{}

inline void Color::set_red(float red) {
    red_ = red;
}

inline void Color::set_green(float green) {
    green_ = green;
}

inline void Color::set_blue(float blue) {
    blue_ = blue;
}

inline float Color::get_red() const {
    return red_;
}

inline float Color::get_green() const {
    return green_;
}

inline float Color::get_blue() const {
    return blue_;
}

inline Color& Color::operator += (const Color& c) {
    red_ += c.red_;
    green_ += c.green_;
    blue_ += c.blue_;
    return *this;
}

inline Color& Color::operator -= (const Color& c) {
    red_ -= c.red_;
    green_ -= c.green_;
    blue_ -= c.blue_;
    return *this;
}

inline Color& Color::operator *= (const Color& c) {
    red_ *= c.red_;
    green_ *= c.green_;
    blue_ *= c.blue_;
    return *this;
}

inline const Color Color::operator + (const Color& c) {
    Color result(*this);
    result += c;
    return result;
}

inline const Color Color::operator - (const Color& c) {
    Color result(*this);
    result -= c;
    return result;
}

inline const Color Color::operator * (const Color& c) {
    Color result(*this);
    result *= c;
    return result;
}

inline Color& Color::operator *= (float factor) {
    red_ *= factor;
    green_ *= factor;
    blue_ *= factor;
    return *this;
}

inline Color& Color::operator /= (float factor) {
    red_ /= factor;
    green_ /= factor;
    blue_ /= factor;
    return *this;
}

inline const Color Color::operator * (float factor) {
    Color result(*this);
    result *= factor;
    return result;
}

inline const Color Color::operator / (float factor) {
    Color result(*this);
    result /= factor;
    return result;
}

inline const Color operator * (float factor, const Color& c) {
    Color result(c);
    result *= factor;
    return result;
}

inline std::ostream& operator << (std::ostream& os, const Color& c) {
    os << "(" << c.get_red() << ","
              << c.get_green() << ","
              << c.get_blue() << ")";
    return os;
}
