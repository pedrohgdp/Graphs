#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Definindo pares de inteiros e lista de adjacência para grafos
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

// Função para imprimir a lista de adjacência
void printList(const vector<vii>& AdjList, int nv) {
    for (int i = 0; i <= nv; ++i) {
        cout << i << " -> ";
        for (int j = 0; j < AdjList[i].size(); ++j) {
            cout << "(" << AdjList[i][j].first << " " << AdjList[i][j].second << ") -> ";
        }
        cout << endl;
    }
    cout << endl;
}

// Função para realizar a ordenação topológica usando o Algoritmo de Kahn
vector<int> khan(const vector<vii>& AdjList, int nv) {
    vi gEntr(nv + 1, 0);   // Grau de entrada dos vértices
    vector<int> ordTop;     // Armazena a ordenação topológica
    queue<int> q;           // Fila para processamento de vértices com grau de entrada zero

    // Calcula o grau de entrada de todos os vértices
    for (int u = 1; u <= nv; ++u) {
        for (int i = 0; i < AdjList[u].size(); ++i) {
            int v = AdjList[u][i].first;
            gEntr[v]++;
        }
    }

    // Enfileira todos os vértices com grau de entrada zero
    for (int u = 1; u <= nv; ++u) {
        if (gEntr[u] == 0) {
            q.push(u);
        }
    }

    // Processa a fila
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        ordTop.push_back(u);

        // Para cada vértice adjacente v de u, decrementa o grau de entrada de v
        for (int i = 0; i < AdjList[u].size(); ++i) {
            int v = AdjList[u][i].first;
            gEntr[v]--;

            // Se o grau de entrada de v se torna zero, coloca v na fila
            if (gEntr[v] == 0) {
                q.push(v);
            }
        }
    }

    return ordTop;
}

int main() {
    int nv, u, v, na;
    cin >> nv >> na;

    // Inicializa a lista de adjacência para representar o grafo direcionado
    vector<vii> AdjList(nv + 1);

    // Lê as arestas do grafo
    while (na) {
		cin >> u >> v;
        AdjList[u].push_back(ii(v, 0));
		na--;
    }

    // Imprime a lista de adjacência para verificação
    printList(AdjList, nv);

    // Realiza a ordenação topológica usando o Algoritmo de Kahn
    vector<int> ordTop = khan(AdjList, nv);

    // Exibe a ordenação topológica
    for (int i = 0; i < ordTop.size(); ++i) {
        cout << ordTop[i] << " ** ";
    }
    cout << endl;

    return 0;
}
