#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "draw.h"
#include "main.h"
#include "appInfo.h"

#define STACKSIZE 0x1000

void    initUI(void);
void    exitUI(void);
int     updateUI(void);
void    setExTopObject(void *object);
void    addTopObject(void *object);
void    addBottomObject(void *object);
void    changeTopFooter(sprite_t *footer);
void    changeTopHeader(sprite_t *header);
void    changeBottomFooter(sprite_t *footer);
void    changeBottomHeader(sprite_t *header);
void    clearTopScreen(void);
void    clearBottomScreen(void);
void    changeTopSprite(int id);

extern appInfoObject_t  *appTop;
extern appInfoObject_t  *appBottom;

#define newAppTop(...) newAppInfoEntry(appTop, __VA_ARGS__)
#define newAppTopMultiline(color, flags, text) drawMultilineText(color, flags, text)
#define removeAppTop(update) removeAppInfoEntry(appTop, update)
#define clearTop(update)    clearAppInfo(appTop, update)

#define TRACE() {newAppTop(DEFAULT_COLOR, SMALL, "%s:%d",__FUNCTION__, __LINE__); svcSleepThread(1000000000); updateUI(); svcSleepThread(1000000000);}
#define XTRACE(str, ...) {newAppTop(DEFAULT_COLOR, SMALL, str, __VA_ARGS__); updateUI(); svcSleepThread(500000000);}  

#endif