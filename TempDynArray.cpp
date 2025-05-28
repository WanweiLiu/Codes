/**
 * TempDynArray.cpp
 *
 *  Created on: May 14, 2016
 *  Author: Wanwei Liu
 */


#include "TempDynArray.h"
#include <iostream>
#include <cstdlib>
using namespace std;

template <typename T>
DynArray<T>::DynArray()
{
	this->m_head = NULL;
	this->m_tail = NULL;
}

template <typename T>
DynArray<T>::~DynArray() {
	if(m_head) this->clear();
}


template <typename T>
typename DynArray<T>::ArrayEle*
DynArray<T>::position(int pos) const
{
        ArrayEle* p_cur = m_head;
	while(pos && p_cur)
	{
		p_cur = p_cur->next;
		pos--;
	}
	return p_cur;
}

template <typename T>
int DynArray<T>::count() const
{
	if(!m_head || !m_tail)
		return 0;
	ArrayEle * p_tmp = m_head;
	int m = 1;
	while(p_tmp != m_tail)
	{
		p_tmp = p_tmp->next;
		m++;
	}
	return m;
}

template <typename T>
void DynArray<T>::add(const T & v)
{
    ArrayEle * p_new = new ArrayEle;
	p_new ->val= v;
	p_new ->next = NULL;
	if(!m_head || !m_tail)
		m_head = m_tail = p_new;
	else
	{
		m_tail->next = p_new;
		m_tail = p_new;
	}
}

template <typename T>
void DynArray<T>::remove(int pos)
{
    int ct = count();
	if(pos<0 || pos>=ct)
		return;
	if(!pos)
	{
	  ArrayEle * p_del = m_head;
	  m_head = m_head->next;
	  delete p_del;
	  if(ct == 1)
	    m_tail = NULL;
	}
	else
	{
	  ArrayEle* p_tmp = this->position(pos-1);
	  ArrayEle* p_del = p_tmp->next;
	  p_tmp->next = p_del ->next;
	  delete p_del;
	  if (pos == ct-1)
	    m_tail = p_tmp;
	}
}

template <typename T>
void DynArray<T>::insert(int pos, const T & val)
{
	int ct = count();
	if(pos<0 || pos>ct)
		return;
	ArrayEle * p_new = new ArrayEle;
	p_new->val = val;
	p_new->next = NULL;
	if(!pos)
	{
		if(!m_head || !m_tail)
			m_head = m_tail = p_new;
		else
		{
			p_new->next = m_head;
			m_head = p_new;
		}
	}
	else
	{
	        ArrayEle * p_ins = this->position(pos-1);
		p_new->next = p_ins->next;
		p_ins->next = p_new;
	}
	if(pos == ct)
		m_tail = p_new;
}

template <typename T>
void DynArray<T>::clear()
{
        ArrayEle* p_cur = m_head;
	while(p_cur)
	{
	        ArrayEle* p_rmv = p_cur;
		p_cur = p_cur->next;
		delete p_rmv;
	}
	m_head = m_tail = NULL;
}


template <typename T>
T & DynArray<T>::operator[](int pos)
{
    ArrayEle* p_dis = this->position(pos);
	if(!p_dis) throw 0;
         return p_dis->val;	
}

template <typename T>
T  DynArray<T>::operator[](int pos) const
{
    ArrayEle* p_dis = this->position(pos);
	if(!p_dis) throw 0;
         return p_dis->val;	
}


template <typename T>
ostream & operator<<(ostream & os, const DynArray<T> & arr)
{
  os<<"[";
  for (int i = 0, ct = arr.count(); i < ct; i++)
    {
      os << i <<":" <<arr[i];
      if(i < ct-1) os << "; ";
    }
  os<<"]";
  return os;
}


