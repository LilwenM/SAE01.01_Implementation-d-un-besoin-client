/**
 * \file BasePuissance4_versionFinal.c
 * \brief SAE 01.01 -- Programme d'un Puissance4
 * \author Lilwen MALESTROIT
 * \version 2.7
 * \date 18/11/2022
 * 
 * Ce programme permet à deux utilisateurs.ices de s'affronter lors d'une
 * partie de Puissance4. Le programme gère l'affichage de la grille, 
 * l'ajout des pieces et verifie le.la potentiel.le gagnant.e.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/**
 * \def couleur(param)
 * Permet l'affichage avec des couleurs
*/
/**
 * \def NbLig 
 * Permet d'enregistrer le nombre de ligne de la grille
*/
/**
 * \def NbCol 
 * Permet d'enregistrer le nombre de colonne de la grille
*/
#define couleur(param) printf("\033[%sm", param)
#define NbLig 6
#define NbCol 7


        /*Déclarations des types*/

/**
 * \typedef int t_grille[NbLig][NbCol]
 * \brief Nom du type du tableau utilisé pour gerer le jeu
*/
/**
 * \typedef char t_cellule[100];
 * \brief Nom du type des différents affichages composant la grille
*/
/**
 * \typedef int t_indiceGagne[4][2]
 * \brief Nom du type du tableau utilisé pour enregistrer les indices des pions gagnants
*/
typedef int t_grille[NbLig][NbCol]; 
typedef char t_cellule[100];
typedef int t_indiceGagne[4][2]; 


        /*Constantes*/

/**
 * \def int CampOrange = 1
 * \brief Nom permettant l'identification du.de la joueur.euse Orange et l'affichage 
 * de son pion dans la grille
*/
/**
 * \def int CampBleu = 2
 * \brief Nom permettant l'identification du.de la joueur.euse Bleu.e et l'affichage 
 * de son pion dans la grille
*/
/**
 * \def int Vide = 0
 * \brief Nom permettant l'identification des cases vides de la grille et leur
 * l'affichage
*/
/**
 * \def int Inconnu = 0
 * \brief Nom permettant de signifier que le ou la gagnant.e est inconnu.e
*/
/**
 * \def t_cellule Tentete = "     1   2   3   4   5   6   7  "
 * \brief Nom de l'entete de la grille
*/
/**
 * \def t_cellule Tligne = "   ║———+———+———+———+———+———+———║"
 * \brief Nom de la ligne de separation de la grille
*/
/**
 * \def t_cellule Tbas = "   ╚═══════════════════════════╝"
 * \brief Nom du bas de la grille.  
*/
/**
 * \def t_cellule CelluleVideGauche = "   ║   |"
 * \brief Nom de la cellule vide a gauche de la grille.
*/
/**
 * \def t_cellule CelluleVideDroite = "   ║"
 * \brief Nom de la cellule vide a droite de la grille.
*/
/**
 * \def t_cellule CelluleVideCentre = "   |"
 * \brief Nom d'une cellule vide au centre de la grille.
*/
/**
 * \def t_cellule CellulePleineGauche = "   ║"
 * \brief Nom d'une cellule pleine à gauche de la grille.
*/
/**
 * \def t_cellule CellulePleineDroite = " ║"
 * \brief Nom d'une cellule pleine à droite de la grille.
*/
/**
 * \def t_cellule CellulePleineCentre = " |"
 * \brief Nom d'une cellule pleine au centre de la grille.
*/
/**
 * \def t_cellule CellulePiece = " ⬤"
 * \brief Nom de la pièce.
*/
const int CampOrange = 1; 
const int CampBleu = 2; 
const int Vide = 0; 
const int Inconnu = 0;

const t_cellule Tentete              =   "     1   2   3   4   5   6   7  \n"; 
/*const t_cellule Tligne               =   "   ║———+———+———+———+———+———+———║\n"; 
const t_cellule Tbas                 =   "   ╚═══════════════════════════╝\n\n";
const t_cellule CelluleVideGauche    =   "   ║   |"; 
const t_cellule CelluleVideDroite    =   "   ║\n"; 
const t_cellule CelluleVideCentre    =   "   |";
const t_cellule CellulePleineGauche  =   "   ║";
const t_cellule CellulePleineDroite  =   " ║\n";
const t_cellule CellulePleineCentre  =   " |";
const t_cellule CellulePiece         =   " ⬤";*/
const t_cellule Tligne               =   "   |---+---+---+---+---+---+---|\n"; 
const t_cellule Tbas                 =   "   |---------------------------|\n\n";
const t_cellule CelluleVideGauche    =   "   |   |"; 
const t_cellule CelluleVideDroite    =   "   |\n"; 
const t_cellule CelluleVideCentre    =   "   |";
const t_cellule CellulePleineGauche  =   "   |";
const t_cellule CellulePleineDroite  =   " |\n";
const t_cellule CellulePleineCentre  =   " |";
const t_cellule CellulePiece         =   " O";



        /*Déclarations des entêtes des Procédures et Fonctions*/

