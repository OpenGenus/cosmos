/* Part of Cosmos by OpenGenus Foundation */

#include <math.h>
#define TRUE    1
#define FALSE   0
#define PI  3.1415926   /* ratio of circumference to diameter */
#define EPSILON 0.000001    /* a quantity small enough to be zero */

typedef int bool;

typedef struct {
    double a;       /* x-coefficient */
    double b;       /* y-coefficient */
    double c;       /* constant term */
} line;

#define DIMENSION   2   /* dimension of points */
#define X       0   /* x-coordinate index */
#define Y       1   /* y-coordinate index */

typedef double point[DIMENSION];

#define MAXPOLY     200 /* maximum number of points in a polygon */

typedef struct {
    int n;          /* number of points in polygon */
    point p[MAXPOLY];   /* array of points in polygon */
} polygon;


typedef struct {
    point p1,p2;        /* endpoints of line segment */
} segment;

typedef point triangle[3];  /* triangle datatype */

typedef struct {
    int n;          /* number of triangles in triangulation */
    int t[MAXPOLY][3];  /* indicies of vertices in triangulation */
} triangulation;

typedef struct {
    point c;        /* center of circle */
    double r;       /* radius of circle */
} circle;


/*  Comparison macros   */

#define max(A, B)       ((A) > (B) ? (A) : (B))
#define min(A, B)       ((A) < (B) ? (A) : (B))


points_to_line(point p1, point p2, line *l)
{
    if (p1[X] == p2[X]) {
        l->a = 1;
        l->b = 0;
        l->c = -p1[X];
    } else {
            l->b = 1;
        l->a = -(p1[Y]-p2[Y])/(p1[X]-p2[X]);
        l->c = -(l->a * p1[X]) - (l->b * p1[Y]);
    }
}

point_and_slope_to_line(point p, double m, line *l)
{
    l->a = -m;
    l->b = 1;
    l->c = -((l->a*p[X]) + (l->b*p[Y]));
}

bool parallelQ(line l1, line l2)
{
    return ( (fabs(l1.a-l2.a) <= EPSILON) &&
         (fabs(l1.b-l2.b) <= EPSILON) );
}

bool same_lineQ(line l1, line l2)
{
    return ( parallelQ(l1,l2) && (fabs(l1.c-l2.c) <= EPSILON) );
}


intersection_point(line l1, line l2, point p)
{
    if (same_lineQ(l1,l2)) {
        printf("Warning: Identical lines, all points intersect.\n");
        p[X] = p[Y] = 0.0;
        return;
    }

    if (parallelQ(l1,l2) == TRUE) {
        printf("Error: Distinct parallel lines do not intersect.\n");
        return;
    }

    p[X] = (l2.b*l1.c - l1.b*l2.c) / (l2.a*l1.b - l1.a*l2.b);

    if (fabs(l1.b) > EPSILON)   /* test for vertical line */
        p[Y] = - (l1.a * (p[X]) + l1.c) / l1.b;
    else
        p[Y] = - (l2.a * (p[X]) + l2.c) / l2.b;
}

closest_point(point p_in, line l, point p_c)
{
    line perp;      /* perpendicular to l through (x,y) */

    if (fabs(l.b) <= EPSILON) { /* vertical line */
        p_c[X] = -(l.c);
        p_c[Y] = p_in[Y];
        return;
    }

    if (fabs(l.a) <= EPSILON) { /* horizontal line */
        p_c[X] = p_in[X];
        p_c[Y] = -(l.c);
        return;
    }

    point_and_slope_to_line(p_in,1/l.a,&perp); /* non-degenerate line */
/*printf("perpendicular bisector "); print_line(perp);*/
    intersection_point(l,perp,p_c);
/*printf("closest point "); print_point(p_c);*/
}

double distance(point a, point b)
{
        int i;          /* counter */
        double d=0.0;       /* accumulated distance */

        for (i=0; i<DIMENSION; i++)
                d = d + (a[i]-b[i]) * (a[i]-b[i]);

        return( sqrt(d) );
}

/***********************************************************************/

copy_point(point a, point b)
{
    int i;          /* counter */

    for (i=0; i<DIMENSION; i++) b[i] = a[i];
}

swap_point(point a, point b)
{
    point c;        /* temporary point */

    copy_point(a,c);
    copy_point(b,a);
    copy_point(c,b);
}


points_to_segment(point a, point b, segment *s)
{
    copy_point(a,s->p1);
    copy_point(b,s->p2);
}

segment_to_points(segment s, point p1, point p2)
{
    copy_point(s.p1,p1);
    copy_point(s.p2,p2);
}


bool point_in_box(point p, point b1, point b2)
{
    return( (p[X] >= min(b1[X],b2[X])) && (p[X] <= max(b1[X],b2[X]))
        && (p[Y] >= min(b1[Y],b2[Y])) && (p[Y] <= max(b1[Y],b2[Y])) );
}

