/*----------------------------------------------------------------------*/
/*	Double Cube Circle Action */
/*----------------------------------------------------------------------*/
#include "sgl.h"

#define DISTANCE_R1 40
#define DISTANCE_R2 40

extern PDATA PD_CUBE;

/* Auxiliar function to position the polygon */
static void set_polygon(ANGLE ang[XYZ], FIXED pos[XYZ]) {
    slTranslate(pos[X], pos[Y], pos[Z]);
    slRotX(ang[X]);
    slRotY(ang[Y]);
    slRotZ(ang[Z]);
}

int main(void) {
    static ANGLE ang1[XYZ], ang2[XYZ];
    static FIXED pos1[XYZ], pos2[XYZ];
    static ANGLE tmp = DEGtoANG(0.0);

    slInitSystem(TV_320x224, NULL, 1);
    slPrint("Sample program 5.2", slLocate(6, 2));

    ang1[X] = ang2[X] = DEGtoANG(30.0);
    ang1[Y] = ang2[Y] = DEGtoANG(45.0);
    ang1[Z] = ang2[Z] = DEGtoANG(0.0);

    pos2[X] = toFIXED(DISTANCE_R2);
    pos2[Y] = toFIXED(0.0);
    pos2[Z] = toFIXED(0.0);
    while (-1) {
        slUnitMatrix(CURRENT); /* Changes the current matrix into a unit matrix */
        
        /* Draws the first (parent) cube */
        slPushMatrix(); {
            pos1[X] = DISTANCE_R1 * slSin(tmp);
            pos1[Y] = toFIXED(30.0);
            pos1[Z] = toFIXED(220.0) + DISTANCE_R1 * slCos(tmp);
            set_polygon(ang1, pos1);
            slPutPolygon(&PD_CUBE);
            /* Draws the second (child) cube*/
            slPushMatrix(); {
                set_polygon(ang2, pos2);
                slPutPolygon(&PD_CUBE);
            }
            /* Both cubes positioned with a distance between them */
            slPopMatrix();
        }
        /* Both cubes get moved in position and rotated */
        slPopMatrix();

        // Reset display angle and position
        ang1[Y] += DEGtoANG(1.0);
        ang2[Y] -= DEGtoANG(1.0);
        // Make to rotate
        tmp += DEGtoANG(1.0);
        slSynch();
    }
}