/*
 * Copyright (C) 2019 Samsung Electronics
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
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA
 *
 */

#ifndef __S2MU107_MUIC_H__
#define __S2MU107_MUIC_H__

#include <linux/wakelock.h>
#include <linux/muic/muic.h>
#include <linux/muic/muic_interface.h>
#if defined (CONFIG_HV_MUIC_S2MU107_AFC)
#include <linux/muic/s2mu107-muic-hv.h>
#endif

#define MUIC_DEV_NAME	"muic-s2mu107"

enum s2mu107_muic_registers {
	S2MU107_REG_AFC_INT =		0x00,
	S2MU107_REG_MUIC_INT1 =		0x01,
	S2MU107_REG_MUIC_INT2 =		0x02,
	S2MU107_REG_AFC_INT_MASK = 	0x08,
	S2MU107_REG_MUIC_INT1_MASK =	0x09,
	S2MU107_REG_MUIC_INT2_MASK = 	0x0A,
	S2MU107_REG_AFC_STATUS = 	0x10,
	S2MU107_REG_AFC_CTRL1 =		0x2D,
	S2MU107_REG_AFC_CTRL2 =		0x2E,
	S2MU107_REG_AFC_TX_BYTE = 	0x2F,
	S2MU107_REG_AFC_RX_BYTE1 = 	0x30,
	S2MU107_REG_AFC_RX_BYTE2 = 	0x31,
	S2MU107_REG_AFC_RX_BYTE3 = 	0x32,
	S2MU107_REG_AFC_RX_BYTE4 = 	0x33,
	S2MU107_REG_AFC_RX_BYTE5 = 	0x34,
	S2MU107_REG_AFC_RX_BYTE6 = 	0x35,
	S2MU107_REG_AFC_RX_BYTE7 = 	0x36,
	S2MU107_REG_AFC_RX_BYTE8 = 	0x37,
	S2MU107_REG_AFC_RX_BYTE9 = 	0x38,
	S2MU107_REG_AFC_RX_BYTE10 = 	0x39,
	S2MU107_REG_AFC_RX_BYTE11 = 	0x3A,
	S2MU107_REG_AFC_RX_BYTE12 = 	0x3B,
	S2MU107_REG_AFC_RX_BYTE13 = 	0x3C,
	S2MU107_REG_AFC_RX_BYTE14 = 	0x3D,
	S2MU107_REG_AFC_RX_BYTE15 = 	0x3E,
	S2MU107_REG_AFC_RX_BYTE16 = 	0x3F,
	S2MU107_REG_AFC_LOGIC_RDATA1 =	0x40,
	S2MU107_REG_AFC_LOGIC_RDATA2 = 	0x41,
	S2MU107_REG_AFC_LOGIC_CTRL1 = 	0x42,
	S2MU107_REG_AFC_LOGIC_CTRL2 = 	0x43,
	S2MU107_REG_AFC_LOGIC_RDATA3 = 	0x44,
	S2MU107_REG_QC30_DP_STEP = 	0x45,
	S2MU107_REG_QC30_DM_STEP =	0x46,
	S2MU107_REG_AFC_MONITOR =	0x47,
	S2MU107_REG_ADC_VALUE =		0x48,
	S2MU107_REG_DEVICE_TYP1 =	0x49,
	S2MU107_REG_DEVICE_TYP2 = 	0x4A,
	S2MU107_REG_DEVICE_TYP3 = 	0x4B,
	S2MU107_REG_RESET = 		0x4E,
	S2MU107_REG_CHG_TYP = 		0x4F,
	S2MU107_REG_DEVICE_APPLE = 	0x50,
	S2MU107_REG_BCD_RESCAN = 	0x51,
	S2MU107_REG_TEST1 = 		0x52,
	S2MU107_REG_TEST2 = 		0x53,
	S2MU107_REG_TEST3 = 		0x54,
	S2MU107_REG_WATER_WARN_FLAG = 	0x55,
	S2MU107_REG_AFC_OTP0 = 		0x64,
	S2MU107_REG_AFC_OTP1 = 		0x65,
	S2MU107_REG_AFC_OTP2 = 		0x66,
	S2MU107_REG_AFC_OTP3 = 		0x67,
	S2MU107_REG_AFC_OTP4 = 		0x68,
	S2MU107_REG_AFC_OTP5 = 		0x69,
	S2MU107_REG_AFC_OTP6 = 		0x6A,
	S2MU107_REG_AFC_OTP7 = 		0x6B,
	S2MU107_REG_MUIC_CTRL1 = 	0x6C,
	S2MU107_REG_TIMER_SET1 = 	0x6D,
	S2MU107_REG_TIMER_SET2 = 	0x6E,
	S2MU107_REG_MANUAL_SW_CTRL = 	0x6F,
	S2MU107_REG_TIMER_SET3 = 	0x70,
	S2MU107_REG_MUIC_CTRL2 = 	0x71,
	S2MU107_REG_MUIC_CTRL3 = 	0x72,
	S2MU107_REG_CHARGER_DET_OTP = 	0x73,
	S2MU107_REG_ADC_VREF_OTP = 	0x74,
	S2MU107_REG_ADCBIAS_OTP1 = 	0x75,
	S2MU107_REG_ADCBIAS_OTP2 = 	0x76,
	S2MU107_REG_ADCBIAS_OTP3 = 	0x77,
	S2MU107_REG_ADCBIAS_OTP4 = 	0x78,
	S2MU107_REG_LDOADC_VSETL = 	0x79,
	S2MU107_REG_LDOADC_VSETH = 	0x7A,
	S2MU107_REG_LDOPCP_VSET_OTP = 	0x7B,
	S2MU107_REG_MONITOR_SEL = 	0x7C,
	S2MU107_REG_RID_WATER_PROOF = 	0x7D,
	S2MU107_REG_RID_DISCHARGE = 	0x7E,
	S2MU107_REG_MUIC_RSVD1 = 	0x7F,
	S2MU107_REG_MUIC_RSVD2 = 	0x80,
	S2MU107_REG_MUIC_RSVD3 = 	0x81,
	S2MU107_REG_MUIC_RSVD4 = 	0x82,
	S2MU107_REG_MUIC_RSVD5 = 	0x83,
};

/* s2mu107 muic register read/write related information defines. */
/* S2MU107 Control register */
/* S2MU107 MUIC_INT1 register (0x01)*/
#define MUIC_INT1_WAKE_UP_I_SHIFT		7
#define MUIC_INT1_USB_KILLER_I_SHIFT		6
#define MUIC_INT1_RID_CHG_I_SHIFT		5
#define MUIC_INT1_LKR_I_SHIFT			4
#define MUIC_INT1_LKP_I_SHIFT			3
#define MUIC_INT1_KP_I_SHIFT			2
#define MUIC_INT1_DETACH_I_SHIFT		1
#define MUIC_INT1_ATTACH_I_SHIFT		0

