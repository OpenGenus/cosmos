/*
 * N dimensional loop unrolled vector class.
 * 
 * https://github.com/RedBlight/LoopUnrolledVector
 * 
 * Refactored a little bit for "cosmos" repository.
 *
 */

#ifndef LU_VECTOR_INCLUDED
#define LU_VECTOR_INCLUDED

#include <sstream>
#include <string>
#include <complex>
#include <vector>
#include <iostream>

namespace LUV
{
    // LuVector.hpp

    template<std::size_t N, class T>
    class LuVector;

    template<class T>
    using LuVector2 = LuVector<2, T>;

    template<class T>
    using LuVector3 = LuVector<3, T>;

    using LuVector2f = LuVector<2, float>;
    using LuVector2d = LuVector<2, double>;
    using LuVector2c = LuVector<2, std::complex<double>>;

    using LuVector3f = LuVector<3, float>;
    using LuVector3d = LuVector<3, double>;
    using LuVector3c = LuVector<3, std::complex<double>>;
    
    // Added for cosmos
    const double pi = 3.14159265358979323846;
    
    // LuVector_Op.hpp
	
    template<std::size_t N>
    struct LoopIndex
    {

    };

    template<class T, class S>
    struct OpCopy
    {
        inline void operator ()(T& lhs, const S& rhs)
        {
            lhs = rhs;
        }
    };

    //////////////////////////////////////////////////////////////

    template<class T, class S>
    struct OpAdd
    {
        inline void operator ()(T& lhs, const S& rhs)
        {
            lhs += rhs;
        }
    };

    template<class T, class S>
    struct OpSub
    {
        inline void operator ()(T& lhs, const S& rhs)
        {
            lhs -= rhs;
        }
    };

    template<class T, class S>
    struct OpMul
    {
        inline void operator ()(T& lhs, const S& rhs)
        {
            lhs *= rhs;
        }
    };

    template<class T, class S>
    struct OpDiv
    {
        inline void operator ()(T& lhs, const S& rhs)
        {
            lhs /= rhs;
        }
    };

    //////////////////////////////////////////////////////////////

    template<class T, class S>
    struct OpAbs
    {
        inline void operator ()(T& lhs, const S& rhs)
        {
            lhs = std::abs(rhs);
        }
    };

    template<class T, class S>
    struct OpArg
    {
        inline void operator ()(T& lhs, const S& rhs)
        {
            lhs = std::arg(rhs);
        }
    };

    template<std::size_t N, class T, class S>
    struct OpMin
    {
        inline void operator ()(LuVector<N, T>& result, const LuVector<N, T>& lhs, const LuVector<N, S>& rhs, const std::size_t& I)
        {
            result[I] = lhs[I] < rhs[I] ? lhs[I] : rhs[I];
        }
    };

    template<std::size_t N, class T, class S>
    struct OpMax
    {
        inline void operator ()(LuVector<N, T>& result, const LuVector<N, T>& lhs, const LuVector<N, S>& rhs, const std::size_t& I)
        {
            result[I] = lhs[I] > rhs[I] ? lhs[I] : rhs[I];
        }
    };

    template<std::size_t N, class T, class S>
    struct OpDot
    {
        inline void operator ()(T& result, const LuVector<N, T>& lhs, const LuVector<N, S>& rhs, const std::size_t& I)
        {
            result += lhs[I] * rhs[I];
        }
    };

    //////////////////////////////////////////////////////////////

    template<class T>
    struct OpOstream
    {
        inline void operator ()(std::ostream& lhs, const T& rhs, const std::string& delimiter)
        {
            lhs << rhs << delimiter;
        }
    };
    
    // LuVector_Unroll.hpp

    // VECTOR OP SCALAR
    template<std::size_t I, std::size_t N, class T, class S, template<class, class> class OP>
    inline void Unroll(LuVector<N, T>& lhs, const S& rhs, OP<T, S> operation, LoopIndex<I>)
    {
        Unroll(lhs, rhs, operation, LoopIndex<I-1>());
        operation(lhs[I], rhs);
    }

