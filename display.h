#ifndef KURSOVAYA_DISPLAY_H
#define KURSOVAYA_DISPLAY_H


#include <GL/glut.h>


void compute_mandelbrot(double, double, double, double);
void processSpecialKeys(int key, int x, int y);
void mouse(int button, int state, int x, int y);
void keyboard(unsigned char c, int x, int y);
void display();
void tui();
void window(int argc, char **argv);
void gui(int argc, char **argv);

#endif //KURSOVAYA_DISPLAY_H
