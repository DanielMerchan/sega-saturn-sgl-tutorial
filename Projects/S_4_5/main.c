/*----------------------------------------------------------------------*/
/*	Expansion and reduction of 1 Polygon (X-Axis and Y-Axis)		*/
/*----------------------------------------------------------------------*/

/*----------------------------------------------------------------------*/
/*	Window & Clipping						*/
/*----------------------------------------------------------------------*/
#include "sgl.h";

#define Zlimit 150
#define CENTER_X 160
#define CENTER_Y 112

extern PDATA PD_PLANE, PD_CUBE;

/**
 * This demo demonstrate the concept of Clipping and Windows.
 * The example will show partially one of the polygons in the outer window as part of it will be projected out of it. 
 * This is known as clipping
*/
int main(void) {
    static ANGLE ang1[XYZ], ang2[XYZ]; /* Angle transformation */
    static FIXED pos1[XYZ], pos2[XYZ]; /* Position of the polygons */
    static Sint16 left = 130, top = 30, right = 190, bottom = 80; /* Position of the window */
    static Sint16 v_move=1, h_move=1;

    slInitSystem(TV_320x224, NULL, 1);
    slPrint("Sample program 4.5", slLocate(9,2));

    ang1[X] = ang1[Y] = ang1[Z] = DEGtoANG(0.0);
    ang2[X] = DEGtoANG(30.0);
    ang2[Y] = ang2[Z] = DEGtoANG(0.0);
    pos1[X] = pos2[X] = toFIXED(0.0);
    pos1[Y] = pos2[Y] = toFIXED(0.0);
    pos1[Z] = pos2[Z] = toFIXED(190.0);

    /* Main game loop */
    while (-1) {

        /* Move the window*/
        left += v_move;
        top += h_move;
        right += v_move;
        bottom += h_move;

        /* Reset window when reaching the borders */
        if (left == 0) v_move = 1;
		if (top == 0) h_move = 1;
		if (right == 319) v_move = -1;
		if (bottom == 223) h_move = -1;

        /* Window definition */
        slWindow(left, top, right, bottom, Zlimit, CENTER_X, CENTER_Y); 

        /* We project the plane ourside of the window.
         * In the polygon.c the PD_PLANE is set to be rendered in the Window_Out 
        */
        slPushMatrix(); {
            slTranslate(pos1[X], pos1[Y], pos1[Z]);
            slRotX(ang1[X]);
            slRotY(ang1[Y]);
            slRotZ(ang1[Z]);
            slPutPolygon(&PD_PLANE);
        }
        slPopMatrix();

        /* We project the cube inside of the window 
         * In the polygon.c the PD_CUBE is set to be rendered in the Window_In
        */
        slPushMatrix(); {
            slTranslate(pos1[X], pos1[Y], pos1[Z]);
            slRotX(ang2[X]);
            slRotY(ang2[Y]);
            slRotZ(ang2[Z]);
            slPutPolygon(&PD_CUBE);
        }
        slPopMatrix();

        /* We rotate the cube in the Y-Axis */
        ang2[Y] += DEGtoANG(1.0); 

        /* Render the frame*/
        slSynch();

        /* Result: The window will be moving (Window_In)*/
    }
   
}