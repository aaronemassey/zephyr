/*
 * Copyright 2023 Google LLC
 * Copyright 2023 Microsoft Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef ZEPHYR_INCLUDE_DRIVERS_SBS_H_
#define ZEPHYR_INCLUDE_DRIVERS_SBS_H_

/**
 * @brief SBS Fuel Gauge Interface
 * @defgroup sbs_gauge_interface Fuel Gauge Interface
 * @ingroup io_interfaces
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include <zephyr/drivers/fuel_gauge.h>


enum sbs_prop_type {
	/** SBS Spec properties. See the Smart Battery Data Specification Rev 1.10 for meanings */
	/* http://sbs-forum.org/specs/sbdat110.pdf */
	FUEL_GAUGE_SBS_MFR_ACCESS = FUEL_GAUGE_COMMON_COUNT,
	FUEL_GAUGE_SBS_MODE,
	FUEL_GAUGE_SBS_ATRATE,
	FUEL_GAUGE_SBS_ATRATE_TIME_TO_FULL,
	FUEL_GAUGE_SBS_ATRATE_TIME_TO_EMPTY,
	FUEL_GAUGE_SBS_ATRATE_OK,
	FUEL_GAUGE_SBS_REMAINING_CAPACITY_ALARM,
	FUEL_GAUGE_SBS_REMAINING_TIME_ALARM,
};


/**
 * Data structures for reading SBS buffer properties
 */
#define SBS_GAUGE_MANUFACTURER_NAME_MAX_SIZE 20
#define SBS_GAUGE_DEVICE_NAME_MAX_SIZE       20
#define SBS_GAUGE_DEVICE_CHEMISTRY_MAX_SIZE  4

struct sbs_gauge_manufacturer_name {
	uint8_t manufacturer_name_length;
	char manufacturer_name[SBS_GAUGE_MANUFACTURER_NAME_MAX_SIZE];
} __packed;

struct sbs_gauge_device_name {
	uint8_t device_name_length;
	char device_name[SBS_GAUGE_DEVICE_NAME_MAX_SIZE];
} __packed;

struct sbs_gauge_device_chemistry {
	uint8_t device_chemistry_length;
	char device_chemistry[SBS_GAUGE_DEVICE_CHEMISTRY_MAX_SIZE];
} __packed;

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZEPHYR_INCLUDE_DRIVERS_SBS_H_ */
