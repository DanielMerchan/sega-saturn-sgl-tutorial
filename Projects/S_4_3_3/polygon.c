#include	"sgl.h"

/**
 * Polygon
 * 
        v1      v2
        +-------+
        |       |
        |       |
        |       |
        +-------+
        v4      v3
*/
POINT point_PLANE1[] = {
        POStoFIXED(-10.0,-10.0, 0.0), /* Array position 0 holds v1 */
        POStoFIXED( 10.0,-10.0, 0.0), /* Array position 1 holds v2 */
        POStoFIXED( 10.0, 10.0, 0.0), /* Array position 2 holds v3 */
        POStoFIXED(-10.0, 10.0, 0.0), /* Array position 0 holds v4 */
};

POLYGON polygon_PLANE1[] = {
        NORMAL(0.0,0.0,1.0), VERTICES(0,1,2,3), /* Face v1, v2, v3, v4 -> Normal +Z */ 
};

ATTR attribute_PLANE1[] = {
        ATTRIBUTE(Dual_Plane,SORT_CEN,No_Texture,C_RGB(31,31,31),No_Gouraud,MESHoff,sprPolygon,No_Option),
};

PDATA PD_PLANE1 = {
        point_PLANE1,sizeof(point_PLANE1)/sizeof(POINT),
        polygon_PLANE1,sizeof(polygon_PLANE1)/sizeof(POLYGON),
        attribute_PLANE1
};
