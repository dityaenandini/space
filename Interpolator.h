#ifndef _INTERPOLATOR_H_
#define _INTERPOLATOR_H_

#pragma once;
#include <map>

template < typename T >
class Interpolator
{
public:
	typedef std::map< float, typename T > Map;
	typedef typename Map::iterator Iterator;
	typedef typename Map::const_iterator ConstIterator;

	Interpolator(const T& defaultValue = T())
		: m_DefaultValue(defaultValue)
	{}

	// Add a value 
	void AddValue(float time, const T& value);

	// Get the interpolated value
	T GetValue(float time) const;

protected:

private:
	Map m_Values;
	T   m_DefaultValue;
};

template< typename T >
void Interpolator<T>::AddValue(float time, const T& value)
{
	m_Values[time] = value;
}

template< typename T >
T Interpolator<T>::GetValue(float time) const
{
	// Case 1.
	if (m_Values.size() < 1) return m_DefaultValue;
	// Case 2. 
	if (m_Values.size() == 1) return m_Values.begin()->second;
	// Case 3. 
	ConstIterator iter0 = m_Values.begin();
	ConstIterator iter1 = iter0;

	while (iter1 != m_Values.end())
	{
		if (iter1->first > time)
		{
			break;
		}
		iter0 = iter1;
		++iter1;
	}

	if (iter1 == m_Values.end())
	{
		return iter0->second;
	}

	// Linear Interpolate 
	float t0 = iter0->first;
	float t1 = iter1->first;

	float ratio = (time - t0) / (t1 - t0);

	const T& value0 = iter0->second;
	const T& value1 = iter1->second;

	return value0 * (1.0f - ratio) + (value1 * ratio);
}

#endif