#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

//Global Variable
#define MAX_NAME_SZ 256

// Declaring functions
char * getname ();
char * getInput ();


int main () {

  // Write to file
  FILE * ofile;
  ofile = fopen("datenbank.txt","a");

  //Declare quit!
 const char *quit = "q";

   // Teste Anrede
  char * variable_a = "Anrede";
  char * anrede = getInput(variable_a);
  if (!*anrede ) {
    printf("WARNUNG: Kein Anrede angegeben!\n");
    printf("Programm wird beendet...\n");
	exit(EXIT_SUCCESS);
  }
    else{
      if (strcmp(anrede, quit)==0) {
	printf("Programm wird beendet...\n");
	exit(EXIT_SUCCESS);
      }
    };
  if (*anrede) {
    fprintf(ofile, "%s,",anrede);}
  free(anrede);

  // Teste Namen
  char * variable_n = "Vornamen";
  char * name = getInput(variable_n);
  if (!*name) {
    printf("WARNUNG: Kein Name angegeben!\n");
  }
    else{
      if (strcmp(name, quit)==0) {
	printf("Programm wird beendet...\n");
	exit(EXIT_SUCCESS);
      }
    };
  fprintf(ofile, "%s,", name);
  free(name);

  // Teste Nachnamen
  char * variable_ln = "Nachamen";
  char * last_name = getInput(variable_ln);
  if (!*last_name) {
    printf("WARNUNG: Kein Nachname angegeben!\n");
  }
    else{
      if (strcmp(last_name, quit)==0) {
	printf("Programm wird beendet...\n");
	exit(EXIT_SUCCESS);
      }
    };
  fprintf(ofile, "%s,", last_name);
  free(last_name);


  // Teste Adresse
  char * variable_s="Strasse";
  char * street = getInput(variable_s);
  if (!*street) {
    printf("WARNUNG: Keine Strasse angegeben!\n");
  }
    else{
      if (strcmp(street, quit)==0) {
	printf("Programm wird beendet...\n");
	exit(EXIT_SUCCESS);
      }
     }
  fprintf(ofile, "%s,", street);
  free(street);

  // Teste Street no
  int strno;
  printf("Hausnummer: ");
  scanf("%d", &strno);
  getchar();
  if (!strno) {
    printf("WARNUNG: Keine Hausnummer angegeben!\n");}
  fprintf(ofile, "%d,", strno);

  // Teste PLZ
  int plz;
  printf("Postleitzahl: ");
  scanf("%d", &plz);
  getchar();
  if (!plz) {
    printf("WARNUNG: Keine Postleitzahl angegeben!\n");}
  fprintf(ofile, "%d,", plz);

  // Teste Wohnort
  char * variable_w="Wohnort";
  char * city = getInput(variable_w);
  if (!*city) {
    printf("WARNUNG: Kein Wohnort angegeben!\n");
  }
    else{
      if (strcmp(city, quit)==0) {
	printf("Programm wird beendet...\n");
	exit(EXIT_SUCCESS);
      }
     }
  fprintf(ofile, "%s\n", city);
  free(city);

  // Close file
  fclose(ofile);

  
  return 0;
}

char * getInput(char * evariable){
    char *input = malloc(MAX_NAME_SZ);
    if (input == NULL) {
        printf("No memory\n");
        return 0;
    }
    printf("Gebe %s ein: ", evariable);
    fgets(input, MAX_NAME_SZ, stdin);
/* Remove trailing newline, if there. */
    if ((strlen(input) > 0) && (input[strlen (input) - 1] == '\n'))
    input [strlen (input) - 1] = '\0';
    return input;
}
