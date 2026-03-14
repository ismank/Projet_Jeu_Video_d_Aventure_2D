#ifndef ENNEMI_H
#define ENNEMI_H

#include "Personnage.h"
#include "Image.h"

class Ennemi
{
  Personnage _perso;

public:

  Ennemi (const Image& image = Image(),
          int x = 0, int y = 0,
          int skin_x = 0, int skin_y = 0,
          Direction direction = BAS);

  void dessiner() const;

  void avancer(const Niveau& niveau);

  int getX() const;
  int getY() const;

};

#endif // ENNEMI_H
