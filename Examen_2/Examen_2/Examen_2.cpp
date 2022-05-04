// Examen_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include<iostream>
#include"Estudiantes.h"
int main()
{

	string nombres, apellidos, direccion, genero, email;
	int telefono, id_Estudiante, carnet, fecha_nacimiento;
	cout << "Ingrese id del estudiante: ";
	cin >> id_Estudiante;
	cout << "Ingrese el carnet: ";
	cin >> carnet;
	cout << "Ingrese nombres: ";
	getline(cin, nombres);
	cout << "Ingrese apellidos: ";
	getline(cin, apellidos);
	cout << "Ingrese la direccion: ";
	cin >> direccion;
	cout << "Ingrese telefono: ";
	cin >> telefono;
	cout << "Ingrese el genero: ";
	cin >> genero;
	cout << "Ingrese el email: ";
	cin >> email;
	cout << "Ingrese la fecha de nacimientos: ";
	cin >> fecha_nacimiento;
	cin.ignore();
	Estudiantes x = Estudiantes(id_Estudiante, carnet, nombres,apellidos, direccion, telefono, genero, email, fecha_nacimiento);
	x.crear();
	x.leer();

	return 0;
}


