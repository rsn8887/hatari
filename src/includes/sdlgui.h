/*
  Hatari - sdlgui.h

  This file is distributed under the GNU Public License, version 2 or at
  your option any later version. Read the file gpl.txt for details.

  Header for the tiny graphical user interface for Hatari.
*/

#ifndef HATARI_SDLGUI_H
#define HATARI_SDLGUI_H

#include <SDL.h>

enum
{
  SGBOX,
  SGTEXT,
  SGEDITFIELD,
  SGBUTTON,
  SGRADIOBUT,
  SGCHECKBOX,
  SGPOPUP
};


/* Object flags: */
#define SG_TOUCHEXIT  1
#define SG_EXIT       2  /* Not yet tested */

/* Object states: */
#define SG_SELECTED   1

/* Special characters: */
#define SGRADIOBUTTON_NORMAL    12
#define SGRADIOBUTTON_SELECTED  13
#define SGCHECKBOX_NORMAL    14
#define SGCHECKBOX_SELECTED  15
#define SGARROWUP    1
#define SGARROWDOWN  2
#define SGFOLDER     5

/* Return codes: */
#define SDLGUI_ERROR         -1
#define SDLGUI_QUIT          -2
#define SDLGUI_UNKNOWNEVENT  -3


typedef struct
{
  int type;             /* What type of object */
  int flags;            /* Object flags */
  int state;            /* Object state */
  int x, y;             /* The offset to the upper left corner */
  int w, h;             /* Width and height */
  char *txt;            /* Text string */
}  SGOBJ;


extern int SDLGui_Init(void);
extern int SDLGui_UnInit(void);
extern int SDLGui_SetScreen(SDL_Surface *pScrn);
extern int SDLGui_DoDialog(SGOBJ *dlg, SDL_Event *pEventOut);
extern void SDLGui_CenterDlg(SGOBJ *dlg);
extern int SDLGui_FileSelect(char *path_and_name, char *zip_path, BOOL bAllowNew);

#endif
