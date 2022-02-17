#include <iostream>
#include<fstream>
#include<string>

using namespace std;


//CONNECT FILES==============================================================================================================
ifstream in("input.txt");
ofstream out("output.txt");
//===========================================================================================================================


//NODE STRUCTURE=============================================================================================================
struct Node {
	long int value;
	struct Node* leftSon;
	struct Node* rightSon;
};
//===========================================================================================================================


//ADD NEW NODE===============================================================================================================
struct Node* addNode(int x, Node* tree) {
	if (tree == NULL) {
		tree = new Node;
		tree->value = x;
		tree->leftSon = NULL;
		tree->rightSon = NULL;
	}
	else if (x < tree->value) {
		tree->leftSon = addNode(x, tree->leftSon);
	}
	else if (x > tree->value) {
		tree->rightSon = addNode(x, tree->rightSon);
	}
	return tree;
}
//===========================================================================================================================


//PRINT TREE(LEFT FORWARD BYPASS)============================================================================================
void print(Node* tree) {
	if (tree != NULL) {
		out << tree->value << endl;
		print(tree->leftSon);
		print(tree->rightSon);
	}
}
//===========================================================================================================================


int main()
{
	int node;
	Node* Tree = NULL;

	while (in >> node) {
		Tree = addNode(node, Tree);
	}
	print(Tree);
	in.close();
	out.close();
	system("pause");
	return 0;
}
