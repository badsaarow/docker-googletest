// mock_device.h
#ifndef MOCK_DEVICE_H
#define MOCK_DEVICE_H

// 고객은 C로 컴파일해도, gTest는 C++로 컴파일하므로 이렇게 해줘야 한다.
#ifdef __cplusplus
extern "C" {
#endif

int connect();
int send(char *str);

#ifdef __cplusplus
}
#endif
#endif