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

namespace Stacks {
	class
}