#include "sgl.h"
#include "ss_akira.h"

POINT point_te_l_ak750[] = {
	POStoFIXED(-36.299988,  17.699997,  10.799988),
	POStoFIXED(-36.599991, -17.099991,   4.799988),
	POStoFIXED(  0.599991, -10.199997,   6.599991),
	POStoFIXED(  0.599991,   9.299988,   6.599991),
	POStoFIXED(-36.299988, -17.099991,  10.799988),
	POStoFIXED(-36.599991,  17.699997,   4.799988),
	POStoFIXED(  0.599991, -10.199997, - 4.500000),
	POStoFIXED(  0.599991,   9.299988, - 4.500000),
	POStoFIXED(-13.199997, -16.799988,  11.699997),
	POStoFIXED(-13.199997,  17.099991,  11.699997),
	POStoFIXED(-13.199997, -16.799988, -10.500000),
	POStoFIXED(-13.199997,  17.099991, -10.500000),
};

POLYGON polygon_te_l_ak750[] = {
	NORMAL( 0.346651, -0.000000,  0.937994), VERTICES( 2,  8,  9,  3),
	NORMAL( 0.492058,  0.870563, -0.000000), VERTICES( 7,  3,  9, 11),
	NORMAL( 0.398726, -0.000000, -0.917070), VERTICES(10,  6,  7, 11),
	NORMAL( 0.431455, -0.902134, -0.000000), VERTICES( 2,  6, 10,  8),
	NORMAL(-0.998752, -0.000000,  0.049938), VERTICES( 5,  0,  4,  1),
	NORMAL( 1.000000,  0.000000,  0.000000), VERTICES( 3,  7,  6,  2),
	NORMAL(-0.038932, -0.000000,  0.999242), VERTICES( 0,  9,  8,  4),
	NORMAL( 0.012820, -0.999918, -0.000000), VERTICES( 8, 10,  1,  4),
	NORMAL(-0.547249,  0.000000, -0.836970), VERTICES( 1, 10, 11,  5),
	NORMAL( 0.025966,  0.999663, -0.000000), VERTICES(11,  9,  0,  5),
};

ATTR attribute_te_l_ak750[] = {
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
};

PDATA AKI_TE_L = {
	point_te_l_ak750, sizeof(point_te_l_ak750) / sizeof(POINT),
	polygon_te_l_ak750, sizeof(polygon_te_l_ak750) / sizeof(POLYGON),
	attribute_te_l_ak750
};


POINT point_yubi_l_ak750[] = {
	POStoFIXED(-35.699997,  16.199997,  10.799988),
	POStoFIXED(-28.799988,  16.199997,   8.099991),
	POStoFIXED(-28.799988, -15.599991,   8.099991),
	POStoFIXED(-36.000000, -15.599991,  10.799988),
	POStoFIXED(-33.000000,  16.199997, - 3.899994),
	POStoFIXED(-33.000000, -15.599991, - 3.899994),
	POStoFIXED(-41.699997, -15.599991, - 7.199997),
	POStoFIXED(-41.699997,  16.199997, - 7.199997),
	POStoFIXED(-29.099991, -15.599991, - 6.899994),
	POStoFIXED(-28.799988,  16.199997, - 6.899994),
	POStoFIXED(-23.699997,  16.199997, - 1.799988),
	POStoFIXED(-24.000000, -15.599991, - 1.799988),
	POStoFIXED(-21.000000,  16.199997, - 7.500000),
	POStoFIXED(-21.000000, -15.599991, - 7.500000),
	POStoFIXED(-29.399994,  16.199997, -16.500000),
	POStoFIXED(-29.399994, -15.599991, -16.500000),
};

