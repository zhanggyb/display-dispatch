//
// Created by zhanggyb on 17-5-4.
//

#include "shm.hpp"

#include <assert.h>

const struct wl_shm_listener Shm::kListener = {
    OnFormat
};

void Shm::OnFormat(void *data, struct wl_shm *shm, uint32_t format) {

}