#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <list>
#include <vector>
#include <stdexcept>
#include "Comando.h"
#include "Objeto.h"
#include "CercanoAux.h"
#include "AuxDijkstra.h"
#include <queue>

std::list<Comando> CargarComandos()
{
    std::ifstream lectura("Ayuda.txt");
    if (!lectura.is_open())
    {
        std::cout << "No se pudo cargar el archivo con los comandos" << std::endl;
        exit(1);
    }

    std::list<Comando> listaComandos;
    std::string linea;

    while (getline(lectura, linea))
    {
        std::stringstream ss(linea);
        std::string campo;
        std::list<std::string> comando;

        // Extraer campos separados por ';'
        while (getline(ss, campo, ';'))
        {
            comando.push_back(campo);
        }

        std::list<std::string> listaAyuda;
        std::list<std::string> listaCorrecto;
        std::string principal = comando.front();
        comando.pop_front();
        int cantidad = comando.size();
        for (int i = 0; i < cantidad; i += 2)
        {
            listaCorrecto.push_back(comando.front());
            comando.pop_front();
            listaAyuda.push_back(comando.front());
            comando.pop_front();
        }
        Comando cmd(principal, listaAyuda, listaCorrecto);
        listaComandos.push_back(cmd);
    }
    lectura.close();
    return listaComandos;
}

void BuscarComandoAyuda(std::string ingresado, std::list<Comando> &comandos)
{
    bool encontrado = false;
    for (std::list<Comando>::iterator it = comandos.begin(); it != comandos.end(); ++it)
    {
        if (it->getPrincipal() == ingresado)
        {
            std::cout << it->mostrarAyudaCompleta() << std::endl;
            encontrado = true;
            break;
        }
    }
    if (!encontrado)
    {
        std::cout << "El comando escrito no existe" << std::endl;
    }
}
void Ayuda(std::list<Comando> comandos)
{
    std::cout << "\nListado de comandos:" << std::endl;
    for (std::list<Comando>::iterator it = comandos.begin(); it != comandos.end(); ++it)
    {
        std::cout << it->getPrincipal() << std::endl;
    }
    std::cout << std::endl;
}

