#ifndef KURSOVAYA_PRELOAD_H
#define KURSOVAYA_PRELOAD_H


#include <ostream>
#include <fstream>

class Preload {
private:
    int maxIterations;
    float move_x;
    float move_y;
    float zoom_x;
    float zoom_y;
    float red;
    float green;
    float blue;
public:
    Preload() {};
    Preload(int maxIterations, float moveX, float moveY, float zoomX, float zoomY, float red, float green, float blue);

    friend std::ostream &operator<<(std::ostream &os, const Preload &preload);
    bool preload_picture();

    int getMaxIterations() const;
    float getMoveX() const;
    float getMoveY() const;
    float getZoomX() const;
    float getZoomY() const;
    float getRed() const;
    float getGreen() const;
    float getBlue() const;


};

char input_answer();
#endif //KURSOVAYA_PRELOAD_H
