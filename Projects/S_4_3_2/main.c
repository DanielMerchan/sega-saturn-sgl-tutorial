/*----------------------------------------------------------------------*/
/*	Rotation of 1 Polygon [Y axis]					*/
/*----------------------------------------------------------------------*/

#include "sgl.h";

extern PDATA PD_PLANE1;

/**
 * This is the example of a Two Axis rotation of a polygon around the X-Axis and the Y-Axis
*/
int main(void) {

    /* Position and angle definitios for the polygon */
    static ANGLE ang[XYZ];
    static FIXED pos[XYZ];

    slInitSystem(TV_320x224, NULL, 1);
    slPrint("Sample program 4.3.2", slLocate(9,2));

    ang[X] = ang[Y] = ang[Z] = DEGtoANG(0.0);
    pos[X] = pos[Y] = toFIXED(0.0);
    pos[Z] = toFIXED(220.0);

    /* Main game loop */
    while (-1) {
        slPushMatrix(); {
            slTranslate(pos[X], pos[Y], pos[Z]);
            slRotX(ang[X]);
            slRotY(ang[Y]);
            slRotZ(ang[Z]);
            ang[X] += DEGtoANG(4.0); // Increasing the angle of rotation over the X-Axis
            ang[Y] += DEGtoANG(2.0); // Increase the angle of rotation over the Y-Axis
            slPutPolygon(&PD_PLANE1);
        }
        slPopMatrix();
        slSynch();
    }
}