#include "BinaryTree.h"
#include <iostream>
using namespace std;

int treeDatum[13] = { 25,12,-1,23,-1,-1,36,43,-1,-1,54,-1,-1 };



int main()
{
	int index = 0;
	biTree bt = buildTree(treeDatum, index);
	PreOrder(bt);
	

	//删除结点测试
	//biTree &F = bt->rchild;//可以删除结点
	////biTree F = bt->rchild;//不能删除结点
	//F = F->lchild;

	biTDelete(36,bt);
	PreOrder(bt);
}

