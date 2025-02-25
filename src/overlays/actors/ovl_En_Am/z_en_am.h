#ifndef Z_EN_AM_H
#define Z_EN_AM_H

#include "global.h"
#include "objects/object_am/object_am.h"

struct EnAm;

typedef void (*EnAmActionFunc)(struct EnAm*, PlayState*);

typedef struct EnAm {
    /* 0x000 */ Actor actor;
    /* 0x144 */ SkelAnime skelAnime;
    /* 0x188 */ Vec3s jointTable[OBJECT_AM_LIMB_MAX];
    /* 0x1DC */ Vec3s morphTable[OBJECT_AM_LIMB_MAX];
    /* 0x230 */ EnAmActionFunc actionFunc;
    /* 0x234 */ u8 textureBlend; // 0 = statue textures; 255 = enemy textures
    /* 0x236 */ s16 explodeTimer; // timer counting down till armos explodes
    /* 0x238 */ s16 returnHomeTimer; // Timer that counts down till an armos will return to its spawn position
    /* 0x23A */ s16 unkFlag;
    /* 0x23C */ s16 armosYaw; // Yaw of Armos
    /* 0x240 */ f32 speed; // Hopping speed of Armos
    /* 0x244 */ f32 drawDmgEffAlpha;
    /* 0x248 */ f32 drawDmgEffScale;
    /* 0x24C */ Vec3f limbPos[13];
    /* 0x2E8 */ ColliderCylinder enemyCollider; // Collider for when Armos is Hostile
    /* 0x334 */ ColliderCylinder interactCollider; // Collider for when an interactable Armos is docile
} EnAm; // size = 0x380

#endif // Z_EN_AM_H
