// Graph.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <functional>
#include <stack>
#include <queue>
#include <map>

using namespace std;

class Graph
{
public:

};

class MyNet :public Graph
{
public:

};

class MyGraph :public Graph
{
public:
	// 判断无向图是否有环
	static void dfs_hasLoop(vector<vector<int>>& source, vector<bool>& visited, int curPoint, bool& hasLoop)
	{
		if (curPoint >= source.size())
		{
			;
		}
		stack<int> myStack;
		myStack.push(curPoint);
		visited[curPoint] = true;


		while (!myStack.empty())
		{
			int tmpPoint = myStack.top();
			bool hasChildFlag = false;
			for (int i = 0; i < source.size(); i++)
			{
				if ((visited[i] == false) && (source[tmpPoint][i] != 0))
				{
					myStack.push(i);
					visited[i] = true;

					hasChildFlag = true;

					break;
				}
				else if ((visited[i] == true) && (source[tmpPoint][i] != 0))
				{
					hasLoop = true;
					return;
				}
			}
			if (hasChildFlag == false)
			{

				myStack.pop();
			}
		}
	}

	// 无向图的深度遍历
	static void dfs_recurse(vector<vector<int>>& source, vector<bool>& visited, int curPoint, vector<int>& ans)
	{
		if (curPoint >= source.size())
		{
			;
		}
		visited[curPoint] = true;
		ans.push_back(curPoint + 1);

		for (int i = 0; i < source.size(); i++)
		{
			if ((visited[i] == false) && (source[curPoint][i] != 0))
			{
				dfs_recurse(source, visited, i, ans);
			}
		}
	}

	// 无向图深度遍历的非递归做法
	static void dfs_stack(vector<vector<int>>& source, vector<bool>& visited, int curPoint, vector<int>& ans)
	{
		if (curPoint >= source.size())
		{
			;
		}
		stack<int> myStack;
		myStack.push(curPoint);
		visited[curPoint] = true;
		ans.push_back(curPoint + 1);

		while (!myStack.empty())
		{
			int tmpPoint = myStack.top();
			bool hasChildFlag = false;
			for (int i = 0; i < source.size(); i++)
			{
				if ((visited[i] == false) && (source[tmpPoint][i] != 0))
				{
					myStack.push(i);
					visited[i] = true;
					ans.push_back(i + 1);
					hasChildFlag = true;

					break;
				}
			}
			if (hasChildFlag == false)
			{
				myStack.pop();
			}
		}
	}

	// 无向图深度遍历的非递归做法 深度优先生成树
	static void dfs_stack_spanningTree(vector<vector<int>>& source, vector<bool>& visited, int curPoint,
		vector<int>& ans, multimap<int, int>& route)
	{
		if (curPoint >= source.size())
		{
			;
		}
		stack<int> myStack;
		myStack.push(curPoint);
		visited[curPoint] = true;
		ans.push_back(curPoint + 1);

		while (!myStack.empty())
		{
			int tmpPoint = myStack.top();
			bool hasChildFlag = false;
			for (int i = 0; i < source.size(); i++)
			{
				if ((visited[i] == false) && (source[tmpPoint][i] != 0))
				{
					myStack.push(i);
					visited[i] = true;
					ans.push_back(i + 1);
					route.insert(pair<int, int>(tmpPoint, i));
					hasChildFlag = true;

					break;
				}
			}
			if (hasChildFlag == false)
			{
				myStack.pop();
			}
		}
	}

	// 无向图广度遍历  
	// 可以解决从A点到B点的边数最小问题
	static void bfs(vector<vector<int>>& source, vector<bool>& visited, int curPoint, vector<int>& ans)
	{
		if (curPoint >= source.size())
		{
			;
		}
		queue<int> myQueue;
		myQueue.push(curPoint);
		ans.push_back(curPoint + 1);
		visited[curPoint] = true;
		while (!myQueue.empty())
		{
			int tmpPoint = myQueue.front();
			myQueue.pop();
			for (int i = 0; i < source.size(); i++)
			{
				if ((visited[i] == false) && (source[tmpPoint][i] == 1))
				{
					myQueue.push(i);
					ans.push_back(i + 1);
					visited[i] = true;
				}
			}
		}
	}


