#include <vector>

#include "Moteur.h"
#include "Image.h"
#include "Avatar.h"
#include "Ennemi.h"
#include "Dictionnaire.h"
#include "Niveau.h"

using namespace std;

int main(int, char**) // Version special du main, ne pas modifier
{
    // Initialisation du jeu
    Moteur moteur("Mon super jeu vidéo");

    // Chargement des fichiers avec traitement des exceptions
    Image fond;
    Image sprites_personnages;
    Image sprites_objets;

    //question 2.1
    Image vie;

    Image bravo;
    Image gameover;

    Dictionnaire dictionnaire;
    Niveau niveau;

    try
    {
        fond = Image(moteur, "assets/fond.png");
        sprites_personnages = Image(moteur, "assets/personnages.png");
        sprites_objets = Image(moteur, "assets/objets.png");
        bravo = Image(moteur, "assets/bravo.png");
        gameover = Image(moteur, "assets/gameover.png");

        //question 2.1
        vie = Image(moteur, "assets/vie.png");

        dictionnaire = Dictionnaire("assets/dictionnaire.txt");
        niveau = Niveau(sprites_objets, "assets/niveau.txt", dictionnaire);
    }
    catch (const runtime_error& e)
    {
        cout << "Erreur: " << e.what() << endl;
        return -1; // On quitte le jeu en cas d'erreur de chargement
    }

    dictionnaire.afficher();

    // Creation des personnages
    Avatar avatar (sprites_personnages, TAILLE_CASE, 2 * TAILLE_CASE, 3, 0);
    Ennemi ennemi1 (sprites_personnages, 5 * TAILLE_CASE, TAILLE_CASE, 3, 4, HAUT);
    Ennemi ennemi2 (sprites_personnages, TAILLE_CASE, 5 * TAILLE_CASE, 6, 4, DROITE);

    bool quitter = false;
    bool perdu = false;
    bool gagne = false;

    // Boucle de jeu, appelee a chaque fois que l'ecran doit etre mis a jour
    // (en general, 60 fois par seconde)
    while (!quitter)
    {
        bool bouge = false;

        // I. Gestion des evenements
        Evenement evenement = moteur.evenementRecu();
        while (evenement != AUCUN)
        {
            switch (evenement)
            {
            // QUITTER = croix de la fenetre ou Echap
            case QUITTER_APPUYE:
                quitter = true;
                break;
            case DROITE_APPUYE:
                avatar.allerDroite(niveau);
                bouge = true;
                break;
            case GAUCHE_APPUYE:
                avatar.allerGauche(niveau);
                bouge = true;
                break;
            case BAS_APPUYE:
                avatar.allerBas(niveau);
                bouge = true;
                break;
            case HAUT_APPUYE:
                avatar.allerHaut(niveau);
                bouge = true;
                break;
            case ESPACE_APPUYE:
                if ( niveau.testerPorte( avatar.getX(), avatar.getY() + TAILLE_CASE ) )
                {
                    bravo.dessiner(LARGEUR_FENETRE / 2 - gameover.getLargeur() / 2,
                                   HAUTEUR_FENETRE / 2 - gameover.getHauteur() / 2);
                    moteur.attendre(2);
                    quitter=true;
                }
                break;
            }
        default:
            break;


            evenement = moteur.evenementRecu();
        }

        // II. Mise à jour de l'état du jeu

        if (moteur.animationsAmettreAjour())
        {
            ennemi1.avancer(niveau);
            ennemi2.avancer(niveau);
        }

        if (avatar.touche(ennemi1) || avatar.touche(ennemi2))
        {

            //question 2.5
            avatar.perteVie();

//      quitter = true;
//      perdu = true;
        }

        //question 2.7
        if ( !avatar.touche(ennemi1) && !avatar.touche(ennemi2))
        {
            avatar.finInvincibilite();

        }

        //question 2.8
        if ( avatar.getNbVies()==0)
        {
            perdu=true;
            quitter=true;
        }
        if (bouge)
        {
            niveau.testerBonusEtPrendre(avatar.getX(), avatar.getY());
            if (niveau.gagne())
            {
                quitter = true;
                gagne = true;
            }
        }

        // III. Generation de l'image à afficher

        moteur.initialiserRendu(); // efface ce qui avait ete affiche precedemment et reinitalise en ecran noir

        fond.dessiner(0, 0);
        niveau.dessiner();

        //question 2.3
        int x=(NB_CASE_LARGEUR-1)*TAILLE_CASE;
        for ( int i=0; i < avatar.getNbVies(); i++)
        {
            vie.dessiner(x,0);
            x-=TAILLE_CASE;

        }

        avatar.dessiner();
        ennemi1.dessiner();
        ennemi2.dessiner();

        if (perdu)
            gameover.dessiner(LARGEUR_FENETRE / 2 - gameover.getLargeur() / 2,
                              HAUTEUR_FENETRE / 2 - gameover.getHauteur() / 2);

        /*Affiche l'image en se cadencant sur la frequence de
          rafraichissement de l'ecran (donc va en general mettre le
          programme en pause jusqu'a ce que l'ecran soit rafraichi). En
          general, 60 images fois par seconde, mais ca peut dependre du
          materiel
        */
        moteur.finaliserRendu();
    }

    if (perdu || gagne) // Si ni perdu ni gagne, jeu ferme par la croix, on n'attend pas
        moteur.attendre(2);

    return 0;
}
