#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include <math.h>

using namespace std;
typedef struct coord{int abs; int ord;} coord;


void echanger(int tableau[][3], int a, int b)
{
    int temp_0 = tableau[a][0];
    int temp_1 = tableau[a][1];
    int temp_2 = tableau[a][2];

    tableau[a][0] = tableau[b][0];
    tableau[a][1] = tableau[b][1];
    tableau[a][2] = tableau[b][2];
    tableau[b][0] = temp_0;
    tableau[b][1] = temp_1;
    tableau[b][2] = temp_2;
}

void quickSort(int tableau[][3], int debut, int fin)
{
    int gauche = debut-1;
    int droite = fin+1;
    const int pivot = tableau[debut][2];

    if(debut >= fin)
        return;

    while(1)
    {
        do droite--; while(tableau[droite][2] > pivot);
        do gauche++; while(tableau[gauche][2] < pivot);

        if(gauche < droite)
            echanger(tableau, gauche, droite);
        else break;
    }
    quickSort(tableau, debut, droite);
    quickSort(tableau, droite+1, fin);
}

void tri(int m, int edge[][3]){
  quickSort(edge, 0, m-1);
  return;
}

void pointrandom(int n, coord point[]){
  srand (time(NULL));
  for(int i=0;i<n;i++){
    point[i].abs=rand()%612;
    point[i].ord=rand()%792;
  }
  return;
}

void readcoord(int n, coord point[]){
  for(int i=0;i<n;i++){
    cout<<"READ POINT == X:"<<point[i].abs<<" Y: "<<point[i].ord<<endl;
  }
  return;
}

void distances(int n, int m, coord point[], int edge[][3]){
  int k=0;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(i<j){
        edge[k][0]=i;
        edge[k][1]=j;
        edge[k][2]=(pow((point[j].abs-point[i].abs),2))+(pow((point[j].ord-point[i].ord),2));
        k++;
      }
    }
  }
  return;
}

void readDist(int m, int edge[][3], coord point[]){
  for(int i=0;i<m;i++){
    cout<<"readDist_"<<i+1<<" : "<<endl;
    cout<<"   Point_"<<edge[i][0]<<" = X: "<<point[edge[i][0]].abs<<" Y: "<<point[edge[i][0]].ord<<endl;
    cout<<"   Point_"<<edge[i][1]<<" = X: "<<point[edge[i][1]].abs<<" Y: "<<point[edge[i][1]].ord<<endl;
    cout<<"   Distance_"<<edge[i][0]<<"_"<<edge[i][1]<<" = "<<edge[i][2]<<endl;
  }
  return;
}

int main(){
  int n;  //nombre de pts
  cout<<"Entrer le nombre de points: ";
  cin>>n;
  int m=n*(n-1)/2;  //Nombre de paires de points
  coord point[n];   //coordonnées des points dans le plan
  int edge[m][3];   //Les paires de points et le carre de leur longueur
  int arbre[n-1][2]; //Les aretes de l'arbre de Kruskal

  pointrandom(n, point);
  readcoord(n, point);
  distances(n, m, point, edge);
  readDist(m, edge, point);
  tri(m, edge);
  readDist(m, edge, point);

  return 0;
}