/**
 * \fn void Pseudo(char pseudoOrange[30], char pseudoBleu[30])
 * \brief Procedure permettant aux utilisateurs.ices de modifier ou non leurs pseudos
 * \param pseudoOrange Chaine de caractere choisie par le.la joueur.euse Orange
 * \param pseudoBleu Chaine de caractere choisie par le.la joueur.euse Bleu.e
*/
void Pseudo(char pseudoOrange[30], char pseudoBleu[30]); 

/**
 * \fn void InitGrille(t_grille puissanceQuatre)
 * \brief Procédure permettant d'initialiser la grille du puissance4 avec seulement des cases vides
 * \param puissanceQuatre Tableau d'entier
 */
void InitGrille(t_grille puissanceQuatre); 

/**
 * \fn void InitGrille(t_grille puissanceQuatre)
 * \brief Procédure permettant d'initialiser le tableau des indices des pions gagnants avec seulement des entiers -1
 * \param tableauIndice Tableau d'entier contenant les indices des pions gagnants
 */
void InitTabIndice(t_indiceGagne tableauIndice); 

/**
 * \fn void AffichePuissanceQuatre(t_grille puissanceQuatre)
 * \brief Procédure permettant d'afficher la grille du puissance4 à partir du tableau puissanceQuatre
 * \param puissanceQuatre Tableau d'entier
 * \param camp L'entier permettant d'identifier qui a joué
 * \param colonnePrec Entier contenant l'indice de la colonne jouée par l'utilisateur.ice précédant.e
 */
void AffichePuissanceQuatre(t_grille puissanceQuatre, int camp, int colonnePrec); 

/**
 * \fn PionGagnant(t_indiceGagne tableauIndice, int indiceLigne, int indiceColonne)
 * \brief Fonction booleen verifiant si le pion aux indices entres en parametre est un pion gagnant
 * \param tableauIndice Tableau d'entier contenant les indices des pions gagnants
 * \param indiceLigne Indice de la ligne
 * \param indiceColonne Indice de la colonne
 * \return Vrai si le pion est gagnant, faux sinon
 */
bool PionGagnant(t_indiceGagne tableauIndice, int indiceLigne, int indiceColonne); 

/**
 * \fn void AffichePuissanceQuatreFinal(t_grille puissanceQuatre, t_indiceGagne tableauIndice, int vainqueur)
 * \brief Procédure permettant d'afficher la grille du puissance4 à partir du tableau puissanceQuatre a la fin de la partie
 * (seuls les jetons gagnants seront affiches de couleur)
 * \param puissanceQuatre Tableau d'entier
 * \param tableauIndice Tableau d'entier contenant les indices des pions gagnants
 * \param vainqueur L'entier permettant d'identifier qui a gagne
 */
void AffichePuissanceQuatreFinal(t_grille puissanceQuatre, t_indiceGagne tableauIndice, int vainqueur);  

/**
 * \fn TableauComplet(t_grille puissanceQuatre)
 * \brief Fonction booleen verifiant si le tableau est complet
 * \param puissanceQuatre Tableau d'entier
 * \return Vrai si le tableau est complet, faux sinon
 */
bool TableauComplet(t_grille puissanceQuatre); 

/**
 * \fn ColonneComplete(t_grille puissanceQuatre, int colonne)
 * \brief Fonction booleen verifiant si la colonne entree en paramètre est complete
 * \param puissanceQuatre Tableau d'entier
 * \param colonne L'indice de la colonne 
 * \return Vrai si la colonne est complete, faux sinon
 */
bool ColonneComplete(t_grille puissanceQuatre, int colonne); 