bool cargar(std::string NombreArchivo, std::list<Objeto> &Objetos)
{
    std::ifstream lectura(NombreArchivo);
    if (!lectura.is_open())
    {
        std::cout << "No se pudo abrir el archivo" << std::endl;
        return false;
    }

    std::string NombreObjeto;
    if (!getline(lectura, NombreObjeto) || NombreObjeto.empty())
    {
        std::cout << "Error al leer el nombre del objeto" << std::endl;
        lectura.close();
        return false;
    }

    // Encuentra el objeto en la lista existente o crea uno nuevo si no se encuentra
    bool objetoEncontrado = false;
    for (std::list<Objeto>::iterator objIt = Objetos.begin(); objIt != Objetos.end(); ++objIt)
    {
        if (objIt->getNombre() == NombreObjeto)
        {
            std::cout << "El objeto ya fue creado" << std::endl;
            lectura.close();
            return false;
        }
    }

    std::string linea;
    if (!getline(lectura, linea) || linea.empty())
    {
        std::cout << "Error al leer la cantidad de vértices" << std::endl;
        lectura.close();
        return false;
    }

    int cantidadVertices = 0;
    try
    {
        cantidadVertices = std::stoi(linea);
    }
    catch (const std::exception &e)
    {
        std::cout << "Error al convertir la cantidad de vértices: " << e.what() << std::endl;
        lectura.close();
        return false;
    }

    if (cantidadVertices <= 0)
    {
        std::cout << "La información del documento es errada" << std::endl;
        lectura.close();
        return false;
    }

    std::list<Vertice> verticesLeidos;
    std::vector<Vertice> vertices;

    int conVertices = 0;
    for (int i = 0; i < cantidadVertices; i++)
    {
        if (!getline(lectura, linea) || linea.empty())
        {
            std::cout << "Error al leer las coordenadas del vértice" << std::endl;
            lectura.close();
            return false;
        }

        std::stringstream ss(linea);
        float coord[3];
        int con = 0;

        while (getline(ss, linea, ' '))
        {
            try
            {
                coord[con] = std::stof(linea);
            }
            catch (const std::exception &e)
            {
                std::cout << "Error al convertir las coordenadas del vértice: " << e.what() << std::endl;
                lectura.close();
                return false;
            }
            con++;
        }

        if (con != 3)
        {
            std::cout << "Número de coordenadas incorrecto para el vértice" << std::endl;
            lectura.close();
            return false;
        }

        Vertice vertice(coord[0], coord[1], coord[2], conVertices);

        // Verifica si el vértice ya fue leído
        bool verticeRepetido = false;
        for (std::list<Vertice>::iterator vIt = verticesLeidos.begin(); vIt != verticesLeidos.end(); ++vIt)
        {
            if (vIt->sonIguales(vertice))
            {
                std::cout << "El vértice ya fue leído por lo que será omitido" << std::endl;
                verticeRepetido = true;
                break;
            }
        }

        if (verticeRepetido)
        {
            continue;
        }

        verticesLeidos.push_back(vertice);
        vertices.push_back(vertice);
        conVertices++;
    }

    std::list<Arista> aristasLeidas; // Lista para verificar duplicados
    Objeto objeto = Objeto(NombreObjeto);
    while (getline(lectura, linea))
    {
        if (linea.empty())
        {
            std::cout << "Error al leer la línea para la cara " << std::endl;
            lectura.close();
            return false;
        }

        Cara cara;
        std::stringstream ss(linea);
        getline(ss, linea, ' ');
        int cantidadAristas = 0;

        try
        {
            cantidadAristas = std::stoi(linea);
        }
        catch (const std::exception &e)
        {
            std::cout << "Error al convertir la cantidad de aristas: " << e.what() << std::endl;
            lectura.close();
            return false;
        }

        if (cantidadAristas == -1)
        {
            lectura.close();
            std::list<Vertice> verticesLista(vertices.begin(), vertices.end());
            objeto.setVertices(verticesLista);
            objeto.setAristas(aristasLeidas);
            Objetos.push_back(objeto);
            return true;
        }
        else if (cantidadAristas <= 0)
        {
            std::cout << "La información del archivo está errada" << std::endl;
            lectura.close();
            return false;
        }

        std::vector<int> indexArista(cantidadAristas);
        for (int i = 0; i < cantidadAristas; i++)
        {
            if (!getline(ss, linea, ' '))
            {
                std::cout << "Error al leer el índice de la arista" << std::endl;
                lectura.close();
                return false;
            }

            try
            {
                indexArista[i] = std::stoi(linea);
            }
            catch (const std::exception &e)
            {
                std::cout << "Error al convertir el índice de la arista: " << e.what() << std::endl;
                lectura.close();
                return false;
            }
        }

        for (int i = 0; i < cantidadAristas; i++)
        {
            int indexInicio = indexArista[i];
            int indexFinal = indexArista[(i + 1) % cantidadAristas];

            if ((indexInicio >= 0 && indexInicio < cantidadVertices) &&
                (indexFinal >= 0 && indexFinal < cantidadVertices))
            {
                Arista arista(vertices[indexInicio], vertices[indexFinal]);

                bool aristaRepetida = false;
                for (std::list<Arista>::iterator aIt = aristasLeidas.begin(); aIt != aristasLeidas.end(); ++aIt)
                {
                    if (aIt->sonIguales(arista))
                    {
                        cara.anadirArista(*aIt);
                        aristaRepetida = true;
                        break;
                    }
                }

                if (!aristaRepetida)
                {
                    aristasLeidas.push_back(arista);
                    cara.anadirArista(arista);
                }
            }
            else
            {
                std::cout << "Dato errado en los índices de los vértices" << std::endl;
                lectura.close();
                return false;
            }
        }
        objeto.agregarCara(cara);
    }

    lectura.close();
    std::cout << "No se encontró el carácter de finalización '-1'" << std::endl;
    return false;
}

void listado(std::list<Objeto> &Objetos)
{
    if (Objetos.empty())
    {
        std::cout << "No se han cargado Objetos" << std::endl;
    }
    else
    {
        for (std::list<Objeto>::iterator objIt = Objetos.begin(); objIt != Objetos.end(); objIt++)
        {
            int verticesCount = objIt->getVertices().size();
            int carasCount = objIt->getCaras().size();
            int aristasCount = objIt->getAristas().size();

            std::cout << objIt->getNombre()
                      << " tiene " << verticesCount
                      << " vértices, " << aristasCount
                      << " aristas y " << carasCount
                      << " caras." << std::endl;
        }
    }
}

