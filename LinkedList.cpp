#include <iostream>
#include <complex>
#include <fstream>

using namespace std;

template <class T>
class Element
{
private:
	Element* next;
	Element* prev;
	T field;
public:
	Element(T value = 0, Element<T>* next_ptr = NULL, Element<T>* prev_ptr = NULL)
	{
		field = value;
		next = next_ptr;
		prev = prev_ptr;
	}

	virtual Element* getNext() { return next; }
	virtual void setNext(Element* value) { next = value; }

	virtual Element* getPrevious() { return prev; }
	virtual void setPrevious(Element* value) { prev = value; }

	virtual T getValue() { return field; }
	virtual void setValue(T value) { field = value; }
	template<class T> friend ostream& operator<< (ostream& ustream, Element<T>& obj);
};

template<class T>
ostream& operator<< (ostream& ustream, Element<T>& obj)
{
	ustream << obj.field;
	return ustream;
}


template <class T>
class LinkedListParent
{
protected:
	Element<T>* head;
	Element<T>* tail;
	int num;
public:
	virtual int Number() { return num; }
	virtual Element<T>* getBegin() { return head; }
	virtual Element<T>* getEnd() { return tail; }
	LinkedListParent()
	{
		head = tail = NULL;
		num = 0;
	}


	virtual Element<T>* push(T value) = 0;
	virtual Element<T>* pop() = 0;
	virtual ~LinkedListParent()
	{
		Element<T>* cur = head->getNext();
		while (cur != tail)
		{
			delete cur->getPrevious();
			cur = cur->getNext();
		}
		delete cur->getPrevious();
		delete tail;
	}

	virtual Element<T>* operator[](int i)
	{
		if (i < 0 || i > num) return NULL;
		int k = 0;
		Element<T>* cur = head;
		for (k = 0; k < i; k++)
		{
			cur = cur->getNext();
		}
		return cur;
	}

	template<class T> friend ostream& operator<< (ostream& ustream, LinkedListParent<T>& obj);
};

template<typename ValueType>
class ListIterator : public std::iterator<std::input_iterator_tag, ValueType>
{
private:
	Element<ValueType>* ptr;
public:
	ListIterator() { ptr = NULL; }

	ListIterator(Element<ValueType>* p) { ptr = p; }

	ListIterator(const ListIterator& it) { ptr = it.ptr; }

	bool operator!=(ListIterator const& other) const
	{
		return ptr != other.ptr;
	}

	bool operator==(ListIterator const& other) const
	{
		return ptr == other.ptr;
	}

	Element<ValueType>& operator*()
	{
		return *ptr;
	}

	ListIterator& operator++()
	{
		ptr = ptr->getNext();
		return *this;
	}

	ListIterator& operator++(int v)
	{
		ptr = ptr->getNext();
		return *this;
	}

	ListIterator& operator=(const ListIterator& it)
	{
		ptr = it.ptr;
		return *this;
	}

	ListIterator& operator=(Element<ValueType>* p)
	{
		ptr = p;
		return *this;
	}

	Element<ValueType>* getPtr()
	{
		return ptr;
	}
};

template<class T>
ostream& operator<<(ostream& ustream, LinkedListParent<T>& obj) //Вывод списка с помощью итераторов
{
	ListIterator<T> it = obj.head;
	cout << '\n';
	while (it.getPtr() != obj.tail)
	{
		cout << *it << " ";
		it++;
	}
	cout << *it << " ";
	return ustream;
}

template <class T>
class IteratedLinkedList : public LinkedListParent<T>
{
public:
	IteratedLinkedList() : LinkedListParent<T>() {}

	virtual ~IteratedLinkedList() {}

	ListIterator<T> iterator;

	ListIterator<T> begin()
	{
		ListIterator<T> it = LinkedListParent<T>::head;
		return it;
	}

	ListIterator<T> end()
	{
		ListIterator<T> it = LinkedListParent<T>::tail;
		return it;
	}
};

template <class T>
class LinkedList : public IteratedLinkedList<T> //Класс D - стек
{
public:
	LinkedList() : IteratedLinkedList<T>() {}
	virtual ~LinkedList() {}

	Element<T>* push(T value) //Добавление в конец
	{
		Element<T>* p = new Element<T>(value);
		if (LinkedListParent<T>::head == NULL)
		{
			LinkedListParent<T>::head = LinkedListParent<T>::tail = p;
			return p;
		}
		LinkedListParent<T>::tail->setNext(p);
		p->setPrevious(LinkedListParent<T>::tail);
		LinkedListParent<T>::tail = LinkedListParent<T>::tail->getNext();
		return p;
	}

	Element<T>* pop() //Удаление с конца
	{
		Element<T>* el = LinkedListParent<T>::head;
		if (LinkedListParent<T>::head == NULL) return el;
		if (LinkedListParent<T>::head == LinkedListParent<T>::tail)
		{
			LinkedListParent<T>::head = LinkedListParent<T>::tail = NULL;
			return el;
		}
		LinkedListParent<T>::tail = LinkedListParent<T>::tail->getPrevious();
		LinkedListParent<T>::tail->setNext(NULL);
		return el;
	}

	template <class T>
	LinkedList filter(bool (*ptr)(T)) //Функция filter 
	{
		ListIterator<T> it = this->begin();
		LinkedList<T> NewList;
		while (it != this->end())
		{
			if (ptr((*it).getValue()))
				NewList.push((*it).getValue());
			it++;
		}
		if (ptr((*it).getValue()))
			NewList.push((*it).getValue());
		return NewList;
	}
};


