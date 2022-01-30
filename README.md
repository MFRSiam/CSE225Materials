# This Repo Has Some of The Data Structures Taught in CSE225(NSU)

### Please Give it a Star If This helped You in any way.

This Repo Has 4 Folders. The `/src/` Is For Testing Different Implemented Data Structure. The `/include/` Has Implementation In it, as many of the data structure uses a template i found this  to be in a header file much more convenient instead of compiling it separately then linking it or just including the .cpp file. Most of the Data Structure's are implemented Inside a Namespace.

![](https://imgur.com/a/r6xU45y)

As You can See Most Of Them Are Self Explanatory. But in Order To use them You need a to use its namespace 1st . Example For a Random Numbers in a BST.

```cpp
#include <iostream>
#include "../include/Implementation.hpp"
#include <random>

int main(void) {
    std::cout << "Hello " << std::endl;
    BinaryTree::BST B1;
    int rand;
    for (int i = 0; i < 100; i++) {
        rand = std::rand() % 899 + 1;
        B1.insertNode(rand);
    }
    B1.printTree();
    return EXIT_SUCCESS;
}

```

I hope That makes it clear.
