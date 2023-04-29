#pragma once

#ifndef CELLS_H
#define CELLS_H

#include "Header.h"

using namespace std;

namespace SCells {

	//Пользовательский класс, определяющий тип Ячейки.
	class Cells {

	private:
		string Column;
		int Row;
		const char Separator = ':';
		bool isSeparator = false;

	public:

		Cells();

		/// <summary>
		/// Инициализация по типу "A4" или "D:2" или "1:1"
		/// </summary>
		/// <param name="cells"></param>
		Cells(string cells);

		/// <summary>
		/// Инициализация по типу ("D",2)
		/// </summary>
		/// <param name="">column</param>
		/// <param name="">row</param>
		Cells(string column, int row);

		/// <summary>
		/// Инициализация по типу (1,1)
		/// </summary>
		/// <param name="column"></param>
		/// <param name="row"></param>
		Cells(int column, int row);


		~Cells();

		/// <summary>
		/// Возвращает ячейку в виде строки.
		/// </summary>
		string get();


		/// <summary>
		/// Оператор вывода.
		/// </summary>
		/// <param name="in"></param>
		/// <param name="str"></param>
		/// <returns></returns>
		friend std::ostream &operator<< (std::ostream &, Cells &);

		
		/// <summary>
		/// Оператор ввода.
		/// </summary>
		friend std::istream &operator>> (std::istream &, Cells &);


		/// <summary>
		/// Оператор присвоения.
		/// </summary>
		Cells &operator= (const Cells &cells);

		/// <summary>
		/// Оператор сравнения
		/// </summary>
		friend bool operator== (const Cells &cells1, const Cells &cells2);

		/// <summary>
		/// Оператор сравнения
		/// </summary>
		friend bool operator!= (const Cells &cells1, const Cells &cells2);


		friend string operator+ (string&, Cells&);
	};

	//bool operator== (Cells &cells1, const string &str) {
	//
	//	return cells1.get() == str;
	//}

	//Не работает.
	//string Cells::operator+() {
	//	return this->get();
	//}
}


#endif