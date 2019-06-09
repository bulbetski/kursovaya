#include "Preload.h"
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;

bool Preload::preload_picture(){
    int line = 1;
    std::string param;
    std::ifstream File("preload.txt");
    if (!File)
        return false;
    else{
        while(getline(File, param)) {
            if (line == 1)
                maxIterations = std::stoi(param);
            else if (line == 2)
                move_x = std::stof(param);
            else if (line == 3)
                move_y = std::stof(param);
            else if (line == 4)
                zoom_x = std::stof(param);
            else if (line == 5)
                zoom_y = std::stof(param);
            else if (line == 6)
                red = std::stof(param);
            else if (line == 7)
                green = std::stof(param);
            else
                blue = std::stof(param);
            line++;
        }
    }
    return true;
}

std::ostream &operator<<(std::ostream &os, const Preload &preload) {
    os << preload.maxIterations << endl << preload.move_x << endl << preload.move_y << endl << preload.zoom_x
       << endl << preload.zoom_y << endl << preload.red << endl << preload.green << endl << preload.blue;
    return os;
}

int Preload::getMaxIterations() const {
    return maxIterations;
}

float Preload::getMoveX() const {
    return move_x;
}

float Preload::getMoveY() const {
    return move_y;
}

float Preload::getZoomX() const {
    return zoom_x;
}

float Preload::getZoomY() const {
    return zoom_y;
}

float Preload::getRed() const {
    return red;
}

float Preload::getGreen() const {
    return green;
}

float Preload::getBlue() const {
    return blue;
}

Preload::Preload(int maxIterations, float moveX, float moveY, float zoomX, float zoomY, float red, float green,
                 float blue) : maxIterations(maxIterations), move_x(moveX), move_y(moveY), zoom_x(zoomX), zoom_y(zoomY),
                               red(red), green(green), blue(blue) {}



char input_answer(){
    std::string inp;
    cin >> inp;
    while (true) {
        bool wrong_input = false;
        if ((inp[0] == 'y' || inp[0] == 'n') && inp.size() == 1) {
            break;
        }
        else
            wrong_input = true;
        if (wrong_input){
            inp = "";
            cout << "The input is wrong, please try again: ";
            cin >> inp;
        }
    }
    return inp[0];
}