Vertice getMinVertice(std::list<Vertice> vertices)
{

    // Inicializar con el primer vértice
    auto minVertice = vertices.front();
    float minX = minVertice.getX();
    float minY = minVertice.getY();
    float minZ = minVertice.getZ();

    // Recorrer la lista de vértices
    for (auto it = vertices.begin(); it != vertices.end(); ++it)
    {
        if (it->getX() < minX)
            minX = it->getX();
        if (it->getY() < minY)
            minY = it->getY();
        if (it->getZ() < minZ)
            minZ = it->getZ();
    }

    return Vertice(minX, minY, minZ, 0);
}
Vertice getMaxVertice(std::list<Vertice> vertices)
{

    // Inicializar con el primer vértice
    auto maxVertice = vertices.front();
    float maxX = maxVertice.getX();
    float maxY = maxVertice.getY();
    float maxZ = maxVertice.getZ();

    // Recorrer la lista de vértices
    for (auto it = vertices.begin(); it != vertices.end(); ++it)
    {
        if (it->getX() > maxX)
            maxX = it->getX();
        if (it->getY() > maxY)
            maxY = it->getY();
        if (it->getZ() > maxZ)
            maxZ = it->getZ();
    }

    return Vertice(maxX, maxY, maxZ, 7);
}
Objeto &crearEnvolvente(std::string nombreObjeto, Vertice min, Vertice max)
{
    std::list<Vertice> vertices;
    std::vector<Vertice> vectorVertices;
    std::list<Arista> aristas;
    // Añadir los 8 vértices que definen la caja envolvente
    vectorVertices.push_back(min);
    vectorVertices.push_back(Vertice(min.getX(), max.getY(), min.getZ(), 1)); // (minX, maxY, minZ)
    vectorVertices.push_back(Vertice(min.getX(), min.getY(), max.getZ(), 2)); // (minX, minY, maxZ)
    vectorVertices.push_back(Vertice(min.getX(), max.getY(), max.getZ(), 3)); // (minX, maxY, maxZ)
    vectorVertices.push_back(Vertice(max.getX(), min.getY(), min.getZ(), 4)); // (maxX, minY, minZ)
    vectorVertices.push_back(Vertice(max.getX(), min.getY(), max.getZ(), 5)); // (maxX, minY, maxZ)
    vectorVertices.push_back(Vertice(max.getX(), max.getY(), min.getZ(), 6)); // (maxX, maxY, minZ)
    vectorVertices.push_back(max);                                            // (maxX, maxY, maxZ)

    // Copiar los vértices al std::list
    vertices.assign(vectorVertices.begin(), vectorVertices.end());

    // Crear las aristas
    Arista ladoIzquierdoCara1(vectorVertices[0], vectorVertices[2]);
    Arista ladoSuperiorCara1(vectorVertices[2], vectorVertices[3]);
    Arista ladoDerechoCara1(vectorVertices[3], vectorVertices[1]);
    Arista ladoBaseCara1(vectorVertices[1], vectorVertices[0]);

    Arista ladoBaseCara2(vectorVertices[4], vectorVertices[6]);
    Arista ladoDerechoCara2(vectorVertices[6], vectorVertices[7]);
    Arista ladoSuperiorCara2(vectorVertices[7], vectorVertices[5]);
    Arista ladoIzquierdoCara2(vectorVertices[5], vectorVertices[4]);

    Arista conectarBaseDelantera(vectorVertices[4], vectorVertices[0]);
    Arista conectarSuperiorDelantera(vectorVertices[2], vectorVertices[5]);
    Arista conectarBaseTrasera(vectorVertices[1], vectorVertices[6]);
    Arista conectarSuperiorTrasera(vectorVertices[3], vectorVertices[7]);

    aristas.push_back(ladoBaseCara1);
    aristas.push_back(ladoDerechoCara1);
    aristas.push_back(ladoSuperiorCara1);
    aristas.push_back(ladoIzquierdoCara1);
    aristas.push_back(ladoBaseCara2);
    aristas.push_back(ladoIzquierdoCara2);
    aristas.push_back(ladoDerechoCara2);
    aristas.push_back(ladoSuperiorCara2);
    aristas.push_back(conectarBaseDelantera);
    aristas.push_back(conectarSuperiorDelantera);
    aristas.push_back(conectarBaseTrasera);
    aristas.push_back(conectarSuperiorTrasera);

    // Crear las caras usando las aristas
    Cara caraIzquierda;
    caraIzquierda.anadirArista(ladoIzquierdoCara1);
    caraIzquierda.anadirArista(ladoSuperiorCara1);
    caraIzquierda.anadirArista(ladoDerechoCara1);
    caraIzquierda.anadirArista(ladoBaseCara1);

    Cara caraDerecha;
    caraDerecha.anadirArista(ladoBaseCara2);
    caraDerecha.anadirArista(ladoDerechoCara2);
    caraDerecha.anadirArista(ladoSuperiorCara2);
    caraDerecha.anadirArista(ladoIzquierdoCara2);

    Cara caraFrontal;
    caraFrontal.anadirArista(ladoIzquierdoCara1);
    caraFrontal.anadirArista(conectarSuperiorDelantera);
    caraFrontal.anadirArista(ladoIzquierdoCara2);
    caraFrontal.anadirArista(conectarBaseDelantera);

    Cara caraSuperior;
    caraSuperior.anadirArista(ladoSuperiorCara1);
    caraSuperior.anadirArista(conectarSuperiorTrasera);
    caraSuperior.anadirArista(ladoSuperiorCara2);
    caraSuperior.anadirArista(conectarSuperiorDelantera);

    Cara caraTrasera;
    caraTrasera.anadirArista(conectarBaseTrasera);
    caraTrasera.anadirArista(ladoDerechoCara2);
    caraTrasera.anadirArista(conectarSuperiorTrasera);
    caraTrasera.anadirArista(ladoDerechoCara1);

    Cara caraInferior;
    caraInferior.anadirArista(conectarBaseDelantera);
    caraInferior.anadirArista(ladoBaseCara2);
    caraInferior.anadirArista(conectarBaseTrasera);
    caraInferior.anadirArista(ladoBaseCara1);

    // Crear el objeto para la caja envolvente
    Objeto *objeto = new Objeto(nombreObjeto);
    objeto->agregarCara(caraIzquierda);
    objeto->agregarCara(caraDerecha);
    objeto->agregarCara(caraFrontal);
    objeto->agregarCara(caraSuperior);
    objeto->agregarCara(caraTrasera);
    objeto->agregarCara(caraInferior);

    objeto->setAristas(aristas);
    objeto->setVertices(vertices);
    return *objeto;
}
void envolvente(std::list<Objeto> &Objetos)
{

    std::string nombre = "Env_Global";
    int con = 1;
    if (Objetos.size() == 0)
    {
        std::cout << "No hay objetos cargados en memoria" << std::endl;
        return;
    }
    std::list<Vertice> vertices;
    for (std::list<Objeto>::iterator objIt = Objetos.begin(); objIt != Objetos.end(); ++objIt)
    {
        if (objIt->getNombre() == nombre)
        {
            nombre = nombre + std::to_string(con);
        }
        vertices.insert(vertices.end(), objIt->getVertices().begin(), objIt->getVertices().end());
    }

    // Encontrar los vértices mínimo y máximo
    Vertice min = getMinVertice(vertices);
    Vertice max = getMaxVertice(vertices);

    // Añadir el objeto de la caja envolvente a la lista
    Objetos.push_back(crearEnvolvente(nombre, min, max));
    std::cout << "Se creo el objeto " << nombre << std::endl;
}

