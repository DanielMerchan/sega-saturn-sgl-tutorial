/*----------------------------------------------------------------------*/
/*	Gouraud Shading							*/
/*----------------------------------------------------------------------*/
#include	"sgl.h"

extern PDATA PD_CUBE;


/* Definition of the Gouraud table */

#define	GRoffsetTBL(r,g,b) (((b & 0x1f) << 10) | ((g & 0x1f) << 5) | (r & 0x1f)) // Helper macro to define the intensity of the colouring shading
#define	VRAMaddr (SpriteVRAM+0x70000) // (0x25c70000) Accoridng to documentation, Gouraud shading table needs to be stored in VDP1 VRAM very near to the end and beginning of VDP2 VRAM.

static Uint16 GRdata[6][4] = {
	{ GRoffsetTBL(  0,-16,-16) , GRoffsetTBL(  0,-16,-16) ,
	  GRoffsetTBL(  0,-16,-16) , GRoffsetTBL(-16, 15,  0) } , 
	{ GRoffsetTBL(  0,-16,-16) , GRoffsetTBL(  0,-16,-16) ,
	  GRoffsetTBL(-16, 15,  0) , GRoffsetTBL(  0,-16,-16) } , 
	{ GRoffsetTBL(-16, 15,  0) , GRoffsetTBL(  0,-16,-16) ,
	  GRoffsetTBL(  0,-16,-16) , GRoffsetTBL(  0,-16,-16) } , 
	{ GRoffsetTBL(  0,-16,-16) , GRoffsetTBL(-16, 15,  0) ,
	  GRoffsetTBL(  0,-16,-16) , GRoffsetTBL(  0,-16,-16) } , 
	{ GRoffsetTBL(  0,-16,-16) , GRoffsetTBL(-16, 15,  0) ,
	  GRoffsetTBL(  0,-16,-16) , GRoffsetTBL(  0,-16,-16) } , 
	{ GRoffsetTBL(-16, 15,  0) , GRoffsetTBL(  0,-16,-16) , 
	  GRoffsetTBL(  0,-16,-16) , GRoffsetTBL(  0,-16,-16) } 
};

/**
 * Auxiliar routine for displaying the plane and making the code more readable in the main loop
*/
void display_polygon(FIXED pos[XYZ], ANGLE ang[XYZ], PDATA polygon) {
    slPushMatrix(); {
        slTranslate(pos[X], pos[Y], pos[Z]);
        slRotX(ang[X]);
        slRotY(ang[Y]);
        slRotZ(ang[Z]);
        slPutPolygon(&polygon);
    }
    slPopMatrix();
}

/* Main videogame routine */
int main() {
    static ANGLE ang[XYZ];
	static FIXED pos[XYZ];

    /* 1. System initialized, NULL as no textures will be used */
	slInitSystem(TV_320x224,NULL,1);
	slPrint("Sample program 7.6" , slLocate(9,2));

	ang[X] = DEGtoANG(30.0);
	ang[Y] = DEGtoANG( 0.0);
	ang[Z] = DEGtoANG( 0.0);
	pos[X] = toFIXED( 0.0);
	pos[Y] = toFIXED( 0.0);
	pos[Z] = toFIXED(200.0);

    /* Load gouraud table into VRAM address */
	slDMACopy(GRdata,(void *)VRAMaddr,sizeof(GRdata));

    /* Display cube and rotate it on its Y-Axis*/
	while(-1){
		display_polygon(pos,ang,PD_CUBE);
		ang[Y] += DEGtoANG(1.0);
		slSynch();
	}
}