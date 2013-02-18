#include <vector>
using namespace std;


#define HEIGHT 512
#define WIDTH 512
#define BORDER 2


double image[HEIGHT][WIDTH];
int init[HEIGHT+BORDER][WIDTH+BORDER];
double phi[HEIGHT+BORDER][WIDTH+BORDER];
int label[HEIGHT+BORDER][WIDTH+BORDER];

vector<int> lz;
vector<int> lp1;
vector<int> ln1;
vector<int> lp2;
vector<int> ln2;