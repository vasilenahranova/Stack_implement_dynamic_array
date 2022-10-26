#pragma once
#include<iostream>

template<typename T>
class RStack {
private:
	T* data;
	int topIndex;
	unsigned capacity;

	//help functions
	bool full() const;
	void resize();
	void copy(T const*);
	void erase();
	void copyRStack(RStack const&);
public:
	//big 4 because of th dynamic memory
	RStack();
	RStack(RStack const&);
	RStack& operator=(RStack const&);
	~RStack();


	//typical functions for the data structure Stack 
	bool isEmpty() const;
	void push(T const& x);
	T pop();
	T top() const;
};

const unsigned INITIAL_CAPACITY = 16;

//help functions definitions
template<typename T>
inline bool RStack<T>::full() const
{
	return topIndex==capacity-1;
}

template<typename T>
inline void RStack<T>::resize()
{
	T* temp = data;
	data=new T[2* capacity];
	copy(temp);
	capacity *= 2;
	delete[] temp;

}

template<typename T>
inline void RStack<T>::copy(T const* other)
{
	for (unsigned i = 0; i < capacity; i++) {
		data[i] = other[i];
	}

}

template<typename T>
inline void RStack<T>::erase()
{
	delete[] data;
}

template<typename T>
inline void RStack<T>::copyRStack(RStack const& other)
{
	capacity = other.capacity;
	topIndex = other.topIndex;
	data = new T[capacity];
	copy(other.data);
}

//big 4 definitions
template<typename T>
inline RStack<T>::RStack():topIndex(-1),capacity(INITIAL_CAPACITY)
{
	data = new T[capacity];
}

template<typename T>
inline RStack<T>::RStack(RStack const& other)
{
	copyRStack(other);
}

template<typename T>
inline RStack<T>& RStack<T>::operator=(RStack const& other)
{
	if (this != &other) {
		erase();

		copyRStack(other);
	}
	return *this;
}

template<typename T>
inline RStack<T>::~RStack()
{
	erase();
}

//basic functions for Stack definitions
template<typename T>
inline bool RStack<T>::isEmpty() const
{
	return topIndex == -1;
}

template<typename T>
inline void RStack<T>::push(T const& x)
{
	if (full()) {
		resize();
	}
	data[++topIndex] = x;
}

template<typename T>
inline T RStack<T>::pop()
{
	if (isEmpty()) {
		std::cout << "The stack is empty!No elements to pop!" << std::endl;
		return T();
	}
	return data[topIndex--];
}

template<typename T>
inline T RStack<T>::top() const
{
	if (isEmpty()) {
		std::cout << "The stack is empty.No top element!" << std::endl;
		return T();
	}
	return data[topIndex];
}
