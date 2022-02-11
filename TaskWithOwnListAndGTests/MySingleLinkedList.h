#pragma once
#ifdef _DEBUG
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#else
#define DBG_NEW new
#endif

template<class T>
class MySinglyLinkedList
{
	struct Node
	{
		T data;
		Node* next;
	};
public:
	class Iterator
	{
	public:
		Iterator(Node* current) : m_current(current) { }
		void operator++() { m_current = m_current->next; }
		bool operator!=(const Iterator& one) { return m_current != one.m_current; }
		T& operator*() { return m_current->data; }
	private:
		Node* m_current;
	};

	Iterator begin() const
	{
		return Iterator(m_head);
	}

	Iterator end() const
	{
		return Iterator(nullptr);
	}

	size_t size() const noexcept
	{
		return m_size;
	}

	bool empty()
	{
		return m_size == 0;
	}

	T& front()
	{
		return m_head->data;
	}

	T& back()
	{
		return m_tail->data;
	}

	void push_front(const T& value)
	{
		Node* newHead = DBG_NEW Node({ value, m_head });
		m_head = newHead;
		m_size += 1;
		if (1 == m_size)
		{
			m_tail = m_head;
		}
	}

	void push_back(const T& value)
	{
		if (0 == m_size)
		{
			push_front(value);
		}
		else
		{
			m_tail->next = DBG_NEW Node({ value, nullptr });
			m_tail = m_tail->next;
			m_size++;
		}
	}

	void pop_front()
	{
		Node* removal = m_head;
		m_head = m_head->next;
		delete removal;
		m_size--;
	}

	void pop_back()
	{
		if (1 == m_size)
		{
			pop_front();
		}
		else
		{
			Node* search = m_head;
			while (search->next != m_tail)
			{
				search = search->next;
			}
			delete m_tail;
			m_tail = search;
			m_tail->next = nullptr;
			m_size--;
		}
	}

	void reverse()
	{
		Node* currentPtr = m_head;
		Node* previousPtr = nullptr;
		Node* nextPtr = nullptr;

		m_tail = m_head;
		while (currentPtr != nullptr)
		{
			nextPtr = currentPtr->next;
			currentPtr->next = previousPtr;
			previousPtr = currentPtr;
			currentPtr = nextPtr;
		}
		m_head = previousPtr;
	}

	void resize(size_t count, const T& value = 0)
	{
		if (m_size == count) return;
		else if (m_size > count)
		{
			if (1 == m_size) // count == 0
			{
				pop_front();
			}
			else
			{
				Node* current = m_head;
				for (size_t i = 0; i < count - 1; i++)
				{
					current = current->next;
				}

				Node* temp = current;
				m_tail = temp;
				current = current->next;
				temp->next = nullptr; // break the list
				while (current->next != nullptr)
				{
					temp = current;
					current = current->next;
					delete temp;
				}
				delete current;
			}
			m_size = count;
		}
		else
		{
			int n = count - m_size;
			if (0 == m_size)
			{
				push_front(value);
				n--;
			}
			Node* current = m_tail;
			for (int i = 0; i < n; i++)
			{
				current->next = DBG_NEW Node({ value, nullptr });
				current = current->next;
			}
			m_tail = current;
			m_size = count;
		}
	}

	MySinglyLinkedList() = default;

	MySinglyLinkedList(const MySinglyLinkedList<T>& obj) // copy constructor 
	{
		*this = obj;
	}

	MySinglyLinkedList<T>& operator=(const MySinglyLinkedList<T>& obj) // copy assignment
	{
		_destruct();
		for (auto& it : obj) push_back(it);
		return *this;
	}

	MySinglyLinkedList<T>& operator=(const std::initializer_list<T> obj)
	{
		_destruct();
		for (auto& it : obj) push_back(it);
		return *this;
	}

	MySinglyLinkedList(const MySinglyLinkedList<T>&& obj) // move constructor 
	{
		*this = obj;
	}

	MySinglyLinkedList<T>& operator=(MySinglyLinkedList<T>&& obj) noexcept // move assignment
	{
		_destruct();
		m_size = obj.m_size;
		m_head = obj.m_head;
		m_tail = obj.m_tail;
		obj.m_size = 0;
		obj.m_head = nullptr;
		obj.m_tail = nullptr;
		return *this;
	}

	~MySinglyLinkedList()
	{
		_destruct();
	}
private:
	void _destruct()
	{
		Node* current = m_head;
		while (current != nullptr)
		{
			Node* removal = current->next;
			delete current;
			current = removal;
		}
		m_head = nullptr;
		m_tail = nullptr;
	}

	size_t m_size = 0;
	Node* m_head = nullptr;
	Node* m_tail = nullptr;
};