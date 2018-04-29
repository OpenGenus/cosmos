/*
Analytical calculations for sphere-tetrahedron intersections...
These calculations use a lot of vector math, so I had to include my vector class.
Vector class ends at around line 900, and intersection codes start.

 - RedBlight
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
	
	using namespace std;

	template< size_t N, class T >
	class LuVector;

	template< class T >
	using LuVector2 = LuVector< 2, T >;

	template< class T >
	using LuVector3 = LuVector< 3, T >;

	using LuVector2f = LuVector< 2, float >;
	using LuVector2d = LuVector< 2, double >;
	using LuVector2c = LuVector< 2, complex< double > >;

	using LuVector3f = LuVector< 3, float >;
	using LuVector3d = LuVector< 3, double >;
	using LuVector3c = LuVector< 3, complex< double > >;
	
	// LuVector_Op.hpp
	
	//////////////////////////////////////////////////////////////
	// TEMPLATE LOOP INDEX VARIABLE
	//////////////////////////////////////////////////////////////
	template< size_t N >
	struct LOOP_INDEX
	{

	};

	//////////////////////////////////////////////////////////////
	// TEMPLATE LOOP UNROLLING OPERATION FUNCTORS
	//////////////////////////////////////////////////////////////

	template< class T, class S >
	struct OP_COPY
	{
		inline void operator ()( T& lhs, const S& rhs )
		{
			lhs = rhs;
		}
	};

	//////////////////////////////////////////////////////////////

	template< class T, class S >
	struct OP_ADD
	{
		inline void operator ()( T& lhs, const S& rhs )
		{
			lhs += rhs;
		}
	};

	template< class T, class S >
	struct OP_SUB
	{
		inline void operator ()( T& lhs, const S& rhs )
		{
			lhs -= rhs;
		}
	};

	template< class T, class S >
	struct OP_MUL
	{
		inline void operator ()( T& lhs, const S& rhs )
		{
			lhs *= rhs;
		}
	};

	template< class T, class S >
	struct OP_DIV
	{
		inline void operator ()( T& lhs, const S& rhs )
		{
			lhs /= rhs;
		}
	};

	//////////////////////////////////////////////////////////////

	template< class T, class S >
	struct OP_ABS
	{
		inline void operator ()( T& lhs, const S& rhs )
		{
			lhs = abs( rhs );
		}
	};

	template< class T, class S >
	struct OP_ARG
	{
		inline void operator ()( T& lhs, const S& rhs )
		{
			lhs = arg( rhs );
		}
	};

	template< size_t N, class T, class S >
	struct OP_MIN
	{
		inline void operator ()( LuVector< N, T >& result, const LuVector< N, T >& lhs, const LuVector< N, S >& rhs, const size_t& I )
		{
			result[ I ] = lhs[ I ] < rhs[ I ] ? lhs[ I ] : rhs[ I ];
		}
	};

	template< size_t N, class T, class S >
	struct OP_MAX
	{
		inline void operator ()( LuVector< N, T >& result, const LuVector< N, T >& lhs, const LuVector< N, S >& rhs, const size_t& I )
		{
			result[ I ] = lhs[ I ] > rhs[ I ] ? lhs[ I ] : rhs[ I ];
		}
	};

	template< size_t N, class T, class S >
	struct OP_DOT
	{
		inline void operator ()( T& result, const LuVector< N, T >& lhs, const LuVector< N, S >& rhs, const size_t& I )
		{
			result += lhs[ I ] * rhs[ I ];
		}
	};

	//////////////////////////////////////////////////////////////

	template< class T >
	struct OP_OSTREAM
	{
		inline void operator ()( ostream& lhs, const T& rhs, const string& delimeter )
		{
			lhs << rhs << delimeter;
		}
	};
	
	// LuVector_Unroll.hpp
	
	//////////////////////////////////////////////////////////////
	// TEMPLATE LOOP UNROLLING
	//////////////////////////////////////////////////////////////

	// VECTOR OP SCALAR
	template< size_t I, size_t N, class T, class S, template< class, class > class OP >
	inline void UNROLL( LuVector< N, T >& lhs, const S& rhs, OP< T, S > operation, LOOP_INDEX< I > )
	{
		UNROLL( lhs, rhs, operation, LOOP_INDEX< I - 1 >() );
		operation( lhs[ I ], rhs );
	}

	template< size_t N, class T, class S, template< class, class > class OP >
	inline void UNROLL( LuVector< N, T >& lhs, const S& rhs, OP< T, S > operation, LOOP_INDEX< 0 > )
	{
		operation( lhs[ 0 ], rhs );
	}

	// SCALAR OP VECTOR
	template< size_t I, size_t N, class T, class S, template< class, class > class OP >
	inline void UNROLL( S& lhs, const LuVector< N, T >& rhs, OP< T, S > operation, LOOP_INDEX< I > )
	{
		UNROLL( lhs, rhs, operation, LOOP_INDEX< I - 1 >() );
		operation( lhs, rhs[ I ] );
	}

	template< size_t N, class T, class S, template< class, class > class OP >
	inline void UNROLL( S& lhs, const LuVector< N, T >& rhs, OP< T, S > operation, LOOP_INDEX< 0 > )
	{
		operation( lhs, rhs[ 0 ] );
	}

	// VECTOR OP VECTOR
	template< size_t I, size_t N, class T, class S, template< class, class > class OP >
	inline void UNROLL( LuVector< N, T >& lhs, const LuVector< N, S >& rhs, OP< T, S > operation, LOOP_INDEX< I > )
	{
		UNROLL( lhs, rhs, operation, LOOP_INDEX< I - 1 >() );
		operation( lhs[ I ], rhs[ I ] );
	}

	template< size_t N, class T, class S, template< class, class > class OP >
	inline void UNROLL( LuVector< N, T >& lhs, const LuVector< N, S >& rhs, OP< T, S > operation, LOOP_INDEX< 0 > )
	{
		operation( lhs[ 0 ], rhs[ 0 ] );
	}

	// SCALAR = VECTOR OP VECTOR (could be cross-element)
	template< size_t I, size_t N, class T, class S, template< size_t, class, class > class OP >
	inline void UNROLL( T& result, const LuVector< N, T >& lhs, const LuVector< N, S >& rhs, OP< N, T, S > operation, LOOP_INDEX< I > )
	{
		UNROLL( result, lhs, rhs, operation, LOOP_INDEX< I - 1 >() );
		operation( result, lhs, rhs, I );
	}

	template< size_t N, class T, class S, template< size_t, class, class > class OP >
	inline void UNROLL( T& result, const LuVector< N, T >& lhs, const LuVector< N, S >& rhs, OP< N, T, S > operation, LOOP_INDEX< 0 > )
	{
		operation( result, lhs, rhs, 0 );
	}

	// VECTOR = VECTOR OP VECTOR (could be cross-element)
	template< size_t I, size_t N, class T, class S, template< size_t, class, class > class OP >
	inline void UNROLL( LuVector< N, T >& result, const LuVector< N, T >& lhs, const LuVector< N, S >& rhs, OP< N, T, S > operation, LOOP_INDEX< I > )
	{
		UNROLL( result, lhs, rhs, operation, LOOP_INDEX< I - 1 >() );
		operation( result, lhs, rhs, I );
	}

	template< size_t N, class T, class S, template< size_t, class, class > class OP >
	inline void UNROLL( LuVector< N, T >& result, const LuVector< N, T >& lhs, const LuVector< N, S >& rhs, OP< N, T, S > operation, LOOP_INDEX< 0 > )
	{
		operation( result, lhs, rhs, 0 );
	}

	// OSTREAM OP VECTOR
	template< size_t I, size_t N, class T, template< class > class OP >
	inline void UNROLL( ostream& lhs, const LuVector< N, T >& rhs, const string& delimeter, OP< T > operation, LOOP_INDEX< I > )
	{
		UNROLL( lhs, rhs, delimeter, operation, LOOP_INDEX< I - 1 >() );
		operation( lhs, rhs[ I ], delimeter );
	}

	template< size_t N, class T, template< class > class OP >
	inline void UNROLL( ostream& lhs, const LuVector< N, T >& rhs, const string& delimeter, OP< T > operation, LOOP_INDEX< 0 > )
	{
		operation( lhs, rhs[ 0 ], delimeter );
	}
	
	// LuVector_Body.hpp
	
	template< size_t N, class T >
	class LuVector
	{
	private:
		T _[ N ];

	public:
		LuVector( )
		{

		}

		~LuVector()
		{

		}

		template< class... S > 
		LuVector( const S&... elem ) : _{ static_cast< T >(elem) ...}
		{

		}

		LuVector( const LuVector< N, const T >& other ) : _{ other._ }
		{

		}

		template< class S > 
		LuVector( const LuVector< N, S >& other )
		{
			UNROLL( *this, other, OP_COPY< T, S >(), LOOP_INDEX< N - 1 >() );
		}

		template< class S > 
		LuVector( const S& scalar )
		{
			UNROLL( *this, scalar, OP_COPY< T, S >(), LOOP_INDEX< N - 1 >() );
		}

		template< class S >
		inline LuVector< N, T >& operator =( const LuVector< N, S >& other )
		{
			UNROLL( *this, other, OP_COPY< T, S >(), LOOP_INDEX< N - 1 >() );
			return *this;
		}

		inline const T& operator []( const size_t& idx ) const
		{
			return _[ idx ];
		}

		inline T& operator []( const size_t& idx )
		{
			return _[ idx ];
		}

		inline string ToString() const
		{
			stringstream ss;
			ss << "(";
			UNROLL( ss, *this, ",", OP_OSTREAM< T >(), LOOP_INDEX< N - 2 >() );
			ss << _[ N - 1 ] << ")";
			return string( ss.str() );
		}

	};
	
	// LuVector_Overload.hpp
	
		//////////////////////////////////////////////////////////////
	// OPERATOR OVERLOADS
	//////////////////////////////////////////////////////////////

	// OSTREAM << VECTOR
	template< size_t N, class T >
	ostream& operator <<( ostream& lhs, const LuVector< N, T >& rhs )
	{
		lhs << "(";
		UNROLL( lhs, rhs, ",", OP_OSTREAM< T >(), LOOP_INDEX< N - 2 >() );
		lhs << rhs[ N - 1 ] << ")";
		return lhs;
	}

	// VECTOR += SCALAR
	template< size_t N, class T, class S >
	inline LuVector< N, T >& operator +=( LuVector< N, T >& lhs, const S& rhs )
	{
		UNROLL( lhs, rhs, OP_ADD< T, S >(), LOOP_INDEX< N - 1 >() );
		return lhs;
	}

	// VECTOR -= SCALAR
	template< size_t N, class T, class S >
	inline LuVector< N, T >& operator -=( LuVector< N, T >& lhs, const S& rhs )
	{
		UNROLL( lhs, rhs, OP_SUB< T, S >(), LOOP_INDEX< N - 1 >() );
		return lhs;
	}

	// VECTOR *= SCALAR
	template< size_t N, class T, class S >
	inline LuVector< N, T >& operator *=( LuVector< N, T >& lhs, const S& rhs )
	{
		UNROLL( lhs, rhs, OP_MUL< T, S >(), LOOP_INDEX< N - 1 >() );
		return lhs;
	}

	// VECTOR /= SCALAR
	template< size_t N, class T, class S >
	inline LuVector< N, T >& operator /=( LuVector< N, T >& lhs, const S& rhs )
	{
		UNROLL( lhs, rhs, OP_DIV< T, S >(), LOOP_INDEX< N - 1 >() );
		return lhs;
	}

	//////////////////////////////////////////////////////////////

	// VECTOR += VECTOR
	template< size_t N, class T, class S >
	inline LuVector< N, T >& operator +=( LuVector< N, T >& lhs, const LuVector< N, S >& rhs )
	{
		UNROLL( lhs, rhs, OP_ADD< T, S >(), LOOP_INDEX< N - 1 >() );
		return lhs;
	}

	// VECTOR -= VECTOR
	template< size_t N, class T, class S >
	inline LuVector< N, T >& operator -=( LuVector< N, T >& lhs, const LuVector< N, S >& rhs )
	{
		UNROLL( lhs, rhs, OP_SUB< T, S >(), LOOP_INDEX< N - 1 >() );
		return lhs;
	}

	// VECTOR *= VECTOR
	template< size_t N, class T, class S >
	inline LuVector< N, T >& operator *=( LuVector< N, T >& lhs, const LuVector< N, S >& rhs )
	{
		UNROLL( lhs, rhs, OP_MUL< T, S >(), LOOP_INDEX< N - 1 >() );
		return lhs;
	}

	// VECTOR /= VECTOR
	template< size_t N, class T, class S >
	inline LuVector< N, T >& operator /=( LuVector< N, T >& lhs, const LuVector< N, S >& rhs )
	{
		UNROLL( lhs, rhs, OP_DIV< T, S >(), LOOP_INDEX< N - 1 >() );
		return lhs;
	}

	//////////////////////////////////////////////////////////////

	// VECTOR + SCALAR
	template< size_t N, class T, class S >
	inline LuVector< N, T > operator +( const LuVector< N, T >& lhs, const S& rhs )
	{
		LuVector< N, T > result( lhs );
		return result += rhs;
	}

	// SCALAR + VECTOR
	template< size_t N, class T, class S >
	inline LuVector< N, T > operator +( const T& lhs, const LuVector< N, S >& rhs )
	{
		LuVector< N, T > result( lhs );
		return result += rhs;
	}

	// VECTOR - SCALAR
	template< size_t N, class T, class S >
	inline LuVector< N, T > operator -( const LuVector< N, T >& lhs, const S& rhs )
	{
		LuVector< N, T > result( lhs );
		return result -= rhs;
	}

	// SCALAR - VECTOR
	template< size_t N, class T, class S >
	inline LuVector< N, T > operator -( const T& lhs, const LuVector< N, S >& rhs )
	{
		LuVector< N, T > result( lhs );
		return result -= rhs;
	}

	// VECTOR * SCALAR
	template< size_t N, class T, class S >
	inline LuVector< N, T > operator *( const LuVector< N, T >& lhs, const S& rhs )
	{
		LuVector< N, T > result( lhs );
		return result *= rhs;
	}

	// SCALAR * VECTOR
	template< size_t N, class T, class S >
	inline LuVector< N, T > operator *( const T& lhs, const LuVector< N, S >& rhs )
	{
		LuVector< N, T > result( lhs );
		return result *= rhs;
	}

	// VECTOR / SCALAR
	template< size_t N, class T, class S >
	inline LuVector< N, T > operator /( const LuVector< N, T >& lhs, const S& rhs )
	{
		LuVector< N, T > result( lhs );
		return result /= rhs;
	}

	// SCALAR / VECTOR
	template< size_t N, class T, class S >
	inline LuVector< N, T > operator /( const T& lhs, const LuVector< N, S >& rhs )
	{
		LuVector< N, T > result( lhs );
		return result /= rhs;
	}

	//////////////////////////////////////////////////////////////

	// VECTOR + VECTOR
	template< size_t N, class T, class S >
	inline LuVector< N, T > operator +( const LuVector< N, T >& lhs, const LuVector< N, S >& rhs )
	{
		LuVector< N, T > result( lhs );
		return result += rhs;
	}

	// VECTOR - VECTOR
	template< size_t N, class T, class S >
	inline LuVector< N, T > operator -( const LuVector< N, T >& lhs, const LuVector< N, S >& rhs )
	{
		LuVector< N, T > result( lhs );
		return result -= rhs;
	}

	// VECTOR * VECTOR
	template< size_t N, class T, class S >
	inline LuVector< N, T > operator *( const LuVector< N, T >& lhs, const LuVector< N, S >& rhs )
	{
		LuVector< N, T > result( lhs );
		return result *= rhs;
	}

	// VECTOR / VECTOR
	template< size_t N, class T, class S >
	inline LuVector< N, T > operator /( const LuVector< N, T >& lhs, const LuVector< N, S >& rhs )
	{
		LuVector< N, T > result( lhs );
		return result /= rhs;
	}

	//////////////////////////////////////////////////////////////

	// - VECTOR
	template< size_t N, class T >
	inline LuVector< N, T > operator -( const LuVector< N, T >& vec )
	{
		return T( 0 ) - vec;
	}

	//////////////////////////////////////////////////////////////

	// VECTOR == VECTOR
	//	template< size_t N, class T, class S >
	//	inline bool operator ==( const Vec< N, T >& lhs, const Vec< N, S >& rhs )
	//	{
	//		return lhs[0] == static_cast< T >( rhs[0] ) && lhs[1] == static_cast< T >( rhs[1] ) && lhs[2] == static_cast< T >( rhs[2] );
	//	}
	
	// LuVector_Math.hpp
	
	template< size_t N, class T >
	inline T Sum( const LuVector< N, T >& vec )
	{
		T result = 0;
		UNROLL( result, vec, OP_ADD< T, T >(), LOOP_INDEX< N - 1 >() );
		return result;
	}

	// Abs
	template< size_t N, class T >
	inline LuVector< N, T > Abs( const LuVector< N, T >& vec )
	{
		LuVector< N, T > absVec;
		UNROLL( absVec, vec, OP_ABS< T, T >(), LOOP_INDEX< N - 1 >() );
		return absVec;
	}

	// Length
	template< size_t N, class T >
	inline T Length( const LuVector< N, T >& vec )
	{
		T result = 0;
		UNROLL( result, vec, vec, OP_DOT< N, T, T >(), LOOP_INDEX< N - 1 >() );
		return sqrt( result );
	}

	// Unit
	template< size_t N, class T >
	inline LuVector< N, T > Unit( const LuVector< N, T >& vec )
	{
		return vec / Length( vec );
	}

	//////////////////////////////////////////////////////////////

	// Abs Complex
	template< size_t N, class T >
	inline LuVector< N, T > Abs( const LuVector< N, complex< T > >& vec )
	{
		LuVector< N, T > absVec;
		UNROLL( absVec, vec, OP_ABS< T, complex< T > >(), LOOP_INDEX< N - 1 >() );
		return absVec;
	}

	// Arg Complex
	template< size_t N, class T >
	inline LuVector< N, T > Arg( const LuVector< N, complex< T > >& vec )
	{
		LuVector< N, T > argVec;
		UNROLL( argVec, vec, OP_ARG< T, complex< T > >(), LOOP_INDEX< N - 1 >() );
		return argVec;
	}

	// Length Complex
	template< size_t N, class T >
	inline T Length( const LuVector< N, complex< T > >& vec )
	{
		return Length( Abs( vec ) ); 
	}

	// Unit Complex
	template< size_t N, class T >
	inline LuVector< N, complex< T > > Unit( const LuVector< N, complex< T > >& vec )
	{
		return vec / Length( vec );
	}

	//////////////////////////////////////////////////////////////

	// Min
	template< size_t N, class T, class S >
	inline LuVector< N, T > Min( const LuVector< N, T >& lhs, const LuVector< N, S >& rhs )
	{
		LuVector< N, T > result;
		UNROLL( result, lhs, rhs, OP_MIN< N, T, S >(), LOOP_INDEX< N - 1 >() );
		return result;
	}

	// Max
	template< size_t N, class T, class S >
	inline LuVector< N, T > Max( const LuVector< N, T >& lhs, const LuVector< N, S >& rhs )
	{
		LuVector< N, T > result;
		UNROLL( result, lhs, rhs, OP_MAX< N, T, S >(), LOOP_INDEX< N - 1 >() );
		return result;
	}

	// Dot
	template< size_t N, class T, class S >
	inline T Dot( const LuVector< N, T >& lhs, const LuVector< N, S >& rhs )
	{
		T result = 0;
		UNROLL( result, lhs, rhs, OP_DOT< N, T, S >(), LOOP_INDEX< N - 1 >() );
		return result;
	}

	// Cross
	template< class T, class S >
	inline LuVector< 3, T > Cross( const LuVector< 3, T >& lhs, const LuVector< 3, S >& rhs )
	{
		return LuVector< 3, T >(
			lhs[1] * rhs[2] - lhs[2] * rhs[1],
			lhs[2] * rhs[0] - lhs[0] * rhs[2],
			lhs[0] * rhs[1] - lhs[1] * rhs[0]
		);
	}

	//////////////////////////////////////////////////////////////

	// Reflect
	template< size_t N, class T, class S >
	inline LuVector< N, T > Reflect( const LuVector< N, T >& vec, const LuVector< N, S >& normal )
	{
		return vec - normal * Dot( vec, normal ) * 2;
	}

	// Rotate...

	//////////////////////////////////////////////////////////////

	// CtsToSph
	template< class T >
	inline LuVector< 3, T > CtsToSph( const LuVector< 3, T >& cts )
	{
		T len = Length( cts );
		return LuVector< 3, T >(
			len,
			cts[0] == 0 && cts[1] == 0 ? 0 : atan2( cts[1], cts[0] ),
			acos( cts[2] / len )
		);
	}

	// SphToCts
	template< class T >
	inline LuVector< 3, T > SphToCts( const LuVector< 3, T >& sph )
	{
		T planarVal = sph[0] * sin( sph[2] );
		return LuVector< 3, T >(
			planarVal * cos( sph[1] ),
			planarVal * sin( sph[1] ),
			sph[0] * cos( sph[2] )
		);
	}

	// CtsToPol
	template< class T >
	inline LuVector< 2, T > CtsToPol( const LuVector< 2, T >& cts )
	{
		T len = Length( cts );
		return LuVector< 2, T >(
			len,
			cts[0] == 0 && cts[1] == 0 ? 0 : atan2( cts[1], cts[0] )
		);
	}

	// PolToCts
	template< class T >
	inline LuVector< 2, T > PolToCts( const LuVector< 2, T >& pol )
	{
		return LuVector< 2, T >(
			pol[0] * cos( pol[1] ),
			pol[0] * sin( pol[1] )
		);
	}

	//////////////////////////////////////////////////////////////

	// OrthonormalSet N=3
	// N: looking outside the sphere at given angles
	// U: up vector
	// R: right vector, parallel to XY plane
	// N = U X R 
	template< class T >
	inline void OrthonormalSet( const T& angP, const T& angT, LuVector< 3, T >& dirN, LuVector< 3, T >& dirU, LuVector< 3, T >& dirR )
	{
		T cp = cos( angP );
		T sp = sin( angP );
		T ct = cos( angT );
		T st = sin( angT );

		dirN[0] = st * cp;
		dirN[1] = st * sp;
		dirN[2] = ct;

		dirR[0] = sp;
		dirR[1] = - cp;
		dirR[2] = 0;

		dirU = Cross( dirR, dirN );
	}

	// OrthonormalSet N=2
	template< class T >
	inline void OrthonormalSet( const T& ang, LuVector< 2, T >& dirN, LuVector< 2, T >& dirR )
	{
		T c = cos( ang );
		T s = sin( ang );

		dirN[0] = c;
		dirN[1] = s;

		dirR[0] = s;
		dirR[1] = - c;
	}

	// OrthogonalR N=3
	template< class T >
	inline LuVector< 3, T > OrthonormalR( const LuVector< 3, T >& dirN )
	{
		T ang = dirN[0] == 0 && dirN[1] == 0 ? 0 : atan2( dirN[1], dirN[0] );
		T c = cos( ang );
		T s = sin( ang );

		return LuVector< 3, T >( s, -c, 0 ); 
	}

	// OrthogonalR N=2
	template< class T >
	inline LuVector< 2, T > OrthonormalR( const LuVector< 2, T >& dirN )
	{
		return LuVector< 2, T >( dirN[1], -dirN[0] ); 
	}

	// OrthogonalU N=3
	template< class T >
	inline LuVector< 3, T > OrthonormalU( const LuVector< 3, T >& dirN )
	{
		return Cross( OrthogonalR( dirN ), dirN ); 
	}
	
	// LuVector_Geometry.hpp
	
	//////////////////////////////////////////////////////////////
	// LUV GEOMETRY
	//////////////////////////////////////////////////////////////

	// ProjLine N=3
	template< class T >
	inline LuVector< 3, T > ProjLine( const LuVector< 3, T >& vec, const LuVector< 3, T >&v1, const LuVector< 3, T >& v2 ) 
	{
		LuVector< 3, T > v12 = Unit( v2 - v1 );
		return v1 + Dot( v12, vec - v1 ) * v12;
	}

	// ProjLine N=2
	template< class T >
	inline LuVector< 2, T > ProjLine( const LuVector< 2, T >& vec, const LuVector< 2, T >&v1, const LuVector< 2, T >& v2 ) 
	{
		LuVector< 2, T > v12 = Unit( v2 - v1 );
		return v1 + Dot( v12, vec - v1 ) * v12;
	}

	// ProjLineL N=3
	template< class T >
	inline LuVector< 3, T > ProjLineL( const LuVector< 3, T >& vec, const LuVector< 3, T >&v1, const LuVector< 3, T >& lineDir ) 
	{
		return v1 + Dot( lineDir, vec - v1 ) * lineDir;
	}

	// ProjLineL N=2
	template< class T >
	inline LuVector< 2, T > ProjLineL( const LuVector< 2, T >& vec, const LuVector< 2, T >&v1, const LuVector< 2, T >& lineDir )  
	{
		return v1 + Dot( lineDir, vec - v1 ) * lineDir;
	}

	// LineNormal N=3
	template< class T >
	inline LuVector< 3, T > LineNormal( const LuVector< 3, T >& v1, const LuVector< 3, T >& v2 ) 
	{
		LuVector< 3, T > v12 = Unit( v2 - v1 );
		return OrthogonalR( v12 );
	}

	// LineNormal N=2
	template< class T >
	inline LuVector< 2, T > LineNormal( const LuVector< 2, T >& v1, const LuVector< 2, T >& v2 ) 
	{
		LuVector< 2, T > v12 = Unit( v2 - v1 );
		return OrthogonalR( v12 );
	}

	// LineNormalL N=3
	template< class T >
	inline LuVector< 3, T > LineNormalL( const LuVector< 3, T >& lineDir ) 
	{
		return OrthogonalR( lineDir );
	}

	// LineNormalL N=2
	template< class T >
	inline LuVector< 2, T > LineNormalL( const LuVector< 2, T >& lineDir ) 
	{
		return OrthogonalR( lineDir );
	}

	// LineNormalP N=3
	template< class T >
	inline LuVector< 3, T > LineNormalP( const LuVector< 3, T >& vec, const LuVector< 3, T >& v1, const LuVector< 3, T >& v2 ) 
	{
		LuVector< 3, T > v12 = Unit( v2 - v1 );
		LuVector< 3, T > ort = vec - ProjLineL( vec, v1, v12 );
		T len = Length( ort );
		return len > 0 ? ort / len : LineNormalL( v12 );
	}

	// LineNormalP N=2
	template< class T >
	inline LuVector< 2, T > LineNormalP( const LuVector< 2, T >& vec, const LuVector< 2, T >& v1, const LuVector< 2, T >& v2 ) 
	{
		LuVector< 2, T > v12 = Unit( v2 - v1 );
		LuVector< 2, T > ort = vec - ProjLineL( vec, v1, v12 );
		T len = Length( ort );
		return len > 0 ? ort / len : LineNormalL( v12 );
	}

	// LineNormalPL N=3
	template< class T >
	inline LuVector< 3, T > LineNormalPL( const LuVector< 3, T >& vec, const LuVector< 3, T >& v1, const LuVector< 3, T >& lineDir )  
	{
		LuVector< 3, T > ort = vec - ProjLineL( vec, v1, lineDir );
		T len = Length( ort );
		return len > 0 ? ort / len : LineNormalL( lineDir );
	}

	// LineNormalPL N=2
	template< class T >
	inline LuVector< 2, T > LineNormalPL( const LuVector< 2, T >& vec, const LuVector< 2, T >& v1, const LuVector< 2, T >& lineDir ) 
	{
		LuVector< 2, T > ort = vec - ProjLineL( vec, v1, lineDir );
		T len = Length( ort );
		return len > 0 ? ort / len : LineNormalL( lineDir );
	}

	//////////////////////////////////////////////////////////////

	// ProjPlane
	template< class T >
	inline LuVector< 3, T > ProjPlane( const LuVector< 3, T >& vec, const LuVector< 3, T >& v1, const LuVector< 3, T >& n ) 
	{
		return vec - Dot( vec - v1, n ) * n;
	}

	// PlaneNormal
	template< class T >
	inline LuVector< 3, T > PlaneNormal( const LuVector< 3, T >& v1, const LuVector< 3, T >& v2, const LuVector< 3, T >& v3 )
	{
		return Unit( Cross( v2 - v1, v3 - v1 ) );
	}

	// PlaneNormalP
	template< class T >
	inline LuVector< 3, T > PlaneNormalP(  const LuVector< 3, T >& vec, const LuVector< 3, T >& v1, const LuVector< 3, T >& v2, const LuVector< 3, T >& v3 ) 
	{
		LuVector< 3, T > n = PlaneNormal( v1, v2, v3 );
		return Dot( n, vec - v1 ) > 0 ? n : -n;
	}

	// PlaneNormalPN
	template< class T >
	inline LuVector< 3, T > PlaneNormalPN(  const LuVector< 3, T >& vec, const LuVector< 3, T >& v1, const LuVector< 3, T >& n ) 
	{
		return Dot( n, vec - v1 ) > 0 ? n : -n;
	}

};
#endif

const double pi = 3.14159265358979323846;
using Vec3 = LUV::LuVector< 3, double >;

double SolidAngleCap( double apexAngle )
{
	return 2.0 * pi * ( 1.0 - std::cos( apexAngle ) );
}

double SolidAngleWedge( const Vec3& v1, const Vec3& v2, const Vec3& v3 )
{
	double ang0 = std::acos( LUV::Dot( v1, v2 ) );
	double ang1 = std::acos( LUV::Dot( v2, v3 ) );
	double ang2 = std::acos( LUV::Dot( v3, v1 ) );
	double angSum = ( ang0 + ang1 + ang2 ) / 2.0;
	return 4.0 * std::atan( std::sqrt(
		std::tan( angSum / 2.0 )
		* std::tan( ( angSum - ang0 ) / 2.0 )
		* std::tan( ( angSum - ang1 ) / 2.0 )
		* std::tan( ( angSum - ang2 ) / 2.0 )
	) );
}

double VolumeCap( double radius, double height )
{
	return radius * radius * height * pi * ( 2.0 / 3.0 ); 
}

double VolumeCone( double radius, double height )
{
	return radius * radius * height * pi * ( 1.0 / 3.0 );
}

double VolumeTetrahedron( const Vec3& v1, const Vec3& v2, const Vec3& v3, const Vec3& v4 )
{
	return std::abs( LUV::Dot( v1 - v4, LUV::Cross( v2 - v4, v3 - v4 ) ) ) / 6.0;
}

double VolumeWedge( const Vec3& v1, const Vec3& v2, const Vec3& v3, double radius )
{
	return SolidAngleWedge( v1, v2, v3 ) * radius * radius * radius / 3.0;
}

class ObservationTetrahedron
{
public:
	
	// Cartesian coordinates of vertices:
	Vec3 posR, posA, posB, posC;
	
	// Distances from posR:
	double lenA, lenB, lenC;
	
	// Direction of sphere-line intersections as radius increases:
	Vec3 prdA, prdB, prdC, prdD, prdE, prdF;
	
	// Some angles between lines:
	double angBAC, angERA, angFAE, solidAngleFull;
	
private:

	// Angles of RBF triangle
	double angRBF, angBFR, angFRB;
	
	// Distance of sphere-line intersections:
	double prlA, prlB, prlC, prlD, prlE, prlF;
	//R->A, R->B, R->C, A->B, A->C, B->C
	
	// Positions of sphere-line intersections:
	Vec3 prpA, prpB, prpC, prpD, prpE, prpF;
	
	// Positions relative to posR:
	// All have the length = radius
	Vec3 vecA, vecB, vecC, vecD, vecE, vecF;
	
	// Directions from posR:
	Vec3 dirA, dirB, dirC, dirD, dirE, dirF;
	
	void Recalculate( double radius )
	{
		angRBF = std::acos( LUV::Dot( posR - posB, posC - posB ) );
		angBFR = std::asin( lenB * std::sin( angRBF ) / radius );
		angFRB = pi - ( angRBF + angBFR );
		
		prlA = radius;
		prlB = radius;
		prlC = radius;
		prlD = std::sqrt( radius * radius - lenA * lenA );
		prlE = prlD;
		prlF = lenB * std::sin( angFRB ) / sin( angBFR );

		prpA = posR + prdA * prlA;
		prpB = posR + prdB * prlB;
		prpC = posR + prdC * prlC;
		prpD = posA + prdD * prlD;
		prpE = posA + prdE * prlE;
		prpF = posB + prdF * prlF;
        
		vecA = prpA - posR;
		vecB = prpB - posR;
		vecC = prpC - posR;
		vecD = prpD - posR;
		vecE = prpE - posR;
		vecF = prpF - posR;
		
		dirA = vecA / LUV::Length( vecA );
		dirB = vecB / LUV::Length( vecB );
		dirC = vecC / LUV::Length( vecC );
		dirD = vecD / LUV::Length( vecD );
		dirE = vecE / LUV::Length( vecE );
		dirF = vecF / LUV::Length( vecF );
		
		angERA = std::acos( LUV::Dot( dirE, dirA ) );
		Vec3 vecAF = prpF - posA;
		Vec3 vecAE = prpE - posA;
		angFAE = std::acos( LUV::Dot( vecAF, vecAE ) / ( LUV::Length( vecAF ) * LUV::Length( vecAE ) ) );
	}
	
public:

	ObservationTetrahedron( const Vec3& vR, const Vec3& vA, const Vec3& vB, const Vec3& vC )
	{
		posR = vR;
		posA = vA;
		posB = vB;
		posC = vC;
		
		Vec3 AmR = vA - vR;
		Vec3 BmR = vB - vR;
		Vec3 CmR = vC - vR;
		Vec3 BmA = vB - vA;
		Vec3 CmA = vC - vA;
		Vec3 CmB = vC - vB;
		
		lenA = LUV::Length( AmR );
		lenB = LUV::Length( BmR );
		lenC = LUV::Length( CmR );
		
		prdA = AmR / lenA;
		prdB = BmR / lenB;
		prdC = CmR / lenC;
		prdD = BmA / LUV::Length( BmA );
		prdE = CmA / LUV::Length( CmA );
		prdF = CmB / LUV::Length( CmB );
		
		angBAC = std::acos( LUV::Dot( prdD, prdE ) );
		solidAngleFull = SolidAngleWedge( prdA, prdB, prdC );
	}
	
	double GetSolidAngle( double radius )
	{
		Recalculate( radius );
		if( radius > lenC )
		{
			return 0;
		}
		else if( radius > lenB )
		{
			return SolidAngleWedge( dirA, dirC, dirF )
				- SolidAngleCap( angERA ) * angFAE / ( 2.0 * pi );
		}
		else if( radius > lenA )
		{
			return solidAngleFull
				- SolidAngleCap( angERA ) * angBAC / ( 2.0 * pi );
		}
		else
		{
			return solidAngleFull;
		}
	}
	
	double GetSurfaceArea( double radius )
	{
		return GetSolidAngle( radius ) * radius * radius;
	}
	
	double GetVolume( double radius )
	{
		Recalculate( radius );
		if( radius > lenC )
		{
			return VolumeTetrahedron( posR, posA, posB, posC );
		}
		else if( radius > lenB )
		{
			return ( VolumeWedge( dirA, dirC, dirF, radius ) - (
				VolumeCap( radius, LUV::Length( prpA - posA ) )
				- VolumeCone( prlE, lenA )
				) * angFAE / ( 2.0 * pi ) )
				+ VolumeTetrahedron( posR, posA, posB, prpF );
		}
		else if( radius > lenA )
		{
			return VolumeWedge( dirA, dirB, dirC, radius ) - (
				VolumeCap( radius, LUV::Length( prpA - posA ) )
				- VolumeCone( prlE, lenA )
				) * angBAC / ( 2.0 * pi );
		}
		else
		{
			return VolumeWedge( dirA, dirB, dirC, radius );
		}
	}
	
};

class SphereTetrahedronIntersection
{
	
private:

	std::vector< ObservationTetrahedron > obsTet;
	std::vector< double > obsTetSgn;
	std::vector< Vec3 > dirN;
	std::vector< Vec3 > dirU;
	std::vector< Vec3 > dirL;
	
	void AddEdge( const Vec3& vecM, const Vec3& vecP, const Vec3& vecT, const Vec3& vecR )
	{
		Vec3 PmM = vecP - vecM;
		dirL.push_back( PmM / LUV::Length( PmM ) );
		Vec3 vecU = vecT - LUV::ProjLine( vecT, vecM, vecP );
		dirU.push_back( vecU / LUV::Length( vecU ) );
		Vec3 vecA = LUV::ProjPlane( vecR, vecM, LUV::PlaneNormal( vecM, vecP, vecT ) );
		Vec3 vecB = LUV::ProjLine( vecA, vecM, vecP );
		obsTet.push_back( ObservationTetrahedron( vecR, vecA, vecB, vecP ) );
		obsTet.push_back( ObservationTetrahedron( vecR, vecA, vecB, vecM ) );
	}
	
	void AddFace( const Vec3& vecA, const Vec3& vecB, const Vec3& vecC, const Vec3& vecU , const Vec3& vecR )
	{
		Vec3 vecN = vecU - LUV::ProjPlane( vecU, vecA, LUV::PlaneNormal( vecA, vecB, vecC ) );
		dirN.push_back( vecN / LUV::Length( vecN ) );
		AddEdge( vecA, vecB, vecC, vecR );
		AddEdge( vecB, vecC, vecA, vecR );
		AddEdge( vecC, vecA, vecB, vecR );
	}
	
public:
	
	SphereTetrahedronIntersection( const Vec3& vecTetA, const Vec3& vecTetB, const Vec3& vecTetC, const Vec3& vecTetD, const Vec3& vecSphCenter )
	{
		AddFace( vecTetA, vecTetB, vecTetC, vecTetD, vecSphCenter );
		AddFace( vecTetB, vecTetC, vecTetD, vecTetA, vecSphCenter );
		AddFace( vecTetC, vecTetD, vecTetA, vecTetB, vecSphCenter );
		AddFace( vecTetD, vecTetA, vecTetB, vecTetC, vecSphCenter );
		for( int idf = 0; idf < 4; ++idf )
		{
			for( int idl = 0; idl < 3; ++idl )
			{
				int ids = 3 * idf + idl;
				int idp = 2 * ids;
				int idm = idp + 1;
				
				obsTetSgn.push_back(
					LUV::Dot( obsTet[idp].prdA, dirN[idf] )
					* LUV::Dot( obsTet[idp].prdF, dirL[ids] )
					* LUV::Dot( obsTet[idp].prdD, dirU[ids] )
				);
				
				obsTetSgn.push_back(
					- LUV::Dot( obsTet[idm].prdA, dirN[idf] )
					* LUV::Dot( obsTet[idm].prdF, dirL[ids] )
					* LUV::Dot( obsTet[idm].prdD, dirU[ids] )
				);
			}
		}
	}
	
	double GetSolidAngle( double radius )
	{
		double solidAngle = 0;
		for( int idx = 0; idx < 24; ++idx )
		{
			solidAngle += obsTet[idx].GetSolidAngle( radius ) * obsTetSgn[idx];
		}
		return solidAngle;
	}
	
	double GetSurfaceArea( double radius )
	{
		return GetSolidAngle( radius ) * radius * radius;
	}
	
	double GetVolume( double radius )
	{
		double volume = 0;
		for( int idx = 0; idx < 24; ++idx )
		{
			volume += obsTet[idx].GetVolume( radius ) * obsTetSgn[idx];
		}
		return volume;
	}
};

int main()
{
    using namespace std;
    
    // An example tetrahedron with a volume of 1000
    Vec3 vecTetA( 0, 0, 0 );
    Vec3 vecTetB( 10, 0, 0 );
    Vec3 vecTetC( 0, 20, 0 );
    Vec3 vecTetD( 0, 0, 30 );
    
    // Center of the sphereş
    Vec3 vecSphCenter( 3, 3, 3 );
    
    SphereTetrahedronIntersection testIntersection( vecTetA, vecTetB, vecTetC, vecTetD, vecSphCenter );
    
    // @ radius = 1 
    double srf = testIntersection.GetSurfaceArea( 1 ) / pi; // must be 4
    double vol = testIntersection.GetVolume( 1 ) / pi; // must be 4/3
    cout << srf << ", " << vol << endl;
    
    // @ radius = 30
    srf = testIntersection.GetSurfaceArea( 30 ); // must be 0
    vol = testIntersection.GetVolume( 30 ); // must be 1000
    cout << srf << ", " << vol << endl;
    
    // Numerical integral of surface area to obtain volume
    int N = 10000;
    double L = 0;
    double U = 13;
    double S = ( U - L ) / (double)N;
    double V = 0;
    for( double R = L; R < U; R += S )
    {
        V += testIntersection.GetSurfaceArea( R ) * S;
    }
    cout << V << ", " << testIntersection.GetVolume( U ) << endl; // must be almost equal
    
    return 0;
}
	
	











