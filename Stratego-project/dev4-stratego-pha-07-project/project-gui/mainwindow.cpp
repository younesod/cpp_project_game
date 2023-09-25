#include "mainwindow.h"
#include "ui_mainwindow.h"



using namespace std;

MainWindow::MainWindow(Game * game,ViewGUI *view,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->view=view;
    this->game=game;
    game->addObserver(this);
    MainWindow::update(NOT_STARTED);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_playButton_clicked()
{
    this->game->startGame();
    size_t iDeck=0;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            bool put=false;
            while(!put && iDeck<game->getDeckPieces().size()){
                if(!game->getDeckPieces().at(i).getIsPut()){
                    int symbol=game->getDeckPieces().at(iDeck).getSymbol();
                    QString symbolString=QString::number(symbol);
                    if(symbol==0) symbolString="D";
                    if(symbol==11) symbolString="B";
                    QPushButton *piece= new QPushButton(symbolString,this);
                    QString style;
                    if(game->getCurrentPlayer().getPColor()==RED)style="background-color:crimson;padding:10;color:white;";
                    else style="background-color:#318CE7;padding:10px;color:white;";
                    piece->setStyleSheet(style);
                    connect(piece,&QPushButton::clicked,this,&MainWindow::onPieceClicked);
                    ui->gridLayoutPieces->addWidget(piece,i,j);
                    put=true;
                    iDeck++;
                }
            }
            if(game->getBoard().getSquare(Position(i,j)).getType()==LAND){
                QPushButton *btn = new QPushButton(this);
                ui->gridLayout->addWidget(btn,i,j);
                view->changeStyleSquare(LAND,Position(i,j),this->getUi());
                connect(btn,&QPushButton::clicked,this,&MainWindow::onPieceBoardClicked);

            }
            else if(game->getBoard().getSquare(Position(i,j)).getType()==WATER){
                QLabel *layout = new QLabel(this);
                ui->gridLayout->addWidget(layout,i,j);
                view->changeStyleSquare(WATER,Position(i,j),this->getUi());
            }
        }
    }
    ui->label_9->setText("Your pieces");
    ui->label_9->setStyleSheet("color:green;font-family: Times New Roman;font-size: 15px;");
    ui->playButton->setDisabled(true);
    view->btn_play_disableStyle(this->getUi());
    ui->defaultGame->setDisabled(false);
    view->btn_default_Style(this->getUi());
}



void MainWindow::on_surrenderButton_clicked()
{
    QMessageBox::about(this,"Surend","you have surrended");
    game->removeFlag();
    game->endGame();
    ui->defaultGame->setDisabled(true);
    view->btn_default_disableStyle(this->getUi());

}


void MainWindow::on_quitButton_clicked()
{
    QMessageBox::StandardButton reply= QMessageBox::question(this,"Quit","Do you really want to quit ?",QMessageBox::Yes | QMessageBox::No);
    if(reply==QMessageBox::Yes){
        QApplication::quit();
    }else{
        qDebug()<<"Continue the game";
    }
}

void MainWindow::on_endPlacement_clicked()
{
    if(this->game->endPlacementPlayer()){
        if(this->game->endPlacement()){
            ui->defaultGame->setDisabled(true);
            view->btn_default_disableStyle(this->getUi());
            ui->endPlacement->setDisabled(true);
            view->btn_enPlacement_disableStyle(this->getUi());
            ui->surrenderButton->setDisabled(false);
            view->btn_surrender_Style(this->getUi());
            QMessageBox::about(this,"START","HAJIME");
            ui->label_9->setText("");
            ui->label_txt->setText("current player: ");
            this->connectPieceOnBoard();
        }
        else{
            QMessageBox::about(this,"Placement End","Next player : place your soldiers");

            if ( ui->gridLayoutPieces->layout() != NULL )
            {
                QLayoutItem* item;
                while ( ( item = ui->gridLayoutPieces->layout()->takeAt( 0 ) ) != NULL )
                {
                    delete item->widget();
                    delete item;
                }
            }
            this->view->updatePieceOnBoard(this->getUi());
            this->updateDeck();
        }
    }
    else{
        QMessageBox box ;
        box.warning(this,"Pas Op"," Place all your tiles");
    }

}

