#ifndef VIEW_H
#define VIEW_H
#include <iostream>
#include <string>
#include <limits.h>
#include <vector>
#include <Game.h>


namespace staticMethod{
/**
 * @brief getUpper met le string mit en paramètre en majuscule
 * @param s un string a modifier
 * @return le string en majuscule
 */
 string getUpper(const string &s){
    string converted;
    for(basic_string<char>::size_type i = 0; i < s.length();++i){
        converted+=toupper(s[i]);
    }
    return converted;
}
 /**
  * @brief sameString compare les deux string
  * @param s1 string à comparer
  * @param s2 string à comparer
  * @return true si s1 et s2 sont égaux sinon faux
  */
 bool sameString(const string &s1,const string &s2) {
    if(getUpper(s1).compare(getUpper(s2)) == 0){
        return true;
    }
    return false;
}

}

using namespace std;
using namespace staticMethod;

/**
 * @brief The View class sert à l'affichage du jeu
 */
class View{
private:
    /**
     * @brief game La structure du jeu
     */
    //un const game
    const Game *game;



    /**
     * @brief displayLetters sert à afficher l'ordonnée du jeu en Lettre
     * @param a un nombre
     * @return retourne une lettre
     */
    char displayLetters(int a);

    /**
     * @brief displayInteger
     * @param letter  une lettre
     * @return un nombre (ordonnée du tableau)
     */
    int displayInteger(char letter);

    /**
     * @brief displayBoard affiche le tableau
     * @param board Le tableau du jeu
     * @param i abscisse du tableau
     * @param j ordonnée du tableau
     */
    void displayBoard(int i , int j);

public:

    View()=default;
    /**
     * @brief View
     * @param game objet de la class Game. la structure du jeu
     */
    View(const Game *game);

    /**
     * @brief displayWelcome Affiche la bienvenue
     */
    void displayWelcome();

    /**
     * @brief displayGame Affiche le jeu pour les deux joueurs
     * @param board Le tableau du jeu
     */
    void displayGame();


    /**
     * @brief askPosition demande a l'utilisateur une position
     * @return retourne une position
     */
    Position askPosition();

    /**
     * @brief displayPiece permet de mettre une pièce du jeu et return le symbole.
     * @param piece une pièce du jeu
     * @return retourne le symbole de la pièce pour l'affichage
     */
    string displayPiece(const Piece *piece);

    /**
     * @brief askDirection demande a l'utilisateur une Direction
     * @return retourne une Direction
     */
    Direction askDirection();

    /**
     * @brief askSteps demande le nombre de pas
     * @return  retourne le nombre de pas souhaiter
     */
    int askSteps();//mettre un nombre max? ex: 100 max?
    /**
     * @brief displayPlayer affiche le joueur courant
     */
    void displayPlayer();

    /**
     * @brief displayWinner Affiche le gagnant
     */
    void displayWinner();

    /**
     * @brief askBuild demande a l'utilisateur si il veut utiliser
     * le build fournie par defaut ou non.
     * @return retourne un string a ou b
     */
    string askBuild();
};

inline View::View(const Game *game){
    this->game=game;
}

inline void View::displayWelcome(){
    cout<<"             ~~~~ welcome to Stratego ~~~~        \n "<<endl;
    cout<<"Author:Younes Oudahya 54314, Mohamed El Kaoui 55960\n"<<endl;
}



inline char View::displayLetters(int a){
    switch (a) {
    case 0:
        return 'A';
        break;
    case 1:
        return 'B';
        break;
    case 2:
        return 'C';
        break;
    case 3:
        return 'D';
        break;
    case 4:
        return 'E';
        break;
    case 5:
        return 'F';
        break;
    case 6:
        return 'G';
        break;
    case 7:
        return 'H';
        break;
    case 8:
        return 'I';
        break;
    case 9:
        return 'J';
        break;
    }
    return '?';
}

inline int View::displayInteger(char letter){
    switch (letter) {
    case 'A':
        return 0;
        break;
    case 'B':
        return 1;
        break;
    case 'C':
        return 2;
        break;
    case 'D':
        return 3;
        break;
    case 'E':
        return 4;
        break;
    case 'F':
        return 5;
        break;
    case 'G':
        return 6;
        break;
    case 'H':
        return 7;
        break;
    case 'I':
        return 8;
        break;
    case 'J':
        return 9;
        break;
    }
    return -1;
}