/**
 * \fn ChoisirColonne(t_grille puissanceQuatre, char camp)
 * \brief Fonction booleen permettant à l'utilisateurice de choisir la colonne où iel 
 * souhaite inserer son pion, cette fonction verifie grace a la fonction ColonneComplete si 
 * il y a de la place dans la colonne souhaitee et si elle est valide
 * \param puissanceQuatre Tableau d'entier
 * \param pseudo Chaine de caractere du.de la joueur.euse 
 * \param camp L'entier permettant d'identifier qui joue
 * \param campPrec L'entier permettant d'identifier qui a joué
 * \param colonnePrec Entier contenant l'indice de la colonne précédente
 * \return Un entier contenant la colonne choisie
 */
int ChoisirColonne(t_grille puissanceQuatre, char pseudo[30], char camp, int campPrec, int colonnePrec); 

/**
 * \fn TrouverLigne(t_grille puissanceQuatre,  int colonne)
 * \brief Fonction booleen permettant de chercher la première ligne vide rencontree 
 * dans la colonne en parametre
 * \param puissanceQuatre Tableau d'entier 
 * \param colonne L'indice de la colonne 
 * \return Un entier contenant la première ligne vide a partir du bas
 */
int TrouverLigne(t_grille puissanceQuatre, int colonne); 

/**
 * \fn VerificationColonne(t_grille puissanceQuatre, char camp, int ligne, int colonne)
 * \brief Fonction booléen permettant de vérifier si le coup joué est gagnant ou non dans la colonne
 * \param puissanceQuatre Tableau d'entier
 * \param camp L'entier permettant d'identifier qui joue
 * \param ligne L'indice de la ligne
 * \param colonne L'indice de la colonne
 * \param tableauIndice Tableau d'entier contenant les indices des pions gagnants
 * \return Vrai si la coup est gagnant dans la colonne, faux sinon
 */
bool VerificationColonne(t_grille puissanceQuatre, char camp, int ligne, int colonne, t_indiceGagne tableauIndice);

/**
 * \fn VerificationLigne(t_grille puissanceQuatre, char camp, int ligne, int colonne)
 * \brief Fonction booléen permettant de vérifier si le coup joué est gagnant ou non dans la ligne.
 * \param puissanceQuatre Tableau d'entier
 * \param camp L'entier permettant d'identifier qui joue
 * \param ligne L'indice de la ligne
 * \param colonne L'indice de la colonne
 * \param tableauIndice Tableau d'entier contenant les indices des pions gagnants
 * \return Vrai si le coup est gagnant dans la ligne, faux sinon
 */
bool VerificationLigne(t_grille puissanceQuatre, char camp, int ligne, int colonne, t_indiceGagne tableauIndice);

/**
 * \fn VerificationDiagonale1(t_grille puissanceQuatre, char camp, int ligne, int colonne)
 * \brief Fonction booléen permettant de vérifier si le coup joué est gagnant ou non dans la première diagonale (haut-gauche à bas-droite)
 * \param puissanceQuatre Tableau d'entier
 * \param camp L'entier permettant d'identifier qui joue
 * \param ligne L'indice de la ligne
 * \param colonne L'indice de la colonne
 * \param tableauIndice Tableau d'entier contenant les indices des pions gagnants
 * \return Vrai si la coup est gagnant dans la premiere diagonale, faux sinon
 */
bool VerificationDiagonale1(t_grille puissanceQuatre, char camp, int ligne, int colonne, t_indiceGagne tableauIndice);

/**
 * \fn VerificationDiagonale2(t_grille puissanceQuatre, char camp, int ligne, int colonne)
 * \brief Fonction booléen permettant de vérifier si le coup joué est gagnant ou non dans la deuxième diagonale (haut-droite à bas-gauche)
 * \param puissanceQuatre Tableau d'entier
 * \param camp L'entier permettant d'identifier qui joue
 * \param ligne L'indice de la ligne
 * \param colonne L'indice de la colonne
 * \param tableauIndice Tableau d'entier contenant les indices des pions gagnants
 * \return Vrai si la coup est gagnant dans la deuxieme diagonale, faux sinon
 */
bool VerificationDiagonale2(t_grille puissanceQuatre, char camp, int ligne, int colonne, t_indiceGagne tableauIndice);

/**
 * \fn VerificationGagne(t_grille puissanceQuatre, int ligne, int colonne)
 * \brief Fonction booleen permettant de chercher la première ligne vide rencontree 
 * dans la colonne en parametre
 * \param puissanceQuatre Tableau d'entier
 * \param ligne L'indice de la ligne
 * \param colonne L'indice de la colonne
 * \param tableauIndice Tableau d'entier contenant les indices des pions gagnants
 * \return Vrai si la coup est gagnant, faux sinon
 */
