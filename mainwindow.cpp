#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ip_url.h"
#include "ui_ip_url.h"
#include "./ocr/ocr.h"
#include <QMessageBox>

QSqlDatabase MainWindow::db = QSqlDatabase::addDatabase("QMYSQL");

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);

    ocr = new Ocr(this);
    //this->setFixedSize(922, 517);
    this->move(382, 134);

    button_url = ui->pushButton_6;
    button_video = ui->pushButton_2;
    button_photo = ui->pushButton;
    format_combo = ui->comboBox;

    // 连接数据库
    databaseConnect("localhost", 3306, "root", "123456", "iot_apply");

    //结果
    connect(ocr, SIGNAL(ocrReadyData(QString)), this, SLOT(disPlaylprResult(QString)));

    //线程 实时显示图片
    std::thread capRun(captureRun, ui->label, ui->pushButton_6);
    capRun.detach();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::captureRun(QLabel* label, QPushButton* btn) {
    int deviceID = 0;
    int apiID = cv::CAP_ANY;
    int flag = 0;
    QString temp = btn->text();

    cap.open(deviceID, apiID);
    for (;;) {

        cap.read(frame);
        cv::resize(frame, frame, Size(640, 480));

        if (temp == "Camera: Local" && flag == 0) {
            //cv::flip(frame, frame, +1);
        }

        else {
            usleep(30000);
        }

        cv::cvtColor(frame, frame, cv::COLOR_BGR2RGB);

        QPixmap pix = QPixmap::fromImage(QImage((unsigned char*)frame.data, frame.cols, frame.rows, QImage::Format_RGB888));
        label->setPixmap(pix);

        if (button_video->text() != "Video") {
            video->write(frame);
        }

        if (button_photo->text() == " ✓✓✓ ") {
            time_t now = time(0);
            char* dt = ctime(&now);

            QString dir_temp = dir + "/" + dt + format_combo->currentText();
            imwrite(qPrintable(dir_temp), frame);
        }
jumb:
        if (btn->text() == "Camera: Local" && flag == 1) {
            cap.open(deviceID, apiID);
            flag = 0;
        }

        else if (btn->text() == "Camera: Ip" && flag == 1) {
            //https://konya.sehirkameralari.com/live/5f106b8a0102b/playlist.m3u8?token=
            cap.open(qPrintable(ip_url));
            flag = 0;
        }

        if (temp != btn->text()) {
            flag = 1;
            temp = btn->text();
            goto jumb;
        }

    }

}


// photo
void MainWindow::on_pushButton_clicked() {

    if (ui->pushButton->text() != "Error") {

        if (ui->pushButton_5->text() != "Location" && ui->pushButton_5->text() != "" && ui->pushButton_5->text() != " ") {

            QImage convertedImage = ui->label->pixmap()->toImage();
            /* 车牌识别类初始化 */
            // 假设有名为"image"的 QImage 对象

            //  水平镜像图像
//            QTransform transform;
//            transform.scale(-1, 1); // 水平方向缩放为-1
//            QImage mirroredImage = convertedImage.transformed(transform);

            ocr->readyToDetection(convertedImage);

            QPixmap pix("https://images.pexels.com/photos/376723/pexels-photo-376723.jpeg?cs=srgb&dl=pexels-daniel-pixelflow-376723.jpg&fm=jpg");
            ui->label->setPixmap(pix);

            std::thread Suc(action, ui->pushButton, 1);
            Suc.detach();

        }

        else {

            std::thread Error(action, ui->pushButton, 0);
            Error.detach();
        }
    }
}

