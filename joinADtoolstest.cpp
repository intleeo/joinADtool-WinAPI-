#include "joinADtoolstest.h"
#include <windows.h>
#include <lm.h>
#include <QMessageBox>
#include <iostream>
#include <QProcess>


#pragma comment(lib, "netapi32.lib")


joinADtoolstest::joinADtoolstest(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    this->setWindowFlags(Qt::WindowCloseButtonHint);//去掉最大化、最小化按钮，保留关闭按钮
}

joinADtoolstest::~joinADtoolstest()
{

}
void joinADtoolstest::on_pushButton_clicked() 
{
    NET_API_STATUS WINAPI status;
    status = NetJoinDomain(NULL, L"hf.huafangtec.cn", NULL, L"lilei-hj", L"woshililei4613@", NETSETUP_JOIN_DOMAIN | NETSETUP_ACCT_CREATE);

    if (status == NERR_Success) {
        // 函数调用成功，计算机已成功退出域
        // 创建包含成功信息的弹窗
        QMessageBox::information(this, tr("Success"), tr("Computer unjoined domain successfully!"));
    }
    else {
        // 函数调用失败，可以根据具体的错误代码进行处理
        // 创建包含失败信息和错误代码的弹窗
        QMessageBox::critical(this, tr("Error"), tr("Failed to unjoin domain. Error code: %1").arg(status));
    }
};

void joinADtoolstest::on_pushButton_2_clicked()
{
    NET_API_STATUS status;
    status = NetUnjoinDomain(NULL, L"lilei-hj", L"woshililei4613@", NETSETUP_ACCT_DELETE);

    if (status == NERR_Success) {
        // 函数调用成功，计算机已成功退出域
        // 创建包含成功信息的弹窗
        QMessageBox::information(this, tr("Success"), tr("Computer unjoined domain successfully!"));
    }
    else {
        // 函数调用失败，可以根据具体的错误代码进行处理
        // 创建包含失败信息和错误代码的弹窗
        QMessageBox::critical(this, tr("Error"), tr("Failed to unjoin domain. Error code: %1").arg(status));
    }
};

void joinADtoolstest::on_pushButton_3_clicked()
{
    if (ui.lineEdit->text() != "")
    {
        QStringList args;
        args << "localgroup" << "administrators" << ui.lineEdit->text() << "/add";

        QProcess process;
        process.start("net", args);
        process.waitForFinished();

        QString output = QString::fromLocal8Bit(process.readAllStandardOutput());
        QString error = QString::fromLocal8Bit(process.readAllStandardError());

        if (!error.isEmpty()) {
            QMessageBox::critical(this, "Error", error);
        }
        else {
            QMessageBox::information(this, "Success", output);
        }
    }
    else
    {
        QMessageBox::information(this, QString::fromLocal8Bit("Tips"), QString::fromLocal8Bit("The user name cannot be empty.(用户名不能为空!)"));//弹窗
    }
};
void joinADtoolstest::on_pushButton_4_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, QString::fromLocal8Bit("确认关机"), QString::fromLocal8Bit("您确定要重启计算机吗？"),
        QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes) {
       /* QProcess process;
        process.start("shutdown", QStringList() << "/s" << "/t" << "0");*/
        system("shutdown -r -t 0");
    }

}