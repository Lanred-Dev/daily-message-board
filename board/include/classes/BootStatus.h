#pragma once

struct BootStatus {
    const char* message;
    bool success;

    BootStatus(const char* msg, bool isSuccess) : message(msg), success(isSuccess) {}
};