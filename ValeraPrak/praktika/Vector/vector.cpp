#include "pch.h"
#include "vector.h"



template <typename T>
Vector<T>::Vector(int nCapacity)
{
	m_nCapacity = nCapacity;
	m_pData = new T[m_nCapacity];
}

template <typename T>
Vector<T>::~Vector()
{
	delete m_pData;
	m_nSize = 0;
	m_nCapacity = 0;
}

template <typename T>
void Vector<T>::insert(const T& value)
{
	if (m_nSize == m_nCapacity)
	{
		if (m_nCapacity == 0)
			m_nCapacity = 1;

		m_nCapacity *= 2;


		auto pNewMemory = new T[m_nCapacity];


		for (auto idx = 0; idx < m_nSize; ++idx)
			pNewMemory[idx] = m_pData[idx];

		delete m_pData;
		m_pData = pNewMemory;
	}

	m_pData[m_nSize] = value;
	++m_nSize;
}

template <typename T>
int Vector<T>::size() const
{
	return m_nSize;
}

template <typename T>
const T& Vector<T>::operator[](int nIndex) const
{
	if (nIndex >= m_nSize)
		throw std::exception("Index out of range");

	return m_pData[nIndex];
}

template <typename T>
typename Vector<T>::Iterator Vector<T>::begin() const
{
	return Vector<T>::Iterator{ this, 0 };
}

template <typename T>
typename Vector<T>::Iterator Vector<T>::end() const
{
	return Vector<T>::Iterator{ this, m_nSize };
}

template <typename T>
Vector<T>::Iterator::Iterator(const Vector<T>* pVector, int nIndex)
	: m_pVector(pVector)
	, m_nIndex(nIndex)
{
}

template <typename T>
const T& Vector<T>::Iterator::operator*() const
{
	return m_pVector->operator[](m_nIndex);
}

template <typename T>
typename Vector<T>::Iterator& Vector<T>::Iterator::operator++()
{
	++m_nIndex;
	return *this;
}

template <typename T>
bool Vector<T>::Iterator::operator!=(const Vector<T>::Iterator& other) const
{
	return m_nIndex != other.m_nIndex;
}
