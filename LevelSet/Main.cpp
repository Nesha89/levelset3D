#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

#define HEIGHT = 512;
#define WIDTH = 512;



double image[512][512] = { 0 };
double init[512][512] = { 0 };
double phi[512][512] = { 0 };
double label[512][512] = { 0 };
vector<int,int> l0;
vector<int,int> lp1;
vector<int,int> ln1;
vector<int,int> lp2;
vector<int,int> ln2;


void setInit(int minX, int minY, int maxX, int maxY){

	for (int i = minY; i<maxY; i++){
		for (int j = minX; j<maxX; j++){
			if (i == minY || i == maxY || j == minX || j == maxX)

		}
	}


}

void readbmp(char* filename){

    FILE* fp = fopen(filename, "rb");

    int width, height, offset;

    fseek(fp, 18, SEEK_SET);
    fread(&width, 4, 1, fp);
    fseek(fp, 22, SEEK_SET);
    fread(&height, 4, 1, fp);
    fseek(fp, 10, SEEK_SET);
    fread(&offset, 4, 1, fp);

    unsigned char* data = (unsigned char*)malloc(sizeof(unsigned char)*height*width);

    fseek(fp, offset, SEEK_SET);
    //We just ignore the padding :)
    fread(data, sizeof(unsigned char), height*width, fp);

    fclose(fp);

	for (int i =0; i<512; i++){
		for (int j = 0; j<512; j++){
		image[i][j] = (double)data[i*512+j]; //må kanskje forandres hvis bildet er opp ned
		
		}
	}
    //return data;
}

void main(){
	char* filename = "c:/osv..";

	readbmp(filename);


}
