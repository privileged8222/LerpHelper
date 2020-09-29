#pragma once
#include <vector>

namespace LerpHelper
{
	struct Point
	{
		float x, y;

		Point* operator -> ( )
		{
			return this;
		}
	};

	struct Line
	{
		float m, c;

		Line( float gradient, float intercept ) : m( gradient ), c( intercept ) { };

		std::vector<Point> GetPoints( float& start, float& end, float& res )
		{
			std::vector<Point> points{ };
			for ( float i = start; i <= end; i += res )
			{
				points.push_back( Point{ i, ( m * i ) + c } );
			}
			return points;
		}

		std::vector<Point> GetPoints( float& start, float& end, float&& res )
		{
			std::vector<Point> points{ };
			for ( float i = start; i <= end; i += res )
			{
				points.push_back( Point{ i, ( m * i ) + c } );
			}
			return points;
		}

		bool IsPointOnLine( Point& p )
		{
			if ( p->y - this->c == this->m * ( p->x ) )
			{
				return true;
			}
			return false;
		}

		bool IsPointOnLine( Point&& p )
		{
			if ( p->y - this->c == this->m * ( p->x ) )
			{
				return true;
			}
			return false;
		}

		Line* operator -> ( )
		{
			return this;
		}
	};

	inline float CalculateC( float& gradient, Point& p ) 
	{
		return ( gradient * ( -p.x ) + p.y );
	}

	inline float CalculateM( Point& a, Point& b )
	{
		return ( ( b.y - a.y ) / ( b.x - a.x ) );
	}

	inline float CalculateC( float&& gradient, Point& p )
	{
		return ( gradient * ( -p.x ) + p.y );
	}

	std::ostream& operator << ( std::ostream& os, const Point& p )
	{
		os << p.x << " " << p.y;
		return os;
	}

	std::ostream& operator << ( std::ostream& os, const Line& l )
	{
		os << "y = " << l.m << "x + " << l.c << "\n";
		return os;
	}
}