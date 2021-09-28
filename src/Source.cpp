#include <fmt/ostream.h>
#include "../include/Implementation.hpp"
#include <random>

int main(void) {
	fmt::print("Hello World \n");
	BinaryTree::BST B1;
	int rand;
	for (int i = 0; i < 100; i++) {
		rand = std::rand() % 899 + 1;
		B1.insertNode(rand);
	}

	B1.printTree();
	return EXIT_SUCCESS;
}