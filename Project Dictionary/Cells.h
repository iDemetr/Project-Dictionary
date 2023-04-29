#pragma once

#ifndef CELLS_H
#define CELLS_H

#include "Header.h"

using namespace std;

namespace SCells {

	//���������������� �����, ������������ ��� ������.
	class Cells {

	private:
		string Column;
		int Row;
		const char Separator = ':';
		bool isSeparator = false;

	public:

		Cells();

		/// <summary>
		/// ������������� �� ���� "A4" ��� "D:2" ��� "1:1"
		/// </summary>
		/// <param name="cells"></param>
		Cells(string cells);

		/// <summary>
		/// ������������� �� ���� ("D",2)
		/// </summary>
		/// <param name="">column</param>
		/// <param name="">row</param>
		Cells(string column, int row);

		/// <summary>
		/// ������������� �� ���� (1,1)
		/// </summary>
		/// <param name="column"></param>
		/// <param name="row"></param>
		Cells(int column, int row);


		~Cells();

		/// <summary>
		/// ���������� ������ � ���� ������.
		/// </summary>
		string get();


		/// <summary>
		/// �������� ������.
		/// </summary>
		/// <param name="in"></param>
		/// <param name="str"></param>
		/// <returns></returns>
		friend std::ostream &operator<< (std::ostream &, Cells &);

		
		/// <summary>
		/// �������� �����.
		/// </summary>
		friend std::istream &operator>> (std::istream &, Cells &);


		/// <summary>
		/// �������� ����������.
		/// </summary>
		Cells &operator= (const Cells &cells);

		/// <summary>
		/// �������� ���������
		/// </summary>
		friend bool operator== (const Cells &cells1, const Cells &cells2);

		/// <summary>
		/// �������� ���������
		/// </summary>
		friend bool operator!= (const Cells &cells1, const Cells &cells2);


		friend string operator+ (string&, Cells&);
	};

	//bool operator== (Cells &cells1, const string &str) {
	//
	//	return cells1.get() == str;
	//}

	//�� ��������.
	//string Cells::operator+() {
	//	return this->get();
	//}
}


#endif