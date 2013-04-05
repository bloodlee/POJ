#include <cstdio>
#include <cstring>

using namespace std;

static int mountainMap[101][101];
static int values[101][101];
static int M;
static int R, C;

static int cross_dir[4][2] = {
	-1, 0, 1, 0, 0, -1, 0, 1
};

int findValue(int i, int j) {

	if (values[i][j] > 0) {
		return values[i][j];
	}

	for (int m = 0; m < 4; ++m) {
		int x1 = i + cross_dir[m][0];
		int y1 = j + cross_dir[m][1];

		int tmpValue = 0;
		if (x1 >= 0 && x1 < R && y1 >= 0 && y1 < C) {
			
			if (mountainMap[i][j] > mountainMap[x1][y1]) {
				
				tmpValue = findValue(x1,y1) + 1;
				
			}
				
		}
		
		if (tmpValue > values[i][j]) {
			values[i][j] = tmpValue;
		}
		
	}


	return values[i][j];
	
}

int main() {

	scanf("%i %i", &R, &C);

	memset(&mountainMap, 0, 101*101*sizeof(int));
	memset(&values, 0, 101*101*sizeof(int));
	M = 0;

	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			scanf("%i", &mountainMap[i][j]);
		}
	}

	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			int value = findValue(i, j);
			if (M < value) {
				M = value;
			}
		}
	}
	
	printf("%i\n", ++M);
	
	return 0;
}
