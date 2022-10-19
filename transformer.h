#ifndef TRANSFORMER_H
#define TRANSFORMER_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class transformer; }
QT_END_NAMESPACE

class transformer : public QMainWindow
{
    Q_OBJECT

public:
    transformer(QWidget *parent = nullptr);
    ~transformer();

private slots:
    void on_encryptButton_clicked();

    void on_decryptButton_clicked();

private:
    Ui::transformer *ui;
};
#endif // TRANSFORMER_H
