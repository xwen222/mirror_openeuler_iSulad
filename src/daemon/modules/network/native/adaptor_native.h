/******************************************************************************
 * Copyright (c) Huawei Technologies Co., Ltd. 2017-2019. All rights reserved.
 * iSulad licensed under the Mulan PSL v2.
 * You can use this software according to the terms and conditions of the Mulan PSL v2.
 * You may obtain a copy of Mulan PSL v2 at:
 *     http://license.coscl.org.cn/MulanPSL2
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY OR FIT FOR A PARTICULAR
 * PURPOSE.
 * See the Mulan PSL v2 for more details.
 * Author: zhangxiaoyu
 * Create: 2020-10-31
 * Description: provide network callback function definition
 *******************************************************************************/

#ifndef DAEMON_MODULES_ADAPTOR_NATIVE_H
#define DAEMON_MODULES_ADAPTOR_NATIVE_H

#include "network_api.h"

int native_init();

bool native_check();

void native_destory();

int native_config_create(const network_create_request *request, network_create_response **response);

int native_config_inspect(const char *name, char **network_json);

int native_config_list(const struct filters_args *filters, network_network_info ***networks, size_t *networks_len);

int native_config_remove(const char *name, char **res_name);

#endif // DAEMON_MODULES_API_NETWORK_CONFIG_H