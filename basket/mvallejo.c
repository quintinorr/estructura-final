/*
Un juego de basketball se juega en cuatro tiempos, participan dos equipos y cada equipo posee 5 jugadores. 
Suponiendo que no haya cambios de jugadores, escriba un programa que sea capaz de almacenar los puntos encestados 
por cada jugador de cada equipo en cada tiempo. Estos puntos deben acumularse para cada uno de los 
jugadores de cada equipo en cada tiempo y luego imprimir los resultados del juego en cada tiempo para cada jugador. 
Las lecturas deben hacerse en un ciclo y este ciclo debe terminar cuando se digite el tiempo número 5.
Y gana el equipo que tenga más puntos. Si al final del 5to tiempo hay empate, se va a tiempo extra y 
dicho tiempo extra será hasta el infinito. Este tiempo extra acabará cuando ya no haya jugadores disponibles 
en condición física CREATIVIDAD y MUCHO ESMERO.
Grupo 5 - Estructura de datos.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Definimos las constantes de nuestro programa.
#define cantidadEquipos 2         // Define la cantidad de equipos que soporta el sistema.
#define cantidadJugadores 1       // Cantidad de jugadores soportados por el sistema
#define cantidadTiempos 5       // Almacena el límite de tiempos de un partido.
#define tiemposNormal 2           // Almacena la cantidad de tiempos que tiene un partido antes de validar la puntiación.

// Valiables.
int tiempoActual = 0;             // Indica el tiempo en que se está jugando.
int EQUIPOS[cantidadEquipos][cantidadTiempos][cantidadJugadores];           // Arreglo de 3 dimensiones que almacena los puntos por jugador, tiempo y partido.

// Función auxiliar que retorna la cantidad de caracteres de un número entero.
int GetIntLength(int numero) {
	int longitud = 1;
	int resultado = numero;
	int divisor = 10;

	while(resultado > 9) {
		resultado = numero / divisor;
		longitud++;
		divisor *= 10;
	}

	return longitud;
}

// Lee los puntos de cada jugador de un equipo en un tiempo dado.
void ReadPlayersPoints(int equipo, int tiempo) {
  int jugador;
  for(jugador = 0; jugador < cantidadJugadores; jugador++){
    printf("    - Jugador %i: ", jugador + 1);
    int puntos = 0;
    scanf("%i", &puntos);
    EQUIPOS[equipo][tiempo][jugador] = puntos;
  }
  printf("\n");
}

// Lee Los puntos de un equipo en un tiempo dado.
void ReadTeamPoints(int tiempo) {
  printf("Inserte los puntos para el tiempo %i: \n", tiempo + 1);
  // Leemos los puntos por cada equipo en el tiempo dado.
  int equipo;
  for(equipo = 0; equipo < cantidadEquipos; equipo++) {
    printf("  + Equipo %i:\n", equipo + 1);
    ReadPlayersPoints(equipo, tiempo);
  }
  printf("** Fin del tiempo %i **\n\n", tiempo + 1);
}

// Recorre los tiempos y va leyendo los puntods de los jugadores por cada equipo.
void ReadTimePoints(){
  int tiempo;
  for(tiempo = 0; tiempo < tiemposNormal; tiempo++) {
    ReadTeamPoints(tiempo);
  }
  tiempoActual = tiempo;
  printf("**** FIN LECTURA ****\n\n");
}

// Devuelve el índice del arreglo que indica el equipo ganador.
// Devuelve -404 si hay un empate.
int GetWinnerTeam(){

  int equipoGanador = -404;
  int puntosGanador = 0;

  // Recorremos los equipos.
  int equipo;
  for(equipo = 0; equipo < cantidadEquipos; equipo++){
    int totalEquipo = 0;
    
    // Recorremos los tiempos de cada equipo.
    int tiempo;
    for(tiempo = 0; tiempo < tiempoActual; tiempo++){
      int totalTiempo = 0;
      
      //Recorremos los jugadores de cada equipo por cada tiempo.
      int jugador;
      for(jugador = 0; jugador < cantidadJugadores; jugador++){
        int puntos = EQUIPOS[equipo][tiempo][jugador];
        totalTiempo += puntos;
      }

      totalEquipo += totalTiempo;
    }

    if(totalEquipo > puntosGanador){
      puntosGanador = totalEquipo;
      equipoGanador = equipo;
    } else if(totalEquipo == puntosGanador) {
      equipoGanador = -404;
    }
  }

  return equipoGanador;
}

// Imprime los resultados de los jugadores en cada tiempo, del equipo indicado.
void PrintTeamResultTable(int equipo) {
  int jugador;
  printf("          |");
  for(jugador = 0; jugador < cantidadJugadores; jugador++){
    printf(" Jugador %i |", jugador + 1);
  }

  int tiempo;
  for(tiempo = 0; tiempo < tiempoActual; tiempo++){
    printf("\n Tiempo %i |", tiempo + 1);
      int jugador;
      // Recorremos la cantidad de jugadores por equipo.
      for(jugador = 0; jugador < cantidadJugadores; jugador++){
        int puntos = EQUIPOS[equipo][tiempo][jugador];

        int lenPuntos = GetIntLength(puntos);
        float resSpace = (((float)12 - (float)lenPuntos) / (float)2);
        int leftSpace = floor(resSpace);
        int rightSpace = ceil(resSpace);

        int i;
        for(i = 0; i < leftSpace; i++) {
          printf(" ");
        }

        printf("%i", puntos);

        for(i = 0; i < rightSpace; i++) {
          printf(" ");
        }
      }
  }
}

// Imprimime la tabla de puntuación de los equipos.
void PrintResult() {
  printf("****************************************************************************\n");
  printf("*                            Tabla de puntuación                           *\n");
  printf("****************************************************************************\n");

  int equipo;
  for(equipo = 0; equipo < cantidadEquipos; equipo++) {
  printf("----------------------------------------------------------------------------\n");
  printf("                                 Equipo %i                                \n", equipo + 1);
  printf("----------------------------------------------------------------------------\n");
    PrintTeamResultTable(equipo);
    printf("\n\n");
  }
}

// Imprime los resultados del equipo ganador.
void PrintWinner(int winner) {
  if (winner != -404){
      printf("****************************************************************************\n");
      printf("*           Felicidades equipo: %i, ¡son los ganadores!           *\n",winner+1);
      printf("****************************************************************************\n");
  } else {
      printf("****************************************************************************\n");
      printf("*                           Ha ocurrido un empate                          *\n");
      printf("****************************************************************************\n");
  }
}

int main(void) {
  //Leemos las puntuaciones de los primeros tiempos.
  ReadTimePoints();
  // Imprimimos los resultados de los primeros tiempos.
  PrintResult();

  // Valida el equipo ganador. En caso de que haya un empate, sigue en el bucle hasta que se llegue a un desempate o hasta 
  // que el programa supere el límite indicado en la constante de arriba 
  // (Los jugadores no se encuentran en condiciones para seguir jugando).
  int winner;
  while((winner = GetWinnerTeam()) == -404) {
      PrintWinner(winner);  
      ReadTeamPoints(tiempoActual);
      tiempoActual++;

      if(tiempoActual == cantidadTiempos){
        printf("Los jugadores no se encuentran en condiciones para seguir jugando. Partido terminado.\n");
        break;
      }
  }

  PrintResult();
  PrintWinner(winner);

  return 0;
}
