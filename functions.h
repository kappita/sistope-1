#include "structs.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/ioctl.h>


// Entradas: Char* (string), int* número de celdas
// Salidas: bool
// Descripción: Recibe el string de opt y verifica que sea un número válido y lo guarda en el puntero
int handleNumber(char *opt, int *cells);
// Entradas: Char* (string)
// Salidas: bool
// Descripción: Recibe el string de opt y verifica que sea un nombre de archivo válido y que exista
int handleInputFile(char *opt);
// Entradas: Char* (string)
// Salidas: bool
// Descripción: Recibe el string de opt y verifica que sea un nombre de archivo válido
int handleOutputFile(char *opt);
// Entradas: int
// Salidas: material*
// Descripción: Crea un material a partir de la cantidad de celdas que tiene 
material* createMaterial(int cellCount);
// Entradas: int, int, int, int
// Salidas: double
// Descripción: Aplica la fórmula para el cálculo de Ei,j
double impactFormula(int cellPos, int impactedCellPos, int cellEnergy, int cellCount);
// Entradas: Material*, int, int
// Salidas: void
// Descripción: impacta el material con la partícula entregada por partes
void impactMaterial(material *mat, int particlePos, int particleEnergy);
// Entradas: FILE*, material*
// Salidas: void
// Descripción: Revisa todas las partículas y aplica los impactos correspondientes
int simulateImpacts(FILE *fp, material *mat);
// Entradas: Material*
// Salidas: int
// Descripción: Obtiene la posición de la celda del material con mayor energía acumulada
int getMaxEnergyCellPos(material* mat);
// Entradas: double 
// Salidas: int
// Descripción: Obtiene la cantidad de dígitos de la parte entera de un número
int getCharAmount(double number);
// Entradas: int, int, int, double
// Salidas: void
// Descripción: Imprime por pantalla la información de la celda, normalizado
void printCell(int cellPos, int energyChars, int cellsChars, double cellEnergy);
// Entradas: double, double
// Salidas: void
// Descripción: Imprime por pantalla la energía normalizada
void printCellEnergy(double cellEnergy, double part);
// Entradas: material*
// Salidas: void
// Descripción: Imprime la información de las celdas del material
void printEnergy(material* mat);
// Entradas: FILE*, int, int, int, double
// Salidas: void
// Descripción: Escribe en un archivo la energía almacenada en una celda,
//              teniendo cuidado de normalizar los datos con los caracteres
//              de los números máximos del total de celdas.
void writeCell(FILE *fp, int cellPos, int energyChars, int maxCellsChars, double cellEnergy);
// Entradas: FILE*, material*
// Salidas: void
// Descripción: Escribe la energía de un material en un archivo
void writeEnergy(FILE *fp, material* mat);
// Entradas: material*
// Salidas: void
// Descripción: Libera la memoria alojada por un material.
void freeMaterial(material* mat);
