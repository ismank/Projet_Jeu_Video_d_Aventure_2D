#include "Objet.h"

Objet::Objet()
{

}

Objet::Objet (const Image& image, const string& nom, const Dictionnaire& dictionnaire, int x, int y)
{
  _image = image;
  _x = x;
  _y = y;

  if (!dictionnaire.recherche(nom, _tuile))
    throw invalid_argument("Impossible de trouver " + nom + " dans le dictionnaire");
}

void Objet::dessiner() const
{
  _image.dessiner(_x, _y, TAILLE_CASE * _tuile.getX(), TAILLE_CASE * _tuile.getY(), TAILLE_CASE, TAILLE_CASE);
}

string Objet::getPropriete() const
{
  return _tuile.getPropriete();
}

int Objet::getX() const
{
  return _x;
}

int Objet::getY() const
{
  return _y;
}

void Objet::mettreAJour (const string& nom, const Dictionnaire& dictionnaire)
{
  if (!dictionnaire.recherche(nom, _tuile))
    throw invalid_argument("Objet introuvable : " + nom);
}


void Objet::cacher()
{
  _tuile.setPropriete("cache");
}
