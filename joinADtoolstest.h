#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_joinADtoolstest.h"

class joinADtoolstest : public QMainWindow
{
    Q_OBJECT

public:
    joinADtoolstest(QWidget *parent = nullptr);
    ~joinADtoolstest();
    QString adadrrs = "hf.huafangtec.cn";
    QString aduser = "lilei-hj";
    QString adpsw = "woshililei4613@";


public slots:

    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();

private:
    Ui::joinADtoolstestClass ui;
};
