#ifndef VECTOR_H
#define VECTOR_H __declspec(dllexport)
#else
#define VECTOR_H __declspec(dllimport)
#endif 
#pragma once
#include <stdexcept>

template <typename T>
class Vector
{
public:
	class Iterator
	{
	public:
		Iterator(const Vector<T>* vector, int nIndex);
		const T& operator*() const;
		Iterator& operator++();
		bool operator!=(const Iterator& other) const;

	private:
		const Vector<T>* m_pVector;
		int m_nIndex = -1;
	};

public:
	Vector() = default;
	explicit Vector(int nSize);

	~Vector();

	void insert(const T& value);

	int size() const;
	const T& operator[](int nIndex) const;

	Iterator begin() const;
	Iterator end() const;

private:
	T* m_pData = nullptr;
	int m_nSize = 0;
	int m_nCapacity = 0;
};

