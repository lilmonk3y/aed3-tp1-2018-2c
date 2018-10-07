//
// Created by Christian nahuel Rivera on 05/10/2018.
//
#include <iostream>
#include <cmath>
#include <fstream>
#include "../backtracking/src/Backtracking.h"
#include "../backtracking/src/EstrategiaFuerzaBruta.h"
#include "../backtracking/src/EstrategiaBacktracking.h"
#include "../programacion_dinamica/src/ProgramacionDinamica.h"

double tiemposProgramacionDinamica(ProgramacionDinamica *programacionDinamica, int limpiarDatos, int valorObjetivo,
                                   std::vector<int> &originalSet);
double
tiemposBacktracking(Backtracking *backtracking, int limpiarDatos, int valorObjetivo, std::vector<int> &originalSet);
double
tiemposFuerzaBruta(Backtracking *backtracking, int limpiarDatos, int valorObjetivo, std::vector<int> &originalSet);

std::vector<int> crearInstanciaExperimento(int elementos, int objetivo);

std::vector<int> crearInstanciaExperimento4(int elementos, int objetivo);

std::vector<int> crearInstanciaExperimento5(int elementos, int objetivo);

int main(){
    std::cout << "steady_clock" << std::endl;
    std::cout << std::chrono::steady_clock::period::num << std::endl;
    std::cout << std::chrono::steady_clock::period::den << std::endl;
    std::cout << "steady = " << std::boolalpha << std::chrono::steady_clock::is_steady << std::endl << std::endl;


    Backtracking *fuerzaBruta = new Backtracking(new EstrategiaFuerzaBruta);
    Backtracking *backtracking = new Backtracking(new EstrategiaBacktracking);
    ProgramacionDinamica *programacionDinamica = new ProgramacionDinamica();

    int limpiarDatos = 100;
    int tamanoMaximoInstancia;
    int valorObjetivo;

    std::vector<int> originalSet;
/*
     * Experimento 0
     * Los tres algoritmos compiten entre ellos.
     * La idea es ver el comportamiento de los mismos en igualdad de condiciones sin perjudicar a ninguno en especial.
*/
    valorObjetivo = 50;
    tamanoMaximoInstancia = 20;
    std::ofstream tiempos;
    tiempos.open("experimento_0.csv",std::ios::out);
    tiempos << "instancias,n,v,fruerza_bruta,backtracking,programacion_dinamica" << std::endl;
    for(int cantidadElementos = 1; cantidadElementos <= tamanoMaximoInstancia; cantidadElementos++){

        originalSet = crearInstanciaExperimento(cantidadElementos, valorObjetivo);

        tiempos << cantidadElementos << "," << cantidadElementos << "," << valorObjetivo << ",";

        double mediana;
        mediana = tiemposFuerzaBruta(fuerzaBruta, limpiarDatos, valorObjetivo, originalSet);
        tiempos << mediana << ",";

        mediana = tiemposBacktracking(backtracking, limpiarDatos, valorObjetivo, originalSet);
        tiempos << mediana << ",";

        mediana = tiemposProgramacionDinamica(programacionDinamica, limpiarDatos, valorObjetivo, originalSet);
        tiempos << mediana << std::endl;
    }
    tiempos.close();

/*
     * Experimento 1
     * Compiten BT y PD
     * La idea es perjudicar a PD teniendo un V muy grande.
     * OBS: Intenté con INT_MAX/2 pero notermina.
*/
    // valorObjetivo = INT_MAX/2;
    //valorObjetivo = 500*500;
    valorObjetivo = 100*100;
    tamanoMaximoInstancia = 20;
    std::ofstream tiempos1;
    tiempos1.open("experimento_1.csv",std::ios::out);
    tiempos1 << "instancias,n,v,backtracking,programacion_dinamica" << std::endl;
    for(int cantidadElementos = 1; cantidadElementos <= tamanoMaximoInstancia; cantidadElementos++){

        originalSet = crearInstanciaExperimento(cantidadElementos, valorObjetivo);

        tiempos1 << cantidadElementos << "," << cantidadElementos << "," << valorObjetivo << ",";

        double mediana;
        mediana = tiemposBacktracking(backtracking, limpiarDatos, valorObjetivo, originalSet);
        tiempos1 << mediana << ",";

        mediana = tiemposProgramacionDinamica(programacionDinamica, limpiarDatos, valorObjetivo, originalSet);
        tiempos1 << mediana << std::endl;
    }
    tiempos1.close();

/*
     * Experimento 2
     * Compiten BT y PD
     * V fijo y N ordenado de menor a mayor. Esto va a ayudar a BT ya que este va a cortar muchas más ramas por sus podas
*/
    valorObjetivo = 100;
    tamanoMaximoInstancia = 50;
    std::ofstream tiempos2;
    tiempos2.open("experimento_2.csv",std::ios::out);
    tiempos2 << "instancias,n,v,backtracking,programacion_dinamica" << std::endl;
    for(int cantidadElementos = 1; cantidadElementos <= tamanoMaximoInstancia; cantidadElementos++){

        originalSet = crearInstanciaExperimento(cantidadElementos, valorObjetivo*2);
        std::sort(originalSet.begin(),originalSet.end());

        tiempos2 << cantidadElementos << "," << cantidadElementos << "," << valorObjetivo << ",";

        double mediana;
        mediana = tiemposBacktracking(backtracking, limpiarDatos, valorObjetivo, originalSet);
        tiempos2 << mediana << ",";

        mediana = tiemposProgramacionDinamica(programacionDinamica, limpiarDatos, valorObjetivo, originalSet);
        tiempos2 << mediana << std::endl;
    }
    tiempos2.close();

    /*
     * Experimento 3
     * Compiten BT y PD
     * V fijo y N ordenado de mayor a menor. Esto va a perjudicar a BT porque va a podar mucho menos.
    */
    valorObjetivo = 100;
    tamanoMaximoInstancia = 50;
    std::ofstream tiempos3;
    tiempos3.open("experimento_3.csv",std::ios::out);
    tiempos3 << "instancias,n,v,backtracking,programacion_dinamica" << std::endl;
    for(int cantidadElementos = 1; cantidadElementos <= tamanoMaximoInstancia; cantidadElementos++){

        originalSet = crearInstanciaExperimento(cantidadElementos, valorObjetivo*2);
        std::sort(originalSet.begin(),originalSet.end(),std::greater<int>());

        tiempos3 << cantidadElementos << "," << cantidadElementos << "," << valorObjetivo << ",";

        double mediana;
        mediana = tiemposBacktracking(backtracking, limpiarDatos, valorObjetivo, originalSet);
        tiempos3 << mediana << ",";

        mediana = tiemposProgramacionDinamica(programacionDinamica, limpiarDatos, valorObjetivo, originalSet);
        tiempos3 << mediana << std::endl;
    }
    tiempos3.close();

    /*
     * Experimento 4
     * Compiten BT y PD
     * V fijo y N con los elementos entre [0,n-1) mayores que V y el elemento n-1 tiene a V.
     * Por esto se perjudica a BT porque tiene que ver el arbol de completo.
     */
    valorObjetivo = 100;
    tamanoMaximoInstancia = 50;
    std::ofstream tiempos4;
    tiempos4.open("experimento_4.csv",std::ios::out);
    tiempos4 << "instancias,n,v,backtracking,programacion_dinamica" << std::endl;
    for(int cantidadElementos = 1; cantidadElementos <= tamanoMaximoInstancia; cantidadElementos++){

        originalSet = crearInstanciaExperimento4(cantidadElementos, valorObjetivo);

        tiempos4 << cantidadElementos << "," << cantidadElementos << "," << valorObjetivo << ",";

        double mediana;
        mediana = tiemposBacktracking(backtracking, limpiarDatos, valorObjetivo, originalSet);
        tiempos4 << mediana << ",";

        mediana = tiemposProgramacionDinamica(programacionDinamica, limpiarDatos, valorObjetivo, originalSet);
        tiempos4 << mediana << std::endl;
    }
    tiempos4.close();

    /*
     * Experimento 5
     * Compiten BT y PD
     * V fijo y N con los elementos entre [1,n) mayores que V y el elemento 0 tiene a V.
     * Por esto se beneficia a BT porque va a podar mucho.
     */
    valorObjetivo = 100;
    tamanoMaximoInstancia = 50;
    std::ofstream tiempos5;
    tiempos5.open("experimento_5.csv",std::ios::out);
    tiempos5 << "instancias,n,v,backtracking,programacion_dinamica" << std::endl;
    for(int cantidadElementos = 1; cantidadElementos <= tamanoMaximoInstancia; cantidadElementos++){

        originalSet = crearInstanciaExperimento5(cantidadElementos, valorObjetivo);

        tiempos5 << cantidadElementos << "," << cantidadElementos << "," << valorObjetivo << ",";

        double mediana;
        mediana = tiemposBacktracking(backtracking, limpiarDatos, valorObjetivo, originalSet);
        tiempos5 << mediana << ",";

        mediana = tiemposProgramacionDinamica(programacionDinamica, limpiarDatos, valorObjetivo, originalSet);
        tiempos5 << mediana << std::endl;
    }
    tiempos5.close();


    return 0;
}

