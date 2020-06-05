#include <stdio.h>
#include<windows.h>
#include <conio.h>

void main(){
	srand (time(NULL));
	int matriz[10][10];
	int i, j;
	int vidas = 3;
	int posicionPjX=9;
	int posicionPjY=9;
	int antiguaPosicionX;
	int antiguaPosicionY;
	const char personaje[]="8";
	const char premio[]="O";
	const char muro[]="X";
	
	for(i=0; i<10; i++){
		for(j=0; j<10; j++){
			matriz[i][j]=rand()%2;
			if(matriz[i][j]==1){
				pintar(i,j,muro);
			}
		}
	}
	matriz[0][0]=0;
	matriz[9][9]=0;
	
	gotoxy(0,12);
	printf("Vidas: %i",vidas);
	
	gotoxy(12,0);
	printf("Usa WASD Para moverte.");
	gotoxy(12,1);
	printf("<8> es tu personaje");
	gotoxy(12,2);
	printf("<X> son los muros");
	gotoxy(12,3);
	printf("<O> es la meta");
	
	pintar(0,0,premio);
	pintar(9,9,personaje);
		
	while(vidas>0) {
		char a;
		a=getch();
		antiguaPosicionX=posicionPjX;
		antiguaPosicionY=posicionPjY;
		switch(a){
        case 'w':
            posicionPjY--;
            break;

        case 'a':
            posicionPjX--;
            break;

        case 's':
            posicionPjY++;
            break;

        case 'd':
            posicionPjX++;
            break;
        }
       
        if(posicionPjX>9||posicionPjY>9||posicionPjX<0||posicionPjY<0){
        	posicionPjX=9;
        	posicionPjY=9;
		}

        pintar(antiguaPosicionX, antiguaPosicionY, "  ");
        pintar(posicionPjX, posicionPjY,personaje);
        
        if(matriz[posicionPjX][posicionPjY]==1){
			vidas--;
			matriz[posicionPjX][posicionPjY]=0;
			gotoxy(0,12);
			printf("Vidas: %i",vidas);
			gotoxy(posicionPjX,posicionPjY);
		}
		
		if(posicionPjX==0&&posicionPjY==0){
			break;
		}
	}
	if(vidas>0){
		gotoxy(0,12);
		printf("¡GANASTE! LLegaste a la meta");
	}else{
		gotoxy(0,12);
		printf("Lo lamento ¡PERDISTE!");
	}
}

void gotoxy(int x,int y){
HANDLE hCon;
COORD dwPos;
dwPos.X=x*3;
dwPos.Y=y;
hCon=GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleCursorPosition(hCon,dwPos);
}

void pintar(int x, int y, char a[]){
	gotoxy(x,y);
	printf(a);
}



