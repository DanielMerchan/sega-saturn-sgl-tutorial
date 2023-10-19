/*----------------------------------------------------------------------*/
/*	Matrix Animation						*/
/*----------------------------------------------------------------------*/
#include "SGL.H"


/* Self defined constants for the default Tang and Aang to be applied */
const ANGLE DefaultAang = DEGtoANG(2.0);
const ANGLE DefaultTang = DEGtoANG(0.0);

/* Import of the 3 Polygons defined in polygon.c */
extern PDATA PD_PLANE1, PD_PLANE2, PD_PLANE3;


/*
    Auxiliar function to translate and to rotate on the current Matrix
*/
static void set_poly(ANGLE ang[XYZ], FIXED pos[XYZ]) {
    slTranslate(pos[X], pos[Y], pos[Z]);
    slRotX(ang[X]); slRotY(ang[Y]); slRotZ(ang[Z]);
}

/* Main videogame routine */
int main() {
    static ANGLE ang1[XYZ], ang2[XYZ], ang3[XYZ];
    static FIXED pos1[XYZ], pos2[XYZ], pos3[XYZ];
    static ANGLE tang, aang;

    slInitSystem(TV_320x224, NULL, 1);
    slPrint("Demo B matrices", slLocate(6,2));

    /* Initialise the angle to 0 degrees by using the macro conversion between Degrees to Angle in bytes */
    ang1[X] = ang2[X] = ang3[X] = DEGtoANG(0.0);
    ang1[Y] = ang2[Y] = ang3[Y] = DEGtoANG(0.0);
    ang1[Z] = ang2[Z] = ang3[Z] = DEGtoANG(0.0);

    /* Initial position for object 1 represented by PD_PLANE1. Blue one on bottom */
    pos1[X] = toFIXED(0.0); /* Position in X-Axis is 0 */
    pos1[Y] = toFIXED(40.0); /* Position in Y-Axis is 40*/
    pos1[Z] = toFIXED(170.0); /* Position in Z-Axis is 170 */

    /* Initial position for object 2 represented by PD_PLANE2. Yellow one in the middle */
    pos2[X] = toFIXED(0.0); /* Position in X-Axis is 0 */
    pos2[Y] = toFIXED(-40.0); /* Position in Y-Axis is -40 */
    pos2[Z] = toFIXED(0.0); /* Position in Z-Axis is 0 */

    /* Initial position for object 3 represented by PD_PLANE3. Hat in pink on the top */
    pos3[X] = toFIXED(0.0); /* Position in X-Axis is 0 */
    pos3[Y] = toFIXED(-40.0); /* Position in Y-Axis is -40 */
    pos3[Z] = toFIXED(0.0); /* Position in Z-Axis is 0 */

    tang = DefaultTang; /* DEGtoANG(0.0); */
    aang = DefaultAang; /* DEGtoANG(2.0); */

    /* Main game loop */
    while (-1) {
        slUnitMatrix(CURRENT); /* Changes the current matrix into a unit matrix. Resetting */
        ang1[Z] = ang2[Z] = tang; /* Angle of object 1 an object 2 in Z axis */
        tang +=aang; /* Increment the angle */
        if (tang < DEGtoANG(-90.0)) {
            aang = DefaultAang; /* DEGtoANG(2.0); */
        } else if (tang > DEGtoANG(90.0)) {
            aang = -DefaultAang; /* DEGtoANG(2.0); */
        }
        
        /*
            Object 1 rotates around its fulcrum -> Z Angle as changed in the code above
            Object 2 receives the matrix from 1 
            Object 2 rotates around its fulcrum -> Z Angle changed and inherited from first matrix
            Object 3 receives matrix from object 2
            Object 3 rotates around its fulcrum
        */
        slPushMatrix(); {
            set_poly(ang1, pos1);
            slPutPolygon(&PD_PLANE1);
            slPushMatrix(); {
                set_poly(ang2, pos2);
                slPutPolygon(&PD_PLANE2);
                slPushMatrix(); {
                    set_poly(ang3, pos3);
                    ang3[Y] += DEGtoANG(5.0);
                    slPutPolygon(&PD_PLANE3);
                }
                slPopMatrix();
            }
            slPopMatrix();
        }
        slPopMatrix();
        slSynch();
    }
}