//
// Created by kevin on 05/05/19.
//

#ifndef INC_2_SIMULACION_H
#define INC_2_SIMULACION_H
#include"Poblacion.h"
#include "AStar.h"
#include "Backtracking.h"
#include "Server.h"
#include <iostream>
#include "ArduinoManager.h"
/**
 * Clase encargada del flow del programa
 * @author elorim
 * @date 05/05/19
 * */
 using namespace std;
class MainExe {
public:
    /**
     * Constructor, inicializa todas las variables para dar inicio, aqui se crea la primera iteracion
     * @author elorim
     * */
    MainExe(int game_size);
    ~MainExe();

    /**
     * Inicia la simulacion, asume primera generacion iniciada
     * @author elorim
     * */
    void iniciar();

    /**
    * Crea el tablero matriz del juego segun el tamano especificado
    * @author Cvaztian
    * */
    void createMap(int size);       //Crea el mapa de referencia (0=vacio, 1=torre normal, 2=torre fuego, 3=torre explosiva y 4=jugador)

    /**
    * Anade una torre a la matriz del juego
    * @author Cvaztian
    * */
    void addTower(int type, int pos_x, int pos_y);      //Añade un valor de torre a una posición específica de la matriz mapa (1=normal, 2=fuego, 3=explosivos)

    /**
    * Revisa si hay algun camino posible
    * @author Cvaztian
    * */
    void checkAvailability();

    /**
    * Aleatoriza las torres en la matriz del juego
    * @author Cvaztian
    * */
    void rearrangeTowers();

    /**
    * Mueve las torres en direcciones aleatorias
    * @author Cvaztian
    * */
    LinkedList<int> moveTowers();

    /**
    * Crea un array con los atributos ordenados de cada gladiador
    * @author Cvaztian
    * */
    int *atributeArray(Gladiator *glad, int poblacion);

    /**
    * Crea una lista enlazada de los movimientos de cada gladiador en formato
    * @author Cvaztian
    * */
    LinkedList<LinkedList<int>> formatMovements(int counter);

    /**
    * Mueve un gladiador de una posicion a la siguiente en la matriz
    * @author Cvaztian
    * */
    void moveGladiator(int x_i, int y_i, int x_f, int y_f);

    int emptySpaces();

    bool isUnblocked(int pos_x, int pos_y);

    void setProbabilidadSuperviencia();

    Gladiator* mejorGladiator(Poblacion * poblacion);

private:
    //Atributos
    Poblacion* poblacionA; /**Poblacion de A*/
    Poblacion* poblacionB; /**Poblacion de Backtracking*/
    LinkedList<LinkedList<int>>* map_matrix;
public:
    LinkedList<LinkedList<int>> *getMapMatrix() const;

private:
    /**Tablero matriz del juego, 0 es torre normal, 1 es torre fuego, 2 es torre explosiva*/
    AStar* aStar;    /**Buscador AStar*/
    Backtracking* backtracking;  /**Buscador Backtracking*/
    int iteration_ctr;
    int matrix_size;
    int tower_ctr;
    Server server;
    ArduinoManager *arduinoManager;

    //Metodos
    void siguienteIteracion();

};


#endif //INC_2_SIMULACION_H
