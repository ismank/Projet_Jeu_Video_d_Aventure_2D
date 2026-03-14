#ifndef OBJET_H
#define OBJET_H

#include <string>

#include "Image.h"
#include "Tuile.h"
#include "Dictionnaire.h"

using namespace std;

class Objet
{
  Image _image;
  int _x;
  int _y;
  Tuile _tuile;

public:

  Objet();
  Objet (const Image& image, const string& nom, const Dictionnaire& dictionnaire, int x, int y);

  void dessiner() const;

  string getPropriete() const;
  int getX() const;
  int getY() const;

  // Permet de remplacer un objet par un autre en selectionnant un autre nom
  void mettreAJour (const string& nom, const Dictionnaire& dictionnaire);

  // Remplace la propriete par "cache"
  void cacher();
};

#endif // OBJET_H
