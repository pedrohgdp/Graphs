#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <queue>


#define SEMCOR -1

using namespace std;

// usando STL para representar grafos

// o par.first -> vértice u, par.second -> peso da aresta
typedef pair<int, int> ii;   

// um vetor de pares
typedef vector<ii> vii;

// vetor apenas. uso genérico... marcar visitados, etc..
typedef vector<int> vi;

// a lista de adjacencia é um vetor de vetor de pares
// seja um vertice (u,v)
// first representa v, e second o peso da aresta !!
// u é cada item do vetor AdjList !! 
vector<vii> AdjList(100);

// um vetor de vértices
vi cor;

void printAdjList(int n){
	for (int i = 0; i < n; ++i) // para todos os vértices
	{
		printf("%d -> ", i+1);
		for (int j = 0; j < AdjList[i].size(); ++j)
		{	if (j < AdjList[i].size()-1)
				printf("(%d,%d) > ", AdjList[i][j].first+1, AdjList[i][j].second);
			else 	printf("(%d,%d)", AdjList[i][j].first+1, AdjList[i][j].second);
		}
		printf("\n");
	}
}

bool bipartite(int u, int n){
	queue<int> q;

	cor[u] = 0; // comecaremos com a cor 0
	q.push(u);  // coloca u na fila.....

	while (!q.empty()) {

		int k = q.front(); q.pop(); // retira o vertice k da fila...

		for (int i = 0; i < AdjList[k].size(); ++i) // para todos adj v de k
		{
			ii v = AdjList[k][i]; // aqui v é um par...
			if (cor[v.first] == SEMCOR){
				cor[v.first] = 1-cor[k];
				q.push(v.first);
			}
			else if (cor[v.first] == cor[k])
				return false;
		}
	}
	return true;
}


int main(int argc, char const *argv[]) {
	int m, n;
	cin >> n >> m;
	int u, v;

	// marca todos como não visitados..
	for (int i = 0; i < n; ++i)
		cor.push_back(SEMCOR);

	// agora le as arestas e coloca na lista e adjacencia
	while (m--) { // o grafo é direcionado e arestas nao tem peso!
		cin >> u >> v;
		AdjList[u-1].push_back(make_pair(v-1,0));
		AdjList[v-1].push_back(make_pair(u-1,0));
	}

	printAdjList(n);
	
	if (bipartite(0, n)) {
		printf("eh");
	} else {
		printf("n eh");
	}

	return 0;
}