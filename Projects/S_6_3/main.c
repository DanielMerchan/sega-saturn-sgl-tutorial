/*----------------------------------------------------------------------*/
/*	Camera Movemenent					                                */
/*----------------------------------------------------------------------*/
#include "SGL.H"

#define POS_Z 100.0

typedef struct cam {
	FIXED pos[XYZ];
	FIXED target[XYZ];
	ANGLE ang[XYZ];
} CAMERA;

extern PDATA PD_CUBE;

static FIXED cubepos[][3] = {
	POStoFIXED(20, 0, 270) ,
	POStoFIXED(-70, 0, 270) ,
	POStoFIXED( 40, 0, 350) ,
	POStoFIXED(-60, 0, 370)
};

void display_cube(FIXED pos[XYZ]) {
    slPushMatrix(); {
        slTranslate(pos[X], pos[Y], pos[Z]);
        slPutPolygon(&PD_CUBE);
    }
    slPopMatrix();
}

/* Main videogame routine */
int main() {

    static ANGLE ang[XYZ];
    static CAMERA cmbuf;
    static ANGLE tmp = DEGtoANG(0.0);

    /* 1. System initialization */
    slInitSystem(TV_320x224, NULL, 1);
    slPrint("Sample program 6.3", slLocate(9,2));

    /* 2. Set initial camera settings */
    /* Initial angle of the camera */
    cmbuf.ang[X] = cmbuf.ang[Y] = cmbuf.ang[Z] = DEGtoANG(0.0);
    /* To where it looks defined by Target */
    cmbuf.target[X] = cmbuf.target[Y] = toFIXED(0.0);
    cmbuf.target[Z] = toFIXED(320.0);
    /* Initial position of the camera is in (0,-20,0) */
    cmbuf.pos[X] = cmbuf.pos[Z] = toFIXED(0.0);
    cmbuf.pos[Y] = toFIXED(-20.0);

    while (-1) {
        /* Load the unit matrix for making sure slLookAt will multiply against it */
        slUnitMatrix(CURRENT);
        /* Routine for setting up the camera */
        slLookAt(cmbuf.pos, cmbuf.target, cmbuf.ang[Z]);
        tmp += DEGtoANG(2.0);
        /* Reposition of the camera each iteration between -100 and 100 on the X and Z axis*/
        cmbuf.pos[X] = POS_Z * slCos(tmp);
        cmbuf.pos[Z] = POS_Z * slSin(tmp);
        /* Debug the camera positioning changing */
        
        slPrint("cmbuf.pos[X] ", slLocate(4,5));
		slPrintFX(cmbuf.pos[X], slLocate(19,5));
        slPrint("cmbuf.pos[Z] ", slLocate(4,6));
		slPrintFX(cmbuf.pos[Z], slLocate(19,6));
        display_cube(cubepos[0]);
        display_cube(cubepos[1]);
        display_cube(cubepos[2]);
        display_cube(cubepos[3]);

        slSynch();
    }

}