#define MUIC_INT1_WAKE_UP_I_MASK		(0x1 << MUIC_INT1_WAKE_UP_I_SHIFT)
#define MUIC_INT1_USB_KILLER_I_MASK		(0x1 << MUIC_INT1_USB_KILLER_I_SHIFT)
#define MUIC_INT1_RID_CHG_I_MASK		(0x1 << MUIC_INT1_RID_CHG_I_SHIFT)
#define MUIC_INT1_LKR_I_MASK			(0x1 << MUIC_INT1_LKR_I_SHIFT)
#define MUIC_INT1_LKP_I_MASK			(0x1 << MUIC_INT1_LKP_I_SHIFT)
#define MUIC_INT1_KP_I_MASK			(0x1 << MUIC_INT1_KP_I_SHIFT)
#define MUIC_INT1_DETACH_I_MASK			(0x1 << MUIC_INT1_DETACH_I_SHIFT)
#define MUIC_INT1_ATTACH_I_MASK			(0x1 << MUIC_INT1_ATTACH_I_SHIFT)

/* S2MU107 MUIC_INT2 register (0x02)*/
#define MUIC_INT2_VBUS_OFF_I_SHIFT		7
#define MUIC_INT2_AV_CHARGE_I_SHIFT		6
#define MUIC_INT2_MHDL_I_SHIFT			5
#define MUIC_INT2_STUCKRCV_I_SHIFT		4
#define MUIC_INT2_STUCK_I_SHIFT			3
#define MUIC_INT2_ADCCHANGE_I_SHIFT		2
#define MUIC_INT2_RSVD_ATTACH_I_SHIFT		1
#define MUIC_INT2_VBUS_ON_I_SHIFT		0

#define MUIC_INT2_VBUS_OFF_I_MASK		(0x1 << MUIC_INT2_VBUS_OFF_I_SHIFT)
#define MUIC_INT2_AV_CHARGE_I_MASK		(0x1 << MUIC_INT2_AV_CHARGE_I_SHIFT)
#define MUIC_INT2_MHDL_I_MASK			(0x1 << MUIC_INT2_MHDL_I_SHIFT)
#define MUIC_INT2_STUCKRCV_I_MASK		(0x1 << MUIC_INT2_STUCKRCV_I_SHIFT)
#define MUIC_INT2_STUCK_I_MASK			(0x1 << MUIC_INT2_STUCK_I_SHIFT)
#define MUIC_INT2_ADCCHANGE_I_MASK		(0x1 << MUIC_INT2_ADCCHANGE_I_SHIFT)
#define MUIC_INT2_RSVD_ATTACH_I_MASK 		(0x1 << MUIC_INT2_RSVD_ATTACH_I_SHIFT)
#define MUIC_INT2_VBUS_ON_I_MASK		(0x1 << MUIC_INT2_VBUS_ON_I_SHIFT)

/* S2MU107 MUIC_INT1_MASK register (0x09)*/
#define MUIC_INT1_MASK_WAKE_UP_Im_SHIFT		7
#define MUIC_INT1_MASK_USB_KILLER_Im_SHIFT	6
#define MUIC_INT1_MASK_RID_CHG_Im_SHIFT		5
#define MUIC_INT1_MASK_LKR_Im_SHIFT		4
#define MUIC_INT1_MASK_LKP_Im_SHIFT		3
#define MUIC_INT1_MASK_KP_Im_SHIFT		2
#define MUIC_INT1_MASK_DETACH_Im_SHIFT		1
#define MUIC_INT1_MASK_ATTACH_Im_SHIFT		0

#define MUIC_INT1_MASK_WAKE_UP_Im_MASK		(0x1 << MUIC_INT1_MASK_WAKE_UP_Im_SHIFT)
#define MUIC_INT1_MASK_USB_KILLER_Im_MASK	(0x1 << MUIC_INT1_MASK_USB_KILLER_Im_SHIFT)
#define MUIC_INT1_MASK_RID_CHG_Im_MASK		(0x1 << MUIC_INT1_MASK_RID_CHG_Im_SHIFT)
#define MUIC_INT1_MASK_LKR_Im_MASK		(0x1 << MUIC_INT1_MASK_LKR_Im_SHIFT)
#define MUIC_INT1_MASK_LKP_Im_MASK		(0x1 << MUIC_INT1_MASK_LKP_Im_SHIFT)
#define MUIC_INT1_MASK_KP_Im_MASK		(0x1 << MUIC_INT1_MASK_KP_Im_SHIFT)
#define MUIC_INT1_MASK_DETACH_Im_MASK		(0x1 << MUIC_INT1_MASK_DETACH_Im_SHIFT)
#define MUIC_INT1_MASK_ATTACH_Im_MASK		(0x1 << MUIC_INT1_MASK_ATTACH_Im_SHIFT)

/* S2MU107 MUIC_INT2_MASK register (0x0A)*/
#define MUIC_INT2_MASK_VBUS_OFF_Im_SHIFT	7
#define MUIC_INT2_MASK_AV_CHARGE_Im_SHIFT	6
#define MUIC_INT2_MASK_MHDL_Im_SHIFT		5
#define MUIC_INT2_MASK_STUCKRCV_Im_SHIFT	4
#define MUIC_INT2_MASK_STUCK_Im_SHIFT		3
#define MUIC_INT2_MASK_ADCCHANGE_Im_SHIFT	2
#define MUIC_INT2_MASK_RSVD_ATTACH_Im_SHIFT	1
#define MUIC_INT2_MASK_VBUS_ON_Im_SHIFT		0

#define MUIC_INT2_MASK_VBUS_OFF_Im_MASK		(0x1 << MUIC_INT2_MASK_VBUS_OFF_Im_SHIFT)
#define MUIC_INT2_MASK_AV_CHARGE_Im_MASK	(0x1 << MUIC_INT2_MASK_AV_CHARGE_Im_SHIFT)
#define MUIC_INT2_MASK_MHDL_Im_MASK		(0x1 << MUIC_INT2_MASK_MHDL_Im_SHIFT)
#define MUIC_INT2_MASK_STUCKRCV_Im_MASK		(0x1 << MUIC_INT2_MASK_STUCKRCV_Im_SHIFT)
#define MUIC_INT2_MASK_STUCK_Im_MASK		(0x1 << MUIC_INT2_MASK_STUCK_Im_SHIFT)
#define MUIC_INT2_MASK_ADCCHANGE_Im_MASK	(0x1 << MUIC_INT2_MASK_ADCCHANGE_Im_SHIFT)
#define MUIC_INT2_MASK_RSVD_ATTACH_Im_MASK 	(0x1 << MUIC_INT2_MASK_RSVD_ATTACH_Im_SHIFT)
#define MUIC_INT2_MASK_VBUS_ON_Im_MASK		(0x1 << MUIC_INT2_MASK_VBUS_ON_Im_SHIFT)

/*
 * S2MU107 MUIC Interrupt Maksing for pdic
 * Use Attach, Detach, VBUS On, ADC Change, VBUS Off.
 */
#define INT_MUIC_MASK1				(0xFC)
#define INT_MUIC_MASK2				(0x7A)

#define INT_USBKILLER_MASK1			(0xBD)
#define ADC_MASK				(0x1f)

/* S2MU107 ADC_VALUE register (0x48) */
#define ADC_VALUE_ADCERR_SHIFT			7
#define ADC_VALUE_ADCVAL_SHIFT			0

#define ADC_VALUE_ADCERR_MASK			(0x1 << ADC_VALUE_ADCERR_SHIFT)
#define ADC_VALUE_ADCVAL_MASK			(0x1F << ADC_VALUE_ADCVAL_SHIFT)

