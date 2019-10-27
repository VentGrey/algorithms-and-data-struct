#include <stdio.h>

int main()
{
		int N, M;
		int box[500][500];
		int max = 0;
		int i,j, tmp, s;

		scanf("%d%d", &N, &M);

		for (i = 0; i < N; i++)	{
				for (j = 0; j < M; j++)
						scanf("%d", &box[i][j]);
		}

		//정사각형
		for (i = 0; i < N - 1; i++) {
				for (j = 0; j < M - 1; j++) {
						tmp = box[i][j] + box[i][j + 1] + box[i + 1][j] + box[i + 1][j + 1];
						if (tmp > max)
								max = tmp;
				}
		}

		//길죽한 거(세로)
		for (i = 0; i < N - 3; i++) {
				for (j = 0; j < M; j++) {
						tmp = box[i][j] + box[i + 1][j] + box[i + 2][j] + box[i + 3][j];
						if (tmp > max)
								max = tmp;
				}
		}

		//길죽한 거 (가로)
		for (j = 0; j < M - 3; j++) {
				for (i = 0; i < N; i++) {
						tmp = box[i][j] + box[i][j + 1] + box[i][j + 2] + box[i][j + 3];
						if (tmp > max)
								max = tmp;
				}
		}

		//3개짜리(세로)
		for (i = 0; i < N - 2; i++) {
				for (j = 0; j < M; j++) {
						s = box[i][j] + box[i + 1][j] + box[i + 2][j]; //s는 고정 3개합
						if (j - 1 >= 0) {
								tmp = s + box[i][j - 1];
								if (tmp > max)
										max = tmp;
								tmp = s + box[i + 1][j - 1];
								if (tmp > max)
										max = tmp;
								tmp = s + box[i + 2][j - 1];
								if (tmp > max)
										max = tmp;
						}
						if (j + 1 < M) {
								tmp = s + box[i][j + 1];
								if (tmp > max)
										max = tmp;
								tmp = s + box[i + 1][j + 1];
								if (tmp > max)
										max = tmp;
								tmp = s + box[i + 2][j + 1];
								if (tmp > max)
										max = tmp;
						}
				}
		}

		//3개짜리(가로)
		for (j = 0; j < M - 2; j++) {
				for (i = 0; i < N; i++) {
						s = box[i][j] + box[i][j + 1] + box[i][j + 2];
						if (i - 1 >= 0) {
								tmp = s + box[i - 1][j];
								if (tmp > max)
										max = tmp;
								tmp = s + box[i - 1][j + 1];
								if (tmp > max)
										max = tmp;
								tmp = s + box[i - 1][j + 2];
								if (tmp > max)
										max = tmp;
						}

						if (i + 1 < N) {
								tmp = s + box[i + 1][j];
								if (tmp > max)
										max = tmp;
								tmp = s + box[i + 1][j + 1];
								if (tmp > max)
										max = tmp;
								tmp = s + box[i + 1][j + 2];
								if (tmp > max)
										max = tmp;
						}
				}
		}

		//2개짜리(가로)
		for (i = 1; i < N - 1; i++)	{
				for (j = 0; j < M - 1; j++)	{
						s = box[i][j] + box[i][j + 1];
						tmp = s + box[i + 1][j] + box[i - 1][j + 1];
						if (tmp > max)
								max = tmp;
						tmp = s + box[i - 1][j] + box[i + 1][j + 1];
						if (tmp > max)
								max = tmp;
				}
		}

		//2개짜리(세로)
		for (i = 0; i < N - 1; i++) {
				for (j = 1; j < M - 1; j++)	{
						s = box[i][j] + box[i + 1][j];
						tmp = s + box[i][j - 1] + box[i + 1][j + 1];
						if (tmp > max)
								max = tmp;
						tmp = s + box[i + 1][j - 1] + box[i][j + 1];
						if (tmp > max)
								max = tmp;
				}
		}

		printf("%d\n", max);

}
