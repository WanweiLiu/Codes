/**
 * TempDynArray.h
 *
 *  Created on: May 14, 2016
 *  Author: Wanwei Liu
 */

#ifndef TEMPLATE_DYNARRAY_H_
#define TEMPLATE_DYNARRAY_H_

#include<iostream>
using namespace std;

template <typename T>
class DynArray {

public:
	DynArray();
	virtual ~DynArray();

protected:
	struct ArrayEle
	{
	  T val;
	  ArrayEle * next;
	};

private:
	ArrayEle* m_head;
	ArrayEle* m_tail;
	ArrayEle* position(int) const;

public:
	int count() const;
	void add(const T &);
	void insert(int, const T &);
	void remove(int);
	void clear();
	T& operator[](int);
    T  operator[](int) const;
};

#endif /* TEMPLATE_DYNARRAY_H_ */