    template<std::size_t N, class T, class S, template<class, class> class OP>
    inline void Unroll(LuVector<N, T>& lhs, const S& rhs, OP<T, S> operation, LoopIndex<0>)
    {
        operation(lhs[0], rhs);
    }

    // SCALAR OP VECTOR
    template<std::size_t I, std::size_t N, class T, class S, template<class, class> class OP>
    inline void Unroll(S& lhs, const LuVector<N, T>& rhs, OP<T, S> operation, LoopIndex<I>)
    {
        Unroll(lhs, rhs, operation, LoopIndex<I-1>());
        operation(lhs, rhs[I]);
    }

    template<std::size_t N, class T, class S, template<class, class> class OP>
    inline void Unroll(S& lhs, const LuVector<N, T>& rhs, OP<T, S> operation, LoopIndex<0>)
    {
        operation(lhs, rhs[0]);
    }

    // VECTOR OP VECTOR
    template<std::size_t I, std::size_t N, class T, class S, template<class, class> class OP>
    inline void Unroll(LuVector<N, T>& lhs, const LuVector<N, S>& rhs, OP<T, S> operation, LoopIndex<I>)
    {
        Unroll(lhs, rhs, operation, LoopIndex<I-1>());
        operation(lhs[I], rhs[I]);
    }

    template<std::size_t N, class T, class S, template<class, class> class OP>
    inline void Unroll(LuVector<N, T>& lhs, const LuVector<N, S>& rhs, OP<T, S> operation, LoopIndex<0>)
    {
        operation(lhs[0], rhs[0]);
    }

    // SCALAR = VECTOR OP VECTOR (could be cross-element)
    template<std::size_t I, std::size_t N, class T, class S, template<std::size_t, class, class> class OP>
    inline void Unroll(T& result, const LuVector<N, T>& lhs, const LuVector<N, S>& rhs, OP<N, T, S> operation, LoopIndex<I>)
    {
        Unroll(result, lhs, rhs, operation, LoopIndex<I-1>());
        operation(result, lhs, rhs, I);
    }

    template<std::size_t N, class T, class S, template<std::size_t, class, class> class OP>
    inline void Unroll(T& result, const LuVector<N, T>& lhs, const LuVector<N, S>& rhs, OP<N, T, S> operation, LoopIndex<0>)
    {
        operation(result, lhs, rhs, 0);
    }

    // VECTOR = VECTOR OP VECTOR (could be cross-element)
    template<std::size_t I, std::size_t N, class T, class S, template<std::size_t, class, class> class OP>
    inline void Unroll(LuVector<N, T>& result, const LuVector<N, T>& lhs, const LuVector<N, S>& rhs, OP<N, T, S> operation, LoopIndex<I>)
    {
        Unroll(result, lhs, rhs, operation, LoopIndex<I-1>());
        operation(result, lhs, rhs, I);
    }

    template<std::size_t N, class T, class S, template<std::size_t, class, class> class OP>
    inline void Unroll(LuVector<N, T>& result, const LuVector<N, T>& lhs, const LuVector<N, S>& rhs, OP<N, T, S> operation, LoopIndex<0>)
    {
        operation(result, lhs, rhs, 0);
    }

    // OSTREAM OP VECTOR
    template<std::size_t I, std::size_t N, class T, template<class> class OP>
    inline void Unroll(std::ostream& lhs, const LuVector<N, T>& rhs, const std::string& delimiter, OP<T> operation, LoopIndex<I>)
    {
        Unroll(lhs, rhs, delimiter, operation, LoopIndex<I-1>());
        operation(lhs, rhs[I], delimiter);
    }

    template<std::size_t N, class T, template<class> class OP>
    inline void Unroll(std::ostream& lhs, const LuVector<N, T>& rhs, const std::string& delimiter, OP<T> operation, LoopIndex<0>)
    {
        operation(lhs, rhs[0], delimiter);
    }
    
    // LuVector_Body.hpp
    
    template<std::size_t N, class T>
    class LuVector
    {
    public:
        LuVector() = default;

        ~LuVector() = default;

