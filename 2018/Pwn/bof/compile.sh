#!/bin/bash

gcc bof.c -o bof -m32 -no-pie -fno-pic -mpreferred-stack-boundary=2 -fno-stack-protector
