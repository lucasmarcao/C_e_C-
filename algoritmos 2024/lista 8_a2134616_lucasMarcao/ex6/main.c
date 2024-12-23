#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N_NAME 100
#define N_PHONE 15

#define TYPE_FAMILY 0
#define TYPE_FRIEND 1
#define TYPE_WORK 2
#define TYPE_OTHER 3

struct contact
{
    char name[N_NAME];
    char email[N_NAME];
    char phone[N_PHONE]; // [44 99999-9999] \0
    int type;
};

typedef struct contact Contact;

struct point2D
{
    float x;
    float y;
};

typedef struct point2D Point2D;

char types[4][20] = {"Family", "Friend", "Work", "Others"};

void print_contact(Contact c)
{
    printf("{%s, %s, %s, %s}\n", c.name, c.email, c.phone, types[c.type]);
}

Point2D point_sum(Point2D p1, Point2D p2)
{
    Point2D res = {p1.x + p2.x, p1.y + p2.y};
    return res;
}

int main()
{
    Point2D p1 = {1, 2};
    Point2D p2 = {3, 4};
    Point2D res = point_sum(p1, p2);
    printf("res: {x:%f, y:%f}\n", res.x, res.y);

    Contact c1 = {"John Doe", "johndoe@email.com", "44 99876-7865", TYPE_FRIEND};
    print_contact(c1);

    Contact c2 = c1;
    print_contact(c2);

    Contact c3;
    c3 = (Contact){"Alanis Morre 7", "morre7@email.com", "44 98765-0987", TYPE_WORK};
    print_contact(c3);

    printf("\n \n");
    return 0;
}