        template<class... S> 
        LuVector(const S&... elem) : _{ static_cast<T>(elem) ...}
        {

        }

        LuVector(const LuVector<N, const T>& other) : _{ other._ }
        {

        }

        template<class S> 
        LuVector(const LuVector<N, S>& other)
        {
            Unroll(*this, other, OpCopy<T, S>(), LoopIndex<N-1>());
        }

        template<class S> 
        LuVector(const S& scalar)
        {
            Unroll(*this, scalar, OpCopy<T, S>(), LoopIndex<N-1>());
        }

        template<class S>
        inline LuVector<N, T>& operator =(const LuVector<N, S>& other)
        {
            Unroll(*this, other, OpCopy<T, S>(), LoopIndex<N-1>());
            return *this;
        }

        inline const T& operator [](const std::size_t& idx) const
        {
            return _[idx];
        }

        inline T& operator [](const std::size_t& idx)
        {
            return _[idx];
        }

        inline std::string ToString() const
        {
            std::stringstream ss;
            ss << "(";
            Unroll(ss, *this, ",", OpOstream<T>(), LoopIndex<N-2>());
            ss << _[N-1] << ")";
            return std::string(ss.str());
        }

    private:
        T _[N];
    };
    
    // LuVector_Overload.hpp

    // OSTREAM << VECTOR
    template<std::size_t N, class T>
    std::ostream& operator <<(std::ostream& lhs, const LuVector<N, T>& rhs)
    {
        lhs << "(";
        Unroll(lhs, rhs, ",", OpOstream<T>(), LoopIndex<N-2>());
        lhs << rhs[N-1] << ")";
        return lhs;
    }

    // VECTOR += SCALAR
    template<std::size_t N, class T, class S>
    inline LuVector<N, T>& operator +=(LuVector<N, T>& lhs, const S& rhs)
    {
        Unroll(lhs, rhs, OpAdd<T, S>(), LoopIndex<N-1>());
        return lhs;
    }

    // VECTOR -= SCALAR
    template<std::size_t N, class T, class S>
    inline LuVector<N, T>& operator -=(LuVector<N, T>& lhs, const S& rhs)
    {
        Unroll(lhs, rhs, OpSub<T, S>(), LoopIndex<N-1>());
        return lhs;
    }

    // VECTOR *= SCALAR
    template<std::size_t N, class T, class S>
    inline LuVector<N, T>& operator *=(LuVector<N, T>& lhs, const S& rhs)
    {
        Unroll(lhs, rhs, OpMul<T, S>(), LoopIndex<N-1>());
        return lhs;
    }

    // VECTOR /= SCALAR
    template<std::size_t N, class T, class S>
    inline LuVector<N, T>& operator /=(LuVector<N, T>& lhs, const S& rhs)
    {
        Unroll(lhs, rhs, OpDiv<T, S>(), LoopIndex<N-1>());
        return lhs;
    }

    //////////////////////////////////////////////////////////////

    // VECTOR += VECTOR
    template<std::size_t N, class T, class S>
    inline LuVector<N, T>& operator +=(LuVector<N, T>& lhs, const LuVector<N, S>& rhs)
    {
        Unroll(lhs, rhs, OpAdd<T, S>(), LoopIndex<N-1>());
        return lhs;
    }

    // VECTOR -= VECTOR
    template<std::size_t N, class T, class S>
    inline LuVector<N, T>& operator -=(LuVector<N, T>& lhs, const LuVector<N, S>& rhs)
    {
        Unroll(lhs, rhs, OpSub<T, S>(), LoopIndex<N-1>());
        return lhs;
    }

    // VECTOR *= VECTOR
    template<std::size_t N, class T, class S>
    inline LuVector<N, T>& operator *=(LuVector<N, T>& lhs, const LuVector<N, S>& rhs)
    {
        Unroll(lhs, rhs, OpMul<T, S>(), LoopIndex<N-1>());
        return lhs;
    }

    // VECTOR /= VECTOR
    template<std::size_t N, class T, class S>
    inline LuVector<N, T>& operator /=(LuVector<N, T>& lhs, const LuVector<N, S>& rhs)
    {
        Unroll(lhs, rhs, OpDiv<T, S>(), LoopIndex<N-1>());
        return lhs;
    }

