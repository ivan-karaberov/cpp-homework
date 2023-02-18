#ifndef _H_LINKED_LIST_H_
#define _H_LINKED_LIST_H_

namespace my {
	template <class T> class LinkedList {
	private:
		class Node {
		public:
			T data;
			Node *prev, *next;

			Node(T data) {
				this->data = data;
				this->prev = this->next = NULL;
			}
		};

		Node *head, *tail;
		int topOfSize;

	public:
		LinkedList() {
			topOfSize = 0;
			head = tail = NULL;
		}

		~LinkedList() {
			while (!empty())
				pop_front();
		}

		int size() {
			return topOfSize;
		}

		bool empty(){
			return topOfSize == 0;
		}

		Node* getByIndex(int index) {
			if (index >= 0) {
				int counter = 0;
				for (Node* ptr = head; ptr != NULL; ptr = ptr->next) {
					if (counter == index) return ptr;
					counter++;
				}
			}

			if (index < 0) {
				int counter = -1;
				for (Node* ptr = tail; ptr != NULL; ptr = ptr->prev) {
					if (counter == index) return ptr;
					counter--;
				}
			}

			return 0;
		}

		Node* operator [] (int index) {
			return getByIndex(index);
		}


		Node* push_front(T data) {
			Node* ptr = new Node(data);
			ptr->next = head;

			if (head != NULL) {
				head->prev = ptr;
			}

			if (tail == NULL) {
				tail = ptr;
			}

			head = ptr;
			topOfSize++;

			return ptr;
		}

		Node* push_back(T data) {
			Node* ptr = new Node(data);
			ptr->prev = tail;
			
			if (tail != NULL) {
				tail->next = ptr;
			}

			if (head == NULL) {
				head = ptr;
			}

			tail = ptr;
			topOfSize++;
			
			return ptr;
		}

		void pop_front() {
			if (empty()) return;

			Node* ptr = head->next;
			if (ptr != NULL) {
				ptr->prev = NULL;
			}
			else {
				tail = NULL;
			}

			delete head;

			head = ptr;
			topOfSize--;
		}


		void pop_back() {
			if (empty()) return;

			Node* ptr = tail->prev;
			if (ptr != NULL) {
				ptr->next = NULL;
			}
			else {
				head = NULL;
			}

			delete tail;

			tail = ptr;
			topOfSize--;
		}

		Node* insert(int index, T data) {
			Node* right = getByIndex(index);
			if (right == NULL) return push_back(data);

			Node* left = right->prev;
			if (left == NULL) return push_front(data);

			Node* ptr = new Node(data);

			ptr->prev = left;
			ptr->next = right;
			left->next = ptr;
			right->prev = ptr;

			topOfSize++;

			return ptr;
		}

		void erase(int index) {
			Node* ptr = getByIndex(index);
			if (ptr == NULL) return;
			
			if (ptr->prev == NULL) {
				pop_front();
				return;
			}

			if (ptr->next == NULL) {
				pop_back();
				return;
			}

			Node* left = ptr->prev;
			Node* right = ptr->next;
			left->next = right;
			right->prev = left;

			delete ptr;
			
			topOfSize--;
		}
	};

};

#endif