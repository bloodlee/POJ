// solution to 3646

#include <cstdio>
#include <algorithm>

using namespace std;

static const int MAX = 20000;
static const char* WORDS = "Loowater is doomed!";

int main() {

	int n = 0;
	int m = 0;

	int heads[MAX];
	int knights[MAX];

	int head = 0;
	int knight = 0;
	
	scanf("%d %d", &n, &m);

	while (n != 0 && m != 0) {
		
		for (int i = 0; i < n; ++i) {

			scanf("%d", &head);
			heads[i] = head;
			
		}

		for (int i = 0; i < m; ++i) {

			scanf("%d", &knight);
			knights[i] = knight;
			
		}

		if (m < n) {
			scanf("%d %d", &n, &m);
			printf("%s\n", WORDS);
			continue;
		}
		
		sort(heads, heads + n);
		sort(knights, knights + m);

		int money = 0;
		bool live = true;

		int knight_index = 0;
		
		for (int i = 0; i < n; ++i) {

			while (heads[i] > knights[knight_index] && knight_index < m) {
				++knight_index;
			}

			if (knight_index == m) {
				live = false;
				break;
			} else {
				money += knights[knight_index++];
			}
			
		}

		scanf("%d %d", &n, &m);
		if (!live) {
			printf("%s\n", WORDS);
		} else {
			printf("%d\n", money);
		}
	}
	
}