    //////////////////////////////////////////////////////////////

    // VECTOR + SCALAR
    template<std::size_t N, class T, class S>
    inline LuVector<N, T> operator +(const LuVector<N, T>& lhs, const S& rhs)
    {
        LuVector<N, T> result(lhs);
        return result += rhs;
    }

    // SCALAR + VECTOR
    template<std::size_t N, class T, class S>
    inline LuVector<N, T> operator +(const T& lhs, const LuVector<N, S>& rhs)
    {
        LuVector<N, T> result(lhs);
        return result += rhs;
    }

    // VECTOR - SCALAR
    template<std::size_t N, class T, class S>
    inline LuVector<N, T> operator -(const LuVector<N, T>& lhs, const S& rhs)
    {
        LuVector<N, T> result(lhs);
        return result -= rhs;
    }

    // SCALAR - VECTOR
    template<std::size_t N, class T, class S>
    inline LuVector<N, T> operator -(const T& lhs, const LuVector<N, S>& rhs)
    {
        LuVector<N, T> result(lhs);
        return result -= rhs;
    }

    // VECTOR * SCALAR
    template<std::size_t N, class T, class S>
    inline LuVector<N, T> operator *(const LuVector<N, T>& lhs, const S& rhs)
    {
        LuVector<N, T> result(lhs);
        return result *= rhs;
    }

    // SCALAR * VECTOR
    template<std::size_t N, class T, class S>
    inline LuVector<N, T> operator *(const T& lhs, const LuVector<N, S>& rhs)
    {
        LuVector<N, T> result(lhs);
        return result *= rhs;
    }

    // VECTOR / SCALAR
    template<std::size_t N, class T, class S>
    inline LuVector<N, T> operator /(const LuVector<N, T>& lhs, const S& rhs)
    {
        LuVector<N, T> result(lhs);
        return result /= rhs;
    }

    // SCALAR / VECTOR
    template<std::size_t N, class T, class S>
    inline LuVector<N, T> operator /(const T& lhs, const LuVector<N, S>& rhs)
    {
        LuVector<N, T> result(lhs);
        return result /= rhs;
    }

    //////////////////////////////////////////////////////////////

    // VECTOR + VECTOR
    template<std::size_t N, class T, class S>
    inline LuVector<N, T> operator +(const LuVector<N, T>& lhs, const LuVector<N, S>& rhs)
    {
        LuVector<N, T> result(lhs);
        return result += rhs;
    }

    // VECTOR - VECTOR
    template<std::size_t N, class T, class S>
    inline LuVector<N, T> operator -(const LuVector<N, T>& lhs, const LuVector<N, S>& rhs)
    {
        LuVector<N, T> result(lhs);
        return result -= rhs;
    }

    // VECTOR * VECTOR
    template<std::size_t N, class T, class S>
    inline LuVector<N, T> operator *(const LuVector<N, T>& lhs, const LuVector<N, S>& rhs)
    {
        LuVector<N, T> result(lhs);
        return result *= rhs;
    }

    // VECTOR / VECTOR
    template<std::size_t N, class T, class S>
    inline LuVector<N, T> operator /(const LuVector<N, T>& lhs, const LuVector<N, S>& rhs)
    {
        LuVector<N, T> result(lhs);
        return result /= rhs;
    }

    //////////////////////////////////////////////////////////////

    // - VECTOR
    template<std::size_t N, class T>
    inline LuVector<N, T> operator -(const LuVector<N, T>& vec)
    {
        return T(0) - vec;
    }

    //////////////////////////////////////////////////////////////
    
    // LuVector_Math.hpp
    
    template<std::size_t N, class T>
    inline T Sum(const LuVector<N, T>& vec)
    {
        T result = 0;
        Unroll(result, vec, OpAdd<T, T>(), LoopIndex<N-1>());
        return result;
    }

