RDKITPATH	:= $(HOME)/.local/share/rdkit
TARGET		:= hello

$(TARGET):
	mkdir -p build
	cd build\
		&& cmake -DCMAKE_PREFIX_PATH=$(RDKITPATH) ..\
		&& make
	mv build/$(TARGET) $(TARGET)

.PHONY: clean
clean:
	rm -rf build $(TARGET)