void MainWindow::onPieceClicked()
{
    ui->defaultGame->setDisabled(true);
    view->btn_default_disableStyle(this->getUi());
    QPushButton *button=(QPushButton*) sender();
    QString str=button->text();
    this->pieceChoosed=str.toStdString();
}

Pos MainWindow::gridPosition(QWidget *widget)
{
    if(!widget->parentWidget()) return{};
    auto layout= qobject_cast<QGridLayout*>(widget->parentWidget()->layout());
    if(!layout) return{};
    int i= layout->indexOf(widget);
    Q_ASSERT(i>=0);
    int _;
    Pos pos;
    layout->getItemPosition(i,&pos.row,&pos.col,&_,&_);
    return pos;
}


int MainWindow::getNbSteps(const Position &start, const Position &end)
{
    int rowC=start.getRow()-end.getRow();
    int colC=start.getColumn()-end.getColumn();
    int nbSteps=0;
    if(rowC!=0 && colC!=0){
        cout<<"erreur"<<endl;
       return 0;

    }
    else{
        if(game->getPiece(start)->getTypeMove()==INFINITE){
            if(rowC==0){
                nbSteps=colC;
            }
            else if(colC==0){
                nbSteps=rowC;
            }
        }
        else if(game->getPiece(start)->getTypeMove()==NORMAL){
            nbSteps=1;
        }
    }
    return nbSteps;
}
Direction MainWindow::getDirection(const Position &start, const Position& end)
{
    Direction dir=NONE;
    int rowC=start.getRow()-end.getRow();
    int colC=start.getColumn()-end.getColumn();
    if(rowC!=0 && colC!=0){
        return dir;
    }
    else{
        if(game->getPiece(start)->getTypeMove()==NORMAL){
            if(rowC==0){
                switch(colC){
                case -1:
                    dir=EAST;
                    break;
                case 1:
                    dir=WEST;
                    break;
                }
            }
            else if(colC==0){
                switch(rowC){
                case -1:
                    dir=SOUTH;
                    break;
                case 1:
                    dir=NORTH;
                    break;
                }
            }
        }
        else if(game->getPiece(start)->getTypeMove()==INFINITE){
            int position,nbSteps=getNbSteps(start,end);
            if(nbSteps<0) nbSteps*=-1;
            if(rowC==0){
                position=colC-nbSteps;
                if(position<0) dir=EAST ;
                else if(position==0) dir=WEST;
            }
            else if(colC==0){
                position=rowC-nbSteps;
                if(position<0) dir=SOUTH;
                else if(position==0) dir=NORTH;
            }
        }
    }
    return dir;
}

void MainWindow::onPieceBoardClicked()
{
    if(this->pieceChoosed.size()!=0){
        QPushButton *button=(QPushButton*) sender();
        Pos position= gridPosition(button);
        Position pos(position.row,position.col);
        if(this->game->canBePlaced(pos)){
            QString symbolString=QString::fromStdString(pieceChoosed);
            if(pieceChoosed=="D") symbolString="0";
            if(pieceChoosed=="B") symbolString="11";
            button->setText(QString::fromStdString(pieceChoosed));
            this->view->updateButton(button);
            int symbol=stoi(symbolString.toStdString());
            this->game->placePiece(pos,symbol);
        }
        view->updateDeck(this->getUi());
        updateDeck();
        this->pieceChoosed.clear();

    }

}


void MainWindow::updateDeck(){
    size_t iDeck=0;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            bool put=false;
            while(!put && iDeck<this->game->getDeckPieces().size()){
                if(!game->getDeckPieces().at(iDeck).getIsPut()){
                    int symbol=this->game->getDeckPieces().at(iDeck).getSymbol();
                    QString symbolString=QString::number(symbol);
                    if(symbol==0) symbolString="D";
                    if(symbol==11) symbolString="B";
                    QPushButton *piece= new QPushButton(symbolString,this);
                    QString style;
                    if(game->getCurrentPlayer().getPColor()==RED)style="background-color:crimson;padding:10;color:white;";
                    else style="background-color:#318CE7;padding:10;color:white;";
                    piece->setStyleSheet(style);
                    connect(piece,&QPushButton::clicked,this,&MainWindow::onPieceClicked);

                    ui->gridLayoutPieces->addWidget(piece,i,j);
                    put=true;
                }
                iDeck++;

            }

        }
    }
}