bool VerificationGagne(t_grille puissanceQuatre, int ligne, int colonne, t_indiceGagne tableauIndice); 

/**
 * \fn Jouer(t_grille puissanceQuatre, char pseudo[30], char camp)
 * \brief Procédure permettant le jeu des deux joueurs.euses
 * \param puissanceQuatre Tableau d'entier
 * \param pseudo Chaine de caractere du.de la joueur.euse 
 * \param camp L'entier permettant d'identifier qui joue
 * \param tableauIndice Tableau d'entier contenant les indices des pions gagnants
 * \param ligne Entier contenant l'indice de la ligne
 * \param colonne Entier contenant l'indice de la colonne 
 * \param campPrec L'entier permettant d'identifier qui a joué
 * \param colonnePrec Entier contenant l'indice de la colonne précédente
 */
void Jouer(t_grille puissanceQuatre, char pseudo[30], char camp, t_indiceGagne tableauIndice, int *ligne, int *colonne, int campPrec, int colonnePrec);

/**
 * \fn FinDePartie(char vainqueur, char pseudoOrange[30], char pseudoBleu[30])
 * \brief Procédure permettant l'affichage en fin de partie en fonction du résultat de cette dernière
 * \param vainqueur L'entier permettant d'identifier qui a gagné
 * \param pseudoOrange Chaine de caractere choisie par le.la joueur.euse Orange
 * \param pseudoBleu Chaine de caractere choisie par le.la joueur.euse Bleu.e
 */
void FinDePartie(char vainqueur, char pseudoOrange[30], char pseudoBleu[30]); 


            /*Programme principal*/

/**
 * \fn int main()
 * \brief Fonction principale
 * \return EXIT_SUCCESS
 */
int main()
{
    t_grille puissanceQuatre; 
    t_indiceGagne tableauIndice; 
    int vainqueur; 
    int ligne, colonne; 
    int colonnePrec; 
    bool coupGagnant; 
    char pseudoJO[30], pseudoJB[30]; 

    vainqueur = Inconnu; 

    strcpy(pseudoJO, "J.Orange"); 
    strcpy(pseudoJB, "J.Bleu.e"); 

    Pseudo(pseudoJO, pseudoJB); 

    InitGrille(puissanceQuatre); 
    AffichePuissanceQuatre(puissanceQuatre, Inconnu, 0); 
    Jouer(puissanceQuatre, pseudoJO, CampOrange, tableauIndice, &ligne, &colonne, Inconnu, 0);  

    while ((vainqueur == Inconnu) && (TableauComplet(puissanceQuatre) != true))
    {
        coupGagnant = VerificationGagne(puissanceQuatre, ligne, colonne, tableauIndice); 
        colonnePrec = colonne; 

        if (coupGagnant == true)
        {
            vainqueur = CampOrange; 
        }
        else //Il y a un nombre pair de cases donc inutile de vérifier si la grille est pleine
        {
            AffichePuissanceQuatre(puissanceQuatre, CampOrange, colonne); 
            Jouer(puissanceQuatre, pseudoJB, CampBleu, tableauIndice, &ligne, &colonne, CampOrange, colonnePrec); 
            coupGagnant = VerificationGagne(puissanceQuatre, ligne, colonne, tableauIndice); 

            colonnePrec = colonne; 

            if (coupGagnant == true)
            {
                vainqueur = CampBleu; 
            }
            else
            {
                AffichePuissanceQuatre(puissanceQuatre, CampBleu, colonne); 
                Jouer(puissanceQuatre, pseudoJO, CampOrange, tableauIndice, &ligne, &colonne, CampBleu, colonnePrec);         
            }
        }
    }

    AffichePuissanceQuatreFinal(puissanceQuatre, tableauIndice, vainqueur);
    FinDePartie(vainqueur, pseudoJO, pseudoJB); 
    
    return EXIT_SUCCESS; 
}


        /*Procédures et Fonctions*/

