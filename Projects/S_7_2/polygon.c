
#include "sgl.h"

/*
	Plane example where Z-axis is 0

	v0      v1
	+-------+
	|		|
	|		|
	|		|
	+-------+
	v3		v2

*/
POINT point_PLANE[] = {
	POStoFIXED(-20.0, -20.0, 0.0), /* Array position 0 -> Corresponds to v0 (x=-20, Y=-20, Z=0) */
	POStoFIXED( 20.0, -20.0, 0.0), /* Array position 1 -> Corresponds to v1 (x=20, Y=-20, Z=0)  */
	POStoFIXED( 20.0,  20.0, 0.0), /* Array position 2 -> Corresponds to v2 (x=20, Y=20, Z=0)  */
	POStoFIXED(-20.0,  20.0, 0.0), /* Array position 3 -> Corresponds to v3 (x=-20, Y=20, Z=0)  */
};

POLYGON polygon_PLANE[] = {
	NORMAL(0.0,0.0,1.0), VERTICES(0,1,2,3), /* The only plan has face v0, v1, v2, v3 -> Normal +Z*/
};


/*
* This is the important part of the example
* Change the attributes to see the changes
* ATTRIBUTE(plane,sort,texture,color,gouraud,mode,dir,option) -> Check the Manual for further values, but sharing here some
* plane = [Single_Plane | Dual_Plane] -> You will see if both sides are seen or not
* sort = [SORT_MIN, SORT_CEN, SORT_MAX, SORT_BFR] -> Change them to make sure you understand the Z positioing depending on this
* texture = No_Texture (check example S_7_4)
* color = You can change the RGB values for example
* gouraud = No_Gouraud (it is just a plane, we will apply this for 3D polygon in S_7_6)
* mode = MESHoff (is a normal display), we already played also with values like `Window_In` and `Window_Out` in the example S_4_5 about clipping
* dir = sprPolygon (we may explore later other values in other examples)
* option = We already checked options in S_3_2 like UseLight for lightining effects
* 
*/
ATTR attribute_PLANE[] = {
	ATTRIBUTE(Single_Plane,SORT_CEN,No_Texture,C_RGB(31,31,0),No_Gouraud,MESHoff,sprPolygon,No_Option),
};

PDATA PD_PLANE = {
	point_PLANE , sizeof(point_PLANE)/sizeof(POINT) ,
	polygon_PLANE , sizeof(polygon_PLANE)/sizeof(POLYGON) ,
	attribute_PLANE
};