POLYGON polygon_yubi_l_ak750[] = {
	NORMAL( 0.943858, -0.000000, -0.330352), VERTICES( 4,  5,  2,  1),
	NORMAL(-0.948683, -0.000000,  0.316228), VERTICES( 6,  7,  0,  3),
	NORMAL(-0.000000,  1.000000, -0.000000), VERTICES( 7,  4,  1,  0),
	NORMAL(-0.000000, -1.000000,  0.000000), VERTICES( 5,  6,  3,  2),
	NORMAL(-0.707092,  0.006671,  0.707090), VERTICES( 8,  9, 10, 11),
	NORMAL( 0.609700, -0.005752,  0.792612), VERTICES( 9,  8,  5,  4),
	NORMAL( 0.903738,  0.000000,  0.428085), VERTICES(10, 12, 13, 11),
	NORMAL( 0.731056, -0.000000, -0.682318), VERTICES(14, 15, 13, 12),
	NORMAL(-0.603108,  0.000000, -0.797659), VERTICES(15, 14,  7,  6),
	NORMAL(-0.000000,  1.000000,  0.000000), VERTICES( 9, 14, 12, 10),
	NORMAL(-0.000000,  1.000000, -0.000000), VERTICES(14,  9,  4,  7),
	NORMAL(-0.000000, -1.000000, -0.000000), VERTICES(15,  8, 11, 13),
	NORMAL(-0.000000, -1.000000, -0.000000), VERTICES( 8, 15,  6,  5),
};

ATTR attribute_yubi_l_ak750[] = {
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
};

PDATA AKI_YUBI_L = {
	point_yubi_l_ak750, sizeof(point_yubi_l_ak750) / sizeof(POINT),
	polygon_yubi_l_ak750, sizeof(polygon_yubi_l_ak750) / sizeof(POLYGON),
	attribute_yubi_l_ak750
};


POINT point_oyubi_l_ak750[] = {
	POStoFIXED(-17.099991, -17.099991,   4.199997),
	POStoFIXED(-20.399994, -11.399994,   2.699997),
	POStoFIXED(-13.799988, - 9.599991, - 3.299988),
	POStoFIXED(-10.500000, -15.000000, - 1.500000),
	POStoFIXED(-26.699997, -15.599991, - 6.299988),
	POStoFIXED(-20.099991, -13.799988, -12.299988),
	POStoFIXED(-20.099991, -21.599991, -14.699997),
	POStoFIXED(-26.699997, -23.399994, - 9.000000),
	POStoFIXED(-23.099991, -10.799988, -14.099991),
	POStoFIXED(-29.399994, -12.599991, - 8.099991),
	POStoFIXED(-27.599991, - 7.799988, - 4.500000),
	POStoFIXED(-21.000000, - 6.000000, -10.199997),
	POStoFIXED(-31.799988, - 6.599991, - 8.399994),
	POStoFIXED(-25.199997, - 4.799988, -14.399994),
	POStoFIXED(-35.099991, -14.099991, -15.000000),
	POStoFIXED(-28.500000, -12.299988, -20.699997),
};

POLYGON polygon_oyubi_l_ak750[] = {
	NORMAL(-0.387235,  0.909162, -0.153210), VERTICES( 4,  5,  2,  1),
	NORMAL( 0.383023, -0.910474,  0.155982), VERTICES( 6,  7,  0,  3),
	NORMAL(-0.749423, -0.216578,  0.625667), VERTICES( 7,  4,  1,  0),
	NORMAL( 0.743564,  0.196646, -0.639096), VERTICES( 5,  6,  3,  2),
	NORMAL( 0.634201, -0.601844,  0.485359), VERTICES( 8,  9, 10, 11),
	NORMAL( 0.361272,  0.718139,  0.594777), VERTICES( 9,  8,  5,  4),
	NORMAL( 0.003381,  0.956791,  0.290756), VERTICES(10, 12, 13, 11),
	NORMAL(-0.587722,  0.656175, -0.473306), VERTICES(14, 15, 13, 12),
	NORMAL(-0.341396, -0.707542, -0.618735), VERTICES(15, 14,  7,  6),
	NORMAL(-0.717640, -0.254645,  0.648189), VERTICES( 9, 14, 12, 10),
	NORMAL(-0.717057, -0.256485,  0.648108), VERTICES(14,  9,  4,  7),
	NORMAL( 0.734262,  0.204674, -0.647277), VERTICES(15,  8, 11, 13),
	NORMAL( 0.724738,  0.237255, -0.646889), VERTICES( 8, 15,  6,  5),
};

