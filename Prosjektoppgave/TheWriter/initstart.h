#ifndef INITSTART_H
#define INITSTART_H

#include <QObject>
#include "view/inputpopup.h"
#include "startup.h"
#include "view/loadgamepopup.h"
class InitStart : public QObject
{
    Q_OBJECT
public:
    explicit InitStart(QObject *parent = 0);
    ~InitStart();
    void start();
private:
    LoadGamePopUp * loadGameWin;
    InputPopUp *newGameWin;
    Startup *w;
signals:

public slots:

private slots:
    void newGame();
    void loadFiles();
    void loadGame();
    void initNewGame();
};

#endif // INITSTART_H
