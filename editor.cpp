#include "editor.h"
#include "ui_editor.h"

Editor::Editor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Editor)
{
    ui->setupUi(this);
    QTextEdit *pte = new QTextEdit();
    ui->tabWidget->addTab(pte,"New");
}

Editor::~Editor()
{
    delete ui;
}

void Editor::on_actionAbrir_triggered()
{
    QString fname = QFileDialog::getOpenFileName();
        if ( QFile::exists(fname) ) {
            QFile file(fname);

            if ( file.open(QFile::ReadOnly) ) {
                QTextStream stream(&file);
                QString line;
                QTextEdit *textOpen = new QTextEdit();
                int linha = 0;
                while ( !stream.atEnd() ) {
                    line = stream.readLine();
                    linha++;
                    if(linha>4){
                        textOpen->append(line);
                    }
                }
                ui->tabWidget->addTab(textOpen,fname);
                ui->tabWidget->setCurrentIndex(tab++);
                file.close();
            }
        }
}

void Editor::on_actionSair_triggered()
{
    exit(0);
}

void Editor::on_actionSalvar_triggered()
{
    QString fnome = ui->tabWidget->tabBar()->tabText(ui->tabWidget->currentIndex());
    if (QFile::exists(fnome)){
        QFile file(fnome);
        if(file.open(QIODevice::WriteOnly)){

        QTextStream out(&file);
        QTextEdit *plainText = (QTextEdit*)ui->tabWidget->currentWidget();
        out << plainText->toHtml();

        file.flush();
        file.close();
        }
    }else{
        on_actionSavar_como_triggered();
    }

}

void Editor::on_actionSavar_como_triggered()
{
    QString fnome = QFileDialog::getSaveFileName();
    if(!fnome.isEmpty()){
        ui->tabWidget->setTabText(ui->tabWidget->currentIndex(),fnome);
        QFile file(fnome);
        if(file.open(QIODevice::WriteOnly)){

        QTextStream out(&file);
        QTextEdit *plainText = (QTextEdit*)ui->tabWidget->currentWidget();
        out << plainText->toHtml();

        file.flush();
        file.close();
        }
    }
}

void Editor::on_actionNovo_triggered()
{
    QTextEdit *pte = new QTextEdit();
    ui->tabWidget->addTab(pte,"New "+ QString::number(tab++));

}

void Editor::on_actionCopia_triggered()
{
    QTextEdit *plainText = (QTextEdit*)ui->tabWidget->currentWidget();
    plainText->copy();
}

void Editor::on_actionUndo_triggered()
{
    QTextEdit *plainText = (QTextEdit*)ui->tabWidget->currentWidget();
    plainText->undo();
}

void Editor::on_actionRedo_triggered()
{
    QTextEdit *plainText = (QTextEdit*)ui->tabWidget->currentWidget();
    plainText->redo();
}

void Editor::on_actionCola_triggered()
{
    QTextEdit *plainText = (QTextEdit*)ui->tabWidget->currentWidget();
    plainText->paste();
}

void Editor::on_actionRecorta_triggered()
{
    QTextEdit *plainText = (QTextEdit*)ui->tabWidget->currentWidget();
    plainText->cut();
}
void Editor::on_action_Italico_triggered()
{
    QTextEdit *plainText = (QTextEdit*)ui->tabWidget->currentWidget();
    QTextCharFormat format = plainText->textCursor().charFormat();
    QFont font = format.font();
    bool isItalic =  font.italic();
    qDebug() << isItalic;

    if(!isItalic){
        font.setItalic(true);
    }else{
        font.setItalic(false);
    }

    format.setFont(font);
    plainText->textCursor().mergeCharFormat(format);
}


void Editor::on_action_Negrito_triggered()
{
   QTextEdit *plainText = (QTextEdit*)ui->tabWidget->currentWidget();
   QTextCharFormat format = plainText->textCursor().charFormat();
   QFont font = format.font();
   bool isbold =  font.bold();
   qDebug() << isbold;

   if(!isbold){
       plainText->setFontWeight(QFont::Bold);
   }else{
       plainText->setFontWeight(QFont::Normal);
//       font.setWeight(QFont::Normal);
   }

//   format.setFont(font);
//   plainText->textCursor().mergeCharFormat(format);
}
