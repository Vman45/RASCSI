//---------------------------------------------------------------------------
//
//	SCSI Target Emulator RaSCSI (*^..^*)
//	for Raspberry Pi
//
//	Powered by XM6 TypeG Technology.
//	Copyright (C) 2016-2020 GIMONS
//
//	[ Common Definition ]
//
//---------------------------------------------------------------------------

#if !defined(xm6_h)
#define xm6_h

//---------------------------------------------------------------------------
//
//	VERSION
//
//---------------------------------------------------------------------------
#define VERSION 0x0147

//---------------------------------------------------------------------------
//
//	RaSCSI
//
//---------------------------------------------------------------------------
#define RASCSI VERSION

//---------------------------------------------------------------------------
//
//	ID Macro
//
//---------------------------------------------------------------------------
#define MAKEID(a, b, c, d)	((DWORD)((a<<24) | (b<<16) | (c<<8) | d))

//---------------------------------------------------------------------------
//
//	Various Operation Settings
//
//---------------------------------------------------------------------------
// For now, USE_SEL_EVENT_ENABLE is incompatible with the Nuvolink functionality.
//   See https://github.com/akuker/RASCSI/issues/27 for more information
//#define USE_SEL_EVENT_ENABLE			// Check SEL signal by event
#define REMOVE_FIXED_SASIHD_SIZE		// remove the size limitation of SASIHD
#define USE_MZ1F23_1024_SUPPORT			// MZ-1F23 (SASI 20M/sector size 1024)

//---------------------------------------------------------------------------
//
//	Class Declaration
//
//---------------------------------------------------------------------------
class Fileio;
										// File I/O
class Disk;
										// SASI/SCSI Disk
class Filepath;
										// File Path

#endif	// xm6_h
