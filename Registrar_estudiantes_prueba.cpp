#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Estudiante {
	string nombre;
	string cu;
	int edad;
	int asistencia;
};
vector<Estudiante> estudiantes;

void datosEstudiante() {
	Estudiante nuevoEstudiante;
	cout << "Ingrese el nombre completo del estudiante: ";
	cin.ignore();
	getline(cin, nuevoEstudiante.nombre); //Se utiliza getline porque 'cin' solo recoge los datos hasta el primer espacio.
	cout << "Ingrese su C.U. (incluir el '-' por favor): ";
	cin >> nuevoEstudiante.cu;
	cout << "Ingresar edad: " << endl;
	cin >> nuevoEstudiante.edad;
	cout << "ingrese asistencia (Use 0 = negativo || Use 1 = afirmativo" << endl;
	cin >> nuevoEstudiante.asistencia;
	estudiantes.push_back(nuevoEstudiante); //agregando nuevo elemento al vector de forma dinamica.
}
void mostrarEstudiante() {
	cout << "Los estudiantes son: " << endl;
	for (const auto& estudiante : estudiantes) {
		cout << "Nombres: " << estudiante.nombre << endl;
		cout << "CU; " << estudiante.cu << endl;
		cout << "Edad: " << estudiante.edad << endl;
		cout << "Asistencia: " << estudiante.asistencia << endl;
	}
}
//Utilizamos un blucle for para aceder a cada uno de los elementos del vector utilizando declarando la variable estudiantes.
//Tambien al hacer uso de 'auto' delegamos al compilador decidir que tipo de variable manejara y haciendo que 'estudiantes' funcione como contador .
void buscarEstudiante() {
	string cuBuscar;
	cout << "Ingrese el numero CU del estudiante que desea buscar: ";
	cin >> cuBuscar;
	for (const auto& estudiante : estudiantes) {
		if (estudiante.cu == cuBuscar) {
			cout << "Datos del Estudiante:" << endl;
			cout << "Nombres: " << estudiante.nombre << endl;
			cout << "CU; " << estudiante.cu << endl;
			cout << "Edad: " << estudiante.edad << endl;
			cout << "Asistencia: " << estudiante.asistencia << endl;
			return;
		}
	}
	cout << "El estudiante no existe o ingreso mal el CU" << endl;
}
void eliminarEstudiante() {
	string cuElimina;
	cout << "Ingrese el CU del estudiante que desea eliminar" << endl;
	cin >> cuElimina;
	for (auto i = estudiantes.begin(); i != estudiantes.end(); ++i) {
		if (i->cu == cuElimina) {
			i = estudiantes.erase(i);
			cout << "Eliminacion exitosa" << endl;
			return;
		}
	}
	cout << "El estudiante no existe o ingreso mal el CU" << endl;
}
void insertarEstudiante() {
	cout << "proximamente...";

}
void mostrarEstudianteHabilitados() {
	cout << "Los habilitado para el examen son: " << endl;
	for (const auto& estudiante : estudiantes) {
		if (estudiante.asistencia > 10) {
			cout << "Nombre: " << estudiante.nombre << endl;
			cout << "CU: " << estudiante.cu << endl;
			cout << "Edad: " << estudiante.edad << endl;
			cout << "Asistencia: " << estudiante.asistencia << endl;
		}
	}
}
void mostrarAsistenciaEstudiante() {
	string cuBuscar;
	cout << "Ingresar el CU del estudiante al que desea ver su asustencia: ";
	cin >> cuBuscar;
	for (const auto& estudiante : estudiantes) {
		if (estudiante.cu == cuBuscar) {
			cout << "Asistencia del estudiante es: " << estudiante.asistencia << endl;
			return;
		}
	}
	cout << "El estudiante no existe o ingreso mal el CU" << endl;
}
int main(int argc, char* argv[]) {
	int opcion;
	cout << "Menu de opciones:" << endl;
	cout << "1.- Introducir datos de estudiante" << endl;
	cout << "2.- Mostrar a los estudiantes" << endl;
	cout << "3.- Buscar a un estudiante" << endl;
	cout << "4.- Eliminar a un estudiante" << endl;
	cout << "5.- Insertar un estudiante" << endl;
	cout << "6.- Mostrar estudiantes habilitados para examen" << endl;
	cout << "7.- Mostrar asistencias de un estudiante" << endl;
	cout << "8.- Salir" << endl;
	cout << "Ingrese una opcion: ";
	cin >> opcion;
	switch (opcion) {
	case 1:
		datosEstudiante();
		break;
	case 2:
		mostrarEstudiante();
		break;
	case 3:
		buscarEstudiante();
		break;
	case 4:
		eliminarEstudiante();
		break;
	case 5:
		insertarEstudiante();
		break;
	case 6:
		mostrarEstudianteHabilitados();
		break;
	case 7:
		mostrarAsistenciaEstudiante();
		break;
	case 8:
		cout << "Saliendo..." << endl;
		break;
	default:
		cout << "Opcion no valida. Por favor ingrese una opcion valida." << endl;
		break;
	}
	return 0;
}