bool pred(complex<double> v)
{
	return v.real() < 0;
}

template <class T>
bool pred2(T v)
{
	return v > 6;
}

template <class T>
class SortedLinkedList : public LinkedList<T>
{
public:
	SortedLinkedList() : LinkedList<T>() {}

	Element<T>* push(T value) //Вставка элемента в отсортированный список
	{
		if (LinkedListParent<T>::head == NULL)
		{
			return LinkedList<T>::push(value);
		}
		Element<T>* p = new Element<T>(value);
		ListIterator<T> it = IteratedLinkedList<T>::begin();
		while (it != IteratedLinkedList<T>::end() and (*it).getValue() > p->getValue())
			it++;
		if ((*it).getValue() <= value)
		{
			p->setPrevious((*it).getPrevious());
			if ((*it).getPrevious() != NULL)
				(*it).getPrevious()->setNext(p);
			(*it).setPrevious(p);
			p->setNext(it.getPtr());
			if (p->getNext() == NULL)
				LinkedListParent<T>::tail = p;
			if (p->getPrevious() == NULL)
				LinkedListParent<T>::head = p;
			return p;
		}
		else
			return LinkedList<T>::push(value);
	}

	Element<T>* pop(int i = 0) //Удаление элемента с использованием итератора
	{
		if (this->head == NULL)
			return NULL;
		if (this->head == this->tail or i == 0)
			return this->pop();
		ListIterator<T> it = this->begin();
		for (int index = 0; index < i; index++)
			it++;
		if (it == this->end())
		{
			this->tail = LinkedListParent<T>::tail->getPrevious();
			return this->tail;
		}
		(*it).getNext()->setPrevious((*it).getPrevious());
		(*it).getPrevious()->setNext((*it).getNext());
		return it.getPtr();
	}
};

template <class T>
LinkedList<T> UnFilter(LinkedListParent<T>* S, bool (*ptr)(T)) 
{
	Element<T>* cur = S->getBegin();
	LinkedList<T> newL;
	while (cur != S->getEnd())
	{
		if (ptr(cur->getValue()))
			newL.push(cur->getValue());
		cur = cur->getNext();
	}
	if (ptr(cur->getValue()))
		newL.push(cur->getValue());
	return newL;
}

class sportsman
{
private:
	string fi;
	int medals;
	int vozvrast;
	string grajdanka;
	string vid;
public:
	sportsman(string fii, int med, int voz, string gra, string vidi)
	{
		fi = fii;
		medals = med;
		vozvrast = voz;
		grajdanka = gra;
		vid = vidi;
	}

	sportsman()
	{
		fi = " ";
		medals = 0;
		vozvrast = 0;
		grajdanka = " ";
		vid = " ";
	}

	bool operator> (sportsman a)
	{
		if (medals > a.medals)
		{
			return true;
		}
		else if (medals == a.medals)
		{
			if (vozvrast > a.vozvrast)
			{
				return true;
			}
			else if (vozvrast == a.vozvrast)
			{
				if (fi > a.fi)
				{
					return true;
				}
			}
		}
		return false;

	}

	bool operator<= (sportsman a)
	{
		if (medals <= a.medals)
		{
			return true;
		}
		else if (medals == a.medals)
		{
			if (vozvrast <= a.vozvrast)
			{
				return true;
			}
			else if (vozvrast == a.vozvrast)
			{
				if (fi <= a.fi)
				{
					return true;
				}
			}
		}
		return false;

	}
	friend ostream& operator<< (ostream& s, sportsman r);
};

ostream& operator<< (ostream& s, sportsman r)
{
	s << r.medals << " " << r.fi << r.grajdanka << r.vid << r.vozvrast;
	return s;
}

int main()
{
	LinkedList<int> testPush;
	for (int i = 0; i < 10; i++)
	{
		testPush.push(i + 7);
	}

	cout << testPush;
	testPush.pop();

	cout << testPush;

	SortedLinkedList<int> testPush2;
	for (int i = 10; i >= 0; i--)
	{
		testPush2.push(i);
	}
	cout << '\n';
	testPush2.push(2);
	testPush2.push(8);
	testPush2.push(15);

	cout << testPush2;

	testPush2.pop(5);

	cout << testPush2;

	LinkedList<complex<double>> testFilter;
	testFilter.push(-7);
	testFilter.push(-2);
	testFilter.push(-8);
	testFilter.push(4);
	testFilter.push(-8);
	testFilter.push(-3);
	testFilter.push(2);
	testFilter.push(8);
	cout << testFilter;

	LinkedList<complex<double>> F = testFilter.filter<complex<double>>(pred);

	cout << F;

	LinkedList<int> testUnFilter;
	for (int i = 0; i < 15; i++)
	{
		if (i % 3 == 0)
			testUnFilter.push(i - 24);
		else
			testUnFilter.push(i + 16);
	}

	cout << testUnFilter;
	LinkedListParent<int>* ptr = &testUnFilter;

	LinkedList<int> res = UnFilter<int>(ptr, pred2);
	cout << res;

	sportsman B("Vinogradov", 3, 19, "RS", "voleybol");
	sportsman B1("Ablom", 0, 19, "RS", "voleybol");
	sportsman B2("Gromov", 10, 19, "RS", "footbool");

	SortedLinkedList<sportsman> obj;
	obj.push(B);
	obj.push(B1);
	obj.push(B2);

	cout << obj;

	char c; cin >> c;
	return 0;
}


