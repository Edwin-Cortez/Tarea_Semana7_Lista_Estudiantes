#include <iostream>
#include <string>

using namespace std;

// 1. estructura iniciada como las instrucciones:
struct Nodo {
    int carne;
    string nombre;
    string apellido;
    string carrera;
    Nodo* siguiente;
};

// FUNCIONES AUXILIARES
// Función para pedir los datos al usuario y crear el espacio en memoria.
Nodo* crearNodo() {
    Nodo* nuevo = new Nodo(); // Uso de memoria dinámica (new).

    cout << "\nIngrese carne: ";
    cin >> nuevo->carne;
    cin.ignore(); // Necesario limpiar el buffer después de un cin numérico para utilizar el getline.

    cout << "Ingrese nombre: ";
    getline(cin, nuevo->nombre); // Permite leer nombres con espacios.

    cout << "Ingrese apellido: ";
    getline(cin, nuevo->apellido);

    cout << "Ingrese carrera: ";
    getline(cin, nuevo->carrera);

    nuevo->siguiente = nullptr; // Al crearlo, el nodo no apunta a nadie.
    return nuevo;
}

// OPERACIONES DE LA LISTA
// 1. Insertar al inicio:
void insertarInicio(Nodo*& head) {
    Nodo* nuevo = crearNodo();
    nuevo->siguiente = head; // El nuevo nodo apunta al que antes era el primero.
    head = nuevo; // Ahora la cabeza de la lista es el nuevo nodo.
    cout << "-> Estudiante insertado al inicio con exito.\n";
}

// 2. Insertar al final:
void insertarFinal(Nodo*& head) {
    Nodo* nuevo = crearNodo();

    // Si la lista está vacía, el nuevo nodo es el primero.
    if (head == nullptr) {
        head = nuevo;
    } else {
        // Recorremos hasta llegar al último nodo.
        Nodo* temporal = head;
        while (temporal->siguiente != nullptr) {
            temporal = temporal->siguiente;
        }
        temporal->siguiente = nuevo; // Conectamos el último con el nuevo.
    }
    cout << "-> Estudiante insertado al final con exito.\n";
}

// 3. Mostramos todos:
void mostrarEstudiantes(Nodo* head) {
    if (head == nullptr) {
        cout << "\n-> La lista esta vacia.\n";
        return;
    }

    Nodo* temporal = head;
    cout << "\n--- LISTA DE ESTUDIANTES ---\n";
    while (temporal != nullptr) {
        cout << "Carne: " << temporal->carne << endl;
        cout << "Nombre: " << temporal->nombre << endl;
        cout << "Apellido: " << temporal->apellido << endl;
        cout << "Carrera: " << temporal->carrera << endl;
        cout << "----------------------------\n";
        temporal = temporal->siguiente; // Avanzamos al siguiente nodo.
    }
}

// 4. Para buscar un estudiante:
void buscarEstudiante(Nodo* head) {
    if (head == nullptr) {
        cout << "\n-> La lista esta vacia.\n";
        return;
    }

    int carneBuscar;
    cout << "\nIngrese carne a buscar: ";
    cin >> carneBuscar;

    Nodo* temporal = head;
    while (temporal != nullptr) {
        if (temporal->carne == carneBuscar) {
            cout << "\nEstudiante encontrado:\n";
            cout << "Nombre: " << temporal->nombre << endl;
            cout << "Apellido: " << temporal->apellido << endl;
            cout << "Carrera: " << temporal->carrera << endl;
            return; // Salimos de la función al encontrarlo
        }
        temporal = temporal->siguiente;
    }
    // Si termina el ciclo y no lo encontró.
    cout << "\n-> Estudiante no encontrado.\n";
}

// 5. Para eliminar un estudiante:
void eliminarEstudiante(Nodo*& head) {
    if (head == nullptr) {
        cout << "\n-> La lista esta vacia.\n";
        return;
    }

    int carneEliminar;
    cout << "\nIngrese carne del estudiante a eliminar: ";
    cin >> carneEliminar;

    // Caso A: El nodo a eliminar es el primero (head).
    if (head->carne == carneEliminar) {
        Nodo* nodoAEliminar = head;
        head = head->siguiente; // La cabeza ahora es el segundo nodo.
        delete nodoAEliminar;   // Liberamos la memoria usando (delete)
        cout << "-> Estudiante eliminado correctamente.\n";
        return;
    }

    // Caso B: El nodo está en el medio o al final.
    Nodo* actual = head;
    Nodo* anterior = nullptr;

    // Buscamos el nodo.
    while (actual != nullptr && actual->carne != carneEliminar) {
        anterior = actual;
        actual = actual->siguiente;
    }

    // Cuando no se encontro.
    if (actual == nullptr) {
        cout << "-> Estudiante no encontrado.\n";
        return;
    }

    // Si se encontro desenlazamos y eliminamos.
    anterior->siguiente = actual->siguiente; // El anterior ahora apunta al siguiente del actual.
    delete actual; // Liberamos memoria utilizando (delete)
    cout << "-> Estudiante eliminado correctamente.\n";
}

// FUNCIÓN PRINCIPAL Y MENÚ:
int main() {
    Nodo* head = nullptr; // Inicializamos la lista vacía.
    int opcion;

    do {
        cout << "\n=========================================\n";
        cout << " ESTUDIANTE: [Edwin Oswaldo Cortez Tista]\n";
        cout << "=========================================\n";
        cout << "           MENU DE OPCIONES\n";
        cout << "1. Insertar estudiante al inicio\n";
        cout << "2. Insertar estudiante al final\n";
        cout << "3. Mostrar todos los estudiantes\n";
        cout << "4. Buscar estudiante por carne\n";
        cout << "5. Eliminar estudiante\n";
        cout << "6. Salir\n";
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1: insertarInicio(head); break;
            case 2: insertarFinal(head); break;
            case 3: mostrarEstudiantes(head); break;
            case 4: buscarEstudiante(head); break;
            case 5: eliminarEstudiante(head); break;
            case 6: cout << "\nSaliendo del programa...\n"; break;
            default: cout << "\n-> Opcion no valida.\n";
        }
    } while (opcion != 6);

    return 0;
}