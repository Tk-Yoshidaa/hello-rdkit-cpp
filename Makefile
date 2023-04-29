RDKITPATH	:= $(HOME)/.local/share/rdkit
RDKITINC	:= ./rdkit/Code
TARGET		:= hello
BUILDDIR	:= ./build

$(TARGET):
	mkdir -p $(BUILDDIR)
	cd $(BUILDDIR)\
		&& cmake -DCMAKE_PREFIX_PATH=$(RDKITPATH) ..\
		&& make
	mv $(BUILDDIR)/$(TARGET) $(TARGET)

.PHONY: clean
clean:
	rm -rf $(BUILDDIR) $(TARGET)
