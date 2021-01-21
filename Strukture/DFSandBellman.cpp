#include <iostream>
#include <stack>
#include <algorithm>
#include <ctime>
#include <vector>
using namespace std;
vector<int> out(100);
vector<bool> used(100);
vector<int> in(100); int n = 100; int m = 0;
int INF = 99999999;
int s = 0;
class graph
{
private:
	struct edges {
		int first, second, cost;
		edges(int first1, int second2, int cost3) {
			first = first1;
			second = second2;
			cost = cost3;
		}
	};
	struct content
	{
		int data;
		vector<content*> adjacentvertices;
		vector<int> distance;
		content(int dat)
		{
			data = dat;
		}
		~content()
		{
			adjacentvertices.clear();
			distance.clear();
			data = NULL;
		}
	};
	vector<content*> peak;
	content* art;
	edges* ert;
	vector<edges*>structed;
public:
	graph()
	{
		art = NULL;
	};
	void insert(int N)
	{
		for (int i = 0; i < N;i++) {
			peak.push_back(push(i));
		}
		for (int i = 0; i < N;i++) {
			connect(i);
		}
		m = structed.size();
	}
	void dfsout(int N)
	{
		int distancetime = 0;
		art = peak[0];
		used[0] = 1;
		dfs(art, distancetime, used, in, out);
		cout << endl;
		cout << "Max value cost" << distancetime;
		cout << endl;
	}
	void FordBellman(int v, int nodesCount, int edgesCount) {
		vector<int> d(nodesCount, INF);
		d[v] = 0;
		for (int i = 0; i < nodesCount - 1; ++i)
			for (int j = 0; j < edgesCount; ++j)
				if (d[structed[j]->first] < INF)
					d[structed[j]->second] =
					min(
						d[structed[j]->second],
						d[structed[j]->first] + structed[j]->cost
					);
		cout << "belman Out";
	}
private:
	content* push(int dat)
	{
		art = new content(dat);
		return art;
	}
	void connect(int dat) {
		art = peak[dat];
		for (int i = 0;i < rand() % 4 + 1;i++) { // рандомный выбор количества смежных вершин от 1 до 4
				int j = rand() % (peak.size()); // выбирается рандомная вершина
			bool flag = 0;
			for (int y = 0; y < (art->adjacentvertices.size());y++)
			{
				if (peak[j] == (art->adjacentvertices[y])) { // проверка на дубликат вершин
						flag = 1;
				}
			}
			if (!flag) {
				art->adjacentvertices.push_back(peak[j]);
				art->distance.push_back(rand() % 2);//рандомный вес ребра
				ert = new edges(dat, peak[j]->data, art -> distance.back());
				structed.push_back(ert);

			}
		}
	}
	void dfs(content *art1, int &timer, vector<bool>& used, vector<int>& in, vector<int>&
		out) //обход графа в глубину
	{
		used[(art1->data)] = 1;
		in[art1->data] = timer;
		for (int i = 0; i < art1->adjacentvertices.size();i++) {
			if (!used[get(art1, i)])
			{
				timer = timer + (art1->distance[i]);
				dfs((art1->adjacentvertices[i]), timer, used, in, out);
			}
		}
		out[(art1->data)] = timer;
	}
	int get(content *ar, int i) {
		int val = 0;
		ar = ar->adjacentvertices[i];
		val = ar->data;
		return val;
	}
};
int main() {
	graph raph;
	int n = 100;
	cout << n << '\n';
	raph.insert(100);
	unsigned int start_time = clock();
	raph.dfsout(100);
	start_time = clock() - start_time;
	cout << "TimeDFS:" << start_time << '\n';
	start_time = clock();
	raph.FordBellman(s, n, m);
	start_time = clock() - start_time;
	cout << "TimeBelman:" << start_time << '\n';
	cout << "Hello World!\n";
}