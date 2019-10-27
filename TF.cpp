#include "Librerias.h"

#define ESPACIO 32

using namespace std;
using namespace System;
using namespace System::IO;

void ScanMyDirFilesName(String^ carpeta)
{
	DirectoryInfo ^ubicacion = gcnew DirectoryInfo(carpeta);
	DirectoryInfo ^ubicacionsub = gcnew DirectoryInfo(carpeta);
	Console::ForegroundColor = ConsoleColor::Gray;
	for each  (auto variable in ubicacion->GetFiles())
	{
		cout << msclr::interop::marshal_as<std::string>(variable->Name) << endl << endl;
	}
}

void ScanMyDirFilesFecha(String^ carpeta)
{
	DirectoryInfo ^ubicacion = gcnew DirectoryInfo(carpeta);
	DirectoryInfo ^ubicacionsub = gcnew DirectoryInfo(carpeta);
    Console::ForegroundColor = ConsoleColor::Gray;
	
	for each  (auto variable in ubicacion->GetFiles())
	{
		cout << msclr::interop::marshal_as<std::string>(variable->Name) << endl;
		cout << "Año: " << int(variable->CreationTime.Year) << " Mes: " << int(variable->CreationTime.Month) << " Dia: " << int(variable->CreationTime.Day) << endl << endl;
	}
}

void ScanMyDirFilesPeso(String^ carpeta)
{
	DirectoryInfo ^ubicacion = gcnew DirectoryInfo(carpeta);
	DirectoryInfo ^ubicacionsub = gcnew DirectoryInfo(carpeta);
	Console::ForegroundColor = ConsoleColor::Gray;
	for each  (auto variable in ubicacion->GetFiles())
	{
		cout << msclr::interop::marshal_as<std::string>(variable->Name) << endl;
		cout << "Tamaño: " << int(variable->Length) << endl << endl;
	}
}

void ScanMyDirFilesPesoMayor(String^ carpeta)
{
	DirectoryInfo ^ubicacion = gcnew DirectoryInfo(carpeta);
	DirectoryInfo ^ubicacionsub = gcnew DirectoryInfo(carpeta);
	Console::ForegroundColor = ConsoleColor::Gray;
	int cantidad_archivos;
	MaxHeap*heap = new MaxHeap(100);

	for each  (auto variable in ubicacion->GetFiles())
	{
		cout << msclr::interop::marshal_as<std::string>(variable->Name) << endl;
		cout << "Tamaño: " << int(variable->Length) << endl << endl;
		cantidad_archivos++;
		heap->insert(variable->Length);
	}
	cout << endl << " .::::::::::::::::::::::::::::::: MAYOR A MENOR :::::::::::::::::::::::::::::::." << endl << endl;
	for (int i = 0; i < cantidad_archivos; i++) {
		cout << "Posicion [ " << i << " ] =>    " << heap->extract() << endl;
	}
}

void ScanMyDirFilesPesoMenor(String^ carpeta)
{
	DirectoryInfo ^ubicacion = gcnew DirectoryInfo(carpeta);
	DirectoryInfo ^ubicacionsub = gcnew DirectoryInfo(carpeta);
	Console::ForegroundColor = ConsoleColor::Gray;
	int cantidad_archivos;
	MinHeap*heap = new MinHeap(100);

	for each  (auto variable in ubicacion->GetFiles())
	{
		cout << msclr::interop::marshal_as<std::string>(variable->Name) << endl;
		cout << "Tamaño: " << int(variable->Length) << endl << endl;
		cantidad_archivos++;
		heap->insert(variable->Length);
	}
	cout << endl << " .::::::::::::::::::::::::::::::: MENOR A MAYOR :::::::::::::::::::::::::::::::." << endl << endl;
	for (int i = 0; i < cantidad_archivos; i++) {
		cout << "Posicion [ " << i << " ] =>    " << heap->extract() << endl;
	}
}

void ScanMyDirFilesExtension(String^ carpeta)
{
	DirectoryInfo ^ubicacion = gcnew DirectoryInfo(carpeta);
	DirectoryInfo ^ubicacionsub = gcnew DirectoryInfo(carpeta);
	Console::ForegroundColor = ConsoleColor::Gray;
	for each  (auto variable in ubicacion->GetFiles())
	{
		cout << msclr::interop::marshal_as<std::string>(variable->Extension) << endl << endl;
	}
}

void ScanMyDirFilesRutaTotal(String^ carpeta)
{
	DirectoryInfo ^ubicacion = gcnew DirectoryInfo(carpeta);
	DirectoryInfo ^ubicacionsub = gcnew DirectoryInfo(carpeta);
	Console::ForegroundColor = ConsoleColor::White;
	for each  (auto variable in ubicacion->GetFiles())
	{
		cout << msclr::interop::marshal_as<std::string>(variable->FullName) << endl << endl;
	}
}

