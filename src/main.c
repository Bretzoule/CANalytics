/*!
 *  \file main.C
 *  \author LEFLOCH Thomas <leflochtho@eisti.eu>
 *  \version 0.1
 *  \date Lun 12 Juin 2023 - 14:56:27
 *
 *  \brief Programme principal
 *
 *
 */

// Inclusion des entetes de librairies
#include <stdlib.h>
#include <stdio.h>
#include "paramHandler.h"
#include "dataParser.h"
/*!
 \def EXIT_SUCCESS
  Code confirmant la bonne exécution du programme
*/
#define EXIT_SUCCESS 0
/*!
 \def ERREUR_SAISIE
  Code d'erreur attestant qu'une erreur de saisie s'est produite
*/
#define ERREUR_SAISIE -1

/*!
 *  \fn int main (int argc, char** argv)
 *  \author LEFLOCH Thomas <leflochtho@eisti.eu>
 *  \version 0.1
 *  \date Lun 12 Juin 2023 - 14:58:04
 *  \brief Programme principal
 *  \param argc : Nombre de paramètres à l'exécution
 *  \param argv : Valeur des paramètres
 *  \return 0 si tout s'est bien passé
 */
int main(int argc, char **argv)
{
  int method = 0;
  FILE* fileHandler = NULL;
  method = paramParser(argc, argv, &fileHandler);
  if (method != -1 && fileHandler != NULL)
  {
    parseFile(method, fileHandler);
  }
  else
  {
    printf("Paramètres invalides -- Method: %d, FileHandler: %d\n", method, fileHandler);
    return ERREUR_SAISIE;
  }
  fclose(fileHandler);
  return (EXIT_SUCCESS);
}