    // Abs
    template<std::size_t N, class T>
    inline LuVector<N, T> Abs(const LuVector<N, T>& vec)
    {
        LuVector<N, T> absVec;
        Unroll(absVec, vec, OpAbs<T, T>(), LoopIndex<N-1>());
        return absVec;
    }

    // Length
    template<std::size_t N, class T>
    inline T Length(const LuVector<N, T>& vec)
    {
        T result = 0;
        Unroll(result, vec, vec, OpDot<N, T, T>(), LoopIndex<N-1>());
        return sqrt(result);
    }

    // Unit
    template<std::size_t N, class T>
    inline LuVector<N, T> Unit(const LuVector<N, T>& vec)
    {
        return vec / Length(vec);
    }

    //////////////////////////////////////////////////////////////

    // Abs Complex
    template<std::size_t N, class T>
    inline LuVector<N, T> Abs(const LuVector<N, std::complex<T>>& vec)
    {
        LuVector<N, T> absVec;
        Unroll(absVec, vec, OpAbs<T, std::complex<T>>(), LoopIndex<N-1>());
        return absVec;
    }

    // Arg Complex
    template<std::size_t N, class T>
    inline LuVector<N, T> Arg(const LuVector<N, std::complex<T>>& vec)
    {
        LuVector<N, T> argVec;
        Unroll(argVec, vec, OpArg<T, std::complex<T>>(), LoopIndex<N-1>());
        return argVec;
    }

    // Length Complex
    template<std::size_t N, class T>
    inline T Length(const LuVector<N, std::complex<T>>& vec)
    {
        return Length(Abs(vec)); 
    }

    // Unit Complex
    template<std::size_t N, class T>
    inline LuVector<N, std::complex<T>> Unit(const LuVector<N, std::complex<T>>& vec)
    {
        return vec / Length(vec);
    }

    //////////////////////////////////////////////////////////////

    // Min
    template<std::size_t N, class T, class S>
    inline LuVector<N, T> Min(const LuVector<N, T>& lhs, const LuVector<N, S>& rhs)
    {
        LuVector<N, T> result;
        Unroll(result, lhs, rhs, OpMin<N, T, S>(), LoopIndex<N-1>());
        return result;
    }

    // Max
    template<std::size_t N, class T, class S>
    inline LuVector<N, T> Max(const LuVector<N, T>& lhs, const LuVector<N, S>& rhs)
    {
        LuVector<N, T> result;
        Unroll(result, lhs, rhs, OpMax<N, T, S>(), LoopIndex<N-1>());
        return result;
    }

    // Dot
    template<std::size_t N, class T, class S>
    inline T Dot(const LuVector<N, T>& lhs, const LuVector<N, S>& rhs)
    {
        T result = 0;
        Unroll(result, lhs, rhs, OpDot<N, T, S>(), LoopIndex<N-1>());
        return result;
    }

    // Cross
    template<class T, class S>
    inline LuVector<3, T> Cross(const LuVector<3, T>& lhs, const LuVector<3, S>& rhs)
    {
        return LuVector<3, T>(
            lhs[1] * rhs[2] - lhs[2] * rhs[1],
            lhs[2] * rhs[0] - lhs[0] * rhs[2],
            lhs[0] * rhs[1] - lhs[1] * rhs[0]
        );
    }

    //////////////////////////////////////////////////////////////

    // Reflect
    template<std::size_t N, class T, class S>
    inline LuVector<N, T> Reflect(const LuVector<N, T>& vec, const LuVector<N, S>& normal)
    {
        return vec - normal * Dot(vec, normal) * 2;
    }

    // Rotate...

    //////////////////////////////////////////////////////////////

    // CtsToSph
    template<class T>
    inline LuVector<3, T> CtsToSph(const LuVector<3, T>& cts)
    {
        T len = Length(cts);
        return LuVector<3, T>(
            len,
            cts[0] == 0 && cts[1] == 0 ? 0 : std::atan2(cts[1], cts[0]),
            std::acos(cts[2] / len)
        );
    }

