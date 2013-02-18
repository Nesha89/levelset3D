#include <iostream>
#include <stdio.h>
#include <vector>
#include <exception>
#include "main.h"
using namespace std;


void updateLevelSets(){
	for (int i = 0; i<HEIGHT; i++){
		for (int j = 0; j<WIDTH; j++){
			phi[i][j] = 0;
		}
	}
}