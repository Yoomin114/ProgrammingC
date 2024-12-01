#include <stdio.h>

struct point {
    int		x;
    int		y;
};

int getArea(struct point *p1, struct point *p2) {
    int width = p2->x - p1->x;  
    int height = p2->y - p1->y;
    
    return width * height;
}

int main() {
    struct point p1, p2;
    struct point *pPtr1 = &p1, *pPtr2 = &p2; 

    printf("Input the coordinate p1 (x y): ");
    scanf("%d %d", &p1.x, &p1.y);

    printf("Input the coordinate p2 (x y): ");
    scanf("%d %d", &p2.x, &p2.y);

    int area = getArea(pPtr1, pPtr2);
    printf("Area: %d\n", area);

    return 0;
}