std::vector<int> crearInstanciaExperimento5(int cantidadDeElementos, int valorObjetivo) {
    std::vector<int> instancia;
    instancia.resize(cantidadDeElementos);
    for(int index = 1; index < cantidadDeElementos; index++){
        instancia.at(index) = std::rand() % (valorObjetivo*2) + valorObjetivo+1;
    }
    instancia.at(0) = valorObjetivo;
    return instancia;
}

std::vector<int> crearInstanciaExperimento4(int cantidadDeElementos, int valorObjetivo) {
    std::vector<int> instancia;
    instancia.resize(cantidadDeElementos);
    for(int index = 0; index < cantidadDeElementos; index++){
        instancia.at(index) = std::rand() % (valorObjetivo*2) + valorObjetivo+1;
    }
    instancia.at(cantidadDeElementos-1) = valorObjetivo;
    return instancia;
}

/*
 * Instancia con valores entre 0 y el valor objetivo.
 */
std::vector<int> crearInstanciaExperimento(int cantidadDeElementos, int valorObjetivo){
    std::vector<int> instancia;
    instancia.resize(cantidadDeElementos);
    for(int index = 0; index < cantidadDeElementos; index++){
        instancia.at(index) = std::rand() % valorObjetivo;
    }
    return instancia;
}


