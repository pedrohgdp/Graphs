#include <bits/stdc++.h>
using namespace std;
#define INF 10000000

//Criando tipos
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

void printList(vector<vii> &listaAdj, int nv){
    for(int u = 0; u < nv; u++){
        printf("%d --> ", u + 1);
        for(int i = 0; i < listaAdj[u].size(); i++){
            ii v = listaAdj[u][i];
            printf("(%d, %d) --> ", v.first + 1, v.second);
        }
        cout << endl;
    }
}


void bfs(int u, int nv, vector<vii> &listaAdj, vi &vis){
    //criamos a fila
    queue<int> q;
    //marcamos o visitados como 0 na posição 0
    vis[u] = 0;
    //botamos u na fila
    q.push(u);
    //enquanto a fila não estiver vazia
    while(!q.empty()){
        //K recebe o u que estava na fila e tiramos o u da fila
        int k = q.front();
        q.pop();
        cout << k + 1 << " ";
        for(int i = 0; i < listaAdj[k].size(); i++){
            //criação de v normal
            ii v = listaAdj[k][i];
            //Se vis na posição v.first ( primeiro valor o isezimo vertice adjacente a u ( nesse caso k )) não foi visitado
            if(vis[v.first] == INF){
                //O valor no visitado da vez recebe o valor do pai dele + 1 
                //No caso da priimeira vez rodando o codigo 0 + 1
                vis[v.first] = vis[k] + 1;
                //Adicionamos v.first na fila
                q.push(v.first);
            }
        }
    }
}




int main(){
    //Iniciamos a lista
    vector<vii> listaAdj(200);
    //Criamos e lemos numero de vetores e quantidade arestas
    int nv, arr;
    cin >> nv >> arr;
    //Criamos vetor u e v e o vetor de visitados com numero de vetores e tudo infinito
    int u, v;
    vi vis(nv, INF);

    while(arr--){
        cin >> u >> v;
        listaAdj[u - 1].push_back(make_pair(v - 1, 0));
        listaAdj[v - 1].push_back(make_pair(u - 1, 0));
    }

    printList(listaAdj, nv);

    bfs(0, nv, listaAdj, vis);
    printf("\n");

    return 0;
}