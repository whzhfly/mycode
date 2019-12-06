#include "pch.h"
#include <iostream>
#define SIZE 10
using namespace std;
/////////////图的邻接矩阵
class Graph
{
private:
	int V;//顶点数目
	int E;//边的数目
	int** Edge;//矩阵
	char* Vertex;//顶点信息矩阵
	int MaxVertex;
public:
	friend void DeepFirstSearch1(Graph g, char i);
	friend void DFS1(Graph G);
	Graph() {
		MaxVertex = SIZE;
		V = E = 0;
		Vertex = new char[MaxVertex];
		Edge = new int* [MaxVertex];//int *Edge[10]
		int i, j;
		for (int i = 0; i < MaxVertex; i++)
			Edge[i] = new int[MaxVertex];
		for (int i = 0; i < MaxVertex; i++)
		{
			for (j = 0; j < MaxVertex; j++)
				Edge[i][j] = 0;
		}//二维矩阵的初始化关于new
	}
	void InsertVerex(char v)//插入顶点
	{
		if (V >= MaxVertex)
			return;
		Vertex[V++] = v;
	}
	int GetVertex(char v)//查找
	{
		for (int i = 0; i <= V; i++)
		{
			if (Vertex[i] == v)
				return i;
		}
		return -1;
	}
	void InsertEdge(char v1, char v2)
	{
		int p1 = GetVertex(v1);
		int p2 = GetVertex(v2);
		if (p1 == -1 || p2 == -1) {
			cout << "Plesase input point first" << endl;
			return;
		}
		if (Edge[p1][p2] == 0) {
			Edge[p1][p2] = Edge[p2][p1] = 1;
			E++;
		}
	}
	void ShowGraph()
	{
		int i, j;
		cout << "  ";
		for (int i = 0; i < V; i++)
			cout << Vertex[i] << " ";
		cout << endl;
		for (int i = 0; i < V; i++)
		{
			cout << Vertex[i] << " ";
			for (int j = 0; j < V; j++)
				cout << Edge[i][j] << " ";
			cout << endl;
		}
	}
	int GetEdgeNum(char v)//获取点的边树
	{
		int p = GetVertex(v);
		if (p == -1)
			return 0;
		int n = 0;
		for (int i = 0; i < V; i++)
		{
			if (Edge[p][i] == 1)
			{
				n++;
			}
		}
		return n;
	}
	void DeleteVertex(char v)//删除一个顶点
	{
		int p = GetVertex(v);
		if (p == -1)
			return;
		int i, j;
		int n = GetEdgeNum(v);
		for (i = p; i < V - 1; i++)  //顶点先删除
			Vertex[i] = Vertex[i + 1];
		for (i = p; i < V - 1; i++)  //行上移
		{
			for (j = 0; j < V; j++)
				Edge[i][j] = Edge[i + 1][j];
		}
		for (i = 0; i < V - 1; i++)  //列左移
		{
			for (j = p; j < V - 1; j++)
			{
				Edge[i][j] = Edge[i][j + 1];
			}
		}
		V--;
		E -= n;
	}
	~Graph()
	{
		/*delete []Vertex;
		Vertex = NULL;
		for (int i = 0; i < V; i++)
		{
			delete []Edge[i];
			Edge[i] = NULL;
		}
		delete []Edge;
		Edge = NULL;
		V = 0;*/
	}
};
