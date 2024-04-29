/*----------------------------------------------------------------------*/
/*	Rotation of Single Plane Polygon				*/
/*----------------------------------------------------------------------*/
#include "SGL.H"

extern PDATA PD_PLANE;

void display_plane(FIXED pos[XYZ], ANGLE ang[XYZ]) {
    slPushMatrix(); {
        slTranslate(pos[X], pos[Y], pos[Z]);
        slRotX(ang[X]);
        slRotY(ang[Y]);
        slRotZ(ang[Z]);
        slPutPolygon(&PD_PLANE);
    }
    slPopMatrix();
}

/* Main videogame routine */
int main() {

    static ANGLE ang[XYZ];
    static FIXED pos[XYZ];

    /* 1. System initialization */
    slInitSystem(TV_320x224, NULL, 1);
    slPrint("Sample program 7.2", slLocate(6,2));

    /**
     * Initial angle is 0, so we are not rotating the plane
    */
    ang[X] = ang[Y] = ang[Z] = DEGtoANG(0.0);

    /**
     * Initial position is X=0, Y=0 and Z=170 (mid distance form the maximum deep of the screen)
    */
    pos[X] = toFIXED(0.0);
    pos[Y] = toFIXED(0.0);
    pos[Z] = toFIXED(170.0);

    while (-1) {
        display_plane(pos,ang);
        ang[Y] += DEGtoANG(2.0);
        slSynch();
    }
    
}