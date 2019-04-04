#include <stdio.h>

// Definimos las constantes de nuestro programa.
#define cantidadEquipos 2
#define cantidadJugadores 5
#define cantidadTiempos 4

//
int EQUIPOS[cantidadEquipos][cantidadTiempos][cantidadJugadores];

void ReadPlayersPoints(int equipo, int tiempo) {
  printf("Inserte los puntos para el equipo %i en el tiempo %i\n", equipo + 1 , tiempo + 1);

  int jugador;
  for(jugador = 0; jugador < cantidadJugadores; jugador++){
    printf("    -Jugador %i: ", jugador + 1);
    int puntos = 0;
    scanf("%i", &puntos);
    EQUIPOS[equipo][tiempo][jugador] = puntos;
  }
}

void ReadTimePoints(int equipo){
  int tiempo;
  for(tiempo = 0; tiempo < cantidadTiempos; tiempo++){
    ReadPlayersPoints(equipo, tiempo);
    printf("  --Fin de tiempo %i--\n", tiempo + 1);
  }
  printf("\n");
}

void ReadTeamPoints(){
  int equipo;
  for(equipo = 0; equipo < cantidadEquipos; equipo++){
    ReadTimePoints(equipo);
    printf("**Fin de equipo %i**\n", equipo + 1);
  }
  printf("\n");
}

int GetWinnerTeam(){

  int equipoGanador = 0;
  int puntosGanador = 0;

  int equipo;
  for(equipo = 0; equipo < cantidadEquipos; equipo++){
    int totalEquipo = 0;
    
    int tiempo;
    for(tiempo = 0; tiempo < cantidadTiempos; tiempo++){
      int totalTiempo = 0;
      
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
    }
  }

  return equipoGanador;
}

// Imprimir el resultado de cada tiempo para cada jugador.
void PrintResult() {
  printf("**************** TABLA DE PUNTUACION ****************\n");
  int equipo;
  // Recorremos los equipos.
  for(equipo = 0; equipo < cantidadEquipos; equipo++){
    printf("Puntos para el equipo %i:\n", equipo);
    int tiempo;
    //Recorremos los tiempos del equipo;
    for(tiempo = 0; tiempo < cantidadTiempos; tiempo++){
      printf("  +Tiempo %i\n", tiempo);
      int jugador;
      // Recorremos la cantidad de jugadores por equipo.
      for(jugador = 0; jugador < cantidadJugadores; jugador++){
        int puntos = EQUIPOS[equipo][tiempo][jugador];
        printf("    -Jugador %i: %i\n", jugador, puntos);
      }
    }
  }
}

int main(void) {
  ReadTeamPoints();
  PrintResult();
  int winner = GetWinnerTeam();
  printf("%i",winner);
  return 0;
}
