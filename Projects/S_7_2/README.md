# Example S_7_2
 
## Documentation reference

_SGL Developer's Manual Tutorial.pdf_

_Chapter 7: Polygon Face Attributes_

_Example: S_7_2 Single Plain Polygon_

## Learning  

This chapter explains the attributes which are used to describe a polygon / plane

In this example, the most important thing is to play with the various attributes specified for the plane defined in `polygon.c`

**ATTRITBUTE** has the following configurable attributes to understand (in order), some of them have been used or tweaked in previous examples (e.g. the light exampple in *S_3_2* used `useLight` for making sure the lightning was applied to it):

- `plane`: This can be configured to `Single_Plane` or `Dual_Plane` indicating if the polygon is single-sided or double-sided. A single-sided polygon cannot be seen from the back if the camera viewpoint moves there
- `sort`: Z sort position on the polygon. It uses a representative point on each polygon to determine its position in 3D space. Values can be:
    - `SORT_MIN` which indicates that the closed point on the polygin will be used
    - `SORT_CEN` which indicates that the center point on the polygon will be used (most common used in the previous examples)
    - `SORT_MAX` which indicates that the farthest point on the polygon will be used
    - `SORT_BFR` which displays the polyon just in front of the last polygon that was registered
- `texture`: Textures comes in the example (**S_7_4**). On the previous examples, we configured `No_Texture` as we were not mapping any texture to any plan / polygon of the examples. But, it can be configured to a texture that has been loaded into memory.
- `color`: Color configuration comes as part of the example **S_7_6**. However, we already made some usage of this attribute in previous examples by applying *RGB* colour to the planes of the polygon when using `No_Texture` as the `texture`. In the case of using a `texture`, then it will depend on the configuration of the `mode` attribute to determine the color configuration
- `gouaud`: It also comes as part of the example **S_7_6**. This attribute specifies the **gouraud table** used for the **gouraud shading**. This is a technique that *hides* the boundaries between polygons and make a more curved feeling of it. 
- `mode`: It adds a variety of conditions to the particular polygon. It also comes as explanationation in the example **S_7_6**. However, we already used this attribute in the example **S_4_5** when we played with `Window_In` and `Window_Out` for the **clipping** concept and the two windows Sega Saturn manages on the screen. There are ton of options which can be checked in the *Developer's Manual Tutorial*
- `dir`: Detemrmines what is this object we are configuring its attributes. This can be a polygon, polyline, a texture... We mostly used `sprPolygon` in all the examples until now
- `option`: This is another attribute we have indirectly make use of it in previous examples (*S_3_2*). This parameter is extra behaviour of our polygons and textures on how light or palette of color is used.
