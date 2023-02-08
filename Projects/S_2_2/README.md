# Example S_2_2

## Documentation reference

_SGL Developer's Manual Tutorial.pdf_

_Chapter 2: Graphics_

_Example: S_2_2 render a polygon (2D square)_
 
## Learning

This can be considered as the `Hello World` on how to draw a polygon.

The example is mainly compose by 2 files:

-  `main.c`: Contains the videogame loop which positions the polygon in the screen

-  `polygonc.c`: Defines a 2D square polygon very simple without textures which will be render in the screen

The important of the code example is in `main.c` to understand the `slPutPolygon` which is the responsible of drawing a polygon.

`slPutPolygon` requires a `PDATA` attribute which represents a polygon. There are three sections in the

Other functions such as `slInitSystem`, `slPushMatrix`, `slTranslate`, `slRotX`, `slRotY`, `slRotY`, `slRotZ`, `slPopMatrix`, `slSynch` are present in this example. However, those functions will be further detailed and explained in the following examples of the tutorial. Basically, they initiate the Sega Saturn system, resolution and also positions the coordinates where the polygon defined in `polygon.c` will be placed.

`polygon.c` contains the typical polygon definition. In this example it is a **2D square**

It is important to have some basic maths knowledge over linear algebra, trigonometry, geometry to understand better the code as the polygons are placed in the screen based on matrix operations, vertex and normals etc...
