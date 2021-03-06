#include "play.h"

///
/// \brief play.cpp
/// \file play.cpp
/// \author Oudin Victor
///


int charToInt(char c)
{
  switch(c){
  case 'a':return 0;
  case 'b':return 1;
  case 'c':return 2;
  case 'd':return 3;
  case 'e':return 4;
  case 'f':return 5;
  case 'g':return 6;
  case 'h':return 7;
  default :return -1;
  }
}

int playChess()
{
  Chess c;
  c.print();
  int turn=0;
  int x1,x2;
  char y1,y2;
  bool ok=false;
  pChess::Color player1=WHITE, player2=BLACK;
  while(1){
    if(turn%2==0){  // White turn
      ok=false;
      while(!ok){
	cout << "\E[37;1mJoueur 1\E[m, choissez une piece a déplacer et ou la déplacer" << endl;
	cin >> y1 >> x1 >> y2 >> x2;
	if(!c.isEmpty(x1-1,charToInt(y1)) and c.getColor(x1-1,charToInt(y1))==player1 and c.canMove(x1-1,charToInt(y1),x2-1,charToInt(y2))){
	  ok=true;
	  if(!c.move(x1-1,charToInt(y1),x2-1,charToInt(y2))){
	    turn--;
	    continue;
	  }
	  if(c.check()==player2){
	    cout << "échec" << endl;
	    if(c.checkmate()){
	      cout << "échec et mat, \E[37;1mJoueur 1\E[m gagne" << endl;
	      return 1;
	    }
	  }
	}
	else{ cout << "baka, choisi correctement" << endl; }
      }
    }
    else{  // Black turn
      ok=false;
      while(!ok){
	cout << "\E[30;1mJoueur 2\E[m, choissez une piece a déplacer et ou la déplacer" << endl;
	cin >> y1 >> x1 >> y2 >> x2;
	if(!c.isEmpty(x1-1,charToInt(y1)) and c.getColor(x1-1,charToInt(y1))==player2 and c.canMove(x1-1,charToInt(y1),x2-1,charToInt(y2))){
	  ok=true;
	  if(!c.move(x1-1,charToInt(y1),x2-1,charToInt(y2))){
	    turn--;
	    continue;
	  }
	  if(c.check()==player1){
	    cout << "échec" << endl;
	    if(c.checkmate()){
	      cout << "échec et mat, \E[30;1mJoueur 2\E[m gagne" << endl;
	      return 1;
	    }
	  }
	}
	else{ cout << "baka, choisi correctement" << endl; }
      }
    }
    turn++;
    c.print();
  }
  return 0;
}

int playMinesweeper()
{
  cout << "Quelle taille de grille voulez vous?" << endl;
  cout << "Small:1  Medium:2  Large:3" << endl;
  int op;
  cin >> op;
  Minesweeper m(op);
  m.print();
  int turn=0;
  int player1=0;
  int player2=0;
  int x,y,size=m.getSize();
  bool ok=false;
  while(!m.isFinish()){
    if(turn%2==0){ // player1 turn
      cout << "Joueur 1, c'est ton tour." << endl;
      cout << "choisi une case." << endl;
      ok=false;
      while(!ok){
	cin >> x >> y;
	if(x-1>=0 and x-1<size and y-1>=0 and y-1<size){
	  ok=true;
	  player1+=m.click(x-1,y-1);
	  cout << "Joueur 1 : " << player1 << " points" << endl;
	}
	else{
	  cout << "Mais tu vas une case possible, Oui?" << endl;
	}
      }
    }
    else{ // player2 turn
      cout << "Joueur 2, c'est ton tour." << endl;
      cout << "choisi une case." << endl;
      ok=false;
      while(!ok){
	cin >> x >> y;
	if(x-1>=0 and x-1<size and y-1>=0 and y-1<size){
	  ok=true;
	  player2+=m.click(x-1,y-1);
	  cout << "Joueur 2 : " << player2 << " points" << endl;
	}
	else{
	  cout << "Mais tu vas une case possible, Oui?" << endl;
	}
      }
    }
    turn++;
    m.print();
  }
  cout << "Partie terminée." << endl;
  if(player1>player2){
    cout << "Joueur 1 gagne avec " << player1 << " à " << player2 << endl;
  }
  else{
    cout << "Joueur 2 gagne avec " << player2 << " à " << player1 << endl;
  }
  return 1;
}


Play::Play()
{
  cout << "A quel jeu voulez vous jouer" << endl;
  cout << "Échecs : 1   Démineur : 2" << endl;
  int j;
  cin >> j;
  if(j==1){
    playChess();
  }
  if(j==2){
    playMinesweeper();
  }
  if(j<1 or j>2){
    cout << "Comme tu sais pas choisir, tu joueras au Démineur" << endl;
    playMinesweeper();
  }

}