/* S2MU107 DEVICE_TYP1 register (0x49)*/
#define DEVICE_TYP1_USBOTG_SHIFT		7
#define DEVICE_TYP1_DCPCHG_SHIFT		6
#define DEVICE_TYP1_CDPCHG_SHIFT		5
#define DEVICE_TYP1_CARKIT_SHIFT		4
#define DEVICE_TYP1_UART_SHIFT			3
#define DEVICE_TYP1_USB_SHIFT			2
#define DEVICE_TYP1_AUDIOTYP2_SHIFT		1
#define DEVICE_TYP1_AUDIOTYP1_SHIFT		0

#define DEVICE_TYP1_USBOTG_MASK			(0x1 << DEVICE_TYP1_USBOTG_SHIFT)
#define DEVICE_TYP1_DCPCHG_MASK			(0x1 << DEVICE_TYP1_DCPCHG_SHIFT)
#define DEVICE_TYP1_CDPCHG_MASK			(0x1 << DEVICE_TYP1_CDPCHG_SHIFT)
#define DEVICE_TYP1_CARKIT_MASK			(0x1 << DEVICE_TYP1_CARKIT_SHIFT)
#define DEVICE_TYP1_UART_MASK			(0x1 << DEVICE_TYP1_UART_SHIFT)
#define DEVICE_TYP1_USB_MASK			(0x1 << DEVICE_TYP1_USB_SHIFT)
#define DEVICE_TYP1_AUDIOTYP2_MASK		(0x1 << DEVICE_TYP1_AUDIOTYP2_SHIFT)
#define DEVICE_TYP1_AUDIOTYP1_MASK		(0x1 << DEVICE_TYP1_AUDIOTYP1_SHIFT)

/* S2MU107 DEVICE_TYP2 register (0x4A) */
#define DEVICE_TYP2_SDP_1P8S_SHIFT		7
#define DEVICE_TYP2_AV_SHIFT			6
#define DEVICE_TYP2_TTY_SHIFT			5
#define DEVICE_TYP2_PPD_SHIFT			4
#define DEVICE_TYP2_JIGUARTOFF_SHIFT		3
#define DEVICE_TYP2_JIGUARTON_SHIFT		2
#define DEVICE_TYP2_JIGUSBOFF_SHIFT		1
#define DEVICE_TYP2_JIGUSBON_SHIFT		0

#define DEVICE_TYP2_SDP_1P8S_MASK		(0x1 << DEVICE_TYP2_SDP_1P8S_SHIFT)
#define DEVICE_TYP2_AV_MASK			(0x1 << DEVICE_TYP2_AV_SHIFT)
#define DEVICE_TYP2_TTY_MASK			(0x1 << DEVICE_TYP2_TTY_SHIFT)
#define DEVICE_TYP2_PPD_MASK			(0x1 << DEVICE_TYP2_PPD_SHIFT)
#define DEVICE_TYP2_JIGUARTOFF_MASK		(0x1 << DEVICE_TYP2_JIGUARTOFF_SHIFT)
#define DEVICE_TYP2_JIGUARTON_MASK		(0x1 << DEVICE_TYP2_JIGUARTON_SHIFT)
#define DEVICE_TYP2_JIGUSBOFF_MASK		(0x1 << DEVICE_TYP2_JIGUSBOFF_SHIFT)
#define DEVICE_TYP2_JIGUSBON_MASK		(0x1 << DEVICE_TYP2_JIGUSBON_SHIFT)

/* S2MU107 DEVICE_TYP3 register (0x4B) */
#define DEVICE_TYP3_U200_CHG_SHIFT		7
#define DEVICE_TYP3_USB_KILLER_SHIFT		6
#define DEVICE_TYP3_AV_VBUS_SHIFT		4
#define DEVICE_TYP3_CARKIT_TYPE_SHIFT		3
#define DEVICE_TYP3_VBUS_R255_SHIFT		1
#define DEVICE_TYP3_MHDL_SHIFT			0

#define DEVICE_TYP3_U200_CHG_MASK		(0x1 << DEVICE_TYP3_U200_CHG_SHIFT)
#define DEVICE_TYP3_USB_KILLER_MASK		(0x1 << DEVICE_TYP3_USB_KILLER_SHIFT)
#define DEVICE_TYP3_AV_VBUS_MASK		(0x1 << DEVICE_TYP3_AV_VBUS_SHIFT)
#define DEVICE_TYP3_CARKIT_TYPE_MASK		(0x3 << DEVICE_TYP3_CARKIT_TYPE_SHIFT)
#define DEVICE_TYP3_VBUS_R255_MASK		(0x1 << DEVICE_TYP3_VBUS_R255_SHIFT)
#define DEVICE_TYP3_MHDL_MASK			(0x1 << DEVICE_TYP3_MHDL_SHIFT)

/* S2MU107 MUIC CHG_TYP Register (0x4D) */
#define CHG_TYP_VBUS_R255_SHIFT		7
#define CHG_TYP_OPPO_DCP_SHIFT		6
#define CHG_TYP_DP_3V_SDP_SHIFT		5
#define CHG_TYP_U200_SHIFT		4
#define CHG_TYP_SDP_1P8S_SHIFT		3
#define CHG_TYP_USB_SHIFT		2
#define CHG_TYP_CDPCHG_SHIFT		1
#define CHG_TYP_DCPCHG_SHIFT		0

#define CHG_TYP_VBUS_R255_MASK		(0x1 << CHG_TYP_VBUS_R255_SHIFT)
#define CHG_TYP_OPPO_DCP_MASK		(0x1 << CHG_TYP_OPPO_DCP_SHIFT)
#define CHG_TYP_DP_3V_SDP_MASK		(0x1 << CHG_TYP_DP_3V_SDP_SHIFT)
#define CHG_TYP_U200_MASK		(0x1 << CHG_TYP_U200_SHIFT)
#define CHG_TYP_SDP_1P8S_MASK		(0x1 << CHG_TYP_SDP_1P8S_SHIFT)
#define CHG_TYP_USB_MASK		(0x1 << CHG_TYP_USB_SHIFT)
#define CHG_TYP_CDPCHG_MASK		(0x1 << CHG_TYP_CDPCHG_SHIFT)
#define CHG_TYP_DCPCHG_MASK		(0x1 << CHG_TYP_DCPCHG_SHIFT)

#define DEV_TYPE_CHG_TYPE		(CHG_TYP_VBUS_R255_MASK | CHG_TYP_U200_MASK \
						| CHG_TYP_SDP_1P8S_MASK)

/* S2MU107 MUIC DEVICE_APPLE Register (0x50) */
#define DEVICE_APPLE_APPLE0P5A_CHG_SHIFT	7
#define DEVICE_APPLE_APPLE1A_CHG_SHIFT		6
#define DEVICE_APPLE_APPLE2A_CHG_SHIFT		5
#define DEVICE_APPLE_APPLE2P4A_CHG_SHIFT	4
#define DEVICE_APPLE_SDP_DCD_OUT_SHIFT		3
#define DEVICE_APPLE_RID_WAKEUP_SHIFT		2
#define DEVICE_APPLE_VBUS_WAKEUP_SHIFT		1
#define DEVICE_APPLE_BCV1P2_OR_OPEN_SHIFT	0

