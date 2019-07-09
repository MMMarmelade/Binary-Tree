#pragma once
#include<iostream>

struct bitreenode {
	bitreenode(int a = -1) :
		data(a), lchild(nullptr), rchild(nullptr) {};//初始化函数
	/*bitreenode(int a = -1) {
		data = a;lchild = NULL;rchild = NULL;
	}*/
	int data;
	bitreenode* lchild, * rchild;
};

typedef bitreenode* biTree;

/**************************
按照先序顺序创建二叉树
数组为结点数据，遇到-1返回
index必须用引用，在多个递归中要保持连续
返回根指针
***************************/
template<int N>
biTree buildTree(int (&datum)[N],int &index) {
	/*过界或遇到终点信号返回sizeof(int)*index==sizeof(datum)*/
	if ( index == N||(datum[index] == -1))
		return nullptr;
	biTree T = new bitreenode(datum[index]);
	T->lchild = buildTree(datum, ++index);
	T->rchild = buildTree(datum, ++index);
	//std::cout << sizeof(datum) << std::endl;
	return T;
}

/*************************
*先根遍历
***************************/
void PreOrder(biTree F) {
	if (F) {
		std::cout << F->data << std::endl;
		PreOrder(F->lchild);
		PreOrder(F->rchild);
	}
}
/***********************
在T中搜索数据为d的结点，返回其指针
************************/
biTree biTSearch(int d,biTree &T) {
	if (!T)
		return NULL;
	else if (T->data == d)
		return T;
	else {
		biTree tmpl = biTSearch(d, T->lchild);
		if (tmpl)
			return tmpl;
		biTree tmpr = biTSearch(d, T->rchild);
		if (tmpr)
			return tmpr;
	}
}
/**********************
在T中删除数据为d的结点
若该结点有左子树，则左子树继承，右子树成为左子树的右子树，若无，则右子树继承
~~~~~目前未完成，更改其本身并未更改父结点的子结点
***********************/
void biTDelete(int d, biTree& T) {
	if (T) {
		if (T->data == d) {
			biTree P = T;
			if (T->lchild) {
				T->lchild->rchild = T->rchild;
				T = T->lchild;
			}
			else
				T = T->rchild;
			delete P;//从内存中删除该地址结点
		}
		else {
			biTDelete(d, T->lchild);
			biTDelete(d, T->rchild);
		}
	}
}
