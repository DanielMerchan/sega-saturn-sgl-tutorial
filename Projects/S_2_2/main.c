/*----------------------------------------------------------------------*/
/*	Draw 1 Polygon							*/
/*----------------------------------------------------------------------*/
#include "sgl.h"

extern PDATA PD_PLANE1;

int main(void)
{
	static ANGLE ang[XYZ];
	static FIXED pos[XYZ];

	slInitSystem(TV_320x224, NULL, 1);

	ang[X] = ang[Y] = ang[Z] = DEGtoANG(0.0);
	pos[X] = toFIXED(0.0);
	pos[Y] = toFIXED(0.0);
	pos[Z] = toFIXED(220.0);

	slPrint("My first sexy Saturn polygon", slLocate(9, 2));

	while (-1)
	{
		slPushMatrix();
		{
			slTranslate(pos[X], pos[Y], pos[Z]);
			slRotX(ang[X]);
			slRotY(ang[Y]);
			slRotZ(ang[Z]);
			slPutPolygon(&PD_PLANE1);
		}
		slPopMatrix();

		slSynch();
	}
}