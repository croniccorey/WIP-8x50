/*
 * Copyright (c) 2011 Bosch Sensortec GmbH
 * Copyright (c) 2011 Unixphere
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#ifndef _BMA150_H_
#define _BMA150_H_

#include <linux/ioctl.h>

#define BMA150_I2C_NAME			"bma150"
#ifdef CONFIG_SPI_QSD
#define BMA150_G_SENSOR_NAME		"bma150_uP_spi"
#else
#define BMA150_G_SENSOR_NAME		"bma150"
#endif

#define BMAIO				0xA1

/* BMA150 register address */
#define CHIP_ID_REG			0x00
#define VERSION_REG			0x01
#define X_AXIS_LSB_REG			0x02
#define X_AXIS_MSB_REG			0x03
#define Y_AXIS_LSB_REG			0x04
#define Y_AXIS_MSB_REG			0x05
#define Z_AXIS_LSB_REG			0x06
#define Z_AXIS_MSB_REG			0x07
#define TEMP_RD_REG			0x08
#define SMB150_STATUS_REG		0x09
#define SMB150_CTRL_REG			0x0a
#define SMB150_CONF1_REG		0x0b
#define LG_THRESHOLD_REG		0x0c
#define LG_DURATION_REG			0x0d
#define HG_THRESHOLD_REG		0x0e
#define HG_DURATION_REG			0x0f
#define MOTION_THRS_REG			0x10
#define HYSTERESIS_REG			0x11
#define CUSTOMER1_REG			0x12
#define CUSTOMER2_REG			0x13
#define RANGE_BWIDTH_REG		0x14
#define SMB150_CONF2_REG		0x15

#define OFFS_GAIN_X_REG			0x16
#define OFFS_GAIN_Y_REG			0x17
#define OFFS_GAIN_Z_REG			0x18
#define OFFS_GAIN_T_REG			0x19
#define OFFSET_X_REG			0x1a
#define OFFSET_Y_REG			0x1b
#define OFFSET_Z_REG			0x1c
#define OFFSET_T_REG			0x1d


/* IOCTLs*/
#define BMA_IOCTL_INIT			_IO(BMAIO, 0x31)
#define BMA_IOCTL_WRITE			_IOW(BMAIO, 0x32, char[5])
#define BMA_IOCTL_READ			_IOWR(BMAIO, 0x33, char[5])
#define BMA_IOCTL_READ_ACCELERATION	_IOWR(BMAIO, 0x34, short[7])
#define BMA_IOCTL_SET_MODE		_IOW(BMAIO, 0x35, short)
#define BMA_IOCTL_GET_INT		_IOR(BMAIO, 0x36, short)
#define BMA_IOCTL_GET_CHIP_LAYOUT	_IOR(BMAIO, 0x37, short)

/* range and bandwidth */
#define BMA_RANGE_2G			0
#define BMA_RANGE_4G			1
#define BMA_RANGE_8G			2

#define BMA_BW_25HZ			0
#define BMA_BW_50HZ			1
#define BMA_BW_100HZ			2
#define BMA_BW_190HZ			3
#define BMA_BW_375HZ			4
#define BMA_BW_750HZ			5
#define BMA_BW_1500HZ			6

/* mode settings */
#define BMA_MODE_NORMAL			0
#define BMA_MODE_SLEEP			1

struct bma150_platform_data {
	int intr;
	int microp_new_cmd;
	int chip_layout;
};

#endif /* _BMA150_H_ */