#define DEVICE_APPLE_APPLE0P5A_CHG_MASK		(0x1 << DEVICE_APPLE_APPLE0P5A_CHG_SHIFT)
#define DEVICE_APPLE_APPLE1A_CHG_MASK		(0x1 << DEVICE_APPLE_APPLE1A_CHG_SHIFT)
#define DEVICE_APPLE_APPLE2A_CHG_MASK		(0x1 << DEVICE_APPLE_APPLE2A_CHG_SHIFT)
#define DEVICE_APPLE_APPLE2P4A_CHG_MASK		(0x1 << DEVICE_APPLE_APPLE2P4A_CHG_SHIFT)
#define DEVICE_APPLE_SDP_DCD_OUT_MASK		(0x1 << DEVICE_APPLE_SDP_DCD_OUT_SHIFT)
#define DEVICE_APPLE_RID_WAKEUP_MASK		(0x1 << DEVICE_APPLE_RID_WAKEUP_SHIFT)
#define DEVICE_APPLE_VBUS_WAKEUP_MASK		(0x1 << DEVICE_APPLE_VBUS_WAKEUP_SHIFT)
#define DEVICE_APPLE_BCV1P2_OR_OPEN_MASK	(0x1 << DEVICE_APPLE_BCV1P2_OR_OPEN_SHIFT)

/* S2MU107 MUIC BCD_RESCAN Register (0x51) */
#define BCD_RESCAN_BCD_RESCAN_SHIFT		0

#define BCD_RESCAN_BCD_RESCAN_MASK		(0x1 << BCD_RESCAN_BCD_RESCAN_SHIFT)

/* S2MU107 MUIC BCD_RESCAN Register (0x55) */
#define WATER_WARN_FLAG_WATER_WARN_FLAG_SHIFT	0

#define WATER_WARN_FLAG_WATER_WARN_FLAG_MASK	(0x1 << WATER_WARN_FLAG_WATER_WARN_FLAG_SHIFT)

/* S2MU107 MUIC AFC_OTP3 Register (0x67) */
#define AFC_OTP3_COMP_REF_SEL_SHIFT		5
#define AFC_OTP3_HCOMP_REF_SEL_SHIFT		0

#define AFC_OTP3_COMP_REF_SEL_MASK		(0x7 << AFC_OTP3_COMP_REF_SEL_SHIFT)
#define AFC_OTP3_HCOMP_REF_SEL_MASK		(0x1f << AFC_OTP3_HCOMP_REF_SEL_SHIFT)

#define AFC_OTP3_HCOMP_REF_SEL_1p65_MASK	(0x10 << AFC_OTP3_HCOMP_REF_SEL_SHIFT)
#define AFC_OTP3_HCOMP_REF_SEL_1p2_MASK		(0x8 << AFC_OTP3_HCOMP_REF_SEL_SHIFT)
#define AFC_OTP3_HCOMP_REF_SEL_0p6_MASK		(0x4 << AFC_OTP3_HCOMP_REF_SEL_SHIFT)
#define AFC_OTP3_HCOMP_REF_SEL_0p55_MASK	(0x2 << AFC_OTP3_HCOMP_REF_SEL_SHIFT)
#define AFC_OTP3_HCOMP_REF_SEL_0p5_MASK		(0x1 << AFC_OTP3_HCOMP_REF_SEL_SHIFT)

/* S2MU107 MUIC MUIC_CTRL1 Register (0x6C) */
#define MUIC_CTRL1_TX_DPDM_SHORT_SHIFT		7
#define MUIC_CTRL1_TX_DP_RDN_SHIFT		6
#define MUIC_CTRL1_TX_DM_RDN_SHIFT		5
#define MUIC_CTRL1_SWITCH_OPEN_SHIFT		4
#define MUIC_CTRL1_RAW_DATA_SHIFT		3
#define MUIC_CTRL1_MANUAL_SW_SHIFT		2
#define MUIC_CTRL1_WAIT_SHIFT			1
#define MUIC_CTRL1_INT_MASK_SHIFT		0

#define MUIC_CTRL1_TX_DPDM_SHORT_MASK		(0x1 << MUIC_CTRL1_TX_DPDM_SHORT_SHIFT)
#define MUIC_CTRL1_TX_DP_RDN_MASK 		(0x1 << MUIC_CTRL1_TX_DP_RDN_SHIFT)
#define MUIC_CTRL1_TX_DM_RDN_MASK 		(0x1 << MUIC_CTRL1_TX_DM_RDN_SHIFT)
#define MUIC_CTRL1_SWITCH_OPEN_MASK 		(0x1 << MUIC_CTRL1_SWITCH_OPEN_SHIFT)
#define MUIC_CTRL1_RAW_DATA_MASK		(0x1 << MUIC_CTRL1_RAW_DATA_SHIFT)
#define MUIC_CTRL1_MANUAL_SW_MASK 		(0x1 << MUIC_CTRL1_MANUAL_SW_SHIFT)
#define MUIC_CTRL1_WAIT_MASK 			(0x1 << MUIC_CTRL1_WAIT_SHIFT)
#define MUIC_CTRL1_INT_MASK_MASK 		(0x1 << MUIC_CTRL1_INT_MASK_SHIFT)

/* S2MU107 MUIC TIMER_SET1 Register (0x6D) */
#define TIMER_SET1_KEY_PRESS_SHIFT 		4
#define TIMER_SET1_VBUS_RISE_DEB_SEL_SHIFT 	3
#define TIMER_SET1_VBUS_FALL_DEB_SEL_SHIFT 	2
#define TIMER_SET1_CLK_DIV2_SHIFT 		1
#define TIMER_SET1_EOC2x_SHIFT 			0

#define TIMER_SET1_KEY_PRESS_MASK 		(0xF << TIMER_SET1_KEY_PRESS_SHIFT)
#define TIMER_SET1_VBUS_RISE_DEB_SEL_MASK 	(0x1 << TIMER_SET1_VBUS_RISE_DEB_SEL_SHIFT)
#define TIMER_SET1_VBUS_FALL_DEB_SEL_MASK 	(0x1 << TIMER_SET1_VBUS_FALL_DEB_SEL_SHIFT)
#define TIMER_SET1_CLK_DIV2_MASK		(0x1 << TIMER_SET1_CLK_DIV2_SHIFT)
#define TIMER_SET1_EOC2x_MASK 			(0x1 << TIMER_SET1_EOC2x_SHIFT)

/* S2MU107 MUIC TIMER_SET2 Register (0x6E) */
#define TIMER_SET2_SWITCHING_WAIT_SHIFT		4
#define TIMER_SET2_LONG_KEY_PRESS_SHIFT 	0

#define TIMER_SET2_SWITCHING_WAIT_MASK 		(0xF << TIMER_SET2_SWITCHING_WAIT_SHIFT)
#define TIMER_SET2_LONG_KEY_PRESS_MASK 		(0xF << TIMER_SET2_LONG_KEY_PRESS_SHIFT)

/* S2MU107 MUIC MANUAL_SW_CTRL Register (0x6F) */
#define MANUAL_SW_CTRL_DM_SWITCHING_SHIFT 	5
#define MANUAL_SW_CTRL_DP_SWITCHING_SHIFT 	2
#define MANUAL_SW_CTRL_JIG_SHIFT 		0

