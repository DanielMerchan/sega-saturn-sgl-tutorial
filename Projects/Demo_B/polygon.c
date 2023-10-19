#include "sgl.h"

/* Definition of 3 objects which will be used to apply hierarchical matrices and transformations together */

/*
   ==== <- Object 3 on top will be placed in main.c
    || <- Object 2
    || <- Object 2
    || <- Object 1
    || <- Object 1
*/

/*
    Object 1 is a rectangle
*/
POINT point_PLANE1[] = {
	POStoFIXED(-5.0, -40.0, 0.0),
	POStoFIXED( 5.0, -40.0, 0.0),
	POStoFIXED( 5.0,   0.0, 0.0),
	POStoFIXED(-5.0,   0.0, 0.0),
};

/*
    Object 2 is a rectangle same as Object 1
*/
POINT point_PLANE2[] = {
	POStoFIXED(-5.0, -40.0, 0.0),
	POStoFIXED( 5.0, -40.0, 0.0),
	POStoFIXED( 5.0,   0.0, 0.0),
	POStoFIXED(-5.0,   0.0, 0.0),
};

/*
    Object 3 is a fan which will be placed on top of the others
*/
POINT point_PLANE3[] = {
	POStoFIXED(-20.0, 0.0, -5.0),
	POStoFIXED(-20.0, 0.0,  5.0),
	POStoFIXED( 20.0, 0.0, -5.0),
	POStoFIXED( 20.0, 0.0,  5.0),
};

POLYGON polygon_PLANE1[] = {
	NORMAL(0.0, 1.0, 0.0), VERTICES(0, 1, 2, 3),
};

POLYGON polygon_PLANE2[] = {
	NORMAL(0.0, 1.0, 0.0), VERTICES(0, 1, 2, 3),
};

POLYGON polygon_PLANE3[] = {
	NORMAL(0.0, 1.0, 0.0), VERTICES(0, 1, 2, 3),
};


ATTR attribute_PLANE1[] = {
	ATTRIBUTE(Dual_Plane, SORT_CEN, No_Texture, C_RGB(0, 31, 31), No_Gouraud, MESHoff, sprPolygon, No_Option),
};

ATTR attribute_PLANE2[] = {
	ATTRIBUTE(Dual_Plane, SORT_CEN, No_Texture, C_RGB(31, 31, 0), No_Gouraud, MESHoff, sprPolygon, No_Option),
};

ATTR attribute_PLANE3[] = {
	ATTRIBUTE(Dual_Plane, SORT_CEN, No_Texture, C_RGB(31, 0, 31), No_Gouraud, MESHoff, sprPolygon, No_Option),
};

PDATA PD_PLANE1 = {
	point_PLANE1, sizeof(point_PLANE1) / sizeof(POINT),
	polygon_PLANE1, sizeof(polygon_PLANE1) / sizeof(POLYGON),
	attribute_PLANE1
};

PDATA PD_PLANE2 = {
	point_PLANE2, sizeof(point_PLANE2) / sizeof(POINT),
	polygon_PLANE2, sizeof(polygon_PLANE2) / sizeof(POLYGON),
	attribute_PLANE2
};

PDATA PD_PLANE3 = {
	point_PLANE3, sizeof(point_PLANE3) / sizeof(POINT),
	polygon_PLANE3, sizeof(polygon_PLANE3) / sizeof(POLYGON),
	attribute_PLANE3
};