void envolvente(std::string nombreObjeto, std::list<Objeto> &Objetos)
{
    if (Objetos.size() == 0)
    {
        std::cout << "No hay objetos cargados en memoria" << std::endl;
        return;
    }
    std::list<Vertice> vertices;
    for (std::list<Objeto>::iterator objIt = Objetos.begin(); objIt != Objetos.end(); ++objIt)
    {
        if (objIt->getNombre() == nombreObjeto)
        {
            vertices = objIt->getVertices();
            break;
        }
    }
    if (vertices.empty())
    {
        std::cout << "No se encontró el objeto" << std::endl;
        return;
    }
    std::string nombre = "Env_" + nombreObjeto;

    // Encontrar los vértices mínimo y máximo
    Vertice min = getMinVertice(vertices);
    Vertice max = getMaxVertice(vertices);

    // Añadir el objeto de la caja envolvente a la lista
    Objetos.push_back(crearEnvolvente(nombre, min, max));
    std::cout << "Se creo el objeto " << nombre << std::endl;
}

void descargar(std::string nombreObjeto, std::list<Objeto> &Objetos)
{
    bool objetoEncontrado = false;

    for (std::list<Objeto>::iterator objIt = Objetos.begin(); objIt != Objetos.end(); ++objIt)
    {
        if (objIt->getNombre() == nombreObjeto)
        {
            Objetos.erase(objIt);
            std::cout << "El objeto " << nombreObjeto << " ha sido eliminado de la memoria de trabajo." << std::endl;
            objetoEncontrado = true;
            break;
        }
    }
    if (!objetoEncontrado)
    {
        std::cout << "El objeto " << nombreObjeto << " no ha sido cargado en memoria." << std::endl;
    }
}
void Guardar(std::string nombreObjeto, std::string nombreArchivo, std::list<Objeto> &Objetos)
{
    Objeto *objeto = nullptr;
    for (std::list<Objeto>::iterator objIt = Objetos.begin(); objIt != Objetos.end(); ++objIt)
    {
        if (objIt->getNombre() == nombreObjeto)
        {
            objeto = &(*objIt);
            break;
        }
    }
    if (objeto == nullptr)
    {
        std::cout << "El objeto no esta cargado en memoria" << std::endl;
    }
    else
    {
        std::ofstream escribir;
        escribir.open(nombreArchivo, std::ios::trunc);
        escribir << objeto->getNombre() << std::endl;
        escribir << objeto->getVertices().size() << std::endl;
        for (std::list<Vertice>::iterator verIt = objeto->getVertices().begin(); verIt != objeto->getVertices().end(); ++verIt)
        {
            escribir << verIt->getX() << " " << verIt->getY() << " " << verIt->getZ() << std::endl;
        }
        for (std::list<Cara>::iterator caraIt = objeto->getCaras().begin(); caraIt != objeto->getCaras().end(); ++caraIt)
        {
            escribir << caraIt->getAristas().size() << " "; // Escribir la cantidad de aristas de la cara
            int con = 1;
            int tam = caraIt->getAristas().size();
            // Iterar sobre las aristas de la cara
            for (std::list<Arista>::const_iterator aristaIt = caraIt->getAristas().begin(); aristaIt != caraIt->getAristas().end(); ++aristaIt)
            {
                // Búsqueda manual del índice del vértice inicial en la lista de vértices
                int indiceInicial = -1, indiceFinal = -1;
                int indice = 0;

                for (std::list<Vertice>::iterator verticeIt = objeto->getVertices().begin(); verticeIt != objeto->getVertices().end(); ++verticeIt, ++indice)
                {
                    if (verticeIt->sonIguales(aristaIt->getVerticeInicial()))
                    {
                        indiceInicial = indice;
                    }
                    if (verticeIt->sonIguales(aristaIt->getVerticeFinal()))
                    {
                        indiceFinal = indice;
                    }
                    if (indiceInicial != -1 && indiceFinal != -1)
                    {
                        break; // Si ya encontramos ambos índices, salimos del bucle
                    }
                }
                // Escribir los índices de los vértices inicial y final de la arista
                if (indiceInicial != -1 && indiceFinal != -1)
                {
                    if (con == 1)
                    {
                        escribir << indiceInicial << " " << indiceFinal;
                        con++;
                    }
                    else if (con < tam)
                    {
                        escribir << " " << indiceFinal;
                        con++;
                    }
                }
                else
                {
                    std::cerr << "Error: No se encontraron los índices de los vértices para una arista." << std::endl;
                }
            }

            escribir << std::endl;
        }
        escribir << "-1";
        escribir.close();
        std::cout << "El archivo fue creado de manera exitosa" << std::endl;
    }
}
std::list<CercanoAux> PuntoCercanoObjeto(float px, float py, float pz, std::string nombre, std::list<Objeto> &Objetos)
{
    bool Encontrado = false;
    std::list<CercanoAux> vertices;
    double valor;

    for (std::list<Objeto>::iterator It = Objetos.begin(); It != Objetos.end(); It++)
    {
        if (It->getNombre() == nombre)
        {
            Encontrado = true;
            bool primero = true;
            int con = 0;
            for (std::list<Vertice>::iterator itVertice = It->getVertices().begin(); itVertice != It->getVertices().end(); itVertice++)
            {
                if (primero)
                {
                    valor = itVertice->DistanciaEuclidiana(px, py, pz);
                    vertices.push_back(CercanoAux(*itVertice, valor, con, nombre));
                    primero = false;
                }
                else
                {
                    double nuevoValor = itVertice->DistanciaEuclidiana(px, py, pz);
                    if (nuevoValor < valor)
                    {
                        vertices.clear();
                        valor = nuevoValor;
                    }
                    if (nuevoValor == valor)
                    {
                        vertices.push_back(CercanoAux(*itVertice, valor, con, nombre));
                    }
                }
                con++;
            }
            break;
        }
    }
    if (!Encontrado)
    {
        std::cout << "El objeto " + nombre + " no ha sido cargado en memoria" << std::endl;
    }
    return vertices;
}
std::list<CercanoAux> PuntoCercanoObjeto(float px, float py, float pz, std::list<Objeto> &Objetos)
{
    std::list<CercanoAux> finales;
    double distancia;
    bool primero = true;
    for (std::list<Objeto>::iterator It = Objetos.begin(); It != Objetos.end(); It++)
    {
        if (primero)
        {
            finales = PuntoCercanoObjeto(px, py, pz, It->getNombre(), Objetos);
            distancia = finales.front().getDistancia();
            primero = false;
        }
        else
        {
            std::list<CercanoAux> aux = PuntoCercanoObjeto(px, py, pz, It->getNombre(), Objetos);
            double nuevaDistancia = aux.front().getDistancia();
            if (nuevaDistancia < distancia)
            {
                finales.clear();
                distancia = nuevaDistancia;
            }
            if (distancia == nuevaDistancia)
            {
                std::copy(aux.begin(), aux.end(), std::back_inserter(finales));
            }
        }
    }
    return finales;
}
void cercano_caja(std::string objeto, std::list<Objeto> &Objetos)
{
    std::string nombre = "Env_" + objeto;
    bool encontradoEnvolvente = false;
    bool encontrado = false;
    for (std::list<Objeto>::iterator objIt = Objetos.begin(); objIt != Objetos.end(); ++objIt)
    {
        if (objIt->getNombre() == nombre)
        {
            encontradoEnvolvente = true;
            int con = 1;
            std::cout << "--Esquina--  --Vertice--  --Distancia--" << std::endl;
            for (std::list<Vertice>::iterator IT = objIt->getVertices().begin(); IT != objIt->getVertices().end(); IT++)
            {
                std::list<CercanoAux> encontrados = PuntoCercanoObjeto(IT->getX(), IT->getY(), IT->getZ(), objeto, Objetos);
                if (encontrados.size() == 1)
                {
                    CercanoAux aux = encontrados.front();
                    encontrados.pop_front();
                    std::cout << con << " " << "(" << IT->getX() << "," << IT->getY() << "," << IT->getZ() << ") " << aux.getIndice() << " " << "(" << aux.getX() << "," << aux.getY() << "," << aux.getZ() << ") " << aux.getDistancia() << std::endl;
                }
                else
                {
                    int tam = encontrados.size();
                    for (int i = 0; i < tam; i++)
                    {
                        CercanoAux aux = encontrados.front();
                        encontrados.pop_front();
                        std::cout << con << "." << i + 1 << " " << "(" << IT->getX() << "," << IT->getY() << "," << IT->getZ() << ") " << aux.getIndice() << " " << "(" << aux.getX() << "," << aux.getY() << "," << aux.getZ() << ") " << aux.getDistancia() << std::endl;
                    }
                }
                con++;
            }
            break;
        }
        if (objIt->getNombre() == objeto)
        {
            encontrado = true;
        }
    }
    if (!encontrado)
    {
        std::cout << "El objeto " << objeto << " no ha sido cargado en memoria." << std::endl;
    }
    if (!encontradoEnvolvente)
    {
        envolvente(objeto, Objetos);
        cercano_caja(objeto, Objetos);
    }
}
void Dijkstra(std::vector<AuxDijkstra> &listado, int indice)
{
    std::priority_queue<std::pair<double, int>, std::vector<std::pair<double, int>>, std::greater<>> cola;
    cola.emplace(0, indice);

    while (!cola.empty())
    {
        std::pair<double, int> Elemento = cola.top();
        indice = Elemento.second;
        cola.pop();

        if (listado[indice].isVisitado())
        {
            continue;
        }

        listado[indice].setVisitado(true);

        for (std::list<int>::const_iterator it = listado[indice].getDestinos().begin(); it != listado[indice].getDestinos().end(); ++it)
        {
            double costoAux = listado[indice].getElemento()->DistanciaEuclidiana(
                                  listado[*it].getElemento()->getX(),
                                  listado[*it].getElemento()->getY(),
                                  listado[*it].getElemento()->getZ()) +
                              Elemento.first;

            if (listado[*it].getCosto() > costoAux)
            {
                listado[*it].setCamino(indice);
                listado[*it].setCosto(costoAux);
                cola.emplace(costoAux, *it);
            }
        }
    }
}