#define MANUAL_SW_CTRL_DM_SWITCHING_MASK 	(0x7 << MANUAL_SW_CTRL_DM_SWITCHING_SHIFT)
#define MANUAL_SW_CTRL_DP_SWITCHING_MASK 	(0x7 << MANUAL_SW_CTRL_DP_SWITCHING_SHIFT)
#define MANUAL_SW_CTRL_JIG_MASK 		(0x1 << MANUAL_SW_CTRL_JIG_SHIFT)
/*
 * Manual Switch Control
 * D- [7:5] / D+ [4:2]
 * 000: Open all / 001: USB / 010: AUDIO / 011: UART / 100: V_AUDIO
 * rsvd[1] / JIG[0]
 * 00: Vbus to Open / 01: Vbus to Charger / 10: Vbus to MIC / 11: Vbus to VBout
 */
#define MANSW_OPEN			0
#define MANSW_USB			1
#define MANSW_UART1			2
#define MANSW_UART2			3

#define MANUAL_SW_CTRL_OPEN_MASK	(MANSW_OPEN << MANUAL_SW_CTRL_DM_SWITCHING_SHIFT | MANSW_OPEN << MANUAL_SW_CTRL_DP_SWITCHING_SHIFT)
#define MANUAL_SW_CTRL_USB_MASK		(MANSW_USB << MANUAL_SW_CTRL_DM_SWITCHING_SHIFT | MANSW_USB << MANUAL_SW_CTRL_DP_SWITCHING_SHIFT)
#define MANUAL_SW_CTRL_UART1_MASK	(MANSW_UART1 << MANUAL_SW_CTRL_DM_SWITCHING_SHIFT | MANSW_UART1 << MANUAL_SW_CTRL_DP_SWITCHING_SHIFT)
#define MANUAL_SW_CTRL_UART2_MASK	(MANSW_UART2 << MANUAL_SW_CTRL_DM_SWITCHING_SHIFT | MANSW_UART2 << MANUAL_SW_CTRL_DP_SWITCHING_SHIFT)

/* S2MU107 MUIC TIMER_SET3 Register (0x70) */
#define TIMER_SET3_JIG_WAIT_TIME_SHIFT	5
#define TIMER_SET3_ADC_PERIOD_SHIFT 	3
#define TIMER_SET3_DCDTMRSET_SHIFT 	0

#define TIMER_SET3_JIG_WAIT_TIME_MASK 	(0x7 << TIMER_SET3_JIG_WAIT_TIME_SHIFT)
#define TIMER_SET3_ADC_PERIOD_MASK 	(0x3 << TIMER_SET3_ADC_PERIOD_SHIFT)
#define TIMER_SET3_DCDTMRSET_MASK 	(0x7 << TIMER_SET3_DCDTMRSET_SHIFT)

#define DCP_TIME_250MS 			(0)
#define DCP_TIME_300MS			(1)
#define DCP_TIME_350MS			(2)
#define DCP_TIME_400MS			(3)
#define DCP_TIME_600MS			(4)
#define DCP_TIME_1200MS			(5)
#define DCP_TIME_1800MS			(6)
#define DCP_TIME_2400MS			(7)

#define TIMER_SET3_DCDTMR_250MS_MASK 	(DCP_TIME_250MS << TIMER_SET3_DCDTMRSET_SHIFT)
#define TIMER_SET3_DCDTMR_300MS_MASK 	(DCP_TIME_300MS << TIMER_SET3_DCDTMRSET_SHIFT)
#define TIMER_SET3_DCDTMR_350MS_MASK 	(DCP_TIME_400MS << TIMER_SET3_DCDTMRSET_SHIFT)
#define TIMER_SET3_DCDTMR_400MS_MASK 	(DCP_TIME_600MS << TIMER_SET3_DCDTMRSET_SHIFT)
#define TIMER_SET3_DCDTMR_600MS_MASK 	(DCP_TIME_1200MS << TIMER_SET3_DCDTMRSET_SHIFT)
#define TIMER_SET3_DCDTMR_1200MS_MASK 	(DCP_TIME_1800MS << TIMER_SET3_DCDTMRSET_SHIFT)
#define TIMER_SET3_DCDTMR_2400MS_MASK 	(DCP_TIME_2400MS << TIMER_SET3_DCDTMRSET_SHIFT)

/* S2MU107 MUIC MUIC_CTRL2 Register (0x71) */
#define MUIC_CTRL2_WAKEUP_LOOP_SEL_SHIFT	7
#define MUIC_CTRL2_ADCEN_CNTR_SHIFT 		4
#define MUIC_CTRL2_DCDTMR_OUT_EN_SHIFT 		3
#define MUIC_CTRL2_USB_2ND_EN_SHIFT 		2
#define MUIC_CTRL2_ADC_OFF_SHIFT 		1
#define MUIC_CTRL2_CPEN_SHIFT 			0

#define MUIC_CTRL2_WAKEUP_LOOP_SEL_MASK		(0x1 << MUIC_CTRL2_WAKEUP_LOOP_SEL_SHIFT)
#define MUIC_CTRL2_ADCEN_CNTR_MASK 		(0x7 << MUIC_CTRL2_ADCEN_CNTR_SHIFT)
#define MUIC_CTRL2_DCDTMR_OUT_EN_MASK 		(0x1 << MUIC_CTRL2_DCDTMR_OUT_EN_SHIFT)
#define MUIC_CTRL2_USB_2ND_EN_MASK 		(0x1 << MUIC_CTRL2_USB_2ND_EN_SHIFT)
#define MUIC_CTRL2_ADC_OFF_MASK 		(0x1 << MUIC_CTRL2_ADC_OFF_SHIFT)
#define MUIC_CTRL2_CPEN_MASK 			(0x1 << MUIC_CTRL2_CPEN_SHIFT)

#define ADCEN_CNTR_1TIME			(1)
#define ADCEN_CNTR_2TIME			(2)
#define ADCEN_CNTR_3TIME			(3)
#define ADCEN_CNTR_4TIME			(4)
#define ADCEN_CNTR_5TIME			(5)
#define ADCEN_CNTR_6TIME			(6)
#define ADCEN_CNTR_7TIME			(7)

#define MUIC_CTRL2_ADCEN_CNTR_1TIME_MASK 	(ADCEN_CNTR_1TIME << MUIC_CTRL2_ADCEN_CNTR_SHIFT)
#define MUIC_CTRL2_ADCEN_CNTR_2TIME_MASK 	(ADCEN_CNTR_2TIME << MUIC_CTRL2_ADCEN_CNTR_SHIFT)
#define MUIC_CTRL2_ADCEN_CNTR_3TIME_MASK 	(ADCEN_CNTR_3TIME << MUIC_CTRL2_ADCEN_CNTR_SHIFT)
#define MUIC_CTRL2_ADCEN_CNTR_4TIME_MASK 	(ADCEN_CNTR_4TIME << MUIC_CTRL2_ADCEN_CNTR_SHIFT)
#define MUIC_CTRL2_ADCEN_CNTR_5TIME_MASK 	(ADCEN_CNTR_5TIME << MUIC_CTRL2_ADCEN_CNTR_SHIFT)
#define MUIC_CTRL2_ADCEN_CNTR_6TIME_MASK 	(ADCEN_CNTR_6TIME << MUIC_CTRL2_ADCEN_CNTR_SHIFT)
#define MUIC_CTRL2_ADCEN_CNTR_7TIME_MASK 	(ADCEN_CNTR_7TIME << MUIC_CTRL2_ADCEN_CNTR_SHIFT)

