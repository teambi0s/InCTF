#!/bin/bash

gcc your_name.c -m32 -o your_name -no-pie -fno-pic -mpreferred-stack-boundary=2
