// ���ޤ��ʤ��ե�����2
#ifndef __VIEW_OTHELLO_h
#define __VIEW_OTHELLO_h
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include <X11/Xlib.h> /* X11 Libraly */
#include <X11/Xutil.h>

//////////////////// Othello part
#define EMPTY (-1)
#define WHITE (0)
#define BLACK (1)

struct othello{
	int n;
	int score[2];
	int pass_flag[2];
	int **board;
};

// myothello�Υץ��ȥ��������
void myothello( int *step, struct othello *o );

// �ܡ��ɤ���������ؿ�
void init_othello( struct othello *o );

/////////////////// Visualization part
/* View */
struct view{
	int			w, h;
	int			screen_number;
	long		event_mask;
	Display*	display;
	Window		parent, window;
	Pixmap		pixmap;
	GC			gc;
	Colormap	cmap;
	XColor		color;
	XEvent		event;
};

void view_init( struct view *v );


void view_out( struct view *v );
void view_draw( struct view *v, void *a );
void view_loop( struct view *v, struct othello *o );
#endif