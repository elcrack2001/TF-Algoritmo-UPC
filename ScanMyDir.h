#pragma once

#include "Librerias.h"

class ScanMyDir {
private:
	long peso_archivo;
public:

	ScanMyDir(void) { this->peso_archivo = 0; }

	// ----------------------------------------------------- ARCHIVOS ----------------------------------------------------------

	void MostrarNombresArchivos(String^ carpeta)
	{
		DirectoryInfo ^ubicacion = gcnew DirectoryInfo(carpeta);
		for each  (auto variable in ubicacion->GetFiles())
		{
			Console::ForegroundColor = ConsoleColor::White;
			cout << msclr::interop::marshal_as<std::string>(variable->Name) << endl << endl;
		}
	}

	void MostrarFechasArchivos(String^ carpeta)
	{
		DirectoryInfo ^ubicacion = gcnew DirectoryInfo(carpeta);
		for each  (auto variable in ubicacion->GetFiles())
		{
			Console::ForegroundColor = ConsoleColor::Gray;
			cout << msclr::interop::marshal_as<std::string>(variable->Name) << endl;
			Console::ForegroundColor = ConsoleColor::White;
			cout << "Año: " << int(variable->CreationTime.Year) << " Mes: " << int(variable->CreationTime.Month) << " Dia: " << int(variable->CreationTime.Day) << endl << endl;
		}
	}

	void MostrarPesoArchivos(String^ carpeta)
	{
		DirectoryInfo ^ubicacion = gcnew DirectoryInfo(carpeta);
		for each  (auto variable in ubicacion->GetFiles())
		{
			Console::ForegroundColor = ConsoleColor::White;
			cout << msclr::interop::marshal_as<std::string>(variable->Name) << endl;
			Console::ForegroundColor = ConsoleColor::Yellow;
			cout << "Tamaño: " << int(variable->Length) << endl << endl;
			peso_archivo += int(variable->Length);
		}
	}

	void MostrarPesoArchivos_UsarParaHallarPesoSubcarpetas(String^ carpeta)
	{
		DirectoryInfo ^ubicacion = gcnew DirectoryInfo(carpeta);
		for each  (auto variable in ubicacion->GetFiles())
		{
			peso_archivo += int(variable->Length);
		}
	}

	void MostrarPesoArchivosMayor(String^ carpeta)
	{
		DirectoryInfo ^ubicacion = gcnew DirectoryInfo(carpeta);
		int cantidad_archivos;
		MaxHeap*heap = new MaxHeap(100);
		for each  (auto variable in ubicacion->GetFiles())
		{
			Console::ForegroundColor = ConsoleColor::White;
			cout << msclr::interop::marshal_as<std::string>(variable->Name) << endl;
			Console::ForegroundColor = ConsoleColor::Yellow;
			cout << "Tamaño: " << int(variable->Length) << endl << endl;
			cantidad_archivos++;
			heap->insert(variable->Length);
		}
		cout << endl << " .::::::::::::::::::::::::::::::: MAYOR A MENOR :::::::::::::::::::::::::::::::." << endl << endl;
		for (int i = 0; i < cantidad_archivos; i++) {
			Console::ForegroundColor = ConsoleColor::Cyan;
			cout << "Posicion [ " << i << " ] =>    " << heap->extract() << endl;
		}
	}

	void MostrarPesoArchivosMenor(String^ carpeta)
	{
		DirectoryInfo ^ubicacion = gcnew DirectoryInfo(carpeta);
		int cantidad_archivos;
		MinHeap*heap = new MinHeap(100);
		for each  (auto variable in ubicacion->GetFiles())
		{
			Console::ForegroundColor = ConsoleColor::White;
			cout << msclr::interop::marshal_as<std::string>(variable->Name) << endl;
			Console::ForegroundColor = ConsoleColor::Yellow;
			cout << "Tamaño: " << int(variable->Length) << endl << endl;
			cantidad_archivos++;
			heap->insert(variable->Length);
		}
		cout << endl << " .::::::::::::::::::::::::::::::: MENOR A MAYOR :::::::::::::::::::::::::::::::." << endl << endl;
		for (int i = 0; i < cantidad_archivos; i++) {
			Console::ForegroundColor = ConsoleColor::Cyan;
			cout << "Posicion [ " << i << " ] =>    " << heap->extract() << endl;
		}
	}

