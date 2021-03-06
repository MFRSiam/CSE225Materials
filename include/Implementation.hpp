#pragma once

#include <iostream>
#include <stack>
#include <queue>

/*! @brief This Namespace Implements Binary Search Tree */
namespace BinaryTree {
	/* @brief Each Node Of the Tree
		@param Value It Creats Node With the given Value with The next Pointer as a nullptr*/
	struct Node {
		int value;
		Node* left;
		Node* right;
		Node() :value(0),left(nullptr),right(nullptr){}
		Node(int i):value(i),left(nullptr), right(nullptr){}
	};
	/*! @brief This Class Implements The Binary Search Tree Data Structure
	*	@param This Class Requires No Parameters
	*/
	class BST {
	private:
		/*! @brief This Is The Head Node Variable To Keep Track Of the head node */ 
		Node* Head_Node;
		/*! @brief This is the private Funtion To insert a new node in Its Place. The 1st recursive call will have an null nod then will create a node which will make the 2nd recursive calls and onwards have a node reference pointer.
		*	@param Node This Requires a Node and a Number
		*/
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

/*! @brief This Namespace Implements Stack Data Type*/
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

/*! @brief This Namespace Implements Queue Data Type*/
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

/*! @brief This Namespace Implements Different Lists*/
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

/*! @brief This Namespace Implements Different Graphs */
namespace Graphs {
	class Graph
	{
	private:
		int numVertices;
		int maxVertices;
		std::string* vertices;
		int** edges;
		bool* visited;

	public:
		Graph()
		{
			numVertices = 0;
			maxVertices = 50;
			vertices = new std::string[50];
			edges = new int* [50];
			for (int i = 0; i < 50; i++)
			{
				edges[i] = new int[50];
			}
			visited = new bool[50];
		}

		Graph(int maxV)
		{
			numVertices = 0;
			maxVertices = maxV;
			vertices = new std::string[maxV];
			edges = new int* [maxV];
			for (int i = 0; i < maxV; i++)
			{
				edges[i] = new int[maxV];
				for (int j = 0; j < maxV; j++)
					edges[i][j] = 0;
			}
			visited = new bool[maxV];
		}

		~Graph()
		{
			delete[] vertices;
			delete[] visited;
			for (int i = 0; i < maxVertices; i++)
				delete[] edges[i];
			delete[] edges;
		}

		void makeEmpty()
		{
			numVertices = 0;
		}

		bool isEmpty()
		{
			if (numVertices = 0)
			{
				return true;
			}
			else
			{
				return false;
			}
		}

		bool isFull()
		{
			if (numVertices = maxVertices)
			{
				return true;
			}
			else
			{
				return false;
			}
		}

		void addVertex(std::string vertex)
		{
			vertices[numVertices] = vertex;
			for (int index = 0; index < numVertices; index++)
			{
				edges[numVertices][index] = 0;
				edges[index][numVertices] = 0;
			}
			numVertices++;
		}

		void addEdge(std::string fromVertex, std::string toVertex, int weight)
		{
			int row = indexIs(vertices, fromVertex);
			int col = indexIs(vertices, toVertex);
			edges[row][col] = weight;
		}

		int weightIs(std::string fromVertex, std::string toVertex)
		{
			int row = indexIs(vertices, fromVertex);
			int col = indexIs(vertices, toVertex);
			return edges[row][col];
		}

		int indexIs(std::string* vertices, std::string vertex)
		{
			for (int i = 0; i < maxVertices; i++)
			{
				if (vertex == vertices[i])
				{
					return i;
				}
			}
			return -1;
		}

		void getAdjacentVertices(std::string vertex, std::queue<std::string>& adjVertices)
		{
			int fromIndex;
			int toIndex;
			fromIndex = indexIs(vertices, vertex);
			for (toIndex = 0; toIndex < numVertices; toIndex++)
			{
				if (edges[fromIndex][toIndex] != 0)
				{
					adjVertices.push(vertices[toIndex]);
					// in C++ STL Queue, push = enqueue
					// and pop = dequeue
				}
			}
		}

		void clearVisited()
		{
			for (int i = 0; i < maxVertices; i++)
			{
				visited[i] = false;
			}
		}

		void markVertex(std::string vertex)
		{
			visited[indexIs(vertices, vertex)] = true;
		}

		bool isMarked(std::string vertex)
		{
			return visited[indexIs(vertices, vertex)];
		}

		void printGraph()
		{
			for (int i = 0; i < numVertices; i++)
			{
				std::cout << vertices[i];
				std::cout << " : ";
				for (int j = 0; j < numVertices; j++)
				{
					if (edges[i][j] != 0)
					{
						std::cout << vertices[j];
						std::cout << ",";
						//cout << "(" <<edges[i][j] << "), ";
					}
				}
				std::cout << "\b ";
				std::cout << std::endl;
			}
		}
	};

	void depthFirstSearch(Graph graph, std::string startVertex, std::string endVertex)
	{
		std::stack<std::string> vStack;
		std::queue<std::string> adjacentVertices;
		bool found = false;
		std::string vertex;
		std::string item;
		graph.clearVisited();
		vStack.push(startVertex);
		std::cout << "Visited nodes: ";
		do
		{
			vertex = vStack.top();
			vStack.pop();
			if (vertex == endVertex)
			{
				std::cout << vertex;
				found = true;
			}
			else
			{
				if (!graph.isMarked(vertex))
				{
					graph.markVertex(vertex);
					std::cout << vertex << " ";
					graph.getAdjacentVertices(vertex, adjacentVertices);
					while (!adjacentVertices.empty())
					{
						item = adjacentVertices.front();
						adjacentVertices.pop();
						if (!graph.isMarked(item))
							vStack.push(item);
					}
				}
			}
		} while (!vStack.empty() && !found);

		if (!found)
			std::cout << "\nPath not found." << std::endl;
	}

	void breadthFirstSearch(Graph graph, std::string startVertex, std::string endVertex)
	{
		std::queue<std::string> mainQueue;
		std::queue<std::string> adjacentVertices;
		bool found = false;
		std::string vertex;
		std::string item;
		graph.clearVisited();
		mainQueue.push(startVertex);
		std::cout << "Visited nodes: ";
		do
		{
			vertex = mainQueue.front();
			mainQueue.pop();
			if (vertex == endVertex)
			{
				std::cout << vertex;
				found = true;
			}
			else
			{
				if (!graph.isMarked(vertex))
				{
					graph.markVertex(vertex);
					std::cout << vertex << " ";
					graph.getAdjacentVertices(vertex, adjacentVertices);
					while (!adjacentVertices.empty())
					{
						item = adjacentVertices.front();
						adjacentVertices.pop();
						if (!graph.isMarked(item))
							mainQueue.push(item);
					}
				}
			}
		} while (!mainQueue.empty() && !found);

		if (!found)
			std::cout << "\nPath not found." << std::endl;
	}

	void checkadjacent(Graph& graph, std::string x)
	{

		std::queue<std::string> q1;
		graph.getAdjacentVertices(x, q1);
		if (q1.size() == 0)
		{
			return;
		}
		for (int i = 0; i <= (int)q1.size(); i++)
		{
			std::cout << q1.front() << " ";
			q1.pop();
		}
		std::cout << std::endl;
	}

}
