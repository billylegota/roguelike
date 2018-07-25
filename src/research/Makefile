
TERMBOX_DIR = ../../lib/termbox

all: libtermbox.a hello_termbox

libtermbox.a:
	cd $(TERMBOX_DIR); \
		python waf configure; \
		python waf
	cp $(TERMBOX_DIR)/build/src/libtermbox.a ./libtermbox.a

hello_termbox:
	$(CC) -c hello_termbox.c -I$(TERMBOX_DIR)/src $(CFLAGS)
	$(CC) -o hello_termbox hello_termbox.o libtermbox.a

clean:
	rm libtermbox.a
	rm hello_termbox
