#pragma once

#include <iostream>

/*! @brif This Namespace Implements Binary Search Tree */
namespace BinaryTree {
	/* @brif Each Node Of the Tree
		@param Value It Creats Node With the given Value with The next Pointer as a nullptr*/
	struct Node {
		int value;
		Node* left;
		Node* right;
		Node() :value(0),left(nullptr),right(nullptr){}
		Node(int i):value(i),left(nullptr), right(nullptr){}
	};

	class BST {
	private:
		Node* Head_Node;
		void p_Insert(Node*& Nod, int number) {
			if (Nod == nullptr) {
				Nod = new Node;
				Nod->value = number;
				Nod->left = nullptr;
				Nod->right = nullptr;
			}
			else if (number == Nod->value) {
				return;
			}
			else if (number < Nod->value) {
				p_Insert(Nod->left, number);
			}
			else {
				p_Insert(Nod->right, number);
			}
		}
		void p_Print(Node* Nod) {
			if (Nod == nullptr) {
				return;
			}
			p_Print(Nod->left);
			std::cout << Nod->value << "-->";
			p_Print(Nod->right);
		}
		int p_Length(Node* Nod) {
			if (Nod == nullptr) {
				return 0;
			}
			return 1 + p_Length(Nod->left) + p_Length(Nod->right);
		}
		Node* p_Delete(Node* Nod, int number) {
			if (Nod == nullptr) {
				return Nod;
			}
			else if (number < Nod->value) {
				Nod->left = p_Delete(Nod->left, number);
			}
			else if (number > Nod->value) {
				Nod->right = p_Delete(Nod->right, number);
			}
			else {
				//When The Item Is Found .
				//Case 1: No Child Thus a LEAF NODE
				if (Nod->left == nullptr and Nod->right == nullptr) {
					delete Nod;
					Nod = nullptr;

				}
				//Case 2: Left Child is null
				else if (Nod->left == nullptr) {
					Node* temp = Nod;
					Nod = Nod->right;
					delete temp;

				}
				else if (Nod->right == nullptr) {
					Node* temp = Nod;
					Nod = Nod->left;
					delete temp;

				}
				//Case 3: Has Both Child
				else {
					Node* temp = p_FindMin(Nod->right);
					Nod->value = temp->value;
					Nod->right = p_Delete(Nod->right, temp->value);
				}

			}
			return Nod;
		}
		Node* p_FindMin(Node* Nod) {
			if (Nod->left == nullptr) {
				return Nod;
			}
			else {
				return p_FindMin(Nod->left);
			}
		}
		static int p_Max(int a, int b) {
			return (a >= b) ? a : b;
		}
		int p_height(Node* Nod) {
			if (Nod == nullptr) {
				return 0;
			}
			return 1 + p_Max(p_height(Nod->left), p_height(Nod->right));
		}
		bool p_FindBalance(Node* Nod) {
			int left_Subtree_Height;
			int right_Subtree_Height;
			if (Nod == nullptr) {
				return true;
			}
			left_Subtree_Height = p_height(Nod->left);
			right_Subtree_Height = p_height(Nod->right);
			if (abs(left_Subtree_Height - right_Subtree_Height) <= 1 and p_FindBalance(Nod->left) and p_FindBalance(Nod->right)) {
				return true;
			}
			return false;
		}
	public:
		BST() {
			Head_Node = nullptr;
		}
		~BST() = default;
		void insertNode(int number) {
			p_Insert(Head_Node, number);
		}
		void printTree() {
			p_Print(Head_Node);
			std::cout << std::endl;
		}
		int treeLength() {
			return p_Length(Head_Node);
		}
		bool isEmpty() {
			if (Head_Node == nullptr) {
				return true;
			}
			return false;
		}
		void removeNode(int number) {
			if (Head_Node == nullptr) {
				return;
			}
			p_Delete(Head_Node, number);
		}
		int findMinNode() {
			Node* temp = Head_Node;
			while (temp->left != nullptr) {
				temp = temp->left;
			}
			return temp->value;
		}
		int findMaxNode() {
			Node* temp = Head_Node;
			while (temp->right != nullptr) {
				temp = temp->right;
			}
			return temp->value;
		}
		void balanceTree() {
			if (p_FindBalance(Head_Node)) {
				std::cout << "It is Balanced " << std::endl;
			}
			else {
				std::cout << "It Is Not Balanced " << std::endl;
			}
		}
		int getTreeHeight() {
			return p_height(Head_Node);
		}
	};
}

