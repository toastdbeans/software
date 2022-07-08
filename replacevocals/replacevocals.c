#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main () {
	srand(time(NULL));
        char input[500];

		//int c;
		int x,i;
		int shuffle[4]= {101, 105, 111, 117};

		for (i = 0; i < 4; i++){
			int randIndex= rand() % 4;
			int temp = shuffle[i];
			shuffle[i] = shuffle[randIndex];
			shuffle[randIndex]=temp;
		}
//		for (i = 0; i < 4; i++){
//		printf("%d\n",shuffle[i]);}
		system("clear");
		printf("\nPut in a string to replace its vocals LOL : \n");
		printf("%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n\n");
		fgets(input,sizeof(input),stdin);
		for (x=1; x<122;x++){
			int var;
			var = input[x];
			if ((var == 97)||(var==101)||(var==105)||(var==111)||(var==117)){
				var=shuffle[(rand() %4)];
				input[x]=var;
			}
		}
			    printf("-------------------------------------------------\n");
			    printf("%s\n", input);
//		for (c = 0; c < 26; c++){
//			    name[6]=letter+c;
				//printf("%c  ", letter +c);

				//switch out vocals aeiou of predefined letter in array
//				if ((name[6] == 'a')||(name[6] == 'e')||(name[6]=='i')||(name[6]=='o')||(name[6]=='u')){
//					printf("%s\t", name);}}
//				printf("\n");

}
