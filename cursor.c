/* Copyright (c) 1994-1996 David Hogan, see README for licence details */
#include <stdio.h>
#include <X11/X.h>
#include <X11/cursorfont.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include "dat.h"
#include "fns.h"

void
initcurs(s)
ScreenInfo *s;
{
	s->arrow = XCreateFontCursor(dpy, XC_left_ptr);
	s->target = XCreateFontCursor(dpy, XC_target);
	s->sweep0 = XCreateFontCursor(dpy, XC_right_ptr);
	s->boxcurs = XCreateFontCursor(dpy, XC_cross);

	s->bordcurs[BorderN] = XCreateFontCursor(dpy, XC_top_side);
	s->bordcurs[BorderNNE] = XCreateFontCursor(dpy, XC_top_right_corner);
	s->bordcurs[BorderENE] = s->bordcurs[BorderNNE] ;
	s->bordcurs[BorderE] = XCreateFontCursor(dpy, XC_right_side);
	s->bordcurs[BorderESE] = XCreateFontCursor(dpy, XC_bottom_right_corner);
	s->bordcurs[BorderSSE] = s->bordcurs[BorderESE];
	s->bordcurs[BorderS] = XCreateFontCursor(dpy, XC_bottom_side);
	s->bordcurs[BorderSSW] = XCreateFontCursor(dpy, XC_bottom_left_corner);
	s->bordcurs[BorderWSW] = s->bordcurs[BorderSSW];
	s->bordcurs[BorderW] = XCreateFontCursor(dpy, XC_left_side);
	s->bordcurs[BorderWNW] = XCreateFontCursor(dpy, XC_top_left_corner);
	s->bordcurs[BorderNNW] = s->bordcurs[BorderWNW];
}

