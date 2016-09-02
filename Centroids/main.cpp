#include <iostream>
#include <vector>
#include <stack>
#include <list>
#include <iomanip>

using namespace std;

class Node;

class AdjList
{
public:
	list<Node*> ls;
};

class Node
{
public:
	int index;
	AdjList adj;
	bool is_visited;
};

class Graph
{
public:
	Graph(){};
	vector<Node *> v;
	int n;
};

Graph readInputs()
{
	Graph g;
	cin >> g.n;

	for(int i = 0; i < g.n; i++)
	{
		Node* temp = new Node;
		temp->index = i;
		temp->is_visited = false;
		g.v.push_back(temp);
	}

	for(int i = 0; i < g.n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		g.v[u-1]->adj.ls.push_back(g.v[v-1]);
		g.v[v-1]->adj.ls.push_back(g.v[u-1]);
	}

	return g;
}

void displayGraph(Graph g)
{
	for(int i = 0; i < g.n; i++)
	{
		cout << "Node:" << setw(5) << g.v[i]->index << endl;
		cout << "Adjacency List:" << endl;
		list<Node*>::iterator itr = g.v[i]->adj.ls.begin();
		while(itr != g.v[i]->adj.ls.end())
		{
			cout << setw(5) << (**itr).index;
			++itr;
		}
		cout << endl;
	}
}

int dfs(Graph g, Node* src)
{
	int ret = 0;
	stack<Node*> s;
	s.push(src);
	while(!s.empty())
	{
		Node* p = s.top();
		s.pop();
		list<Node*>::iterator itr = p->adj.ls.begin();
		while(itr != p->adj.ls.end())
		{
			cout << "Visited:" << setw(5) << (*itr)->index;
			cout << boolalpha << setw(10) << (*itr)->is_visited << endl;
			if(!(**itr).is_visited)
				s.push(*itr);
			++itr;
		}
		g.v[p->index]->is_visited = true;
		ret++;
	}
	return ret;
}

void scc(Graph g)
{
	for(int i = 0; i < g.n; i++)
	{
		if(g.v[i]->is_visited)
			continue;
		int scc_len = dfs(g, g.v[i]);
		cout << "SCC Root:" << setw(5) << g.v[i]->index << endl;
		cout << "SCC Length:" << setw(5) << scc_len << endl;
	}
}

void testRef(){
	list<Node*> l;
	Node* x = new Node;
	x->index = 5;
	x->is_visited = true;

	l.push_back(x);

	x->index = 10;
	x->is_visited = false;

	Node* y = l.front();
	cout << setw(5) << y->index << setw(10) << boolalpha << y->is_visited << endl;
}

int main()
{
	Graph g = readInputs();
	displayGraph(g);

	 scc(g);
//	testRef();

	return(0);
}
