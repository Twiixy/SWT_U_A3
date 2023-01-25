#include<iostream>
using namespace std;




class int3 {                                                // (A)
    int m_n{ 0 };

public:
    int3() {}

    int3(int n) : m_n{ n % 3 } {}

    int3(const int3& i) : m_n{ i.m_n } {}

    operator int() const { return m_n; }                    // (B)

    int3& operator+=(const int3& i) {                       // (C)
        m_n = (m_n + i.m_n) % 3;
        return *this;
    }

};

int3 operator+(const int3& lhs, const int3& rhs) {          // (D)
    cout << "-a|      op+, lhs=" << lhs << ", rhs=" << rhs << endl;
    int3 res{ lhs };
    return res += rhs; // res.operator+=(rhs)
}


ostream& operator<<(ostream& os, const int3& i) {
    os << (int)(i);
    return os;
}

//-----------------------
const int dim{ 4 };
class polynom {                                             // (A)
public:
    double coeffs[dim];

    //  double eval(double x) {
    double operator()(double x) {                           // (B)
        double r{ 0.0 };
        for (int i = dim - 1; i >= 1; --i)
            r = x * (coeffs[i] + r);
        r += coeffs[0];
        return r;
    }

    //  double at(size_t i) const {
    double operator[](size_t i) const {                     // (C)
        if (i >= dim)
            throw invalid_argument("index too large");
        return coeffs[i];
    }

    //  double& at(size_t i) {                                  // (D)
    double& operator[](size_t i) {
        if (i >= dim)
            throw invalid_argument("index too large");
        return coeffs[i];
    }
};
