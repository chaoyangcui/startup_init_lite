/*
* Copyright (c) 2021 Huawei Device Co., Ltd.
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

#include <string.h>
#include <stdio.h>

#include "sys_param.h"

#define HELP_PARAM "--help"

int main(int argc, char* argv[])
{
    if (argc == 1 || argc > 3) {
        printf("setparam: Need 2 arguments (see \"setparam --help\")\n");
        return 0;
    }
    if (argc == 2 && strncmp(argv[1], HELP_PARAM, strlen(HELP_PARAM)) == 0) {
        printf("usage: setparam NAME VALUE\n");
        return 0;
    }
    int ret = SystemSetParameter(argv[1], argv[2]);
    if (ret == 0) {
        printf("setparam %s %s success\n", argv[1], argv[2]);
    } else {
        printf("setparam %s %s fail\n", argv[1], argv[2]);
    }
}
