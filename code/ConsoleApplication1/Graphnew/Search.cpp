#include "pch.h"
#include <iostream>
#include<queue>
#include<vector>
#include "Graph.h"
#include "GraphLink.h"
#include <algorithm>
#define SIZE 10
using namespace std;
bool visited1[SIZE];
bool visited2[SIZE];
bool visited3[SIZE];
bool visited4[SIZE];
bool visited5[SIZE];
void DeepFirstSearch1(Graph G,char b) {//深度优先
	int j;
	int i = G.GetVertex(b);
	visited1[i] = true;
	cout << G.Vertex[i];
	for (j = 0; j < G.V; j++) {
		if (G.Edge[i][j] == 1 && !visited1[j])
			DeepFirstSearch1(G, G.Vertex[j]);
	}
}
void DFS1(Graph G)//深度遍历
{
	int i;
	for (i = 0; i < G.V; i++)
		visited1[i] = false;
	for (int i = 0; i < G.V; i++) {
		if (!visited1[i])
			DeepFirstSearch1(G, G.Vertex[i]);
	}
}

void DeepFirstSearch2(GraphLink G, char b) {//深度优先
	int i = G.GetVertex(b);
	visited2[i] = true;
	cout << G.vertextable[i].data;
	Edge *p = G.vertextable[i].list;
	while (p) {
		if (!visited2[G.GetVertex(p->des)])
			DeepFirstSearch2(G,p->des);
		p = p->link;
	}
}
void DFS2(GraphLink G) {//深度遍历
	int i;
	for (i = 0; i < G.V; i++)
		visited2[i] = false;
	for (int i = 0; i < G.V; i++) {
		if (!visited2[i])
			DeepFirstSearch2(G, G.vertextable[i].data);
	}
}

