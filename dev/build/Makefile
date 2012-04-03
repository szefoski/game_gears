CLAW_BUILD_ROOT = .
TARGET_DIR=$(PLATFORM)
COMPILER=gcce

build_scripts: Gears.claw
	perl $(CLAW_ROOT)/bin/claw-build-scripts.pl --platform=$(PLATFORM) --target-dir=$(TARGET_DIR) --platform=$(PLATFORM) $?
