#!/bin/bash

gcc rop.c -o rop  -no-pie -fno-pic -mpreferred-stack-boundary=3 -fno-stack-protector
