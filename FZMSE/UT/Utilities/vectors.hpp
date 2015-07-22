/*
 * vectors.hpp
 *
 *  Created on: 22 lip 2015
 *      Author: pkozuch
 */
#pragma once

#include <vector>


template <typename T>
bool isVectorsIdentical(std::vector<T> a, std::vector<T> b)
{
	if ( a.size() != b.size() )
		return false;

	if ( a.size() == 0 )
		return true;

	typename std::vector<T>::iterator itA = a.begin();
	typename std::vector<T>::iterator itB = b.begin();

	while( itA != a.end() && itB != b.end())
	{
		if ( (*itA) == (*itB) )
		{
			++ itA;
			++ itB;
		}
		else
			return false;
	}

	return true;
}
