#pragma once
#include <iostream>

using namespace std;

// Khai bao cau truc node
struct TNode {
    int key;
    TNode *pLeft;
    TNode *pRight;
};

// Khai bao cau truc cay
typedef TNode *Tree;

// Create Tree
void CreateTree(Tree &T)
{
    T = NULL;
}

// Create Node
TNode* CreateNode(int x)
{
    TNode *p;
    p = new TNode;
    if (p == NULL)
    {
        exit(1);
    }
    p->key = x;
    p->pLeft = NULL;
    p->pRight = NULL;
    return p;
}

// Insert a node to tree (recursion)
int InsertRecursion(Tree &T, int x)
{
    if (T)
    {
        if (T->key == x)
        {
            return 0;
        }
        else if (x > T->key)
        {
            return InsertRecursion(T->pRight, x);
        }
        else
        {
            return InsertRecursion(T->pLeft, x);
        }
    }
    T = CreateNode(x);
    return 1;
}

// Insert a node to tree
int Insert(Tree &Root, int x)
{
    if (Root == NULL)
    {
        Root = CreateNode(x);
    }
    Tree T = Root;
    while (T)
    {
        if (T->key == x)
        {
            return 0;
        }
        if (x > T->key)
        {
            if (T->pRight == NULL)
            {
                T->pRight = CreateNode(x);
            }
            else
            {
                T = T->pRight;
            }
        }
        else
        {
            if (T->pLeft == NULL)
            {
                T->pLeft = CreateNode(x);
            }
            else
            {
                T = T->pLeft;
            }
        }
    }
    return 1;
}

// List: preOrder
void preOrder(Tree Root)
{
    if (Root)
    {
        cout << Root->key << "\t";
        preOrder(Root->pLeft);
        preOrder(Root->pRight);
    }
}

// List: inOrder
void inOrder(Tree Root)
{
    if (Root)
    {
        inOrder(Root->pLeft);
        cout << Root->key << "\t";
        inOrder(Root->pRight);
    }
}

// List: postOrder
void postOrder(Tree Root)
{
    if (Root)
    {
        postOrder(Root->pLeft);
        postOrder(Root->pRight);
        cout << Root->key << "\t";
    }
}

// Delete node
void ThayThe(Tree &p, Tree &T) // Thế mạng là node trái nhất bên phải
{
	if (T->pLeft != NULL)
		ThayThe(p, T->pLeft);
	else
    {
        p->key = T->key;
        p = T;
        T = T->pRight;		
    }
}

void DeleteNodeX(Tree &T, int x)
{
	if (T != NULL)
	{
		if (x > T->key)
		{
            cout << x;
            cout << T->key;
            cout << "Right";
            cout << endl;
			DeleteNodeX(T->pRight, x);
		}
        else
        {
            if (x < T->key)
            {
                cout << x;
                cout << T->key;
                cout << "Left";
                cout << endl;
                DeleteNodeX(T->pLeft, x);
            }
            else
            {
                TNode* p;
                p = T;
                if (T->pLeft == NULL)
                {
                    T = T->pRight;
                }
                else
                {
                    if (T->pRight == NULL)
                    {
                        T = T->pLeft;
                    }
                    else // Đủ 2 cây con
                    {
                        ThayThe(p, T->pRight);
                    }
                }
                delete p;
            }
        }
		
	}
}
