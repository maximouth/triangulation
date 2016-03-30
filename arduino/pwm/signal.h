#ifndef _SIGNAL_H
#define _SIGNAL_H

/* recupere la puissance du dernier signal reçu et le renvoie*/
int puissance();
/* convertie de l'ascii en int  */
int asci (char c);
/* lit et ignore les '!' lu  */
char get_byte_ignore ();
/* convertie la puissance du signal en distance m*/
float convert_p_distance (double n);

#endif
