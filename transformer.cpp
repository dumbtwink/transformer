#include "transformer.h"
#include "./ui_transformer.h"
#include <iostream>
#include <string>
#include <QtDebug>

transformer::transformer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::transformer)
{
    ui->setupUi(this);
}

transformer::~transformer()
{
    delete ui;
}


void transformer::on_encryptButton_clicked()
{
   QString qmagicPhrase = ui->magicWord->text();
   QString qinput = ui->textInput->toPlainText();
   std::string magicPhrase = qmagicPhrase.toStdString();
   std::string input = qinput.toStdString();
   std::string output;
   for(int i=0; i<input.length(); i++){
        int cycle = i % magicPhrase.length();
        int factor = (int)magicPhrase[cycle];
        int key = (int)input[i];
        output.append(std::to_string(factor*key));
        output.append(";");
    }
   ui->textOutput->setText(QString::fromStdString(output));
}


void transformer::on_decryptButton_clicked()
{
    QString qmagicPhrase = ui->magicWord->text();
    QString qinput = ui->textInput->toPlainText();
    std::string magicPhrase = qmagicPhrase.toStdString();
    std::string input = qinput.toStdString();
    std::string output;
    int buffer = 0;
    int cursor = 0;
    for(int i=0; i<input.length(); i++){
        if((int)input.at(i)!=59){
            buffer*=10;
            buffer=buffer + ((int)input.at(i)-48);
        } else {
            int factor = (int)magicPhrase[cursor % magicPhrase.length()];
            cursor++;
            buffer/=factor;
            char c = (char)buffer;
            output.push_back(c);
            buffer = 0;
        }
    }
    ui->textOutput->setText(QString::fromStdString(output));
}

