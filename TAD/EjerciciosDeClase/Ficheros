/*************************************
Juliana Pacheco Amaya
Fecha: 24/07/2024
Materia: Estructuras de Datos
*************************************/

#include <iostream>
#include <string>
#include <math.h>

using namespace std;

//Función que calcula la suma de todos los números enteros desde 1 hasta n.
int sumaRecursiva(int n) {
	if (n <= 1) {
		return n;
	}
	else {
		return n + sumaRecursiva(n - 1);
	}
}

//Función que calcula la suma de los cuadrados de todos los números pares desde n hasta 0.
int cuadradosPares(int n) {
	if (n == 0) {
		return n;
	}
	else if (n % 2 == 0) {
		return n * n + cuadradosPares(n - 1);
	}
	else {
		return cuadradosPares(n - 1);
	}
}

// Función que calcula el cuadrado del doble del valor actual de n.
int cuadradosPares2(int n) {
	if (n == 0) {
		return n;
	}
	else {
		return pow(n + n, 2) + cuadradosPares2(n - 1);
	}
}

//Función que calcula el n-ésimo número en la secuencia de Fibonacci utilizando recursión.
int fibNumero(int n) {
	if (n <= 1) {
		return n;
	}
	else {
		return fibNumero(n - 1) + fibNumero(n - 2);
	}
}

// Función lineal que busca un carácter c dentro de una cadena s
bool lineal(string s, char c, int l) {
	if (l < 0) {
		return false;
	}
	else if (s[l] == c) {
		return true;
	}
	else {
		return lineal(s, c, l - 1);
	}
}


int main() {
	//Inicialización de funciones
	int cuadradosPares(int n);
	int cuadradosPares2(int n);
	int fibNumero(int n);
	string palabra = "Palabra";
	char substring = 'g';
	bool caracter = lineal(palabra, substring, palabra.length() - 1);
	int op, n;

	cout << "  Bienvenido al programa!" << endl;
	//Pide al usuario la opción que desea
	cout << endl << "Que ecuacion desea ejecutar?" << endl;
	cout << " Elija una opcion:" << endl;
	cout << "  1. Suma" << endl;
	cout << "  2. Cuadrados pares" << endl;
	cout << "  3. Cuadrados pares 2" << endl;
	cout << "  4. numero Fibonacci" << endl;
	cin >> op;

	//Pide al usuario un numero para ejecutar la función seleccionada
	cout << "Digite el numero que desea operar: " << endl;
	cin >> n;

	//Opciones de funciones a ejecutar
	switch (op) {
	case 1:
		sumaRecursiva(n);
		cout << "suma : " << sumaRecursiva(n) << endl;
		break;

	case 2:
		cuadradosPares(n);
		cout << "suma : " << cuadradosPares(n) << endl;
		break;

	case 3:
		cuadradosPares2(n);
		cout << "Cuadrados pares 2: " << cuadradosPares2(n) << endl;
		break;

	case 4:
		int fibNumero(int n);
		cout << "Fibonacci: " << fibNumero(n) << endl;
		break;
	}
}