inline string View::displayPiece(const Piece* piece){

    switch (piece->getSymbol()) {
    case 0:
        return "D";
        break;
    case 1:
        return "1";
        break;
    case 2:
        return "2";
        break;
    case 3:
        return "3";
        break;
    case 4:
        return "4";
        break;
    case 5:
        return "5";
        break;
    case 6:
        return "6";
        break;
    case 7:
        return "7";
        break;
    case 8:
        return "8";
        break;
    case 9:
        return "9";
        break;
    case 10:
        return "10";
        break;
    case 11:
        return "B";
        break;
    }
    return "unknow";
}

inline void View::displayGame(){

    cout<<"    ";
    for(size_t a=0;a<10;a++){
        cout<<displayLetters(a)<<"   ";
    }
    cout<<"\n";
    cout<<"  ";
    for(size_t a=0;a<10;a++){
        cout<<"----";
    }
    cout<<"\n";

    if(this->game->getCurrentPlayer().getPColor() == PlayerColor::RED){
        for(size_t i=0;i<10;i++){
            if(i != 9){
                cout<<" ";
            }
            cout<<i+1<<"|";
            for(size_t j=0;j<10;j++){
                displayBoard(i,j);
            }
            cout<<" "<< i+1;
            cout<<"\n";
            cout<<"  ";
            for(size_t a=0;a<10;a++){
                cout<<"----";
            }
            cout<<"\n";
        }
    }else{
        for(int i=9;i>=0;i--){

            if(i != 9){
                cout<<" ";
            }
            cout<<i+1<<"|";
            for(int j=0;j<10;j++){
                displayBoard(i,j);
            }
            cout<<" "<< i+1;
            cout<<"\n";

            cout<<"  ";
            for(size_t a=0;a<10;a++){
                cout<<"----";
            }
            cout<<"\n";
        }
    }


    cout<<"   ";
    for(size_t a=0;a<10;a++){
        cout<<displayLetters(a)<<"   ";
    }
    cout<<"\n";
}


inline void View::displayBoard(int i , int j){

    if(this->game->getBoard().getSquare(Position(i,j)).getType() == SquareType::LAND){

        if(this->game->getBoard().getPiece(Position(i,j)) == nullptr){
            cout<<"  | ";
        }else{
            if(this->game->getBoard().getPiece(Position(i,j))->getColorPiece() == PlayerColor::BLUE){

                if(this->game->getBoard().getPiece(Position(i,j))->getVisible() || this->game->getCurrentPlayer().getPColor() == PlayerColor::BLUE){
                    cout<<displayPiece(this->game->getBoard().getPiece(Position(i,j)));
                }else{
                    if(displayPiece(this->game->getBoard().getPiece(Position(i,j))) == "10"){
                        cout<<"* ";
                    }else{
                        cout<<"*";
                    }
                }
                if(displayPiece(this->game->getBoard().getPiece(Position(i,j))) == "10"){
                    cout<<"| ";
                }else{
                    cout<<" | ";
                }

            }else{
                if(this->game->getBoard().getPiece(Position(i,j))->getVisible() || this->game->getCurrentPlayer().getPColor() == PlayerColor::RED){
                    cout<<displayPiece(this->game->getBoard().getPiece(Position(i,j)));
                }else{
                    if(displayPiece(this->game->getBoard().getPiece(Position(i,j))) == "10"){
                        cout<<"* ";
                    }else{
                        cout<<"*";
                    }

                }
                if(displayPiece(this->game->getBoard().getPiece(Position(i,j))) == "10"){
                    cout<<"| ";
                }else{
                    cout<<" | ";
                }
            }
        }

    }else{
        cout<<"X";
        cout<<" | ";
    }

}