void Pseudo(char pseudoOrange[30], char pseudoBleu[30])
{
    system("clear"); 
    char entree, del; 

    printf("\n"); 

    printf("   Pseudo du.de la joueur.euse ");
    couleur("33");
    printf("ORANGE"); 
    couleur("0");
    printf(" : "); 
    couleur("33");
    printf("%s\n", pseudoOrange); 
    couleur("0");
    printf("   Pseudo du.de la joueur.euse ");
    couleur("36");
    printf("BLEU.E"); 
    couleur("0");
    printf(" : "); 
    couleur("36");
    printf("%s\n\n", pseudoBleu); 
    couleur("0");

    printf("   Voulez vous modifier vos pseudos ?\n");
    printf("          > Oui (entrez O)\n");
    printf("          > Non (entrez N)\n");
    printf("   --> "); 
    scanf("%c%c", &entree, &del); 

    while ((entree != 'O') && (entree != 'o') &&
           (entree != 'N') && (entree != 'n'))
    {
        printf("\n\n   Une erreur de saisie s'est produite !\n"); 
        printf("   Voulez vous modifier vos pseudos ?\n");
        printf("          > Oui (entrez O)\n");
        printf("          > Non (entrez N)\n");
        printf("   --> "); 
        scanf("%c%c", &entree, &del); 
    }

    if ((entree == 'O') || (entree == 'o'))
    {
        printf("\n      Joueur.euse ");
        couleur("33");
        printf("ORANGE"); 
        couleur("0");
        printf(", entrez votre pseudonyme : "); 
        couleur("33");
        scanf("%[^\n]", pseudoOrange);
        getchar(); 
        couleur("0");
        printf("      Joueur.euse ");
        couleur("36");
        printf("BLEU.E"); 
        couleur("0");
        printf(", entrez votre pseudonyme : "); 
        couleur("36");
        scanf("%[^\n]", pseudoBleu);
        getchar(); 
        couleur("0");
    }
}

void InitGrille(t_grille puissanceQuatre)
{
    for (int i = 0 ; i < NbLig ; i++)
    {
        for (int j = 0 ; j < NbCol ; j++)
        {
            puissanceQuatre[i][j] = Vide; 
        }
    }
}

void InitTabIndice(t_indiceGagne tableauIndice)
{
    for (int i = 0 ; i < 4 ; i++)
    {
        for (int j = 0 ; j < 2 ; j++)
        {
            tableauIndice[i][j] = -1; 
        }
    }
}

void AffichePuissanceQuatre(t_grille puissanceQuatre, int camp, int colonnePrec)
{
    system("clear"); 
    
    if (camp == CampOrange)
    {
        printf("\n\n   Le "); 
        couleur("33"); 
        printf("V"); 
        couleur("0"); 
        printf(" designe le pion precedent\n");
    }
    else if (camp == CampBleu)
    {
        printf("\n\n   Le "); 
        couleur("36"); 
        printf("V"); 
        couleur("0"); 
        printf(" designe le pion precedent\n");
    }
     

    printf("\n\n     "); 
    for (int x = 1 ; x <= colonnePrec ; x++)
    {
        printf("    "); 
    }
    if (camp == CampOrange)
    {
        couleur("33");
        printf("V"); 
        couleur("0");
    }
    else if (camp == CampBleu)
    {
        couleur("36");
        printf("V"); 
        couleur("0");
    }
    printf("\n"); 

    printf("%s", Tentete);

    for (int i = 0 ; i < NbLig ; i++)
    {
        for (int j = 0 ; j < NbCol ; j++)
        {
            if (puissanceQuatre[i][j] == CampOrange)
            {
                if (j == 0)
                {
                    printf("%s", CellulePleineGauche);
                    couleur("33");
                    printf("%s", CellulePiece);
                    couleur("0"); 
                    printf("%s", CellulePleineCentre);
                }
                else if (j == 6)
                {
                    couleur("33");
                    printf("%s", CellulePiece);
                    couleur("0"); 
                    printf("%s", CellulePleineDroite);
                }
                else
                {
                    couleur("33");
                    printf("%s", CellulePiece);
                    couleur("0"); 
                    printf("%s", CellulePleineCentre);
                }
            }

            else if (puissanceQuatre[i][j] == CampBleu)
            {
                if (j == 0)
                {
                    printf("%s", CellulePleineGauche);
                    couleur("36");
                    printf("%s", CellulePiece);
                    couleur("0"); 
                    printf("%s", CellulePleineCentre);
                }
                else if (j == 6)
                {
                    couleur("36");
                    printf("%s", CellulePiece);
                    couleur("0"); 
                    printf("%s", CellulePleineDroite);
                }
                else
                {
                    couleur("36");
                    printf("%s", CellulePiece);
                    couleur("0"); 
                    printf("%s", CellulePleineCentre);
                }
            }

            else
            {
                if (j == 0)
                {
                    printf("%s", CelluleVideGauche);
                }
                else if (j == 6)
                {
                    printf("%s", CelluleVideDroite);
                }
                else
                {
                    printf("%s", CelluleVideCentre);
                }
            }
        }
        if (i == 5)
        {
            printf("%s", Tbas);
        }
        else 
        {
            printf("%s", Tligne);
        }
    }
}

