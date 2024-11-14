#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;



int AdjMat[200][200];

// par de inteiros: guarda o vertice v e o peso da aresta
typedef pair<int,int> ii;

// todos os vertices v adjacentes a u 
typedef vector<ii> vii;

// lista de adjacencia para todo vertice u do meu grafo..
vector<vii> AdjList(200);

typedef vector<int> vi;

//#define VISITADO 1
//#define NAOVISITADO 0
#define INF 10000000

int nv;


void printAdjList(){
	for (int u = 0; u < nv; ++u){ // para todo vertice u
		printf("%d -> ", u+1);
		for (int i = 0; i < AdjList[u].size(); ++i) { // para todo adjacente v de u
			ii v = AdjList[u][i];
			printf("(%d, %d) -> ", v.first+1, v.second);
		}
		printf("\n");
	}
}

void bfs(int u){
	queue<int> q;

	vi vis(nv,INF);
	vis[u] = 0; // a distancia de u para u eh zero.
	q.push(u); 

	while(!q.empty()){
		int k = q.front(); q.pop();
		printf("%d ", k+1);

		for (int i = 0; i < AdjList[k].size(); ++i) { // para todo adjacente v de u
			ii v = AdjList[k][i];
			if (vis[v.first] == INF){
				vis[v.first] = vis[k] + 1;  // o nivel do adj v eh o do pai k + 1
				//vis[v.first] = VISITADO;  // o nivel do adj v eh o do pai k + 1
				q.push(v.first);  // coloca o adj na fila...
			}
		}
	}

}


int main(int argc, char const *argv[])
{
	int ar;
	cin >> nv >> ar;
	int u,v;

	//vis.assign(nv, NAOVISITADO);  // inicio vetor de visitados livre...

	while (ar--){  // leia todas as arestas..
		cin >> u >> v;
		// porque o grafo eh nao direcionado...
		AdjList[u-1].push_back(make_pair(v-1, 0));   // eh um grafo sem peso...
		AdjList[v-1].push_back(make_pair(u-1, 0));   // eh um grafo sem peso...
	}

	printAdjList();

	bfs(0); printf("\n");

	return 0;
}

