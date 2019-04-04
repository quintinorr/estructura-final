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
#define cantidadEquipos 2
#define cantidadJugadores 5
#define cantidadTiempos 500
#define tiemposNormal 4

int tiempoActual = 0;
int EQUIPOS[cantidadEquipos][cantidadTiempos ][cantidadJugadores];

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

void ReadTimePoints(){
  // Leemos los puntos por cada tiempo.
  int tiempo;
  for(tiempo = 0; tiempo < tiemposNormal; tiempo++) {
    ReadTeamPoints(tiempo);
  }
  tiempoActual = tiempo;
  printf("**** FIN LECTURA ****\n\n");
}

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

    // printf("Total de puntos del equipo %i: %i puntos\n",equipo + 1, totalEquipo);

    if(totalEquipo > puntosGanador){
      puntosGanador = totalEquipo;
      equipoGanador = equipo;
    } else if(totalEquipo == puntosGanador) {
      equipoGanador = -404;
    }
  }

  return equipoGanador;
}

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

// Imprimir el resultado de cada tiempo para cada jugador.
void PrintResult() {
  printf("******************************************************************\n");
  printf("*                       Tabla de puntuación                      *\n");
  printf("******************************************************************\n");

  int equipo;
  for(equipo = 0; equipo < cantidadEquipos; equipo++) {
  printf("------------------------------------------------------------------\n");
  printf("                            Equipo %i                           \n", equipo + 1);
  printf("------------------------------------------------------------------\n");
    PrintTeamResultTable(equipo);
    printf("\n\n");
  }
}

void PrintWinner(int winner) {
  if (winner != -404){
      printf("\n\n******************************************************************\n");
      printf("*           Felicidades equipo: %i, ¡son los ganadores!           *\n",winner+1);
      printf("******************************************************************\n");
  } else {
      printf("\n\n******************************************************************\n");
      printf("*                      Ha ocurrido un empate                     *\n");
      printf("******************************************************************\n");
  }
}

int main(void) {
  
  ReadTimePoints();
  PrintResult();
  // Tiempo extra.
  int winner;
  while((winner = GetWinnerTeam()) == -404) {
      PrintWinner(winner);  
      ReadTeamPoints(tiempoActual);
      tiempoActual++;
  }

  PrintWinner(winner);

  return 0;
}
