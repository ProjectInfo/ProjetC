/* Nom : RASOLOARISON
   Prénom : Tina
   TP1 informatique embarquée
    
   durée du travail : 72 heures dont 2 heures pour appréhension des pointeurs en C
   * 
*/
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
//la fonction incr1 incrémente une ligne de gauche à droite
int incr1(int **tab,unsigned int di,unsigned int debutj,unsigned int fin,unsigned int rep){
unsigned int j;
if (debutj<fin){
	for(j=debutj;j<fin;j++){
		tab[di][j]=rep+1;
		rep=rep+1;
					 }
			   }
return 0;
}

//la fonction incr2 incrémente une colonne du haut vers le bas
int incr2(int **tab,unsigned int debuti,unsigned int dj,unsigned int fin,unsigned int rep){
unsigned int i;
if(debuti<fin){
	for(i=debuti+1;i<fin;i++){
		tab[i][dj]=rep+1;
		rep=rep+1;
					}
			  }
return 0;
}

// la fonction incr3 incrémente une ligne de droite à gauche 
int incr3(int **tab,unsigned int di,unsigned int dj, unsigned int fin,unsigned int rep){
unsigned int j;
if(dj>fin){
	for(j=dj-1;j+1>fin;j--){
		tab[di][j]=rep+1;
		rep=rep+1;
				}
		  }
return 0;
}

//la fonction incr4 incrémente une colonne du bas vers le haut
int incr4(int **tab,unsigned int di,unsigned int dj,unsigned int fin,unsigned int rep){
unsigned int i;
if(di>fin){
	for(i=di-1;i+1>fin;i--){
		tab[i][dj]=rep+1;
		rep=rep+1;
	          	}
		  }
return rep;
}

//la fonction 'affiche' sert à afficher le tableau 
int affiche(int **tab,unsigned int k,unsigned int n){
int i,j;
for (i=0;i<k;i++)
for(j=0;j<n;j++)
	{if((j+1)%n==0)
		printf("%d\n",tab[i][j]);
	 else
		printf("%d\t",tab[i][j]);
}
return 0;
}

// la fonction 'min' retourne le minimum de deux entiers positifs 
int minimum(unsigned int x,unsigned int y){
	if(x<y)
		return x;
	else
		return y; 
		}

int estChiffre(char c){
	if(c =='0'|| c=='1'|| c=='2'|| c=='3'|| c=='4'|| c=='5'|| c=='6'|| c=='7'|| c=='8' || c=='9')
		return 1;
	else 
		return 0;
}
int estEntier(char n[50]){
	int i=0;
	while((n[i]!='\0')&&(estChiffre(n[i]))) i++;
	if(n[i]=='\0')
		return 1;
	else return 0;
	
	}
		
//la fonction 'colimacon' remplit notre tableau en spirale
int colimacon(int **array,unsigned int rows,unsigned int column){
	int x,y,rep;
	
// la variable rep sert à contenir la dernière valeur de l'incrémentation
// elle est utile pour commencer l'incrémentation suivante (lors du passage 
// de l'horizontale à la verticale ou inversement	

int mini=minimum(rows,column);
rep=0;

for(y=0;y<(mini/2);y++){
	x=incr1(array,y,y,column-y,rep);
	x=incr2(array,y,column-(y+1),rows-y,array[y][column-(y+1)]);
	x=incr3(array,rows-(y+1),column-(y+1),y,array[rows-(y+1)][column-(y+1)]);
	x=incr4(array,rows-(y+1),y,y+1,array[rows-(y+1)][y]);
	rep=array[(y+1)][y];
	}

if(mini%2!=0){
	x=incr1(array,y,y,column-y,rep);
	x=incr2(array,y,column-(y+1),rows-y,array[y][column-(y+1)]);
}
	if ((rows==0)||(column)==0){array=NULL;return 0;}
		else return 1;
	}
	
int main()
{

int rows,column;int i,x,y; char r[50]="";char s[50]="";
int mini=minimum(rows,column);
int **array;


while (1){
	printf("\nSuggestion de couple (rows, column) pour les tests:\n");
	printf("(2,7),(4,5),(10,10),(13,2),(100000,3),(20,3),(8,12),(21,1),(1,24),(2,16) ou CTR+C pour quitter\n"); 
	
	printf("rows=");	scanf("%49s",r);
	printf("column=");	scanf("%49s",s);
	
	if (estEntier(r)) 
	      rows = atoi(r);
	else 
		{ printf("erreur: la valeur de la ligne doit être entière\n"); return 0;}
	
	if(estEntier(s)) 
			column = atoi(s); 
	else 	
		{printf("erreur: la valeur de la colonne doit être entière\n");return 0;}
	
	if(rows==0 || column ==0)
		printf("les valeurs de 'rows' et 'column' ne doivent pas être nulles\n");
	
	array= (int**)malloc(rows* sizeof(int*));

	for (i = 0; i < rows; i++)
		array[i] = (int*)calloc(column , sizeof(int));

	x=colimacon(array,rows,column);
	x=affiche(array,rows,column);

	for (i = 0; i < rows; i++)
		free(array[i]);
	free(array);
		}
}

