#include <stdio.h>

struct tri {
	struct tri *next[10];
	int exist;
} x[100000], head;

int xl;

char p[11];

int find(void)
{
	struct tri *tmp = &head;
	int i, j;

	for(i = 0; p[i]; i++) {
		if(tmp->next[p[i] - '0'] == 0) {
			tmp->next[p[i] - '0'] = &x[xl];
			for(j = 0; j < 10; j++)
				x[xl].next[j] = 0;
			x[xl++].exist = 0;
		}
		tmp = tmp->next[p[i] - '0'];
		if(tmp->exist)
			return 1;
	}

	for(i = 0; i < 10; i++)
		if(tmp->next[i])
			return 1;

	tmp->exist = 1;

	return 0;
}

int main()
{
	int T, N, chk, i;

	scanf("%d", &T);

	while(T--) {
		chk = 0;
		xl = 0;

		for(i = 0; i < 10; i++)
			head.next[i] = 0;

		scanf("%d", &N);

		while(N--) {
			scanf("%s", p);

			if(find())
				chk = 1;
		}
		
		printf("%s\n", chk ? "NO" : "YES");
	}

	return 0;
}
