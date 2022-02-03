#pragma once
#ifdef _DEBUG
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#else
#define DBG_NEW new
#endif

template<class T>
class MySingleLinkedList
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
		/*Node* currentPtr = m_head;
		while (currentPtr->next != nullptr)
		{
			currentPtr = currentPtr->next;
		}
		return currentPtr->data;*/
		return m_tail->data;
	}

	void push_front(const T& value)
	{
		Node* tempNode = DBG_NEW Node();
		tempNode->data = value;
		tempNode->next = m_head;
		m_head = tempNode;
		if (m_head->next == nullptr)
		{
			m_tail = m_head;
		}
		m_size++;
	}

	void push_back(const T& value)
	{
		if (m_head == nullptr)
		{
			push_front(value);
		}
		else
		{
			Node* tempNode = DBG_NEW Node();
			tempNode->data = value;
			tempNode->next = nullptr;
			/*Node* currentPtr = m_head;
			while (currentPtr->next != nullptr)
			{
				currentPtr = currentPtr->next;
			}
			currentPtr->next = tempNode;*/
			m_tail->next = tempNode;
			m_tail = m_tail->next;
			m_size++;
		}
	}

	void pop_front()
	{
		Node* tempNode = m_head;
		m_head = m_head->next;
		delete tempNode;
		m_size--;
	}

	void pop_back()
	{
		// Calling pop_back on an empty container results in undefined behavior. ref std::list
		if (m_head->next == nullptr)
		{
			pop_front();
		}
		else
		{
			Node* tempNode = m_head;
			while (tempNode->next->next != nullptr)
			{
				tempNode = tempNode->next;
			}
			delete tempNode->next;
			tempNode->next = nullptr;
			m_tail = tempNode;
			m_size--;
		}
	}

	void reverse()
	{
		Node* currentPtr = m_head;
		Node* previousPtr = nullptr;
		Node* nextPtr = nullptr;

		while (currentPtr != nullptr)
		{
			nextPtr = currentPtr->next;
			currentPtr->next = previousPtr;
			previousPtr = currentPtr;
			currentPtr = nextPtr;
		}
		m_head = previousPtr;
		currentPtr = m_head;
		while (currentPtr->next != nullptr)
		{
			currentPtr = currentPtr->next;
		}
		m_tail = currentPtr;
	}

	void resize(size_t count, const T& value = 100)
	{
		if (m_size == count) return;
		else if (m_size > count)
		{
			if (m_head->next == nullptr)
			{
				pop_front();
			}
			else
			{
				Node* currentPtr = m_head;
				for (int i = 0; i < count - 1; i++)
				{
					currentPtr = currentPtr->next;
				}

				Node* tempNode = currentPtr;
				m_tail = tempNode;
				currentPtr = currentPtr->next;
				tempNode->next = nullptr;
				while (currentPtr->next != nullptr)
				{
					tempNode = currentPtr;
					currentPtr = currentPtr->next;
					delete tempNode;
				}
				delete currentPtr;
			}
			m_size = count;
		}
		else
		{
			int n = count - m_size;
			if (m_head == nullptr)
			{
				push_front(value);
			}
			else
			{
				Node* currentPtr = m_tail;
				/*while (currentPtr->next != nullptr)
				{
					currentPtr = currentPtr->next;
				}*/
				for (int i = 0; i < n; i++)
				{
					Node* tempNode = DBG_NEW Node();
					tempNode->data = value;
					currentPtr->next = tempNode;
					currentPtr = currentPtr->next;
				}
				m_tail = currentPtr;
				m_size = count;
			}
		}
	}

	MySingleLinkedList() = default;

	MySingleLinkedList(const MySingleLinkedList<T>& obj) // copy constructor 
	{
		*this = obj;
	}

	MySingleLinkedList<T>& operator=(const MySingleLinkedList<T>& obj) // copy assignment
	{
		dispose();
		for (auto& it : obj) push_back(it);
		return *this;
	}

	MySingleLinkedList<T>& operator=(const std::initializer_list<T> obj) // copy assignment
	{
		dispose();
		for (auto& it : obj) push_back(it);
		return *this;
	}

	MySingleLinkedList(const MySingleLinkedList<T>&& obj) // move constructor 
	{
		*this = obj;
	}

	MySingleLinkedList<T>& operator=(MySingleLinkedList<T>&& obj) noexcept // move assignment
	{
		m_size = obj.m_size;
		m_head = obj.m_head;
		m_tail = obj.m_tail;
		obj.m_size = 0;
		obj.m_head = nullptr;
		obj.m_tail = nullptr;
		return *this;
	}

	~MySingleLinkedList()
	{
		dispose();
	}
private:
	int m_size = 0;
	Node* m_head = nullptr;
	Node* m_tail = nullptr;
	void dispose()
	{
		Node* currentPtr = m_head;
		while (currentPtr != nullptr)
		{
			Node* tempNode = currentPtr->next;
			delete currentPtr;
			currentPtr = tempNode;
		}
		m_head = nullptr;
		m_tail = nullptr;
	}

};