/* S2MU107 MUIC MUIC_CTRL3 Register (0x72) */
#define MUIC_CTRL3_ADC_DECISION_PERI_SHIFT 	6
#define MUIC_CTRL3_ADC_DECISION_ONE_SHIFT 	4
#define MUIC_CTRL3_Auto_rescan_SHIFT 		3
#define MUIC_CTRL3_ONE_SHOT_SHIFT		2
#define MUIC_CTRL3_LOWPWR_SHIFT 		0

#define MUIC_CTRL3_ADC_DECISION_PERI_MASK	(0x3 << MUIC_CTRL3_ADC_DECISION_PERI_SHIFT)
#define MUIC_CTRL3_ADC_DECISION_ONE_MASK 	(0x3 << MUIC_CTRL3_ADC_DECISION_ONE_SHIFT)
#define MUIC_CTRL3_Auto_rescan_MASK 		(0x1 << MUIC_CTRL3_Auto_rescan_SHIFT)
#define MUIC_CTRL3_ONE_SHOT_MASK 		(0x1 << MUIC_CTRL3_ONE_SHOT_SHIFT)
#define MUIC_CTRL3_LOWPWR_MASK 			(0x1 << MUIC_CTRL3_LOWPWR_SHIFT)

#define ADC_DECISION_1TIME 			(1)
#define ADC_DECISION_2TIME			(2)
#define ADC_DECISION_3TIME			(3)

#define MUIC_CTRL3_ADC_DECISION_PERI_1TIME_MASK	(ADC_DECISION_1TIME << MUIC_CTRL3_ADC_DECISION_PERI_SHIFT)
#define MUIC_CTRL3_ADC_DECISION_PERI_2TIME_MASK	(ADC_DECISION_2TIME << MUIC_CTRL3_ADC_DECISION_PERI_SHIFT)
#define MUIC_CTRL3_ADC_DECISION_PERI_3TIME_MASK	(ADC_DECISION_3TIME << MUIC_CTRL3_ADC_DECISION_PERI_SHIFT)

#define MUIC_CTRL3_ADC_DECISION_ONE_1TIME_MASK	(ADC_DECISION_1TIME << MUIC_CTRL3_ADC_DECISION_PERI_SHIFT)
#define MUIC_CTRL3_ADC_DECISION_ONE_2TIME_MASK	(ADC_DECISION_2TIME << MUIC_CTRL3_ADC_DECISION_PERI_SHIFT)
#define MUIC_CTRL3_ADC_DECISION_ONE_3TIME_MASK	(ADC_DECISION_3TIME << MUIC_CTRL3_ADC_DECISION_PERI_SHIFT)

/* S2MU107 MUIC CHARGER_DET_OTP Register (0x73) */
#define CHARGER_DET_OTP_MAN_VBUSTMR_ON_SHIFT	7
#define CHARGER_DET_OTP_VTH_APPLE_SHIFT 	4
#define CHARGER_DET_OTP_VTRIM_DATA_SHIFT 	0

#define CHARGER_DET_OTP_MAN_VBUSTMR_ON_MASK	(0x1 << CHARGER_DET_OTP_MAN_VBUSTMR_ON_SHIFT)
#define CHARGER_DET_OTP_VTH_APPLE_MASK 		(0x7 << CHARGER_DET_OTP_VTH_APPLE_2_SHIFT)
#define CHARGER_DET_OTP_VTRIM_DATA_MASK		(0xF << CHARGER_DET_OTP_VTRIM_DATA_1_SHIFT)

/* S2MU107 MUIC ADC_VREF_OTP Register (0x74) */
#define ADC_VREF_OTP_ADC_VREF_TRIM_SHIFT 	0

#define ADC_VREF_OTP_ADC_VREF_TRIM_MASK		(0xFF << ADC_VREF_OTP_ADC_VREF_TRIM_SHIFT)

/* S2MU107 MUIC ADCBIAS_OTP1 Register (0x75) */
#define ADCBIAS_OTP1_WAKEUP_LOW_VTH_SEL_SHIFT	7
#define ADCBIAS_OTP1_TRM_RID2U_2ND_SHIFT 	0

#define ADCBIAS_OTP1_WAKEUP_LOW_VTH_SEL_MASK 	(0x1 << ADCBIAS_OTP1_WAKEUP_LOW_VTH_SEL_SHIFT)
#define ADCBIAS_OTP1_TRM_RID2U_2ND_MASK 	(0x3F << ADCBIAS_OTP1_TRM_RID2U_2ND_0_SHIFT)

/* S2MU107 MUIC ADCBIAS_OTP2 Register (0x76) */
#define ADCBIAS_OTP2_RID_PUP_RES_SEL1_SHIFT 	7
#define ADCBIAS_OTP2_TRM_RID11U_2ND_SHIFT 	0

#define ADCBIAS_OTP2_RID_PUP_RES_SEL1_MASK 	(0x1 << ADCBIAS_OTP2_RID_PUP_RES_SEL1_SHIFT)
#define ADCBIAS_OTP2_TRM_RID11U_2ND_MASK 	(0x3F << ADCBIAS_OTP2_TRM_RID11U_2ND_0_SHIFT)

/* S2MU107 MUIC ADCBIAS_OTP3 Register (0x77) */
#define ADCBIAS_OTP3_RID_PUP_RES_SEL0_SHIFT	7
#define ADCBIAS_OTP3_TRM_RID64U_2ND_SHIFT 	0

#define ADCBIAS_OTP3_RID_PUP_RES_SEL0_MASK 	(0x1 << ADCBIAS_OTP3_RID_PUP_RES_SEL0_SHIFT)
#define ADCBIAS_OTP3_TRM_RID64U_2ND_MASK 	(0x3F << ADCBIAS_OTP3_TRM_RID64U_2ND_0_SHIFT)

/* S2MU107 MUIC ADCBIAS_OTP4 Register (0x78) */
#define ADCBIAS_OTP4_ADC_STDBY_BIAS_SEL_SHIFT	7
#define ADCBIAS_OTP4_TRM_RID260U_2ND_SHIFT	0

#define ADCBIAS_OTP4_ADC_STDBY_BIAS_SEL_MASK	(0x1 << ADCBIAS_OTP4_ADC_STDBY_BIAS_SEL_SHIFT)
#define ADCBIAS_OTP4_TRM_RID260U_2ND_MASK 	(0x3F << ADCBIAS_OTP4_TRM_RID260U_2ND_0_SHIFT)

/* S2MU107 MUIC LDOADC_VSETL Register (0x79) */
#define LDOADC_VSETL_UART_SEL_SHIFT 			7
#define LDOADC_VSETL_MUIC_CLK_O_SHIFT 			6
#define LDOADC_VSETL_CHG_TYPE_DET_ALWAYS_ONB_SHIFT	5
#define LDOADC_VSETL_LDOADC_VSETL_SHIFT 		0

