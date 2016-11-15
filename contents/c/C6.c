#include <stdio.h>
#include <stdlib.h>
#define MaxLength 300

int main()
{
	int length=7,des=7;
	//scanf("%d%d",&length,&des);
	int peopleLeft=length;
	int people[MaxLength]={0};
	int currentPos=0,counter=0;
	while(peopleLeft>0)
	{
		if(people[currentPos]==0)
		{
			++counter;
			if(counter==des)
			{
				printf("%d",currentPos+1);
				if(peopleLeft>1) printf("->");
				people[currentPos]=1;
				--peopleLeft;
				counter=0;
			}
		}
		if(++currentPos>=length) currentPos=0;
	}
	printf("\n");
	system("pause");
	return 0;
}