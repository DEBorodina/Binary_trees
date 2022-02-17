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


class BinaryTree {

public:

	//ADD NEW NODE===============================================================================================================
	static struct Node* addNode(long int x, Node* tree) {
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
    static void print(Node* tree) {
		if (tree != NULL) {
			out << tree->value << endl;
			print(tree->leftSon);
			print(tree->rightSon);
		}
	}
	//===========================================================================================================================


	//DELETE NODE(RIGHT)=====================================================================================================
	static struct Node* deleteNode(Node* tree,long int target) {

		if (tree == NULL) {
			return NULL;
		}
		if (target < tree->value) {
			tree->leftSon = deleteNode(tree->leftSon, target);
			return tree;
		}
		else if (target > tree->value) {
			tree->rightSon = deleteNode(tree->rightSon, target);
			return tree;
		}
		if (target == tree->value) {
			if (tree->leftSon == NULL) {
				return tree->rightSon;
			}
			else if (tree->rightSon == NULL) {
				return tree->leftSon;
			}
			else {
				long int min = minValueNode(tree->rightSon)->value;
				tree->value = min;
				tree->rightSon = deleteNode(tree->rightSon, min);
				return tree;
			}
		}

	}
	//========================================================================================================================



private:
	
	//FIND MIN  VALUE=========================================================================================================
	static struct Node* minValueNode(Node* tree) {
		if (tree->leftSon == NULL) {
			return tree;
		}
		else {
			return minValueNode(tree->leftSon);
		}
	}
	//========================================================================================================================
};


int main()
{
	string node;
	Node* Tree = NULL;

	long int target;
	in >> target;

	while (in >> node) {
		if(node != "") Tree = BinaryTree::addNode(atoi(node.c_str()), Tree);
	}

	BinaryTree::print(BinaryTree::deleteNode(Tree, target));

	in.close();
	out.close();
	system("pause");
	return 0;
}
