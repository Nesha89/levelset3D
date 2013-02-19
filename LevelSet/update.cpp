#include <iostream>
#include <stdio.h>
#include <vector>
#include <exception>
#include "main.h"
#include "update.h"
using namespace std;

extern double image[HEIGHT][WIDTH];
extern int init[HEIGHT+BORDER][WIDTH+BORDER];
extern double phi[HEIGHT+BORDER][WIDTH+BORDER];
extern int label[HEIGHT+BORDER][WIDTH+BORDER];
extern double F[HEIGHT][WIDTH];

extern vector<int> lz;
extern vector<int> lp1;
extern vector<int> ln1;
extern vector<int> lp2;
extern vector<int> ln2;

extern vector<int> sz;
extern vector<int> sp1;
extern vector<int> sn1;
extern vector<int> sp2;
extern vector<int> sn2;


void updateLevelSets(){
	for(int i =0; i<lz.size(); i+=2){
		int j = i+1;
		phi[i][j] += F[i][j];
		if(phi[i][j] > 0.5)[
			lz.erase(i);
			lz.erase(j);
			sp1.push_back(i);
			sp1.push_back(j);
		}
		else if(phi[i][j] <= -0.5){
			lz.erase(i);
			lz.erase(j);
			sn1.push_back(i);
			sn1.push_back(j);
		}
	}
	for(int i =0; i<ln1.size(); i+=2){
		int j = i+1;
		if(checkMaskNeighbours(i,i,2) == false){//if Ln1[i][j] has no neighbors q with label(q) == 0
			ln1.erase(i);
			ln1.erase(j);
			sn2.push_back(i);
			sn2.push_back(j);
		}
		else{
			Max(??);
		}
	}
}