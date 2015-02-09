/*
 * drivers/input/tablet/wacom_wac.h
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 */
#ifndef WACOM_WAC_H
#define WACOM_WAC_H

#include <linux/types.h>

/* maximum packet length for USB devices */
#define WACOM_PKGLEN_MAX	68

/* packet length for individual models */
#define WACOM_PKGLEN_PENPRTN	 7
#define WACOM_PKGLEN_GRAPHIRE	 8
#define WACOM_PKGLEN_BBFUN	 9
#define WACOM_PKGLEN_INTUOS	10
#define WACOM_PKGLEN_TPC1FG	 5
#define WACOM_PKGLEN_TPC1FG_B	10
#define WACOM_PKGLEN_TPC2FG	14
#define WACOM_PKGLEN_BBTOUCH	20
#define WACOM_PKGLEN_MTOUCH	62
#define WACOM_PKGLEN_BBTOUCH3   64
#define WACOM_PKGLEN_DTUS	68

/* device IDs */
#define STYLUS_DEVICE_ID	0x02
#define TOUCH_DEVICE_ID		0x03
#define CURSOR_DEVICE_ID	0x06
#define ERASER_DEVICE_ID	0x0A
#define PAD_DEVICE_ID		0x0F

/* wacom data packet report IDs */
#define WACOM_REPORT_PENABLED		2
#define WACOM_REPORT_INTUOSREAD		5
#define WACOM_REPORT_INTUOSWRITE	6
#define WACOM_REPORT_INTUOSPAD		12
#define WACOM_REPORT_INTUOS5PAD         3
#define WACOM_REPORT_DTUSPAD		21
#define WACOM_REPORT_TPC1FG		6
#define WACOM_REPORT_TPCMT		13
#define WACOM_REPORT_TPCHID		15
#define WACOM_REPORT_TPCST		16
#define WACOM_REPORT_DTUS		17

/* wacom data size per MT contact */
#define WACOM_BYTES_PER_MT_PACKET	11

/* device quirks */
#define WACOM_QUIRK_MULTI_INPUT		0x0001
#define WACOM_QUIRK_BBTOUCH_LOWRES	0x0002

/* largest reported tracking id */
#define MAX_TRACKING_ID			0xffff

enum {
	PENPARTNER = 0,
	GRAPHIRE,
	WACOM_G4,
	PTU,
	PL,
	DTU,
	DTUS,
	DTUSX,
	BAMBOO_PT,
	INTUOS,
	INTUOS3S,
	INTUOS3,
	INTUOS3L,
	INTUOS4S,
	INTUOS4,
	INTUOS4L,
	INTUOS5S,
	INTUOS5,
	INTUOS5L,
	INTUOSPS,
	INTUOSPM,
	INTUOSPL,
	WACOM_21UX2,
	WACOM_22HD,
	DTK,
	WACOM_24HD,
	CINTIQ,
	WACOM_BEE,
	WACOM_13HD,
	WACOM_MO,
	TABLETPC,
	TABLETPCE,
	TABLETPC2FG,
	MTSCREEN,
	MAX_TYPE
};

struct wacom_features {
	const char *name;
	int pktlen;
	int x_max;
	int y_max;
	int pressure_max;
	int distance_max;
	int type;
	int x_resolution;
	int y_resolution;
	int x_min;
	int y_min;
	int device_type;
	int x_phy;
	int y_phy;
	unsigned char unit;
	unsigned char unitExpo;
	int x_fuzz;
	int y_fuzz;
	int pressure_fuzz;
	int distance_fuzz;
	unsigned quirks;
	unsigned touch_max;
	unsigned num_contacts;
	unsigned num_contacts_left;
};

struct wacom_shared {
	bool stylus_in_proximity;
	bool touch_down;
};

struct wacom_wac {
	char name[64];
	unsigned char *data;
	int tool[2];
	int id[2];
	__u32 serial[2];
	bool reporting_data;
	int trk_id;
	struct wacom_features features;
	struct wacom_shared *shared;
	struct input_dev *input;
	int pid;
};

#endif
