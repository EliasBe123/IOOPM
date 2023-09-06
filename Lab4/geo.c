#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

struct point
{
  int x;
  int y;
};

typedef struct point point_t;

struct rectangle{
    point_t upper;
    point_t lower;
};

typedef struct rectangle rectangle_t;

struct point translate(point_t p1, point_t p2)
{
  p1.x += p2.x;
  p1.y += p2.y;
  return p1;
}

void print_point(point_t *p){
    printf("point(x=%d,y=%d)\n", p->x, p->y);
}

void print_rect(rectangle_t *r){
    printf("upper left(x = %d,y = %d), lower right(x = %d,y = %d)\n", r->upper.x, r->upper.y, r->lower.x, r->lower.y);
}

point_t make_point(int x, int y){
    point_t p = { .x = x, .y = y};
    return p;
}

rectangle_t make_rect(int x1, int y1, int x2, int y2){
    rectangle_t r = { .upper.x = x1, .upper.y = y1, .lower.x = x2, .lower.y = y2};
    return r;
}

int area_rect(rectangle_t *r){
    return (r->upper.x - r->lower.x * r->upper.y - r->lower.y);
}

bool intersects_rect(rectangle_t *r1, rectangle_t *r2){
    for(int i = r1->upper.y; i > r1->lower.y; i--){
        for(int j = r1->upper.x; j < r1->lower.x; j++){
            if((j >= r2->upper.x && j <= r2->lower.x) && (i <= r2->upper.y && i >= r2->lower.y)){
                return true;
            }
        }
    }
    return false;
}

rectangle_t intersection_rect(rectangle_t *r1, rectangle_t *r2){
    int x1;
    int x2;
    int y1;
    int y2;
    if(r2->upper.x < r1->upper.x){
        x1 = r1->upper.x;
    }else{
        x1 = r2->upper.x;
    }
    if( r2->upper.y < r1->upper.y){
        y1 = r2->upper.y;
    }else{
        y1 = r1->upper.y;
    }
    if(r1->lower.x < r2->lower.x){
        x2 = r1->lower.x;
    }else{
        x2 = r2->lower.x;
    }
    if(r1->lower.y < r2->lower.y){
        y2 = r2->lower.y;
    }else{
        y2 = r1->lower.y;
    }

    
    return make_rect(x1, y1, x2, y2);

}

int main(void)
{
  rectangle_t r1 = make_rect(0, 10, 10, 0);
  rectangle_t r2 = make_rect(2, 15, 8, 8);
  rectangle_t r = intersection_rect(&r1, &r2);
  printf("Your boolean variable is: %s", intersects_rect(&r1, &r2) ? "true" : "false");
  print_rect(&r);
  
}