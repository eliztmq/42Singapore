FDF (creating a wireframe model)

Objective: to use MiniLibX to create a simple wireframe model representation of a 3D landscape by linking various points (x,y,z) through line segments

1. Program has to display image in a window
2. Management of window must remain smooth
3. Pressing ESC must close the window and quit the program in a clean way
4. Clicking on the cross on the window's frame must close the window and quit the program in a clean way

Navigation of model space: Rotation by right clicking and dragging of mouse

Background: MiniLibX is a library developed internally that includes basic necessary tools to open a window, create images and deal with keyboard and mouse events


ISSUE WITH WINDOW.C
when file is really big, scale ~ 0, so need to add in line 76
if (vis->scale == 0)
	visc->scale = 1;
