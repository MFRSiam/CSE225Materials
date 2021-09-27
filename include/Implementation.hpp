#pragma once

#include <iostream>

/*! @brif This Namespace Implements Binary Search Tree */
namespace BST {
	/* @brif Each Node Of the Tree
		@param Value It Creats Node With the given Value with The next Pointer as a nullptr*/
	struct Node {
		int value;
		Node* next;
		Node() :value(0),next(nullptr){}
		Node(int i):value(i),next(nullptr){}
	};

	class BST {

	};
}