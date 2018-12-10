PROJECT_DIR?=$(shell pwd)
SRC_DIR=$(PROJECT_DIR)/src
DEST_DIR=$(PROJECT_DIR)/bin

MKDIR=mkdir -p
RM=rm -f

INSTALL_TOP=/usr/local
INSTALL_BIN=$(INSTALL_TOP)/bin
INSTALL_INC= $(INSTALL_TOP)/include

INSTALL=install -p
INSTALL_EXEC=$(INSTALL) -m 0755

TO_BIN=bible

$(DEST_DIR):
	mkdir -p $(DEST_DIR)

build: clean $(DEST_DIR)
	gcc -lcurl $(SRC_DIR)/bible.c -o $(DEST_DIR)/bible

clean:
	$(RM) -r $(DEST_DIR)

install: build
	cd src && $(MKDIR) $(INSTALL_BIN)
	cd src && $(INSTALL_EXEC) $(DEST_DIR)/$(TO_BIN) $(INSTALL_BIN)

uninstall:
	cd src && cd $(INSTALL_BIN) && $(RM) $(TO_BIN)