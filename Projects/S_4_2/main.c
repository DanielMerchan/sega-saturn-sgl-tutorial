/*----------------------------------------------------------------------*/
/*	Perspective Control						*/
/*----------------------------------------------------------------------*/
#include "SGL.H"

extern PDATA PD_CUBE;

int main (void) {
    static ANGLE ang[XYZ];
	static ANGLE angper[XYZ];
	static FIXED pos[XYZ];
	static ANGLE tmp = DEGtoANG(90.0);
	static ANGLE adang = DEGtoANG(0.5);

	slInitSystem(TV_320x224,NULL,1);
	slPrint("Sample program 4.2" , slLocate(6,2));

	ang[X] = DEGtoANG(30.0);
	ang[Y] = DEGtoANG(45.0);
	ang[Z] = DEGtoANG( 0.0);
	pos[X] = toFIXED(0.0);
	pos[Y] = toFIXED(0.0);
	pos[Z] = toFIXED(20.0);

	slPrint("Perspective : " , slLocate(4,5));
	while(-1) {
		slPerspective(tmp); // Perspective transformation table setting
		slPrintHex(slAng2Dec(tmp) , slLocate(18,5));

		// Perspective going from 20 to 160 degrees
		tmp += adang;
		if (tmp > DEGtoANG(160.0)) 
			adang = DEGtoANG(-0.5);
		if (tmp < DEGtoANG(20.0))
			adang = DEGtoANG(0.5);

		// Positioning the polygon
		slPushMatrix(); {
			FIXED dz;
			dz = slDivFX(slTan(tmp >> 1), toFIXED(170.0));
			slPrint("DZ: ", slLocate(4,7));
			slPrintHex(dz, slLocate(19,7));
			slTranslate(pos[X] , pos[Y] , pos[Z] + dz);
			slRotX(ang[X]);
			slRotY(ang[Y]);
			slRotZ(ang[Z]);
			slPutPolygon(&PD_CUBE);
		}
		slPopMatrix();

		slSynch();
    }
}
