#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <dos.h>


int main (void)
{

int LebronTGL,PedroTGL,JuanTGL,AntonioTGL,EmilioTGL,TGL; // jugadores del equipo 1 TGL = Tigres del Licey
int DavidAGC,JavierAGC,MarioAGC,SergioAGC,MarcosAGC,AGC; // jugaores del equipo 2 AGC = Aguilas Cibaeñas

int LebronTGLs,PedroTGLs,JuanTGLs,AntonioTGLs,EmilioTGLs; ///Puntos
int DavidAGCs,JavierAGCs,MarioAGCs,SergioAGCs,MarcosAGCs; /// Score

int i,scoreT,scoreA;
do{
inicio:
printf(" ----------------Final del Campeonato Nacional de Baloncesto 2019----------------\n\n");
srand (time(NULL) %20) ;
LebronTGL = rand () % 20;
PedroTGL = rand () % 14;
JuanTGL = rand () % 14; //Se aplican los valores de los puntos anotados por cada jugador
AntonioTGL = rand () % 16;
EmilioTGL = rand () % 9;

DavidAGC = rand () % 20;
JavierAGC = rand () % 14;
MarcosAGC = rand () % 14; //Se aplican los valores de los puntos anotados por cada jugador
MarioAGC = rand () % 16;
SergioAGC = rand () % 9;

printf("\tLebron TGL %i\t\t",LebronTGL);
printf("\tDavid AGC %i\n",DavidAGC);
printf("\tPedro TGL %i\t\t",PedroTGL);
printf("\tJavier AGC %i\n",JavierAGC);
printf("\tJuan TGL %i\t\t",JuanTGL);
printf("\tMarcos AGC %i\n",MarcosAGC); //Se imprimen los puntos de cada jugador de manera aleatoria
printf("\tAntonio TGL %i\t\t",AntonioTGL);
printf("\tMario AGC %i\n",MarioAGC);
printf("\tEmilio TGL %i\t\t",EmilioTGL);
printf("\tSergio AGC %i\n\n",SergioAGC);





TGL = LebronTGL + PedroTGL + JuanTGL + AntonioTGL + EmilioTGL;
AGC = DavidAGC + JavierAGC + MarioAGC + SergioAGC + MarcosAGC;
printf("\tTigres del Licey %i\t",TGL);
printf("\tAguilas del Cibao %i\n\n",AGC);

if (i == 0)
{
LebronTGLs = LebronTGL;
PedroTGLs = PedroTGL;
JuanTGLs = JuanTGL; //Almacenamos los puntos en las variables de puntaje
AntonioTGLs = AntonioTGL;// Tigres del Licey
EmilioTGLs = EmilioTGL;

DavidAGCs = DavidAGC;
JavierAGCs = JavierAGC;
MarioAGCs = MarioAGC; // Almacenamos los puntos en las variables de puntaje
SergioAGCs = SergioAGC; //Aguilas del Cibao
MarcosAGCs = MarcosAGC;

scoreA = AGC;
scoreT = TGL;
printf("Fin del primer tiempo.\n\n");
system("pause");
system("cls");
}

if (i ==1)
{

LebronTGLs = LebronTGLs + LebronTGL;
PedroTGLs = PedroTGLs + PedroTGL;
JuanTGLs = JuanTGLs + JuanTGL; //Almacenamos los puntos en las variables de puntaje
AntonioTGLs = AntonioTGLs + AntonioTGL;// Tigres del Licey
EmilioTGLs = EmilioTGLs + EmilioTGL;

DavidAGCs = DavidAGCs + DavidAGC;
JavierAGCs = JavierAGCs + JavierAGC;
MarioAGCs = MarioAGCs + MarioAGC; // Almacenamos los puntos en las variables de puntaje
SergioAGCs = SergioAGCs + SergioAGC; //Aguilas del Cibao
MarcosAGCs = MarcosAGCs + MarcosAGC;

scoreA = scoreA + AGC;
scoreT = scoreT + TGL;
printf("Fin del segundo tiempo.\n\n");
system("pause");
system("cls");
}
if (i ==2)
{

LebronTGLs = LebronTGLs + LebronTGL;
PedroTGLs = PedroTGLs + PedroTGL;
JuanTGLs = JuanTGLs + JuanTGL; //Almacenamos los puntos en las variables de puntaje
AntonioTGLs = AntonioTGLs + AntonioTGL;// Tigres del Licey
EmilioTGLs = EmilioTGLs + EmilioTGL;

DavidAGCs = DavidAGCs + DavidAGC;
JavierAGCs = JavierAGCs + JavierAGC;
MarioAGCs = MarioAGCs + MarioAGC; // Almacenamos los puntos en las variables de puntaje
SergioAGCs = SergioAGCs + SergioAGC; //Aguilas del Cibao
MarcosAGCs = MarcosAGCs + MarcosAGC;

scoreA =scoreA + AGC;
scoreT =scoreT + TGL;
printf("Fin del tercer tiempo.\n\n");
system("pause");
system("cls");
}
if (i ==3)
{

LebronTGLs = LebronTGLs + LebronTGL;
PedroTGLs = PedroTGLs + PedroTGL;
JuanTGLs = JuanTGLs + JuanTGL; //Almacenamos los puntos en las variables de puntaje
AntonioTGLs = AntonioTGLs + AntonioTGL;// Tigres del Licey
EmilioTGLs = EmilioTGLs + EmilioTGL;

DavidAGCs = DavidAGCs + DavidAGC;
JavierAGCs = JavierAGCs + JavierAGC;
MarioAGCs = MarioAGCs + MarioAGC; // Almacenamos los puntos en las variables de puntaje
SergioAGCs = SergioAGCs + SergioAGC; //Aguilas del Cibao
MarcosAGCs = MarcosAGCs + MarcosAGC;


scoreA =scoreA + AGC;
scoreT =scoreT + TGL;

printf("Fin del ultimo tiempo.\n\n");
sleep(2);
printf("Los tigres anotaron %i puntos.\t\t",scoreT);
printf("Las aguilas anotaron %i puntos.\n\n",scoreA);
sleep(2);
if (scoreT > scoreA)
{
printf("Los Tigres del Licey son los ganadores del campeonato.\n\n");
}
else
{
printf("Los Aguilas del Cibao son los ganadores del campeonato.\n\n");
}
int a;
system("pause");

system("cls");
printf(" ----------------Puntos Encestados por Jugador----------------\n\n");
printf("1\tLebron TGL %i\t\t",LebronTGLs);
printf("6\tDavid AGC %i\n",DavidAGCs);
printf("2\tPedro TGL %i\t\t",PedroTGLs);
printf("7\tJavier AGC %i\n",JavierAGCs);
printf("3\tJuan TGL %i\t\t",JuanTGLs);
printf("8\tMarcos AGC %i\n",MarcosAGCs); //Se imprimen los puntos encestados por cada jugador
printf("4\tAntonio TGL %i\t\t",AntonioTGLs);
printf("9\tMario AGC %i\n",MarioAGCs);
printf("5\tEmilio TGL %i\t\t",EmilioTGLs);
printf("10\tSergio AGC %i\n\n",SergioAGCs);


int jugadores[10];
jugadores[1]=LebronTGLs;
jugadores[2]=PedroTGLs;
jugadores[3]=JuanTGLs;
jugadores[4]=AntonioTGLs;
jugadores[5]=EmilioTGLs;
jugadores[6]=DavidAGCs;
jugadores[7]=JavierAGCs;
jugadores[8]=MarcosAGCs;
jugadores[9]=MarioAGCs;
jugadores[10]=SergioAGCs;
int z = 0;
int mvp;
int w,jugador;

for ( w =1; w < 11; w++)
    {
   	 if (jugadores[w]>z)
   	 {
   		 z = jugadores[w];
   		 mvp = jugadores[w];
   		 jugador = w;
   	 }

    }

printf("El jugador mvp fue el numero %i, con un total de %i puntos anotados.\n\n",jugador,mvp);
char repetir;
printf("Desea volver a jugar? [s/n] : ");
fflush(stdin);
scanf ("%c",&repetir);

if (repetir == 'n')

{
system("cls");
printf("Muchas gracias por jugar a nuestro juego...");
sleep(2);
}
else
{
i = 0;
LebronTGL= 0,PedroTGL=0,JuanTGL=0,AntonioTGL=0,EmilioTGL=0,TGL=0;
DavidAGC=0,JavierAGC=0,MarioAGC=0,SergioAGC=0,MarcosAGC=0,AGC=0;
LebronTGLs=0,PedroTGLs=0,JuanTGLs=0,AntonioTGLs=0,EmilioTGLs=0;
DavidAGCs=0,JavierAGCs=0,MarioAGCs=0,SergioAGCs=0,MarcosAGCs=0;
scoreT=0,scoreA=0;
system("cls");
printf("El juego iniciara en breve...");
sleep(3);
system("cls");
goto inicio;
}

}

i++;

}while(i < 4);



getch();
return 0;


}







