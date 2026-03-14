#include <fstream>

#include "Niveau.h"

using namespace std;

Niveau::Niveau()
{

}

Niveau::Niveau (const Image& image, const string& nomDuFichier, const Dictionnaire& dictionnaire)
{
  ifstream fichier(nomDuFichier);
  if (!fichier)
    throw std::runtime_error("Impossible de charger " + nomDuFichier);

  int nbLignes;
  fichier >> nbLignes;

  _nbBonus = 0;
  for (int i = 0; i < nbLignes; i ++)
  {
    string nom;
    int x, y;
    fichier >> nom >> x >> y;
    _objets.push_back(Objet(image, nom, dictionnaire, x * TAILLE_CASE, y * TAILLE_CASE));

    if (_objets[i].getPropriete() == "bonus")
      _nbBonus ++;
  }
}

void Niveau::dessiner() const
{
  for (int i = 0; i < _objets.size(); i ++)
    if (_objets[i].getPropriete() != "cache")
      _objets[i].dessiner();
}

bool Niveau::caseEstLibre(int x, int y) const
{
  return (indiceObjet(x, y, "solide") == -1);
}

void Niveau::testerBonusEtPrendre(int x, int y)
{
  int indice = indiceObjet(x, y, "bonus");
  if (indice != -1)
  {
    _nbBonus --;
    _objets[indice].cacher();
  }
}

bool Niveau::gagne() const
{
  return _nbBonus == 0;
}

int Niveau::indiceObjet(int x, int y, const string& propriete) const
{
  int indice = -1;
  int i = 0;

  while (indice == -1 && i < _objets.size())
  {
    if (_objets[i].getPropriete() == propriete
        && _objets[i].getX() == x
        && _objets[i].getY() == y)
      indice = i;
    else
      i ++;
  }

  return indice;
}


//question 1.2
bool Niveau::testerPorte(int x, int y)const
{
    bool test = false;
    while (test = false)
    {
        if( indiceObjet(x,y,"porte") != -1)
        return true;
    else
        return false;
    }
}
