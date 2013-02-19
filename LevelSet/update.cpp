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

extern double test[3];

extern vector<int> lz;
extern vector<int> lp1;
extern vector<int> ln1;
extern vector<int> lp2;
extern vector<int> ln2;

void updateLevelSets(){
	test[0] = 0.55;
	test[1] = 0.65;
	test[2] = 0.75;
}