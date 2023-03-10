/*
 * システム名?ﾌ?Fソフトウェアライブラリ
 *
 * モジュ?[ル記??名?ﾌ?Fsega_xpt.h
 *
 * モジュ?[ル名?ﾌ?Fライブラリ共通ヘッダファイル
 *
 * 目的?F(1)他マシン移?Aを簡単にするため
 *       (2)プ??グラムを解?ﾍしやすくするため
 *
 * 適用範囲?Fプ??グラミング全般?iライブラリ開発者?Aライブラリ使用者の両方が使
 *           用できる?j
 *
 * 前提?????Fここで?骭ｾ?A定義している識別子と同じ意味の?骭ｾ?A定義を他ファイル
 *           でしてはいけない?B
 * 
 * AUTHOR?FVer1.00  N.T 1993/12/22
 *         Ver1.01  N.T 1993/12/27
 *         Ver1.02  N.T 1994/01/06
 *         Ver1.03  N.T 1994/02/23
 *         Ver1.04  N.T 1994/02/23
 *
 * DATE?F1994-07-29
 */


#ifndef SEGA_XPT_H
#define SEGA_XPT_H

/*****************************************************************************/
/****************************** 基本デ?[タ型?骭ｾ *****************************/
/*****************************************************************************/

typedef unsigned    char    Uint8;      /* 符??なし１バイト?ｮ?? */
typedef signed      char    Sint8;      /* 符??つき１バイト?ｮ?? */
typedef unsigned    short   Uint16;     /* 符??なし２バイト?ｮ?? */
typedef signed      short   Sint16;     /* 符??つき２バイト?ｮ?? */
typedef unsigned    long    Uint32;     /* 符??なし４バイト?ｮ?? */
typedef signed      long    Sint32;     /* 符??つき４バイト?ｮ?? */
typedef float               Float32;    /* ４バイト実?? */
typedef double              Float64;    /* ８バイト実?? */

typedef int                 Int;        /* INT型?iツ?[ル用?j            */

typedef int                 Bool;       /* 論??型?i論??定?狽?値にとる?j */

/*****************************************************************************/
/********************************* 定?買}ク?? ********************************/
/*****************************************************************************/

#ifndef NULL
#define NULL    ((void *)0)             /* NULL */
#endif  /* NULL */

/*****************************************************************************/
/********************************** 列挙定?? *********************************/
/*****************************************************************************/

enum BooleanLogic {                     /* 論??定?狽P?i偽?A?^?j */
    FALSE = 0,
    TRUE  = 1
};

enum BooleanSwitch {                    /* 論??定?狽Q?iスイッチ?j */
    OFF = 0,
    ON  = 1
};

enum Judgement {                        /* 結果判定の定???i?ｬ功?A失敗?j */
    OK = 0,                             /* ?ｬ功 */
    NG = -1                             /* 失敗 */
};

/*****************************************************************************/
/********************************* ????マク?? ********************************/
/*****************************************************************************/

#define MAX(x, y)       ((x) > (y) ? (x) : (y)) /* ?ﾅ大値 */
#define MIN(x, y)       ((x) < (y) ? (x) : (y)) /* ?ﾅ?ｬ値 */
#define ABS(x)          ((x) < 0 ? -(x) : (x))  /* ?竭ﾎ値 */

#endif  /* SEGA_XPT_H */