// video save
void MainWindow::on_pushButton_2_clicked() {

    if (ui->pushButton_2->text() != "Error") {

        if (ui->pushButton_2->text() == "Video") {

            if (ui->pushButton_5->text() != "Location" && ui->pushButton_5->text() != "" && ui->pushButton_5->text() != " ") {

                time_t now = time(0);
                char* dt = ctime(&now);
                QString dir_temp = dir + QString("/" + QString::fromUtf8(dt) + ui->comboBox_2->currentText());

                int fps;
                if (ui->comboBox_3->currentText() != "default FPS") {

                    QString fps_temp = ui->comboBox_3->currentText();
                    fps_temp.remove(" ");
                    fps_temp.remove("F");
                    fps_temp.remove("P");
                    fps_temp.remove("S");

                    fps = fps_temp.toInt();

                }

                else {
                    fps = (int)cap.get(cv::CAP_PROP_FPS);
                }

                int codec = cv::VideoWriter::fourcc('M', 'P', '4', 'V');
                video = new cv::VideoWriter(qPrintable(dir_temp), codec, fps, cv::Size(640, 480), true);
                ui->pushButton_2->setText("");
                std::thread count(Count, ui->pushButton_2);
                count.detach();
            }
            else {

                std::thread Error(action, ui->pushButton_2, 2);
                Error.detach();
            }
        }

        else {
            video->release();
            int i;
            for (i = 0;i < 40;i++) {
                ui->pushButton_2->setText("Video");
            }
        }
    }
}

// thema
void MainWindow::on_pushButton_3_clicked() {
    if (ui->pushButton_3->text() == "Thema: Light") {
        qApp->setStyle(QStyleFactory::create("Fusion"));
        QPalette darkPalette;

        darkPalette.setColor(QPalette::Window, QColor(53, 53, 53));
        darkPalette.setColor(QPalette::WindowText, Qt::white);
        darkPalette.setColor(QPalette::Base, QColor(25, 25, 25));
        darkPalette.setColor(QPalette::AlternateBase, QColor(53, 53, 53));
        darkPalette.setColor(QPalette::ToolTipBase, Qt::white);
        darkPalette.setColor(QPalette::ToolTipText, Qt::white);
        darkPalette.setColor(QPalette::Text, Qt::white);
        darkPalette.setColor(QPalette::Button, QColor(53, 53, 53));
        darkPalette.setColor(QPalette::ButtonText, Qt::white);
        darkPalette.setColor(QPalette::BrightText, Qt::red);
        darkPalette.setColor(QPalette::Link, QColor(42, 130, 218));
        darkPalette.setColor(QPalette::Highlight, QColor(42, 130, 218));
        darkPalette.setColor(QPalette::HighlightedText, Qt::black);
        qApp->setPalette(darkPalette);
        ui->pushButton_3->setText("Thema: Dark");
    }

    else {
        qApp->setPalette(style()->standardPalette());
        ui->pushButton_3->setText("Thema: Light");
    }
}

// path
void MainWindow::on_pushButton_5_clicked() {
    dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
        "/home",
        QFileDialog::ShowDirsOnly
        | QFileDialog::DontResolveSymlinks);

    ui->pushButton_5->setText(dir);
}

// local and ip
void MainWindow::on_pushButton_6_clicked() {
    if (ui->pushButton_6->text() == "Camera: Local") {

        Ip_url* dialog = new Ip_url(this);
        connect(dialog, SIGNAL(accepted()), this, SLOT(show()));
        connect(dialog, SIGNAL(rejected()), this, SLOT(show()));
        dialog->show();

    }

    else {
        ui->pushButton_6->setText("Camera: Local");
    }
}

// button count
void MainWindow::Count(QPushButton* button) {
    QString time;
    int hour = 0;
    int minute = 0;
    int second = 0;
    QString hour_string;
    QString minute_string;
    QString second_string;
    for (;;) {
        if (button->text() == "Video") {
            break;
        }

        else {

            if (hour < 10) {
                hour_string = "0" + QString::number(hour);
            }
            else {
                hour_string = QString::number(hour);
            }

            if (minute < 10) {
                minute_string = "0" + QString::number(minute);
            }
            else {
                minute_string = QString::number(minute);
            }

            if (second < 10) {
                second_string = "0" + QString::number(second);
            }
            else {
                second_string = QString::number(second);
            }

            time = hour_string + ":" + minute_string + ":" + second_string;

            button->setText(time);

            second++;

            if (second == 60) {
                second = 0;

                minute++;
            }

            if (minute == 60) {
                minute = 0;
                hour++;
            }
            sleep(1);
        }
    }
}

