/*----------------------------------------------------------------------*/
/*	Parallel translation of 1 Polygon along the X-Axis			*/
/*----------------------------------------------------------------------*/

#include "sgl.h";

#define POS_Z 50.0

extern PDATA PD_PLANE1;

/**
 * This is the example of a shift of a polygon around the X-Axis
*/
int main(void) {

    /* Position and angle definitios for the polygon */
    static ANGLE ang[XYZ];
    static FIXED pos[XYZ];
    static ANGLE tmp = DEGtoANG(0.0);

    slInitSystem(TV_320x224, NULL, 1);
    slPrint("Sample program 4.3.3", slLocate(9,2));

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
            tmp += DEGtoANG(5.0);
            pos[X] = slMulFX(toFIXED(POS_Z), slSin(tmp)); // Multiply against the Sin of a increasing angle so there fore -1 to 1
            // Debug info
            slPrint("pos[X]:", slLocate(4,7));
			slPrintFX(pos[X], slLocate(8,7));
            // End debug info
            slPutPolygon(&PD_PLANE1);
        }
        slPopMatrix();
        slSynch();
    }
}