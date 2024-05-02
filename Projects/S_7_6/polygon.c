
#include "sgl.h"

#define	GRaddr 0xe000 // Defines the offset (base address for accessing the Gouraud shading data)

/*   
       v5       v4
       +--------+
      /|       /|
  v0 / |    v1/ |
    +--------+  |
    |  v6    |  |
    |  +-----|--+ v7
    | /      | /
    |/       |/
 v3 +--------+ v2

*/

static POINT point_CUBE[] = {
	POStoFIXED(-20.0, -20.0, 20.0), /* Array position 0 holds v0 */
	POStoFIXED( 20.0, -20.0, 20.0), /* Array position 1 holds v1 */
	POStoFIXED( 20.0, 20.0, 20.0),  /* Array position 2 holds v2 */
	POStoFIXED(-20.0, 20.0, 20.0),  /* Array position 3 holds v3 */
	POStoFIXED(-20.0, -20.0,-20.0), /* Array position 4 holds v5 */
	POStoFIXED( 20.0, -20.0,-20.0), /* Array position 5 holds v4 */
	POStoFIXED( 20.0, 20.0,-20.0),  /* Array position 6 holds v7 */
	POStoFIXED(-20.0, 20.0,-20.0)   /* Array position 7 holds v6 */
};

static POLYGON polygon_CUBE[] = {
	NORMAL(0.0, 0.0, 1.0), VERTICES(0,1,2,3),  /* Face v0, v1, v2, v3 -> Normal +Z */ 
	NORMAL(-1.0, 0.0, 0.0), VERTICES(4,0,3,7), /* Face v5, v0, v3, v6 -> Normal -X */
	NORMAL(0.0, 0.0,-1.0), VERTICES(5,4,7,6),  /* Face v4, v5, v6, v7 -> Normal -Z */
	NORMAL(1.0, 0.0, 0.0), VERTICES(1,5,6,2),  /* Face v1, v4, v7, v2 -> Normal +X */
	NORMAL(0.0, -1.0, 0.0), VERTICES(4,5,1,0), /* Face v5, v4, v1, v0 -> Normal +Y */
	NORMAL(0.0, 1.0, 0.0), VERTICES(3,2,6,7)   /* Face v3, v2, v7, v6 -> Normal -Y */
};

/*
* ATTRIBUTE(plane,sort,texture,color,gouraud,mode,dir,option) -> Check the Manual for further values, but sharing here some
* plane = [Single_Plane | Dual_Plane] -> You will see if both sides are seen or not
* sort = [SORT_MIN, SORT_CEN, SORT_MAX, SORT_BFR] -> Change them to make sure you understand the Z positioing depending on this
* texture = No_Texture applied in this example
* color = A direct RGB colour applied in each face of the polygon
* gouraud = Passing a memory address offset and incrementing by 1 to access each Gouraud shading configuration defined in `main.c`
* mode = MESHoff|CL_Gouraud (Normal display and Gouraud shading mode enabled)
* dir = sprPolygon indicates we are displaying the polygon normally
* option = No_Option as we are not applying lighning for example
* 
*/
static ATTR attribute_CUBE[] = {
	ATTRIBUTE(Single_Plane, SORT_MIN, No_Texture, C_RGB(31,16,31), GRaddr,   MESHoff|CL_Gouraud, sprPolygon,No_Option),
	ATTRIBUTE(Single_Plane, SORT_MIN, No_Texture, C_RGB(31,16,31), GRaddr+1, MESHoff|CL_Gouraud, sprPolygon,No_Option),
	ATTRIBUTE(Single_Plane, SORT_MIN, No_Texture, C_RGB(31,16,31), GRaddr+2, MESHoff|CL_Gouraud, sprPolygon,No_Option),
	ATTRIBUTE(Single_Plane, SORT_MIN, No_Texture, C_RGB(31,16,31), GRaddr+3, MESHoff|CL_Gouraud, sprPolygon,No_Option),
	ATTRIBUTE(Single_Plane, SORT_MIN, No_Texture, C_RGB(31,16,31), GRaddr+4, MESHoff|CL_Gouraud, sprPolygon,No_Option),
	ATTRIBUTE(Single_Plane, SORT_MIN, No_Texture, C_RGB(31,16,31), GRaddr+5, MESHoff|CL_Gouraud, sprPolygon,No_Option),
};

PDATA PD_CUBE = {
	point_CUBE , sizeof(point_CUBE)/sizeof(POINT),
	polygon_CUBE , sizeof(polygon_CUBE)/sizeof(POLYGON) ,
	attribute_CUBE
};
