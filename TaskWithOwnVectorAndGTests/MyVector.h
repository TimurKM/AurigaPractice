#pragma once
#include <iostream>

template<class T>
class MyVector
{
public:
	T& front()
	{
		return m_array[0];
	}

	T& back()
	{
		return m_array[m_size - 1];
	}

	T* data() noexcept
	{
		return m_array;
	}

	T& operator[](size_t pos)
	{
		return m_array[pos];
	}

	T& at(size_t pos)
	{
		if (pos >= m_size)
		{
			throw std::out_of_range("invalid vector<T> subscript");
		}
		return m_array[pos];
	}

	size_t size() const
	{
		return m_size;
	}

	size_t capacity() const
	{
		return m_capacity;
	}

	void shrink_to_fit()
	{
		if (m_capacity == m_size) return;
		m_capacity = m_size;
		T* newArray = new T[m_size];
		for (size_t i = 0; i < m_size; i++)
		{
			newArray[i] = std::move(m_array[i]);
		}
		delete[] m_array;
		m_array = newArray;
	}

	void clear()
	{
		m_size = 0;
		shrink_to_fit();
	}

	void push_back(const T& value)
	{
		if (m_size < m_capacity)
		{
			m_array[m_size] = value;
			m_size++;
		}
		else
		{
			m_capacity = m_capacity ? (2 * m_capacity) : 15;
			T* newArray = new T[m_capacity];
			for (size_t i = 0; i < m_size; i++)
			{
				newArray[i] = std::move(m_array[i]);
			}
			newArray[m_size] = value;
			m_size++;
			delete[] m_array;
			m_array = newArray;
		}
	}

	void pop_back()
	{
		m_size--;
		//m_array[m_size].~T(); // will cause problems with a real class
	}

	void resize(size_t count, const T& value)
	{
		if (m_size > count)
		{
			m_size = count;
			// calling ~T() will cause problems with a real class
		}
		else if (m_size < count)
		{
			if (m_capacity < count)
			{
				m_capacity = count;
				T* newArray = new T[m_capacity];
				for (size_t i = 0; i < m_size; i++)
				{
					newArray[i] = std::move(m_array[i]);
				}
				for (size_t i = m_size; i < m_capacity; i++)
				{
					newArray[i] = value;
				}
				delete[] m_array;
				m_array = newArray;
				m_size = m_capacity;
			}
			else
			{
				for (size_t i = m_size; i < count; i++)
				{
					m_array[i] = value;
				}
				m_size = count;
			}
		}
	}

	MyVector() // default constructor
	{
		m_size = 0;
		m_capacity = 15;
		m_array = new T[m_capacity];
	}

	MyVector(const MyVector<T>& obj) // copy constructor 
	{
		m_size = obj.m_size;
		m_capacity = obj.m_capacity;
		m_array = new T[m_capacity];
		for (size_t i = 0; i < obj.m_size; i++)
		{
			m_array[i] = obj.m_array[i];
		}
	}

	MyVector<T>& operator=(const std::initializer_list<T> obj)
	{
		clear();
		for (auto& it : obj) push_back(it);
		return *this;
	}

	MyVector(const MyVector<T>&& obj) // move constructor 
	{
		*this = obj;
	}

	MyVector<T>& operator=(MyVector<T>&& obj) noexcept // move assignment
	{
		m_size = obj.m_size;
		m_capacity = obj.m_capacity;
		m_array = obj.m_array;
		obj.m_size = 0;
		obj.m_capacity = 0;
		obj.m_array = nullptr;
		return *this;
	}

	~MyVector()
	{
		delete[] m_array;
	}

private:
	size_t m_size;
	size_t m_capacity;
	T* m_array;
	friend std::ostream& operator<<(std::ostream& os, MyVector const& m);
};

template <class T>
std::ostream& operator<<(std::ostream& os, MyVector<T> const& m)
{
	return m.m_ptr ? (os << m.m_ptr) : os;
}

