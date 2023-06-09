#!/bin/bash
#
# attributes: isulad basic network inspect
# concurrent: NA
# spend time: 15

#######################################################################
##- Copyright (c) Huawei Technologies Co., Ltd. 2021. All rights reserved.
# - iSulad licensed under the Mulan PSL v2.
# - You can use this software according to the terms and conditions of the Mulan PSL v2.
# - You may obtain a copy of Mulan PSL v2 at:
# -     http://license.coscl.org.cn/MulanPSL2
# - THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR
# - IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY OR FIT FOR A PARTICULAR
# - PURPOSE.
# - See the Mulan PSL v2 for more details.
##- @Description:CI
##- @Author: zhangxiaoyu
##- @Create: 2020-09-30
#######################################################################

curr_path=$(dirname $(readlink -f "$0"))
source ../helpers.sh

if [ ${enable_native_network} -ne 0 ]; then
    msg_info "${test} disable native network, just ignore test."
    exit 0
fi

function test_network_inspect()
{
    local ret=0
    local name1="cni1"
    local name2="cni2"
    local test="network inspect test => (${FUNCNAME[@]})"

    msg_info "${test} starting..."

    check_valgrind_log
    [[ $? -ne 0 ]] && msg_err "${FUNCNAME[0]}:${LINENO} - stop isulad failed" && ((ret++))

    start_isulad_with_valgrind
    [[ $? -ne 0 ]] && msg_err "${FUNCNAME[0]}:${LINENO} - start isulad failed" && ((ret++))

    isula network create --subnet 192.172.59.0/24 --gateway 192.172.59.3 ${name1}
    [[ $? -ne 0 ]] && msg_err "${FUNCNAME[0]}:${LINENO} - create network ${name1} failed" && return ${FAILURE}
    file1="/etc/cni/net.d/isulacni-${name1}.conflist"
    [ ! -f ${file1} ] && msg_err "${FUNCNAME[0]}:${LINENO} - file ${file1} not exist" && return ${FAILURE}

    isula network create --driver bridge --internal ${name2}
    [[ $? -ne 0 ]] && msg_err "${FUNCNAME[0]}:${LINENO} - create network ${name2} failed" && return ${FAILURE}
    file2="/etc/cni/net.d/isulacni-${name2}.conflist"
    [ ! -f ${file2} ] && msg_err "${FUNCNAME[0]}:${LINENO} - file ${file2} not exist" && return ${FAILURE}

    isula network inspect .xx 2>&1 | grep "Invalid network name"
    [[ $? -ne 0 ]] && msg_err "${FUNCNAME[0]}:${LINENO} - failed to inspect invalid name" && return ${FAILURE}

    isula network inspect cni3 2>&1 | grep "No such network"
    [[ $? -ne 0 ]] && msg_err "${FUNCNAME[0]}:${LINENO} - failed to inspect not exist network" && return ${FAILURE}

    isula network inspect 2>&1 | grep "requires at least 1 network name"
    [[ $? -ne 0 ]] && msg_err "${FUNCNAME[0]}:${LINENO} - failed to inspect no name network" && return ${FAILURE}

    isula network inspect ${name1} ${name2}
    [[ $? -ne 0 ]] && msg_err "${FUNCNAME[0]}:${LINENO} - failed to inspect multi-network" && return ${FAILURE}

    isula network inspect -f='{{.plugins.ipam.ranges}}' ${name1} | grep "192.172.59.0/24"
    [[ $? -ne 0 ]] && msg_err "${FUNCNAME[0]}:${LINENO} - failed to inspect ${name1}" && return ${FAILURE}

    isula network inspect -f='{{...}}' ${name1}
    [[ $? -eq 0 ]] && msg_err "${FUNCNAME[0]}:${LINENO} - inspect ${name1} success" && return ${FAILURE}

    isula network rm ${name1}
    [[ $? -ne 0 ]] && msg_err "${FUNCNAME[0]}:${LINENO} - network rm ${name1} failed" && return ${FAILURE}

    isula network rm ${name2}
    [[ $? -ne 0 ]] && msg_err "${FUNCNAME[0]}:${LINENO} - network rm ${name2} failed" && return ${FAILURE}

    check_valgrind_log
    [[ $? -ne 0 ]] && msg_err "${FUNCNAME[0]}:${LINENO} - stop isulad failed" && ((ret++))

    start_isulad_with_valgrind
    [[ $? -ne 0 ]] && msg_err "${FUNCNAME[0]}:${LINENO} - start isulad failed" && ((ret++))

    msg_info "${test} finished with return ${ret}..."
    return ${ret}
}

declare -i ans=0

test_network_inspect || ((ans++))

show_result ${ans} "${curr_path}/${0}"