	void MostrarExtencionArchivos(String^ carpeta)
	{
		DirectoryInfo ^ubicacion = gcnew DirectoryInfo(carpeta);
		for each  (auto variable in ubicacion->GetFiles())
		{
			Console::ForegroundColor = ConsoleColor::White;
			cout << msclr::interop::marshal_as<std::string>(variable->Extension) << endl << endl;
		}
	}

	void MostrarRutaCompletaArchivos(String^ carpeta)
	{
		DirectoryInfo ^ubicacion = gcnew DirectoryInfo(carpeta);
		for each  (auto variable in ubicacion->GetFiles())
		{
			Console::ForegroundColor = ConsoleColor::White;
			cout << msclr::interop::marshal_as<std::string>(variable->FullName) << endl << endl;
		}
	}

	// ------------------------------------------------------------------------------------------------------------------------

	// ----------------------------------------------------- SUB CARPETAS -----------------------------------------------------

	void MostrarNombresSubcarpetas(String^ carpeta)
	{
		DirectoryInfo ^ubicacion = gcnew DirectoryInfo(carpeta);
		for each  (auto variable in ubicacion->GetDirectories())
		{
			Console::ForegroundColor = ConsoleColor::White;
			cout << msclr::interop::marshal_as<std::string>(variable->Name) << endl << endl;
		}
	}
	
	void MostrarFechasSubcarpetas(String^ carpeta)
	{
		DirectoryInfo ^ubicacion = gcnew DirectoryInfo(carpeta);
		for each  (auto variable in ubicacion->GetDirectories())
		{
			Console::ForegroundColor = ConsoleColor::Gray;
			cout << msclr::interop::marshal_as<std::string>(variable->Name) << endl;
			Console::ForegroundColor = ConsoleColor::White;
			cout << "Año: " << int(variable->CreationTime.Year) << " Mes: " << int(variable->CreationTime.Month) << " Dia: " << int(variable->CreationTime.Day) << endl << endl;
		}
	}

	void MostrarPesoSubcarpetas(String^ carpeta)
	{
		DirectoryInfo ^ubicacion = gcnew DirectoryInfo(carpeta);
		string ruta;
		for each  (auto variable in ubicacion->GetDirectories())
		{
			Console::ForegroundColor = ConsoleColor::Green;
			cout << msclr::interop::marshal_as<std::string>(variable->Name) << endl << endl;
			Console::ForegroundColor = ConsoleColor::Cyan;
			cout << "peso " << peso_archivo << endl << endl;
			Console::ForegroundColor = ConsoleColor::Red;
			ruta = msclr::interop::marshal_as<std::string>(variable->FullName);
			cout << endl << endl;
			MostrarPesoArchivos_UsarParaHallarPesoSubcarpetas(msclr::interop::marshal_as<String^>(ruta));
			MostrarPesoSubcarpetas(msclr::interop::marshal_as<String^>(ruta));
		}
	}

	void MostrarContenidoSubcarpetas(String^ carpeta)
	{
		DirectoryInfo ^ubicacion = gcnew DirectoryInfo(carpeta);
		string ruta;
		for each  (auto variable in ubicacion->GetDirectories())
		{
			Console::ForegroundColor = ConsoleColor::Red;
			cout << msclr::interop::marshal_as<std::string>(variable->Name) << endl << endl;
			ruta = msclr::interop::marshal_as<std::string>(variable->FullName);
			Console::ForegroundColor = ConsoleColor::Cyan;
			MostrarNombresArchivos(msclr::interop::marshal_as<String^>(ruta));
			MostrarContenidoSubcarpetas(msclr::interop::marshal_as<String^>(ruta));
		}
	}

	void MostrarRutaCompletaSubCarpetas(String^ carpeta)
	{
		DirectoryInfo ^ubicacion = gcnew DirectoryInfo(carpeta);
		string ruta;
		for each  (auto variable in ubicacion->GetDirectories())
		{
			Console::ForegroundColor = ConsoleColor::White;
			cout << msclr::interop::marshal_as<std::string>(variable->FullName) << endl << endl;
			ruta = msclr::interop::marshal_as<std::string>(variable->FullName);
			MostrarRutaCompletaSubCarpetas(msclr::interop::marshal_as<String^>(ruta));
		}
	}

	// ------------------------------------------------------------------------------------------------------------------------

	long tamaño_archivo() { return peso_archivo; }
};