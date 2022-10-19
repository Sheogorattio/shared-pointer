#pragma once

template<class T>
struct ptrContainer {
	T* ptr= nullptr;
	int counter=0;
};

template<class T>
class sharedPtr
{
public:
	sharedPtr();
	~sharedPtr();
	sharedPtr(const sharedPtr& obj);
	sharedPtr(T* obj);
	T* get();//возврат ссылки
	int getCount();// возврат кол-ва
	sharedPtr<T>* operator=(sharedPtr<T>& obj);
private:
	ptrContainer<T>* ptr;
};

template<class T>
inline sharedPtr<T>::sharedPtr()
{
	ptr = new ptrContainer<T>;
}

template<class T>
inline sharedPtr<T>::~sharedPtr()
{
	if (ptr->counter > 1) {
		ptr->counter--;
	}
	else {
		delete[] ptr->ptr;
		ptr->counter--;
		ptr = nullptr;
	}
}

template<class T>
inline sharedPtr<T>::sharedPtr(const sharedPtr& obj)
{
	ptr = obj.ptr;
	ptr->counter++;
}

template<class T>
inline sharedPtr<T>::sharedPtr(T* obj)
{
	ptr = new ptrContainer<T>;
	ptr->ptr = obj;
	ptr->counter++;
}

template<class T>
inline T* sharedPtr<T>::get()
{
	return ptr->ptr;
}

template<class T>
inline int sharedPtr<T>::getCount()
{
	return ptr->counter;
}

template<class T>
inline sharedPtr<T>* sharedPtr<T>::operator=(sharedPtr<T>& obj)
{
	ptr->ptr = obj.ptr->ptr;
	ptr->counter = ++obj.ptr->counter;
	return this;
}