#define LDOADC_VSETL_UART_SEL_MASK			(0x1 << LDOADC_VSETL_UART_SEL_SHIFT)
#define LDOADC_VSETL_MUIC_CLK_O_MASK 			(0x1 << LDOADC_VSETL_MUIC_CLK_O_SHIFT)
#define LDOADC_VSETL_CHG_TYPE_DET_ALWAYS_ONB_MASK	(0x1 << LDOADC_VSETL_CHG_TYPE_DET_ALWAYS_ONB_SHIFT)
#define LDOADC_VSETL_LDOADC_VSETL_MASK 			(0xF << LDOADC_VSETL_LDOADC_VSETL_SHIFT)

/* S2MU107 MUIC LDOADC_VSETH Register (0x7A) */
#define LDOADC_VSETH_WAKEUP_DLY_SHIFT 			7
#define LDOADC_VSETH_WAKE_HYS_SHIFT 			6
#define LDOADC_VSETH_MANUAL_JIGB_RID_SHIFT		5
#define LDOADC_VSETH_LDOADC_VSETH_SHIFT 		0

#define LDOADC_VSETH_WAKEUP_DLY_MASK 			(0x1 << LDOADC_VSETH_WAKEUP_DLY_SHIFT)
#define LDOADC_VSETH_WAKE_HYS_MASK 			(0x1 << LDOADC_VSETH_WAKE_HYS_SHIFT)
#define LDOADC_VSETH_MANUAL_JIGB_RID_MASK		(0x1 << LDOADC_VSETH_MANUAL_JIGB_RID_SHIFT)
#define LDOADC_VSETH_LDOADC_VSETH_MASK 			(0x1F << LDOADC_VSETH_LDOADC_VSETH_SHIFT)

#define LDOADC_VSETH_MASK	0x1F
#define LDOADC_VSETL_MASK	0x1F
#define LDOADC_VSET_3V		0x1F
#define LDOADC_VSET_2_7V	0x1C
#define LDOADC_VSET_2_6V	0x0E
#define LDOADC_VSET_2_4V	0x0C
#define LDOADC_VSET_2_2V	0x0A
#define LDOADC_VSET_2_0V	0x08
#define LDOADC_VSET_1_8V	0x06
#define LDOADC_VSET_1_7V	0x05
#define LDOADC_VSET_1_6V	0x04
#define LDOADC_VSET_1_5V	0x03
#define LDOADC_VSET_1_4V	0x02
#define LDOADC_VSET_1_2V	0x00
#define LDOADC_VSETH_WAKE_HYS_SHIFT	6
#define LDOADC_VSETH_WAKE_HYS_MASK	(0x1 << LDOADC_VSETH_WAKE_HYS_SHIFT)

/* S2MU107 MUIC LDOPCP_VSET_OTP Register (0x7B) */
#define LDOPCP_VSET_OTP_LDOPCP_USB_SET_SHIFT 		4
#define LDOPCP_VSET_OTP_JIGB_DLY_AB_SEL_SHIFT 		3
#define LDOPCP_VSET_OTP_VBUS_DET_TMR_MASK_CTRL_SHIFT	2
#define LDOPCP_VSET_OTP_DETACH_TIME_SET_SHIFT 		0

#define LDOPCP_VSET_OTP_LDOPCP_USB_SET_MASK 		(0xF << LDOPCP_VSET_OTP_LDOPCP_USB_SET_SHIFT)
#define LDOPCP_VSET_OTP_JIGB_DLY_AB_SEL_MASK 		(0x3 << LDOPCP_VSET_OTP_JIGB_DLY_AB_SEL_SHIFT)
#define LDOPCP_VSET_OTP_VBUS_DET_TMR_MASK_CTRL_MASK	(0x1 << LDOPCP_VSET_OTP_VBUS_DET_TMR_MASK_CTRL_SHIFT)
#define LDOPCP_VSET_OTP_DETACH_TIME_SET_MASK 		(0x3 << LDOPCP_VSET_OTP_DETACH_TIME_SET_SHIFT)

/* S2MU107 MUIC MONITOR_SEL Register (0x7C) */
#define MONITOR_SEL_MONITOR_SEL_SHIFT			7

#define MONITOR_SEL_MONITOR_SEL_MASK			(0x1 << MONITOR_SEL_MONITOR_SEL_SHIFT)

/* S2MU107 MUIC RID_WATER_PROOF Register (0x7D) */
#define RID_WATER_PROOF_ADC_STD_BIAS_CTRL_SHIFT 	4
#define RID_WATER_PROOF_DETACH_VALID_TSET_SHIFT 	1
#define RID_WATER_PROOF_WATER_WARN_SEL_SHIFT 		0

#define RID_WATER_PROOF_ADC_STD_BIAS_CTRL_MASK		(0xF << RID_WATER_PROOF_ADC_STD_BIAS_CTRL_SHIFT)
#define RID_WATER_PROOF_DETACH_VALID_TSET_MASK 		(0x3 << RID_WATER_PROOF_DETACH_VALID_TSET_SHIFT)
#define RID_WATER_PROOF_WATER_WARN_SEL_MASK 		(0x1 << RID_WATER_PROOF_WATER_WARN_SEL_SHIFT)

/* S2MU107 MUIC RID_DISCHARGE Register (0x7E) */
#define RID_DISCHARGE_DCD_DAATTACH_OPTION_BACKUP_SHIFT	7
#define RID_DISCHARGE_CHG_DET_OFF_SHIFT			6
#define RID_DISCHARGE_USBKILL_OTG_OPTION_SHIFT 		5
#define RID_DISCHARGE_RID_DISCHG_MAN_OFF_WC_SHIFT 	4
#define RID_DISCHARGE_RID_DISCHG_MAN_ON_SHIFT 		3
#define RID_DISCHARGE_RID_DISCHARGE_ON_SHIFT 		2
#define RID_DISCHARGE_RID_DISCHG_TIME_SHIFT 		0

#define RID_DISCHARGE_DCD_DAATTACH_OPTION_BACKUP_MASK	(0x1 << RID_DISCHARGE_DCD_DAATTACH_OPTION_BACKUP_SHIFT)
#define RID_DISCHARGE_CHG_DET_OFF_MASK 			(0x1 << RID_DISCHARGE_CHG_DET_OFF_SHIFT)
#define RID_DISCHARGE_USBKILL_OTG_OPTION_MASK 		(0x1 << RID_DISCHARGE_USBKILL_OTG_OPTION_SHIFT)
#define RID_DISCHARGE_RID_DISCHG_MAN_OFF_WC_MASK 	(0x1 << RID_DISCHARGE_RID_DISCHG_MAN_OFF_WC_SHIFT)
#define RID_DISCHARGE_RID_DISCHG_MAN_ON_MASK 		(0x1 << RID_DISCHARGE_RID_DISCHG_MAN_ON_SHIFT)
#define RID_DISCHARGE_RID_DISCHARGE_ON_MASK 		(0x1 << RID_DISCHARGE_RID_DISCHARGE_ON_SHIFT)
#define RID_DISCHARGE_RID_DISCHG_TIME_MASK 		(0x3 << RID_DISCHARGE_RID_DISCHG_TIME_SHIFT)

/* S2MU107 MUIC MUIC_RSVD1 Register (0x7F) */
#define MUIC_RSVD1_HICCUP_UARX_CP_SHIFT			(2)
#define MUIC_RSVD1_HICCUP_UATX_CP_SHIFT			(1)
#define MUIC_RSVD1_FAC_WAIT_SHIFT			(0)