std::string ruta_corta(int indiceInicial, int indiceFinal, std::string nombreObjeto, std::list<Objeto> &Objetos)
{
    for (std::list<Objeto>::iterator objIt = Objetos.begin(); objIt != Objetos.end(); ++objIt)
    {
        if (objIt->getNombre() == nombreObjeto)
        {
            if (indiceInicial >= objIt->getVertices().size() || indiceFinal >= objIt->getVertices().size())
            {
                std::cout << "Algunos de los indices de vertices estan fuera de rango para el objeto " << nombreObjeto << std::endl;
                return ("");
            }
            else
            {
                std::vector<AuxDijkstra> listado;
                for (std::list<Vertice>::iterator verItr = objIt->getVertices().begin(); verItr != objIt->getVertices().end(); ++verItr)
                {
                    listado.push_back(AuxDijkstra(&(*verItr)));
                }
                for (std::list<Arista>::iterator artIt = objIt->getAristas().begin(); artIt != objIt->getAristas().end(); ++artIt)
                {
                    int indiceInicialArista = artIt->getVerticeInicial().getIndice();
                    int indiceFinalArista = artIt->getVerticeFinal().getIndice();
                    listado[indiceInicialArista].addDestino(indiceFinalArista);
                    listado[indiceFinalArista].addDestino(indiceInicialArista);
                }
                listado[indiceInicial].setCosto(0);
                Dijkstra(listado, indiceInicial);
                std::string camino = std::to_string(indiceFinal);
                int indiceAux = indiceFinal;
                while (true)
                {
                    int origen = listado[indiceAux].getCamino();
                    if (origen == indiceInicial)
                    {

                        return (std::to_string(origen) + "-" + camino + "; con una longitud de " + std::to_string(listado[indiceFinal].getCosto()) + ".");
                    }
                    else if (origen == -1)
                    {
                        std::string error = "No se encontro un camino entre los vertices " + std::to_string(indiceInicial) + " y " + std::to_string(indiceFinal);
                        std::cout << error << std::endl;
                        return ("");
                    }
                    else
                    {
                        std::string camino_actualizado = std::to_string(origen) + "-" + camino;
                        camino = camino_actualizado;
                        indiceAux = origen;
                    }
                }
            }
            break;
        }
    }

    std::cout << " El objeto " << nombreObjeto << " no ha sido cargado en memoria" << std::endl;
    return ("");
}
std::string ruta_corta_centro(int indiceInicial, std::string nombreObjeto, std::list<Objeto> &Objetos)
{
    for (std::list<Objeto>::iterator objIt = Objetos.begin(); objIt != Objetos.end(); ++objIt)
    {
        if (objIt->getNombre() == nombreObjeto)
        {
            if (indiceInicial >= objIt->getVertices().size())
            {
                std::cout << " El indice de vertice esta fuera de rango para el objeto " << nombreObjeto << std::endl;
                return ("");
            }
            else
            {
                float x = 0;
                float y = 0;
                float z = 0;
                for (std::list<Vertice>::iterator verItr = objIt->getVertices().begin(); verItr != objIt->getVertices().end(); ++verItr)
                {
                    x += verItr->getX();
                    y += verItr->getY();
                    z += verItr->getZ();
                }
                x = x / objIt->getVertices().size();
                y = x / objIt->getVertices().size();
                z = x / objIt->getVertices().size();
                Vertice vertice(x, y, z, objIt->getVertices().size());
                int indiceFinal=objIt->getVertices().size();
                bool iguales = false;
                int con=0;
                for (std::list<Vertice>::iterator verItr = objIt->getVertices().begin(); verItr != objIt->getVertices().end(); ++verItr)
                {
                    if (verItr->sonIguales(vertice))
                    {
                        indiceFinal=con;
                        iguales = true;
                        break;
                    }
                    con++;
                }
                if (!iguales)
                {
                    Cara cara;
                    Arista arista(vertice, *PuntoCercanoObjeto(x, y, z, nombreObjeto, Objetos).front().getVertice());
                    cara.anadirArista(arista);
                    objIt->agregarCara(cara);
                    objIt->agregarVertice(vertice);
                    objIt->agregarArista(arista);
                }
                std::string ct="ct ("+std::to_string(x)+","+std::to_string(y)+","+std::to_string(z)+") , pasa por: ";
                return ct+ruta_corta(indiceInicial,indiceFinal,nombreObjeto,Objetos);
            }
        }
    }
    return ("");
}

