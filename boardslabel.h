#ifndef BOARDSLABEL_H
#define BOARDSLABEL_H
#include <QLabel>
#include "Board.h"
#include "mainwindow.h"

class PostsLabel;

class BoardsLabel : public QLabel
{
public:
    BoardsLabel();
    ~BoardsLabel();
    void ConnectUi(Ui::MainWindow *ui){this->ui = ui;}
    void ConnectBoard (Board* const b) {board = b;}
    void mousePressEvent(QMouseEvent *event);   //��д������¼�

private:
    Board* board;
    vector<PostsLabel*> plabes;
    Ui::MainWindow *ui;
};

#endif // BOARDSLABEL_H
