#!/bin/bash

lcov -q --directory ./ --zerocounters

./$1 --gtest_color=yes

echo -e '\n--- [ Generating coverage data ] ---\n'
lcov --no-external --base-directory ../src --directory ./obj --capture -o ./obj/lcov_test.info

echo -e '\n--- [ Generating HTML coverage report ] ---\n'
genhtml --legend --dark-mode --ignore-errors source ./obj/lcov_test.info -o ./html