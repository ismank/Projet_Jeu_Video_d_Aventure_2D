#ifndef TUILE_H
#define TUILE_H

#include <string>

using namespace std;

class Tuile
{
  string _nom;
  int _x;
  int _y;
  string _propriete;

public:

  Tuile (const string& nom = "", int x = 0, int y = 0, const string& propriete = "");

  void afficher() const;

  string getNom() const;
  int getX() const;
  int getY() const;
  string getPropriete() const;
  void setPropriete(const string& propriete);
};

#endif // TUILE_H
