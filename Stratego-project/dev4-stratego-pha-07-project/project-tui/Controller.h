#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <fstream>
#include <iostream>
#include <Game.h>
#include "View.h"


/**
 * @brief The Controller class permet de contrôler le jeu
 */
class Controller{
private:
    Game *game;
    View *view;

    /**
     * @brief getGameInitialization
     * @param url c'est l'url dossier (path)
     * @return renvoie les mots du fichier .txt
     */
    std::vector<string> getGameInitialization(string url);
public:
    Controller()=default;

    /**
     * @brief Controller controller qui reçois la vue et le game en paramètre afin de lancer le jeu
     * @param game structure du jeu
     * @param view affichage du jeu
     */
    Controller(Game *game, View *view);

    /**
     * @brief start permet d'initialiser le jeu en mettant les pieces du fichier .txt dans le tableau
     * @param url1 c'est l'url dossier (path)
     * @param url2 c'est l'url dossier (path)
     */
    void start(string url1,string url2);

    /**
     * @brief startGame lance le jeu
     */
    void startGame();
};

inline Controller::Controller(Game *game,View *view)
{
    this->game=game;
    this->view=view;

}

inline std::vector<string> Controller::getGameInitialization(string url)
{
    std::vector<string> listUrl;
    ifstream file;
    file.open(url);
    if (!file.is_open()){
        cout<<"unable to open file";
    }
    else{
        string word;
        while (file >> word){
            listUrl.push_back(word);
        }
    }
    return listUrl;

}
inline void Controller::start(string url1,string url2)
{
    this->game->start(getGameInitialization(url1),getGameInitialization(url2));;
}

inline void Controller::startGame()
{
    string url1="../../../Stratego-project/dev4-stratego-pha-07-project/RessourcesGame/playerR.txt";
    string url2="../../../Stratego-project/dev4-stratego-pha-07-project/RessourcesGame/playerB.txt";
    bool gameNotFinished= true;
    string askInit=view->askBuild();
    if(this->game->getState()==NOT_STARTED ){
        if(askInit=="a"){
            this->start(url1,url2);
        }else if(askInit=="b"){
            this->game->start();
        }
        this->view->displayWelcome();
        this->view->displayGame();
        this->view->displayPlayer();
    }
    while(this->game->endGame() && gameNotFinished){
        if(this->game->getState()==CHOOSE_PIECE && this->game->getTurnEnd(this->game->getCurrentPlayer().getPColor())==false){
            Position askPosition = this->view->askPosition();
            Direction askDirection= this->view->askDirection();
            int nbSteps=1;
            if(this->game->getPiece(askPosition)->isEclaireur()){
                nbSteps=this->view->askSteps();
            }
            cout<<nbSteps<<endl;
            this->game->move(askPosition,askDirection,nbSteps);
        }
        if(this->game->getState()==MOVE_PIECE){
            if(this->game->endGame()){
                this->game->swapPlayer();
                this->view->displayGame();
                this->view->displayPlayer();
            }
        }
    }
    if(this->game->getState()==END_GAME){
        this->view->displayGame();
        this->view->displayWinner();

    }

}


#endif // CONTROLLER_H




