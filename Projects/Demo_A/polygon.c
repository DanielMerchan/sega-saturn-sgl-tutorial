#include "sgl.h"

POINT point_PLANE1[] = {
    POStoFIXED(-15.0, -15.0, -15.0),
    POStoFIXED(-15.0, -15.0, 15.0),
    POStoFIXED(-15.0, 15.0, -15.0),
    POStoFIXED(-15.0, 15.0, 15.0),
    POStoFIXED(15.0, -15.0, -15.0),
    POStoFIXED(15.0, -15.0, 15.0),
    POStoFIXED(15.0, 15.0, -15.0),
    POStoFIXED(15.0, 15.0, 15.0),
};

POINT point_PLANE2[] = {
    POStoFIXED(-100.0, -100.0, -100.0),
    POStoFIXED(-100.0, -100.0, 100.0),
    POStoFIXED(-100.0, 100.0, -100.0),
    POStoFIXED(-100.0, 100.0, 100.0),
    POStoFIXED(100.0, -100.0, -100.0),
    POStoFIXED(100.0, -100.0, 100.0),
    POStoFIXED(100.0, 100.0, -100.0),
    POStoFIXED(100.0, 100.0, 100.0),
};

POLYGON polygon_PLANE1[] = {
    NORMAL(-1.0, 0.0, 0.0), VERTICES(0, 1, 3, 2),
    NORMAL(0.0, 0.0, 1.0), VERTICES(1, 5, 7, 3),
    NORMAL(1.0, 0.0, 0.0), VERTICES(5, 4, 6, 7),
    NORMAL(0.0, 0.0, -1.0), VERTICES(4, 0, 2, 6),
    NORMAL(0.0, -1.0, 0.0), VERTICES(4, 5, 1, 0),
    NORMAL(0.0, 1.0, 0.0), VERTICES(2, 3, 7, 6),
};

POLYGON polygon_PLANE2[] = {
    NORMAL(1.0, 0.0, 0.0), VERTICES(0, 1, 3, 2),
    NORMAL(0.0, 0.0, -1.0), VERTICES(1, 5, 7, 3),
    NORMAL(-1.0, 0.0, 0.0), VERTICES(5, 4, 6, 7),
    NORMAL(0.0, 0.0, 1.0), VERTICES(4, 0, 2, 6),
    NORMAL(0.0, 1.0, 0.0), VERTICES(4, 5, 1, 0),
    NORMAL(0.0, -1.0, 0.0), VERTICES(2, 3, 7, 6),
};

ATTR attribute_PLANE1[] = {
    ATTRIBUTE(Single_Plane, SORT_MAX, No_Texture, C_RGB(31, 31, 31), No_Gouraud, MESHoff, sprPolygon, UseLight),
    ATTRIBUTE(Single_Plane, SORT_MAX, No_Texture, C_RGB(31, 0, 0), No_Gouraud, MESHoff, sprPolygon, UseLight),
    ATTRIBUTE(Single_Plane, SORT_MAX, No_Texture, C_RGB(0, 31, 0), No_Gouraud, MESHoff, sprPolygon, UseLight),
    ATTRIBUTE(Single_Plane, SORT_MAX, No_Texture, C_RGB(0, 0, 31), No_Gouraud, MESHoff, sprPolygon, UseLight),
    ATTRIBUTE(Single_Plane, SORT_MAX, No_Texture, C_RGB(31, 0, 31), No_Gouraud, MESHoff, sprPolygon, UseLight),
    ATTRIBUTE(Single_Plane, SORT_MAX, No_Texture, C_RGB(0, 31, 31), No_Gouraud, MESHoff, sprPolygon, UseLight),
};

ATTR attribute_PLANE2[] = {
    ATTRIBUTE(Single_Plane, SORT_MAX, No_Texture, C_RGB(16, 16, 16), No_Gouraud, MESHoff, sprPolygon, No_Option),
    ATTRIBUTE(Single_Plane, SORT_MAX, No_Texture, C_RGB(16, 0, 0), No_Gouraud, MESHoff, sprPolygon, No_Option),
    ATTRIBUTE(Single_Plane, SORT_MAX, No_Texture, C_RGB(0, 16, 0), No_Gouraud, MESHoff, sprPolygon, No_Option),
    ATTRIBUTE(Single_Plane, SORT_MAX, No_Texture, C_RGB(0, 0, 16), No_Gouraud, MESHoff, sprPolygon, No_Option),
    ATTRIBUTE(Single_Plane, SORT_MAX, No_Texture, C_RGB(16, 0, 16), No_Gouraud, MESHoff, sprPolygon, No_Option),
    ATTRIBUTE(Single_Plane, SORT_MAX, No_Texture, C_RGB(0, 16, 16), No_Gouraud, MESHoff, sprPolygon, No_Option),
};

PDATA PD_PLANE1 = {
    point_PLANE1, sizeof(point_PLANE1) / sizeof(POINT),
    polygon_PLANE1, sizeof(polygon_PLANE1) / sizeof(POLYGON),
    attribute_PLANE1};

PDATA PD_PLANE2 = {
    point_PLANE2, sizeof(point_PLANE2) / sizeof(POINT),
    polygon_PLANE2, sizeof(polygon_PLANE2) / sizeof(POLYGON),
    attribute_PLANE2};