void BFS(GraphLink G) {//广度遍历
	int i;
	Edge *p;
	queue<char> Q;
	for (int i = 0; i < G.V; i++)
		visited1[i] = false;
	for (int i = 0; i< G.V; i++)
	{
		if (!visited1[i])
		{
			visited1[i] = true;
			cout << G.vertextable[i].data << " -> ";
			Q.push(G.vertextable[i].data);
			while (!Q.empty()) {
				char v = Q.front();
				Q.pop();
				int a = G.GetVertex(v);
				p = G.vertextable[a].list;
				while (p)
				{
					int k = G.GetVertex(p->des);
					if (!visited1[k]) {
						visited1[k] = true;
						cout << G.vertextable[k].data << " -> ";
						Q.push(p->des);
					}
					p = p->link;
				}
			}
		}
	}
	cout << "null";
}
void BreadthFirstPaths(GraphLink G,char a,char b) {//广度搜索最短路径
	int edgeto[SIZE];
	Edge *p;
	for (int i = 0; i < G.V; i++)
		visited3[i] = false;
	queue<char> Q;
	int i = G.GetVertex(a);
	Q.push(a);
	while (!Q.empty()) {
		char v = Q.front();
		Q.pop();
		int k = G.GetVertex(v);
		p = G.vertextable[k].list;
		while (p)
		{
			int k1 = G.GetVertex(p->des);
			if (!visited3[k1]) {
				edgeto[k1] = k;
				visited3[k1] = true;
				Q.push(p->des);
			}
			p = p->link;
		}
	}
	//has to path
	int d = G.GetVertex(b);
	if (!visited3[d])
		cout <<a<< " canot go to " << b << endl;
	else
	{
		//char res[SIZE];
		int count = 0;
		for (char x=b; x !=a; x =G.vertextable[edgeto[G.GetVertex(x)]].data) {
			//res[count] = x;
			cout<< x << "->";
		}
		cout << a;
	}
}
//************************//
struct cmp
{
	bool operator()(Edge a, Edge b) {
		return a.weight > b.weight;//小顶堆
	}
};
priority_queue < Edge, vector<Edge>, cmp> WQ;
void visit(GraphLink G,int i) {
	visited4[i] = true;
	Edge* p = G.vertextable[i].list;
	while (p)
	{
		if (!visited4[G.GetVertex(p->des)])
			WQ.push(*p);
		p = p->link;
	}
}
void LazyPrim(GraphLink G)
{
	//int edgeto[SIZE];
	//Edge* p;
	for (int i = 0; i < G.V; i++)
		visited4[i] = false;
	queue<Edge> Q;
	visit(G, 0);
	cout << "LazyPrim---" << endl;
	while (!WQ.empty()){
		Edge e = WQ.top();
		WQ.pop();
		char a = e.begin;
		char b = e.des;
		if (visited4[G.GetVertex(a)] && visited4[G.GetVertex(b)])
			continue;
		Q.push(e);
		cout << e.des << "  " << e.weight << "-> ";
		if (!visited4[G.GetVertex(a)])
			visit(G, G.GetVertex(a));
		if (!visited4[G.GetVertex(b)])
			visit(G, G.GetVertex(b));
	}
	cout << "NULL";
}
//*************************//
//vector <pair<int,int> > PQ;//由于priority_queue不支持便利 所以用vect  也可以用2个priority_queue
struct paircmp
{
	bool operator()(const pair<int, int> a, const pair<int, int> b) {
		return a.second > b.second;
	}
};
priority_queue<pair<int, int> , vector <pair<int, int> >,paircmp> PQ;
int distTo[SIZE];  //weight值
//vector<Edge> edgeTo(SIZE);  //距离树最近的边
Edge  edgeTo[SIZE];
void visit2(GraphLink G, int v) {
	visited4[v] = true;
	//cout << "--"<<v<<"--";
	Edge *p= G.vertextable[v].list;
	while (p)
	{
		char a = p->begin;
		char b = p->des;
		if (visited4[G.GetVertex(b)]){
			p = p->link;
			continue;
		}
		if (p->weight<distTo[G.GetVertex(b)])
		{
			 //更新weight
			edgeTo[G.GetVertex(b)] = *p;
			distTo[G.GetVertex(b)] = p->weight;
			bool flag = false;
			priority_queue<pair<int, int> > tmp;
			while (!PQ.empty())
			{
				int k1 = PQ.top().first;
				int k2 = PQ.top().second;
				PQ.pop();
				if (k1 == G.GetVertex(b)) {
					flag = true;
					k2 = p->weight;
				}
				tmp.push(make_pair(k1, k2));
			}
			if (!flag)
				tmp.push(make_pair(G.GetVertex(b),p->weight));
			while (!tmp.empty())
			{
				int k1 = tmp.top().first;
				int k2 = tmp.top().second;
				tmp.pop();
				PQ.push(make_pair(k1, k2));

			}
		}
		p = p->link;
	}
	
}
void PrimMST(GraphLink G)
{
	for (int i = 0; i < G.V; i++) {
		distTo[i] = 100;
	}//无限大
	distTo[0] = 0;
	PQ.push(make_pair(0,0));
	while (!PQ.empty())
	{
		int k = PQ.top().first;
		PQ.pop();
		visit2(G,k);
	}
	//showprim();
	cout << "0" <<"  edgeTo "<<" distTo "<< endl;
	for (int i = 1; i < G.V; i++)
		cout << i << "  " << edgeTo[i].begin << " -> " << edgeTo[i].des << "  " << distTo[i] << endl;
	
}
//**************************//
priority_queue < Edge, vector<Edge>, cmp> LQ;
int findcircle(int* parent, int k) {
	while (parent[k] > 0)
		k = parent[k];
	return k;
}
void KruskalMST(GraphLink G)
{
	Edge* p;
	int parent[SIZE];
	for (int i = 0; i < G.V; i++)
	{
		p = G.vertextable[i].list;
		while (p)
		{
			LQ.push(*p);
			p = p->link;
		}
	}
	int count = 0;
	while (!LQ.empty() && count < G.V - 1)
	{
		Edge ed;
		ed = LQ.top();
		LQ.pop();
		char a = ed.begin;
		char b = ed.des;
		int n = findcircle(parent, G.GetVertex(a));
		int m = findcircle(parent, G.GetVertex(b));
		if (n != m)
		{
			parent[n] = m;
			cout << a << "  " << b << "  " << ed.weight << endl;
		}

	}
}

