
#include <iostream>
#include "LerpHelper.h"

int main( ) 
{
	LerpHelper::Point a = { 10, 5 };
	LerpHelper::Point b = { 12, 7 };
	LerpHelper::Point c = { -5, -10 };

	LerpHelper::Line l( LerpHelper::CalculateM( a, b ), LerpHelper::CalculateC(
		LerpHelper::CalculateM( a, b ), a ) );

	std::cout << l << std::endl;
	
	for ( LerpHelper::Point& p : l->GetPoints( a->x, b->x, 0.5 ) )
	{
		std::cout << p << std::endl;
	}

	LerpHelper::Point point = { 10, 10 };
	std::cout << point->x << std::endl;

	std::cout << ( l->IsPointOnLine( c ) ? "Point is on line" : "Point is not on line" ) << std::endl;

	std::cout << "Distance from a -> b: " << a->DistanceTo( b ) << std::endl;
}