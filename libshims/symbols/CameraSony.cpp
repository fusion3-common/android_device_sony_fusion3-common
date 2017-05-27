/*
 * Copyright (C) 2018 The LineageOS Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <cutils/log.h>
#include <sys/types.h>
#include <dlfcn.h>
#include <string.h>

extern "C"
{
    /* property_get */
    int property_get(const char* key, char* value, const char* default_value)
    {
        if (strcmp("ro.build.type", key) == 0) {
            strcpy(value, "eng");
            return 3;
        }

        return ((int(*)(const char*, char*, const char*))(dlsym((void*) - 1,
                "property_get")))(key, value, default_value);
    }
}
