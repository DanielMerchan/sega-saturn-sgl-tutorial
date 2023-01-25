#include	"sgl.h"

/* Excercise: Fig 2-6 Drawing Model Based on Parameters in List 2-3 */

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

POINT point_PLANE1[] = {
        POStoFIXED(-15.0, -15.0, -15.0), /* Array position 0 holds v5 */
        POStoFIXED(-15.0, -15.0,  15.0), /* Array position 1 holds v0 */
        POStoFIXED(-15.0,  15.0, -15.0), /* Array position 2 holds v6 */
        POStoFIXED(-15.0,  15.0,  15.0), /* Array position 3 holds v3 */
        POStoFIXED( 15.0, -15.0, -15.0), /* Array position 4 holds v4 */
        POStoFIXED( 15.0, -15.0,  15.0), /* Array position 5 holds v1 */
        POStoFIXED( 15.0,  15.0, -15.0), /* Array position 6 holds v7 */
        POStoFIXED( 15.0,  15.0,  15.0), /* Array position 7 holds v2 */
};

POLYGON polygon_PLANE1[] = {
        NORMAL(-1.0,  0.0,  0.0), VERTICES(0, 1, 3, 2), /* Face v5, v0, v3, v6 -> Normal -X */ 
        NORMAL( 0.0,  0.0,  1.0), VERTICES(1, 5, 7, 3), /* Face v0, v1, v2, v3 -> Normal +Z */
        NORMAL( 1.0,  0.0,  0.0), VERTICES(5, 4, 6, 7), /* Face v1, v4, v7, v2 -> Normal +X */
        NORMAL( 0.0,  0.0, -1.0), VERTICES(4, 0, 2, 6), /* Face v4, v5, v6, v7 -> Normal -Z */
        NORMAL( 0.0, -1.0,  0.0), VERTICES(4, 5, 1, 0), /* Face v4, v1, v0, v5 -> Normal -Y */
        NORMAL( 0.0,  1.0,  0.0), VERTICES(2, 3, 7, 6), /* Face v6, v3, v2, v7 -> Normal +Y */
};

ATTR attribute_PLANE1[] = {
        ATTRIBUTE(Dual_Plane,SORT_CEN,No_Texture,C_RGB(31,31,00),No_Gouraud,MESHoff,sprPolygon,UseLight),
        ATTRIBUTE(Dual_Plane,SORT_CEN,No_Texture,C_RGB(31,00,00),No_Gouraud,MESHoff,sprPolygon,UseLight),
        ATTRIBUTE(Dual_Plane,SORT_CEN,No_Texture,C_RGB(00,31,00),No_Gouraud,MESHoff,sprPolygon,UseLight),
        ATTRIBUTE(Dual_Plane,SORT_CEN,No_Texture,C_RGB(00,00,31),No_Gouraud,MESHoff,sprPolygon,UseLight),
        ATTRIBUTE(Dual_Plane,SORT_CEN,No_Texture,C_RGB(31,00,31),No_Gouraud,MESHoff,sprPolygon,UseLight),
        ATTRIBUTE(Dual_Plane,SORT_CEN,No_Texture,C_RGB(00,31,31),No_Gouraud,MESHoff,sprPolygon,UseLight),
};

PDATA PD_PLANE1 = {
        point_PLANE1,sizeof(point_PLANE1)/sizeof(POINT),
        polygon_PLANE1,sizeof(polygon_PLANE1)/sizeof(POLYGON),
        attribute_PLANE1
};