bool segments_intersect(segment s1, segment s2)
{
    line l1,l2;     /* lines containing the input segments */
    point p;        /* intersection point */

    points_to_line(s1.p1,s1.p2,&l1);
    points_to_line(s2.p1,s2.p2,&l2);

    if (same_lineQ(l1,l2))  /* overlapping or disjoint segments */
        return( point_in_box(s1.p1,s2.p1,s2.p2) ||
            point_in_box(s1.p2,s2.p1,s2.p2) ||
            point_in_box(s2.p1,s1.p1,s1.p2) ||
            point_in_box(s2.p2,s1.p1,s1.p2) );

    if (parallelQ(l1,l2)) return(FALSE);

    intersection_point(l1,l2,p);

    return( point_in_box(p,s1.p1,s1.p2) && point_in_box(p,s2.p1,s2.p2) );
}

double signed_triangle_area(point a, point b, point c)
{
    return( (a[X]*b[Y] - a[Y]*b[X] + a[Y]*c[X] 
        - a[X]*c[Y] + b[X]*c[Y] - c[X]*b[Y]) / 2.0 );
}

double triangle_area(point a, point b, point c)
{
    return( fabs(signed_triangle_area(a,b,c)) );
}

bool ccw(point a, point b, point c)
{
    double signed_triangle_area();

    return (signed_triangle_area(a,b,c) > EPSILON);
}

bool cw(point a, point b, point c)
{
    double signed_triangle_area();

    return (signed_triangle_area(a,b,c) < - EPSILON);
}

bool collinear(point a, point b, point c)
{
    double signed_triangle_area();

    return (fabs(signed_triangle_area(a,b,c)) <= EPSILON);
}

print_points(point p[], int n)
{
        int i;                  /* counter */

        for (i=0; i<n; i++)
                printf("(%lf,%lf)\n",p[i][X],p[i][Y]);
}

print_polygon(polygon *p)
{
    int i;          /* counter */

        for (i=0; i<p->n; i++)
                printf("(%lf,%lf)\n",p->p[i][X],p->p[i][Y]);
}

print_point(point p)
{
    printf("%7.3lf %7.3lf\n",p[X],p[Y]);
}

print_line(line l)
{
    printf("(a=%7.3lf,b=%7.3lf,c=%7.3lf)\n",l.a,l.b,l.c);
}

print_segment(segment s)
{
    printf("segment: ");
    print_point(s.p1);
    print_point(s.p2);
}


point first_point;      /* first hull point */

convex_hull(point in[], int n, polygon *hull)
{
    int i;          /* input counter */
    int top;        /* current hull size */
    bool smaller_angle();

    if (n <= 3) {       /* all points on hull! */
        for (i=0; i<n; i++)
                        copy_point(in[i],hull->p[i]);
        hull->n = n;
        return;
    }

    sort_and_remove_duplicates(in,&n);
    copy_point(in[0],&first_point);

    qsort(&in[1], n-1, sizeof(point), smaller_angle);

    copy_point(first_point,hull->p[0]);
    copy_point(in[1],hull->p[1]);

    copy_point(first_point,in[n]);  /* sentinel to avoid special case */
    top = 1;
    i = 2;

    while (i <= n) {
        if (!ccw(hull->p[top-1], hull->p[top], in[i])) 
            top = top-1;    /* top not on hull */
        else {
            top = top+1;
                        copy_point(in[i],hull->p[top]);
            i = i+1;
        }
    }

    hull->n = top;
}


sort_and_remove_duplicates(point in[], int *n)
{
        int i;                  /* counter */
        int oldn;               /* number of points before deletion */
        int hole;               /* index marked for potential deletion */
    bool leftlower();

    qsort(in, *n, sizeof(point), leftlower);

        oldn = *n;
    hole = 1;
        for (i=1; i<oldn; i++) {
        if ((in[hole-1][X] == in[i][X]) && (in[hole-1][Y] == in[i][Y])) 
                        (*n)--;
                else {
                        copy_point(in[i],in[hole]);
                        hole = hole + 1;
                }
        }
        copy_point(in[oldn-1],in[hole]);
}


main(){
    point in[MAXPOLY];      /* input points */
    polygon hull;           /* convex hull */
    int n;              /* number of points */
    int i;              /* counter */

    scanf("%d",&n);
    for (i=0; i<n; i++)
        scanf("%lf %lf",&in[i][X],&in[i][Y]);

    convex_hull(in,n,&hull);

    print_polygon(&hull);
}


bool leftlower(point *p1, point *p2)
{
    if ((*p1)[X] < (*p2)[X]) return (-1);
    if ((*p1)[X] > (*p2)[X]) return (1);

        if ((*p1)[Y] < (*p2)[Y]) return (-1);
        if ((*p1)[Y] > (*p2)[Y]) return (1);

    return(0);
}

bool smaller_angle(point *p1, point *p2)
{
    if (collinear(first_point,*p1,*p2)) {
        if (distance(first_point,*p1) <= distance(first_point,*p2))
            return(-1);
        else
            return(1);
    }

    if (ccw(first_point,*p1,*p2))
        return(-1);
    else
        return(1);
}
