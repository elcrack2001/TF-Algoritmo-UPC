#pragma once
#include "Librerias.h"

template<class T>
struct Node
{
	T key;
	struct Node* Lchild;
	struct Node* Rchild;
	int height;
	Node()
	{
		Lchild = nullptr;
		Rchild = nullptr;
		height = 1;
	}
};

