#include "pch.h"
#include "Cells.h"

namespace SCells {

	Cells::Cells() { Row = 0, Column = ""; }

	Cells::Cells(string cells) {

		Row = 0; Column = "";

		for(char var : cells) {

			if(var == Separator)
				isSeparator = true;

			if(var >= 'A' && var <= 'Z' || var >= 'a' && var <= 'z') {

				//Если уже был встречен разделитель ":" или после считывания цифр встречана буква.
				if(isSeparator) {

					throw string("\n Ошибка парсинга ячейки, она должна быть типа [\"A4\"], [\"A:4\"]");
				}
				Column += var;

			} else if(var >= '0' && var <= '9') {

				if(Column == "") {

					throw string("\n Ошибка парсинга ячейки, она должна быть типа [\"A4\"], [\"A:4\"]");
				}

				isSeparator = true;

				Row = Row * 10 + var - 48;
			}
		}

		if(isSeparator == false || Column == "")
			throw string("\n Ошибка парсинга ячейки, она должна быть типа [\"A4\"], [\"A:4\"]");
	}

	Cells::Cells(string column, int row) {

		Row = row;

		for(char var : column) {

			if(var >= 'A' && var <= 'Z' || var >= 'a' && var <= 'z') {
				Column += var;
			} else {
				//Если был встречен любой симбол кроме букв.
				throw string("\n\n Ошибка парсинга ячейки, она должна быть типа [\"A\",4], или [\"AA\",4]");
			}
		}
	}

	Cells::Cells(int column, int row) {

		int Letter;

		Row = row;
		Column = "";

		do {
			Letter = column % 26;

			Column += (char)Letter + 65;

			column /= 26;
			column--;

		} while(column != -1);

		std::reverse(Column.begin(), Column.end());
	}

	Cells::~Cells() {}

	string Cells::get() {
		return Column + to_string(Row);
	}


	// оператор присвоения
	Cells& Cells::operator= (const Cells &cells) {

		Row = cells.Row;
		Column = cells.Column;

		return *this;   // возвращаем ссылку на текущий объект
	}


	/// <summary>
	/// Оператор вывода
	/// </summary>
	/// <param name="stream"></param>
	/// <param name="cells"></param>
	/// <returns></returns>
	ostream &operator<< (ostream &stream, Cells &cells) {

		stream << cells.get();

		return stream;
	}

	/// <summary>
	/// Оператор ввода
	/// </summary>
	/// <param name="stream"></param>
	/// <param name="cells"></param>
	/// <returns></returns>
	istream &operator>> (istream &stream, Cells &cells) {

		string str;
		stream >> str;

		try {
			cells = Cells(str);

		} catch(const std::string &ex) {
			throw ex;
		}

		return stream;
	}

	//Не работает
	//string operator+(const string &str, Cells &Cells) {
	//	return str + Cells.get();
	//}

	bool operator== (const Cells &cells1, const Cells &cells2) {
		return cells1.Row == cells2.Row && cells1.Column == cells2.Column;
	}

	bool operator!= (const Cells &cells1, const Cells &cells2) {
		return cells1.Row != cells2.Row && cells1.Column != cells2.Column;
	}

}
