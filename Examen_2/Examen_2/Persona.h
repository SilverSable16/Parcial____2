#pragma once
#include <iostream>
using namespace std;
class Persona {
protected: string nombres, apellidos, direccion, genero, email;
		 int telefono, id_Estudiante, carnet, fecha_nacimiento;

protected:
	Persona() {
	}
	Persona(string nom, string ape, string dir, string gen, string em, int tel, int id, int car, int f) {
		nombres = nom;
		apellidos = ape;
		direccion = dir;
		genero = gen;
		email = em;
		telefono = tel;
		id_Estudiante = id;
		carnet = car;
		fecha_nacimiento = f;

	}
};