    // SphToCts
    template<class T>
    inline LuVector<3, T> SphToCts(const LuVector<3, T>& sph)
    {
        T planarVal = sph[0] * std::sin(sph[2]);
        return LuVector<3, T>(
            planarVal * std::cos(sph[1]),
            planarVal * std::sin(sph[1]),
            sph[0] * std::cos(sph[2])
        );
    }

    // CtsToPol
    template<class T>
    inline LuVector<2, T> CtsToPol(const LuVector<2, T>& cts)
    {
        T len = Length(cts);
        return LuVector<2, T>(
            len,
            cts[0] == 0 && cts[1] == 0 ? 0 : std::atan2(cts[1], cts[0])
        );
    }

    // PolToCts
    template<class T>
    inline LuVector<2, T> PolToCts(const LuVector<2, T>& pol)
    {
        return LuVector<2, T>(
            pol[0] * std::cos(pol[1]),
            pol[0] * std::sin(pol[1])
        );
    }

    //////////////////////////////////////////////////////////////

    // OrthonormalSet N=3
    // N: looking outside the sphere at given angles
    // U: up vector
    // R: right vector, parallel to XY plane
    // N = U X R 
    template<class T>
    inline void OrthonormalSet(const T& angP, const T& angT, LuVector<3, T>& dirN, LuVector<3, T>& dirU, LuVector<3, T>& dirR)
    {
        T cp = std::cos(angP);
        T sp = std::sin(angP);
        T ct = std::cos(angT);
        T st = std::sin(angT);

        dirN[0] = st * cp;
        dirN[1] = st * sp;
        dirN[2] = ct;

        dirR[0] = sp;
        dirR[1] = -cp;
        dirR[2] = 0;

        dirU = Cross(dirR, dirN);
    }

    // OrthonormalSet N=2
    template<class T>
    inline void OrthonormalSet(const T& ang, LuVector<2, T>& dirN, LuVector<2, T>& dirR)
    {
        T c = std::cos(ang);
        T s = std::sin(ang);

        dirN[0] = c;
        dirN[1] = s;

        dirR[0] = s;
        dirR[1] = -c;
    }

    // OrthogonalR N=3
    template<class T>
    inline LuVector<3, T> OrthonormalR(const LuVector<3, T>& dirN)
    {
        T ang = dirN[0] == 0 && dirN[1] == 0 ? 0 : std::atan2(dirN[1], dirN[0]);
        T c = std::cos(ang);
        T s = std::sin(ang);

        return LuVector<3, T>(s, -c, 0); 
    }

    // OrthogonalR N=2
    template<class T>
    inline LuVector<2, T> OrthonormalR(const LuVector<2, T>& dirN)
    {
        return LuVector<2, T>(dirN[1], -dirN[0]); 
    }

    // OrthogonalU N=3
    template<class T>
    inline LuVector<3, T> OrthonormalU(const LuVector<3, T>& dirN)
    {
        return Cross(OrthogonalR(dirN), dirN); 
    }
    
    // LuVector_Geometry.hpp

    // ProjLine N=3
    template<class T>
    inline LuVector<3, T> ProjLine(const LuVector<3, T>& vec, const LuVector<3, T>&v1, const LuVector<3, T>& v2) 
    {
        LuVector<3, T> v12 = Unit(v2 - v1);
        return v1 + Dot(v12, vec - v1) * v12;
    }

    // ProjLine N=2
    template<class T>
    inline LuVector<2, T> ProjLine(const LuVector<2, T>& vec, const LuVector<2, T>&v1, const LuVector<2, T>& v2) 
    {
        LuVector<2, T> v12 = Unit(v2 - v1);
        return v1 + Dot(v12, vec - v1) * v12;
    }

    // ProjLineL N=3
    template<class T>
    inline LuVector<3, T> ProjLineL(const LuVector<3, T>& vec, const LuVector<3, T>&v1, const LuVector<3, T>& lineDir) 
    {
        return v1 + Dot(lineDir, vec - v1) * lineDir;
    }

    // ProjLineL N=2
    template<class T>
    inline LuVector<2, T> ProjLineL(const LuVector<2, T>& vec, const LuVector<2, T>&v1, const LuVector<2, T>& lineDir)  
    {
        return v1 + Dot(lineDir, vec - v1) * lineDir;
    }

