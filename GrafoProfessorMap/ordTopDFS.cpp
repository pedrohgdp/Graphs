#include <iostream>
#include <vector>

using namespace std;

#define VIS 1       // Define constante para marcar vértices visitados
#define NAOVIS 0    // Define constante para marcar vértices não visitados

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

// Função para imprimir a lista de adjacência
void printList(const vector<vii>& AdjList, int nv) {
    for (int i = 1; i <= nv; ++i) {
        printf("%d -> ", i);
        for (int j = 0; j < AdjList[i].size(); ++j) {
            printf("(%d %d) -> ", AdjList[i][j].first, AdjList[i][j].second);
        }
        printf("\n");
    }
    printf("\n");
}

// Função de busca em profundidade (DFS) recursiva
void dfs(int u, const vector<vii>& AdjList, vi& vertices, vi& ordTop) {
    vertices[u] = VIS;  // Marca o vértice u como visitado

    // Para cada vértice adjacente v de u
    for (int i = 0; i < AdjList[u].size(); ++i) {
        int v = AdjList[u][i].first;
        if (vertices[v] == NAOVIS) {
            dfs(v, AdjList, vertices, ordTop); // Chama DFS recursivamente para v
        }
    }

    // Adiciona o vértice u à lista de ordenação topológica
    ordTop.push_back(u);
    printf("%d\n", u);  // Imprime o vértice no processo
}

int main() {
    int nv, u, v;
    cout << "Digite o número de vértices: ";
    cin >> nv;

    // Inicializa a lista de adjacência e o vetor de visitados
    vector<vii> AdjList(nv + 1, vii());
    vi vertices(nv + 1, NAOVIS);  // Inicializa todos os vértices como não visitados
    vi ordTop;                    // Vetor para armazenar a ordenação topológica

    // Leitura das arestas do grafo não direcionado
    cout << "Digite as arestas (par de vértices) e pressione Ctrl+D para parar:" << endl;
    while (cin >> u >> v) {
        AdjList[u].push_back(make_pair(v, 0));
        // Se o grafo for não direcionado, adicionar também a aresta inversa:
        // AdjList[v].push_back(make_pair(u, 0));
    }

    // Imprime a lista de adjacência
    printList(AdjList, nv);

    // Executa DFS a partir de cada vértice não visitado
    for (int i = 1; i <= nv; ++i) {
        if (vertices[i] == NAOVIS) {
            dfs(i, AdjList, vertices, ordTop);
        }
    }

    // Imprime a ordenação topológica (em ordem inversa)
    cout << "Ordenação Topológica:" << endl;
    for (int i = ordTop.size() - 1; i >= 0; --i) {
        printf("%d **", ordTop[i]);
    }

    return 0;
}
