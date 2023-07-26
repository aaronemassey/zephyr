/*
 * Copyright 2023 Google LLC
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/device.h>
#include <zephyr/drivers/fuel_gauge.h>
#include <zephyr/drivers/i2c.h>
#include <zephyr/logging/log.h>
#include <zephyr/sys/byteorder.h>
#include <zephyr/sys/util.h>
#include <zephyr/ztest.h>
#include <zephyr/ztest_assert.h>

#include "test_sbs_gauge.h"
#include <stdbool.h>
#include <stdio.h>

ZTEST_USER_F(sbs_gauge_new_api, test_cutoff)
{
	struct fuel_gauge_get_property get_props[] = {
		{
			.property_type = FUEL_GAUGE_BATTERY_CUT_OFF,
		},
	};

	zassert_ok(fuel_gauge_get_prop(fixture->dev, get_props, ARRAY_SIZE(get_props)));

	zassert_ok(get_props[0].status);
	/* Should initially be 0 */
	zassert_equal(get_props[0].value.battery_cutoff, false);

	struct fuel_gauge_set_property set_props[] = {
		{
			.property_type = FUEL_GAUGE_BATTERY_CUT_OFF,
			.value.battery_cutoff = true,
		},
	};

	zassert_ok(fuel_gauge_set_prop(fixture->dev, set_props, ARRAY_SIZE(set_props)));
	zassert_ok(set_props[0].status);

	/* Should now be true */
	zassert_ok(fuel_gauge_get_prop(fixture->dev, get_props, ARRAY_SIZE(get_props)));
	zassert_equal(get_props[0].value.battery_cutoff, true);
}
