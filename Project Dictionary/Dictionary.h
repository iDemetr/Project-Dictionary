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
/// Пользовательский класс, реализующий структуру данных "Словарь"
/// </summary>
template<class TKey, class TValue>
class Dictionary {

public:

	Dictionary();
	~Dictionary();
	
	/// <summary>
	/// Конструктор копирования
	/// </summary>
	/// <param name=""></param>
	Dictionary(Dictionary &);

	NodeDictionary<TKey,TValue> *Head, *Tail;

	/// <summary>
	/// Счётчик ключей.
	/// </summary>
	int Count;

	/// <summary>
	/// Функция создаёт узел с Ключом TKey и Значением TValue и добавляет его в словарь.
	/// </summary>
	/// <param name="TKey">Ключ</param>
	/// <param name="TValue">Значение</param>
	void Add(TKey *, TValue*);

	/// <summary>
	/// Функция добавления в словарь созданного узла.
	/// </summary>
	/// <param name="node">Указатель на добавляемый узел</param>
	void Append(NodeDictionary<TKey, TValue> *);

	/// <summary>
	/// Функция проверки наличия узла с заданным ключём.
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	bool Contains(TKey *);

	/// <summary>
	/// Возвращает указатель на узел словаря
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	NodeDictionary<TKey, TValue>* Get (TKey *);

	/// <summary>
	/// Функция удаления по ключу.
	/// </summary>
	/// <param name="key">Ключ удаляемого узла.</param>
	void Delete(TKey *);

	/// <summary>
	/// Функия удаления по указателю на объект.
	/// </summary>
	/// <param name="node">Удаляемый узел.</param>
	void Delete(NodeDictionary<TKey, TValue> *);

	/// <summary>
	/// Функия очистки словаря от всех созданных узлов.
	/// </summary>
	void Clear();
};

/// <summary>
/// Класс узла для словаря.
/// </summary>
/// <typeparam name="TKey"></typeparam>
/// <typeparam name="TValue"></typeparam>
template<class TKey, class TValue>
class NodeDictionary {

public:

	/// <summary>
	/// Ключ узла.
	/// </summary>
	TKey *Key;

	/// <summary>
	/// Значение узла.
	/// </summary>
	TValue *Value;

	NodeDictionary<TKey, TValue> *Next, *Previous;

	/// <summary>
	/// Конструктор, обнуляющуй узкатели на следующий и предыдущий 
	/// </summary>
	NodeDictionary();

	/// <summary>
	/// 
	/// </summary>
	~NodeDictionary();

	/// <summary>
	/// Создание узла с заданным TKey и TValue
	/// </summary>
	/// <typeparam name="Key"></typeparam>
	/// <typeparam name="value"></typeparam>
	NodeDictionary(TKey*, TValue*);

	/// <summary>
	/// Конструктор копирования
	/// </summary>
	/// <param name=""></param>
	NodeDictionary(NodeDictionary &);

	/// <summary>
	/// Добавление значений в узел
	/// </summary>
	/// <param name=""></param>
	template<class T>
	void AddValue(List<T> *);

	/// <summary>
	/// Удаление значения из узла
	/// </summary>
	/// <param name=""></param>
	template<class T>
	void DelValue(T *);
};


template<class TKey, class TValue>
template<class T>
void NodeDictionary<TKey, TValue>::AddValue(List<T> *value) {
	try { this->Value->Add(value); }												// Ошибка, если Value не список.
	catch( exception e) { throw string(e.what()); }
}

template<class TKey, class TValue>
template<class T>
void NodeDictionary<TKey, TValue>::DelValue(T *value) {
	try { this->Value->Delete(value); }												// Ошибка, если Value не список.
	catch(string mess) { throw mess; }
	catch( exception e) { throw string(e.what()); }
}

#endif