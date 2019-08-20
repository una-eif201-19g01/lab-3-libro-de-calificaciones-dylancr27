/*
 * =====================================================================================
 *
 *       Filename:  LibroCalificaciones.cpp
 *
 *    Description:  Reporte de calificaciones
 *
 *        Created:  2019-08-13
 *
 *         Author:  Dylan Molina Obando
 *   Organization:  Universidad Nacional de Costa Rica
 *
 * =====================================================================================
 */

#include "LibroCalificaciones.h"
#include <iomanip>
#include <iostream>


LibroCalificaciones::LibroCalificaciones(){}

void LibroCalificaciones::setNombreCurso(::std nomcurso){
    nombreCurso=nomcurso;
}

std::string LibroCalificaciones::getNombreCurso(){
    return nombreCurso;
}

LibroCalificaciones::LibroCalificaciones(const std::string &nombreCurso, int arregloCalificaciones[][EXAMENES]) {
    setNombreCurso(nombreCurso);

    for (int fil = 0; fil < ESTUDIANTES; fil++) {
        for (int col = 0; col < EXAMENES; col++) {
            calificaciones[fil][col] = arregloCalificaciones[fil][col];
        }
    }
}

int LibroCalificaciones:: obtenerNotaMaxima() {
    int mayor=0;
    for (int fil = 0; fil < ESTUDIANTES; fil++) {
        for (int col = 0; col < EXAMENES; col++) {
            if (calificaciones[fil][col] > mayor) 
                 mayor= calificaciones[fil][col];
        }
    }
    return mayor;
}

int LibroCalificaciones::obtenerNotaMinima() {
    int menor = 100;
    for (int fil = 0; fil < ESTUDIANTES; fil++) {
        for (int col = 0; col < EXAMENES; col++) {
            if (calificaciones[fil][col] < menor)
                menor = calificaciones[fil][col];

        }
    }
    return menor;
}

double LibroCalificaciones::obtenerPromedio(int col){
    double suma=0.0;
    for(int fil;fil<EXAMENES;fil++){
        suma=suma+calificaciones[col][fil];
    }
    return suma/EXAMENES;
}

std::string LibroCalificaciones::obtenerReporteNotasMaxMin() {
    std::string reporte;
    reporte = "\nLa nota minima es:[" + std::to_string(obtenerNotaMinima())+"\n";
    reporte += "La nota Maxima es:[" + std::to_string(obtenerNotaMaxima());
    return reporte;
}

std::string LibroCalificaciones::obtenerReporteNotas() {
    std::string reportenot = "\nLas siguientes son las notas del curso [PROGRA 1]";
    int numExa = 1;

    while (numExa <= EXAMENES) {
        reportenot = reportenot + "\tExamen" + to_string(numExa) + "\t";
        numExa++;
    }
    reportenot = reportenot + "\tPromedio";
    for (int fil = 0; fil < ESTUDIANTES, fil++) {
        reportenot = reportenot + "n\Estudiante[" + to_string(fil) + "]\t\t\t";
        for (int col = 0; col < EXAMENES; col++) {
            reportenot = reportenot + to_string(calificaciones[fil][col]) + "\t\t";
        }
        reportenot = reportenot + to_string(obtenerPromedio(fil));
    }
    return reportenot;
}