void MainWindow::moveSoldier()
{
    QPushButton *button=(QPushButton*) sender();
    this->pieceChoosed=button->text().toStdString();
    if(pieceChoosed=="D") pieceChoosed="0";
    if(pieceChoosed=="B") pieceChoosed="11";
    Pos position= gridPosition(button);
    Position pos(position.row,position.col);
    if(this->game->getBoard().isMyPiece(pos,this->game->getCurrentPlayer().getPColor())){
        this->positionStart=pos;
        positionEnd=Position(-1,-1);
    }
    else{
        this->positionEnd=pos;
    }
    if(this->game->getBoard().isInside(positionStart) && this->game->getBoard().isInside(positionEnd) && this->game->getBoard().getSquare(positionEnd).getType()!=WATER){
        Direction dir=getDirection(positionStart,positionEnd);
        int steps= getNbSteps(positionStart,positionEnd);
        if(steps<0) steps*=-1;
        this->game->move(positionStart,dir,steps);
        view->updatePieceOnBoard(this->getUi());
        positionStart=Position(-1,-1);
        positionEnd=Position(-1,-1);
        pieceChoosed.clear();
        if(this->game->getTurnEnd(game->getCurrentPlayer().getPColor()) && this->game->getState()!=END_GAME){
            this->game->swapPlayer();
            view->updatePieceOnBoard(this->getUi());
        }
    }

}


Ui::MainWindow *MainWindow::getUi() const
{
    return ui;
}

void MainWindow::update(State state){
    if(state == State::END_GAME){
        QMessageBox *msgWinner = new QMessageBox(this);
        if(game->getWinner() == BLUE ){
            disconnectAllPiece();
            msgWinner->setText("Winner of the game");
            msgWinner->setInformativeText("PLAYER BLUE");
            msgWinner->setStyleSheet("background-color:#f5f5dc;text-align: center;color:blue;font-weight: bold;font-family: serif;font-size:20px;");
            msgWinner->exec();


        }else if(game->getWinner() == RED){
            disconnectAllPiece();
            msgWinner->setText("Winner of the game");
            msgWinner->setInformativeText("PLAYER RED");
            msgWinner->setStyleSheet("background-color:#f5f5dc;text-align: center;color:red;font-weight: bold;font-family: serif;font-size:20px;");
            msgWinner->exec();
        }
    }else if(state == State::INITIALIZED){
        ui->surrenderButton->setDisabled(true);
        view->btn_surrender_disableStyle(this->getUi());
        ui->endPlacement->setDisabled(false);
        view->btn_enPlacement_Style(this->getUi());
    }else if(state == State::NOT_STARTED){
        view->btn_play_Style(this->getUi());
        view->btn_quit_Style(this->getUi());
        view->btn_enPlacement_disableStyle(this->getUi());
        view->btn_surrender_disableStyle(this->getUi());
        view->btn_default_disableStyle(this->getUi());
    }else if(state == State::CHOOSE_PIECE){
        view->currentPlayer(this->getUi());
        game->endGame();
    }else if(state == State::MOVE_PIECE){
        game->endGame();
    }




}


