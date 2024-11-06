/***************************************
Nombre: Juliana Pacheco Amaya
Clase: Estructura de datos
Tema: Laboratorio Grafos (Ciclo de EULER)
Profesor: John Corredor
Fecha: 06/11/2024
***************************************/

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

// Estructura para el grafo
struct Grafo {
    int V; // Número de vértices
    vector<list<int>> adj; // Lista de adyacencia para representar el grafo
};

// Inicializa un grafo con V vértices
Grafo crearGrafo(int V) {
    Grafo g;
    g.V = V;
    g.adj.resize(V);
    return g;
}

// Agrega una arista no dirigida entre los vértices v y w
void agregarArista(Grafo &g, int v, int w) {
    g.adj[v].push_back(w);
    g.adj[w].push_back(v); // Agregar en ambas direcciones porque el grafo es no dirigido
}

// Imprime el ciclo de Euler desde un vértice inicial adecuado
void imprimirCicloEuler(Grafo &g);

// Encuentra y muestra el ciclo de Euler de forma recursiva
void encontrarCicloEuler(Grafo &g, int v);

// Función auxiliar para verificar si una arista es un puente
bool esPuente(Grafo &g, int v, int u);

// Función auxiliar para eliminar una arista entre dos vértices
void eliminarArista(Grafo &g, int v, int u);

// Función auxiliar para contar el número de vértices conectados desde un nodo dado
int contarVerticesConectados(Grafo &g, int v, vector<bool> &visitado);

void imprimirCicloEuler(Grafo &g) {
    int u = 0;
    // Selecciona un vértice inicial; si hay vértices de grado impar, empieza desde uno de ellos
    for (int i = 0; i < g.V; i++) {
        if (g.adj[i].size() % 2 != 0) {
            u = i;
            break;
        }
    }
    cout << "Ciclo de Euler: ";
    encontrarCicloEuler(g, u);
    cout << endl;
}

void encontrarCicloEuler(Grafo &g, int v) {
    for (auto it = g.adj[v].begin(); it != g.adj[v].end(); ++it) {
        int u = *it;
        // Si la arista no ha sido visitada (-1 indica arista visitada) y no es un puente (si hay opciones)
        if (u != -1 && !esPuente(g, v, u)) {
            cout << v << " -> ";
            eliminarArista(g, v, u);
            encontrarCicloEuler(g, u);
        }
    }
    cout << v; // Para mostrar el último nodo al final del ciclo
}

bool esPuente(Grafo &g, int v, int u) {
    if (g.adj[v].size() == 1) return false;

    vector<bool> visitado1(g.V, false);
    int antes = contarVerticesConectados(g, v, visitado1);

    eliminarArista(g, v, u);

    vector<bool> visitado2(g.V, false); // Nuevo vector sin necesidad de reiniciar valores
    int despues = contarVerticesConectados(g, v, visitado2);

    agregarArista(g, v, u); // Restaurar la arista

    return (antes > despues);
}

void eliminarArista(Grafo &g, int v, int u) {
    g.adj[v].remove(u);
    g.adj[u].remove(v);
}

int contarVerticesConectados(Grafo &g, int v, vector<bool> &visitado) {
    visitado[v] = true;
    int cuenta = 1;
    for (int u : g.adj[v]) {
        if (u != -1 && !visitado[u]) {
            cuenta += contarVerticesConectados(g, u, visitado);
        }
    }
    return cuenta;
}

int main() {
    Grafo g = crearGrafo(7); // Crear un grafo con 7 nodos
    agregarArista(g, 0, 1);
    agregarArista(g, 0, 2);
    agregarArista(g, 1, 2);
    agregarArista(g, 1, 3);
    agregarArista(g, 2, 4);
    agregarArista(g, 3, 4);
    agregarArista(g, 3, 5);
    agregarArista(g, 4, 5);
    agregarArista(g, 5, 6);

    imprimirCicloEuler(g);

    return 0;
}
