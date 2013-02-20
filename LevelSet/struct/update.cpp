#include <iostream>
#include <stdio.h>
#include <vector>
#include <exception>
#include "main.h"
#include "update.h"
using namespace std;

extern double image[HEIGHT][WIDTH]; //image to be segmented
extern int init[HEIGHT+BORDER][WIDTH+BORDER]; //mask with seed points
extern double phi[HEIGHT+BORDER][WIDTH+BORDER]; //representation of the zero level set interface
extern int label[HEIGHT+BORDER][WIDTH+BORDER];//contains only integer values between -3 and 3
extern double F[HEIGHT][WIDTH];

extern vector<px> lz; // zero level set
extern vector<px> lp1;
extern vector<px> ln1;
extern vector<px> lp2;
extern vector<px> ln2;

//temp values
extern vector<px> sz; //values in sz are to be moved to lz
extern vector<px> sp1;
extern vector<px> sn1;
extern vector<px> sp2;
extern vector<px> sn2;


void updateLevelSets(){
	for(int i =0; i<lz.size(); i+=2){//find pixels that are moving out of lz
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
	for(int i =0; i<ln1.size(); i+=2){//find pixels that are moving out of ln1
		int j = i+1;
		if(checkMaskNeighbours(i,j,2) == false){//if Ln1[i][j] has no neighbors q with label(q) == 0
			ln1.erase(i);
			ln1.erase(j);
			sn2.push_back(i);
			sn2.push_back(j);
		}
		else{
			int M = Max(??);//TODO
			phi[i][j] = M-1;
			if(phi[i][j] >= -0.5){ //moving from ln1 to sz
				ln1.erase(i);
				ln1.erase(j);
				sz.push_back(i);
				sz.push_back(j);
			}
			else if(phi[i][j] < -1.5){
				ln1.erase(i);
				ln1.erase(j);
				sn2.push_back(i);
				sn2.push_back(j);
			}
		}
	}
	for(int i =0; i<lp1.size(); i+=2){//find pixels that are moving out of lp1
		int j = i+1;
		if(checkMaskNeighbours(i,j,2) == false){
			lp1.erase(i);
			lp1.erase(j);
			sp2.push_back(i);
		}
	}
}