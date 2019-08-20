/*
 * =====================================================================================
 *
 *       Filename:  LibroCalificaciones.h
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


#ifndef CALIFICACIONES_LIBROCALIFICACIONES_H
#define CALIFICACIONES_LIBROCALIFICACIONES_H

#include <string>

static const int ESTUDIANTES = 10;
static const int EXAMENES = 3;

class LibroCalificaciones {
private:

    std::string nombreCurso;
    int calificaciones[ESTUDIANTES][EXAMENES];
    int obtenerNotaMinima();
    int obtenerNotaMaxima();
    double obtenerPromedio(int);

public:
    LibroCalificaciones();
    LibroCalificaciones(const std::string, int[][EXAMENES]);
    void setNombreCurso(const std::string);
    std::string getNombreCurso();
    std::string obtenerReporteNotas();
    std::string obtenerReporteNotasMaxMin();


};


#endif //CALIFICACIONES_LIBROCALIFICACIONES_H