ATTR attribute_oyubi_l_ak750[] = {
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
};

PDATA AKI_OYAYUBI_L = {
	point_oyubi_l_ak750, sizeof(point_oyubi_l_ak750) / sizeof(POINT),
	polygon_oyubi_l_ak750, sizeof(polygon_oyubi_l_ak750) / sizeof(POLYGON),
	attribute_oyubi_l_ak750
};


POINT point_te_r_ak750[] = {
	POStoFIXED(-36.000000,  16.500000, -12.899994),
	POStoFIXED(-36.000000, -18.299988, - 6.599991),
	POStoFIXED(  0.899994, -11.399994, - 8.399994),
	POStoFIXED(  1.199997,   8.099991, - 8.399994),
	POStoFIXED(-36.000000, -18.299988, -12.899994),
	POStoFIXED(-36.000000,  16.500000, - 6.599991),
	POStoFIXED(  0.899994, -11.399994,   2.399994),
	POStoFIXED(  0.899994,   8.099991,   2.399994),
	POStoFIXED(-12.599991, -18.000000, -13.799988),
	POStoFIXED(-12.599991,  15.899994, -13.799988),
	POStoFIXED(-12.599991, -18.000000,   8.699997),
	POStoFIXED(-12.599991,  15.899994,   8.699997),
};

POLYGON polygon_te_r_ak750[] = {
	NORMAL( 0.364399, -0.000000, -0.931243), VERTICES( 3,  9,  8,  2),
	NORMAL( 0.492058,  0.870563,  0.000000), VERTICES(11,  9,  3,  7),
	NORMAL( 0.422886,  0.000000,  0.906183), VERTICES(11,  7,  6, 10),
	NORMAL( 0.439211, -0.898384, -0.000000), VERTICES( 8, 10,  6,  2),
	NORMAL(-1.000000,  0.000000, -0.000000), VERTICES( 1,  4,  0,  5),
	NORMAL( 1.000000, -0.000000, -0.000000), VERTICES( 2,  6,  7,  3),
	NORMAL(-0.038433,  0.000000, -0.999261), VERTICES( 4,  8,  9,  0),
	NORMAL( 0.012819, -0.999918, -0.000000), VERTICES( 4,  1, 10,  8),
	NORMAL(-0.547249, -0.000000,  0.836970), VERTICES( 5, 11, 10,  1),
	NORMAL( 0.025633,  0.999671,  0.000000), VERTICES( 5,  0,  9, 11),
};

ATTR attribute_te_r_ak750[] = {
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
};

PDATA AKI_TE_R = {
	point_te_r_ak750, sizeof(point_te_r_ak750) / sizeof(POINT),
	polygon_te_r_ak750, sizeof(polygon_te_r_ak750) / sizeof(POLYGON),
	attribute_te_r_ak750
};


POINT point_yubi_r_ak750[] = {
	POStoFIXED(-35.399994,  15.000000, -12.599991),
	POStoFIXED(-28.500000,  15.000000, - 9.899994),
	POStoFIXED(-28.500000, -16.799988, - 9.899994),
	POStoFIXED(-35.399994, -16.799988, -12.599991),
	POStoFIXED(-32.399994,  15.000000,   2.099991),
	POStoFIXED(-32.699997, -16.799988,   2.099991),
	POStoFIXED(-41.399994, -16.799988,   5.399994),
	POStoFIXED(-41.099991,  15.000000,   5.399994),
	POStoFIXED(-28.500000, -16.799988,   5.099991),
	POStoFIXED(-28.500000,  15.000000,   5.099991),
	POStoFIXED(-23.399994,  15.000000,   0.000000),
	POStoFIXED(-23.399994, -16.799988,   0.000000),
	POStoFIXED(-20.399994,  15.000000,   5.699997),
	POStoFIXED(-20.699997, -16.799988,   5.699997),
	POStoFIXED(-28.799988,  15.000000,  14.699997),
	POStoFIXED(-29.099991, -16.799988,  14.699997),
};

