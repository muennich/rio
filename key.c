/* Copyright (c) 2005 Russ Cox, see README for licence details */
#include <stdio.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/keysym.h>
#include "dat.h"
#include "fns.h"

static void alttab(int shift);

void
keysetup(void)
{
	int i;
	int tabcode = XKeysymToKeycode(dpy, XK_Tab);

	for(i=0; i<num_screens; i++){
		XGrabKey(dpy, tabcode, Mod4Mask, screens[i].root, 0, GrabModeSync, GrabModeAsync);
		XGrabKey(dpy, tabcode, Mod4Mask|ShiftMask, screens[i].root, 0, GrabModeSync, GrabModeAsync);
	}
}

void
keypress(XKeyEvent *e)
{
	/*
	 * process key press here
	 */
	int tabcode = XKeysymToKeycode(dpy, XK_Tab);
	if(e->keycode == tabcode && (e->state&Mod4Mask) == (Mod4Mask))
		alttab(e->state&ShiftMask);
	XAllowEvents(dpy, SyncKeyboard, e->time);
}

void
keyrelease(XKeyEvent *e)
{
	XAllowEvents(dpy, SyncKeyboard, e->time);
}

static void
alttab(int shift)
{
	shuffle(shift);
/*	fprintf(stderr, "%sTab\n", shift ? "Back" : ""); */
}