void MainWindow::on_defaultGame_clicked()
{
    game->emptyBoard();
    //red
    game->placePiece(Position(6,0),11);
    game->placePiece(Position(6,1),11);
    game->placePiece(Position(6,2),11);
    game->placePiece(Position(6,3),3);
    game->placePiece(Position(6,4),0);
    game->placePiece(Position(6,5),5);
    game->placePiece(Position(6,6),2);
    game->placePiece(Position(6,7),11);
    game->placePiece(Position(6,8),11);
    game->placePiece(Position(6,9),11);

    game->placePiece(Position(7,0),1);
    game->placePiece(Position(7,1),5);
    game->placePiece(Position(7,2),4);
    game->placePiece(Position(7,3),4);
    game->placePiece(Position(7,4),6);
    game->placePiece(Position(7,5),6);
    game->placePiece(Position(7,6),4);
    game->placePiece(Position(7,7),4);
    game->placePiece(Position(7,8),5);
    game->placePiece(Position(7,9),5);

    game->placePiece(Position(8,0),2);
    game->placePiece(Position(8,1),2);
    game->placePiece(Position(8,2),2);
    game->placePiece(Position(8,3),3);
    game->placePiece(Position(8,4),3);
    game->placePiece(Position(8,5),3);
    game->placePiece(Position(8,6),3);
    game->placePiece(Position(8,7),2);
    game->placePiece(Position(8,8),2);
    game->placePiece(Position(8,9),2);

    game->placePiece(Position(9,0),10);
    game->placePiece(Position(9,1),9);
    game->placePiece(Position(9,2),2);
    game->placePiece(Position(9,3),6);
    game->placePiece(Position(9,4),6);
    game->placePiece(Position(9,5),7);
    game->placePiece(Position(9,6),7);
    game->placePiece(Position(9,7),7);
    game->placePiece(Position(9,8),8);
    game->placePiece(Position(9,9),8);
    //blue
    game->switchPlayer();
    game->placePiece(Position(0,0),11);
    game->placePiece(Position(0,1),11);
    game->placePiece(Position(0,2),11);
    game->placePiece(Position(0,3),2);
    game->placePiece(Position(0,4),3);
    game->placePiece(Position(0,5),5);
    game->placePiece(Position(0,6),2);
    game->placePiece(Position(0,7),11);
    game->placePiece(Position(0,8),11);
    game->placePiece(Position(0,9),11);

    game->placePiece(Position(1,0),1);
    game->placePiece(Position(1,1),5);
    game->placePiece(Position(1,2),4);
    game->placePiece(Position(1,3),4);
    game->placePiece(Position(1,4),6);
    game->placePiece(Position(1,5),6);
    game->placePiece(Position(1,6),4);
    game->placePiece(Position(1,7),4);
    game->placePiece(Position(1,8),5);
    game->placePiece(Position(1,9),5);

    game->placePiece(Position(2,0),2);
    game->placePiece(Position(2,1),2);
    game->placePiece(Position(2,2),2);
    game->placePiece(Position(2,3),3);
    game->placePiece(Position(2,4),3);
    game->placePiece(Position(2,5),3);
    game->placePiece(Position(2,6),3);
    game->placePiece(Position(2,7),2);
    game->placePiece(Position(2,8),2);
    game->placePiece(Position(2,9),2);

    game->placePiece(Position(3,0),10);
    game->placePiece(Position(3,1),9);
    game->placePiece(Position(3,2),6);
    game->placePiece(Position(3,3),6);
    game->placePiece(Position(3,4),0);
    game->placePiece(Position(3,5),7);
    game->placePiece(Position(3,6),7);
    game->placePiece(Position(3,7),7);
    game->placePiece(Position(3,8),8);
    game->placePiece(Position(3,9),8);
    game->switchPlayer();
    this->connectPieceOnBoard();
    if(this->game->endPlacement()){ // si les deux ont fini
        ui->endPlacement->setDisabled(true);
        view->btn_enPlacement_disableStyle(this->getUi());
        ui->surrenderButton->setDisabled(false);
        view->btn_surrender_Style(this->getUi());

        QMessageBox::about(this,"START","HAJIME");
        ui->label_9->setText("");
        ui->label_txt->setText("current player: ");
        this->connectPieceOnBoard();
        ui->defaultGame->setDisabled(true);
        view->btn_default_disableStyle(this->getUi());
        view->updateDeck(this->getUi());
        view->updatePieceOnBoard(this->getUi());
    }
}
void MainWindow::connectPieceOnBoard()
{

    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(game->getBoard().getSquare(Position(i,j)).getType()==LAND){
                QLayoutItem *item = ui->gridLayout->itemAtPosition(i,j);
                QPushButton *btn= qobject_cast<QPushButton*>(item->widget());
                btn->disconnect();
                ui->gridLayout->addWidget(btn,i,j);
                view->buttonVisibility(btn,i,j);
                connect(btn,&QPushButton::clicked,this,&MainWindow::moveSoldier);
            }
        }
    }
}

void MainWindow::disconnectAllPiece(){
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(game->getBoard().getSquare(Position(i,j)).getType()==LAND){
                QLayoutItem *item = ui->gridLayout->itemAtPosition(i,j);
                QPushButton *btn= qobject_cast<QPushButton*>(item->widget());
                btn->disconnect();
                btn->setDisabled(true);

            }
        }
    }
    ui->defaultGame->setDisabled(true);
    view->btn_default_disableStyle(this->getUi());
    ui->endPlacement->setDisabled(true);
    view->btn_enPlacement_disableStyle(this->getUi());
    ui->surrenderButton->setDisabled(true);
    view->btn_surrender_disableStyle(this->getUi());
    view->currentWinner(this->getUi());
}

