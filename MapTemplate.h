#include <iostream>

template <class T1, class T2>
class MapTemplate {
private:
	template <class T3, class T4>
	class Node {
	private:
		Node<T3, T4>* right;
		Node<T3, T4>* left;
		T3 key;
		T4 data;
	public:
		Node(T3 key, T4 data) { right = nullptr; left = nullptr; this->key = key; this->data = data; }
		~Node() {}
		Node<T3, T4>* getRight() const { return right; }
		Node<T3, T4>* getLeft() const { return left; }
		const T3 getKey() const { return key; }
		const T4 getData() const { return data; }
		void setRight(Node<T3, T4>* right) { this->right = right; }
		void setLeft(Node<T3, T4>* left) { this->left = left; }
	};

	Node<T1, T2>* head;
	size_t size;
	/*Node <T1, T2>* add(Node<T1, T2>* aux, T1 key, T2 data, bool equal) {
		if (equal == false) {
			if (aux == nullptr)
			{
				Node <T1, T2>* aux = new Node<T1, T2>(key, data);
				aux->setLeft(nullptr);
				aux->setRight(nullptr);
				std::cout << "Adicionou!" << std::endl;
			}
			else {
				if (key < aux->getKey())
					aux->setLeft(add(aux->getLeft(), key, data, equal));
				else if (key > aux->getKey())
					aux->setRight(add(aux->getRight(), key, data, equal));
				else
					equal = true;
			}
			return aux;
		}
		else
			return aux;
	}*/

	bool search(Node<T1, T2>* aux, T1 key) {
		if (aux == nullptr)
			return 0;
		else if (key < aux->getKey())
			return search(aux->getLeft(), key);
		else if (key > aux->getKey())
			return search(aux->getRight(), key);
		else
			return 1;
	}

	Node<T1, T2>* find(Node<T1, T2>* aux, T1 key) {
		if (aux == nullptr)
			return nullptr;
		else if (key < aux->getKey())
			return find(aux->getLeft(), key);
		else if (key > aux->getKey())
			return find(aux->getRight(), key);
		else
			return aux;
	}

	void forEach1(void(*function)(T1), Node<T1,T2> *aux) {
		if (aux != nullptr) {
			function(aux->getKey());
			forEach1(function, aux->getLeft());
			forEach1(function, aux->getRight());
		}
	}

public:
	MapTemplate() { head = nullptr; size = 0; }
	~MapTemplate() { clear(head); }
	void clear(Node<T1, T2>* aux) {
		if (aux != nullptr) {
			clear(aux->getLeft());
			clear(aux->getRight());
			delete aux;
		}
	}

	void add(T1 key, T2 data) {
		Node<T1, T2>* aux = head;
		Node<T1, T2>* prev = nullptr;
		Node<T1, T2>* newNode = nullptr;
		if (head == nullptr) {
			newNode = new Node<T1, T2>(key, data);
			head = newNode;
			return;
		}
		while (aux != nullptr) {
			prev = aux;
			if (aux->getKey() > key)
				aux = aux->getLeft();
			else if (aux->getKey() < key)
				aux = aux->getRight();
			else
				return;
		}
		newNode = new Node<T1, T2>(key, data);
		if (prev->getKey() > key)
			prev->setLeft(newNode);
		else
			prev->setRight(newNode);
	}

	bool contains(T1 key) {
		return search(head, key);
	}

	void forEach(void(*function)(T1)) {
		forEach1(function, head);
	}

	T2 operator[](T1 key) {
		return find(head, key)->getData();
	}
};
	
