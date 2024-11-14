#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>

#define VISITADO 1
#define NAOVISITADO 0

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
vi vertices;
vi ot;

int n; // numero de vertices do grafo...

void printAdjList(){
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
	printf("\n");
}

void ordtopRec(int u){
	vertices[u] = VISITADO; // marca como visitado
	//printf("%d ", u);

	for (int i = 0; i < AdjList[u].size(); ++i) // para todos adj v de u
	{
		ii v = AdjList[u][i]; // aqui v é um par...
		if (vertices[v.first] == NAOVISITADO)
			ordtopRec(v.first);
	}
	ot.push_back(u);
}

void ordtop(){
	for (int i = 0; i < n; ++i) // para todos os vértices
	{
		if (vertices[i] == NAOVISITADO ){
			ordtopRec(i);
		}
	}
}

int main(int argc, char const *argv[]) {
	int m;
	cin >> n >> m;
	int u, v;

	// marca todos como não visitados..
	for (int i = 0; i < n; ++i)
		vertices.push_back(NAOVISITADO);

	// agora le as arestas e coloca na lista e adjacencia
	while (m--) { // o grafo é direcionado e arestas nao tem peso!
		cin >> u >> v;
		AdjList[u-1].push_back(make_pair(v-1,0));
	}

	printAdjList();
	ordtop();

	for (int i = ot.size()-1; i >=0; i--)
		printf("%d ", ot[i]+1);

	return 0;
}