#pragma once
#include<mysql.h>
#include<iostream>
#include<string>
#include"Conexion.h"
#include "Persona.h"
using namespace std;
class Estudiantes :Persona {
	// atributos
private: string nit;
	   // constructor
public:
	Estudiantes() {
	}
	Estudiantes(string nom, string ape, string dir, string gen, string em, int tel, int id, int car, int f) : Persona(nom, ape, dir, gen, em, tel, id, car, f) {
	}
	//metodos
	//set (modificar)
	void setNit(int id) { id_Estudiante = id; }
	void setNit(int car) { carnet = car; }
	void setNombres(string nom) { nombres = nom; }
	void setApellidos(string ape) { apellidos = ape; }
	void setDireccion(string dir) { direccion = dir; }
	void setTelefono(int tel) { telefono = tel; }
	void setDireccion(string gen) { genero = gen; }
	void setDireccion(string em) { email = em; }
	void setTelefono(int f) { fecha_nacimiento = f; }

	//get (mostrar)
	int getId_Estudiante() { return id_Estudiante; }
	int getCarnet() { return carnet; }
	string getNombres() { return nombres; }
	string getApellidos() { return apellidos; }
	string getDireccion() { return direccion; }
	int getTelefono() { return telefono; }
	string getGenero() { return genero; }
	string getEmail() { return email; }
	int getFecha_nacimiento() { return fecha_nacimiento; }
	void crear() {
		int q_estado;
		Conexion cn = Conexion();
		if (cn.getConectar()) {
			string t = to_string(telefono);
			string d = to_string(id_Estudiante);
			string c = to_string(carnet);
			string fn = to_string(fecha_nacimiento);
			string insert = "INSERT INTO estudiantes(id_Estudiantes,carnet,nombres,apellidos,direccion,telefono,genero,email,fecha_nacimiento)VALUES('" + d + "','" + c + "','" + nombres + "','" + apellidos + "','" + direccion + ",'" + t + ",'" + genero + ",'" + email + ",'" + fn + "'); ";
			const char* i = insert.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Ingreso Exitoso..." << endl;
			}
			else {
				cout << "Error de informacion..." << endl;
			}
		}
		else {
			cout << "Error en la conexion......" << endl;
		}cn.cerrar_conexion();
	}

	//metodos
	void leer() {
		int q_estado;
		Conexion cn = Conexion();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "select * from proveedor";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "," << fila[1] << "," << fila[2] << "," << fila[3] << "," << fila[4] << "," << fila[5] << "," << fila[6] << "," << fila[7]<< "," << fila[8]<< "," << fila[9]<<endl;
				}
			}
		}
		else {
			cout << "Error en la conexion......" << endl;
		}
		cn.cerrar_conexion();
	}

	void eliminar(int id_Estudiantes) {

		int q_estado;
		Conexion cn = Conexion();

		cn.abrir_conexion();

		if (cn.getConectar()) {
			string d = to_string(id_Estudiante);
			string eliminar = "DELETE from estudiantes where id_estudiante = " + d + "";
			const char* i = eliminar.c_str();
			q_estado = mysql_query(cn.getConectar(), i);

			if (!q_estado) {
				system("cls");
				cout << "Eliminacion exitosa" << endl;
			}
		}
		else {
			system("cls");
			cout << "Hubo un error a la hora de eliminar el registro deseado" << endl;
			system("pause");
		}
		cn.cerrar_conexion();
		system("pause");
	}
};
