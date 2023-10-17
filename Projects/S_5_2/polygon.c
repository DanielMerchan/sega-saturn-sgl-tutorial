#include "sgl.h"

POINT point_CUBE[] = {
	POStoFIXED(-10.0, -10.0,  10.0),
	POStoFIXED( 10.0, -10.0,  10.0),
	POStoFIXED( 10.0,  10.0,  10.0),
	POStoFIXED(-10.0,  10.0,  10.0),
	POStoFIXED(-10.0, -10.0, -10.0),
	POStoFIXED( 10.0, -10.0, -10.0),
	POStoFIXED( 10.0,  10.0, -10.0),
	POStoFIXED(-10.0,  10.0, -10.0),
};

POLYGON polygon_CUBE[] = {
	NORMAL( 0.0, 0.0, 1.0), VERTICES(0,1,2,3),
	NORMAL(-1.0, 0.0, 0.0), VERTICES(4,0,3,7),
	NORMAL( 0.0, 0.0,-1.0), VERTICES(5,4,7,6),
	NORMAL( 1.0, 0.0, 0.0), VERTICES(1,5,6,2),
	NORMAL( 0.0,-1.0, 0.0), VERTICES(4,5,1,0),
	NORMAL( 0.0, 1.0, 0.0), VERTICES(3,2,6,7),
};

ATTR attribute_CUBE[] = {
	ATTRIBUTE(Single_Plane,SORT_MIN,No_Texture,C_RGB(31,31,31),No_Gouraud,MESHoff,sprPolygon,No_Option),
	ATTRIBUTE(Single_Plane,SORT_MIN,No_Texture,C_RGB(31,31,0),No_Gouraud,MESHoff,sprPolygon,No_Option),
	ATTRIBUTE(Single_Plane,SORT_MIN,No_Texture,C_RGB(31,31,31),No_Gouraud,MESHoff,sprPolygon,No_Option),
	ATTRIBUTE(Single_Plane,SORT_MIN,No_Texture,C_RGB(31,31,0),No_Gouraud,MESHoff,sprPolygon,No_Option),
	ATTRIBUTE(Single_Plane,SORT_MIN,No_Texture,C_RGB(31,0,31),No_Gouraud,MESHoff,sprPolygon,No_Option),
	ATTRIBUTE(Single_Plane,SORT_MIN,No_Texture,C_RGB(31,0,31),No_Gouraud,MESHoff,sprPolygon,No_Option),
};

PDATA PD_CUBE = {
	point_CUBE,sizeof(point_CUBE)/sizeof(POINT),
	polygon_CUBE,sizeof(polygon_CUBE)/sizeof(POLYGON),
	attribute_CUBE
};

