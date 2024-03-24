#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    connect(ui->radioButton__black, SIGNAL(clicked()), this, SLOT(do_setFontColor()));
    connect(ui->radioButton_blue, SIGNAL(clicked()), this, SLOT(do_setFontColor()));
    connect(ui->radioButton_red, SIGNAL(clicked()), this, SLOT(do_setFontColor()));
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_checkBox_underLine_clicked(bool checked)
{//下划线
    QFont font = ui->plainTextEdit->font();
    font.setUnderline(checked);
    ui->plainTextEdit->setFont(font);
}


void Dialog::on_checkBox_italic_clicked(bool checked)
{//斜体

    QFont font = ui->plainTextEdit->font();
    font.setItalic(checked);
    ui->plainTextEdit->setFont(font);
}


void Dialog::on_checkBox_blod_clicked(bool checked)
{//加粗
    QFont font = ui->plainTextEdit->font();
    font.setBold(checked);
    ui->plainTextEdit->setFont(font);
}


void Dialog::on_pushButton_clear_clicked()
{//清空
    ui->plainTextEdit->clear();
}

void Dialog::do_setFontColor()
{//自定义槽函数，设置文字颜色 需要手动关联
    QPalette plet = ui->plainTextEdit->palette();
    if (ui->radioButton__black->isChecked())
        plet.setColor(QPalette::Text, Qt::black);
    else if (ui->radioButton_blue->isChecked())
        plet.setColor(QPalette::Text, Qt::blue);
    else if (ui->radioButton_red->isChecked())
        plet.setColor(QPalette::Text, Qt::red);
    else
        plet.setColor(QPalette::Text, Qt::black);

    ui->plainTextEdit->setPalette(plet);
}

