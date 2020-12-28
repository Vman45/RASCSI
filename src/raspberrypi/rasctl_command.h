//---------------------------------------------------------------------------
//
//	SCSI Target Emulator RaSCSI (*^..^*)
//	for Raspberry Pi
//
//	Powered by XM6 TypeG Technology.
//	Copyright (C) 2016-2020 GIMONS
//  Copyright (C) akuker
//
//	[ Send Control Command ]
//
//---------------------------------------------------------------------------
#pragma once

#include "os.h"

// Todo - this is a clone of the declaration in rascsi.cpp. This is sloppy!!! Fix this!!
#ifndef CtrlMax
#define CtrlMax	8					// Maximum number of SCSI controllers
#define UnitNum	2					// Number of units around controller
#endif 

enum rasctl_command : int {
    rasctl_cmd_invalid  = -1,
    rasctl_cmd_attach   =  0,
    rasctl_cmd_detach   =  1,
    rasctl_cmd_insert   =  2,
    rasctl_cmd_eject    =  3,
    rasctl_cmd_protect  =  4,
    rasctl_cmd_list     =  5,
    rasctl_cmd_op       =  6,
    rasctl_cmd_shutdown =  7,
};

enum rasctl_dev_type : int {
    rasctl_dev_invalid = -1,
    rasctl_dev_sasi_hd =  0,
    rasctl_dev_scsi_hd =  1,
    rasctl_dev_mo      =  2,
    rasctl_dev_cd      =  3,
    rasctl_dev_br      =  4,
    rasctl_dev_scsi_hd_appl =  5,
    rasctl_dev_scsi_hd_nec  =  6,
};


class Rasctl_Command{
    public:
        void Serialize(char *buff, int max_buff_size);
        static Rasctl_Command* DeSerialize(char* buff, int size);
        BOOL IsValid(FILE *fp);


        rasctl_command cmd = rasctl_cmd_invalid;
        rasctl_dev_type type = rasctl_dev_invalid;
        int id = -1;
        int un = -1; 
        char file[_MAX_PATH] = "";

        static BOOL rasctl_dev_is_hd(rasctl_dev_type dev);
        static const uint16_t PortNumber;

        static rasctl_dev_type DeviceTypeFromFilename(FILE *fp, const char* filename);

    private:
        static const char* m_delimiter; // Record separator charater
        static const char* m_no_file; // Special character sequence indicating an empty file name.


        enum serial_token_order : int {
            serial_token_first_token = 0,
            serial_token_id = 0,
            serial_token_un = 1,
            serial_token_cmd = 2,
            serial_token_type = 3,
            serial_token_file_name = 4,
            serial_token_last_token = 5,
        };

    static const char* dev_type_lookup[];
};