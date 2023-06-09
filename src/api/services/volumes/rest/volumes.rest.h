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
 * Author: zhongtao
 * Create: 2022-08-23
 * Description: provide volumes rest definition
 **********************************************************************************/
#ifndef API_SERVICES_VOLUMES_REST_H
#define API_SERVICES_VOLUMES_REST_H

#include <isula_libutils/volume_list_volume_request.h>
#include <isula_libutils/volume_list_volume_response.h>
#include <isula_libutils/volume_remove_volume_request.h>
#include <isula_libutils/volume_remove_volume_response.h>
#include <isula_libutils/volume_prune_volume_request.h>
#include <isula_libutils/volume_prune_volume_response.h>

#ifndef RestHttpHead
#define RestHttpHead "http://localhost"
#endif

#define VolumesServiceList "/VolumesService/List"
#define VolumesServiceRemove "/VolumesService/Remove"
#define VolumesServicePrune "/VolumesService/Prune"

#endif // API_SERVICES_VOLUMES_REST_H

