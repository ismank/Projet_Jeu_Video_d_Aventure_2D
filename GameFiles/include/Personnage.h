#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include "Image.h"
#include "Niveau.h"

enum Direction { HAUT, BAS, GAUCHE, DROITE };

class Personnage
{
  Image _image;
  int _x;
  int _y;
  Direction _direction;
  int _skin_x;
  int _skin_y;


public:

  // Constructeur (les valeurs par defaut en font aussi le constructeur vide)
  Personnage (const Image& image = Image(),
              int x = 0, int y = 0,
              int skin_x = 0, int skin_y = 0,
              Direction direction = BAS);

  void dessiner() const;

  void regarderDroite();
  void regarderGauche();
  void regarderBas();
  void regarderHaut();

  void deplacer (int dx, int dy);

  bool peutBougerVers (Direction direction, const Niveau& niveau) const;

  Direction getDirection() const;
  void inverserDirection();

  int getX() const;
  int getY() const;

};

#endif //  PERSONNAGE_H
