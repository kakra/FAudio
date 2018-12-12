CCFLAGS = -O2 -march=native -fomit-frame-pointer -g0 -fipa-pta

CMAKE_FLAGS = -DCMAKE_BUILD_TYPE=Release -DXNASONG=OFF -DFFMPEG=ON -DLOG_ASSERTIONS=ON
CMAKE = cmake $(abspath .) $(CMAKE_FLAGS)

ifndef VERBOSE
CMAKE += -DCMAKE_RULE_MESSAGES=OFF -DCMAKE_INSTALL_MESSAGE=NEVER
SILENCE_IS_GOLDEN = &>output-$$$$.log || cat output-$$$$.log; rm output-$$$$.log
.SILENT:
endif

FAUDIO_OBJS := \
	dist/lib/libFAudio.so \
	dist/lib64/libFAudio.so

dist: dist.tar.xz

build/wine32/Makefile: CCFLAGS += -m32
build/wine64/Makefile: CCFLAGS += -m64

build/wine32/Makefile: LIBDIR = lib
build/wine64/Makefile: LIBDIR = lib64

build/%/Makefile: CMakeLists.txt makefile
	echo "Configuring $(patsubst build/wine%/Makefile,%,$@)-bit FAudio libraries..."
	mkdir -p $(dir $@)
	cd $(dir $@) && $(CMAKE) \
		-DCMAKE_INSTALL_PREFIX=$(abspath dist) \
		-DCMAKE_INSTALL_LIBDIR="$(LIBDIR)" \
		-DCMAKE_C_FLAGS="$(CCFLAGS)" \
		-DCMAKE_CXX_FLAGS="$(CCFLAGS)" \
		$(SILENCE_IS_GOLDEN)

build/%/libFAudio.so: build/%/Makefile
	echo "Building $(patsubst build/wine%/libFAudio.so,%,$@)-bit FAudio libraries..."
	+$(MAKE) -C $(dir $@) $(SILENCE_IS_GOLDEN)

dist/lib64/libFAudio.so: build/wine64/libFAudio.so
dist/lib/libFAudio.so: build/wine32/libFAudio.so

$(FAUDIO_OBJS):
	+$(MAKE) -C $(dir $<) install/strip $(SILENCE_IS_GOLDEN)

clean:
	rm -Rf build/

makefiles: build/wine32/Makefile build/wine64/Makefile
configure: makefiles

install: $(FAUDIO_OBJS)

dist.tar.xz: $(FAUDIO_OBJS)
	echo "Creating FAudio distribution..."
	tar cJf $@ $^
