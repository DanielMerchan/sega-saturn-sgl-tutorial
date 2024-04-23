#include "sgl.h"

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
POINT point_CUBE[] = {
	POStoFIXED(-10.0, -10.0,  10.0), /* Array position 0 -> Corresponds with v0 */
	POStoFIXED( 10.0, -10.0,  10.0), /* Array position 1 -> Corresponds with v1 */
	POStoFIXED( 10.0,  10.0,  10.0), /* Array position 2 -> Corresponds with v2 */
	POStoFIXED(-10.0,  10.0,  10.0), /* Array position 3 -> Corresponds with v3 */
	POStoFIXED(-10.0, -10.0, -10.0), /* Array position 4 -> Corresponds with v5*/
	POStoFIXED( 10.0, -10.0, -10.0), /* Array position 5 -> Corresponds with v4*/
	POStoFIXED( 10.0,  10.0, -10.0), /* Array position 6 -> Corresponds with v7*/
	POStoFIXED(-10.0,  10.0, -10.0), /* Array position 7 -> Corresponds with v6 */
};


POLYGON polygon_CUBE[] = {
	NORMAL(0.0, 0.0, 1.0), VERTICES(0,1,2,3), /* Face v0, v1, v2, v3 -> Normal +Z */
	NORMAL(-1.0, 0.0, 0.0), VERTICES(4,0,3,7), /* Face v5, v0, v3, v6 -> Normal -X */
	NORMAL(0.0, 0.0,-1.0), VERTICES(5,4,7,6), /* Face v4, v5, v6, v7 -> Normal -Z */
	NORMAL(1.0, 0.0, 0.0), VERTICES(1,5,6,2), /* Face v1, v4, v7, v2 -> Normal +X */
	NORMAL(0.0, 1.0, 0.0), VERTICES(4,5,1,0), /* Face v5, v4, v1, v0 -> Normal +Y <- CORRECTED FROM DOCUMENTATION */
	NORMAL(0.0, -1.0, 0.0), VERTICES(3,2,6,7), /* Face v3, v2, v7, v6 -> Normal -Y <- CORRECTED FROM DOCUMENTATION */
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

