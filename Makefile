# Course checks. Run from the course root.
#   make test DAY=03 SRC=DAY_03/my_solutions.cpp   learners: test your own code
#   make check                                     maintainers: verify starters, templates and reference solutions
#   make ros                           build the Day 6 ROS 2 packages (source ROS 2 first)
CXX      ?= g++
WARN     := -std=c++17 -Wall -Wextra -Wpedantic
ASAN     := -g -O1 -fsanitize=address,undefined -fno-omit-frame-pointer
TSAN     := -g -O1 -fsanitize=thread
# GCC 11's TSan fails on kernels with high mmap randomisation; disabling ASLR for the run avoids it.
TSAN_RUN := setarch $(shell uname -m) -R
BUILD    := build

STARTERS := DAY_01/starter/telemetry_analyser.cpp \
            DAY_02/starter/sensor_demo.cpp \
            DAY_03/starter/fleet_manager.cpp \
            DAY_04/starter/sensor_event_processor.cpp \
            DAY_05/starter/sensor_queue.cpp \
            DAY_06/starter/portable_status_logic.cpp \
            DAY_07/starter/buggy_telemetry.cpp \
            DAY_07/starter/racy_stats.cpp \
            DAY_08/starter/mock_coding.cpp
TEST_DAYS := 01 02 03 04 05 06 07 08

.PHONY: check starters templates tests day05-tsan day07-programs test ros clean

check: starters templates tests day05-tsan day07-programs
	@echo "All checks passed."

# Starters must compile without warnings, except the unused parameters of TODO stubs.
starters:
	@for f in $(STARTERS); do \
	  $(CXX) $(WARN) -Werror -Wno-unused-parameter -pthread -fsyntax-only $$f || exit 1; \
	done
	@echo "Starters compile cleanly."

# Each DAY_XX/my_solutions.cpp must declare everything that day's tests call.
templates:
	@for d in $(TEST_DAYS); do \
	  $(CXX) $(WARN) -Werror -Wno-unused-parameter -pthread -fsyntax-only \
	    -DSOLUTION_FILE='"$(CURDIR)/DAY_'$$d'/my_solutions.cpp"' DAY_$$d/tests/tests.cpp || exit 1; \
	done
	@echo "Learner templates compile against the tests."

tests: | $(BUILD)
	@for d in $(TEST_DAYS); do \
	  $(CXX) $(WARN) -Werror $(ASAN) -pthread DAY_$$d/tests/tests.cpp -o $(BUILD)/day$${d}_tests && \
	  $(BUILD)/day$${d}_tests || exit 1; \
	done

day05-tsan: | $(BUILD)
	@$(CXX) $(WARN) -Werror $(TSAN) -pthread DAY_05/tests/tests.cpp -o $(BUILD)/day05_tests_tsan
	@$(TSAN_RUN) $(BUILD)/day05_tests_tsan

# The repaired Day 7 programs check themselves. The telemetry one reads its limits file from DAY_07/starter.
day07-programs: | $(BUILD)
	@$(CXX) $(WARN) -Werror $(ASAN) DAY_07/instructor_solutions/buggy_telemetry_fixed.cpp -o $(BUILD)/day07_telemetry_fixed
	@cd DAY_07/starter && ../../$(BUILD)/day07_telemetry_fixed > /dev/null && echo "Day 7 telemetry (fixed): passed"
	@$(CXX) $(WARN) -Werror $(TSAN) -pthread DAY_07/instructor_solutions/racy_stats_fixed.cpp -o $(BUILD)/day07_stats_fixed
	@$(TSAN_RUN) $(BUILD)/day07_stats_fixed > /dev/null && echo "Day 7 sample stats (fixed): passed"

# Runs one day's tests against SRC (normally DAY_XX/my_solutions.cpp); without SRC, against the instructor solutions.
test: | $(BUILD)
	@test -n "$(DAY)" || { echo "Usage: make test DAY=03 [SRC=path/to/your_file.cpp]"; exit 2; }
	$(CXX) $(WARN) -Wno-unused-parameter $(ASAN) -pthread $(if $(SRC),-DSOLUTION_FILE='"$(abspath $(SRC))"') \
	  DAY_$(DAY)/tests/tests.cpp -o $(BUILD)/day$(DAY)_mine
	$(BUILD)/day$(DAY)_mine

ros:
	@test -n "$$ROS_DISTRO" || { echo "Source ROS 2 first, e.g. source /opt/ros/humble/setup.bash"; exit 2; }
	colcon --log-base $(BUILD)/ros/log build --base-paths DAY_06 \
	  --build-base $(BUILD)/ros/build --install-base $(BUILD)/ros/install

$(BUILD):
	@mkdir -p $(BUILD)

clean:
	rm -rf $(BUILD)
