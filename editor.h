#ifndef EDITOR_H
#define EDITOR_H

#include <QMainWindow>
#include <QFileDialog>
#include <QTextStream>
#include <iostream>
#include <QPlainTextEdit>
#include <QtDebug>

namespace Ui {
class Editor;
}

class Editor : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Editor(QWidget *parent = 0);
    ~Editor();
    
private slots:
    void on_actionAbrir_triggered();

    void on_actionSair_triggered();

    void on_actionSalvar_triggered();

    void on_actionNovo_triggered();

    void on_actionCopia_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void on_actionCola_triggered();

    void on_actionRecorta_triggered();

    void on_actionSavar_como_triggered();

    void on_action_Italico_triggered();

    void on_action_Negrito_triggered();

private:
    Ui::Editor *ui;
    QString meuArquivo;
    int tab=1;
};

#endif // EDITOR_H
