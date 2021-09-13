/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 0;         /* border pixel of windows */
static const unsigned int snap      = 0;         /* snap pixel */
static const int swallowfloating    = 0;        /* 1 means swallow floating windows by default */
static const int showbar            = 1;         /* 0 means no bar */
static const int topbar             = 1;         /* 0 means bottom bar */
static const char *fonts[]          = { "monospace:size=10" };
static const int smartgaps          = 0;         /* 1 means no outer gap when there is only one window */
static const unsigned int gappih    = 30;        /* horiz inner gap between windows */
static const unsigned int gappiv    = 30;        /* vert inner gap between windows */
static const unsigned int gappoh    = 50;        /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 50;        /* vert outer gap between windows and screen edge */
static const int focusonwheel       = 0;         /* don't focus on mwheel event */
static const int usealtbar          = 1;         /* 1 means use non-dwm status bar */
static const char *altbarclass      = "Polybar"; /* Alternate bar class name */
static const char *alttrayname      = "tray";    /* Polybar tray instance name */
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#005577";
static const char *colors[][3]      = {
	/*             fg           bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
};

typedef struct {
	const char *name;
	const void *cmd;
} Sp;
const char *spcmd1[] = {"alacritty", "-t", "spterm", NULL };
const char *spcmd2[] = {"alacritty", "-t", "amogu.sh - memes", "-e", "memes", NULL };
const char *spcmd3[] = {"alacritty", "-t", "amogu.sh - screenshots", "-e", "screenshots", NULL };
static Sp scratchpads[] = {
	/* name			cmd  */
	{"spterm",		spcmd1},
	{"amogu.sh - memes",		spcmd2},
	{"amogu.sh - screenshots",		spcmd3},
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5"};

static const Rule rules[] = {
	/*	WM_CLASS(STRING) = instance, class
	 	WM_NAME(STRING) = title
       class     instance  title           tags mask  isfloating  isterminal  noswallow  monitor */
	{  NULL,       NULL,   "spterm",   SPTAG(0),     1,           1,        0,          -1},
	{  NULL,       NULL,   "amogu.sh - memes",    SPTAG(1),     1,           1,        0,          -1},
	{  NULL,       NULL,   "amogu.sh - screenshots",    SPTAG(2),     1,           1,        0,          -1},
	{  NULL,       NULL,   "Alacritty",0,            0,           1,        0,          -1},
};

#include "vanitygaps.c"
/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "",      dwindle },
	{ "",      monocle },
	{ "",	    centeredmaster },
	{ "",	    bstack },
	{ "",      NULL },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },
