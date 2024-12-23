#include <stdio.h>

struct point
{
    float x;
    float y;
};

typedef struct point Point;

void print_point(Point p)
{
    printf("(%.2f, %.2f)\n", p.x, p.y);
}

int main()
{
    Point p = {3.14159, 2.71828};
    print_point(p);
    return 0;
}
