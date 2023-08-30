
#include <stdio.h>
#include<stdlib.h>
typedef struct {
    double x;
    double y;
} Point;


void Sierpinski(int amountp, Point a, Point b, Point c, Point d) {
    int i;
    int w = 0;
    double nx;
    double ny;

    for (i = 0; i < amountp; i++) {
        w = rand() % 3;
        if (w == 0) {
            nx = (a.x + d.x) / 2;
            ny = (a.y + d.y) / 2;
            d.x = nx;
            d.y = ny;

        }
        if (w == 1) {
            nx = (b.x + d.x) / 2;
            ny = (b.y + d.y) / 2;
            d.x = nx;
            d.y = ny;

        }
        if (w == 2) {
            nx = (c.x + d.x) / 2;
            ny = (c.y + d.y) / 2;
            d.x = nx;
            d.y = ny;

        }
        printf("%d %f %f\n", w, d.x, d.y);

    }
        
       
     


}
int main()
{
    Point a = { 100, 173 };
    Point b = { 0, 0 };
    Point c = { 200, 0 };
    Point d = { 38, 19 };

    srand(0);

    Sierpinski(3, a, b, c, d);
}
