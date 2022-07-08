#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>



int main() {
  FILE * kartei = fopen("kartei.txt","a");
  char * lkr();
  char * k;

  // Datum
  time_t t;
  t = time(NULL);
  struct tm tm = *localtime(&t);
  fprintf(kartei, "\n%d.%d.%d", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);

  // Call Abmeldung, Zulassung?
  char * grund();
  char * g;
  g = grund();
  fprintf(kartei, g);

  // Fahrzeugmarke, Modell, Farbe
  char marke[10];
  char modell[30];
  char * farbe[10];
  printf("\nGebe die Marke ein:\n");
  scanf("%s",marke);
  fprintf(kartei,",%s",marke);
  getchar();
  printf("\nGebe das Modell ein:\n");
  scanf("%s",modell);
  fprintf(kartei,",%s",modell);
  getchar();
  printf("\nGebe die Farbe ein:\n");
  scanf("%s",farbe);
  fprintf(kartei,",%s",farbe);
  getchar();


  //Call Landkreis function
  k = lkr();
  printf("%s ist der LandKreis\n",k);
  fprintf(kartei, ",%s",k);

  //Call Kennzeichen
  char * ok;
  char * kzn();
  ok = kzn();
  fprintf(kartei,"-%s",ok);
}

char * grund(){
	int a;
	char k[30];
	char *spk = k;
	printf("Was ist das folgende?\n(1) Zulassung\n(2) Abmeldung\n(3) Ummeldung\n");
	scanf("%1d",&a);
	getchar();

	switch(a){
    case 1:{
		printf("\nDu hast die Zulassung ausgewalht\n");
		strcpy(k, "\nZulassung");
		break;
		   }
    case 2:{
		printf("\nDu hast die Abmeldung ausgewalht\n");
		strcpy(k, "\nAbmeldung");
		break;
		   }
    case 3:{
		printf("\nDu hast die Ummeldung ausgewalht\n");
		strcpy(k, "\nUmmeldung");
		break;
		   }
	}
	return spk;


}

char * lkr (){
  // malloc variable lk , um zu returnen oder aktuell: return pointer auf lokale variable
  char lk[30];
  char *lk_return = lk;
  //lk = malloc(sizeof(char)*30);
  char n[2];
  char lau[4];
  char fue[4];
  char nm[4];
  int o,x ;
   
  //Definiere die Landkreise
  strcpy(n, "n");
  strcpy(lau, "lau");
  strcpy(fue, "fue");
  strcpy(nm, "nm");

  //Gebe LKR Option
  printf("\nbitte wahle aus: (n)\t(lau)\t(nm)\t(fue)\n");

  // Frage fuer LKR input
  scanf("%4s",lk);
  getchar();

  // Vergleiche input mit LKR definitionen und fuehre entsprechenden Befehle aus 
  if (!strcmp(n, lk)){
	printf("\nDu hast die Stadt Nuernberg gewalht\n");
	strcpy(lk, "N");
  }

  else if (strcmp(lau,lk)==0){
	printf("\nDu hast den Landkreis Nuernberger Land gewaelht. (LAU) \n");
	strcpy(lk, "LAU");
  }

  else if (strcmp(nm,lk)==0){
	printf("\nDu hast die Stadt Neumarkt gewaelht\n");
	strcpy(lk, "NM");
  }

  else if (strcmp(fue,lk)==0){
	printf("\nDu hast die Stadt Fuerth gewaelht\n");
	strcpy(lk, "FUE");
  }

  else
  { 
	  printf("du hast nix gewaehlt\n");
  }
  return lk_return;

}


char * kzn (){

  // malloc variable lk , um zu returnen oder aktuell: return pointer auf lokale variable
  char kn[30];
  char *kn_return = kn;
  //lk = malloc(sizeof(char)*30);
   
  //Gebe Kennzeichen ein
  printf("\nBitte gebe den Rest den Kennzeichens ein:\n");
  fgets(kn,sizeof(kn),stdin);
  int i;
  for (i=0; kn[i]!=0; i++){
		  if (kn[i]>='a' && kn[i] <='z'){
			kn[i]=putchar(toupper(kn[i]));
		  }
		  }

  return kn_return;
}
