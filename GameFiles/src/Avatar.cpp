#include "Avatar.h"

Avatar::Avatar (const Image& image, int x, int y,
                int skin_x, int skin_y, Direction direction)
{
  _perso = Personnage(image, x, y, skin_x, skin_y, direction);

    //question 2.2
  _nbVies = 5;
  _invincible = false;
}

void Avatar::dessiner() const
{
  _perso.dessiner();
}

void Avatar::allerDroite(const Niveau& niveau)
{
  if (_perso.peutBougerVers(DROITE, niveau))
    _perso.deplacer(TAILLE_CASE, 0);
  _perso.regarderDroite();
}

void Avatar::allerGauche(const Niveau& niveau)
{
  if (_perso.peutBougerVers(GAUCHE, niveau))
    _perso.deplacer(-TAILLE_CASE, 0);
  _perso.regarderGauche();
}

void Avatar::allerHaut(const Niveau& niveau)
{
  if (_perso.peutBougerVers(HAUT, niveau))
    _perso.deplacer(0, -TAILLE_CASE);
  _perso.regarderHaut();
}

void Avatar::allerBas(const Niveau& niveau)
{
  if (_perso.peutBougerVers(BAS, niveau))
    _perso.deplacer(0, TAILLE_CASE);
  _perso.regarderBas();
}

int Avatar::getX() const
{
  return _perso.getX();
}

int Avatar::getY() const
{
  return _perso.getY();
}

bool Avatar::touche (const Ennemi& ennemi) const
{
  return getX() == ennemi.getX() && getY() == ennemi.getY();
}

//question 2.2
int Avatar::getNbVies()const
{
    return _nbVies;
}

//question 2.4
void Avatar::perteVie()
{
    //question 2.6
    if ( !_invincible ){
        _nbVies--;
        _invincible= true;
    }

}

//question 2.7
void Avatar::finInvincibilite()
{
    _invincible=false;
}