POLYGON polygon_yubi_r_ak750[] = {
	NORMAL( 0.943858,  0.000000,  0.330351), VERTICES( 1,  2,  5,  4),
	NORMAL(-0.953342,  0.000000, -0.301892), VERTICES( 3,  0,  7,  6),
	NORMAL(-0.000000,  1.000000, -0.000000), VERTICES( 0,  1,  4,  7),
	NORMAL(-0.000000, -1.000000, -0.000000), VERTICES( 2,  3,  6,  5),
	NORMAL(-0.707106,  0.000000, -0.707108), VERTICES(11, 10,  9,  8),
	NORMAL( 0.581230, -0.005483, -0.813721), VERTICES( 4,  5,  8,  9),
	NORMAL( 0.903705, -0.008526, -0.428071), VERTICES(11, 13, 12, 10),
	NORMAL( 0.731038, -0.006897,  0.682302), VERTICES(12, 13, 15, 14),
	NORMAL(-0.603099,  0.005690,  0.797646), VERTICES( 6,  7, 14, 15),
	NORMAL(-0.000000,  1.000000, -0.000000), VERTICES(10, 12, 14,  9),
	NORMAL(-0.000000,  1.000000, -0.000000), VERTICES( 7,  4,  9, 14),
	NORMAL(-0.000000, -1.000000, -0.000000), VERTICES(13, 11,  8, 15),
	NORMAL(-0.000000, -1.000000,  0.000000), VERTICES( 5,  6, 15,  8),
};

ATTR attribute_yubi_r_ak750[] = {
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
};

PDATA AKI_YUBI_R = {
	point_yubi_r_ak750, sizeof(point_yubi_r_ak750) / sizeof(POINT),
	polygon_yubi_r_ak750, sizeof(polygon_yubi_r_ak750) / sizeof(POLYGON),
	attribute_yubi_r_ak750
};


POINT point_oyubi_r_ak750[] = {
	POStoFIXED(-16.500000, -18.000000, - 6.000000),
	POStoFIXED(-19.799988, -12.599991, - 4.500000),
	POStoFIXED(-13.199997, -10.799988,   1.500000),
	POStoFIXED(- 9.899994, -16.199997, - 0.299988),
	POStoFIXED(-26.399994, -16.799988,   4.500000),
	POStoFIXED(-19.799988, -15.000000,  10.199997),
	POStoFIXED(-19.799988, -22.799988,  12.899994),
	POStoFIXED(-26.099991, -24.599991,   6.899994),
	POStoFIXED(-22.500000, -12.000000,  12.299988),
	POStoFIXED(-29.099991, -13.799988,   6.299988),
	POStoFIXED(-27.299988, - 9.000000,   2.399994),
	POStoFIXED(-20.699997, - 7.199997,   8.399994),
	POStoFIXED(-31.199997, - 7.799988,   6.599991),
	POStoFIXED(-24.599991, - 6.000000,  12.299988),
	POStoFIXED(-34.799988, -15.299988,  13.199997),
	POStoFIXED(-28.199997, -13.500000,  18.899994),
};

