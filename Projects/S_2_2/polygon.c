#include "sgl.h"

/*

The polygon described in this example:

        v1      v2
        +-------+
        |       |
        |       |
        |       |
        +-------+
        v4      v3

*/

POINT point_PLANE1[] = {
        POStoFIXED(-10.0, -10.0, 0.0), /* position 0 holds the v1 vertice, X=-10, Y=-10, Z=0 */
        POStoFIXED( 10.0, -10.0, 0.0), /* position 1 holds the v2 vertice, X=10, Y=-10, Z=0 */
        POStoFIXED( 10.0,  10.0, 0.0), /* position 2 holds the v3 vertice, X=10, Y=10, Z=0 */
        POStoFIXED(-10.0,  10.0, 0.0), /* position 3 holds the v4 vertice, X=-10, Y=10, Z=0 */
};

POLYGON polygon_PLANE1[] = {
        NORMAL(0.0, 1.0, 0.0), VERTICES(0, 1, 2, 3), // Polygon face is indicated by its normal vertex
};

ATTR attribute_PLANE1[] = {
        ATTRIBUTE(Dual_Plane, SORT_CEN, No_Texture, C_RGB(31, 31, 31), No_Gouraud, MESHoff, sprPolygon, No_Option), // Attributes of the polygon, no textures and nothing exotic, first demo
};

PDATA PD_PLANE1 = {
        point_PLANE1, sizeof(point_PLANE1) / sizeof(POINT),
        polygon_PLANE1, sizeof(polygon_PLANE1) / sizeof(POLYGON),
        attribute_PLANE1
};
