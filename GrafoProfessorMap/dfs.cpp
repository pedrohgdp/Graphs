#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

// par de inteiros: guarda o vertice v e o peso da aresta
typedef pair<int,int> ii;

// todos os vertices v adjacentes a u 
typedef vector<ii> vii;

// lista de adjacencia para todo vertice u do meu grafo..
vector<vii> AdjList(200);

typedef vector<int> vi;

#define VISITADO 1
#define NAOVISITADO 0


int nv;

vi vis;


void printAdjList(){
	for (int u = 0; u < nv; ++u){ // para todo vertice u
		printf("%d -> ", u);
		for (int i = 0; i < AdjList[u].size(); ++i) { // para todo adjacente v de u
			ii v = AdjList[u][i];
			printf("(%d, %d) -> ", v.first, v.second);
		}
		printf("\n");
	}
}

void dfs(int u){
	printf("%d ", u+1);
	vis[u] = VISITADO;

	for (int i = 0; i < AdjList[u].size(); ++i) { // para todo adjacente v de u
		ii v = AdjList[u][i];
		if (vis[v.first] == NAOVISITADO){
			dfs(v.first);
		}
	}
}


int main(int argc, char const *argv[]){

	int ar;
	cin >> nv >> ar;

	

	int u,v;

	vis.assign(nv, NAOVISITADO);  // inicio vetor de visitados livre...

	while (ar--){  // leia todas as arestas..
		cin >> u >> v;
		// porque o grafo eh nao direcionado...
		AdjList[u-1].push_back(make_pair(v-1, 0));
		AdjList[v-1].push_back(make_pair(u-1, 0));
	}

	printAdjList();


	dfs(0); printf("\n");

	return 0;
}

