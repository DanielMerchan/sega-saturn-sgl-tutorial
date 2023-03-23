#include "sgl.h"

POINT point_PLANE[] = {
    POStoFIXED(-160.0, -160.0, 0.0),
    POStoFIXED(160.0, -160.0, 0.0),
    POStoFIXED(160.0, 160.0, 0.0),
    POStoFIXED(-160.0, 160.0, 0.0),
    POStoFIXED(-80.0, -80.0, 0.0),
    POStoFIXED(80.0, -80.0, 0.0),
    POStoFIXED(80.0, 80.0, 0.0),
    POStoFIXED(-80.0, 80.0, 0.0),
};

POINT point_CUBE[] = {
    POStoFIXED(-15.0, -15.0, 15.0),
    POStoFIXED(15.0, -15.0, 15.0),
    POStoFIXED(15.0, 15.0, 15.0),
    POStoFIXED(-15.0, 15.0, 15.0),
    POStoFIXED(-15.0, -15.0, -15.0),
    POStoFIXED(15.0, -15.0, -15.0),
    POStoFIXED(15.0, 15.0, -15.0),
    POStoFIXED(-15.0, 15.0, -15.0),
};

POLYGON polygon_PLANE[] = {
    NORMAL(0.000000, 0.000000, -1.000000),
    VERTICES(0, 1, 2, 3),
    NORMAL(0.000000, 0.000000, -1.000000),
    VERTICES(4, 5, 6, 7),
};

POLYGON polygon_CUBE[] = {
    NORMAL(0.000000, 0.000000, 1.000000),
    VERTICES(0, 1, 2, 3),
    NORMAL(-1.000000, 0.000000, 0.000000),
    VERTICES(4, 0, 3, 7),
    NORMAL(0.000000, 0.000000, -1.000000),
    VERTICES(5, 4, 7, 6),
    NORMAL(1.000000, 0.000000, 0.000000),
    VERTICES(1, 5, 6, 2),
    NORMAL(0.000000, -1.000000, 0.000000),
    VERTICES(4, 5, 1, 0),
    NORMAL(0.000000, 1.000000, 0.000000),
    VERTICES(3, 2, 6, 7),
};

ATTR attribute_PLANE[] = {
    ATTRIBUTE(Single_Plane, SORT_MIN, No_Texture, C_RGB(16, 16, 16), No_Gouraud, MESHoff | Window_Out, sprPolygon, No_Option),
    ATTRIBUTE(Single_Plane, SORT_MIN, No_Texture, C_RGB(00, 31, 31), No_Gouraud, MESHoff | Window_Out, sprPolygon, No_Option),
};

ATTR attribute_CUBE[] = {
    ATTRIBUTE(Single_Plane, SORT_MIN, No_Texture, C_RGB(31, 31, 31), No_Gouraud, MESHoff | Window_In, sprPolygon, No_Option),
    ATTRIBUTE(Single_Plane, SORT_MIN, No_Texture, C_RGB(31, 00, 00), No_Gouraud, MESHoff | Window_In, sprPolygon, No_Option),
    ATTRIBUTE(Single_Plane, SORT_MIN, No_Texture, C_RGB(00, 31, 00), No_Gouraud, MESHoff | Window_In, sprPolygon, No_Option),
    ATTRIBUTE(Single_Plane, SORT_MIN, No_Texture, C_RGB(00, 00, 31), No_Gouraud, MESHoff | Window_In, sprPolygon, No_Option),
    ATTRIBUTE(Single_Plane, SORT_MIN, No_Texture, C_RGB(31, 31, 00), No_Gouraud, MESHoff | Window_In, sprPolygon, No_Option),
    ATTRIBUTE(Single_Plane, SORT_MIN, No_Texture, C_RGB(00, 31, 31), No_Gouraud, MESHoff | Window_In, sprPolygon, No_Option),
};

PDATA PD_PLANE = {
    point_PLANE,
    sizeof(point_PLANE) / sizeof(POINT),
    polygon_PLANE,
    sizeof(polygon_PLANE) / sizeof(POLYGON),
    attribute_PLANE,
};

PDATA PD_CUBE = {
    point_CUBE,
    sizeof(point_CUBE) / sizeof(POINT),
    polygon_CUBE,
    sizeof(polygon_CUBE) / sizeof(POLYGON),
    attribute_CUBE,
};
