// AvlTree.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<vector>
#include<queue>
#include<stack>

using namespace std;
#define LH +1//左高
#define EH 0//等高
#define RH -1//右高
typedef struct BiTNode {
	int data;
	int bf;
	struct BiTNode * lchild, * rchild;
}BiTNode, *BiTree;
//typedef enum { false, true }bool;
//R旋转
void R_Rotate(BiTree *p) {
	BiTree L;
	L = (*p)->lchild;
	(*p)->lchild = L->rchild;
	L->rchild = (*p);
	*p = L;
}
void L_Rotate(BiTree *p) {
	BiTree R;
	R= (*p)->rchild;
	(*p)->rchild = R->lchild;
	R->lchild = (*p);
	*p = R;
}
void LeftBalance(BiTree *T) {
	BiTree L, Lr;
	L = (*T)->lchild;//L指向T的左子树
	switch (L->bf)
	{
	case LH:
		(*T)->bf = L->bf = EH;
		R_Rotate(T);
		break;
	case RH:
		Lr = L->rchild;
		switch (Lr->bf) {
		case LH:
			(*T)->bf = RH;
			L->bf = EH;
			break;
		case EH:
			(*T)->bf = L->bf = EH;
			break;
		case RH:
			(*T)->bf = EH;
			L->bf = LH;
			break;
		}
		Lr->bf = EH;
		L_Rotate(&(*T)->lchild);//对T德左子树做左旋平衡处理
		R_Rotate(T);//对T做右旋平衡处理
		break;
	}
}
void RightBalance(BiTree *T) {
	BiTree R, Rl;
	R = (*T)->rchild;//L指向T的左子树
	switch (R->bf)
	{
	case RH:
		(*T)->bf = R->bf = EH;
		L_Rotate(T);
		break;
	case LH:
		Rl = R->lchild;
		switch (Rl->bf) {
		case LH:
			(*T)->bf = EH;
			R->bf = RH;
			break;
		case EH:
			(*T)->bf = R->bf = EH;
			break;
		case RH:
			(*T)->bf = LH;
			R->bf = EH;
			break;
		}
		Rl->bf = EH;
		R_Rotate(&(*T)->rchild);
		L_Rotate(T);
		break;
	}
}
//往平衡二叉树上插入结点
bool InsertAVL(BiTree *T, int e, bool *  taller) {
	if (*T == NULL) //找到插入位置
	{
		*T = (BiTree)malloc(sizeof(BiTNode));
		(*T)->data = e;
		(*T)->lchild = (*T)->rchild = NULL;
	}
	else
	{
		if (e == (*T)->data)//数中存在相同节点
		{
			*taller = false;
			return false;
		}
		if (e < (*T)->data)//左子树搜查
		{
			if (!InsertAVL(&(*T)->lchild, e, taller));
			return false;
			if (taller)//长高 指的是那个部分 每个循环中以&(*T)->lchild为root的树 每次添加最后一个root肯定使taller为true 在返回时候如果有为false 则一直为false 表示以这个root
				//的添加并没有taller
			{
				switch ((*T)->bf) //检查平衡
				{
				case LH:
					LeftBalance(T); //插入后左边不平衡了，让其左平衡
					*taller = false;
					break;
				case EH:
					(*T)->bf = LH;
					*taller = true;
					break;
				case RH:
					(*T)->bf = EH;
					*taller = true;
					break;
				}
			}
		}
		else//右子树查找
		{
			if (!InsertAVL(&(*T)->rchild, e, taller));
			return false;
			if (taller)//长高 
			{
				switch ((*T)->bf) //检查平衡
				{
				case LH:
					(*T)->bf = EH;
					*taller = true;
					break;
				case EH:
					(*T)->bf = RH;
					*taller = true;
					break;
				case RH:
					RightBalance(T);
					*taller = false;
					break;
				}
			}
		}
	}
	return true;
}
//往平衡二叉树上删除结点
bool DeleteAVL(BiTree * T, int key, bool * shorter) 
{
	if (*T == NULL)
		return false;
	else if ((*T)->data == key) //找到key
	{
		BiTree  p = NULL;
		if ((*T)->lchild == NULL) {
			//左子树为空
			p = (*T);
			(*T) = (*T)->rchild;
			free(p);
			*shorter = true;
		}
		else if((*T)->rchild == NULL) {
			//有子树为空
			p = (*T);
			(*T) = (*T)->lchild;
			free(p);
			*shorter = true;
		}
		else {//左右都在
			p = (*T)->lchild;
			while (p->rchild!=NULL)
			{
				p = p->rchild;
			}
			(*T)->data = p->data;
			// 在左子树中删除前驱结点
			DeleteAVL(&(*T)->lchild, p->data, shorter);
		}
	}
	else if ((*T)->data > key) {
		if (!DeleteAVL(&(*T)->lchild, key, shorter))
			return false;
		if (*shorter == true) {
			switch ((*T)->bf)
			{
			case LH:
				(*T)->bf = EH;
				*shorter = true;
				break;
			case EH:
				(*T)->bf = RH;
				*shorter = false;
				break;
			case RH:
				RightBalance(T);
				if ((*T)->rchild->bf == EH)
					*shorter = false;
				else *shorter = true;
				break;
			}
		}
	}
	else {
		if (!DeleteAVL(&(*T)->rchild, key, shorter))
			return false;
		if (*shorter == true) {
			switch ((*T)->bf)
			{
			case LH:
				LeftBalance(T);
				if ((*T)->lchild->bf == EH)
					*shorter = false;
				else *shorter = true;
				break;
			case EH:
				(*T)->bf = LH;
				*shorter = false;
				break;
			case RH:
				(*T)->bf = EH;
				*shorter = true;
				break;
			}
		}
	}
	return true;
}
void SplitVAL(BiTree * T, int key, BiTree * T1, BiTree * T2) {
	bool * taller = false;
	if (T != NULL) {
		SplitVAL(&(*T)->lchild, key,&(*T1), &(*T2)); //递归
		if ((*T)->data > key) {
			InsertAVL(&(*T1), (*T)->data, taller);
		}
		else 
			InsertAVL(&(*T2), (*T)->data, taller);
		SplitVAL(&(*T)->rchild, key, &(*T1), &(*T2)); //递归
	}
}
void MergeVAL(BiTree * T1, BiTree * T2) {
	bool * taller = false;
	if (T2 != NULL)
	{
		MergeVAL(&(*T1), &(*T2)->lchild);
		InsertAVL(&(*T1), (*T2)->data, taller);
		MergeVAL(&(*T1), &(*T2)->rchild);
	}
}
void PreOrderTraversal(BiTree T)                    //递归前序遍历
{
	if (T != NULL)
	{
		printf("%5d", T->data);
		PreOrderTraversal(T->lchild);
		PreOrderTraversal(T->rchild);
	}
}
int main()
{
	BiTree T = NULL;
	int i;
	int a[6] = { 10,15,23,5,6,1 };
	bool taller = true;
	for (i = 0; i < 6; i++)
		InsertAVL(&T, a[i], &taller);      //如果InsertAVLtree的参数是BiTree T而不是BiTree *T的话，是没有办法改变T的值的，所以用前序遍历是没有用的
	PreOrderTraversal(T);				//因为跟值传递一样，只有改变地址才可以改变指针的指向。如果不改，那么T将永远指向NULL
	printf("\n");
    taller = true;
	DeleteAVL(&T, 10, &taller);
	PreOrderTraversal(T);
	system("pause");
	return 0;
	
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
