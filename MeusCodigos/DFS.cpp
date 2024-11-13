#include <bits/stdc++.h>
using namespace std;
#define VISITADO 1
#define NAOVISITADO 0


//Vamos criar umas sequencias de typedefs, para definirmos alguns tipos
typedef pair<int, int> ii; //Par de inteiros
typedef vector<ii> vii; //Vetor de pares de inteiros onde vamos guardar os vertices adjacentes a u
typedef vector<int> vi; //vetor de inteiros


void printar_lista_adjacencia(vector<vii> &listaAdjacencia, int numerosVertices){
    //Para todo u no nosso vetor de par de vertices
    for(int u = 0; u < numerosVertices; u++){
        cout << u + 1 << " --> ";
        //Para cada item da lista de adjacencia na posição u
        for(int i = 0; i < listaAdjacencia[u].size(); i++){
            //A gente cria um pair v que para cada U ( vertices do nosso grafo ) ele vai andar por todos os pares ( vertices / pesoa da aresta ) que aquele U aponta
            //Exemplo 1 liga com 2 com 3 e com 4
            //Aqui ele no 1 vai andar: i = 0 vai ser 2 / i = 1 vai ser 3 / i = 2 vai ser 4
            //E o desenho da lista que a gente fez
            //com v.first a gente pega o primeiro valor do par i que estamos
            //v.second pegamos o segundo valor ( o peso ) do par i que estamos 
            //sendo esse par dentro do u;;
            ii v = listaAdjacencia[u][i];
            printf("(%d, %d) --> ", v.first + 1, v.second);
        }
        cout << endl;
    }
}

void dfs(int u, vector<vii> &listaAdjacencia, vi &visitados){
    printf("%d ", u+1);
    visitados[u] = VISITADO;
    for(int i = 0; i < listaAdjacencia[u].size(); i++){
        ii v = listaAdjacencia[u][i];
        if(visitados[v.first] == NAOVISITADO){
            dfs(v.first, listaAdjacencia, visitados);
        }
    }
}

int main(){


    // Cria lista de Adjacencia com 200 casas
    vector<vii> listaAdjacencia(200);
    // numeros de arestas e vertices
    int numerosVertices, arestas;
    cin >> numerosVertices >> arestas;

    //Vertices u e v, u principal v adjacente
    int u, v;
    //Vetor de inteiros que marcam os nós visitados
    vi visitados(numerosVertices, NAOVISITADO);

    while(arestas--){
        cin >> u >> v;
        listaAdjacencia[u-1].push_back(make_pair(v-1, 0));
		listaAdjacencia[v-1].push_back(make_pair(u-1, 0));
        //Isso por que é um grafo não direcionado, logo u e v, é a mesma coisa de v u
    }

    printar_lista_adjacencia(listaAdjacencia, numerosVertices);

    dfs(0, listaAdjacencia, visitados); printf("\n");


    return 0;
}