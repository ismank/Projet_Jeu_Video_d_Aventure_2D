#include "Ennemi.h"

Ennemi::Ennemi (const Image& image, int x, int y,
                int skin_x, int skin_y, Direction direction)
{
  _perso = Personnage(image, x, y, skin_x, skin_y, direction);
}

void Ennemi::dessiner() const
{
  _perso.dessiner();
}

void Ennemi::avancer(const Niveau& niveau)
{
  if (_perso.peutBougerVers(_perso.getDirection(), niveau))
  {
    switch (_perso.getDirection())
    {
      case DROITE:
        _perso.deplacer(TAILLE_CASE, 0);
        break;
      case GAUCHE:
        _perso.deplacer(-TAILLE_CASE, 0);
        break;
      case HAUT:
        _perso.deplacer(0, -TAILLE_CASE);
        break;
      case BAS:
        _perso.deplacer(0, TAILLE_CASE);
        break;
    }
  }
  else
    _perso.inverserDirection();
}

int Ennemi::getX() const
{
  return _perso.getX();
}

int Ennemi::getY() const
{
  return _perso.getY();
}
