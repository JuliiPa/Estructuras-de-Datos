// Clase Vehiculo: representa un vehículo que llega a un punto de cobro.
class Vehiculo {
private:
    std::string placa; // Identificación única del vehículo
    int tipo;  // Tipo de vehículo (por ejemplo, 1 para automóvil, 2 para camión, etc.)

public:
    // Constructor para inicializar el vehículo con su placa y tipo
    Vehiculo(std::string p, int t) : placa(p), tipo(t) {}

    // Método para obtener la placa del vehículo
    std::string getPlaca() const { return placa; }

    // Método para obtener el tipo del vehículo
    int getTipo() const { return tipo; }
};

// Clase Caseta: representa una caseta de cobro en un punto de peaje.
class Caseta {
private:
    int id;  // Identificación única de la caseta
    std::queue<Vehiculo> cola;  // Cola de vehículos esperando en la caseta
    float totalRecaudado;  // Total recaudado hasta el momento
    std::map<int, float> totalesParciales;  // Total recaudado por tipo de vehículo

public:
    // Constructor para inicializar la caseta con un ID
    Caseta(int i) : id(i), totalRecaudado(0) {}

    // Método para añadir un vehículo a la cola de la caseta
    void añadirVehiculo(const Vehiculo& v) {
        cola.push(v);
    }

    // Método para procesar el cobro del vehículo al frente de la cola
    void procesarCobro(float tarifa) {
        if (!cola.empty()) {  // Verifica si hay vehículos en la cola
            Vehiculo v = cola.front();  // Toma el vehículo al frente de la cola
            cola.pop();  // Retira el vehículo de la cola
            totalRecaudado += tarifa;  // Actualiza el total recaudado
            totalesParciales[v.getTipo()] += tarifa;  // Actualiza el total para el tipo de vehículo
        }
    }

    // Método para realizar el arqueo de caja, reiniciando las cuentas de la caseta
    float realizarArqueo() {
        float total = totalRecaudado;  // Guarda el total recaudado
        totalRecaudado = 0;  // Reinicia el total recaudado
        totalesParciales.clear();  // Limpia los totales parciales por tipo
        return total;  // Retorna el total recaudado hasta el momento
    }

    // Método para obtener el tamaño de la cola (opcional)
    int getColaSize() const {
        return cola.size();
    }

    // Método para obtener el ID de la caseta (opcional)
    int getId() const {
        return id;
    }
};

// Clase PuntoDeCobro: representa un punto de cobro con múltiples casetas.
class PuntoDeCobro {
private:
    std::vector<Caseta> casetas;  // Colección de casetas en el punto de cobro
    std::map<int, float> tarifas;  // Tabla de tarifas por tipo de vehículo

public:
    // Constructor para inicializar el punto de cobro con una tabla de tarifas
    PuntoDeCobro(const std::map<int, float>& t) : tarifas(t) {}

    // Método para añadir una caseta al punto de cobro
    void añadirCaseta(const Caseta& c) {
        casetas.push_back(c);
    }

    // Método para registrar la llegada de un vehículo y ubicarlo en la caseta con menos vehículos
    void registrarLlegada(const Vehiculo& v) {
        // Encuentra la caseta con menos vehículos en cola
        auto casetaConMenosVehiculos = std::min_element(casetas.begin(), casetas.end(),
            [](const Caseta& a, const Caseta& b) {
                return a.getColaSize() < b.getColaSize();
            });
        casetaConMenosVehiculos->añadirVehiculo(v);  // Añade el vehículo a la caseta encontrada
    }

    // Método para procesar el cobro en una caseta específica por su ID
    void procesarCobroEnCaseta(int id) {
        for (auto& caseta : casetas) {
            if (caseta.getId() == id) {  // Encuentra la caseta por su ID
                caseta.procesarCobro(tarifas[caseta.getId()]);  // Procesa el cobro con la tarifa correspondiente
                break;
            }
        }
    }

    // Método para realizar el arqueo de caja de todas las casetas en el punto de cobro
    void realizarArqueoDeTodasCasetas() {
        for (auto& caseta : casetas) {
            float total = caseta.realizarArqueo();  // Realiza el arqueo de cada caseta
            // Aquí podrías hacer algo con el total recaudado por cada caseta, si es necesario.
        }
    }
};
