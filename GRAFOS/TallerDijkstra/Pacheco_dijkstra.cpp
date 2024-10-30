/***************************************
Nombre: Juliana Pacheco Amaya
Clase: Estructura de datos
Tema: Algoritmo Dijkstra
Profesor: John Corredor
Fecha: 30/10/2024
***************************************/



#include <iostream>
#include <climits> // Necesario para usar INT_MAX
using namespace std;

// Función para encontrar el vértice con la distancia mínima
int miniDist(int distance[], bool Tset[]) {
    int minimum = INT_MAX, ind = -1;

    // Recore todos los vértices
    for (int k = 0; k < 7; k++) {
        // Si el vértice no ha sido procesado y su distancia es menor o igual a la mínima actual
        if (!Tset[k] && distance[k] <= minimum) {
            minimum = distance[k];
            ind = k;
        }
    }
    return ind; // Retorna el índice del vértice con la distancia mínima
}

// Implementación del algoritmo de Dijkstra para encontrar la ruta más corta desde un vértice fuente
void DijkstraAlgo(int graph[7][7], int src) {
    int distance[7];  // Array para almacenar las distancias mínimas desde el vértice fuente
    bool Tset[7];     // Array para marcar los vértices ya procesados

    // Inicializa las distancias como infinitas y el conjunto Tset como falso
    for (int k = 0; k < 7; k++) {
        distance[k] = INT_MAX;
        Tset[k] = false;
    }

    distance[src] = 0; // La distancia del vértice fuente a sí mismo es siempre 0

    // Itera para encontrar la distancia mínima para cada vértice
    for (int k = 0; k < 7; k++) {
        int m = miniDist(distance, Tset); // Obtiene el vértice con la menor distancia
        Tset[m] = true; // Marca el vértice como procesado

        // Actualiza las distancias de los vértices adyacentes al vértice seleccionado
        for (int j = 0; j < 7; j++) {
            // Condiciones: el vértice no ha sido procesado, hay una arista, y la nueva distancia es menor
            if (!Tset[j] && graph[m][j] && distance[m] != INT_MAX && distance[m] + graph[m][j] < distance[j]) {
                distance[j] = distance[m] + graph[m][j];
            }
        }
    }

    // Imprime el resultado de las distancias desde el vértice fuente
    cout << "Vertice \t\t Distancia desde la fuente al Vertice" << endl;
    for (int k = 0; k < 7; k++) {
        char str = 65 + k; // Convierte el índice numérico en un carácter (A, B, C, ...)
        cout << str << "\t\t\t" << distance[k] << endl;
    }
}

int main() {
    // Definición de la matriz de adyacencia para el grafo
    int graph[7][7] = {
    // A   B   C   D   E   F   G
    {  0,  2,  4,  0,  0,  0,  0 },  // A
    {  2,  0,  0,  5,  0,  0,  0 },  // B
    {  4,  0,  0,  8,  0,  0,  0 },  // C
    {  0,  5,  8,  0, 10, 15,  0 },  // D
    {  0,  0,  0, 10,  0,  6,  2 },  // E
    {  0,  0,  0, 15,  6,  0,  6 },  // F
    {  0,  0,  0,  0,  2,  6,  0 }   // G
};

    // Llama a la función Dijkstra desde el vértice fuente 0
    DijkstraAlgo(graph, 0);

    return 0;
}