/*! @brif This Namespace Implements Stack Data Type*/
namespace Stacks {
	class Stack
	{
	public:
		Stack() : nob(-1),maxItems(10)
		{
			items = new int[10];
		}
		Stack(int size) : nob(-1), maxItems(size)
		{
			items = new int[size];
		}
		bool isFull() {
			return (nob == maxItems - 1);
		}
		bool isEmpty() {
			return (nob == -1);
		}
		void push(int newItem) {
			if (isFull()) {
				throw std::string("Stack is Already Full");
			}
			nob++;
			items[nob] = newItem;
		}
		void pop() {
			if (isEmpty()) {
				throw std::string("The Stack is Already EMpty");
			}
			nob--;
		}
		int top() {
			if (isEmpty()) {
				throw std::string("The Stack is Empty Nothing To Peek");
			}
			return items[nob];
		}

	private:
		int nob;
		int *items;
		int maxItems;
	};
}

/*! @brif This Namespace Implements Queue Data Type*/
namespace Queue {
	class Que
	{
	public:
		Que() : maxQue(501), front(500), rear(500) {
			items = new int[maxQue];
		}
		Que(int max) : maxQue(max), front(max - 1), rear(max - 1) {
			items = new int[max];
		}
		~Que() = default;
		void MakeEmpty() {
			front = maxQue - 1;
			rear = maxQue - 1;
		}
		bool IsEmpty() {
			return (rear == front);
		}
		bool IsFull() {
			return ((rear + 1) % maxQue == front);
		}
		void Enqueue(int newItem) {
			if (IsFull())
				throw std::string("Queue is Already Full");
			else
			{
				rear = (rear + 1) % maxQue;
				items[rear] = newItem;
			}
		}
		void Dequeue(int& item) {
			if (IsEmpty())
				throw std::string("The Queue is Empty Cant Dequeue From an Empty Queue");
			else
			{
				front = (front + 1) % maxQue;
				item = items[front];
			}
		}

	private:
		int front;
		int rear;
		int * items;
		int maxQue;
	};
}

/*! @brif This Namespace Implements Different Lists*/
namespace List {
	struct Node {
	public:
		int value;
		Node* next;
	};

	class LinkedList {
	private:
		Node* head;
	public:
		LinkedList() {
			head = nullptr;
		}

		// Adds a node at the end of the list
		void addNode(int val) {
			Node* n = new Node;
			n->value = val;
			n->next = nullptr;

			if (head == nullptr) {
				head = n;
			}
			else {
				Node* p = head;
				while (p->next != nullptr) {
					p = p->next;
				}
				p->next = n;
			}
		}

		// Prints the value of each node
		void printList() {
			Node* p = head;
			if (head == nullptr) {
				std::cout << "List is empty.";
			}
			while (p != nullptr) {
				std::cout << p->value << "->";
				p = p->next;
			}
			std::cout << std::endl;
		}

		// Checks if a node with a specific
		// value exists in the list
		bool findNode(int val) {
			Node* p = head;
			if (p == nullptr) {
				return false;
			}
			while (p != nullptr) {
				if (p->value == val) {
					return true;
				}
				p = p->next;
			}
			return false;
		}

		// Prints the value of the last node
		void printLastNode() {
			Node* p = head;
			if (p == nullptr) {
				std::cout << "Empty List " << std::endl;
			}
			while (p->next != nullptr) {
				p = p->next;
			}
			std::cout << "The Last Node is " << p->value << std::endl;

		}

		// Prints the value of the middle node
		// if the list has even number of nodes then print
		// the value of the two middle nodes
		void printMiddleNode() {
			int l = length();
			if (l % 2 == 0) {
				int m = l / 2 - 1;
				Node* p = head;
				while (m--) {
					p = p->next;
				}
				std::cout << "The Middle Node is " << p->value << std::endl;
				std::cout << "The Middle Node is " << p->next->value << std::endl;
			}
			else {

				int m = length() / 2;
				Node* p = head;
				while (m--) {
					p = p->next;
				}
				std::cout << "The Middle Node is " << p->value << std::endl;
			}

		}

		int length() {
			int l{ 0 };
			Node* p = head;
			if (p == nullptr) {
				return 0;
			}
			while (p != nullptr) {
				l++;
				p = p->next;
			}
			return l;
		}
	};
}