POLYGON polygon_oyubi_r_ak750[] = {
	NORMAL(-0.383814,  0.911344,  0.148791), VERTICES( 1,  2,  5,  4),
	NORMAL( 0.393106, -0.903678, -0.169803), VERTICES( 3,  0,  7,  6),
	NORMAL(-0.717399, -0.258732, -0.646835), VERTICES( 0,  1,  4,  7),
	NORMAL( 0.722742,  0.223707,  0.653911), VERTICES( 2,  3,  6,  5),
	NORMAL( 0.611877, -0.624176, -0.485810), VERTICES(11, 10,  9,  8),
	NORMAL( 0.328804,  0.722035, -0.608731), VERTICES( 4,  5,  8,  9),
	NORMAL(-0.003582,  0.954761, -0.297354), VERTICES(11, 13, 12, 10),
	NORMAL(-0.577733,  0.677673,  0.454955), VERTICES(12, 13, 15, 14),
	NORMAL(-0.352219, -0.727968,  0.588221), VERTICES( 6,  7, 14, 15),
	NORMAL(-0.745811, -0.200929, -0.635132), VERTICES(10, 12, 14,  9),
	NORMAL(-0.705322, -0.233115, -0.669461), VERTICES( 7,  4,  9, 14),
	NORMAL( 0.721930,  0.252674,  0.644184), VERTICES(13, 11,  8, 15),
	NORMAL( 0.719881,  0.227047,  0.655912), VERTICES( 5,  6, 15,  8),
};

ATTR attribute_oyubi_r_ak750[] = {
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
};

PDATA AKI_OYAYUBI_R = {
	point_oyubi_r_ak750, sizeof(point_oyubi_r_ak750) / sizeof(POINT),
	polygon_oyubi_r_ak750, sizeof(polygon_oyubi_r_ak750) / sizeof(POLYGON),
	attribute_oyubi_r_ak750
};


POINT point_ude_l_ak750[] = {
	POStoFIXED(  0.899994, -14.099991, -15.299988),
	POStoFIXED(-20.099991, -12.599991, -15.299988),
	POStoFIXED(-65.699997, - 6.899994,   0.899994),
	POStoFIXED(-59.699997, -11.699997,   1.199997),
	POStoFIXED(-34.199997, -16.199997,   1.799988),
	POStoFIXED(-21.000000, -22.199997,   0.000000),
	POStoFIXED(  0.299988, -23.699997,   0.000000),
	POStoFIXED(-65.399994, - 3.299988,   6.599991),
	POStoFIXED(-59.399994, - 5.699997,   9.899994),
	POStoFIXED(-33.599991, - 9.000000,  13.500000),
	POStoFIXED(-20.099991, -12.599991,  15.299988),
	POStoFIXED(  0.899994, -14.099991,  15.299988),
	POStoFIXED(-64.799988,   4.199997,   6.599991),
	POStoFIXED(-58.500000,   6.000000,   9.899994),
	POStoFIXED(-32.699997,   5.099991,  13.500000),
	POStoFIXED(-18.599991,   6.599991,  15.299988),
	POStoFIXED(  2.399994,   4.799988,  15.299988),
	POStoFIXED(-64.500000,   8.099991,   0.899994),
	POStoFIXED(-57.899994,  11.699997,   1.199997),
	POStoFIXED(-32.099991,  12.299988,   1.799988),
	POStoFIXED(-18.000000,  16.199997,   0.000000),
	POStoFIXED(  3.299988,  14.399994,   0.000000),
	POStoFIXED(-64.799988,   4.199997, - 4.799988),
	POStoFIXED(-58.500000,   6.000000, - 7.199997),
	POStoFIXED(-32.699997,   5.099991, - 9.899994),
	POStoFIXED(-18.599991,   6.599991, -15.299988),
	POStoFIXED(  2.399994,   4.799988, -15.299988),
	POStoFIXED(-65.399994, - 3.299988, - 4.799988),
	POStoFIXED(-59.399994, - 5.699997, - 7.199997),
	POStoFIXED(-33.599991, - 9.000000, - 9.899994),
	POStoFIXED( 12.299988,   4.199997, - 7.799988),
	POStoFIXED( 10.799988, -15.000000,   7.799988),
	POStoFIXED( 10.799988, -15.000000, - 7.799988),
	POStoFIXED( 12.299988,   4.199997,   7.799988),
};

