#include <windows.h>

//#include "List.h"
//#include "Dictionary.h" 
#include "SupportLibrary.h"

//#include "Cells.h"

using namespace std;
using namespace MyList;
using namespace SCells;

const string PathFile = "Dictionary.txt";

enum menu { addNew = '1', addValue, print2cmd, print2file, deleteMenu, quit = 27 };


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	bool isMenu = true, isDelMenu = true;

	cout << "\n\t Добро пожаловать в программу реализации пользовательноской структуры данных \"Словарь\"\n";
	cout << "------------------------------------------------------------------------------------------------------";
	cout << "\n\n Для начала работы, нажмите любую клавишу...";

	_getch(); system("cls");

	int s(0), a;
	Cells key;
	string value;

	auto CinKey{[&](string massage)
	{
		do {
			try {
				cout << massage; cin >> key;
				cin.get();

				break;																//Если нет исключения, при создании ключа, программа продолжит выполнение

			} catch(const std::string &ex) {
				cout << ex;
			}
		} while(true);
	}};

	auto *LValue = new List<string>();

	Dictionary<Cells, List<string>> *dictionary = FReadData < Cells, List<string> >(PathFile);

	if(dictionary != nullptr && dictionary->Count != 0)
		cout << " Данные успешно восстановлены из " + PathFile + "\n\n";

	else if(dictionary == nullptr)
		dictionary = new Dictionary<Cells, List<string>>();

	//Цикл главного меню.
	do {
		cout << "=====================================\n";
		cout << " (1) Добавить новый узел\n";
		cout << " (2) Добавить данные в узел\n";
		cout << "-------------------------------------\n";
		cout << " (3) Вывести имеющиеся данные в консоль\n";
		cout << " (4) Сохранить данные в файл\n";
		cout << "-------------------------------------\n";
		cout << " (5) Удалить данные\n";
		cout << "-------------------------------------\n";
		cout << " (esc) Завершение программы\n";

		while(s = _getch(), s < addNew &&s > deleteMenu &&s != quit);

		switch(s) {

		//Добавление нового узла.
		case addNew:
		{
			system("cls");

			CinKey("\n Введите ключ: ");

			cout << "\n Введите список значений: ";
			while(cin >> value, a = cin.get(), a != '\n')
				LValue->Add(&value);

			LValue->Add(&value);

			//Добавление в словарь нового узла
			try { dictionary->Add(&key, LValue); } catch(string str) {
				cout << str << endl;
				cout << "\n Чтобы продолжить, нажмите любую клавишу.\n"; _getch();

				LValue->Clear(); continue;
			}

			cout << "\n\n Узел " + key.get() + " успешно добавлен в словарь.";
			cout << "\n Чтобы продолжить, нажмите любую клавишу.\n"; _getch();

			LValue->Clear();

			break;
		}

		//Добавление в узел.
		case addValue:
		{
			system("cls");

			cout << "\n Вывод текущей структуры словаря: ";
			ProcessData(dictionary, print2CMD);

			CinKey("\n\n Введите ключ, по которому добавить данные: ");

			if(dictionary->Contains(&key)) {													//Проверка на наличие узла с таким ключём.

				cout << "\n Введите список значений: ";
				while(cin >> value, a = cin.get(), a != '\n')
					LValue->Add(&value);

				LValue->Add(&value);

				// Добавление значений в словарь по ключу.
				try { dictionary->Get(&key)->AddValue(LValue); } catch(string str) {

					cout << str << "\n\n Чтобы продолжить, нажмите любую клавишу.\n"; _getch();

					LValue->Clear();
					system("cls"); continue;
				}

				cout << "\n\n Значние " + value + " успешно добавлен в словарь по ключу " + key.get();
				cout << "\n Чтобы продолжить, нажмите любую клавишу.\n"; _getch();

				LValue->Clear();
			} else {
				cout << "\n Узла с заданным ключём не обнаружено!";
				cout << "\n Чтобы продолжить, нажмите любую клавишу.\n"; _getch();
			}

			break;
		}

		//Вывод в консоль.
		case print2cmd:
		{

			cout << "\n Вывод текущей структуры словаря: ";

			ProcessData(dictionary, print2CMD);

			cout << "\n\n Чтобы продолжить, нажмите любую клавишу.";
			_getch();

			break;
		}

		//Вывод в файл.
		case print2file:
		{
			cout << "\n\n Вы уверены, что хотите перезаписать файл Dictionary.txt? (y/n) ";
			while(s = _getch(), s != 'y' && s != 'n' && s != 237 && s != 242);

			if(s == 'n' || s == 242) {
				system("cls"); continue;
			}

			ofstream f(PathFile, ios_base::trunc); f.close();														//Очистка файла от предыддущих данных

			ProcessData(dictionary, print2File);

			cout << "\n\n Файл успешно сохранён." << endl;
			cout << "\n Чтобы продолжить, нажмите любую клавишу.";
			_getch();

			break;
		}

		//Удаление
		case deleteMenu:
		{
			do {

				system("cls");

				cout << "\n Вывод текущей структуры словаря: ";
				ProcessData(dictionary, print2CMD);

				cout << "\n=====================================\n";
				cout << "\n (1) Удалить по ключу";
				cout << "\n (2) Удалить значение";
				cout << "\n (esc) Возврат в главное меню";

				while(s = _getch(), s != '1' && s != '2' && s != 27);

				Cells key;

				switch(s) {

				//Удаление по узла ключу.
				case '1':
				{
					CinKey("\n\n Введите ключ удаляемого узла: ");

					if(dictionary->Contains(&key)) {															//Убрать!
						try {
							dictionary->Delete(&key);
							cout << "\n Узел " + key.get() + " успешно удалён";
							cout << "\n Чтобы продолжить, нажмите любую клавишу." << endl;
							_getch();

						} catch(string mess) {
							cout << mess + "\n Чтобы продолжить, нажмите любую клавишу." << endl;
							_getch();
						}
					} else {
						cout << "\n Узла с заданным ключём не обнаружено!";
						cout << "\n Чтобы продолжить, нажмите любую клавишу." << endl;
						_getch();
					}

					break;
				}

				//Удаление из узла значения.
				case '2':
				{
					CinKey("\n\n Введите ключ узла, из которого необходимо удалить значение: ");

					if(dictionary->Contains(&key)) {														//Проверка на наличие узла с таким ключём.

						cout << "\n Введите удаляемое значение: ";
						cin >> value;

						try {
							dictionary->Get(&key)->DelValue(&value);
							cout << "\n Значение " + value + " успешно удалено";
							cout << "\n Чтобы продолжить, нажмите любую клавишу." << endl;
							_getch();

						} catch(string mess) {
							cout << mess + "\n Чтобы продолжить, нажмите любую клавишу." << endl;
							_getch();
						}

					} else {
						cout << "\n Узла с заданным ключём не обнаружено!";
						cout << "\n Чтобы продолжить, нажмите любую клавишу." << endl;
						_getch();
					}
					break;
				}

				case 27:
					isDelMenu = false;
					break;
				}
			} while(isDelMenu);

			break;
		}

		// Выбран пункт меню выхода из программы.
		case quit:
			isMenu = false;
			break;
		}

		system("cls");
		isDelMenu = true;

	} while(isMenu);
}
