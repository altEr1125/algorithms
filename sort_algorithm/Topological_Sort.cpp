//拓扑排序
#include<list>
#include <vector>
#include <iostream>
class Graph {
	int v;	//总边数
	std::list<int>* adj;//邻接表
	std::vector<int> q;//度为0的vector
	int* indegree;//记录每个顶点的入度
public:
	Graph(int v);//构造函数
	~Graph();//析构函数
	void addEdge(int v, int w);//添加边
	bool topological_sort();//拓扑排序
};

Graph::Graph(int v) {
	this->v = v;
	adj = new std::list<int>[v];
	indegree = new int[v];//入度全部初始化为0
	for (int i = 0; i < v; ++i)
		indegree[i] = 0;
}

Graph::~Graph() {
	delete[]adj;
	delete[]indegree;
}

void Graph::addEdge(int v, int w) {
	adj[v].push_back(w);
	++indegree[w];
}

bool Graph::topological_sort() {
	int flag = -1;
	for (int i = 0; i < v; i++)
		if (indegree[i] == 0) {
			q.push_back(i);//将所有入度为0的顶点入度
			flag = 0;
		}
	while (flag>=0) {
		std::list<int>::iterator beg = adj[q[flag]].begin();
		for (; beg != adj[q[flag]].end(); beg++)
			if (!(--indegree[*beg]))
				q.push_back(*beg);
		flag++;
		if (flag == q.size()||q.size()==v)
			break;
	}
	if (q.size() < v)
		return false;
	else {
		for (int i = 0; i < v; i++)
			std::cout << q[i] << " ";
		return true;
	}
}
int main(){
	Graph g(6);   // 创建图
	g.addEdge(5, 2);
	g.addEdge(5, 0);
	g.addEdge(4, 0);
	g.addEdge(4, 1);
	g.addEdge(2, 3);
	g.addEdge(3, 1);
	g.topological_sort();
	return 0;
}