POLYGON polygon_ude_l_ak750[] = {
	NORMAL(-0.996813,  0.079746,  0.002101), VERTICES(17, 12,  7,  2),
	NORMAL(-0.538327, -0.699443,  0.470088), VERTICES( 2,  7,  8,  3),
	NORMAL(-0.181659, -0.806577,  0.562524), VERTICES( 3,  8,  9,  4),
	NORMAL(-0.284376, -0.809918,  0.512994), VERTICES( 4,  9, 10,  5),
	NORMAL(-0.060280, -0.843923,  0.533067), VERTICES( 5, 10, 11,  6),
	NORMAL( 0.423932,  0.755745,  0.499131), VERTICES(33, 16, 21, 21),
	NORMAL(-0.472124,  0.037770,  0.880723), VERTICES( 7, 12, 13,  8),
	NORMAL(-0.137826,  0.010602,  0.990400), VERTICES( 8, 13, 14,  9),
	NORMAL(-0.127478,  0.008137,  0.991808), VERTICES( 9, 14, 15, 10),
	NORMAL(-0.000000, -0.000000,  1.000000), VERTICES(10, 15, 16, 11),
	NORMAL(-0.433747,  0.754107,  0.493139), VERTICES(12, 17, 18, 13),
	NORMAL(-0.032168,  0.837044,  0.546189), VERTICES(13, 18, 19, 14),
	NORMAL(-0.168118,  0.843362,  0.510370), VERTICES(14, 19, 20, 15),
	NORMAL( 0.071294,  0.843647,  0.532144), VERTICES(15, 20, 21, 16),
	NORMAL(-0.996813,  0.079746, -0.002098), VERTICES( 2, 27, 22, 17),
	NORMAL(-0.408739,  0.763100, -0.500610), VERTICES(17, 22, 23, 18),
	NORMAL(-0.029696,  0.828095, -0.559801), VERTICES(18, 23, 24, 19),
	NORMAL(-0.276660,  0.824684, -0.493311), VERTICES(19, 24, 25, 20),
	NORMAL( 0.072306,  0.843567, -0.532133), VERTICES(20, 25, 26, 21),
	NORMAL(-0.361250,  0.028900, -0.932021), VERTICES(22, 27, 28, 23),
	NORMAL(-0.103076,  0.007929, -0.994642), VERTICES(23, 28, 29, 24),
	NORMAL(-0.365914,  0.023356, -0.930356), VERTICES(24, 29,  1, 25),
	NORMAL(-0.000000, -0.000000, -1.000000), VERTICES(25,  1,  0, 26),
	NORMAL(-0.536741, -0.700337, -0.470570), VERTICES(27,  2,  3, 28),
	NORMAL(-0.128394, -0.804824, -0.579460), VERTICES(28,  3,  4, 29),
	NORMAL(-0.414946, -0.765226, -0.492188), VERTICES(29,  4,  5,  1),
	NORMAL(-0.059436, -0.843988, -0.533058), VERTICES( 1,  5,  6,  0),
	NORMAL( 0.303327, -0.812466, -0.497888), VERTICES(32,  0,  6,  6),
	NORMAL( 0.601331, -0.047725, -0.797574), VERTICES(30, 26,  0, 32),
	NORMAL( 0.423932,  0.755745, -0.499131), VERTICES(21, 26, 30, 30),
	NORMAL( 0.749838,  0.661622, -0.000000), VERTICES(30, 33, 21, 21),
	NORMAL( 0.600416, -0.047652,  0.798267), VERTICES(31, 11, 16, 33),
	NORMAL( 0.303327, -0.812466,  0.497888), VERTICES( 6, 11, 31, 31),
	NORMAL( 0.638018, -0.770022, -0.000000), VERTICES(31, 32,  6,  6),
	NORMAL( 0.996962, -0.077888, -0.000000), VERTICES(33, 30, 32, 31),
};

