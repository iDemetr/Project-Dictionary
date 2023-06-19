#include "Dictionary.h"

//Предворительное инстанцирование шаблонов словаря
template Dictionary<Cells, List<string>>;
template Dictionary<Cells, List<int>>;
template Dictionary<Cells, List<double>>;
template Dictionary<Cells, List<float>>;

//Предворительное инстанцирование шаблонов списка
template List<string>;
template List<int>;
template List<double>;
template List<float>;


template<class TKey, class TValue>
Dictionary<TKey, TValue>::Dictionary() {
	Head = Tail = nullptr;

	Count = 0;
}

template<class TKey, class TValue>
Dictionary<TKey, TValue>::Dictionary(Dictionary &dictoinary) {
	Count = dictoinary.Count;

	//Возможно избыточная проверка на наличие указателей.
	if(dictoinary.Head) Head = new NodeDictionary<TKey, TValue>(*dictoinary.Head);
	else Head = nullptr;

	//Поиск нового адреса хвоста.
	Tail = [](NodeDictionary<TKey, TValue> *node) { while(node->Next) node = node->Next; return node; } (Head);
}

template<class TKey, class TValue>
Dictionary<TKey, TValue>::~Dictionary() {
	Clear();
}

template<class TKey, class TValue>
void Dictionary<TKey, TValue>::Add(TKey *key, TValue *value) {

	//Проверка на дублирование ключей.
	if(Contains(key)) {
		throw string("\n A node with such a key is already in the dictionary!!"); return;
	}

	NodeDictionary<TKey, TValue> *node = new NodeDictionary<TKey, TValue>(key, value);

	this->Count++;

	Append(node);
}

template<class TKey, class TValue>
void Dictionary<TKey, TValue>::Append(NodeDictionary<TKey, TValue> *node) {

	if(this->Head == nullptr) {
		this->Head = this->Tail = node;
	} else {
		this->Tail->Next = node;
		node->Previous = Tail;
		Tail = node;
	}
}

template<class TKey, class TValue>
bool Dictionary<TKey, TValue>::Contains(TKey *key) {

	NodeDictionary<TKey, TValue> *node = Head;

	while(node) { if(*node->Key == *key) { return true; } else node = node->Next; }

	return false;
}

template<class TKey, class TValue>
NodeDictionary<TKey, TValue>* Dictionary<TKey, TValue>::Get(TKey *key) {
	
	NodeDictionary<TKey, TValue> *node = Head;

	while(node) { if(*node->Key == *key) { return node; } else node = node->Next; }
	
	return nullptr;
}

template<class TKey, class TValue>
void Dictionary<TKey, TValue>::Delete(TKey *key) {

	NodeDictionary<TKey, TValue> *node = this->Head;

	//Поиск узла с заданным ключом
	while(node && *node->Key != *key) 
		node = node->Next; 

	//Если узел с заданным ключом найден
	if(*node->Key == *key) {
		Delete(node); 
		return;
	}
	
	throw string("\n Ошибка удаления, узла по такому ключу не найдено.");	
}

template<class TKey, class TValue>
void Dictionary<TKey, TValue>::Delete(NodeDictionary<TKey, TValue> *node) {

	//Если удаляемый элемент - голова.
	if(node == Head) { Head = Head->Next; }
	
	//Если удаляемый элемент - хвост.
	else if(node == Tail) { Tail = Tail->Previous; }

	//Элемент из середины списка.
	else {
		node->Previous->Next = node->Next;
		node->Next->Previous = node->Previous;
	}

	delete node;
}

template<class TKey, class TValue>
void Dictionary<TKey, TValue>::Clear() {
	NodeDictionary<TKey, TValue> *node;

	while(Head) {
		node = Head->Next;
		delete Head;

		Head = node;
	}
}

//============================================================================================================================||

template<class TKey, class TValue>
NodeDictionary<TKey, TValue>::NodeDictionary() {
	Next = Previous = Key = Value = nullptr;
}

template<class TKey, class TValue>
NodeDictionary<TKey, TValue>::NodeDictionary(TKey *key, TValue *value) {
	
	if(key) Key = new TKey(*key);
	else Key = nullptr;

	if(value) Value = new TValue(*value);
	else Value = nullptr;

	Next = Previous = nullptr;
}

template<class TKey, class TValue>
NodeDictionary<TKey, TValue>::NodeDictionary(NodeDictionary &node) {

	if(node.Next) this->Next = new NodeDictionary<TKey, TValue>(*node.Next);
	else this->Next = nullptr;

	if(node.Previous) this->Previous = new NodeDictionary<TKey, TValue>(*node.Previous);
	else this->Previous = nullptr;


	if(node.Key) this->Key = new TKey(*node.Key);
	else this->Key = nullptr;

	if(node.Value) this->Value = new TValue(*node.Value);
	else this->Value = nullptr;
}

template<class TKey, class TValue>
NodeDictionary<TKey, TValue>::~NodeDictionary() {
	Next = nullptr; Previous = nullptr;	

	delete Key; delete Value;
}
