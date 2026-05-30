// SPDX-License-Identifier: GPL-2.0
/*
 * Samsung Exynos SoC series Pablo driver
 *
 * Exynos Pablo image subsystem functions
 *
 * Copyright (c) 2021 Samsung Electronics Co., Ltd
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#include "pablo-kunit-test.h"

#include "pablo-obte.h"

static void pablo_pablo_obte_init_3aa_kunit_test(struct kunit *test)
{
	int ret;
	u32 instance = 0;
	bool reprocessing = false;

	ret = pablo_obte_init_3aa(instance, reprocessing);
	KUNIT_EXPECT_EQ(test, ret, 0);

	pablo_obte_deinit_3aa(instance);

}

static struct kunit_case pablo_pablo_obte_kunit_test_cases[] = {
	KUNIT_CASE(pablo_pablo_obte_init_3aa_kunit_test),
	{},
};

struct kunit_suite pablo_pablo_obte_kunit_test_suite = {
	.name = "pablo-pablo-obte-kunit-test",
	.test_cases = pablo_pablo_obte_kunit_test_cases,
};
define_pablo_kunit_test_suites(&pablo_pablo_obte_kunit_test_suite);

MODULE_LICENSE("GPL");