	// 无向图广度遍历  广度优先生成树
	static void bfs_spanningTree(vector<vector<int>>& source, vector<bool>& visited, int curPoint, vector<int>& ans,
		multimap<int, int>& route)
	{
		if (curPoint >= source.size())
		{
			;
		}
		queue<int> myQueue;
		myQueue.push(curPoint);
		ans.push_back(curPoint + 1);
		visited[curPoint] = true;
		while (!myQueue.empty())
		{
			int tmpPoint = myQueue.front();
			myQueue.pop();
			for (int i = 0; i < source.size(); i++)
			{
				if ((visited[i] == false) && (source[tmpPoint][i] == 1))
				{
					myQueue.push(i);
					ans.push_back(i + 1);
					route.insert(pair<int, int>(tmpPoint, i));
					visited[i] = true;
				}
			}
		}
	}
};

class DirectionNet :public MyNet
{
public:
	// Dijstra算法
	static vector<int> getShortestPath_DIJ(vector<vector<int>> myGraph, int curVex)
	{
		vector<int> hadShortestNode(myGraph.size(), false);
		vector<int> distanceVec(myGraph[curVex].begin(), myGraph[curVex].end());

		//for (int i = 0; i < myGraph.size(); i++)
		//{
		//	myGraph[i][i] = 0;
		//}

		distanceVec[curVex] = 0;
		hadShortestNode[curVex] = true;  // 初始化，v0顶点属于S集合

		unsigned int minDistance = INT_MAX;
		for (int i = 1; i < myGraph.size(); i++)
		{
			unsigned minDistance = INT_MAX;
			int adjVex = -1;
			for (int j = 0; j < myGraph.size(); j++)
			{
				if (hadShortestNode[j] == false)  // j顶点在V-S中
				{
					if (distanceVec[j] < minDistance /*&& distanceVec[j]!=0*/)
					{
						adjVex = j;
						minDistance = distanceVec[j];
					}
				}
			}
			if (adjVex == -1)
			{
				return distanceVec;
			}
			hadShortestNode[adjVex] = true; // 离v0顶点最近的adjVex加入S集合
			for (int w = 0; w < myGraph.size(); w++)
			{
				if ((hadShortestNode[w] == false) && (minDistance + myGraph[adjVex][w] < distanceVec[w]))
				{
					distanceVec[w] = minDistance + myGraph[adjVex][w];
				}
			}
		}
		return distanceVec;
	}

	static vector<int> getTopologicalSort(vector<vector<int>> myGraph)
	{
		//有向图采用邻接表存储结构
		//若有环，返回空的vector<int>;否则返回一个拓扑排序
		vector<int> inDegreeVec(myGraph.size(), -1);
		for (int i = 0; i < inDegreeVec.size(); i++)
		{
			inDegreeVec[i] = getIndegree(myGraph, i);
		}

		vector<int> topologicalSortVec;
		int countVex = myGraph.size();
		while (countVex > 0)
		{
			for (int i = 0; i < inDegreeVec.size(); i++)
			{
				if (inDegreeVec[i] == 0)
				{
					countVex--;
					topologicalSortVec.push_back(i);
					inDegreeVec[i] = -1;
					for (int j = 0; j < myGraph.size(); j++)
					{
						if (myGraph[i][j] != 0)
						{
							inDegreeVec[j]--;
						}
					}
					break;
				}
			}
		}

		return topologicalSortVec;

	}
	static vector<vector<int>> createDirectionNet(vector<vector<int>> edges, int nodes)
	{
		vector<vector<int>> ans(nodes, vector<int>(nodes, INT_MAX));
		for (int i = 0; i < edges.size(); i++)
		{
			if (edges[i].size() != 3)
			{
				throw runtime_error("数组长度不对！");
			}
			ans[edges[i][0]][edges[i][1]] = edges[i][2];
		}
		return ans;
	}

