#include <bits/stdc++.h>
using namespace std;

//Definição de tipos, quando não vamos ter peso nas arestas, podemos guardar a informação
//Somente dos vertices adjacentes a u
typedef vector<int> vi;


void dfs(int u, vector<vi> &grafoNormal, vector<int> &visitados, stack<int> &pilha){
    visitados[u] = 1;
    for(int v : grafoNormal[u]){
        if(!visitados[v]){
            dfs(v, grafoNormal, visitados, pilha);
        }
    }
    pilha.push(u);
}


void reverseDfs(int u, vector<vi> &grafoInvertido, vector<int> &visitados, vi &scc){
    visitados[u] = 1;
    scc.push_back(u);
    for(int v : grafoInvertido[u]){
        if(!visitados[v]){
            reverseDfs(v, grafoInvertido, visitados, scc);
        }
    }
}



int main(){

    int nv, arr;
    cin >> nv >> arr;

    vector<vi> grafoNormal(nv);
    vector<vi> grafoInvertido(nv);

    int u, v;

    while(arr--){
        cin >> u >> v;
        grafoNormal[u - 1].push_back(v - 1);
        grafoInvertido[v - 1].push_back(u - 1);
    }


    //Primeira passagem ordem de termino no grafo original, vamos monta a pilha e fazer um dfs enchendo a pilha
    vector<int> visitados(nv, 0);
    stack<int> pilha;
    for(int i = 0; i < nv; i++){
        if(!visitados[i]){ //Ver sobre no gpt
            dfs(i, grafoNormal, visitados, pilha);
        }
    }


    //Segunda chamada vamos passar pelo grafo invertido tirando os itens da pilha, de forma que conseguiremos ver os scc do codigo
    //Isso vai ser que nem um bfs que chama um dfs
    fill(visitados.begin(), visitados.end(), 0); // Marca todos de visitado como 0 ( nao visitado novamente )
    while(!pilha.empty()){//Enquanto a pilha nao estiver vazia
        //Tira o item do topo da pilha e poe em u depois remove ele da pilha
        int u = pilha.top();
        pilha.pop();
        if(!visitados[u]){ //Se u nao foi visitado
            //Criamos o vetor de inteiros para podermos guardar o scc e chamamos o reverse dfs que vai ver os scc e andar o grafo limpando a pilha
            vi scc;
            reverseDfs(u, grafoInvertido, visitados, scc);

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