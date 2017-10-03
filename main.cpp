#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include <math.h>

using namespace std;
typedef struct coord{int abs; int ord;} coord;

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
        edge[k][2]=sqrt((pow((point[j].abs-point[i].abs),2))+(pow((point[j].ord-point[i].ord),2)));
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
  return 0;
}
