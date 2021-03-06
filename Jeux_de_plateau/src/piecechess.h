#ifndef PIECECHESS_HPP_
#define PIECECHESS_HPP_

#include <iostream>

///
/// \brief piecechess.h
/// \file piecechess.h
/// \author Oudin Victor
///

using namespace std;

namespace pChess
{
  typedef enum { WHITE=0, BLACK=1, NUL=-1 } Color;
  
  typedef enum { PAWN='p', ROOK='r', KNIGHT='n', BISHOP='b', QUEEN='q', KING='k' } Type;
  
  class PieceChess
  {
  protected:
    Color col;
    Type typ;
  public:
    PieceChess () { col=NUL; }
    PieceChess (Color c,Type t) { col=c; typ=t; }
    Color getColor() { return col; }
    Type getType() { return typ; }
    string toString();
  };
}

#endif
