#include <stdio.h>
int main()
{
	int x;
	int i, k;
	int p[5] = {0};
	for (i = 0; i < 4; i++)
		scanf("%d,", &p[i]);
		scanf("%d",&p[4]);
	scanf("%d", &x);
	for (k = 0; k < 5; k++)
	{
		if (x < p[k])
			break;
	}
	for (i = 0; i < k ; i++)
		printf("%d,", p[i]);
	printf("%d,", x);
	for (i = k ; i < 4; i++)
		printf("%d,", p[i]);
	printf("%d",p[4]);
	return 0;
}