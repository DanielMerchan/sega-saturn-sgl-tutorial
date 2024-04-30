
#include "sgl.h"

#define PN_SONIC 0 // This macro value corresponds to the Sonic Logo texture defined in texture.c in PICDEF, the texno (Texture Number)
#define PN_AM2 1 // This macro value corresponds to the AM2 Logo texture defined in texture.c in PICDEF, the texno (Texture Number)

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
	POStoFIXED(-40.0, -40.0, 0.0), /* Array position 0 -> Corresponds to v0  */
	POStoFIXED( 40.0, -40.0, 0.0), /* Array position 1 -> Corresponds to v1  */
	POStoFIXED( 40.0,  40.0, 0.0), /* Array position 2 -> Corresponds to v2  */
	POStoFIXED(-40.0,  40.0, 0.0), /* Array position 3 -> Corresponds to v3  */
};

POLYGON polygon_PLANE[] = {
	NORMAL(0.0,0.0,1.0), VERTICES(0,1,2,3), /* The only plan has face v0, v1, v2, v3 -> Normal +Z*/
};

/*
* ATTRIBUTE(plane,sort,texture,color,gouraud,mode,dir,option) -> Check the Manual for further values, but sharing here some
* plane = [Single_Plane | Dual_Plane] -> You will see if both sides are seen or not
* sort = [SORT_MIN, SORT_CEN, SORT_MAX, SORT_BFR] -> Change them to make sure you understand the Z positioing depending on this
* texture = PN_SONIC or PN_AM2 depending on which texture we wanna map to the plane (these macros are defined above)
* color = No_Palet as we are  making a texture mapping over the plane
* gouraud = No_Gouraud (it is just a plane, we will apply this for 3D polygon in S_7_6)
* mode = CL32KRGB|MESHoff (32k RGB colors mode and Normal display)
* dir = sprNoFlip indicates we are displaying the texture normally
* option = No_Option as we are not applying lighning for example
* 
*/
ATTR attribute_PLANE[] = {
	ATTRIBUTE(Single_Plane,SORT_CEN,PN_SONIC,No_Palet,No_Gouraud,CL32KRGB|MESHoff,sprNoflip,No_Option),
};

PDATA PD_PLANE = {
	point_PLANE , sizeof(point_PLANE)/sizeof(POINT) ,
	polygon_PLANE , sizeof(polygon_PLANE)/sizeof(POLYGON) ,
	attribute_PLANE
};