    // LineNormal N=3
    template<class T>
    inline LuVector<3, T> LineNormal(const LuVector<3, T>& v1, const LuVector<3, T>& v2) 
    {
        LuVector<3, T> v12 = Unit(v2 - v1);
        return OrthogonalR(v12);
    }

    // LineNormal N=2
    template<class T>
    inline LuVector<2, T> LineNormal(const LuVector<2, T>& v1, const LuVector<2, T>& v2) 
    {
        LuVector<2, T> v12 = Unit(v2 - v1);
        return OrthogonalR(v12);
    }

    // LineNormalL N=3
    template<class T>
    inline LuVector<3, T> LineNormalL(const LuVector<3, T>& lineDir) 
    {
        return OrthogonalR(lineDir);
    }

    // LineNormalL N=2
    template<class T>
    inline LuVector<2, T> LineNormalL(const LuVector<2, T>& lineDir) 
    {
        return OrthogonalR(lineDir);
    }

    // LineNormalP N=3
    template<class T>
    inline LuVector<3, T> LineNormalP(const LuVector<3, T>& vec, const LuVector<3, T>& v1, const LuVector<3, T>& v2) 
    {
        LuVector<3, T> v12 = Unit(v2 - v1);
        LuVector<3, T> ort = vec - ProjLineL(vec, v1, v12);
        T len = Length(ort);
        return len > 0 ? ort / len : LineNormalL(v12);
    }

    // LineNormalP N=2
    template<class T>
    inline LuVector<2, T> LineNormalP(const LuVector<2, T>& vec, const LuVector<2, T>& v1, const LuVector<2, T>& v2) 
    {
        LuVector<2, T> v12 = Unit(v2 - v1);
        LuVector<2, T> ort = vec - ProjLineL(vec, v1, v12);
        T len = Length(ort);
        return len > 0 ? ort / len : LineNormalL(v12);
    }

    // LineNormalPL N=3
    template<class T>
    inline LuVector<3, T> LineNormalPL(const LuVector<3, T>& vec, const LuVector<3, T>& v1, const LuVector<3, T>& lineDir)  
    {
        LuVector<3, T> ort = vec - ProjLineL(vec, v1, lineDir);
        T len = Length(ort);
        return len > 0 ? ort / len : LineNormalL(lineDir);
    }

    // LineNormalPL N=2
    template<class T>
    inline LuVector<2, T> LineNormalPL(const LuVector<2, T>& vec, const LuVector<2, T>& v1, const LuVector<2, T>& lineDir) 
    {
        LuVector<2, T> ort = vec - ProjLineL(vec, v1, lineDir);
        T len = Length(ort);
        return len > 0 ? ort / len : LineNormalL(lineDir);
    }

    //////////////////////////////////////////////////////////////

    // ProjPlane
    template<class T>
    inline LuVector<3, T> ProjPlane(const LuVector<3, T>& vec, const LuVector<3, T>& v1, const LuVector<3, T>& n) 
    {
        return vec - Dot(vec - v1, n) * n;
    }

    // PlaneNormal
    template<class T>
    inline LuVector<3, T> PlaneNormal(const LuVector<3, T>& v1, const LuVector<3, T>& v2, const LuVector<3, T>& v3)
    {
        return Unit(Cross(v2 - v1, v3 - v1));
    }

    // PlaneNormalP
    template<class T>
    inline LuVector<3, T> PlaneNormalP( const LuVector<3, T>& vec, const LuVector<3, T>& v1, const LuVector<3, T>& v2, const LuVector<3, T>& v3) 
    {
        LuVector<3, T> n = PlaneNormal(v1, v2, v3);
        return Dot(n, vec - v1) > 0 ? n : -n;
    }

    // PlaneNormalPN
    template<class T>
    inline LuVector<3, T> PlaneNormalPN( const LuVector<3, T>& vec, const LuVector<3, T>& v1, const LuVector<3, T>& n) 
    {
        return Dot(n, vec - v1)> 0 ? n : -n;
    }

};
#endif