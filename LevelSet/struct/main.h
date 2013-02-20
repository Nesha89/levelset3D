#include <vector>
using namespace std;

#define HEIGHT 512
#define WIDTH 512
#define BORDER 2

struct px{
	int x;
	int y;
	px(int newX, int newY): x(newX), y(newY){} //constructor
};

bool checkMaskNeighbours(int i, int j, int id);