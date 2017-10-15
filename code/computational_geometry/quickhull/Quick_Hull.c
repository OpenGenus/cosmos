/* Part of Cosmos by OpenGenus Foundation */

#include "bool.h"
#include "geometry.h"
#include <math.h>

point first_point;		/* first hull point */

convex_hull(point in[], int n, polygon *hull)
{
	int i;			/* input counter */
	int top;		/* current hull size */
	bool smaller_angle();
	
	if (n <= 3) { 		/* all points on hull! */
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

	copy_point(first_point,in[n]);	/* sentinel to avoid special case */
	top = 1;
	i = 2;

	while (i <= n) {
		if (!ccw(hull->p[top-1], hull->p[top], in[i])) 
			top = top-1;	/* top not on hull */
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
	point in[MAXPOLY];		/* input points */
	polygon hull;			/* convex hull */
	int n;				/* number of points */
	int i;				/* counter */

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

/*
bool leftlower(point *p1, point *p2)
{
	if (fabs((*p1)[X] - (*p2)[X]) > EPSILON) {
        	if ((*p1)[X] < (*p2)[X]) return (-1);
        	if ((*p1)[X] > (*p2)[X]) return (1);
	}

	if (fabs((*p1)[Y] - (*p2)[Y]) > EPSILON) {
        	if ((*p1)[Y] < (*p2)[Y]) return (-1);
        	if ((*p1)[Y] > (*p2)[Y]) return (1);
	}

        return(0);
}
*/

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
