// Templated Implementation of FFT.
// Used to multiply 2 polynomials of size N in O(N logN).
// Polynomials are passed as vectors with index of "i" is
// coefficient of x^i in polynomial.

#include <iostream>
#include <cmath>
#include <vector>

const int MAX = 131100;         //2^ceil(log2(N)) where N = Maximum size of Polynomial

//Complex class: Quite faster than in-built C++ library as it uses
// only functions required
template<typename T> class cmplx {
private:
    T x, y;
public:
    cmplx () : x(0.0), y(0.0)
    {
    }
    cmplx (T a) : x(a), y(0.0)
    {
    }
    cmplx (T a, T b) : x(a), y(b)
    {
    }
    T get_real()
    {
        return this->x;
    }
    T get_img()
    {
        return this->y;
    }
    cmplx conj()
    {
        return cmplx(this->x, -(this->y));
    }
    cmplx operator = (const cmplx& a)
    {
        this->x = a.x; this->y = a.y; return *this;
    }
    cmplx operator + (const cmplx& b)
    {
        return cmplx(this->x + b.x, this->y + b.y);
    }
    cmplx operator - (const cmplx& b)
    {
        return cmplx(this->x - b.x, this->y - b.y);
    }
    cmplx operator * (const T& num)
    {
        return cmplx(this->x * num, this->y * num);
    }
    cmplx operator / (const T& num)
    {
        return cmplx(this->x / num, this->y / num);
    }
    cmplx operator * (const cmplx& b)
    {
        return cmplx(this->x * b.x - this->y * b.y, this->y * b.x + this->x * b.y);
    }
    cmplx operator / (const cmplx& b)
    {
        cmplx temp(b.x, -b.y); cmplx n = (*this) * temp;
        return n / (b.x * b.x + b.y * b.y);
    }
};

//T = int/long long as per polynomial coefficients
//S = double/long double as per precision required
template<typename T, typename S> struct FFT
{
    S PI;
    int n, L, *rev, last;
    cmplx<S> ONE, ZERO;
    cmplx<S> *omega_powers;

    FFT()
    {
        PI = acos(-1.0);
        ONE = cmplx<S>(1.0, 0.0);
        ZERO = cmplx<S>(0.0, 0.0);
        last = -1;
        int req = 1 << (32 - __builtin_clz(MAX));
        rev = new int[req];
        omega_powers = new cmplx<S>[req];
    }

    ~FFT()
    {
        delete rev;
        delete omega_powers;
    }

    void ReverseBits()
    {
        if (n != last)
            for (int i = 1, j = 0; i < n; ++i)
            {
                int bit = n >> 1;
                for (; j >= bit; bit >>= 1)
                    j -= bit;
                j += bit;
                rev[i] = j;
            }
    }

    void DFT(std::vector<cmplx<S>> &A, bool inverse = false)
    {
        using namespace std;
        for (int i = 0; i < n; ++i)
            if (rev[i] > i)
                swap(A[i], A[rev[i]]);
        for (int s = 1; s <= L; s++)
        {
            int m = 1 << s, half = m / 2;
            cmplx<S> wm(cosl(2.0 * PI / m), sinl(2.0 * PI / m));
            if (inverse)
                wm = ONE / wm;
            omega_powers[0] = ONE;
            for (int k = 1; k < half; ++k)
                omega_powers[k] = omega_powers[k - 1] * wm;
            for (int k = 0; k < n; k += m)
                for (int j = 0; j < half; j++)
                {
                    cmplx<S> t = omega_powers[j] * A[k + j + half];
                    cmplx<S> u = A[k + j];
                    A[k + j] = u + t;
                    A[k + j + half] = u - t;
                }
        }
        if (inverse)
            for (int i = 0; i < n; i++)
                A[i] = A[i] / n;
    }

    // c[k] = sum_{i=0}^k a[i] b[k-i]
    std::vector<T> multiply(const std::vector<T> &a, const std::vector<T> &b)
    {
        using namespace std;
        L = 0;
        int sa = a.size(), sb = b.size(), sc = sa + sb - 1;
        while ((1 << L) < sc)
            L++;
        n = 1 << L;
        ReverseBits();
        last = n;
        vector<cmplx<S>> aa(n, ZERO), bb(n, ZERO), cc;
        for (int i = 0; i < sa; ++i)
            aa[i] = cmplx<S>(a[i], 0);
        for (int i = 0; i < sb; ++i)
            bb[i] = cmplx<S>(b[i], 0);
        DFT(aa, false); DFT(bb, false);
        for (int i = 0; i < n; ++i)
            cc.push_back(aa[i] * bb[i]);
        DFT(cc, true);
        vector<T> ans(sc);
        for (int i = 0; i < sc; ++i)
            ans[i] = cc[i].get_real() + 0.5;
        return ans;
    }
};

int main()
{
    using namespace std;
    vector<int> poly_1(4);              //1 + 3x^2 + 2x^3
    poly_1[0] = 1;
    poly_1[1] = 0;
    poly_1[2] = 3;
    poly_1[3] = 2;

    vector<int> poly_2(3);              //2 + x + x^2
    poly_2[0] = 2;
    poly_2[1] = 1;
    poly_2[2] = 1;

    // int = final datatype in which coefficients should fit.
    // double = internal calculations done in double but has precision loss.
    // use "long double" to get less precision issues, but constant factor
    // of algorithm increases.
    FFT<int, double> fft;

    // Product should be 2 + x + 7x^2 + 7x^3 + 5x^4 + 2x^5
    std::vector<int> poly_mul = fft.multiply(poly_1, poly_2);
    for (size_t i = 0; i < poly_mul.size(); ++i)
        cout << poly_mul[i] << " ";
    cout << "\n";
    return 0;
}
