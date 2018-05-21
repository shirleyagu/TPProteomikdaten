#include<QApplication>
#include <QtWidgets> //include the needed lib

int main(int argc, char *argv[]){
    QApplication app(argc,argv);
    QWidget ourTestWindow; //create a widget(window)
    ourTestWindow.resize(600,400); //set window size
    ourTestWindow.show();
    ourTestWindow.setWindowTitle("MoeJoeTP");
    return app.exec();
}