bool PionGagnant(t_indiceGagne tableauIndice, int indiceLigne, int indiceColonne)
{
    bool estGagnant; 
    estGagnant = false; 

    for (int i = 0 ; (i < 4) && (estGagnant != true) ; i++)
    {
        if ((tableauIndice[i][0] == indiceLigne) && (tableauIndice[i][1] == indiceColonne))
        {
            estGagnant = true; 
        }
    }

    return estGagnant; 
}

void AffichePuissanceQuatreFinal(t_grille puissanceQuatre, t_indiceGagne tableauIndice, int vainqueur)
{
    system("clear");

    bool estGagnant; 

    printf("\n\n%s", Tentete);

    for (int i = 0 ; i < NbLig ; i++)
    {
        for (int j = 0 ; j < NbCol ; j++)
        {
            estGagnant = PionGagnant(tableauIndice, i, j); 

            if (estGagnant == true)
            {
                if (vainqueur == CampOrange)
                {
                    if (j == 0)
                    {
                        printf("%s", CellulePleineGauche);
                        couleur("33");
                        printf("%s", CellulePiece);
                        couleur("0"); 
                        printf("%s", CellulePleineCentre);
                    }
                    else if (j == 6)
                    {
                        couleur("33");
                        printf("%s", CellulePiece);
                        couleur("0"); 
                        printf("%s", CellulePleineDroite);
                    }
                    else
                    {
                        couleur("33");
                        printf("%s", CellulePiece);
                        couleur("0"); 
                        printf("%s", CellulePleineCentre);
                    }
                }
                else
                {
                    if (j == 0)
                    {
                        printf("%s", CellulePleineGauche);
                        couleur("36");
                        printf("%s", CellulePiece);
                        couleur("0"); 
                        printf("%s", CellulePleineCentre);
                    }
                    else if (j == 6)
                    {
                        couleur("36");
                        printf("%s", CellulePiece);
                        couleur("0"); 
                        printf("%s", CellulePleineDroite);
                    }
                    else
                    {
                        couleur("36");
                        printf("%s", CellulePiece);
                        couleur("0"); 
                        printf("%s", CellulePleineCentre);
                    }
                }
            }

            else if ((puissanceQuatre[i][j] == CampOrange) || (puissanceQuatre[i][j] == CampBleu))
            {
                if (j == 0)
                {
                    printf("%s%s%s", CellulePleineGauche, CellulePiece, CellulePleineCentre);
                }
                else if (j == 6)
                {
                    printf("%s%s", CellulePiece, CellulePleineDroite);
                }
                else
                {
                    printf("%s%s", CellulePiece, CellulePleineCentre);
                }
            }

            else
            {
                if (j == 0)
                {
                    printf("%s", CelluleVideGauche);
                }
                else if (j == 6)
                {
                    printf("%s", CelluleVideDroite);
                }
                else
                {
                    printf("%s", CelluleVideCentre);
                }
            }
        }
        if (i == 5)
        {
            printf("%s", Tbas);
        }
        else 
        {
            printf("%s", Tligne);
        }
    }
}

bool TableauComplet(t_grille puissanceQuatre)
{
    bool restePlace; 
    restePlace = true;

    for (int i = 0; i < NbLig; i++)
    {
        for (int x = 0; x < NbCol; x++)
        {
            if (puissanceQuatre[i][x] == Vide)
            {
                restePlace = false;
            }
        }
    }
    
    return restePlace; 
}

bool ColonneComplete(t_grille puissanceQuatre, int colonne)
{
    bool restePlace; 
    restePlace = true; 

    for (int i = 0; i < NbLig; i++)
    {
        if (puissanceQuatre[i][colonne] == 0)
        {
            restePlace = false;
        }
    }

    return restePlace; 
}