#define STACKKEYS(MOD,ACTION) \
	{ MOD,	XK_j,	ACTION##stack,	{.i = INC(+1) } }, \
	{ MOD,	XK_k,	ACTION##stack,	{.i = INC(-1) } }, \

#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *termcmd[]  = { "alacritty", NULL };

#include <X11/XF86keysym.h>
static Key keys[] = {
	/* modifier                 key                   function        argument */
	STACKKEYS(MODKEY,                                 focus)
	STACKKEYS(MODKEY|ShiftMask,                       push)

	TAGKEYS(			        XK_1,		          0)
	TAGKEYS(			        XK_2,		          1)
	TAGKEYS(			        XK_3,		          2)
	TAGKEYS(			        XK_4,		          3)
	TAGKEYS(			        XK_5,		          4)
	TAGKEYS(			        XK_6,		          5)
	TAGKEYS(			        XK_7,		          6)
	TAGKEYS(			        XK_8,		          7)
	TAGKEYS(			        XK_v,		          8)

	/* modifier                 key                   function          argument */
    /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
	{ MODKEY,			        XK_0,		          view,		        {.ui = ~0 } },
	{ MODKEY|ShiftMask,         XK_0,		          tag,		        {.ui = ~0 } },
	{ MODKEY,			        XK_semicolon,         view,		        {0} },
	{ MODKEY,		            XK_c,		          killclient,	    {0} },
	{ MODKEY,			        XK_t,		          setlayout,	    {.v = &layouts[0]} }, /* tile */
	{ MODKEY,		            XK_m,		          setlayout,	    {.v = &layouts[1]} }, /* monocle */
	{ MODKEY|ShiftMask,			XK_c,		          setlayout,	    {.v = &layouts[2]} }, /* centeredmaster */
	{ MODKEY,			        XK_b,		          setlayout,	    {.v = &layouts[3]} }, /* bstack */
	{ MODKEY|ShiftMask,		    XK_f,		          setlayout,	    {.v = &layouts[4]} }, /* floating */
	{ MODKEY,			        XK_comma,		      incnmaster,       {.i = +1 } },
	{ MODKEY|ShiftMask,		    XK_comma,		      incnmaster,       {.i = -1 } },
	{ MODKEY|ShiftMask,         XK_q,                 quit,             {1} },
 	{ MODKEY,			        XK_a,		          togglegaps,	    {0} },
	{ MODKEY|ShiftMask,		    XK_a,		          defaultgaps,	    {0} },
    { MODKEY,			        XK_f,		          togglefullscr,    {0} },
	{ MODKEY,			        XK_h,		          setmfact,	        {.f = -0.05} },
	{ MODKEY,			        XK_l,		          setmfact,      	{.f = +0.05} },
	{ MODKEY,                   XK_x,	              spawn,		    {.v = termcmd } },
	{ MODKEY,			        XK_z,		          spawn,            SHCMD("rofi -show drun")},
 	{ MODKEY|ShiftMask,		    XK_x,	              togglescratch,    {.ui = 0} },
 	{ MODKEY,        		    XK_r,    	          togglescratch,    {.ui = 1} },
 	{ MODKEY|ShiftMask,         XK_r,    	          togglescratch,    {.ui = 2} },
	{ MODKEY,		            XK_e,		          incrgaps,	        {.i = +8 } },
	{ MODKEY,		            XK_w,		          incrgaps,	        {.i = -8 } },
	{ MODKEY,			        XK_Left,	          focusmon,	        {.i = -1 } },
	{ MODKEY|ShiftMask,		    XK_Left,	          tagmon,		    {.i = -1 } },
	{ MODKEY,			        XK_Right,	          focusmon,	        {.i = +1 } },
	{ MODKEY|ShiftMask,		    XK_Right,	          tagmon,		    {.i = +1 } },
	{ MODKEY,			        XK_space,	          zoom,		        {0} },
	{ MODKEY|ShiftMask,		    XK_space,	          togglefloating,	{0} },
	{ MODKEY,                       XK_Down,   moveresize,     {.v = "0x 25y 0w 0h" } },
	{ MODKEY,                       XK_Up,     moveresize,     {.v = "0x -25y 0w 0h" } },
	{ MODKEY,                       XK_Right,  moveresize,     {.v = "25x 0y 0w 0h" } },
	{ MODKEY,                       XK_Left,   moveresize,     {.v = "-25x 0y 0w 0h" } },
	{ MODKEY|ShiftMask,             XK_Down,   moveresize,     {.v = "0x 0y 0w 25h" } },
	{ MODKEY|ShiftMask,             XK_Up,     moveresize,     {.v = "0x 0y 0w -25h" } },
	{ MODKEY|ShiftMask,             XK_Right,  moveresize,     {.v = "0x 0y 25w 0h" } },
	{ MODKEY|ShiftMask,             XK_Left,   moveresize,     {.v = "0x 0y -25w 0h" } },
	{ MODKEY|ControlMask,           XK_Up,     moveresizeedge, {.v = "t"} },
	{ MODKEY|ControlMask,           XK_Down,   moveresizeedge, {.v = "b"} },
	{ MODKEY|ControlMask,           XK_Left,   moveresizeedge, {.v = "l"} },
	{ MODKEY|ControlMask,           XK_Right,  moveresizeedge, {.v = "r"} },
	{ MODKEY|ControlMask|ShiftMask, XK_Up,     moveresizeedge, {.v = "T"} },
	{ MODKEY|ControlMask|ShiftMask, XK_Down,   moveresizeedge, {.v = "B"} },
	{ MODKEY|ControlMask|ShiftMask, XK_Left,   moveresizeedge, {.v = "L"} },
	{ MODKEY|ControlMask|ShiftMask, XK_Right,  moveresizeedge, {.v = "R"} },
	{ MODKEY,                   XK_u,                 spawn,             SHCMD("vol-up") },
	{ MODKEY,                   XK_i,                 spawn,             SHCMD("vol-down") },
	{ MODKEY,                   XK_o,                 spawn,		     SHCMD("light-up") },
	{ MODKEY|ShiftMask,         XK_o,                 spawn,		     SHCMD("light-on") },
	{ MODKEY,                   XK_p,                 spawn,		     SHCMD("light-down") },
	{ MODKEY|ShiftMask,         XK_p,                 spawn,		     SHCMD("light-off") },
	{ MODKEY,                   XK_s,                 spawn,		     SHCMD("bang") },
	{ MODKEY|ShiftMask,         XK_s,                 spawn,		     SHCMD("bam") },
	{ MODKEY|ShiftMask,         XK_l,                 spawn,		     SHCMD("betterlockscreen -l") },

	/* modifier                 key                          function          argument */
    /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
	{ 0,                        XF86XK_Mail,		         focusmon,		    {.i = +1 } },
	{ 0|ShiftMask,              XF86XK_Mail,		         tagmon, 		    {.i = +1 } },
 	{ 0,			            XF86XK_Calculator,	         togglescratch,	    {.ui = 1} }, /* spawn ncmpcpp terminal */
	{ 0,                        XF86XK_AudioPrev,		     spawn,		        SHCMD("mpc prev") },
	{ 0,                        XF86XK_AudioNext,		     spawn,		        SHCMD("mpc next") },
	{ 0,                        XF86XK_AudioPause,		     spawn,		        SHCMD("mpc pause") },
	{ 0,                        XF86XK_AudioPlay,		     spawn,		        SHCMD("mpc play") },
	{ 0,                        XF86XK_AudioStop,		     spawn,		        SHCMD("mpc stop") },
	{ 0,                        XF86XK_AudioRewind,	         spawn,		        SHCMD("mpc seek -10") },
	{ 0,                        XF86XK_AudioForward,	     spawn,		        SHCMD("mpc seek +10") },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

static const char *ipcsockpath = "/tmp/dwm.sock";
static IPCCommand ipccommands[] = {
  IPCCOMMAND(  view,                1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  toggleview,          1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  tag,                 1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  toggletag,           1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  tagmon,              1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  focusmon,            1,      {ARG_TYPE_SINT}   ),
  IPCCOMMAND(  focusstack,          1,      {ARG_TYPE_SINT}   ),
  IPCCOMMAND(  zoom,                1,      {ARG_TYPE_NONE}   ),
  IPCCOMMAND(  spawn,               1,      {ARG_TYPE_PTR}    ),
  IPCCOMMAND(  incnmaster,          1,      {ARG_TYPE_SINT}   ),
  IPCCOMMAND(  killclient,          1,      {ARG_TYPE_SINT}   ),
  IPCCOMMAND(  togglefloating,      1,      {ARG_TYPE_NONE}   ),
  IPCCOMMAND(  setmfact,            1,      {ARG_TYPE_FLOAT}  ),
  IPCCOMMAND(  setlayoutsafe,       1,      {ARG_TYPE_PTR}    ),
  IPCCOMMAND(  quit,                1,      {ARG_TYPE_NONE}   )
};