// button action
void MainWindow::action(QPushButton* button, int flag) {
    if (flag == 0) {
        button->setText("Error");
        sleep(2);
        button->setText("Photo");
    }

    else if (flag == 1) {
        button->setText(" ✓✓✓ ");
        usleep(45000);
        button->setText("Photo");
    }

    if (flag == 2) {
        button->setText("Error");
        sleep(2);
        button->setText("Video");
    }
}

void MainWindow::disPlaylprResult(QString result) {
    if (result.isEmpty()) {
        ui->resultLabel->setText("Result:No license plate recognition!");
    }
    else {
        ui->resultLabel->setText("车牌:" + result);
        // 从数据库中查找
        queryData.clear();
        queryData.prepare("select * from users where license=?;");
        queryData.addBindValue(result);
        queryData.exec();
        if (queryData.size() > 0) {
            queryData.next();
            if (queryData.value(2).toString() == "黑名单") {
                QMessageBox::warning(this, "提示", "该车牌号已被禁止使用！");
            }
            else {
                ui->nameLabel->setText("车主:" + queryData.value(1).toString());
                ui->balanceLabel->setText("余额:" + queryData.value(3).toString());
                queryData.clear();
                queryData.prepare("select * from logs where license=? and out_date is null;");
                queryData.addBindValue(result);
                queryData.exec();
                queryData.next();
                QDateTime inDate = QDateTime::currentDateTime();
                ui->inDateLabel->setText("入库时间:" + inDate.toString());
                // 判断有没有找到出库时间是空的，没找到说明是入库
                if (queryData.size() == 0) {
                    queryData.clear();
                    queryData.prepare("insert into logs (license, in_date) values (?, now());");
                    queryData.addBindValue(result);
                    queryData.exec();
                    ui->statusLabel->setText("操作:入库");
                    ui->outDateLabel->setVisible(false);
                }
                else {
                    // VsCode
                    // 提取并显示入库时间
                    QString dateTimeString = queryData.value("in_date").toString(); //提取的时间格式为：2020-12-12T12:12:12.000Z
                    dateTimeString = dateTimeString.mid(0, 19);
                    dateTimeString.replace("T", " ");
                    QDateTime dateTime = QDateTime::fromString(dateTimeString, "yyyy-MM-dd hh:mm:ss");

                    // 获取当前时间，即出库时间
                    QDateTime now = QDateTime::currentDateTime();
                    int seconds = dateTime.secsTo(now);
                    int minutes = seconds / 60;
                    float cost = minutes * 0.02 + 0.02;  // 2分钱每分钟
                    ui->balanceLabel->setText("支付:" + QString::number(cost) + "元");
                    ui->outDateLabel->setVisible(true);
                    ui->outDateLabel->setText("出库时间:" + now.toString());
                    queryData.clear();
                    queryData.prepare("update logs set out_date=now(),cost=? where license=? and out_date is null;");
                    queryData.addBindValue(cost);
                    queryData.addBindValue(result);
                    queryData.exec();
                    queryData.clear();
                    queryData.prepare("update users set balance=balance-? where license=?;");
                    queryData.addBindValue(cost);
                    queryData.addBindValue(result);
                    queryData.exec();
                    ui->statusLabel->setText("操作:出库");
                }
            }
        }
        else {
            QMessageBox::warning(this, "提示", "数据库中没有该车牌号！");
        }
    }
}

void MainWindow::databaseConnect(QString host, int port, QString userName, QString password, QString databaseName) {
    db.setHostName(host);
    db.setPort(port);
    db.setUserName(userName);
    db.setPassword(password);
    db.setDatabaseName(databaseName);
    if (!db.open()) {
        QMessageBox::warning(this, "错误", db.lastError().text());
        return;
    }
    else {
        QMessageBox::information(this, "成功", "数据库连接成功");
        qDebug() << "数据连接成功";
    }
}




