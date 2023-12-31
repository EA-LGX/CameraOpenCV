#include "mainwindow.h"
#include <QApplication>
#include <QPushButton>

Mat frame;
VideoCapture cap;
QString dir = "";
QString ip_url;
QPushButton* button_url;
QPushButton* button_video;
QPushButton* button_photo;
cv::VideoWriter* video;
QComboBox* format_combo;

int main(int argc, char* argv[]) {

    //对高分辨率屏幕的支持
#if (QT_VERSION >= QT_VERSION_CHECK(5,6,0))
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QApplication a(argc, argv);

    FILE* file;
    //    std::string path=get_current_dir_name();
    std::string path_temp = "D:\\Desktop\\Code\\QT\\CameraOpenCV\\build\\release\\camera.png";

    if (file = fopen(path_temp.c_str(), "r")) {
        fclose(file);
    }
    else {
        system("wget https://ahmetfurkandemir.s3.amazonaws.com/camera.png");
    }

    MainWindow w;
    w.setWindowIcon(QPixmap(path_temp.c_str()));

    w.show();
    return a.exec();
}