	static multimap<int, int> getCriticalPath(vector<vector<int>> myGraph, vector<vector<int>> edges)
	{
		vector<int> criticalPath;
		multimap<int, int> route;

		vector<int> vecEarly = getEarliestCompleteTaskTime(myGraph);
		vector<int> vecLatest(vecEarly.begin(), vecEarly.end());

		int countVex = myGraph.size();
		stack<int> topologicalOrderStack;
		vector<int> topologicalOrder = getTopologicalSort(myGraph);
		for (int i = 0; i < topologicalOrder.size(); i++)
		{
			topologicalOrderStack.push(topologicalOrder[i]);
		}
		while (!topologicalOrderStack.empty())
		{
			int _curNode = topologicalOrderStack.top();
			topologicalOrderStack.pop();
			for (int i = 0; i < myGraph.size(); i++)
			{
				if (myGraph[i][_curNode] != 0)
				{
					if (vecLatest[_curNode] - myGraph[i][_curNode] > vecLatest[i])
					{
						vecLatest[i] = vecLatest[_curNode] - myGraph[i][_curNode];
					}
				}
			}
		}

		vecLatest[topologicalOrder[0]] = 0;

		for (int i = 0; i < myGraph.size(); i++)
		{
			if (vecLatest[i] == vecEarly[i])
			{
				criticalPath.push_back(i);
			}
		}

		int firstNode = topologicalOrder[0];

		bool hasChild = true;

		for (int i = 0; i < edges.size(); i++)
		{
			if ((vexContain(criticalPath, edges[i][0])) && (vexContain(criticalPath, edges[i][1])))
			{
				if ((vecLatest[edges[i][0]] + myGraph[edges[i][0]][edges[i][1]] == vecLatest[edges[i][1]]) || (vecLatest[edges[i][0]] - myGraph[edges[i][0]][edges[i][1]] == vecLatest[edges[i][1]]))
				{
					route.insert(pair<int, int>(edges[i][0], edges[i][1]));

				}
			}
		}

		return route;
	}
private:
	static bool vexContain(vector<int> source, int index)
	{
		bool ans = false;
		for (int i = 0; i < source.size(); i++)
		{
			if (source[i] == index)
			{
				ans = true;
				break;
			}
		}
		return ans;
	}
	static int getOutdegree(const vector<vector<int>>& myGraph, int curVex)
	{
		int countDegree = 0;
		for (int i = 0; i < myGraph.size(); i++)
		{
			if (myGraph[curVex][i] != 0)
			{
				countDegree++;
			}
		}
		return countDegree;
	}
	static int getIndegree(const vector<vector<int>>& myGraph, int curVex)
	{
		int countDegree = 0;
		for (int i = 0; i < myGraph.size(); i++)
		{
			if (myGraph[i][curVex] != 0)
			{
				countDegree++;
			}
		}
		return countDegree;
	}
public:
	// AOV-网求项目最早完工时间
	static vector<int> getEarliestCompleteTaskTime(vector<vector<int>> myGraph)
	{

		//有向图采用邻接表存储结构
		//若有环，返回空的vector<int>;否则返回一个拓扑排序
		vector<int> vecEarly(myGraph.size(), 0);

		vector<int> inDegreeVec(myGraph.size(), -1);
		for (int i = 0; i < inDegreeVec.size(); i++)
		{
			inDegreeVec[i] = getIndegree(myGraph, i);
		}

		vector<int> topologicalSortVec;
		int countVex = myGraph.size();
		while (countVex > 0)
		{
			for (int i = 0; i < inDegreeVec.size(); i++)
			{
				if (inDegreeVec[i] == 0)
				{
					countVex--;
					topologicalSortVec.push_back(i);
					inDegreeVec[i] = -1;
					for (int j = 0; j < myGraph.size(); j++)
					{
						if (myGraph[i][j] != 0)
						{
							inDegreeVec[j]--;

							// 求最早时间序列
							if (vecEarly[i] + myGraph[i][j] > vecEarly[j])
							{
								vecEarly[j] = vecEarly[i] + myGraph[i][j];
							}
						}

					}

					break;
				}
			}
		}
		return vecEarly;
	}
};


