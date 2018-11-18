/* Copyright (c) 2005 Russ Cox, see README for licence details */
#include <stdio.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/keysym.h>
#include "dat.h"
#include "fns.h"

static int esccode;
static int tabcode;

static void alttab(int shift);

void
keysetup(void)
{
	int i;

	esccode = XKeysymToKeycode(dpy, XK_Escape);
	tabcode = XKeysymToKeycode(dpy, XK_Tab);

	for(i=0; i<num_screens; i++){
		XGrabKey(dpy, esccode, Mod4Mask, screens[i].root, 0, GrabModeSync, GrabModeAsync);
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
	if(e->keycode == tabcode && (e->state&Mod4Mask) == (Mod4Mask))
		alttab(e->state&ShiftMask);
	else if(e->keycode == esccode && (e->state&Mod4Mask) == (Mod4Mask))
		hide(current);
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

