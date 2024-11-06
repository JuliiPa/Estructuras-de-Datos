/***************************************
Nombre: Juliana Pacheco Amaya
Clase: Estructura de datos
Tema: Laboratorio Grafos (Algoritmo DIJKSTRA)
Profesor: John Corredor
Fecha: 06/11/2024
***************************************/

#include <iostream>
#include <climits> // Necesario para usar INT_MAX
#include <vector>  // Para almacenar los caminos
using namespace std;

// Función para encontrar el vértice con la distancia mínima
int miniDist(int distance[], bool Tset[]) {
    int minimo = INT_MAX, indice = -1;

    // Recorre todos los vértices para encontrar el que no ha sido procesado y tiene la menor distancia
    for (int k = 0; k < 7; k++) {
        if (!Tset[k] && distance[k] <= minimo) {
            minimo = distance[k];
            indice = k;
        }
    }
    return indice;
}

// Implementación del algoritmo de Dijkstra para encontrar el camino más corto desde un vértice fuente
void DijkstraAlgo(int graph[7][7], int src) {
    int distancia[7];  // Array para almacenar las distancias mínimas desde el vértice fuente
    bool Tset[7];      // Array para marcar los vértices ya procesados
    vector<int> camino[7]; // Vector para almacenar los caminos de cada vértice

    // Inicializa las distancias como infinitas y el conjunto Tset como falso
    for (int k = 0; k < 7; k++) {
        distancia[k] = INT_MAX;
        Tset[k] = false;
    }

    distancia[src] = 0; // La distancia del vértice fuente a sí mismo es siempre 0
    camino[src].push_back(src + 1); // Agrega el nodo fuente al camino

    // Itera para encontrar la distancia mínima para cada vértice
    for (int k = 0; k < 7; k++) {
        int m = miniDist(distancia, Tset); // Obtiene el vértice con la menor distancia
        Tset[m] = true; // Marca el vértice como procesado

        // Actualiza las distancias de los vértices adyacentes al vértice seleccionado
        for (int j = 0; j < 7; j++) {
            // Condiciones: el vértice no ha sido procesado, hay una arista, y la nueva distancia es menor
            if (!Tset[j] && graph[m][j] && distancia[m] != INT_MAX && distancia[m] + graph[m][j] < distancia[j]) {
                distancia[j] = distancia[m] + graph[m][j];
                camino[j] = camino[m]; // Copia el camino actual
                camino[j].push_back(j + 1); // Agrega el vértice al camino
            }
        }
    }

    // Imprime el resultado de las distancias y caminos desde el vértice fuente
    cout << "Vertice\t\tDistancia\tCamino" << endl;
    for (int k = 1; k < 7; k++) { // Empieza desde 1 para evitar imprimir el nodo fuente como destino de sí mismo
        cout << "1 -> " << k + 1 << "\t\t" << distancia[k] << "\t\t";
        for (int v : camino[k]) {
            cout << v << " ";
        }
        cout << endl;
    }
}

int main() {
    // Definición de la matriz de adyacencia para el grafo
    int graph[7][7] = {
    // A   B   C   D   E   F   G
    {  0,  1,  7,  6,  0,  0,  0 },  // A
    {  1,  0,  9,  0,  0,  3,  0 },  // B
    {  7,  9,  0,  0,  0,  0,  1 },  // C
    {  6,  0,  0,  0,  2,  0,  0 },  // D
    {  0,  0,  0,  2,  0,  0,  5 },  // E
    {  0,  3,  0,  0,  0,  0,  3 },  // F
    {  0,  0,  1,  0,  5,  3,  0 }   // G
};

    // Llama a la función Dijkstra desde el vértice fuente 0 (A)
    DijkstraAlgo(graph, 0);

    return 0;
}