void Menu() {
	Console::ForegroundColor = ConsoleColor::Red;
	Console::SetCursorPosition(35, 5);
	cout << " .:::::::::::::::::MENU::::::::::::::::::.";
	Console::ForegroundColor = ConsoleColor::DarkCyan;
	Console::SetCursorPosition(35, 7);
	cout << " 1) INGRESAR LA RUTA";
	Console::SetCursorPosition(35, 9);
	cout << " 2) MOSTRAR LOS ARCHIVOS DE LA RUTA";
	Console::SetCursorPosition(35, 11);
	cout << " 3) MOSTRAR ANIO DE CREACION";
	Console::SetCursorPosition(35, 13);
	cout << " 4) MOSTRAR PESO DEL ARCHIVO";
	Console::SetCursorPosition(35, 15);
	cout << " 5) MOSTRAR PESO DEL ARCHIVO MAYOR A MENOR (SIN NOMBRE)";
	Console::SetCursorPosition(35, 17);
	cout << " 6) MOSTRAR PESO DEL ARCHIVO MENOR A MAYOR (SIN NOMBRE)";
	Console::SetCursorPosition(35, 19);
	cout << " 7) MOSTRAR EXTENCION DEL ARCHIVO";
	Console::SetCursorPosition(35, 21);
	cout << " 8) MOSTRAR RUTA COMPLETA DEL ARCHIVO";
	Console::SetCursorPosition(35, 23);
	cout << " 9) SALIR";
}

int main() {
	Console::CursorVisible = false;
  	string asd;

	Menu();
	while (true) {
		if (_kbhit()) {
			char opcion = _getch();
			if (opcion == '1') {
				Console::Clear();
				Console::ForegroundColor = ConsoleColor::Green;
				cout << "Coloque la ruta (Sin ESPACIOS en el nombre de la ruta): "; cin >> asd;
				cout << endl << endl << endl << "PRESIONE 'SPACE' PARA VOLVER AL MENU";
			} // opcion 1
			if (opcion == '2') {
				Console::Clear();
				ScanMyDirFilesName(msclr::interop::marshal_as<String^>(asd));
				Console::ForegroundColor = ConsoleColor::Green;
				cout << endl << endl << endl << "PRESIONE 'SPACE' PARA VOLVER AL MENU";
			} // opcion 2
			if (opcion == '3') {
				Console::Clear();
				ScanMyDirFilesFecha(msclr::interop::marshal_as<String^>(asd));
				Console::ForegroundColor = ConsoleColor::Green;
				cout << endl << endl << endl << "PRESIONE 'SPACE' PARA VOLVER AL MENU";
			} // opcion 3
			if (opcion == '4') {
				Console::Clear();
				ScanMyDirFilesPeso(msclr::interop::marshal_as<String^>(asd));
				Console::ForegroundColor = ConsoleColor::Green;
				cout << endl << endl << endl << "PRESIONE 'SPACE' PARA VOLVER AL MENU";
			} // opcion 4
			if (opcion == '5') {
				Console::Clear();
				ScanMyDirFilesPesoMayor(msclr::interop::marshal_as<String^>(asd));
				Console::ForegroundColor = ConsoleColor::Green;
				cout << endl << endl << endl << "PRESIONE 'SPACE' PARA VOLVER AL MENU";
			} // opcion 6
			if (opcion == '6') {
				Console::Clear();
				ScanMyDirFilesPesoMenor(msclr::interop::marshal_as<String^>(asd));
				Console::ForegroundColor = ConsoleColor::Green;
				cout << endl << endl << endl << "PRESIONE 'SPACE' PARA VOLVER AL MENU";
			} // opcion 7
			if (opcion == '7') {
				Console::Clear();
				ScanMyDirFilesExtension(msclr::interop::marshal_as<String^>(asd));
				Console::ForegroundColor = ConsoleColor::Green;
				cout << endl << endl << endl << "PRESIONE 'SPACE' PARA VOLVER AL MENU";
			} // opcion 5
			if (opcion == '8') {
				Console::Clear();
				ScanMyDirFilesRutaTotal(msclr::interop::marshal_as<String^>(asd));
				Console::ForegroundColor = ConsoleColor::Green;
				cout << endl << endl << endl << "PRESIONE 'SPACE' PARA VOLVER AL MENU";
			} // opcion 6
			if (opcion == '9') {
				Console::Clear();
				Console::SetCursorPosition(50, 10);
				cout << "    ADIOS";
				break;
			}
			if (opcion == ESPACIO) {
				Console::Clear();
				Menu();
			}
		}
	}
	_getch();
	return 0;
}