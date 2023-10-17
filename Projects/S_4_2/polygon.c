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

static POINT point_CUBE[]={
	POStoFIXED(-15.0, -15.0,  15.0), /* Array position 0 holds v0 */
	POStoFIXED( 15.0, -15.0,  15.0), /* Array position 1 holds v1 */
	POStoFIXED( 15.0,  15.0,  15.0), /* Array position 2 holds v2 */
	POStoFIXED(-15.0,  15.0,  15.0), /* Array position 3 holds v3 */
	POStoFIXED(-15.0, -15.0, -15.0), /* Array position 4 holds v5 */
	POStoFIXED( 15.0, -15.0, -15.0), /* Array position 5 holds v4 */
	POStoFIXED( 15.0,  15.0, -15.0), /* Array position 6 holds v7 */
	POStoFIXED(-15.0,  15.0, -15.0), /* Array position 7 holds v6 */
};

static POLYGON polygon_CUBE[]={
		NORMAL( 0.0, 0.0, 1.0), VERTICES(0,1,2,3), /* Face v0, v1, v2, v3 -> Normal +Z */
		NORMAL(-1.0, 0.0, 0.0), VERTICES(4,0,3,7), /* Face v5, v0, v3, v6 -> Normal -X */
		NORMAL( 0.0, 0.0,-1.0), VERTICES(5,4,7,6), /* Face v4, v5, v6, v7 -> Normal -Z */
		NORMAL( 1.0, 0.0, 0.0), VERTICES(1,5,6,2), /* Face v1, v4, v7, v2 -> Normal +X */
		NORMAL( 0.0,-1.0, 0.0), VERTICES(4,5,1,0), /* Face v5, v4, v1, v0 -> Normal -Y */
		NORMAL( 0.0, 1.0, 0.0), VERTICES(3,2,6,7), /* Face v3, v2, v7, v6 -> Normal +Y */
	};

static ATTR attribute_CUBE[]={
	ATTRIBUTE(Single_Plane,SORT_MIN,No_Texture,C_RGB(0,20,28),No_Gouraud,MESHoff,sprPolygon,UseLight),
	ATTRIBUTE(Single_Plane,SORT_MIN,No_Texture,C_RGB(28,8,0),No_Gouraud,MESHoff,sprPolygon,UseLight),
	ATTRIBUTE(Single_Plane,SORT_MIN,No_Texture,C_RGB(8,28,0),No_Gouraud,MESHoff,sprPolygon,UseLight),
	ATTRIBUTE(Single_Plane,SORT_MIN,No_Texture,C_RGB(28,20,0),No_Gouraud,MESHoff,sprPolygon,UseLight),
	ATTRIBUTE(Single_Plane,SORT_MIN,No_Texture,C_RGB(16,0,28),No_Gouraud,MESHoff,sprPolygon,UseLight),
	ATTRIBUTE(Single_Plane,SORT_MIN,No_Texture,C_RGB(28,20,16),No_Gouraud,MESHoff,sprPolygon,UseLight),
};

PDATA PD_CUBE = {
	point_CUBE,sizeof(point_CUBE)/sizeof(POINT),
	polygon_CUBE,sizeof(polygon_CUBE)/sizeof(POLYGON),
	attribute_CUBE
};

