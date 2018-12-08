#!/bin/bash

gcc cheating.c -o  cheating -m32 -mpreferred-stack-boundary=2 -fno-stack-protector -fno-pic -no-pie