int ChoisirColonne(t_grille puissanceQuatre, char pseudo[30], char camp, int campPrec, int colonnePrec)
{
    char colonneChoisie[10];
    int colonne;

    printf("\n   |   ");
    if (camp == CampOrange)
    {
        couleur("33");
    }
    else if (camp == CampBleu)
    {
        couleur("36");
    }
    printf("%s", pseudo);
    couleur("0"); 
    printf("   |   Colonne : ");
    scanf("%s", colonneChoisie);

    colonne = atoi(colonneChoisie); //Permet de convertir une chaine de caractere par un entier (fonctionne grace a la libraire stdlib.h)

    while ((colonne < 1) || (colonne > 7)  || 
           (ColonneComplete(puissanceQuatre, colonne-1) == true)) 
    {
        AffichePuissanceQuatre(puissanceQuatre, campPrec, colonnePrec);
        printf("\n   Saisie de la colonne incorrecte.\n");
        printf("\n   |   ");
        if (camp == CampOrange)
        {
            couleur("33");
        }
        else if (camp == CampBleu)
        {
            couleur("36");
        }
        printf("%s", pseudo);
        couleur("0"); 
        printf("   |   Colonne : ");
        scanf("%s", colonneChoisie);

        colonne = atoi(colonneChoisie); 
    }

    return colonne-1; 
}

int TrouverLigne(t_grille puissanceQuatre, int colonne)
{
    int ligne;
    bool sortie; 
    sortie = true;

    for (int i = 5; ((i >= 0) && (sortie == true))  ; i--)
    {
        if ((puissanceQuatre[i][colonne] != CampOrange) && (puissanceQuatre[i][colonne] != CampBleu))
        {
            ligne = i; 
            sortie = false;
        }
    }

    return ligne; 
}

bool VerificationColonne(t_grille puissanceQuatre, char camp, int ligne, int colonne, t_indiceGagne tableauIndice)
{
    int cmp;
    bool sortie; 
    bool gagnant; 
    cmp = 1; 
    sortie = true;
    gagnant = false; 

    tableauIndice[0][0] = ligne; 
    tableauIndice[0][1] = colonne; 

    for (int i = 1; ((i < 4) && (ligne+i < NbLig) && (sortie == true)); i++)
    {
        if (puissanceQuatre[ligne+i][colonne] == camp)
        {
            tableauIndice[cmp][0] = ligne+i; 
            tableauIndice[cmp][1] = colonne; 
            cmp++; 
        }
        else 
        {
            sortie = false; 
        }
    }
    if (cmp >= 4)
    {
        gagnant = true; 
    }
    return gagnant; 
}

bool VerificationLigne(t_grille puissanceQuatre, char camp, int ligne, int colonne, t_indiceGagne tableauIndice)
{
    int cmp;
    bool sortie; 
    bool gagnant; 
    cmp = 1; 
    sortie = true;
    gagnant = false; 

    tableauIndice[0][0] = ligne; 
    tableauIndice[0][1] = colonne; 
    
    for (int i = 1; ((colonne+i < NbCol) && (cmp <= 4) && (sortie == true)); i++)
    {
        if (puissanceQuatre[ligne][colonne+i] == camp)
        {
            tableauIndice[cmp][0] = ligne; 
            tableauIndice[cmp][1] = colonne+i; 
            cmp++; 
        }
        else
        {
            sortie = false;
        }
    }

    sortie = true;

    if (cmp < 4)
    {
        for (int i = 1; ((colonne-i >= 0) && (cmp <= 4) && (sortie == true)); i++)
        {
            if (puissanceQuatre[ligne][colonne-i] == camp)
            {
                tableauIndice[cmp][0] = ligne; 
                tableauIndice[cmp][1] = colonne-i; 
                cmp++; 
            }
            else
            {
                sortie = false;
            }
            
        }
    }
    if (cmp >= 4)
    {
        gagnant = true; 
    }
    return gagnant; 
}

