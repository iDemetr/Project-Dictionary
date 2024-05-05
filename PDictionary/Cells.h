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
	/// ���������������� �����, ������������ ��� ������.
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
		friend ostream &operator<< (ostream &, Cells &);

		
		/// <summary>
		/// �������� �����.
		/// </summary>
		friend istream &operator>> (istream &, Cells &);


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

		//�� ��������
		//friend string operator+ (string&, Cells&);
	};
}
#endif