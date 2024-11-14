#include <iostream>
#include <vector>
#include <stack>

using namespace std;

typedef vector<int> vi;

void dfs(int u, const vector<vi>& graph, vi& visited, stack<int>& finishStack) {
    visited[u] = 1;
    for (int v : graph[u]) {
        if (!visited[v]) {
            dfs(v, graph, visited, finishStack);
        }
    }
    finishStack.push(u);  // Empilha ao terminar
}

void reverseDfs(int u, const vector<vi>& reverseGraph, vi& visited, vi& scc) {
    visited[u] = 1;
    scc.push_back(u);  // Coleta vértices do SCC atual
    for (int v : reverseGraph[u]) {
        if (!visited[v]) {
            reverseDfs(v, reverseGraph, visited, scc);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vi> graph(n), reverseGraph(n);
    int u, v;

    // Leitura do grafo e construção do grafo reverso
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        graph[u - 1].push_back(v - 1);
        reverseGraph[v - 1].push_back(u - 1);  // Adiciona aresta reversa
    }

    // Primeira passagem: ordem de término no grafo original
    vi visited(n, 0);
    stack<int> finishStack;
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(i, graph, visited, finishStack);
        }
    }

    // Segunda passagem: DFS no grafo invertido para identificar SCCs
    fill(visited.begin(), visited.end(), 0);  // Marca todos como não visitados
    while (!finishStack.empty()) {
        int u = finishStack.top();
        finishStack.pop();
        if (!visited[u]) {
            vi scc;  // Armazena os vértices do SCC atual
            reverseDfs(u, reverseGraph, visited, scc);

            // Imprime o componente fortemente conectado
            cout << "SCC: ";
            for (int v : scc) {
                cout << (v + 1) << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