ATTR attribute_ude_l_ak750[] = {
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(19,  0,  0), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(19,  0,  0), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(19,  0,  0), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(19,  0,  0), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(19,  0,  0), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(19,  0,  0), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(19,  0,  0), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(19,  0,  0), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(19,  0,  0), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(19,  0,  0), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(19,  0,  0), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(19,  0,  0), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(19,  0,  0), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(19,  0,  0), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
};

PDATA AKI_UDE_L = {
	point_ude_l_ak750, sizeof(point_ude_l_ak750) / sizeof(POINT),
	polygon_ude_l_ak750, sizeof(polygon_ude_l_ak750) / sizeof(POLYGON),
	attribute_ude_l_ak750
};


POINT point_ude_r_ak750[] = {
	POStoFIXED(  0.599991, -14.399994,  15.299988),
	POStoFIXED(-20.399994, -12.899994,  15.299988),
	POStoFIXED(-66.000000, - 8.099991, - 0.899994),
	POStoFIXED(-60.000000, -12.599991, - 1.199997),
	POStoFIXED(-34.500000, -16.799988, - 1.799988),
	POStoFIXED(-21.000000, -22.500000,   0.000000),
	POStoFIXED(  0.299988, -23.699997,   0.000000),
	POStoFIXED(-65.699997, - 4.500000, - 6.599991),
	POStoFIXED(-59.699997, - 6.899994, - 9.899994),
	POStoFIXED(-34.199997, - 9.599991, -13.500000),
	POStoFIXED(-20.399994, -12.899994, -15.299988),
	POStoFIXED(  0.599991, -14.399994, -15.299988),
	POStoFIXED(-65.399994,   3.000000, - 6.599991),
	POStoFIXED(-59.099991,   4.799988, - 9.899994),
	POStoFIXED(-33.299988,   4.500000, -13.500000),
	POStoFIXED(-19.199997,   6.299988, -15.299988),
	POStoFIXED(  1.799988,   4.799988, -15.299988),
	POStoFIXED(-65.099991,   6.899994, - 0.899994),
	POStoFIXED(-58.799988,  10.500000, - 1.199997),
	POStoFIXED(-32.699997,  11.699997, - 1.799988),
	POStoFIXED(-18.599991,  15.599991,   0.000000),
	POStoFIXED(  2.399994,  14.399994,   0.000000),
	POStoFIXED(-65.399994,   3.000000,   4.799988),
	POStoFIXED(-59.099991,   4.799988,   7.199997),
	POStoFIXED(-33.299988,   4.500000,   9.899994),
	POStoFIXED(-19.199997,   6.299988,  15.299988),
	POStoFIXED(  1.799988,   4.799988,  15.299988),
	POStoFIXED(-65.699997, - 4.500000,   4.799988),
	POStoFIXED(-59.699997, - 6.899994,   7.199997),
	POStoFIXED(-34.199997, - 9.599991,   9.899994),
	POStoFIXED( 12.000000,   4.199997,   7.799988),
	POStoFIXED( 10.799988, -15.000000, - 7.799988),
	POStoFIXED( 10.799988, -15.000000,   7.799988),
	POStoFIXED( 12.000000,   4.199997, - 7.799988),
};

