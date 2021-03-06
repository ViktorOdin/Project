#include "mines.h"
using namespace std;
///
/// \brief mines.cpp
/// \file mines.cpp
/// \author Oudin Victor
///


/**
 * \fn string intToString (int i)
 * \brief Fonction renvoyant un entier (compris entre 1 et 9) en string.
 *
 * \param i entier à changer en string, ne peut pas être NULL.
 * \return string de l'entier en cas de succes, string d'un espace dans le cas contraire.
 */
string intToString(int i)
{
  switch(i){
  case 1:return "1";
  case 2:return "2";
  case 3:return "3";
  case 4:return "4";
  case 5:return "5";
  case 6:return "6";
  case 7:return "7";
  case 8:return "8";
  default:return " ";
  }
}


/**
 * \fn string Mines::toString ()
 * \brief Fonction renvoyant une string représentant la mine courante (pour l'affichage dans le terminal.
 *
 * \return string de la mine.
 */
string Mines::toString()
{
  if(hyde){
    return "\E[30;1m×\E[m";
  }
  else{
    if(mine==0){
      return " ";
    }
    else if(mine==9){
      return "\E[31;1m*\E[m"; // red mines
    }
    else{
      string s=intToString(mine);
      return "\E[34;1m"+s+"\E[m"; // blue number
    }
  }
}


/**
 * \fn bool Mines::reveal ()
 * \brief Fonction changeant la variable "hyde" de la mine courante en "true".
 *
 * \return "true" si fonctionne, "false" dans le cas contraire.
 */
bool Mines::reveal()
{
  if(hyde){
    hyde=false;
    return true;
  }
  return false;
}
