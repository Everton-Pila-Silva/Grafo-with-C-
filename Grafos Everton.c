#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAX 10
typedef struct G{
	int m2[MAX][MAX], i, j;
}Grafos;

int grafo[MAX][MAX];
//--------------------------------
void inicializa(){
	int i,j;
	for(i=0;i<MAX;i++)
	  for(j=0;j<MAX;j++)
	     grafo[i][j]=0;
	   
}// fim 
//---------------------------------
void inserir(int x, int y){
	grafo[x][y]=1;
}
//---------------------------------
void remover(int x, int y){
	grafo[x][y]=0;
}
//---------------------------------
void RefleSime(int grafo[MAX][MAX]){
	int i, j, re=0, si=0;
	for (i=0;i<10; i++) {
      	for (j=0; j<10; j++) {
        if((i=j)==1){
        	re++;
        }
      }
      for (i=0;i<10; i++) {
      	for (j=0; j<10; j++) {
        if(grafo[i][j]==1){
		si++;
        }
      }
  }
if(re==10){
		printf("\n reflexiva pois existem todas as relacoes entre i e j \n");
		}else{
			printf("\n Nao e reflexiva pois nao existe relacao de i e j em todos os casos\n");
		}
		if(si==100){//Só é simetrica se todos os elementos se relacionarem, se todos se relacionarem então matriz cheia, contador si=100;
			printf("\n E Simetrica pois Mij = Mji \n");
		}else{
			printf("\nNao e simetrica pois nao existe relacao de (i e j  --> j e i )em todos os casos \n");
		}
}
}
void Mr2(Grafos G[], int grafo[MAX][MAX]){
	  int i, j, x, m2[MAX][MAX], Aux=0;
	  
	 for(i=0; i<10; i++){
         for(j=0; j<10; j++){
             m2[i][j]=0;
                 for(x=0; x<10; x++){
                     Aux+= grafo[i][x] * grafo[x][j];
                     if(Aux>1){
                     	Aux=1;
					 }
                 }
                 m2[i][j]=Aux;
                 Aux=0;
         }
     }
    printf("\n********* Matriz R2 *********\n");

    for (i=0; i<10; i++) {
    	printf("\n");
      for (j=0; j<10; j++) {
        printf("%2d ", m2[i][j]);

      }
}
}
void printGrafo(int grafo[MAX][MAX]){
	int i,j;
	printf("   ");
	for(i=0;i<MAX;i++)
	   printf("%3d",i);
	printf("\n");
	for(i=0;i<MAX;i++){
		printf("%3d",i);
		for(j=0;j<MAX;j++)
		   printf("%3d",grafo[i][j]);   
		printf("\n");
	}// fim for i   
}// fim funcao print
//------------------------------------------
void saveGrafo(){
	FILE *arq;
	arq=fopen("grafo.txt","wb");
	fwrite(grafo,sizeof(int)*MAX*MAX,1,arq);
	printf("Salvo com sucesso!:)");
	fclose(arq);
}//fim funcao
//------------------------------
void loadGrafo(){
	FILE *arq;
	arq=fopen("Everton.txt","rb");
	if(arq==NULL){
		printf("Arquivo nao encontrado :(\n");
		return;
	}// fim if
	fread(grafo,sizeof(int)*MAX*MAX,1,arq);
	printf("Carregado com sucesso!:)");
	fclose(arq);
}
//----------------------------
void multiplica(int grafo[MAX][MAX]){
	int i, j, lA, cA, lB, cB, x;
lA=10;
cA=10;
lB=10;
cB=10;
printf("Multiplicador de matrizes para achar matriz ao infinito\n"); //Conseguiria fazer melhor se tivesse mais tempo ¯\_('.')_/¯
float matrizB[lB][cB],matrizC[lA][cB],Aux=0;
     for(i=0; i<10; i++){   
     
         for(j=0; j<10; j++){
             printf("Proxima matriz (Linha %d): ", i);
             scanf("%f", &matrizB[i][j]);
         }
         printf("\n\n");
     }
         for(i=0; i<10; i++){
         	for(j=0; j<10; j++){
             matrizC[i][j]=0;
                 for(x=0; x<10; x++){
                     Aux+= grafo[i][x] * matrizB[x][j];
                     if(Aux>1){
                     	Aux=1;
                     }
                 }
                 matrizC[i][j]=Aux;
                 Aux=0;
         }
     }
printf("\n\n");
printf("Matriz Gerada da Multiplicacao grafo R * Matriz inserida \n\n");
     for(i=0; i<10; i++){
         for(j=0; j<10; j++){
             printf("%2.f", matrizC[i][j]);
         }
         printf("\n");
     }
}
int menu(){
	int op;
	printf("***Digrafo Ponderado***\n");
	printf("1-Inserir\n");
	printf("2-Remover\n");
	printf("3-Reflexiva e Simetrica\n");
	printf("4-Matriz R2\n");
	printf("5-Salvar\n");
	printf("6-Carregar\n");
	printf("7-Multiplica Grafo(Para o Infinito)\n");
	printf("0-Sair\n");
	printf("Opcao:");
	scanf("%d",&op);
	return op;
}
//-------------------------------------
int main(){
    int op,v1,v2,r;
    Grafos G[MAX];
    inicializa();
	do{
		printf("Grafo:\n");
		printGrafo(grafo);
		op=menu();
		switch(op){
			case 1:printf("Inserir\nVertices da adj:");
			       scanf("%d%d",&v1,&v2);
			       inserir(v1,v2);
				break;
			case 2: 
				break;
			case 3: RefleSime(grafo);
				break;      
			case 4:  Mr2(G, grafo);
				break;
			case 5:	saveGrafo();
				break;
			case 6:  loadGrafo();
				break;
				case 7:	multiplica(grafo);
			case 0: printf("Saindo...");
				break;	
		}// fim switch
		getch();
		system("cls");
	}while(op!=0);

}