class DirectionGraph :public Graph
{
public:


	static vector<int> getTopologicalSort(vector<vector<int>> myGraph)
	{
		//有向图采用邻接表存储结构
		//若有环，返回空的vector<int>;否则返回一个拓扑排序
		vector<int> inDegreeVec(myGraph.size(), -1);
		for (int i = 0; i < inDegreeVec.size(); i++)
		{
			inDegreeVec[i] = getIndegree(myGraph, i);
		}

		vector<int> topologicalSortVec;
		int countVex = myGraph.size();
		while (countVex > 0)
		{
			for (int i = 0; i < inDegreeVec.size(); i++)
			{
				if (inDegreeVec[i] == 0)
				{
					countVex--;
					topologicalSortVec.push_back(i);
					inDegreeVec[i] = -1;
					for (int j = 0; j < myGraph.size(); j++)
					{
						if (myGraph[i][j] != 0)
						{
							inDegreeVec[j]--;
						}
					}
					break;
				}
			}
		}

		return topologicalSortVec;

	}
	static vector<vector<int>> createDirectionGraph(vector<vector<int>> edges, int nodes)
	{
		vector<vector<int>> ans(nodes, vector<int>(nodes, 0));
		for (int i = 0; i < edges.size(); i++)
		{
			if (edges[i].size() != 2)
			{
				throw runtime_error("数组长度不对！");
			}
			//ans[1][1] = 100;
			int _row = edges[i][0];
			int _col = edges[i][1];
			ans[_row][_col] = 1;
		}
		return ans;
	}


private:
	static int getOutdegree(const vector<vector<int>>& myGraph, int curVex)
	{
		int countDegree = 0;
		for (int i = 0; i < myGraph.size(); i++)
		{
			if (myGraph[curVex][i] != 0)
			{
				countDegree++;
			}
		}
		return countDegree;
	}
	static int getIndegree(const vector<vector<int>>& myGraph, int curVex)
	{
		int countDegree = 0;
		for (int i = 0; i < myGraph.size(); i++)
		{
			if (myGraph[i][curVex] != 0)
			{
				countDegree++;
			}
		}
		return countDegree;
	}

};

class UnDirectionNet :public MyNet
{
private:
	struct CloseEdge
	{
		int adjvec;
		int lowcost;

		CloseEdge()
		{
			this->adjvec = 0;
			this->lowcost = 0;
		}
	};
public:
	vector<vector<int>> createUnDirectionNet(vector<vector<int>> edges, int nodes)
	{
		vector<vector<int>> ans(nodes, vector<int>(nodes, INT_MAX));
		for (int i = 0; i < edges.size(); i++)
		{
			if (edges[i].size() != 3)
			{
				throw runtime_error("数组长度不对！");
			}
			ans[edges[i][0]][edges[i][1]] == edges[i][2];
			ans[edges[i][1]][edges[i][0]] == edges[i][2];
		}
		return ans;
	}

