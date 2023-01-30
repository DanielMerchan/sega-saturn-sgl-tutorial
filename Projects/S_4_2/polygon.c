#include "sgl.h"

static POINT point_CUBE[]={
	POStoFIXED(-15.0, -15.0,  15.0),
	POStoFIXED( 15.0, -15.0,  15.0),
	POStoFIXED( 15.0,  15.0,  15.0),
	POStoFIXED(-15.0,  15.0,  15.0),
	POStoFIXED(-15.0, -15.0, -15.0),
	POStoFIXED( 15.0, -15.0, -15.0),
	POStoFIXED( 15.0,  15.0, -15.0),
	POStoFIXED(-15.0,  15.0, -15.0),
};

static POLYGON polygon_CUBE[]={
		NORMAL( 0.0, 0.0, 1.0), VERTICES(0,1,2,3),
		NORMAL(-1.0, 0.0, 0.0), VERTICES(4,0,3,7),
		NORMAL( 0.0, 0.0,-1.0), VERTICES(5,4,7,6),
		NORMAL( 1.0, 0.0, 0.0), VERTICES(1,5,6,2),
		NORMAL( 0.0,-1.0, 0.0), VERTICES(4,5,1,0),
		NORMAL( 0.0, 1.0, 0.0), VERTICES(3,2,6,7),
	};

static ATTR attribute_CUBE[]={
	ATTRIBUTE(Single_Plane,SORT_MIN,No_Texture,C_RGB( 0,20,28),No_Gouraud,MESHoff,sprPolygon,UseLight),
	ATTRIBUTE(Single_Plane,SORT_MIN,No_Texture,C_RGB(28, 8, 0),No_Gouraud,MESHoff,sprPolygon,UseLight),
	ATTRIBUTE(Single_Plane,SORT_MIN,No_Texture,C_RGB( 8,28, 0),No_Gouraud,MESHoff,sprPolygon,UseLight),
	ATTRIBUTE(Single_Plane,SORT_MIN,No_Texture,C_RGB(28,20, 0),No_Gouraud,MESHoff,sprPolygon,UseLight),
	ATTRIBUTE(Single_Plane,SORT_MIN,No_Texture,C_RGB(16, 0,28),No_Gouraud,MESHoff,sprPolygon,UseLight),
	ATTRIBUTE(Single_Plane,SORT_MIN,No_Texture,C_RGB(28,20,16),No_Gouraud,MESHoff,sprPolygon,UseLight),
};

PDATA PD_CUBE = {
	point_CUBE,sizeof(point_CUBE)/sizeof(POINT),
	polygon_CUBE,sizeof(polygon_CUBE)/sizeof(POLYGON),
	attribute_CUBE
};

