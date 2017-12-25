GPP = g++
OUTFILE = nolog.so

SDK_DIR = lib/samp-plugin-sdk

COMPILE_FLAGS = -fpermissive -fPIC -m32 -std=c++11 -c -O3 -w -ggdb -D LINUX
LINK_FLAGS = -W -O2 -m32 -fshort-wchar -shared


build/amxplugin.o: $(SDK_DIR)/amxplugin.cpp
	$(GPP) $(COMPILE_FLAGS) $(SDK_DIR)/amxplugin.cpp -o build/amxplugin.o
build/amxplugin2.o: $(SDK_DIR)/amxplugin2.cpp
	$(GPP) $(COMPILE_FLAGS) $(SDK_DIR)/amxplugin2.cpp -o build/amxplugin2.o

build/main.o: src/main.cpp
	$(GPP) $(COMPILE_FLAGS) -I$(SDK_DIR) -I$(SDK_DIR)/amx src/main.cpp -o build/main.o

$(OUTFILE): build/amxplugin.o build/amxplugin2.o build/main.o
	$(GPP) $(LINK_FLAGS) -o $(OUTFILE) build/*.o

all: $(OUTFILE)

clean:
	-rm build/*.o *.so

indocker:
	docker run \
		-it \
		--entrypoint "make" \
		-w '//root' \
		-v '/$(shell pwd):/root' \
		maddinat0r/debian-samp \
		all

runtest:
	cp nolog.so test/plugins/nolog.so
	sampctl package build --forceEnsure --dir test
	sampctl server run --dir test --container
