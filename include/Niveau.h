#ifndef NIVEAU_H
#define NIVEAU_H

#include <vector>

#include "Objet.h"
#include "Dictionnaire.h"

using namespace std;

class Niveau
{
  vector<Objet> _objets;
  int _nbBonus;

public:

  Niveau();
  Niveau (const Image& image, const string& nomDuFichier, const Dictionnaire& dictionnaire);

  void dessiner() const;

  // Retourne `true` si la case n'est pas occupee par un objet "solide"
  bool caseEstLibre(int x, int y) const;

  void testerBonusEtPrendre(int x, int y);

  bool gagne() const;

  //question 1.2
  bool testerPorte(int x, int y) const;

private:

  // S'il y a un objet de propriete "propriete" à la case (x,y), cette
  // fonction retourne son indice dans le vecteur _objets. Sinon, elle
  // retourne -1.
  // Methode privee car elle n'est utilisee que dans la classe
  int indiceObjet(int x, int y, const string& propriete) const;
};

#endif // NIVEAU_H
