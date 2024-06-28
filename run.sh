#!/bin/sh

ARGS=$1

./push_swap $ARGS | ./checker_linux $ARGS
