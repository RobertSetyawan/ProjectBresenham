#include <GL\freeglut.h>
#include <GL\glut.h>
#include <iostream>
#include <stdlib.h>
#include <conio.h>

///Nama     : Robert Setyawan
///Materi   : Algoritma Bresenham

using namespace std;

void init();
void display(void);
void bresenham(void);

///ukuran window
int lebar = 500;
int tinggi = 500;

// judul window
char *judul = "Algoritma Bresenham";

int x1, y1, x2, y2, x, y, xend, yend,duaDy,duaDyDx,duaDx,duaDxDy, p;

int main(int argc, char **argv)
{
    cout <<"Masukkan nilai x , y awal : ";
    cin >>x1;
    cin >>y1;
    cout <<"Masukkan nilai x , y akhir : ";
    cin >>x2;
    cin >>y2;
	//  inisialisasi GLUT (OpenGL Utility Toolkit)
	glutInit(&argc, argv);
	glutInitWindowSize(lebar, tinggi); //set ukuran window
	glutCreateWindow(judul); //set judul window

	init();
	glutDisplayFunc(display);
	glutMainLoop(); // set loop pemrosesan GLUT
}

void init()
{
	glClearColor(1.0, 1.0, 1.0, 0.0); //set warna background
	glColor3f(0.0, 0.0, 0.0); //set warna titik
	glPointSize(3.0); //set ukuran titik
	gluOrtho2D(0, 800.0, 0.0, 600.0); // set ukuran viewing window
}
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT); //clear color
	bresenham(); //jalankan fungsi bresenham
	glutSwapBuffers(); //swap buffer
}

void bresenham() {

	//hitung dx dan dy
	int dx = abs(x2 - x1);
	int dy = abs(y2 - y1);

    //menentukan titik awal
    //jika x1 > x2 maka titik awal = x1
    if (dx  > dy) {
        //Menentukan p awal
        p = (2 * dx) - dy;
        //p selanjutnya untuk p < 0
        duaDy = 2 * dy;
        //p selanjutnya untuk p >= 0
        duaDyDx = (2*dy) - (2*dx);

        if(x1 < x2){
            x = x1;
            y = y1;
            xend = x2;
            yend = y2;
        }else{
            x = x2;
            y = y2;
            xend = x1;
            yend = y1;
        }
    }
    //jika x1<x2 maka titik awal = x2
    else
    {
        //Menentukan p awal
        p = (2 * dy) - dx;
        //p selanjutnya untuk p < 0
        duaDx = 2 * dx;
        //p selanjutnya untuk p >= 0
        duaDxDy = (2*dx) - (2*dy);
        if(y1 < y2){
            x = x1;
            y = y1;
            xend = x2;
            yend = y2;
        }else{
            x = x2;
            y = y2;
            xend = x1;
            yend = y1;
        }
    }

    //menentukan titik awal
    //jika y1 > y2 maka titik awal = y2
//    if (y1 > y2) {
//        x = x2;
//        y = y2;
//
//        cout<<"hai";
//    }
//    else
//    {
//        x = x1;
//        y = y1;
//
//    }
	//gambar titik awal
    glBegin(GL_POINTS);
    glVertex2i(x, y);

        //perulangan untuk menggambar titik-titik
        do {
           if(dx>dy){
            x++;
                if(p < 0){
                p = p + duaDy;
                }
            else{
                if(y > yend){
                    y--;
                }else{
                    y++;
                }
                p = p + duaDyDx;

            }

        }
            else{
            y++;
            if(p < 0){
                p = p + duaDx;

            }
            else{
                if(x > xend){
                    x--;
                }else{
                    x++;
                }
                p = p + duaDxDy;

                }
            }
            glVertex2i(x, y);
		}while(y < yend || x < xend);

	glEnd();
	glFlush();
    }


