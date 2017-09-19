PYUIC=pyuic5

gui: gui_eventinfo.py gui_frontend.py gui_ownerdog.py

all: gui

gui_eventinfo.py : eventinfo.ui
	${PYUIC} -x eventinfo.ui -o gui_eventinfo.py

gui_frontend.py : frontend.ui
	${PYUIC} -x frontend.ui -o gui_frontend.py

gui_ownerdog.py : ownerdog.ui
	${PYUIC} -x ownerdog.ui -o gui_ownerdog.py

.PHONY: clean
clean:
	@echo "Nothing to do yet!"
