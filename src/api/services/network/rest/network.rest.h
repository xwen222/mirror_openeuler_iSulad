/******************************************************************************
 * Copyright (c) Huawei Technologies Co., Ltd. 2020. All rights reserved.
 * iSulad licensed under the Mulan PSL v2.
 * You can use this software according to the terms and conditions of the Mulan PSL v2.
 * You may obtain a copy of Mulan PSL v2 at:
 *     http://license.coscl.org.cn/MulanPSL2
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY OR FIT FOR A PARTICULAR
 * PURPOSE.
 * See the Mulan PSL v2 for more details.
 * Author: zhangxiaoyu
 * Create: 2020-09-10
 * Description: provide network rest definition
 **********************************************************************************/
#ifndef API_SERVICES_NETWORK_REST_H
#define API_SERVICES_NETWORK_REST_H

#include "isula_libutils/network_create_request.h"
#include "isula_libutils/network_create_response.h"
#include "isula_libutils/network_inspect_request.h"
#include "isula_libutils/network_inspect_response.h"
#include "isula_libutils/network_list_request.h"
#include "isula_libutils/network_list_response.h"
#include "isula_libutils/network_remove_request.h"
#include "isula_libutils/network_remove_response.h"

#ifndef RestHttpHead
#define RestHttpHead "http://localhost"
#endif

#define NetworkServiceCreate "/NetworkService/Create"
#define NetworkServiceInspect "/NetworkService/Inspect"
#define NetworkServiceList "/NetworkService/List"
#define NetworkServiceRemove "/NetworkService/Remove"

#endif // API_SERVICES_NETWORK_REST_H