	static multimap<int, int> getMiniSpanTree_PRIM(vector<vector<int>>& myGraph, int curPoint)
	{
		vector<CloseEdge> minCostVec(myGraph.size());

		multimap<int, int> ans;

		// 辅助数组初始化
		for (int i = 0; i < myGraph.size(); i++)
		{
			if (i != curPoint)
			{
				minCostVec[i].adjvec = curPoint;
				minCostVec[i].lowcost = myGraph[curPoint][i];
			}
		}

		minCostVec[curPoint].lowcost = 0;
		int curNode = curPoint;
		for (int i = 1; i < myGraph.size(); i++)
		{
			int k = getMinCostVecIndex(minCostVec);
			ans.insert(pair<int, int>(minCostVec[k].adjvec, k));
			minCostVec[k].lowcost = 0;
			curNode = k;

			for (int j = 0; j < myGraph.size(); j++)
			{
				if (myGraph[curNode][j] < minCostVec[j].lowcost)
				{
					minCostVec[j].adjvec = curNode;
					minCostVec[j].lowcost = myGraph[curNode][j];
				}
			}
		}
		return ans;
	}
private:
	static int getMinCostVecIndex(vector<CloseEdge> closedge)
	{
		int index = -1;
		int minNum = INT_MAX;
		for (int i = 0; i < closedge.size(); i++)
		{
			if (closedge[i].lowcost != 0 && closedge[i].lowcost < minNum)
			{
				index = i;
				minNum = closedge[i].lowcost;
			}
		}

		return index;
	}
};

class UnDirectionGraph :public MyGraph
{
public:

};

int main_UnDirectionGraph_dfs_hasLoop()
{
	vector<vector<int>> sourceGraph{ {0,1,0,1,0},
	{1,0,1,0,1},
	{0,1,0,1,1},
	{1,0,1,0,0},
	{0,1,1,0,0} };

	//vector<vector<int>> sourceGraph{ {INT_MAX,6,1,5,INT_MAX,INT_MAX},
	//								{6,INT_MAX,5,INT_MAX,3,INT_MAX},
	//								{1,5,INT_MAX,5,6,4},
	//								{5,INT_MAX,5,INT_MAX,INT_MAX,2},
	//								{INT_MAX,3,6,INT_MAX,INT_MAX,6},
	//{INT_MAX,INT_MAX,4,2,6,INT_MAX} };

	vector<bool> visited(sourceGraph.size(), false);
	vector<int>  ans;

	//UnDirectionGraph::dfs_recurse(sourceGraph, visited, 0,ans);
	//UnDirectionGraph::dfs_stack(sourceGraph, visited, 0, ans);
	//UnDirectionGraph::bfs(sourceGraph, visited, 0, ans);

	bool hasLoop = false;
	UnDirectionGraph::dfs_hasLoop(sourceGraph, visited, 0, hasLoop);
	cout << boolalpha << hasLoop << endl;

	//for (auto item : ans)
	//{
	//	cout << item << endl;
	//}

	//multimap<int, int> spanningTree;
	////UnDirectionGraph::dfs_stack_spanningTree(sourceGraph, visited, 0, ans, spanningTree);
	////UnDirectionGraph::bfs_spanningTree(sourceGraph, visited, 0, ans, spanningTree);
	//spanningTree = UnDirectionNet::getMiniSpanTree_PRIM(sourceGraph,0);
	//for (multimap<int, int>::iterator it = spanningTree.begin(); it != spanningTree.end(); it++)
	//{
	//	cout << it->first << " " << it->second << endl;
	//}

	system("pause");
	return 0;
}

int main_DirectionGraph_getTopologicalSort()
{
	vector<vector<int>> edges{ {0,1},{0,3},{5,3},{5,4},{0,2},{3,4},{2,1},{2,4} };

	vector<vector<int>> myGraph = DirectionGraph::createDirectionGraph(edges, 6);
	vector<int> ans = DirectionGraph::getTopologicalSort(myGraph);

	for (auto item : ans)
	{
		cout << item << endl;
	}


	system("pause");
	return 0;
}
int main/*_DirectionNet_Djistra*/()
{
	vector<vector<int>> edges{ {0,2,10},{0,4,30},{0,5,100},{1,2,5},{2,3,50},
								{3,5,10},{4,3,20},{4,5,60} };

	vector<vector<int>> myGraph = DirectionNet::createDirectionNet(edges, 6);
	vector<int> ans = DirectionNet::getShortestPath_DIJ(myGraph, 0);

	for (auto item : ans)
	{
		cout << item << endl;
	}


	system("pause");
	return 0;
}
// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