bool VerificationDiagonale1(t_grille puissanceQuatre, char camp, int ligne, int colonne, t_indiceGagne tableauIndice)
{
    int cmp;
    bool sortie; 
    bool gagnant; 
    cmp = 1; 
    sortie = true;
    gagnant = false; 

    tableauIndice[0][0] = ligne; 
    tableauIndice[0][1] = colonne; 
    
    for (int i = 1; ((ligne+i < NbLig) && (colonne+i < NbCol) && (cmp <= 4) && (sortie == true)); i++)
    {
        if (puissanceQuatre[ligne+i][colonne+i] == camp)
        {
            tableauIndice[cmp][0] = ligne+i; 
            tableauIndice[cmp][1] = colonne+i;
            cmp++; 
        }
        else
        {
            sortie = false; 
        }
    }

    sortie = true; 

    if (cmp < 4)
    {
        for (int i = 1; ((ligne-i >= 0) && (colonne-i >= 0) && (cmp <= 4) && (sortie == true)); i++)
        {
            if (puissanceQuatre[ligne-i][colonne-i] == camp)
            {
                tableauIndice[cmp][0] = ligne-i; 
                tableauIndice[cmp][1] = colonne-i;
                cmp++; 
            }
            else
            {
                sortie = false; 
            }
        }
    }
    if (cmp >= 4)
    {
        gagnant = true; 
    }
    return gagnant; 
}

bool VerificationDiagonale2(t_grille puissanceQuatre, char camp, int ligne, int colonne, t_indiceGagne tableauIndice)
{
    int cmp;
    bool sortie; 
    bool gagnant; 
    cmp = 1; 
    sortie = true;
    gagnant = false; 

    tableauIndice[0][0] = ligne; 
    tableauIndice[0][1] = colonne;
    
    for (int i = 1; ((ligne-i >= 0) && (colonne+i < NbCol) && (cmp <= 4) && (sortie == true)); i++)
    {
        if (puissanceQuatre[ligne-i][colonne+i] == camp)
        {
            tableauIndice[cmp][0] = ligne-i; 
            tableauIndice[cmp][1] = colonne+i;
            cmp++; 
        }
        else
        {
            sortie = false; 
        }
    }

    sortie = true; 

    if (cmp < 4)
    {
        for (int i = 1; ((ligne+i < NbLig) && (colonne-i >= 0) && (cmp <= 4) && (sortie == true)); i++)
        {
            if (puissanceQuatre[ligne+i][colonne-i] == camp)
            {
                tableauIndice[cmp][0] = ligne+i; 
                tableauIndice[cmp][1] = colonne-i;
                cmp++; 
            }
            else
            {
                sortie = false; 
            }
        }
    }
    if (cmp >= 4)
    {
        gagnant = true; 
    }
    return gagnant; 
}

bool VerificationGagne(t_grille puissanceQuatre, int ligne, int colonne, t_indiceGagne tableauIndice)
{
    bool gagnant; 
    char camp; 
    camp = puissanceQuatre[ligne][colonne]; 
    
    InitTabIndice(tableauIndice); 

    gagnant = VerificationColonne(puissanceQuatre, camp, ligne, colonne, tableauIndice); 
    if (gagnant != true)
    {
        InitTabIndice(tableauIndice); 

        gagnant = VerificationLigne(puissanceQuatre, camp, ligne, colonne, tableauIndice);
        if (gagnant != true)
        {
            InitTabIndice(tableauIndice); 

            gagnant = VerificationDiagonale1(puissanceQuatre, camp, ligne, colonne, tableauIndice);
            if (gagnant != true)
            {
                InitTabIndice(tableauIndice); 

                gagnant = VerificationDiagonale2(puissanceQuatre, camp, ligne, colonne, tableauIndice); 
            }
        }
    }

    if (gagnant != true)
    {
        InitTabIndice(tableauIndice); 
    }

    return gagnant;
}

void Jouer(t_grille puissanceQuatre, char pseudo[30], char camp, t_indiceGagne tableauIndice, int *ligne, int *colonne, int campPrec, int colonnePrec)
{
    *ligne = -1; 

    *colonne = ChoisirColonne(puissanceQuatre, pseudo, camp, campPrec, colonnePrec); 
    *ligne = TrouverLigne(puissanceQuatre, *colonne); 
    
    puissanceQuatre[*ligne][*colonne] = camp;
}

void FinDePartie(char vainqueur, char pseudoOrange[30], char pseudoBleu[30])
{
    if (vainqueur == CampOrange)
    {
        printf("\n    Le.la joueur.euse ");
        couleur("33");
        printf("%s", pseudoOrange);
        couleur("0");
        printf(" a gagne !\n\n");
    }
    else if (vainqueur == CampBleu)
    {
        printf("\n    Le.la joueur.euse ");
        couleur("36");
        printf("%s", pseudoBleu);
        couleur("0");
        printf(" a gagne !\n\n");
    }
    else 
    {
        printf("\n    Il n'y a aucun.e gagnant.e sur cette partie !\n\n");
    } 
}
