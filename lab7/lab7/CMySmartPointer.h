#pragma once
#include "CRefCounter.h"

template <typename T> class CMySmartPointer
{
public:
	CMySmartPointer() { pc_pointer = 0; }
	CMySmartPointer(T *pcPointer);
	CMySmartPointer(const CMySmartPointer<T> &pcOther);
	~CMySmartPointer();
	T& operator*() { return(*pc_pointer); }
	T* operator->() { return(pc_pointer); }
	CMySmartPointer<T>& operator=(T * pcPointer);
private:
	CRefCounter *pc_counter;
	T *pc_pointer;
};






template <typename T>
CMySmartPointer<T>::CMySmartPointer(const CMySmartPointer<T> &pcOther)
{
	pc_pointer = pcOther.pc_pointer;
	pc_counter = pcOther.pc_counter;
	pc_counter->iAdd();
}

template <typename T>
CMySmartPointer<T>::CMySmartPointer(T *pcPointer)
{
	pc_pointer = pcPointer;
	pc_counter = new CRefCounter();
	pc_counter->iAdd();
}

template <typename T>
CMySmartPointer<T>::~CMySmartPointer()
{
	if (pc_counter->iDec())
	{
		delete pc_pointer;
		delete pc_counter;
	}
}

template <typename T>
CMySmartPointer<T>& CMySmartPointer<T>::operator=(T * pcPointer)
{
	if (pc_counter->iGet() >= 1)
	{
		delete pc_pointer;
		pc_counter->iDec();
	}
	pc_pointer = pcPointer;
	pc_counter->iAdd();
	return *this;
}