Position View::askPosition(){
    int x;
    char letter;
    cout<<"inserer la ligne(1-10):\n";
    cin>>x;
    while(cin.fail()){
        cin.clear();
        cin.ignore(INT_MAX,'\n');
        cout<<"erreur, veuillez reinserer la ligne:";
        cin >> x;
    }
    cout<<"inserer la colonne: (lettre) ";
    cin>>letter;
    while(toupper(letter) != 'A' && toupper(letter) != 'B' && toupper(letter) != 'C' && toupper(letter) != 'D' && toupper(letter) != 'E' &&
          toupper(letter) != 'F' && toupper(letter) != 'G' && toupper(letter) != 'H' && toupper(letter) != 'I' && toupper(letter) != 'J'){
        cout<<"\nerreur, veuillez reinserer la colonne: (lettre) ";
        cin >> letter;
    }
    cout<<"\n";
    x--;
    int y = displayInteger(toupper(letter));

    while(!this->game->gameIsInside(Position(x,y)) || this->game->gameGetPiece(Position(x,y)) == nullptr){
        cout<<"la position inseree n'est pas valide veuillez inserer une nouvelle position\n";
        cout<<"inserer la ligne(1-10):";
        cin>>x;
        while(cin.fail()){
            cin.clear();
            cin.ignore(INT_MAX,'\n');
            cout<<"\nerreur, veuillez reinserer la ligne:";
            cin >> x;
        }
        cout<<"\ninserer la colonne: (lettre)";
        cin>>letter;
        while(toupper(letter) != 'A' && toupper(letter) != 'B' && toupper(letter) != 'C' && toupper(letter) != 'D' && toupper(letter) != 'E' &&
              toupper(letter) != 'F' && toupper(letter) != 'G' && toupper(letter) != 'H' && toupper(letter) != 'I' && toupper(letter) != 'J'){
            cout<<"\nerreur, veuillez reinserer la colonne: (lettre) ";
            cin >> letter;
        }
        x--;
        y = displayInteger(toupper(letter));
    }

    return Position(x,y);
}

inline Direction View::askDirection(){
    Direction dir=NONE;
    cout<<"veuillez inserer une direction (north south,west,east)\n";
    string direction;
    cin>>direction;
    while(!sameString(direction,"north") && !sameString(direction,"south") &&
          !sameString(direction,"west") && !sameString(direction,"east")){
        cout<<"\nerreur valeur\n";
        cout<<"veuillez inserer une nouvelle direction (north south,west,east)\n";
        cin>>direction;
    }

    if(sameString(direction,"north")){
        if(this->game->getCurrentPlayer().getPColor() == BLUE){
            return dir=SOUTH;
        }else{
            return dir=NORTH;
        }
    }else if(sameString(direction,"south")){
        if(this->game->getCurrentPlayer().getPColor() == BLUE){
            return dir=NORTH;
        }else{
            return dir=SOUTH;
        }
    }else if(sameString(direction,"west")){
        return dir=WEST;
    }else if(sameString(direction,"east")){
        return dir=EAST;
    }
    return dir;
}





inline int View::askSteps(){
    int nbSteps;
    cout<<"inserer le nombre de pas souhaite:\n";
    cin>>nbSteps;
    while(cin.fail()){
        cin.clear();
        cin.ignore(INT_MAX,'\n');
        cout<<"erreur, veuillez reinserer le nombre de pas souhaité:";
        cin >> nbSteps;
    }
    return nbSteps;
}

inline void View::displayPlayer(){
    if(this->game->getCurrentPlayer().getPColor() == PlayerColor::BLUE){
        cout<<"Joueur courant: BLEU"<<endl;
    }else{
        cout<<"Joueur courant: ROUGE"<<endl;
    }

}

inline void View::displayWinner(){
    cout<<"\nFelicitations ! Le Gagnant est:";
    if(this->game->getWinner()==RED){
        cout<<" joueur ROUGE "<<endl;
        cout<<"L'autre joueur retourne a la cuisine , la guerre c'est pas fait pour toi"<<endl;
    }else{
        cout<<" joueur BLEU "<<endl;
        cout<<"L'autre joueur retourne a la cuisine , la guerre c'est pas fait pour toi"<<endl;
    }

}


inline string View::askBuild()
{
    string askInit;
    cout<<"Souhaitez vous utiliser un build(a) fourni ou un build par defaut(b) ?";
    cin>>askInit;
    while(askInit!="a"&& askInit!="b"){
        cin.clear();
        cout<<"Erreur"<<endl;
        cout<<"Souhaitez vous utiliser un build(a) fourni ou un build par defaut(b) ?";
        cin>>askInit;
    }
    return askInit;
}


#endif // VIEW_H

