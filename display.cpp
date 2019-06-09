#include "display.h"
#include "Preload.h"
#include "Complex.h"
#include <iostream>


using std::cout;
using std::cin;
using std::endl;

int maxIterations = 15;
float xx = 0.0, yy = 0.0;
float zoom_x = 1, zoom_y = 1;
float red, green, blue;


void compute_mandelbrot(double left, double right, double top, double bottom){
    const int width = glutGet(GLUT_WINDOW_WIDTH);
    const int height = glutGet(GLUT_WINDOW_HEIGHT);
    glBegin(GL_POINTS);
    for(int y = 0; y < height; y++){
        for(int x = 0; x < width; x++){
            Complex c(left + (x * (right - left) / width), top + (y * (bottom - top) / height));
            Complex z(0.0, 0.0);

            int iterations = 0;
            while(z.abs() < 2.0 && iterations < maxIterations){
                z = (z * z) + c;
                iterations++;
            }
            if (iterations == maxIterations){
                glColor3f(red, green, blue);
                glVertex2i(x, y);
            }
        }
    }
    glEnd();
}

void processSpecialKeys(int key, int x, int y) {

    switch(key) {
        case GLUT_KEY_F1:
            red = 1.0;
            green = 0.0;
            blue = 0.0;
            break;
        case GLUT_KEY_F2:
            red = 0.0;
            green = 1.0;
            blue = 0.0;
            break;
        case GLUT_KEY_F3:
            red = 0.0;
            green = 0.0;
            blue = 1.0;
            break;
        case GLUT_KEY_F4:
            red = 0.0;
            green = 0.0;
            blue = 0.0;
            break;
        case GLUT_KEY_LEFT:
            xx += 20.0;
            break;
        case GLUT_KEY_RIGHT:
            xx -= 20.0;
            break;
        case GLUT_KEY_UP:
            yy -= 20.0;
           break;
        case GLUT_KEY_DOWN:
            yy += 20.0;
            break;
        case GLUT_KEY_F12:
            Preload picture(maxIterations, xx, yy, zoom_x, zoom_y, red, green, blue);
            std::ofstream File("preload.txt");
            File << picture;
            File.close();
            break;
    }
}

void mouse(int button, int state, int x, int y){
    if (button == 3){
        zoom_x += 0.03;
        zoom_y += 0.03;
    }

    if (button == 4 && maxIterations > 2){
        zoom_x -= 0.03;
        zoom_y -= 0.03;
    }

}

void keyboard(unsigned char c, int x, int y){
    if (c == 27)
        exit(0);
    if (c == 43)
        maxIterations++;
    if (c == 45)
        maxIterations--;
}

void display(){
    const int width = glutGet(GLUT_WINDOW_WIDTH);
    const int height = glutGet(GLUT_WINDOW_HEIGHT);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, width, 0, height, -1, 1);
    glTranslatef(xx, yy, 0.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glScalef(zoom_x, zoom_y, 1);
    compute_mandelbrot(-2.0, 1.0, 1.125, -1.125);
    glutSwapBuffers();
}

void tui(){
    cout << "=============================================" << endl;
    cout << "Welcome to Mandelbrot's set drawer." << endl;
    cout << "=============================================" << endl;
    cout << "To close drawer press ESC button" << endl;
    cout << "=============================================" << endl;
    cout << "You can use arrow keys to move camera around." << endl;
    cout << "=============================================" << endl;
    cout << "Use + or - buttons to change the number of iterations (the more iterations the more precise picture will be)." << endl
         << "By default this value is set to 15." << endl;
    cout << "=============================================" << endl;
    cout << "Use your mouse wheel to zoom." << endl;
    cout << "=============================================" << endl;
    cout << "Also you can change Mandelbrot's set color by pressing following buttons:" << endl
         << "F1 to make drawing RED" << endl
         << "F2 to make drawing GREEN" << endl
         << "F3 to make drawing BLUE" << endl
         << "F4 to make drawing BLACK" << endl;
    cout << "=============================================" << endl;
    cout << "You can take screenshots by pressing F12." << endl;
    cout << "Also you can preload last taken screenshot (if screenshot file exists)." << endl;
    cout << "=============================================" << endl;
    Preload p;
    bool file_exists = p.preload_picture();
    if (file_exists){
        cout << "Do you want to preload last taken screenshot? Press yes or no [y/n]." << endl;
        if (input_answer() == 'y'){
            maxIterations = p.getMaxIterations();
            xx = p.getMoveX();
            yy = p.getMoveY();
            zoom_x = p.getZoomX();
            zoom_y = p.getZoomY();
            red = p.getRed();
            green = p.getGreen();
            blue = p.getBlue();
            cout << "Picture is successfully preloaded." << endl;
            cout << "=============================================" << endl;
            cout << "Press any button to continue...";
            getchar();
        }
        else{
            cout << "The default picture will be drawn." << endl;
            cout << "=============================================" << endl;
            cout << "Press any button to continue...";
            getchar();
        }
    }
    else{
        cout << "File does not exist. Can't preload picture." << endl;
        cout << "=============================================" << endl;
        cout << "Press any button to continue...";
    }
    getchar();
}

void window(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE| GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Mandelbrot set");
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutSpecialFunc(processSpecialKeys);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
}

void gui(int argc, char **argv){
    tui();
    window(argc, argv);
}