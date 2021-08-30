#include <iostream>
#pragma once

namespace List {
	template <class T>
	class List {
	private:
		template <class T1>
		class Node {
		private:
			T1 value;
			Node<T1>* next;
			Node<T1>* previous;
		public:
			Node(T1 value) { this->value = value; this->next = nullptr; this->previous = nullptr; }
			~Node() { }
			T1 GetValue() const { return this->value; }
			Node<T1>* GetNext() const { return this->next; }
			void SetNext(Node<T>* next) { this->next = next; }
			Node<T1>* GetPrevious() const { return this->previous; }
			void SetPrevious(Node<T>* previous) { this->previous = previous; }
		};
		Node<T>* head;
		Node<T>* tail;
		int size;
	public:
		List() { this->head = nullptr; this->size = 0; this->tail = nullptr; }
		~List() { Delete(); }
		class Iterator {
		private:
			List<T>::Node<T>* element;
		public:
			Iterator() { this->element = nullptr; }
			Iterator(Node<T>* node) { this->element = node; }
			~Iterator() { this->element = nullptr; }
			const T GetValue() const { return this->element->GetValue(); }
			void Next() { this->element = this->element->GetNext(); }
			void Previous() { this->element = this->element->GetPrevious(); }

			void operator=(List::Iterator other) { this->element = other.element; }
			void operator++() { this->element = this->element->GetNext(); } //++iterator;
			void operator++(int) { ++*this; } //iterator++;
			void operator--() { Previous(); } //--iterator;
			void operator--(int) { Previous(); } //iterator++;
			//bool operator==(const List::Node<T>& node) { return (this->element == node); }
			bool operator==(const Iterator& other) { return (this->element == other.element); }
			bool operator!=(const List::Node<T>& node) { return !(this->element == node); }
			bool operator!=(const Iterator& other) { return !(*this == other); }
			T operator*() { return this->element->GetValue(); }
			//T operator->() { return this->element->GetValue(); }
			//T operator+(int n) { return *(this + n); }
			//T operator[](int n) { return operator+(n); }
		};
		void Delete() { for (Node<T>* aux = this->head; aux != nullptr; aux = this->head) { this->head = aux->GetNext(); delete aux; } this->head = nullptr; this->tail = nullptr; }
		void Include(T value);
		void IncludeBack(T value);
		void Remove(T value);
		int GetSize() const { return this->size; }
		T Front() const { return this->head->GetValue(); }
		T Back() const { return this->tail->GetValue(); }
		List::Iterator Begin() { return Iterator(this->head); }
		List::Iterator End() { return Iterator(this->tail); }


		void ForEach(void(*ptr)(T)) { for (Node<T>* aux = head; aux != nullptr; aux = aux->GetNext()) { ptr(aux->GetValue()); } }
		void ForEach(void(*ptr)()) { for (Node<T>* aux = head; aux != nullptr; aux = aux->GetNext()) { ptr(); } }
	};

	template <class T>
	void List<T>::Include(T value)
	{
		Node<T>* aux = new Node<T>(value);
		aux->SetNext(this->head);
		if (this->head)
			this->head->SetPrevious(aux);
		else
			this->tail = aux;
		this->head = aux;
		this->size++;
	}

	template <class T>
	void List<T>::IncludeBack(T value)
	{
		Node<T>* aux = new Node<T>(value);
		aux->SetPrevious(this->tail);
		if (this->head == nullptr)
			this->head = aux;
		else //tail exists
			this->tail->SetNext(aux);
		this->tail = aux;
		this->size++;
	}

	template <class T>
	void List<T>::Remove(T value)
	{
		Node<T>* aux = this->head;
		for (; aux != nullptr && aux->GetValue() != value; aux = aux->GetNext()) {}
		if (aux == nullptr)
			return;
		if (aux == this->tail)
			this->tail = aux->GetPrevious();
		if (aux->GetNext() != nullptr)
			aux->GetNext()->SetPrevious(aux->GetPrevious());
		if (aux->GetPrevious() != nullptr)
			aux->GetPrevious()->SetNext(aux->GetNext());
		if (this->head == aux)
			this->head = aux->GetNext();
		this->size--;
		delete aux;
	}
}


