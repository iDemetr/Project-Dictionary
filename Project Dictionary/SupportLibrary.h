#pragma once

//#include "List.h"
#include "Dictionary.h"
//#include "Cells.h"

#include "Header.h"

using namespace SCells;
using namespace std;

//Предворительное инстанцирование шаблонов списка
template List<string>;
template List<int>;
template List<double>;
template List<float>;

//Предворительное инстанцирование шаблонов словаря
template Dictionary<Cells, List<string>>;
template Dictionary<Cells, List<int>>;
template Dictionary<Cells, List<double>>;
template Dictionary<Cells, List<float>>;


/// <summary>
/// 
/// </summary>
/// <typeparam name="TKey"></typeparam>
/// <typeparam name="TValue"></typeparam>
/// <param name="PathFile"></param>
/// <returns></returns>
template<class TKey, class TValue>
Dictionary<TKey, TValue>* FReadData(const string PathFile) {

	ifstream f(PathFile, ios_base::in);

	if(!f.is_open()) return nullptr;

	string str(""), tmpValue("");

	int space(0);

	TKey key;
	TValue *value = new TValue();

	//Проверка на соответствие типов
	List<std::string> *Lvalue = (List<std::string>*)value;											//Список строк.
	Dictionary<TKey, TValue> *dictionary = new Dictionary<TKey, TValue>();							//Словарь считанных данных из файла.

	while(!f.eof()) {

		getline(f, str);																			//Считывание строки из файла.

		if(str == "") continue;

		//Получение ключа, путём нахождения первого слова по пробелу из строки.
		space = str.find(' ');
		key = str.substr(0, space);
		str = str.substr(space+1, str.length());

		if(key.get() == "") continue;

		//Цикл по оставшейся строке с разделеним по слову(пробелу).
		while(space = str.find(' '), space != std::string::npos) {
						
			tmpValue = str.substr(0, space);
			str = str.substr(space+1, str.length());			

			Lvalue->Add(&tmpValue);
		}

		//Обработка исключений при дублировании.
		try {
			dictionary->Add(&key, Lvalue);
		} catch(string s) {};

		Lvalue->Clear();
	}

	return dictionary;
}





 /// <summary>
 /// Функция обработки данных, находящихся в словаре.
 /// </summary>
 /// <typeparam name="TKey"></typeparam>
 /// <typeparam name="TValue"></typeparam>
 /// <param name="dictionary"></param>
 /// <param name="Func">Функтор, определяющий метод вывода данных</param>
template<class TKey, class TValue>
void ProcessData(Dictionary<TKey, TValue> *dictionary, void Func(TKey key, TValue *value)) {

	NodeDictionary<TKey, TValue> *node = dictionary->Head;
	while(node) {
		Func(*node->Key, node->Value);

		node = node->Next;
	}
}



/// <summary>
/// Вывод ключа и списка значений в файл
/// Не оптимально
/// </summary>
/// <typeparam name="TKey"></typeparam>
/// <typeparam name="TValue"></typeparam>
/// <param name="key"></param>
/// <param name="value"></param>
template<class TKey, class TValue>
void print2File(TKey key, TValue *value) {
	ofstream out("Dictionary.txt", ios_base::app);
	
	if(out.is_open()) {

		out << "\n" << key << " ";

		auto *node = value->Head;

		while(node) {
			out << *node->Оbj << " ";

			node = node->Next;
		}
	}
	out.close();
};


/// <summary>
/// Вывод ключа и списка значений в консоль
/// </summary>
/// <typeparam name="TKey"></typeparam>
/// <typeparam name="TValue"></typeparam>
/// <param name="key"></param>
/// <param name="value"></param>
template<class TKey, class TValue>
void print2CMD(TKey key, TValue *value) {

	try {
		cout << "\n\n " << key << " : ";

		//Проверка, является ли TValue типом List
		//List<std::string> *s = dynamic_cast< List<std::string>* >(value);
		//List<std::string> *s = (List<std::string>)value;
		//List<std::string> *s = static_cast<List<std::string>*>(value);

		if(true) {

			auto *node = value->Head;

			while(node) {
				cout << *node->Оbj << " ";

				node = node->Next;
			}
		}

		//Проверка, является ли value типом List
		//if(std::is_same(decltype(value), template<class T> class List)) {
		//
		//}
	} catch(exception e) {

	}
};
