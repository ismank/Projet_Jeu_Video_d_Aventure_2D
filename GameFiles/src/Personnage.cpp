#include "Personnage.h"

Personnage::Personnage (const Image& image, int x, int y,
                        int skin_x, int skin_y, Direction direction)
{
  _image = image;
  _x = x;
  _y = y;
  _direction = direction;
  _skin_x = skin_x;
  _skin_y = skin_y;

}

void Personnage::dessiner() const
{
  // Pour eviter de dupliquer plein de fois l'appel a dessiner,
  // on peut precalculer les parametres dans le switch
  int x_selection = (_skin_x + 1) * TAILLE_CASE;
  int y_selection;
  switch (_direction)
  {
    case DROITE:
      y_selection = (_skin_y + 2) * TAILLE_CASE;
      break;
    case GAUCHE:
      y_selection = (_skin_y + 1) * TAILLE_CASE;
      break;
    case BAS:
      y_selection = (_skin_y + 0) * TAILLE_CASE;
      break;
    case HAUT:
      y_selection = (_skin_y + 3) * TAILLE_CASE;
      break;
  }

  _image.dessiner(_x, _y, x_selection, y_selection, TAILLE_CASE, TAILLE_CASE);
}

void Personnage::regarderDroite()
{
  _direction = DROITE;
}

void Personnage::regarderGauche()
{
  _direction = GAUCHE;
}

void Personnage::regarderBas()
{
  _direction = BAS;
}

void Personnage::regarderHaut()
{
  _direction = HAUT;
}

void Personnage::deplacer (int dx, int dy)
{
  _x += dx;
  _y += dy;
}

bool Personnage::peutBougerVers (Direction direction, const Niveau& niveau) const
{
  bool resultat;
  switch (direction)
  {
    case DROITE:
      resultat = niveau.caseEstLibre(_x + TAILLE_CASE, _y);
      break;
    case GAUCHE:
      resultat = niveau.caseEstLibre(_x - TAILLE_CASE, _y);
      break;
    case HAUT:
      resultat = niveau.caseEstLibre(_x, _y - TAILLE_CASE);
      break;
    case BAS:
      resultat = niveau.caseEstLibre(_x, _y + TAILLE_CASE);
      break;
  }
  return resultat;
}

Direction Personnage::getDirection() const
{
  return _direction;
}

void Personnage::inverserDirection()
{
  switch (_direction)
  {
    case DROITE:
      _direction = GAUCHE;
      break;
    case GAUCHE:
      _direction = DROITE;
      break;
    case HAUT:
      _direction = BAS;
      break;
    case BAS:
      _direction = HAUT;
      break;
  }
}

int Personnage::getX() const
{
  return _x;
}

int Personnage::getY() const
{
  return _y;
}

