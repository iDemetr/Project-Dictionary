#pragma once

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include "List.h"
#include "Cells.h"

using namespace MyList;
using namespace SCells;
using namespace std;

template<class TKey, class TValue>
class NodeDictionary;

/// <summary>
/// ���������������� �����, ����������� ��������� ������ "�������"
/// </summary>
template<class TKey, class TValue>
class Dictionary {

public:

	Dictionary();
	~Dictionary();
	
	/// <summary>
	/// ����������� �����������
	/// </summary>
	/// <param name=""></param>
	Dictionary(Dictionary &);

	NodeDictionary<TKey,TValue> *Head, *Tail;

	/// <summary>
	/// ������� ������.
	/// </summary>
	int Count;

	/// <summary>
	/// ������� ������ ���� � ������ TKey � ��������� TValue � ��������� ��� � �������.
	/// </summary>
	/// <param name="TKey">����</param>
	/// <param name="TValue">��������</param>
	void Add(TKey *, TValue*);

	/// <summary>
	/// ������� ���������� � ������� ���������� ����.
	/// </summary>
	/// <param name="node">��������� �� ����������� ����</param>
	void Append(NodeDictionary<TKey, TValue> *);

	/// <summary>
	/// ������� �������� ������� ���� � �������� ������.
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	bool Contains(TKey *);

	/// <summary>
	/// ���������� ��������� �� ���� �������
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	NodeDictionary<TKey, TValue>* Get (TKey *);

	/// <summary>
	/// ������� �������� �� �����.
	/// </summary>
	/// <param name="key">���� ���������� ����.</param>
	void Delete(TKey *);

	/// <summary>
	/// ������ �������� �� ��������� �� ������.
	/// </summary>
	/// <param name="node">��������� ����.</param>
	void Delete(NodeDictionary<TKey, TValue> *);

	/// <summary>
	/// ������ ������� ������� �� ���� ��������� �����.
	/// </summary>
	void Clear();
};

/// <summary>
/// ����� ���� ��� �������.
/// </summary>
/// <typeparam name="TKey"></typeparam>
/// <typeparam name="TValue"></typeparam>
template<class TKey, class TValue>
class NodeDictionary {

public:

	/// <summary>
	/// ���� ����.
	/// </summary>
	TKey *Key;

	/// <summary>
	/// �������� ����.
	/// </summary>
	TValue *Value;

	NodeDictionary<TKey, TValue> *Next, *Previous;

	/// <summary>
	/// �����������, ���������� �������� �� ��������� � ���������� 
	/// </summary>
	NodeDictionary();

	/// <summary>
	/// 
	/// </summary>
	~NodeDictionary();

	/// <summary>
	/// �������� ���� � �������� TKey � TValue
	/// </summary>
	/// <typeparam name="Key"></typeparam>
	/// <typeparam name="value"></typeparam>
	NodeDictionary(TKey*, TValue*);

	/// <summary>
	/// ����������� �����������
	/// </summary>
	/// <param name=""></param>
	NodeDictionary(NodeDictionary &);

	/// <summary>
	/// ���������� �������� � ����
	/// </summary>
	/// <param name=""></param>
	template<class T>
	void AddValue(List<T> *);

	/// <summary>
	/// �������� �������� �� ����
	/// </summary>
	/// <param name=""></param>
	template<class T>
	void DelValue(T *);
};


template<class TKey, class TValue>
template<class T>
void NodeDictionary<TKey, TValue>::AddValue(List<T> *value) {
	try { this->Value->Add(value); }												// ������, ���� Value �� ������.
	catch( exception e) { throw string(e.what()); }
}

template<class TKey, class TValue>
template<class T>
void NodeDictionary<TKey, TValue>::DelValue(T *value) {
	try { this->Value->Delete(value); }												// ������, ���� Value �� ������.
	catch(string mess) { throw mess; }
	catch( exception e) { throw string(e.what()); }
}

#endif