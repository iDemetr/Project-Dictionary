#pragma once

#ifndef LIST_H
#define LIST_H

#ifdef LIST_EXPORTS
#define LIST_API __declspec(dllexport)
#else
#define LIST_API __declspec(dllimport)
#endif

using namespace std;

namespace MyList {

	template<class T>
	class List;

	template<class T>
	class NodeList;

	/// <summary>
	/// ���������������� �����, ����������� ��������� ������ "������������ ������"
	/// </summary>
	template<class T>
	class LIST_API List {

	public:
		List();
		~List();

		/// <summary>
		/// ����������� �����������
		/// </summary>
		/// <param name=""></param>
		List(List<T> &);

		/// <summary>
		/// ������� ���������.
		/// </summary>
		int Count;

		NodeList<T> *Head, *Tail;

		/// <summary>
		/// ������� ������ ���� � ��������� ���� T � ��������� ��� � ������.
		/// </summary>
		/// <param name="T">����</param>
		void Add(T *);

		/// <summary>
		/// ����������� �������.
		/// </summary>
		void Add(List<T> *);

		/// <summary>
		/// ������� ���������� � ������ ���������� ����.
		/// </summary>
		/// <param name="node">��������� �� ����������� ����</param>
		void Append(NodeList<T> *&);

		/// <summary>
		/// ������� �������� �� �����.
		/// </summary>
		/// <param name="key">�������� ���������� ����.</param>
		void Delete(T *);

		/// <summary>
		/// ������ �������� �� ��������� �� ������.
		/// </summary>
		/// <param name="node">��������� ����.</param>
		void Delete(NodeList<T> *);

		/// <summary>
		/// ������ ������� ������.
		/// </summary>
		void Clear();
	};

	/// <summary>
	/// ����� ���� ��� ������������ ������.
	/// </summary>
	/// <typeparam name="T"></typeparam>
	template<class T>
	class LIST_API NodeList {

	public:
		T *�bj;

		NodeList<T> *Next;

		/// <summary>
		/// �����������, ���������� �������� �� ��������� � ���������� ��������
		/// </summary>
		NodeList();

		/// <summary>
		/// 
		/// </summary>
		~NodeList();

		/// <summary>
		/// �������� ���� � �������� ���������.
		/// </summary>
		/// <typeparam name="T"></typeparam>
		NodeList(T*);

		/// <summary>
		/// ����������� �����������
		/// </summary>
		/// <param name=""></param>
		NodeList(NodeList<T> &);
	};
}

#endif