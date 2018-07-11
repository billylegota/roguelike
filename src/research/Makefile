TERMBOX_DIR = "../../lib/termbox"

all: termbox hello_termbox

termbox:
	python $(TERMBOX_DIR)/waf configure
	python $(TERMBOX_DIR)/waf
	cp $(TERMBOX_DIR)/build/src/libtermbox.a ./libtermbox.a

hello_termbox:
	$(CC) -c hello_termbox.c $(CFLAGS)
	$(CC) -o hello_termbox hello_termbox.o libtermbox.a