void CargarComando(std::list<Comando> comandos, std::list<Objeto> &Objetos)
{
    std::list<std::string> comando;
    std::string linea;
    std::string palabra;
    std::stringstream ss;
    std::cout << "$";
    getline(std::cin, linea);
    ss << linea;
    while (getline(ss, palabra, ' '))
    {
        comando.push_back(palabra);
    }
    if (comando.front() == "ayuda")
    {
        if (comando.size() == 1)
        {
            Ayuda(comandos);
        }
        else if (comando.size() == 2)
        {
            BuscarComandoAyuda(comando.back(), comandos);
        }
        else
        {
            std::cout << "El comando ayuda esta incompleto" << std::endl;
        }
    }
    else if (comando.front() == "cargar")
    {
        if (comando.size() != 2)
        {
            std::cout << "El comando esta escrito de manera erronea, escriba ayuda cargar para más información" << std::endl;
        }
        else
        {
            if (cargar(comando.back(), Objetos))
            {
                std::cout << "Objeto agregado de manera exitosa" << std::endl;
            }
        }
    }
    else if (comando.front() == "listado")
    {
        if (comando.size() != 1)
        {
            std::cout << "El comando esta escrito de manera erronea, escriba ayuda listado para más información" << std::endl;
        }
        else
        {
            listado(Objetos);
        }
    }
    else if (comando.front() == "salir")
    {
        if (comando.size() != 1)
        {
            std::cout << "El comando esta escrito de manera erronea, escriba ayuda salir para más información" << std::endl;
        }
        else
        {
            exit(1);
        }
    }
    else if (comando.front() == "envolvente")
    {
        if (comando.size() != 1 && comando.size() != 2)
        {
            std::cout << "El comando esta escrito de manera erronea, escriba ayuda envolvente para más información" << std::endl;
        }
        else if (comando.size() == 1)
        {
            envolvente(Objetos);
        }
        else if (comando.size() == 2)
        {
            std::string nombreObjeto = comando.back();
            envolvente(nombreObjeto, Objetos);
        }
    }
    else if (comando.front() == "descargar")
    {
        if (comando.size() != 2)
        {
            std::cout << "El comando esta escrito de manera erronea, escriba ayuda descargar para más información" << std::endl;
        }
        else
        {
            descargar(comando.back(), Objetos);
        }
    }
    else if (comando.front() == "guardar")
    {
        if (comando.size() != 3)
        {
            std::cout << "El comando esta escrito de manera erronea, escriba ayuda guardar para más información" << std::endl;
        }
        else
        {
            comando.pop_front();
            Guardar(comando.front(), comando.back(), Objetos);
        }
    }
    else if (comando.front() == "v_cercano")
    {
        if (comando.size() != 4 && comando.size() != 5)
        {
            std::cout << "El comando esta escrito de manera erronea, escriba ayuda v_cercano para más información" << std::endl;
        }
        else
        {
            std::list<CercanoAux> vertices;
            if (comando.size() == 5)
            {
                try
                {
                    std::string nombre = comando.back();
                    comando.pop_back();
                    int z = stoi(comando.back());
                    comando.pop_back();
                    int y = stoi(comando.back());
                    comando.pop_back();
                    int x = stoi(comando.back());
                    comando.pop_back();
                    vertices = PuntoCercanoObjeto(x, y, z, nombre, Objetos);
                    if (vertices.size() != 0)
                    {
                        if (vertices.size() == 1)
                        {
                            CercanoAux mostrar = vertices.front();
                            vertices.pop_front();
                            std::cout << " El vertice " << mostrar.getIndice() << " (" << mostrar.getX() << "," << mostrar.getY() << "," << mostrar.getZ() << ") del objeto " << nombre << " es el más cercano al punto (" << x << "," << y << "," << z << "), a una distancia de " << mostrar.getDistancia() << std::endl;
                        }
                        else
                        {
                            std::cout << "Lista de vertices cercanos:" << std::endl;
                            int cantidad = vertices.size();
                            for (int i = 0; cantidad; i++)
                            {
                                CercanoAux mostrar = vertices.front();
                                vertices.pop_front();
                                std::cout << " El vertice " << mostrar.getIndice() << " (" << mostrar.getX() << "," << mostrar.getY() << "," << mostrar.getZ() << ") del objeto " << nombre << " es el más cercano al punto (" << x << "," << y << "," << z << "), a una distancia de " << mostrar.getDistancia() << std::endl;
                            }
                        }
                    }
                }
                catch (const std::exception &e)
                {
                    std::cout << "Error al convertir las coordenadas: " << std::endl;
                }
            }
            else if (comando.size() == 4)
            {
                try
                {
                    int z = stoi(comando.back());
                    comando.pop_back();
                    int y = stoi(comando.back());
                    comando.pop_back();
                    int x = stoi(comando.back());
                    comando.pop_back();
                    vertices = PuntoCercanoObjeto(x, y, z, Objetos);
                    if (vertices.size() != 0)
                    {
                        if (vertices.size() == 1)
                        {
                            CercanoAux mostrar = vertices.front();
                            vertices.pop_front();
                            std::cout << " El vertice " << mostrar.getIndice() << " (" << mostrar.getX() << "," << mostrar.getY() << "," << mostrar.getZ() << ") del objeto " << mostrar.getObjeto() << " es el más cercano al punto (" << x << "," << y << "," << z << "), a una distancia de " << mostrar.getDistancia() << std::endl;
                        }
                        else
                        {
                            std::cout << "Lista de vertices cercanos:" << std::endl;
                            int cantidad = vertices.size();
                            for (int i = 0; cantidad; i++)
                            {
                                CercanoAux mostrar = vertices.front();
                                vertices.pop_front();
                                std::cout << " El vertice " << mostrar.getIndice() << " (" << mostrar.getX() << "," << mostrar.getY() << "," << mostrar.getZ() << ") del objeto " << mostrar.getObjeto() << " es el más cercano al punto (" << x << "," << y << "," << z << "), a una distancia de " << mostrar.getDistancia() << std::endl;
                            }
                        }
                    }
                    else
                    {
                        std::cout << "Ningun objeto ha sido cargado en memoria." << std::endl;
                    }
                }
                catch (const std::exception &e)
                {
                    std::cout << "Error al convertir las coordenadas: " << e.what() << std::endl;
                }
            }
        }
    }
    else if (comando.front() == "v_cercanos_caja")
    {
        if (comando.size() != 2)
        {
            std::cout << "El comando esta escrito de manera erronea, escriba ayuda v_cercano_caja para más información" << std::endl;
        }
        else
        {
            cercano_caja(comando.back(), Objetos);
        }
    }
    else if (comando.front() == "ruta_corta")
    {
        if (comando.size() != 4)
        {
            std::cout << "El comando esta escrito de manera erronea, escriba ayuda ruta_corta para más información" << std::endl;
        }
        else
        {
            try
            {
                comando.pop_front();
                int indiceInicial = stoi(comando.front());
                comando.pop_front();
                int indiceFinal = stoi(comando.front());
                if (indiceFinal == indiceInicial)
                {
                    std::cout << "Los indices de los vertices dados son iguales" << std::endl;
                }
                else if (indiceFinal < 0 || indiceInicial < 0)
                {
                    std::cout << "Algunos de los indices de vertices estan fuera de rango para el objeto " << comando.back() << std::endl;
                }
                else
                {
                    std::string ruta = ruta_corta(indiceInicial, indiceFinal, comando.back(), Objetos);
                    if (ruta != "")
                    {
                        std::cout << " La ruta más corta que conecta los vertices " << indiceInicial << " y " << indiceFinal << " del objeto " << comando.back() << ". pasa por: " << ruta << std::endl;
                    }
                }
            }
            catch (const std::exception &e)
            {
                std::cout << "Los indices no son numeros" << std::endl;
            }
        }
    }
    else if (comando.front() == "ruta_corta_centro")
    {
        if (comando.size() != 3)
        {
            std::cout << "El comando esta escrito de manera erronea, escriba ayuda ruta_corta_centro para más información" << std::endl;
        }
        else
        {
            try
            {
                comando.pop_front();
                int indiceInicial = stoi(comando.front());

                if (indiceInicial < 0)
                {
                    std::cout << " El indice de vertice esta fuera de rango para el objeto " << comando.back() << std::endl;
                }
                else
                {
                    std::string ruta = ruta_corta_centro(indiceInicial, comando.back(), Objetos);
                    if (ruta != "")
                    {
                        std::cout << " ) La ruta más corta que conecta el vertice " << indiceInicial <<"con el centro del objeto " << comando.back() <<" , ubicado en "<< ruta << std::endl;
                    }
                }
            }
            catch (const std::exception &e)
            {
                std::cout << "Los indices no son numeros" << std::endl;
            }
        }
    }
    else
    {
        std::cout << "Comando no reconocido" << std::endl;
    }
}