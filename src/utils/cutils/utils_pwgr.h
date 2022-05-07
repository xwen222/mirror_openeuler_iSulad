/******************************************************************************
 * Copyright (c) Huawei Technologies Co., Ltd. 2022. All rights reserved.
 * iSulad licensed under the Mulan PSL v2.
 * You can use this software according to the terms and conditions of the Mulan PSL v2.
 * You may obtain a copy of Mulan PSL v2 at:
 *     http://license.coscl.org.cn/MulanPSL2
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY OR FIT FOR A PARTICULAR
 * PURPOSE.
 * See the Mulan PSL v2 for more details.
 * Author: hejunjie
 * Create: 2022-04-08
 * Description: Provide line parser for android
 *******************************************************************************/
#ifndef UTILS_CUTILS_UTILS_PWGR_H
#define UTILS_CUTILS_UTILS_PWGR_H

#include <stdio.h>
#include <pwd.h>
#include <grp.h>

#ifdef __cplusplus
extern "C" {
#endif

int util_getpwent_r(FILE *stream, struct passwd *resbuf, char *buffer, size_t buflen, struct passwd **result);

int util_getgrent_r(FILE *stream, struct group *resbuf, char *buffer, size_t buflen, struct group **result);

#ifdef __cplusplus
}
#endif
#endif // UTILS_CUTILS_UTILS_PWGR_H
