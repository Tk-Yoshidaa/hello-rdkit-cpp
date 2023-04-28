RDKITPATH	:= $(HOME)/.local/share/rdkit


.PHONY: hello
hello:
	mkdir -p build
	cd build\
		&& cmake -DCMAKE_PREFIX_PATH=$(RDKITPATH) ..\
		&& make
	mv build/hello hello


.PHONY: clean
clean:
	rm -rf build hello
