/*----------------------------------------------------------------------*/
/*	Cube Action							*/
/*----------------------------------------------------------------------*/
#include "sgl.h";

#define REFLECT_EXTENT                                              \
    toFIXED(85.0) /* Collision point as internal cube is 15 on each \
                     coordinate*/
#define XSPD toFIXED(1.5)
#define YSPD toFIXED(2.0)
#define ZSPD toFIXED(3.0)
#define XAPD DEGtoANG(3.0)
#define YAPD DEGtoANG(5.0)
#define ZAPD DEGtoANG(3.0)

extern PDATA PD_PLANE1, PD_PLANE2;

/**
 * Exercise to put in practice the concepts learn in S_2_2 to S_4_5
 * Corresponds to Chapters 2, 3 and 4
 */
int main(void) {
    static ANGLE ang1[XYZ], ang2[XYZ];
    static FIXED pos1[XYZ], pos2[XYZ], delta[XYZ], light[XYZ];

    /* 1. Initialize the system */
    slInitSystem(TV_320x224, NULL, 1);
    slPrint("Demo A", slLocate(9, 2));

    /* 2. Set initial object angle */
    ang1[X] = ang1[Y] = ang1[Z] = DEGtoANG(0.0);
    ang2[X] = ang2[Y] = ang2[Z] = DEGtoANG(0.0);

    /* 3. Set initial object positions */
    pos1[X] = pos2[X] = toFIXED(0.0);
    pos1[Y] = pos2[Y] = toFIXED(0.0);
    pos1[Z] = pos2[Z] = toFIXED(100.0);

    /* 4. Delta initialization */
    delta[X] = XSPD, delta[Y] = YSPD, delta[Z] = ZSPD;

    /* 5. Light vector intialization */
    light[X] = slSin(DEGtoANG(30.0));  /* Sin 30 degrees = 0.5 */
    light[Y] = slCos(DEGtoANG(30.0));  /* Cos 30 degrees = 0.86 */
    light[Z] = slSin(DEGtoANG(-30.0)); /* Sin -30 degrees = -0.5 */

    /* 6. Main game loop */
    while (-1) {
        /* 7. Positioning the light vector */
        slLight(light);

        /* 8. Place small cube, object 1 */
        slPushMatrix();
        {
            /* Shift the object*/
            slTranslate(pos1[X], pos1[Y], pos1[Z] + toFIXED(270.0));

            /* Shift movement change using the delta values*/
            pos1[X] += delta[X];
            pos1[Y] += delta[Y];
            pos1[Z] += delta[Z];

            /* Collision detection for correction */
            if (pos1[X] > REFLECT_EXTENT) {
                delta[X] = -XSPD, pos1[X] -= XSPD;
            } else if (pos1[X] < -REFLECT_EXTENT) {
                delta[X] = XSPD, pos1[X] += XSPD;
            }

            if (pos1[Y] > REFLECT_EXTENT) {
                delta[Y] = -YSPD, pos1[Y] -= YSPD;
            } else if (pos1[Y] < -REFLECT_EXTENT) {
                delta[Y] = YSPD, pos1[Y] += YSPD;
            }

            if (pos1[Z] > REFLECT_EXTENT) {
                delta[Z] = -ZSPD, pos1[Z] -= ZSPD;
            } else if (pos1[Z] < -REFLECT_EXTENT) {
                delta[Z] = ZSPD, pos1[Z] += ZSPD;
            }

            /* Set object angle */
            slRotX(ang1[X]);
            slRotY(ang1[Y]);
            slRotZ(ang1[Z]);

            /* Modify its angle for the next iterations */
            ang1[X] += XAPD;
            ang1[Y] += YAPD;
            ang1[Z] += ZAPD;

            /* Place the polygon in the screen */
            slPutPolygon(&PD_PLANE1);
        }
        slPopMatrix();

        /* 9. Place big cube, object 2 */
        slPushMatrix();
        {
            /* Shift / Translate the object 2 which is the big cube */
            slTranslate(pos2[X], pos2[Y], pos2[Z] + toFIXED(170.0));

            /* Rotation of the object 2 */
            slRotX(ang2[X]);
            slRotY(ang2[Y]);
            slRotZ(ang2[Z]);

            /* Place the second polygon in screen */
            slPutPolygon(&PD_PLANE2);
        }
        slPopMatrix();

        /* Draw frames */
        slSynch();
    }
}