#define MUIC_RSVD1_HICCUP_UARX_CP_MASK			(0x1 << MUIC_RSVD1_HICCUP_UARX_CP_SHIFT)
#define MUIC_RSVD1_HICCUP_UATX_CP_MASK			(0x1 << MUIC_RSVD1_HICCUP_UATX_CP_SHIFT)
#define MUIC_RSVD1_FAC_WAIT_MASK			(0x1 << MUIC_RSVD1_FAC_WAIT_SHIFT)

#define IS_JIG_ADC(adc) \
	(((adc == ADC_JIG_USB_OFF) \
	|| (adc == ADC_JIG_USB_ON) \
	|| (adc == ADC_JIG_UART_OFF) \
	|| (adc == ADC_JIG_UART_ON)) ? 1 : 0)

/* s2mu107-muic macros */
#define ENUM_STR(x, r) { case x: r = #x; break; }

#define REQUEST_IRQ(_irq, _dev_id, _name, _func)				\
do {									\
	ret = request_threaded_irq(_irq, NULL, _func,	\
				0, _name, _dev_id);	\
	if (ret < 0) {							\
		pr_err("%s:%s Failed to request IRQ #%d: %d\n",		\
				MUIC_DEV_NAME, __func__, _irq, ret);	\
		_irq = 0;						\
	}								\
} while (0)

#define FREE_IRQ(_irq, _dev_id, _name)					\
do {									\
	if (_irq) {							\
		free_irq(_irq, _dev_id);				\
		pr_info("%s:%s IRQ(%d):%s free done\n", MUIC_DEV_NAME,	\
				__func__, _irq, _name);			\
	}								\
} while (0)
/* end of macros */

enum s2mu107_muic_enable {
	S2MU107_DISABLE,
	S2MU107_ENABLE,
};

enum s2mu107_muic_adc_mode {
	S2MU107_ADC_ONESHOT,
	S2MU107_ADC_PERIODIC,
};

enum s2mu107_muic_detect_dev_read_val {
	DEVICE_TYPE1 = 0,
	DEVICE_TYPE2,
	DEVICE_TYPE3,
	ADC,
	DEVICE_APPLE,
	CHG_TYPE,
	SC_STATUS2,
	MAX_NUM,
};

typedef enum {
	S2MU107_MODE_NONE = -1,
	S2MU107_MODE_AUTO,
	S2MU107_MODE_MANUAL,
	S2MU107_MODE_MAX,
} t_mode_data ;

typedef enum {
	S2MU107_PATH_NONE = -1,
	S2MU107_PATH_OPEN,
	S2MU107_PATH_USB,
	S2MU107_PATH_UART_AP,
	S2MU107_PATH_UART_CP,
	S2MU107_PATH_RSVD,
	S2MU107_PATH_MAX,
} t_path_data;

typedef enum {
	S2MU107_DETECT_NONE,
	S2MU107_DETECT_DONE,
	S2MU107_DETECT_SKIP,
} t_detect_status;

typedef enum {
	S2MU107_IRQ_CHECK_DONE,
	S2MU107_IRQ_SKIP,
} t_irq_status;

/* muic chip specific internal data structure
 * that setted at muic-xxxx.c file
 */
struct s2mu107_muic_data {
	struct device *dev;
	struct i2c_client *i2c;	/* i2c addr: 0x7C; MUIC */
	struct i2c_client *i2c_common;	/* i2c addr: 0x74; common */
	struct s2mu107_dev *s2mu107_dev;

	struct mutex muic_mutex;
	struct mutex switch_mutex;
	struct mutex bcd_rescan_mutex;
#if defined(CONFIG_HV_MUIC_S2MU107_AFC)
	struct mutex afc_mutex;
#endif

	/* struct wakeup_source wakeup_src; */
	struct wake_lock wake_lock;

	/* model dependant mfd platform data */
	struct s2mu107_platform_data *mfd_pdata;

	/* model dependant muic platform data */
	struct muic_platform_data *pdata;

	void *if_data;

	int irq_attach;
	int irq_detach;
	int irq_rid_chg;
	int irq_usb_killer;
	int irq_vbus_on;
	int irq_rsvd_attach;
	int irq_adc_change;
	int irq_av_charge;
	int irq_vbus_off;
#if defined(CONFIG_HV_MUIC_S2MU107_AFC)
	int irq_vdnmon;
	int irq_mpnack;
	int irq_mrxtrf;
	int irq_mrxrdy;
	struct power_supply *psy_pm;
#endif
	bool afc_check;
#if defined(CONFIG_HV_MUIC_S2MU107_AFC)
	bool is_dp_drive;
	bool is_hvcharger_detected;
#endif
#if IS_ENABLED(CONFIG_HICCUP_CHARGER)
	bool is_hiccup_mode;
#endif
	muic_attached_dev_t new_dev;

	int adc;
	int vbvolt;
	int vmid;
	int reg[MAX_NUM];
#if defined(CONFIG_HV_MUIC_S2MU107_AFC)
	int mrxrdy_cnt;
	int mping_cnt;
	int qc_retry_cnt;
	int tx_data;
	int qc_retry_wait_cnt;

	muic_hv_state_t hv_state;
#endif

	/*
	 * Distinguisher is needed,
	 * if it doesn't have the muic manager.
	 */

	/* W/A waiting for the charger ic */
	struct delayed_work dcd_recheck;
#if defined(CONFIG_HV_MUIC_S2MU107_AFC)
	struct delayed_work reset_work;
	struct delayed_work mping_retry_work;
	struct delayed_work qc_retry_work;
#endif
};

extern struct muic_platform_data muic_pdata;

int s2mu107_i2c_read_byte(struct i2c_client *client, u8 command);
int s2mu107_i2c_write_byte(struct i2c_client *client, u8 command, u8 value);
int s2mu107_muic_recheck_adc(struct s2mu107_muic_data *muic_data);
void s2mu107_muic_control_vbus_det(struct s2mu107_muic_data *muic_data,
		bool enable);
extern void s2mu107_muic_dcd_rescan(struct s2mu107_muic_data *muic_data);
extern int s2mu107_muic_control_rid_adc(struct s2mu107_muic_data *muic_data,
		bool enable);
extern int s2mu107_muic_bcd_rescan(struct s2mu107_muic_data *muic_data);
int s2mu107_muic_jig_on(struct s2mu107_muic_data *muic_data);
void s2mu107_muic_control_vbus_det(struct s2mu107_muic_data *muic_data,
		bool enable);
int s2mu107_set_gpio_uart_sel(struct s2mu107_muic_data *muic_data,
		int uart_sel);
int s2mu107_init_interface(struct s2mu107_muic_data *muic_data,
		struct muic_interface_t *muic_if);
extern int _s2mu107_muic_get_vbus_state(struct s2mu107_muic_data *muic_data);
#if IS_ENABLED(CONFIG_CCIC_S2MU107)
int s2mu107_muic_refresh_adc(struct s2mu107_muic_data *muic_data);
#endif
#if defined(CONFIG_HV_MUIC_S2MU107_AFC)
int s2mu107_hv_muic_get_vdnmon_status(struct s2mu107_muic_data* muic_data);
#endif
#endif /* __S2MU107_MUIC_H__ */
