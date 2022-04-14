#pragma once

template <class T1, class T2>
class Pair
{
private:
	T1 m_first;
	T2 m_second;
public:
	Pair(T1 first, T2 second) : m_first(first), m_second(second)
	{

	}

	T1 first() const
	{
		return m_first;
	}

	T2 second() const
	{
		return m_second;
	}
};