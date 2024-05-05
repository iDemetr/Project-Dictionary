#pragma once

#ifndef CELLS_H
#define CELLS_H

#ifdef DICTIONARY_EXPORTS
#define CELLS_API __declspec(dllexport)
#else
#define CELLS_API __declspec(dllimport)
#endif

#include "pch.h"

using namespace std;

namespace SCells {

	/// <summary>
	/// Пользовательский класс, определяющий тип Ячейки.
	/// </summary>
	class CELLS_API Cells {

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
		friend ostream &operator<< (ostream &, Cells &);

		
		/// <summary>
		/// Оператор ввода.
		/// </summary>
		friend istream &operator>> (istream &, Cells &);


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

		//Не работает
		//friend string operator+ (string&, Cells&);
	};
}
#endif