double tiemposProgramacionDinamica(ProgramacionDinamica *programacionDinamica, int limpiarDatos, int valorObjetivo,
                                   std::vector<int> &originalSet) {
    std::vector<double> tiemposALimpiar;
    tiemposALimpiar.resize(limpiarDatos);
    for(int limpiar = 0; limpiar < limpiarDatos; limpiar++){

            auto tiempo_inicio = std::__1::chrono::steady_clock::now();
            programacionDinamica->execute(originalSet,valorObjetivo);
            auto tiempo_final = std::__1::chrono::steady_clock::now();
            auto diferencia = tiempo_final - tiempo_inicio;
            tiemposALimpiar.at(limpiar) = std::__1::chrono::duration <double, std::__1::milli> (diferencia).count();

        }
    sort(tiemposALimpiar.begin(),tiemposALimpiar.end());
    return tiemposALimpiar.at(std::floor(tiemposALimpiar.size() / 2));
}

double
tiemposBacktracking(Backtracking *backtracking, int limpiarDatos, int valorObjetivo, std::vector<int> &originalSet) {
    std::vector<double> tiemposALimpiar;
    tiemposALimpiar.resize(limpiarDatos);
    for(int limpiar = 0; limpiar < limpiarDatos; limpiar++){

        auto tiempo_inicio = std::__1::chrono::steady_clock::now();
        backtracking->execute(originalSet,valorObjetivo);
        auto tiempo_final = std::__1::chrono::steady_clock::now();
        auto diferencia = tiempo_final - tiempo_inicio;
        tiemposALimpiar.at(limpiar) = std::__1::chrono::duration <double, std::__1::milli> (diferencia).count();

    }
    sort(tiemposALimpiar.begin(),tiemposALimpiar.end());
    return tiemposALimpiar.at(std::floor(tiemposALimpiar.size() / 2));
}

double
tiemposFuerzaBruta(Backtracking *fuerzaBruta, int limpiarDatos, int valorObjetivo, std::vector<int> &originalSet) {
    std::vector<double> tiemposALimpiar;
    tiemposALimpiar.resize(limpiarDatos);
    for(int limpiar = 0; limpiar < limpiarDatos; limpiar++){

        auto tiempo_inicio = std::__1::chrono::steady_clock::now();
        fuerzaBruta->execute(originalSet,valorObjetivo);
        auto tiempo_final = std::__1::chrono::steady_clock::now();
        auto diferencia = tiempo_final - tiempo_inicio;
        tiemposALimpiar.at(limpiar) = std::__1::chrono::duration <double, std::__1::milli> (diferencia).count();

    }
    sort(tiemposALimpiar.begin(),tiemposALimpiar.end());
    return tiemposALimpiar.at(std::floor(tiemposALimpiar.size() / 2));
}
