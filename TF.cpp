#include "Librerias.h"
#include <Windows.h>

#define ESPACIO 32

void Menu() {
	Console::ForegroundColor = ConsoleColor::Red;
	Console::SetCursorPosition(25, 5);
	cout << " .:::::::::::::::::MENU::::::::::::::::::.";
	Console::ForegroundColor = ConsoleColor::Cyan;
	Console::SetCursorPosition(25, 7);
	cout << " a)  INGRESAR LA RUTA";
	Console::SetCursorPosition(25, 9);
	cout << " b)  MOSTRAR LOS ARCHIVOS DE LA RUTA";
	Console::SetCursorPosition(25, 11);
	cout << " c)  MOSTRAR LAS SUBCARPETAS DE LA RUTA";
	Console::SetCursorPosition(25, 13);
	cout << " d)  MOSTRAR ANIO DE CREACION DE ARCHIVOS";
	Console::SetCursorPosition(25, 15);
	cout << " e)  MOSTRAR ANIO DE CREACION DE LAS SUB CARPETAS";
	Console::SetCursorPosition(25, 17);
	cout << " f)  MOSTRAR PESO DE ARCHIVOS";
	Console::SetCursorPosition(25, 19);
	cout << " g)  MOSTRAR PESO DEL ARCHIVO MAYOR A MENOR (SIN NOMBRE)";
	Console::SetCursorPosition(25, 21);
	cout << " h)  MOSTRAR PESO DEL ARCHIVO MENOR A MAYOR (SIN NOMBRE)";
	Console::SetCursorPosition(25, 23);
	cout << " i)  MOSTRAR PESO DE SUB CARPERTAS";
	Console::SetCursorPosition(25, 25);
	cout << " j) MOSTRAR CONTENIDO SUB CARPETAS (NO LEE DIRECTORIOS 'C:/' . SOLO RUTAS 'C:/EJEMPLO')";
	Console::SetCursorPosition(25, 27);
	cout << " k) MOSTRAR EXTENCION DEL ARCHIVO";
	Console::SetCursorPosition(25, 29);
	cout << " l) MOSTRAR RUTA COMPLETA DEL ARCHIVO";
	Console::SetCursorPosition(25, 31);
	cout << " m) MOSTRAR RUTA COMPLETA SUB CARPETAS";
	Console::SetCursorPosition(25, 33);
	cout << " S) SALIR";
}

int main() {
	Console::CursorVisible = false;
	string ruta;
	ScanMyDir*Dir = new ScanMyDir();
	Menu();

	while (true) {
		if (_kbhit()) {
			char opcion = _getch();
			opcion = toupper(opcion);
			if (opcion == 'A') {
				Console::Clear();
				Console::ForegroundColor = ConsoleColor::DarkGray;
				cout << "Coloque la ruta: "; getline (cin, ruta);
				Console::ForegroundColor = ConsoleColor::Green;
				cout << endl << endl << endl << "PRESIONE 'SPACE' PARA VOLVER AL MENU";
			} // opcion a
			if (opcion == 'B') {
				Console::Clear();
				Dir->MostrarNombresArchivos(msclr::interop::marshal_as<String^>(ruta));
				Console::ForegroundColor = ConsoleColor::Green;
				cout << endl << endl << endl << "PRESIONE 'SPACE' PARA VOLVER AL MENU";
			} // opcion b
			if (opcion == 'C') {
				Console::Clear();
				Dir->MostrarNombresSubcarpetas(msclr::interop::marshal_as<String^>(ruta));
				Console::ForegroundColor = ConsoleColor::Green;
				cout << endl << endl << endl << "PRESIONE 'SPACE' PARA VOLVER AL MENU";
			} // opcion c
			if (opcion == 'D') {
				Console::Clear();
				Dir->MostrarFechasArchivos(msclr::interop::marshal_as<String^>(ruta));
				Console::ForegroundColor = ConsoleColor::Green;
				cout << endl << endl << endl << "PRESIONE 'SPACE' PARA VOLVER AL MENU";
			} // opcion d
			if (opcion == 'E') {
				Console::Clear();
				Dir->MostrarFechasSubcarpetas(msclr::interop::marshal_as<String^>(ruta));
				Console::ForegroundColor = ConsoleColor::Green;
				cout << endl << endl << endl << "PRESIONE 'SPACE' PARA VOLVER AL MENU";
			} // opcion e
			if (opcion == 'F') {
				Console::Clear();
				Dir->MostrarPesoArchivos(msclr::interop::marshal_as<String^>(ruta));
				Console::ForegroundColor = ConsoleColor::Green;
				cout << endl << endl << endl << "PRESIONE 'SPACE' PARA VOLVER AL MENU";
			} // opcion f
			if (opcion == 'G') {
				Console::Clear();
				Dir->MostrarPesoArchivosMayor(msclr::interop::marshal_as<String^>(ruta));
				Console::ForegroundColor = ConsoleColor::Green;
				cout << endl << endl << endl << "PRESIONE 'SPACE' PARA VOLVER AL MENU";
			} // opcion g
			if (opcion == 'H') {
				Console::Clear();
				Dir->MostrarPesoArchivosMenor(msclr::interop::marshal_as<String^>(ruta));
				Console::ForegroundColor = ConsoleColor::Green;
				cout << endl << endl << endl << "PRESIONE 'SPACE' PARA VOLVER AL MENU";
			} // opcion h
			if (opcion == 'I') {
				Console::Clear();
				Dir->MostrarPesoSubcarpetas(msclr::interop::marshal_as<String^>(ruta));
				Console::ForegroundColor = ConsoleColor::Green;
				cout << endl << endl << endl << "PRESIONE 'SPACE' PARA VOLVER AL MENU";
			} // opcion i
			if (opcion == 'J') {
				Console::Clear();
				Dir->MostrarContenidoSubcarpetas(msclr::interop::marshal_as<String^>(ruta));
				Console::ForegroundColor = ConsoleColor::Green;
				cout << endl << endl << endl << "PRESIONE 'SPACE' PARA VOLVER AL MENU";
			} // opcion j
			if (opcion == 'K') {
				Console::Clear();
				Dir->MostrarExtencionArchivos(msclr::interop::marshal_as<String^>(ruta));
				Console::ForegroundColor = ConsoleColor::Green;
				cout << endl << endl << endl << "PRESIONE 'SPACE' PARA VOLVER AL MENU";
			} // opcion k
			if (opcion == 'L') {
				Console::Clear();
				Dir->MostrarRutaCompletaArchivos(msclr::interop::marshal_as<String^>(ruta));
				Console::ForegroundColor = ConsoleColor::Green;
				cout << endl << endl << endl << "PRESIONE 'SPACE' PARA VOLVER AL MENU";
			} // opcion k
			if (opcion == 'M') {
				Console::Clear();
				Dir->MostrarRutaCompletaSubCarpetas(msclr::interop::marshal_as<String^>(ruta));
				Console::ForegroundColor = ConsoleColor::Green;
				cout << endl << endl << endl << "PRESIONE 'SPACE' PARA VOLVER AL MENU";
			} // opcion k
			if (opcion == 'S') {
				Console::Clear();
				break;
				Console::ForegroundColor = ConsoleColor::Green;
				Console::SetCursorPosition(50, 50);
				cout << "ADIOS";
			} // opcion k
			if (opcion == ESPACIO) {
				Console::Clear();
				Menu();
			} // ESPACIO
		}
	}
	_getch();
	return 0;
} 