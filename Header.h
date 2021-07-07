#pragma once

void setLength(MEMORYSTATUSEX* memoryStatusEx)
{
    memoryStatusEx->dwLength = sizeof(*memoryStatusEx);
}