POLYGON polygon_ude_r_ak750[] = {
	NORMAL(-0.998828,  0.039954, -0.027337), VERTICES( 2,  7, 12, 17),
	NORMAL(-0.539256, -0.695775, -0.474448), VERTICES( 3,  8,  7,  2),
	NORMAL(-0.162220, -0.838516, -0.520169), VERTICES( 4,  9,  8,  3),
	NORMAL(-0.262215, -0.812762, -0.520252), VERTICES( 5, 10,  9,  4),
	NORMAL(-0.060886, -0.852406, -0.519324), VERTICES( 6, 11, 10,  5),
	NORMAL( 0.409918,  0.765302, -0.496266), VERTICES(21, 16, 33, 33),
	NORMAL(-0.469259,  0.024065, -0.882732), VERTICES( 8, 13, 12,  7),
	NORMAL(-0.138090,  0.008814, -0.990380), VERTICES( 9, 14, 13,  8),
	NORMAL(-0.127629,  0.007977, -0.991790), VERTICES(10, 15, 14,  9),
	NORMAL(-0.000000,  0.000000, -1.000000), VERTICES(11, 16, 15, 10),
	NORMAL(-0.452929,  0.752823, -0.477612), VERTICES(13, 18, 17, 12),
	NORMAL(-0.051148,  0.851713, -0.521507), VERTICES(14, 19, 18, 13),
	NORMAL(-0.169031,  0.845154, -0.507093), VERTICES(15, 20, 19, 14),
	NORMAL( 0.048298,  0.845221, -0.532230), VERTICES(16, 21, 20, 15),
	NORMAL(-0.998883,  0.039956, -0.025235), VERTICES(17, 22, 27,  2),
	NORMAL(-0.409026,  0.761811,  0.502336), VERTICES(18, 23, 22, 17),
	NORMAL(-0.044714,  0.851828,  0.521910), VERTICES(19, 24, 23, 18),
	NORMAL(-0.292018,  0.822316,  0.488388), VERTICES(20, 25, 24, 19),
	NORMAL( 0.060318,  0.844455,  0.532220), VERTICES(21, 26, 25, 20),
	NORMAL(-0.364866,  0.018711,  0.930872), VERTICES(23, 28, 27, 22),
	NORMAL(-0.104592,  0.006676,  0.994493), VERTICES(24, 29, 28, 23),
	NORMAL(-0.359641,  0.022478,  0.932820), VERTICES(25,  1, 29, 24),
	NORMAL( 0.000000, -0.000000,  1.000000), VERTICES(26,  0,  1, 25),
	NORMAL(-0.504593, -0.705927,  0.497044), VERTICES(28,  3,  2, 27),
	NORMAL(-0.126617, -0.843351,  0.522233), VERTICES(29,  4,  3, 28),
	NORMAL(-0.392613, -0.772037,  0.499813), VERTICES( 1,  5,  4, 29),
	NORMAL(-0.048063, -0.853116,  0.519503), VERTICES( 0,  6,  5,  1),
	NORMAL( 0.311689, -0.814653,  0.489070), VERTICES( 6,  0, 32, 32),
	NORMAL( 0.590577, -0.036911,  0.806137), VERTICES(32,  0, 26, 30),
	NORMAL( 0.409918,  0.765302,  0.496266), VERTICES(30, 26, 21, 21),
	NORMAL( 0.728200,  0.685365, -0.000000), VERTICES(21, 33, 30, 30),
	NORMAL( 0.590576, -0.036911, -0.806137), VERTICES(33, 16, 11, 31),
	NORMAL( 0.311689, -0.814653, -0.489070), VERTICES(31, 11,  6,  6),
	NORMAL( 0.638018, -0.770022, -0.000000), VERTICES( 6, 32, 31, 31),
	NORMAL( 0.998053, -0.062379, -0.000000), VERTICES(31, 32, 30, 33),
};

ATTR attribute_ude_r_ak750[] = {
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(19,  0,  0), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(19,  0,  0), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(19,  0,  0), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(19,  0,  0), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(19,  0,  0), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(19,  0,  0), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(19,  0,  0), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(19,  0,  0), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(19,  0,  0), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(19,  0,  0), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(19,  0,  0), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(19,  0,  0), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(19,  0,  0), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(19,  0,  0), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
	ATTRIBUTE(Single_Plane, SORT_CEN, No_Texture, C_RGB(31, 26, 22), No_Gouraud, MESHoff, sprPolygon, UseLight),
};

PDATA AKI_UDE_R = {
	point_ude_r_ak750, sizeof(point_ude_r_ak750) / sizeof(POINT),
	polygon_ude_r_ak750, sizeof(polygon_ude_r_ak750) / sizeof(POLYGON),
	attribute_ude_r_ak750
};
