/*----------------------------------------------------------------------*/
/*	Expansion and reduction of 1 Polygon (X-Axis and Y-Axis)		*/
/*----------------------------------------------------------------------*/

#include "sgl.h";

#define POS_Z 50.0

extern PDATA PD_PLANE1;

/**
 * This is the example of how to use slScale to enlarge or reduce a polygon around certain axis
*/
int main(void) {

    /* Position and angle definitios for the polygon */
    static ANGLE ang[XYZ];
    static FIXED pos[XYZ];
    static FIXED sclx, scly, sclz, tmp = toFIXED(0.0); // Define the ratio of Scaling
    static Sint16 flag = 1;

    slInitSystem(TV_320x224, NULL, 1);
    slPrint("Sample program 4.3.4", slLocate(9,2));

    ang[X] = ang[Y] = ang[Z] = DEGtoANG(0.0);
    pos[X] = pos[Y] = toFIXED(0.0);
    pos[Z] = toFIXED(220.0);
    sclx = scly = sclz = toFIXED(1.0); // Initial ratio scale

    /* Main game loop */
    while (-1) {
        slPushMatrix(); {
            slTranslate(pos[X], pos[Y], pos[Z]);
            slRotX(ang[X]);
            slRotY(ang[Y]);
            slRotZ(ang[Z]);
            if (flag == 1) tmp += toFIXED(0.1);
            else tmp -= toFIXED(0.1);
            if (tmp > toFIXED(1.0)) flag = 0;
            if (tmp < toFIXED(-1.0)) flag = 1;
            /*
            * scale < 0.0 -> Mirror image
            * scale = 0.0 -> Disapears
            * 0.0 < scale < 1.0 Reduced
            * scale = 1.0 Unchanged
            * 1.0 < scale Enlarged
            */
            slScale(sclx+tmp, scly-tmp, sclz);
            slPutPolygon(&PD_PLANE1);
        }
        slPopMatrix();
        slSynch();
    }
}